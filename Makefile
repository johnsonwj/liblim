rootc = g++ -Wall -g -std=c++11 -Iinclude $(shell root-config --cflags --libs)

obj_files = $(addprefix src/, AtlasStyle.o DatasetIter.o LimTree.o)

VPATH = src

all: doHists draw optimize yields

.PHONY: clean objs

%: %.cxx objs
	$(rootc) $< $(obj_files) -o $@

objs:
	cd src && $(MAKE)

clean:
	rm src/*.o
