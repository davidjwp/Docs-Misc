# Makefile
### A non exaustive list of useful info on Makefiles
#### Basics
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

let's see how to compile a programm :

    FileName: file.o
	    gcc file.o -o FileName
    
    file.o: file.c
    	gcc -c file.c 
from up to down the Makefile looks at the first rul "Filename" which needs the dependency "file.o", "file.o" is a rule that compiles the c file into an object file.

it then uses the object file to create the output file "FileName".

now let's try a more complicated Makefile by simply adding more

    FileName: file1.o file2.o file3.o file3.o file4.o
	    gcc file1.o file2.o file3.o file3.o file4.o -o FileName
    
    file1.o file2.o file3.o file3.o file4.o: file1.c file2.c file3.c file3.c file4.c
	    gcc -c file1.c file2.c file3.c file3.c file4.c

The Makefile is suddendly a lot messier and harder to work with so let's use variables
    
    CC      = gcc
    NAME    = FileName
    
    $(NAME): %.o
	    $(CC) %.o -o $(NAME)

    %.o: %.c
	    $(CC) -c

Things have gotten much clearer but more complex as well, the variable CC corresponds to the gcc command then NAME is whatever we choose that way there is no need to replace the name if change it everytime it is written, the '%' s a pattern rule, which is a type of implicit rule. It specifies one target and one dependency, and causes one invocation of $(CC) for each target.

() and {} are the same and can be used interchangeably (but the squiggly looks cooler)
**automatic variables/make operands and prefix (the most useful so far)**

- **$@**    target name
- **$<**    first prerequisite
- **$^**    all prerequisites
- **$%**    member/s of target
- **$?**    names of the prerequisites that are newer than the target
- **$***    the stem of the pattern rule, if file.a and %.a then stem is file
            if no pattern rule then it will take the prefix, a.file.o then stem is a  

**general info**

    Target(member.o OtherMember.o):
	    	$(RULE)

.PHONY	is a target that stipulates the Makefile that the prerequisite target is not a build (a build is for when a target specifically creates a file
	every target is a build by default)

@	this prefix is used to tell the makefile not to display the command being executed,
	thus it is used before a command

the variable ${MAKE} is a recursive call to the Makefile and does not need to be 
#### STANDARD RULES

there are some standard rules used often to accomplish certain tasks and although we can call them by any name they do have names to recognize them by, here are some of them:

**${NAME}:** 
*defines the build of the file NAME, it is better used with the rule all*

example:
	
	.PHONY: all
	
	all: ${NAME}

	${NAME}: ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o $@ 

---

**all:** 
*compiles the entire program and should be the first target for make* 

example:

	.PHONY : all
	all: executable

	executable: %.o
		${CC} ${CFLAGS} %.o ${OPTS} $@

	%.o: %.c
		${CC} ${CFLAGS} -c %.c
---

**clean:**
*clean is a simple and clean shell command* 
*simple and clean is the way that i want you to be when you write a Makefile* 

 
    clean:	
	    rm %.o

---

**fclean:**
*fclean goes for file clean, the same use as clean but more targeted*

    fclean:
	    rm -f ${FILE}

---

**re:**
*reset is used mostly for repeating a step or include another rule*

example:

	re: fclean all

or

	re:
		${MAKE} fclean
		${MAKE} all

---

**bonus:**
*the bonus target serves to add bonus files to compilation*
*using this method you can choose wether or not to compile with some files*

	bonus:
	    ${MAKE} WITH_BONUS=1 all

example:

    REG_OBJS	= file1.o file2.o
    BONUS_OBJS	= file3.o file4.o
    
    ifdef WITH_BONUS
    REG_OBJS	= ${REG_OBJS} ${BONUS_OBJS}
    endif
    
    name: ${REG_OBJS}
	    gcc ${REG_OBJS} -o $@
    
    bonus:
	    ${MAKE} WITH_BONUS=1 all 
	    
or

    REG_OBJS	= file1.o file2.o
    BONUS_OBJS	= file3.o file4.o
    
    name: ${REG_OBJS}
	    gcc ${REG_OBJS} -o $@
    
    bonus: ${BONUS_OBJS}
	    gcc ${BONUS_OBJS} -o $@