TARGET=./matrix

DEBUG=-DDEBUG
DEBUG=

CXX = g++

#
DIR_OBJ=objs
SOURCES=$(wildcard *.cc)
OBJECTS=$(patsubst %.cc,$(DIR_OBJ)/%.o,$(SOURCES))

INTRINSICS=-msse2 -mavx

INCLUDES =-I. -I./include
CPPFLAGS =-std=c++17  -Wno-deprecated $(INTRINSICS) 
LDFLAGS =-L/usr/local/lib 
LDLIBS = -lm -lpthread 

all: $(TARGET)
	@echo Made [ $? ] OK :\)
	
$(TARGET): $(OBJECTS) 
	@echo Linking [$@]
	@eval $(CXX) $(LDFLAGS) $^ $(LDLIBS)  -o $@ 
	
$(DIR_OBJ)/%.o: %.cc
	@echo Compiling [$@]
	@mkdir -p $(DIR_OBJ)
	@eval $(CXX) -c $(INCLUDES) $(CPPFLAGS)  $< -o $@
	
clean:
	@$(RM) core *~ \#*\# *.bak *.BAK *\%
	@$(RM) -f .dummy $(OBJECTS)

distclean:
	@$(RM) $(TARGET)







