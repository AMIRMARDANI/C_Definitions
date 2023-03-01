/*___C instruction___:
Some instructions for C programming language
*/
/*___List___:
1-Volatile Variable.
2-Void Pointer.
3-Interrupt Latency.
*/

/*Template Name List.
Introduction:
Syntax:
Example:
*/


/*1-Volatile Variable.
Introduction:
The Volatile used to inform the compiler
that the variable value can be changed any
time without any task given by the source code.
Syntax:
volatile data_type variable_name;
volatile data_type *variable_name;
Example:
*/
volatile int x;
volatile int *a;
/*2-Void Pointer.
Introduction:
Till now, we have studied that the address assigned
to a pointer should be of the same type as specified
in the pointer declaration. For example, if we declare
the int pointer, then this int pointer cannot point to
the float variable or some other type of variable, i.e,
it can point to only int type variable. to overcome
this problem, we use a pointer to void. A pointer to
void means a generic pointer that can point to any data 
type, we can assign the address of any data type to 
the void pointer, and a void pointer can be assigned to
any type of the pointer without performing any explicit 
typecasting.
Syntax:
void *pointer name;
Example:
*/
void *ptr; //void pointer declaration
int i=9; //integer variable initialization
int *p; // integer pointer declaration
float *fp; //floating pointer declaration
p = fp; //incorrect
fp = &i //incorrect
ptr = p; //correct
ptr = fp;//correct
ptr = &i;

/*3-Interrupt Latency.
Introduction:
Interrupt latancy is the time that elapses
between the occurrence of an interrupt and
execution of the first instruction of the
interrupt service routine (ISR) that handles
the interrupt
Or:
Interrupt latancy is the time from the assertion of a hardware interrupt until the first instruction of the device driver's interrupt
handler is executed.
Syntax:
Example:

Interrupt occurs               Interrupt handler runs                      Interrupt handler finishes                    Interrupt process continues execution
........|<..............(Til)...............>|<..............(Tint)........................>|<...................(Tiret)........................>|.........................................>Time

Til: interrupt latancy
Tint: interrupt processing time
Tiret: interrupt termination time
*/

/*
4-printf() and scanf() functions
Description:
printf(): used to print: integer, character, float and string values on the screen:
%d: is format specifier used to print an integer value.
%s: string.
%c: character.
%f: floating point value.
scanf(): used to take input from the user.
Example:
*/
#include <stdio.h>
int main(){
	int number;
	printf("enter a number:");
	scanf("%d", &number);
	printf("cube of the number is: %d", number*number*number);
	return;
}

/*
5- Difference between local variable and global variable:
Description:
Basic for comparision | Local variable  | Global variable |
-----------------------------------------------------------
Declaration:          | inside function | outside function|
		      |	or block        | or block        |
-----------------------------------------------------------
Scope:                | available within| available       |
                      |  a function     | throughout the  |
                      |                 | program         |
-----------------------------------------------------------					  
Access:               | Inside the func | Entire program  |
-----------------------------------------------------------
Life:                 | Func start      | Program Execute |
		      |	until exit func |                 |
-----------------------------------------------------------
Srorage:              | Stack unless    | Compiler decide |
		      |	Specified       | storage location|
-----------------------------------------------------------
Example:
*/
int x1=10; //Global Variable
void function1(){
int x2=20; //Local Variable
}

