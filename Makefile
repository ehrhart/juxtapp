VERSION = 1.0
LIBNAME = Juxtapp

ifeq ($(mode),debug)
	CPPFLAGS += -g -Wall -O0
else
	mode = release
	CPPFLAGS += -g -Wall -O2
endif

CC = g++

#CFLAGS += -g -Wall -O2 --std=c++11 -Iinclude -static -static-libgcc -ldl -lm -lpthread -Llib -lstdc++ -llua -shared -fPIC
#LDFLAGS += -g -Wall --std=c++11 -static -static-libgcc -ldl -lm -lpthread -Iinclude -Llib -lstdc++ -llua -shared -fPIC

CPPFLAGS += --std=c++11 -static -static-libgcc -ldl -lm -lpthread -Iinclude -Llib -llua -shared -fPIC

OBJDIR=obj
DISTDIR=dist

.PHONY: init all clean shared

all: information clean init shared

information:
ifneq ($(mode),release)
ifneq ($(mode),debug)
	@echo "Invalid build mode." 
	@echo "Please use 'make mode=release' or 'make mode=debug'"
	@exit 1
endif
endif
	@echo "Building on "$(mode)" mode"
	@echo ".........................."

init:
	mkdir -p $(OBJDIR)
	mkdir -p $(DISTDIR)

shared:
	$(CC) src/main.cpp $(CPPFLAGS) -o $(DISTDIR)/lib$(LIBNAME).so

clean:
	$(RM) -r $(OBJDIR) $(DISTDIR)