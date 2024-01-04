# libgmem

#### 介绍
libgmem是GMEM（基于Linux的操作系统面向异构硬件的通用内存管理架构）用户模式接口的抽象层，它封装了GMEM的一些内存特性和语义

#### 软件架构
软件架构说明


#### 安装教程

使用以下命令进行安装
```
sh ./autogen.sh
./configure --with-device=xxx
make
make install
```

#### 使用说明

libgmem当前有六个对外接口：
1.
gmemFreeEager：对于给定范围[addr, addr + size]的地址段，gmemFreeEager会对范围向内对齐页面大小的完整页面进行释放（默认页面大小2M）。
               stream为空表示同步调用，非空表示异步调用，异步调用时会注册在对应设备的工作流上。
               如果范围内不存在完整页面，将直接返回成功。

  接口成功返回0，失败返回错误码。

  ```c
  接口原型: int gmemFreeEager(unsigned long addr, size_t size, void *stream);
  接口用法: ret = gmemFreeEager(addr, size, stream);
  ```

2.
gmemPrefetch：对于给定范围[addr, addr + size]的地址段，Prefetch会对范围向外对齐页面大小的完整页面（覆盖整个地址段）进行预取。
              确保指定的计算单元设备hnid在接下来对vma发起的访问不会触发page fault。
              stream为空表示同步调用，非空表示异步调用，异步调用时会注册在对应设备的工作流上。
              如果数据已经在指定设备上，gmemPrefetch会标记数据为热数据。

  接口成功返回0，失败返回错误码。

  ```c
  接口原型: int gmemPrefetch(unsigned long addr, size_t size, int hnid, void *stream);
  接口用法: ret = gmemPrefetch(addr, size, hnid, stream);
  ```

3.
gmemGetNumaId：获取当前设备的NumaId。

  接口成功返回设备的异构NumaId，失败返回错误码。

  ```c
  接口原型: int gmemGetNumaId(void);
  接口用法: numaid = gmemGetNumaId();
  ```

4.
malloc/free/realloc: 接口声明为标准posix接口，封装了jemalloc内存池管理，可以避免多次使用mmap，带来额外的性能开销。

#### 参与贡献

1.  Fork 本仓库
2.  新建 Feat_xxx 分支
3.  提交代码
4.  新建 Pull Request
