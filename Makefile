BINDINGS = Bindings/raylib/main.o\
		   Bindings/raylib/Colors.o\
		   Bindings/raylib/Structs.o\
		   Bindings/raylib/Enums.o\
		   Bindings/raylib/Callbacks.o\
		   Bindings/raylib/Globals.o\
		   Bindings/raylib/Core.o\
		   Bindings/raylib/Gestures.o\
		   Bindings/raylib/Camera.o\
		   Bindings/raylib/Shapes.o\
		   Bindings/raylib/Textures.o \
		   Bindings/raylib/Text.o\
		   Bindings/raylib/Models.o\
		   Bindings/raylib/Audio.o\
		   Bindings/Engine/Engine.o\
		   Bindings/External.o\
		   Bindings/raymath.o

CPP      = g++
CC       = gcc
WINDRES  = windres
OBJ      = Icon.res main.o $(BINDINGS) libtinyfiledialogs/tinyfiledialogs.o
LINKOBJ  = $(OBJ)
LINKERS  = -static-libgcc -mwindows -lwren -lraylib -lopengl32 -lgdi32 -lwinmm -lole32
LIBS     = -L"C:/TDM-GCC-64/lib" -L"C:/Libraries/raylib/lib" -L"C:/Libraries/wren/lib" $(LINKERS)
INCS     = -I"C:/TDM-GCC-64/include" -I"C:/Libraries/raylib/include" -I"C:/Libraries/wren/include" 
CXXINCS  = -I"./wrenbind17/include" -I"./libtinyfiledialogs" -I"./RLL/include"
BIN      = Cube2D.exe
CFLAGS   = $(INCS)
CXXFLAGS = $(CXXINCS) $(CFLAGS) -std=c++17
RM       = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after run

clean: clean-custom
	${RM} $(OBJ) $(BIN)

run: $(BIN)
	$(BIN)
	
$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)

Icon.res: Icon.rc
	$(WINDRES) Icon.rc -O coff -o Icon.res