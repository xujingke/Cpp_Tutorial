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

#allow users to put headers in any subfolders
ALLDIRS:=$(shell find . -type d | sed 's/\.\///' | grep -v \.git)
ALLDIRS:=$(filter-out exe, $(ALLDIRS))
INCLUDES:=$(addprefix -I,$(ALLDIRS))

CFLAGS=$(SYSCFLAGS) $(INCLUDES) $(EXTRACFLAGS) -fPIC
LFLAGS=$(SYSLFLAGS) $(EXTRALIBS)

#use the headers only to decide whether regeneraget .d files
HEADERS:=$(shell find . -name '*.h') $(shell find . -name '*.hh')
#by default name all useful codes *.cpp
ALLCPPS:=$(shell find . -type f -name "*.cpp" | sed 's/\.\///' )

#put all .d and .o files in the same folder as .cpp for simplicity
ALLDEPS:= $(ALLCPPS:%.cpp=%.d)
ALLOBJS:= $(ALLCPPS:%.cpp=%.o)

#the binary files we need to build
BINCPPS:=$(shell find exe -type f -name "*.cpp" | sed 's/\.\///' )
BINS:=$(notdir $(BINCPPS))
BINS:=$(basename $(BINS))
BINS:=$(addprefix bin/,$(BINS))

BINOBJS:=$(BINCPPS:%.cpp=%.o)
OBJS:=$(filter-out $(BINOBJS),$(ALLOBJS))

all: $(BINS)

$(BINS): bin/%: exe/%.o $(OBJS)
	@mkdir -p bin
	$(CC)  $^ $(LFLAGS) -o $@

clean:
	rm -f bin/*
	find . -name \*.o -exec rm \{\} \;

distclean: clean
	rm -fr bin
	find . -name \*.d -exec rm \{\} \;

depend: $(ALLDEPS)

#the dependencies are specified in the DEPS files
%.o: 
	$(CC) -c  $< $(CFLAGS) -o $@

#the dependencies for .d files are specified in obj/deps.dep
%.d: %.cpp $(HEADERS)
	@echo Making dependencies for $< ...
	@$(CC) $(CFLAGS) -MM -MT"$(<:.cpp=.o)" $< >$@

ifneq ($(MAKECMDGOALS), clean)
ifneq ($(MAKECMDGOALS), distclean)
ifneq ($(MAKECMDGOALS), depend)
-include $(ALLDEPS)
endif
endif
endif

.PHONY: all clean distclean depend
