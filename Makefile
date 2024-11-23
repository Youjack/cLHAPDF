CXXFLAGS += -std=c++11 -fPIC -O2
CXXFLAGS += $(shell lhapdf-config --cflags)
LDFLAGS += -shared
LDFLAGS += -Wl,-rpath,$(shell lhapdf-config --libdir --ldflags)

.PHONY: all clean

all: libclhapdf.dylib

libclhapdf.dylib: clhapdf.cpp
	clang++ $(CXXFLAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -f libclhapdf.dylib
