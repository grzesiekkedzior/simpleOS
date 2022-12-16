# simpleOS
### This is simple implementation of the operating system.


# How to run it
* Install qemu, nasm and cmake;
* open terminal inside root directory;
```shell
mkdir build
cd build
cmake ..
cmake --build .
```
* Inside root directory is created kernel.bin file;
* open it by qemu.
```shell
qemu-system-x86_64 -kernel ../kernel.bin
```

# GTest
* You can test OS by GTest;
* run this inside tests directory.
```shell
cmake -S . -B build
cmake --build build
cd build && ctest
```

# How to contribute
If you want to contribute just write some code and push it.

# The most important things to implement for now
- Shell
- Virtual File System