/*
5- Difference between call by value and call by reference:
Description:
Basic for comparision | Call by value   | Call by ref     |
-----------------------------------------------------------
Declaration:          | When a copy of  | When a copy of  |
		      |	value passed to | value passed to |
		      |	the function,	| the function,   |
		      |	then the orginal| then the orginal|
		      | value is not	| value is        |
		      |	modified	| modified        |
-----------------------------------------------------------
Memory Location:      | actual argument | actual argument |
                      | &formal argument| &formal argument|
                      | are created in  | are created in  |
                      | separate memory | same memory     |
                      | location        | location        |
-----------------------------------------------------------					  
Safety:               | Actual arguments| Actual arguments|
                      | remain safe     | are not reliable|
-----------------------------------------------------------
Arguments:            | The copies of   | The addresses of|
		      |	the actual      | actual arguments|
		      |	arguments are	| are passed to   |
		      |	passed to the   | their respective|
		      | formal arguments| formal arguments|
-----------------------------------------------------------
Example:
*/
//call by values:
#include <stdio.h>
void change(int,int);
int main()
{
	int a=10, b=20;
	change(a,b); //calling a function by passing the values of variable
	printf("value of a is:%d", a);
	printf("\n");
	printf("value of b is:%d",b);
	return 0;
}
void change(int x, int y)
{
	x=13;
	y=17;
}
///-----> The output:
///value of a is: 10
///value of b is: 20

//call by reference:
#include <stdio.h>
void change(int*, int*);
int main()
{
	int a=10, b=20;
	change(&a,&b); //calling a function by passing references of variables.
	printf("value of a is:%d",a);
	printf("\n");
	printf("value of b is:%d",b);
	return 0;
}
void change(int*x, int*y)
{
	*x=13;
	*y=17;
}
///-----> The output:
///value of a is: 13
///value of b is: 17

/*
6-Recursion
Description:
When a function calls itself, so this process is known as recurion,
the function that calls itself known as a recursive function
recursive function comes in two phases:
1-Winding phase : When the recursive function calls itself, and this phase ends when the condition is reached
2-Unwinding phase : starts when the condition is reached, and the control returns to the original call.
Example:
*/
#include <stdio.h>
int calculate_fact(int);
int main()
{
	int n=5, f;
	f = calculate_fact(n); // calling a function
	printf("factorial of a number is %d",f);
	return 0;
}
int calculate_fact(int a)
{
	if (a==1)
	{
		return 1;
	}
	else
		return a*calculate_fact(a-1);
}
///-----> The output:
///factorial of a number is 120

/*
7-array
Description:
An array is a group of similar types of elements.
It has a contiguous memory location.
it optimize the code, it easy to traverse and sort.
The size and type of arrays cannot be changed after its declaration
arrays are two types:
- One-dimensional : Stores the elements one after the another
  Syntax: data_type array_name[size];
- multi-dimensional: contains more than one array
  Syntax: datatype array_name[size];
Example:
*/
int main()
{
	int arr[5]={1,2,3,4,5};
	for (int i=0;i<5;i++)
	{
		printf("%d",arr[i]);
	}
	return 0;
}
///-----> The output:
///1 2 3 4 5

/*
8-pointer
Description:
a pointer is a variable that refers to the address of a value,
whenever a variable is declared inside a program, then the systemallocates
some memory to a variable. The memory contains some address number.
The variables that holds this address number is known as the
pointer variable.
Advantage: optimize code, make performance fast
Usage of pointers:
-Accessing array elements.
-Dynamic memory allocation.
-Call by reference.
-Data Structures like a tree, graph, linked list, etc.
Syntax:
Data_type *p //p is a pointer variable that holds the address number of a given data type value
Example:
*/
#include <stdio.h>
int main()
{
	int *p; pointer of type integer
	int a=5;
	p = &a;
	printf("Address value of 'a' variable is %u",p);
	return 0;
}
///-----> The output:
///Address value of 'a' variable is 428781252

/*
9-NULL pointer
Description:
a pointer that doesn't refer to any address of value but NULL is known
as a NULL pointer. When we assign a '0' value to a pointer of any type,
then it becomes a Null pointer.
Example:
*/
int *p=NULL;

/*
9-far pointer
Description:
a pointer which can access all the 16 segments (whole residence memory)
of RAM is known as far pointer. A far pointer is a 32-bit pointer that
obtains information outside the memory in a given section
Example:
*/

#Address mapping
/*
please read below example about Address maping:

*/

#Structure size
/*
please read below example about Structure size:

*/