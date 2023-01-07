## Makefile
##### non exaustive list of useful info on Makefiles

a Makefie is made up of targets, prerequisites and rules.

the Makefile will look at the target as a creatable file and use the rule to make it, if something is needed to create that target it will look at the prerequisite which can be itself a target, like a function in a programm once that target is done it will use that creation in the original target.

here is a basic Makfile rule:

    target:prerequisite
        rule
applied to output a "hey!"
    
    hello:
        echo hey!
in this case there is no need for any dependency/prerequisite, a rule does not need a prerequisite but it needs a target, it also does not need a rule command though it would make the rule useless.

you can also declare variables in makefiles like so:

    NAME    = variable  

a variable could be anything you want, it could be a bash command or text or another variable, variable are used with the % prefix like this 

    %(NAME)

At the fundamental level Makefiles help you compiles a very large and complex amount of files for big projects though they can do much more.
**automatic variables/make operands and prefix (the most useful so far)**

- **$@**    target name
- **$<**    first prerequisite
- **$^**    all prerequisites
- **$%**    member/s of target


	Target(member.o OtherMember.o):
		$(RULE)

**general info**

.PHONY	is a target that stipulates the Makefile that the prerequisite target is not a build (a build is for when a target specifically creates a file
	every target is a build by default)

@	this prefix is used to tell the makefile not to display the command being executed,
	thus it is used before a command

FileName: file.o
	gcc file.o -o FileName

file.o: file.c
	gcc -c file.c 

The Makefile sees the first rule and checks the prerequisite for the target, in this case the target is FileName this is the file we are trying to create using the object file, the object file does not exist so it will check for a rule that can.

Thus the next rule is in effect, the Makefile compiles file.c using the compiler option -c to output an object file, then the first rule can be fullfilled.

Now let's try a more complicated Makefile by simply adding files:

FileName: file1.o file2.o file3.o file3.o file4.o
	gcc file1.o file2.o file3.o file3.o file4.o -o FileName

file1.o file2.o file3.o file3.o file4.o: file1.c file2.c file3.c file3.c file4.c
	gcc -c file1.c file2.c file3.c file3.c file4.c

The Makefile is suddendly a lot messier and harder to work with so let's use variables:

CC	= gcc
NAME	= FileName

${NAME}: %.o
	${CC} %.o -o ${NAME}

%.o: %.c
	${CC} -c

Things have gotten much clearer but more complex as well, first we declare the variable CC which will correspond to the gcc command, then NAME is gonna be the name of our executable file.

Then we use the variable NAME as target for the first rule with as a prerequesite %.o which is a pattern rule the symbol % contains the target pattern in this case it's all files ending in .o much like *.o in bash.

The rule compiles with the CC variable, selects all object files and renames them with the NAME variable.

The second rule creates our object files by using those same variables
To use a variable simply use ${VARIABLE} or $(VARIABLE) same thing but the squiggly lines look cooler, you can also use the variable ${MAKE} which is a recursive call to the Makefile and does not need to be set.

...STANDARD RULES...:

There are some standard rules used often to accomplish certain tasks and although we can call them by any name they do have names to recognize them by, here are some of them:

${NAME}: 
	
^defines the build of the file NAME, it is better used with the rule
all

example:
	.PHONY: all
	
	all: ${NAME}

	${NAME}: ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o $@ 

-	-	-	-	-

all: 

^all compiles the entire program and should be the first target for make 

example:

	.PHONY : all
	all: executable

	executable: %.o
		${CC} ${CFLAGS} %.o ${OPTS} $@

	%.o: %.c
		${CC} ${CFLAGS} -c %.c
-	-	-	-	-

clean:
	rm %.o

^clean is a simple and clean shell command, 
simple and clean is the way that i want you to be when you write a Makefile 

-	-	-	-	-

fclean:
	rm -f ${FILE}

^fclean goes for file clean, the same use as clean but more targeted


-	-	-	-	-

re:
	
^re is used mostly for repeating a step or include another rule

example:

	re: fclean all

or

	re:
		${MAKE} fclean
		${MAKE} all

-	-	-	-	-

bonus:
	${MAKE} WITH_BONUS=1 all

^the bonus target serves to add bonus files to compilation,
using this method you can choose wether or not to compile with some files

example:

NAME		= exe
CC		= gcc
CFLAGS		= -Wall -Wextra -Werror
REG_OBJS	= file1.o file2.o
BONUS_OBJS	= file3.o file4.o

ifdef WITH_BONUS
REG_OBJS	= ${REG_OBJS} ${BONUS_OBJS}
endif

.PHONY: all clean re bonus

all: ${NAME}

${NAME}: ${REG_OBJS}
	${CC} ${CFLAGS} ${REG_OBJS} -o $@ | re

clean: 
	rm %.o

fclean:
	rm ${BONUS_OBJS}

re: 
	${MAKE} all
	${MAKE} fclean
bonus:
	${MAKE} WITH_BONUS=1 all 
