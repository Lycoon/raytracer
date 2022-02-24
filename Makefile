#************************************************
#*                                              *
#*   TP 1&2    (c) 2017 J. FABRIZIO             *
#*                                              *
#*                               LRDE EPITA     *
#*                                              *
#************************************************

CC = g++

SKEL_CPP_FILES = image.cpp image_io.cpp histogram.cpp
SKEL_HH_FILES  = image.hh histogram.hh image_io.hh

CPP_FILES =  $(SKEL_CPP_FILES)
H_FILES =  $(SKEL_HH_FILES)
OBJ_FILES = $(CPP_FILES:.cpp=.o)

CXX_FLAGS += -Wall -Wextra -O3 -g -std=c++11
CXX_FLAGS += -lm
CXX_FLAGS += -m64 -march=native
CXX_FLAGS += -fopt-info-vec-optimized #-fopt-info-vec-missed -ftree-vectorize
LDXX_FLAGS =

SKEL_DIST_DIR = tifo_skel_tp

#For gcc 4.9
#CXXFLAGS+=-fdiagnostics-color=auto
export GCC_COLORS=1

define color
    if test `tput colors` -gt 0 ; then \
	tput setaf $(1); \
    fi
endef

define default_color
 if test `tput colors` -gt 0 ; then  tput sgr0 ; fi
endef


all: post-build

pre-build:
	@$(call color,4)
	@echo "******** Starting Compilation ************"
	@$(call default_color)

post-build:
	@make --no-print-directory main-build ; \
	sta=$$?;	  \
	$(call color,4); \
	echo "*********** End Compilation **************"; \
	$(call default_color); \
	exit $$sta;

main-build: pre-build build

build: $(OBJ_FILES)
	#$(CC) tp1.cpp -o tp1 $(OBJ_FILES) $(CXX_FLAGS) $(LDXX_FLAGS)
	#$(CC) tp2.cpp -o tp2 $(OBJ_FILES) $(CXX_FLAGS) $(LDXX_FLAGS)

%.o: %.cpp %.hh
	@$(call color,2)
	@echo "[$@] $(CXX_FLAGS)"
	@$(call default_color)
	@$(CC) -c -o $@ $< $(CXX_FLAGS) ; \
	sta=$$?;	  \
	if [ $$sta -eq 0 ]; then  \
	  $(call color,2) ; \
	  echo "[$@ succes]" ; \
	  $(call default_color) ; \
	else  \
	  $(call color,1) ; \
	  echo "[$@ failure]" ; \
	  $(call default_color) ; \
	fi ;\
	exit $$sta

.PHONY: all clean pre-build post-build main-build build

clean:
	rm -f $(OBJ_FILES)
	rm -f $(SKEL_DIST_DIR)
	rm -f $(SKEL_DIST_DIR).tar.bz2

skel:
	rm -rf $(SKEL_DIST_DIR)
	mkdir $(SKEL_DIST_DIR)
	cp $(SKEL_CPP_FILES) $(SKEL_DIST_DIR)
	cp $(SKEL_HH_FILES) $(SKEL_DIST_DIR)
	cp Makefile $(SKEL_DIST_DIR)
	tar -cjvf $(SKEL_DIST_DIR).tar.bz2 $(SKEL_DIST_DIR)
	rm -rf $(SKEL_DIST_DIR)
