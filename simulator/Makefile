CXX=clang++
LDFLAGS=-lSDL2 -lSDL_image -ldl #Linker
CXXFLAGS=-Wall

BUILD_FOLDER=./BUILD/
src =  $(wildcard *.cpp) $(wildcard */*.cpp)
obj = $(src:.cpp=.o)
b_obj = $(addprefix $(BUILD_FOLDER), $(obj))

#for every .o file with a matching .cpp as a prerequisite, do this pattern rule
%.o : %.cpp ;
#compiler, flags -c -o ofile.o cppfile.cpp
	mkdir -p $(dir $(BUILD_FOLDER)$@)
	$(CXX) $(CXXFLAGS) -c -o $(BUILD_FOLDER)$@ $^

#phony indicates that this target does not denote rules for a specfic file
.PHONY: build
#$(obj) is a prerequisite for build, meaning that it will build all .o files first
build: $(obj)
#build the main program from the o files in the build folder
	$(CXX) $(CXXFLAGS) -o program $(BUILD_FOLDER)*.o $(LDFLAGS)

.PHONY: clean
clean:
#remove the .o files
	rm -f $(b_obj) myprog

.PHONY: run
run:
#run the program, you can call make build run to build and run quickly
	./program

.PHONY: dependants
dependants:
#this is usually not in a make file, but I like to live life on the edge
	apt-get install libsdl2-dev
	apt-get install libsdl2-image-dev
