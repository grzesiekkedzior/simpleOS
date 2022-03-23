# simpleOS
### This is simple implementation of the operating system.


# How to run it
* install qemu, nasm and cmake;
* open terminal inside root directory;
```shell
mkdir build
cd build
cmake ..
cmake --build .
```
* inside root directory is created kernel.bin file;
* open it by qemu.
```shell
qemu-system-x86_64 -kernel kernel.bin
```

# How to contribute
If you want to contribute just write some code and push it.

# The most important things to implement for now.
- Shell
- Virtual File System


