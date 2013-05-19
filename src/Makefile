rootc = g++ -Wall -g -std=c++11 -I../include $(shell root-config --cflags --libs)

VPATH = ../include

objc = $(rootc) -c $< -o $@

all: DatasetIter.o LimTree.o AtlasStyle.o

DatasetIter.o: DatasetIter.cxx DatasetIter.h LimTree.o
	$(objc)

%.o: %.cxx %.h
	$(objc)
