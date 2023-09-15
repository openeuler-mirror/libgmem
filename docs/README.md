

## GMEM主页编辑

* 安装mkdocs

  ```sh
  pip install mkdocs
  # Print help message
  mkdocs -h 
  ```

* 网页组成

  ```sh
  mkdocs.yml    # The configuration file.
  docs/
      index.md  # The documentation homepage.
      ...       # Other markdown pages, images and other files.
  site/
      index.html # 由mkdocs生成的静态网页，托管到gh-pages分支
      ... 
  ```

* 在本地查看网页

  ```sh
  mkdocs serve
  ```
  
* 更新网页到gh-pages分支

  ```sh
  mkdocs gh-deploy --force --no-history -f ./mkdocs.yml
  ```

