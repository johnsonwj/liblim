rootc = g++ -Wall -g -std=c++11 -Iinclude $(shell root-config --cflags --libs)

objs = $(addprefix obj/, AtlasStyle.o DatasetIter.o LimTree.o)
VPATH = src:include

all: doHists draw optimize yields

obj/%.o: %.cxx %.h xsec_data.h
	$(rootc) -c $< -o $@

%: %.cxx $(objs)
	$(rootc) $^ -o $@
