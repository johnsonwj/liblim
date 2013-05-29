rootc = ~/usr/local/bin/g++ -Wall -g -I../include $(shell root-config --cflags --libs)

VPATH = ../include

objc = $(rootc) -c $< -o $@

objs = AtlasStyle.o DatasetIter.o LimTree.o common.o
execs = $(addprefix ../, dohists draw yields optim)

all: $(execs)

../%: %.cxx $(objs)
	$(rootc) $^ -o $@

common.o: common.cxx common.h
	$(objc)

DatasetIter.o: DatasetIter.cxx DatasetIter.h LimTree.o common.o
	$(objc)

LimTree.o: LimTree.cxx LimTree.h common.o
	$(objc)

AtlasStyle.o: AtlasStyle.cxx AtlasStyle.h
	$(objc)

