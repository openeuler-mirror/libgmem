# libgmem

#### Description
libgmem is the abstract layer of GMEM(Generalized Memory Management) user-mode interface, which encapsulates some memory characteristics and semantics of GMEM

#### Software Architecture
Software architecture description

#### Installation

install with follows command
```
sh ./autogen.sh
./configure --with-device=xxx
make
make install
```

#### Instructions

libgmem currently has three external interfaces:
1.
gmemFreeEager: For address segments within a given range of [addr, addr + size], gmemFreeEager will release the entire page with the range aligned inward (default page size 2M).
               A stream that is NULL represents synchronous calls, while a non-NULL represents asynchronous calls. Asynchronous calls will be registered on the corresponding device's work stream.
               If there is no complete page within the scope, success will be returned directly.

  The interface successfully returns 0, while failure returns an error code.

  ```c
  Prototype: int gmemFreeEager (unsigned long addr, size_t size, void * stream);
  Usage: ret = gmemFreeEager (addr, size, stream);
  ```

2.
gmemPrefetch: For address segments within a given range of [addr, addr + size], Prefetch will prefetch the entire page (covering the entire address segment) that aligns the page size outward from the range.
              Ensure that the specified computing unit device hnid does not trigger a page fault in subsequent access to the vma.
              A stream that is NULL represents synchronous calls, while a non-NULL represents asynchronous calls. Asynchronous calls will be registered on the corresponding device's work stream.
              If the data is already on the specified device, gmemPrefetch will mark the data as hot data.

  The interface successfully returns 0, while failure returns an error code.

  ```c
  Prototype: int gmemPrefetch (unsigned long addr, size_t size, int hnid, void * stream);
  Usage: ret = gmemPrefetch (addr, size, hnid, stream);
  ```

3.
gmemGetNumaId: Gets the NumaId of the current device.

  The interface successfully returns the heterogeneous numaid of devices, while failure returns an error code.

  ```c
  Prototype: int gmemGetNumaId (void);
  Usage: numaid = gmemGetNumaId();
  ```

#### Contribution

1.  Fork the repository
2.  Create Feat_xxx branch
3.  Commit your code
4.  Create Pull Request
