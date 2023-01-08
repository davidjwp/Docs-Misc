# CC is the standard name of the C compiler which will be used.
# By using ?= instead of = to assign a value to CC we are only setting its value
# if it wasn't previsouly set.
CC ?= gcc

# CFLAGS is the standard name for flags to pass to the C compiler.
# Here, we unconditionally set them as the coding style specifies your code
# should compile with these flags only.
CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic

# When building your testsuite executable, you will need to link it with the
# library we use for testing: `criterion`, as well as with the library which
# will contain your code: `student`.
# When specifying `-lname` the linker will search for a file called
# `libname.so` in a predifined set of directories.
# The `-L` adds a directory (`.` the current folder here) to that predefined
# search path.
TEST_LDLIBS = \
	-lcriterion \
	-L. -lstudent

# When a dynamically linked executable is launched, a default path called
# LD_LIBRARY_PATH is searched to load the libraries.
# By using -Wl we give a flag '-rpath' and it's parameter '.' to our linker.
# rpath is just another way to specify places to search for libaries at runtime.
# For more info, see ldso(8) and ld(1).
# By doing this, we avoid the need to run the `testsuite` executable like this:
# LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH ./testsuite
TEST_LDFLAGS = -Wl,-rpath,.

# This will be the name of the library we will build with our code (to be able
# to use the `-lstudent` flag we evoked earlier.
LIB = libstudent.so

# This is the list of object files we will build from our C source code files.
OBJS = bubble_sort.o

# This is the list of object files we will build from our testsuite source code.
TEST_OBJS = tests/test.o

# This rule (the first one that doesn't start with a `.`) will be the default
# target which will be called if we use `make` without any parameter.
all: $(LIB)

# For the library, we just have to specify its dependencies as it will fall into
# the pattern rule at the end of this Makefile.
# Moreover, library code needs to be Position independant, `-fPIC` allows this
$(LIB): CFLAGS += -fPIC
$(LIB): $(OBJS)

# `make` does not have a default rule to build executables we will have to tell
# it how to build the `testsuite` executable from its dependencies.
# $(LINK.o) will be our linker (`cc` here).
# $^ will be replaced by this rule's dependencies and $@ by the rule's name.
testsuite: $(TEST_OBJS)
	$(LINK.o) $^ $(TEST_LDFLAGS) -o $@ $(TEST_LDLIBS)

# This is a rule to build and the run our testsuite.
check: testsuite
	./testsuite --verbose

# `clean` is the standard name for a rule which cleans all the build files
# produced by the other rules in the Makefile.
# $(RM) will be replaced by `rm  -f`.
clean:
	$(RM) testsuite $(TEST_OBJS) $(LIB) $(OBJS)

# The .PHONY target contains the names of all targets which don't produce a file
# called like them.
.PHONY: all check clean


# This is a pattern rule which matches all the files ending with `.so`.
# If no explicit rule matches a target name and this does, it will be considered
# as its rule.
%.so:
	$(CC) -shared $(LDFLAGS) -o $@ $^ $(LD_LIBS)
