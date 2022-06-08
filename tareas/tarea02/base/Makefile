#/////////////////////////////////////////////////////////////////////////////////
#  Identificación del alumno
#
#  Nombre Completo:
#/////////////////////////////////////////////////////////////////////////////////

#/////////////////////////////////////////////////////////////////////////////////
# Cambie el nombre del TARGET y WORK_NAME según las indicaciones de la tarea
#/////////////////////////////////////////////////////////////////////////////////
TARGET=./matrixMult
WORK_NAME="tarea2"

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

DIR_SUBMIT="/entregas/$(USER)/$(WORK_NAME)"

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
	@$(RM) -rf $(DIR_OBJ)

submit: clean distclean
	@echo "deleting old $(DIR_SUBMIT) content ..."
	@$(RM) -rf $(DIR_SUBMIT)
	@echo "submitting homework to $(DIR_SUBMIT) ..."
	@mkdir -p $(DIR_SUBMIT)
	@tar cf - . | tar xvf - -C $(DIR_SUBMIT)
	@echo "done"





