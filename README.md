# jxcore_embedding
Project that dedicated to embedding examples and research for jxnode into C++

# How to build jxcore for Linux
* clone repository from https://github.com/jxcore/jxcore
* make sure that you have python2.7 installed and that 'python' command refers to python2.7. It is required for build scripts and configure script
* run ./configure  --static-library --prefix=<installation_folder>
* run make install

# How to build embeded examples for Linux
* goto examples/example1 and look into Makefile

Basically you can build any source file by adapting this string:
````
g++ sample.cpp -lstdc++ -std=c++11 -pthread -O3 -Wno-write-strings -I/targetFolder/include/node/public \
    -fno-rtti /targetFolder/bin/libjx.a /targetFolder/bin/libsqlite3.a \
    /targetFolder/bin/libchrome_zlib.a /targetFolder/bin/libmozjs.a  /targetFolder/bin/libuv.a \
    /targetFolder/bin/libhttp_parser.a  /targetFolder/bin/libopenssl.a  \
    -ldl /targetFolder/bin/libcares.a \
    -o sample
````

# How to build jxcore for Windows
* clone repository from https://github.com/jxcore/jxcore
* make sure that you have python2.7 installed and that 'python' command refers to python2.7. It is required for build scripts
* run "VS2012 Cross Tool Command Prompt" from Microsoft Visual Studio
* cd to jxcore directory
* run vcbuild.bat --shared-library

# How to build embeded examples for Windows
* run "VS2012 Cross Tool Command Prompt" from Microsoft Visual Studio
* goto jxcore_embedding\examples\example1
* run following command. Don't forget to replace <jxcore_folder> with actual jxcore folder.
````
cl /Feexample1.exe /O2 /I<jxcore_folder>\src\public\ main.cpp /link <jxcore_folder>\Release\jx.lib
````

To run the program copy jx.dll to your PATH, or put it near example1.exe file.
