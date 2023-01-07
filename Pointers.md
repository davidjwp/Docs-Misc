## Pointers

**a brief overview of pointers and how to use them**

##### POINTERS

A pointer is a variable that stores the physical address in memory of another variable or value
we say the pointer references that variable and we can then dereference that variable to access the actual 
value of the what the pointer points to in memory.

c is a low level language with a high focus on memory management thus pointers are extremely useful and are used for
numerous different things. 

since pointers store memory addresses and this address is a number it can be added or substracted like any other variable
here is an example :
```
int	*ptr;
int	var;

ptr = var;
ptr++;
```
in this example the pointer iterates it's pointed address and points to the next memory address, if we dereference ptr we would get a random value since that memory address has not been initialized.

when a pointer that has been iterated gets passed into an argument, the functions pointer created as argument 
takes the address of the passed pointer as it's value, here is an example :
```
int iter(int *ptr2)
{
	for(int i = 0; i < 4; i++)
		ptr2++;
	return (*ptr2);
}

int	main(void)
{
	int	arr[] = {0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9};
	int	*ptr1 = arr;

	for(int i = 0; i < 5; i++)
		 ptr1++;
	printf("%i", iter(ptr1));
	return (0);
}
```

in this example we iterate a pointer over an array of 10 elements to 5, then give that pointer to a function which iterates to 4 the ouput of that function gets printed to standard output
```
9
```

memory addresses can also be compared just like regular values like so :
```
#include <stdio>

int	main(void)
{
	int	arr[] = {0, 1, 2, 3, 4, 5, 6, 8, 7, 8, 9};
	int	*ptr1;
	int	*ptr2;

	ptr1 = arr;
	ptr2 = arr - 5;
	for (int i = 0; i < 5; i++)
		ptr2++;
	if (ptr1 > ptr2 || ptr1 < ptr2)
		printf ("pointers are not equal");
	else
        printf ("pointers are equal");
    return (0);
}
```

In this example the pointers are set to arr (it's first position in the array) but one is set 5 spaces back in memory addresses then we iterate that pointer to 'i' value 5 and compare them to see wether they are equal or not, we can also change that value to see a different output.

if we advance ptr2 to 5 

```
pointers are equal
```
else
```
pointers are not equal
```
##### FUNCTION POINTERS

Pointers can also point to a function since functions are declared in memory, that memory address can be use to reference the function, here is the syntax to do so.
```
int (*f)(int);
```
this is a function pointer declaration, it takes an integer as an argument and is a integer type, so far this pointer is 
uninitialized let's do that :
```
#include <stdio.h>

int add25(int a)
{
	a += 25;
	return (a);
}

int	main(void)
{
	int	(*f)(int);
	int	a;
	
	a = 0;
	f = &add25;
	printf("%i", f(25));
	return (0);
}
```
here we have initialized the function pointer to add25 by referencing the function and assigning it to f, f now contains the memory address of add25, f returns an int and takes an int.

when f() is written the function add25 is called, in the example f(25) is called and it's output gets redirected to standard output giving 
```
50
```
function pointers are mostly used as function arguments to give a function to a function.

##### STACK

![stack_full](https://en.wikipedia.org/wiki/Stack-based_memory_allocation#/media/File:ProgramCallStack2_en.svg)

when we initalize memory by doing virtually anything, like starting a program with a main or creating a function or 
creating variables we allocate memory on the stack one after the other, here is an example of what i mean:
```
int	main(void)
{
	int	var;
	
	var = 5;
	return (0);
}
```
here we begin allocating memory in the stack by creating a main then the arguments and the memory address of main gets pushed down in the stack and again with the variable var it gets pushed further down.

all that memory allocated goes from top to bottom, this is how the stack works, and that memory stays within the scope
of the function and together, meaning that the memory addresses are together in order of when they were created in physical memory, the program memory constantly changes location as memory gets rewritten but memory in the same scope stays together.

##### WIP
it is generally a bad idea to read uninitialized memory you might come across some bugs, for example using the function 
strlcat on an uninitialized string will return a random integer based on where the string is created in the stack.
