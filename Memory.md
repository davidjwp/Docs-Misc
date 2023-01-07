# Memory

**a brief overview of how memory works in the c language**

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
int	*function(int *ptr2)
{
	for(int i = 0; i < 5; i++)
		ptr2++;
	return (ptr2);
}

int	main(void)
{
	int	ptr0[] = {0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9};
	int	*ptr1 = ptr0;

	for(int i = 0; i < 5; i++)
		 ptr1++;
	ptr1 = function(ptr1);
	return (0);
}
```

in this example the we iterate over an array of 10 to 5, then give that pointer to a function which does the same thing


pointers can also be compared in if loops just like a regular variable, but it will compare the memory address instead 
of a regular number like so :

int	main(void)
{
	int	arr[] = {0, 1, 2, 3, 4, 5, 6, 8, 7, 8, 9};
	int	*ptr1;
	int	*ptr2;

	ptr1 = arr;
	ptr2 = arr;
	//iterating ptr1 to arr[5]	
	for (int i = 0; i < 5; i++)
		ptr1++;
	//we can compare the address of the pointers, ptr1 now has a bigger address than ptr2
	if (ptr1 > ptr2)
		printf ("ptr1 has a bigger address");
	return (0);
}
FUNCTION POINTERS.	.	.	.	.	.	.	.	.	.	.	.	.	.

pointers can do many things, and one of theyre biggest uses is to point to a function like so :

int (*f)(int);

this is a function pointer declaration, it takes an integer as an argument and is a integer type, so far this pointer is 
uninitialized let's do that :

0	int	func(int a)
1	{
2		a += 5;
3		return (a);
4	}
5	
6	int	main(void)
7	{
8		int	(*f)(int);
9		int	a;
10	
11		a = 0;
12		f = &func;
13		for (int i = 0; i < 5; i++)
14			a = f(a);
15		return (0);
16	}

here we have initialized the function pointer on line 12, f now points to func, much like func f return an in and takes 
an int.

we then iterate five times over a, each time applying f to a, f points to func so when we use f we use func with argument a
returning a + 5, thus the loop adds 5 five times, at the end of the loop a = 25.

 
STACK.	.	.	.	.	.	.	.	.	.	.	.	.	.	.	.
when we initalize memory by doing virtually anything like starting a program with a main or creating a function or 
creating variables we allocate memory on the stack one after the other, here is an example of what i mean:
```
int	main(void)
{
	int	var;
	
	var = 5;
	return (0);
}
```
here we begin allocating memory by creating a main then the arguments might come after and the variable var, memory 
allocation is a little more complicated but this will do to understand the stack and how pointers can interact with
it, all that memory allocated goes from top to bottom this is how the stack works, and that memory stays within the scope
of the function and together, meaning that the memory addresses are together in order of when they were created.


it is generally a bad idea to read uninitialized memory you might come across some bugs, for example using the function 
strlcat on an uninitialized string will return a random integer based on where the string is created in the stack.
