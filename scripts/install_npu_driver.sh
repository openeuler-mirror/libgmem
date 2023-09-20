#!/bin/bash

# install npu-driver to kernel-6.4

RPM_NAME=$1
RUN_DIR="/usr/local/Ascend"
RUN_NAME="$RUN_DIR/Ascend-hdk-910-npu-driver_6.0.0.1_linux-aarch64.run"

function sed_run()
{
    echo "sed $RUN_NAME ..."

    sed -n  '1,/^eval $finish; exit $res/!p' $RUN_NAME > tmp.tar.gz
    sed -n  '1,/^eval $finish; exit $res/p' $RUN_NAME > install.sh
    sed -i 's/MS_Check "$0".*/echo "skip MS_Check"/g' install.sh

    mkdir sz_tmp
    mv tmp.tar.gz sz_tmp/
    cd sz_tmp

    tar -axf tmp.tar.gz
    rm -rf tmp.tar.gz

    sed -i "s/^check_euleros$/#check_euleros/g" driver/script/run_driver_map_kernel.sh
    sed -i "s/^check_and_match$/#check_and_match/g" driver/script/run_driver_map_kernel.sh
    sed -i "s/^drv_dkms_env_check$/#/g" driver/script/run_driver_install.sh
    sed -i "s/^.*driver_ko_install_manually$/echo \"skip\"/g" driver/script/run_driver_install.sh

    tar -acf tmp.tar.gz *
    mv tmp.tar.gz ../tmp.tar.gz
    cd ..

    cat install.sh tmp.tar.gz > $RUN_NAME
    rm -rf sz_tmp
    rm -f install.sh tmp.tar.gz
}


rpm -ivh $RPM_NAME --noscripts

cd $RUN_DIR
sed_run
groupadd HwHiAiUser
useradd -g HwHiAiUser -d /home/HwHiAiUser -m HwHiAiUser -s /bin/bash
$RUN_NAME --full --force
cd -

