rootc = g++ -Wall -g -I../include $(shell root-config --cflags --libs)

VPATH = ../include

objc = $(rootc) -c $< -o $@

objs = AtlasStyle.o DatasetIter.o LimTree.o liblim.o

all: dohists draw yields # optimize

%: %.cxx $(objs)
	$(rootc) $^ -o ../$@

liblim.o: liblim.cxx liblim.h
	$(objc)

DatasetIter.o: DatasetIter.cxx DatasetIter.h LimTree.o liblim.o
	$(objc)

LimTree.o: LimTree.cxx LimTree.h liblim.o
	$(objc)

AtlasStyle.o: AtlasStyle.cxx AtlasStyle.h
	$(objc)

