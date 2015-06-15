IDIR =.
JXCOREDIR =$(HOME)/local/jxcore
CC=g++
ODIR=obj
CFLAGS=-O3 -Wno-write-strings -I$(IDIR) -I$(JXCOREDIR)/include/node/public
LIBS=-lstdc++ -std=c++11 -pthread -fno-rtti $(JXCOREDIR)/bin/libjx.a $(JXCOREDIR)/bin/libsqlite3.a $(JXCOREDIR)/bin/libchrome_zlib.a $(JXCOREDIR)/bin/libv8_base.a $(JXCOREDIR)/bin/libv8_nosnapshot.a $(JXCOREDIR)/bin/libuv.a $(JXCOREDIR)/bin/libhttp_parser.a $(JXCOREDIR)/bin/libopenssl.a -ldl $(JXCOREDIR)/bin/libcares.a

src = main.cpp
objects = $(patsubst %.c,obj/%.o,$(src))

program=example1

.PHONY: all
all: $(program)

$(program): $(objects)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(objects): | obj

obj:
	@mkdir -p $@

obj/%.o : %.c
	@echo $<
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o *~ $(program)
