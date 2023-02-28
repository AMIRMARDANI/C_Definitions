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
                      |                 | program		  |
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
					  |	modified		| modified        |
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
#include <stdio.h>
void change(int,int);
int main()
{
	int a=10, b=
}

#Address mapping
/*
please read below example about Address maping:

*/

#Structure size
/*
please read below example about Structure size:

*/