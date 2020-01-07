#MACROS
# var_name = value
# to access them use $(var_name)
#-----------------------------------------
CXX = c++
LANG = ENGLISH

SRC = src/greetings.cc src/conclusion.cc
OBJ = $(SRC:.cc=.o)
#-----------------------------------------

#first rule: by convetion is called all or default
# rules with no actions are called PRE-REQUISITES
all: libgreetings.so
#TARGET syntax
# target: dep1 dep2 ... depN
#        action1 (could be a for loop, which has to be written in one line)
#        action2
# when all the actions are terminated, a file named "target" should be generated
# the command "make" executes the first target if you don't specify the target
# $@: name of the target
# $^: list all the dependencies

# this generates a library (convetion: lib*.so)
# compiler confronts te timestamp of the target with the timestamp of the dependency
# if the timestamp is more recent, then the actions are exectuted and file re-written 
libgreetings.so: $(OBJ)
	$(CXX) -shared -o $@ $^

#fpic = position independent call
# %: wild card
# %.o depends on %.cc
# -D: define a macro for the pre-processor
# $<: first element of the list of dependencies
# -Iinclude: compile flag
%.o:%.cc
	$(CXX) -fpic -D$(LANG) -o $@ -c $< -Iinclude

src/greetings.o: include/greetings.h

src/conclusion.o: include/conclusion.h

format: $(SRC) include/greetings.h include/conclusion.h
	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this commands"

# @ in front of a command will prevent echoing the command
clean:
	@rm -f *~ */*~ libgreetings.so src/*.o

# this tells the compiler that the words "clear" "all" and  "format"
# have nothing to with filenames (if you have a file named clean,
# the command "make clean" will not refer the file, ma to the rule)
.PHONY: clean all format

#how to use make files
# FORCE RE-COMPILATION: make -B
# make -B -j 3
# 	3 is the num of procs+1
# 	-j compile things in parallel
# make -n
# 	-n: prints the actions, but it doesn't execute then (useful for debugging)
