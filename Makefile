CC := gcc
CFlags :=

CXX := g++
CXXFlags := -m64

INCLUDE := include
LIB := lib
LIBRARIES := -lGL -lGLU -lX11 -lpthread -lXrandr -lXi -ldl -lSDL2
EXE := main

glad := lib/glad
glad_inc := $(glad)/include


all: bin/$(EXE)

run: clean all
	@echo "Executing..."
	./bin/$(EXE)

bin/$(EXE): PolyEngine PolyGL PolySDL glad
	$(CXX) $(CXXFlags) src/Main.cpp bin/PolyEngine.o bin/PolyGL.o bin/PolySDL.o bin/glad.o src/engine/PolyEngine.h src/gl/PolyGL.h src/sdl/PolySDL.h lib/glad/include/glad/glad.h lib/glad/include/KHR/khrplatform.h $(LIBRARIES) -o bin/$(EXE)

glad:
	$(CC) -c $(CFlags) lib/glad/src/glad.c -o bin/glad.o


PolyEngine:
	$(CXX) -c $(CXXFlags) src/engine/PolyEngine.cpp $(LIBRARIES) -o bin/PolyEngine.o

PolyGL:
	$(CXX) -c $(CXXFlags) src/gl/PolyGL.cpp $(LIBRARIES) -o bin/PolyGL.o

PolySDL:
	$(CXX) -c $(CXXFlags) src/sdl/PolySDL.cpp $(LIBRARIES) -o bin/PolySDL.o

clean:
	@echo "Clearing..."
	-rm bin/*