############# A Makefile that attempts to be generic #################
############# Author: Jingke Xu (xujingke@gmail.com) #################

########### Environmental Variables need to be declared ##############
EXTRACFLAGS =
EXTRALIBS =

#add your extra flags/libs here

#add cern root flags/libs
ROOTCFLAGS:=$(shell root-config --cflags)
ROOTLIBS:=$(shell root-config --libs)
EXTRACFLAGS += $(ROOTCFLAGS)
EXTRALIBS += $(ROOTLIBS)

############# Do NOT change any codes below this line ################

# Add .d to Make's recognized suffixes.
SUFFIXES += .d

CC=g++
DEBUG=-g
SYSCFLAGS=-O3 -Wall $(DEBUG)
SYSLFLAGS=-O3 -Wall $(DEBUG)

CFLAGS=$(SYSCFLAGS)  -I$(PWD) $(EXTRACFLAGS) -fPIC
LFLAGS=$(SYSLFLAGS) $(EXTRALIBS)

#use the headers only to decide whether regeneraget .d files
HEADERS:=$(shell find . -name '*.h') $(shell find . -name '*.hh')
#by default name all useful codes *.cpp
ALLCPPS:=$(shell find . -type f -name "*.cpp" | sed 's/\.\///' )
#take the base name
BASECPPS:=$(basename $(ALLCPPS))
BASECPPS:=$(notdir $(BASECPPS))

#put all deps files in obj/
DEPS:=$(addsuffix .d,$(BASECPPS))
DEPS:=$(addprefix obj/,$(DEPS))

#the binary files we need to build
BINS = $(shell find exe/ -type f -name "*.cpp" | sed 's/\.\///' )
BINS:=$(notdir $(BINS))
BINS:=$(basename $(BINS))

OBJS:=$(filter-out $(BINS),$(BASECPPS))
OBJS:=$(addprefix obj/,$(OBJS))
OBJS:=$(addsuffix .o,$(OBJS))

BINS:=$(addprefix bin/,$(BINS))

all: $(BINS)

$(BINS): bin/%: obj/%.o $(OBJS)
	@mkdir -p bin
	$(CC)  $^ $(LFLAGS) -o $@

clean:
	rm -f obj/*.o
	rm -f bin/*

distclean:
	rm -fr obj
	rm -fr bin

#the dependencies are specified by the DEPS files
%.o:
	$(CC) -c  $< $(CFLAGS) -o $@

depend: $(DEPS)

obj/deps.dep: $(ALLCPPS) $(HEADERS)
	@mkdir -p obj
	@for fl in $(DEPS); do echo "$${fl}:" >>obj/targets.d; done
	@for fl in $(ALLCPPS); do echo $${fl} >>obj/dependencies.d; done
	@paste obj/targets.d obj/dependencies.d >obj/deps.dep
	@rm -f obj/targets.d obj/dependencies.d

#the dependencies for .d files are specified in obj/deps.dep
%.d:
	@if [ -z $< ]; then :; else echo Making dependencies for $< ...; \
	$(CC) $(CFLAGS) -MM $< | sed '1s/^/obj\//' >$@; fi

.PHONY: all clean distclean depend

-include obj/deps.dep

ifneq ($(MAKECMDGOALS), clean)
ifneq ($(MAKECMDGOALS), distclean)
ifneq ($(MAKECMDGOALS), depend)
ifneq ($(MAKECMDGOALS), obj/deps.dep)
-include $(DEPS)
endif
endif
endif
endif
