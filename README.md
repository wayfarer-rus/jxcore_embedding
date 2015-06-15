# jxcore_embedding
Project that dedicated to embedding examples and research for jxnode into C++

# How to build jxcore
* clone repository from https://github.com/jxcore/jxcore
* make sure that you have python2.7 installed and that 'python' command refers to python2.7. It is required for build scripts and configure script
* run ./configure  --static-library --prefix=<installation_folder>
* run make install

# How to build embeded examples
* goto examples/example1 and look into Makefile

Particularly you can build any source file by adapting this string:
````
g++ sample.cpp -lstdc++ -std=c++11 -pthread -O3 -Wno-write-strings -I/targetFolder/include/node/public \
    -fno-rtti /targetFolder/bin/libjx.a /targetFolder/bin/libsqlite3.a \
    /targetFolder/bin/libchrome_zlib.a /targetFolder/bin/libmozjs.a  /targetFolder/bin/libuv.a \
    /targetFolder/bin/libhttp_parser.a  /targetFolder/bin/libopenssl.a  \
    -ldl /targetFolder/bin/libcares.a \
    -o sample
````
