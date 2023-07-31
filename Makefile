prefix = /usr/local
libdir = $(prefix)/lib64
headerdir = $(prefix)/include

target = libgmem.so
cc = gcc
srcs = $(wildcard ./src/*.c)
objs = $(patsubst %c, %o, $(srcs))
INCLUDES = -I./include/ 
CFLAGS = -shared -fPIC

all: $(target)
$(target): $(objs)
	$(cc) $(CFLAGS) $(objs) -o $@ $(LDFLAGS) $(INCLUDES)

%.o: %.c
	$(cc) -c $(CFLAGS) $^ -o $@ $(LDFLAGS) $(INCLUDES)

clean:
	rm -f $(target) $(objs) 
install:
	install -m 0755  $(target) $(libdir)
	install -m 0644  ./include/libgmem.h $(headerdir)
uninstall:
	rm -f $(libdir)/$(target)
	rm -f $(headerdir)/libgmem.h

