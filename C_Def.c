/*___C instruction___:
Some instructions for C programming language
****************************************************
*****************www.amokh.ir***********************
**************************************************** 
Autors Name: Email : ListNumber/s
--------------------------------
1- Amir Mardani (AmirM) : mir.mardani@gmail.com : 1 to 31
--------------------------------
2- ?  

*/
/*___List___:
1-Volatile Variable. 
2-Void Pointer.
3-Interrupt Latency.
4-printf() and scanf() functions.
5-Difference between local variable and global variable.
6-Difference between call by value and call by reference.
7-Recursion.
8-array.
9-pointer.
10-NULL pointer.
11-far pointer.
12-dangling pointer.
13-pointer to pointer.
14-Static memory allocation.
15-Dynamic memory allocation.
16-structure.
17-union.
18-auto variable.
19-purpose of sprintf() function.
20-can we Compile program without main() function?.
21-command line argument.
22-difference between getch() and getche().
23-difference between near, far and huge pointer.
24-typecasting.
25-Access the array using a pointer.
26-Infinite For Loop.
27-write a program to print "hello world" without using a semicolon.
28-write a program to swap two numbers without using the third variable.
29-print Fibonancci series without using recursion.
30-print Fibonancci series with using recursion.
31-pointer using examples.
*/

/*1-Volatile Variable:
Introduction:
The Volatile used to inform the compiler
that the variable value can be changed any
time without any task given by the source code.
The compiler reloads the value from memory each time
it's accessed by the program that means it prevents from
cache a variable into a register.

Using:
The volatile keyword is mainly used where we directly
deal with GPIO. interrupt or flag Register. It is also
used with a global variable or buffer which shared
between the threads. 

Syntax:
volatile data_type variable_name;
volatile data_type *variable_name;

1-1: What is the difference between the const and volatile qualifiers in C?
1-1-1: constant keyword or variable:
	the const keyword is compiler-enforced and says that
	the program couldn't change the value of the object
	that means it makes the object nonmodifiable type.
	If we will try to modify the const value, we will get
	the compiler error because const value is qualified with const
	keyword that prevents to change the value of the const value
	
	Example:
	
	const int a = 0;
	
1-2: Can a variable be both constant and volatile:
yes, as you know one of the great use of volatile and const
keyword together is at the time accessing the GPIO registers.
Volatile plays an important role and ensures that the compiler
always read the value from the GPIO address and avoid to make any assumption.

After using the volatile keyword to reading GPIO value, you
will get the proper value whenever you are accessing the ports
but still here is one more problem because the pointer is not 
const type so it might be your program change the pointing
address of the pointer. So we have to create a constant pointer
with a volatile keyword.
	
Syntax:
int volatile * const PortRegister;
 |     |     |   |    |
 |     |     |   |    +------> PortRegister is a
 |     |     |   +-----------> constant
 |     |     +---------------> pointer to a
 |     +---------------------> volatile
 +---------------------------> integer


1-3: Can we have a volatile pointer:
Yes, we can create it.
//in bellow example piData is a volatile pointer to an integer.
int *volatile piData;

Example1: Comertial use
*/
volatile int x;
//Example2: volatile pointer
volatile int *a;

//Example3: accessing the memory-mapped peripherals register or hardware status register:
#define COM_STATUS_BIT 0x00000006
uint32_t const volatile * const pStatusReg = (uint32_t*)0x00020000;

uint32_t GetRecvData()
{
	uint32_t RecvData;
	
	while ((*pStatusRe) & COM_STATUS_BIT) == 0)
	{
		//Wait until flag does not set
		//Recieved data in RecvData
	}
	
	//
}


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
ptr = &i;//correct

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
6- Difference between call by value and call by reference:
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
7-Recursion
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
8-array
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
9-pointer
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
10-NULL pointer
Description:
a pointer that doesn't refer to any address of value but NULL is known
as a NULL pointer. When we assign a '0' value to a pointer of any type,
then it becomes a Null pointer.
Example:
*/
int *p=NULL;

/*
11-far pointer
Description:
a pointer which can access all the 16 segments (whole residence memory)
of RAM is known as far pointer. A far pointer is a 32-bit pointer that
obtains information outside the memory in a given section
Example:
*/

/*
12-dangling pointer
Description:
If a pointer is pointing any memory location, but meanwhile another pointer deletes
the memory occupied by the first pointer while the first pointer still points to that
memory location, the first pointer will be known as a dangling pointer. This problem
is known as a dangling pointer problem.
Dangling pointer arises when an object is deleted without modifying the value of
the pointer. The pointer points to the deallocated memory.
Example:
In the below example, initially memory is allocated to the pointer variable ptr,
and then the memory is deallocated from the pointer variable. now,
pointer variable, i.e, ptr become a dangling pointer
How to overcome the problem of a dangling pointer?
by assing a NULL value to the dangling pointer and
this means that ptr does not point to any memory location
*/
#include <stdio.h>
void main()
{
	int *ptr = malloc(constant value);//allocating a memory space.
	free(ptr); //ptr becomes a dangling pointer.
	ptr = NULL; //Now, ptr is no longer a dangling pointer
}	

/*
13-pointer to pointer
Description:
It means, one pointer refers to the address of another pointer.
pointer to pointer is a chain of pointers, generally, the pointer
contains the address of a variable. the pointer to pointer contains
the address of a first pointer.
Example1:
In the bellow example, pptr is a double pointer pointing to the 
address of the ptr variable and ptr points to the address of 'a' variable.
*/
#include<stdio.h>  
void main ()  
{  
    int a = 10;  
    int *p;  
    int **pp;   
    p = &a; // pointer p is pointing to the address of a  
    pp = &p; // pointer pp is a double pointer pointing to the address of pointer p  
    printf("address of a: %x\n",p); // Address of a will be printed   
    printf("address of p: %x\n",pp); // Address of p will be printed  
    printf("value stored at p: %d\n",*p); // value stoted at the address contained by p i.e. 10 will be printed  
    printf("value stored at pp: %d\n",**pp); // value stored at the address contained by the pointer stoyred at pp  
}  
///-----> The output:
///address of a: d26a8734
///address of p: d26a8738
///value stored at p: 10
///value stored at pp: 10
/*
Example2:
As you can see in the below example, p2 contains the address of p (fff2),
and p contains the address of number variable (fff4).

fff0 |     |      |
-----|-----|------|
fff2 |fff2 |      |
-----|-----|------|
p2   |fff4 |fff4  |
-----|-----|------|
     |p    |50    |
-----|-----|------|
     |     |number|	 
*/
#include<stdio.h>  
int main(){  
int number=50;      
int *p;//pointer to int    
int **p2;//pointer to pointer        
p=&number;//stores the address of number variable      
p2=&p;    
printf("Address of number variable is %x \n",&number);      
printf("Address of p variable is %x \n",p);      
printf("Value of *p variable is %d \n",*p);      
printf("Address of p2 variable is %x \n",p2);      
printf("Value of **p2 variable is %d \n",*p);      
return 0;  
}  
///-----> The output:
///Address of number variable is fff4
///Address of p variable is fff4
///Value of *p variable is 50
///Address of p2 variable is fff2
///Value of **p variable is 50	

/*
14-Static memory allocation
Description:
- in case of static memory allocation, memory is allocated at compile
  time, and memory can't be increased while executing the program.
  it is used in the array.
- lifetime of a variable in static memory is the lifetime of a program.
- static memory is allocated using static keyword.
- The static memory is implemented using stacks or heap.
- The pointer is required to access the variable present in the static memory.
- The static memory is faster than dynamic memory.
- In static memory, more memory space is required to store the variable.
Example:
*/
int a[10];

/*
15-Dynamic memory allocation
Description:
 - in case of static memory allocation, memory is allocated at run
   time, and memory can be increased while executing the program.
  it is used in the linked list.
 - The malloc() or calloc() function is required to allocate the memory at the runtime
 - An allocation or deallocation of memory is done at the execution time of a program.
 - No dynamic pointers are required to access the memory.
 - The dynamic memory is implemented using data segments.
 - Less memory space is required to store the variable.
Functions:
-malloc():
 - the malloc() function is used to allocate the memory during
   the execution of the program
 - it does not initialize the memory but carries the garbage value.
 - it returns a null pointer if it could not be able to allocate
   the requested space
 -syntax:
  ptr = (cast-type*) malloc(byte-size) // allocating the memory using malloc() function.
-calloc():
 - The calloc() is same as malloc() function, but the difference
	only is that it inilializes the 
Example:
The bellow example allocates the memory at runtime.
*/
int *p = malloc(sizeof(int)*10); 


/*
16-structure
Description:
- the structure is a user-defined data type that allows
  storing multiple types of data in a single unit. It 
  occupies the sum of the memory of all members.
- the structure members can be accessed only through structure variables
- structure variables accessing the same structure but the memory
  allocated for each variable will be different

Syntax:
 struct sturct_name
 {
	 Member_variable1;
	 Member_variable2;
	 .
	 .
 } [structure variables];

Example:
*/
#include <stdio.h>
struct student
{
	char name[10]; //structure members declaration.
	int age;
}s1; //structure variabel
int main()
{
	printf("Enter the name");
	scanf("%s",s1.name);
	printf("\n");
	printf("Enter the age");
	scanf("%d",&s1.age);
	printf("\n");
	printf("Name and age of a student: %s,%d",s1.name,s1.age);
	return 0;
	
}
///-----> The output:
///Enter the name Amir
///Enter the age 26
///Name and age of a student: Amir,26  

/*
17-union
Description:
	-The union is a user-defined data type that allows sroting
	multiple types of data in a single unit. However,
	it doesn't occupy the sum of the memory of all members,
	it holds the memory of the largest member only.
	- In union, we can  access only one variable at
	a time as is allocates one common space for all the 
	members of a union.

Syntax:
	union union_name
	{
		Member_variable1;
		Member_variable2;
		.
		.
		Member_variable_n;
	}[union variables];

Example:
In bellow example, the value of a and b gets corrupted,
and only variable ch shows the actual output. This is 
because all the numbers of a union share the common 
memory space. Hence, the variable ch whose value is 
currently updated.
*/
#include <stdio.h>
union data
{
	int a; //union members declaration.
	float b;
	chat ch;
};
int main()
{
	union data d; // union variable
	d.a = 3;
	d.b = 5.6;
	d.ch = 'a';
	printf("value of a is %d",d.a);
	printf("\n");
	printf("value of b is %f",d.b);
	printf("\n");
	printf("value of ch is %d",d.ch);
	return 0;
	
}
///-----> The output:
///value of a is 1085485921
///value of b is 5.600022
///value of ch is a  

/*
18-union
Description:
In C, every local variable of a function is known as an automatic (auto) variable.
variable. Variables which are declared inside the function block are known as a
local variable. The local variables are also known as an auto variable. It is
optional to use an auto keyword before the data type of a variable. If no value
is stored in the local variable, then it consists of a garbage value. 
Example:

*/

/*
19-purpose of sprintf() function
Description:
The sprintf() stands for "string print". The sprintf()
function does not print the output on the console screen.
It transfers the data to the buffer. It returns the total
numbers of characters present in the string.
Syntax:
	int sprintf(char *str, const char *format,...);
Example:

*/
#include<stdio.h>
int main()
	{
		char a[20];
		int n=sprintf(a,"javaToint");
		printf("value of n is %d",n);
		return 0;
	}
///-----> The output:
///value of n is 9
/*
20-can we Compile program without main() function?
Description:
Yes, we can compile but it can't be executed.
but if we use #define, we can compile and run a c program without
using the main() function.
Example:
*/
#include <stdio.h>
#define start main
void start ()
{
	print("Hello");
}

/*
21-command line argument
Description:
The argument passed to the main() function while executing
the program is known as command line argument
Example:
*/
main (int count, char *args[]){
//code to be executed
}

/*
22-difference between getch() and getche()
Description:
getch() function: reads a single character from the keyboard.
It doesn't use any buffer, so entered data will not be 
displayed on the output screen.
getche() function: reads a single character from the keyboard.
but data is displayed on the output screen. press Alt+f5
to see the entered character displayed on the output screen.
Example:
in below example, the value entered through a getch() function
is not displayed on the screen while the value entered through
a getche() function is displayed on the screen.
*/
#include <stdio.h>
#include <conio.h>
int main()
{
	char ch;
	printf ("Enter a character");
	ch = getch(); //taking an user input without printing the value
	printf("\nvalue of ch is %c",ch);
	printf("\nEnter a character again");
	ch = getche();//taking an user input and then displayed it on the screen
	printf("\nvalue of ch is %c",ch);
	return 0;
}
///-----> The output:
///Enter a character
///value of ch is a
///Enter a character again a
///value of ch is a

/*
23-difference between near, far and huge pointer
Description:
A virtual address is composed of the selector and offset.

A given logical address consists of two parts:
Segment Identifier and an Offset.

Segment Identifier is a 16-bit field which we call as
Segment Selector and Offset is a 32-bit field.

" Think of Segment Identifier as a Street Address in a town
and offset is a number which will tell you at which position
the house you are looking for is located
 Now this city has many streets with unique Street Address
 or we can say have a unique segment Identifier and
 have an offset for the specific house (data/instruction)
 of your interest"
"
With this introduction so:
A near pointer doesn't have explicit selector whereas
far, and huge pointers have explicit sector. When you
perform pointer arithmetic on the far pointer, the 
selector is not modified, but in case of a huge pointer,
it can be modified.
These are the nonstandard keywords and implementation
specific. these are irrelevant in a modern platform
Example:
*/

/*
21-maximun length of an identifier
Description:
It's 32 characters ideally but implementation specific
Example:
*/

/*
24-typecasting
Description:
the typecasting is a process of converting one data type
into another is known as typecasting. If we want to store
the floating type value to an int type, then we will convert
the data type into another data type explicity
Syntax:
(type_name) expression;
*/

/*
25-Access the array using a pointer
Description:
By holding the base address of array into a pointer,
we can access the array using a pointer
(type_name) expression;
Example:
*/
//Example 1: Access the array elements using a pointer
#include <stdio.h>
int main()
{
	int p[5] = {8,9,10,11,12}, i;
	int *ptr = p;
	for (i=0; i<5; i++)
		printf("&p[%d] = %p \t p[%d] = %d\n", i, ptr+i, i, *(ptr+i));
	return 0;
}
///-----> The output:
///&p[0] = 0x7ffeafbc9190	 p[0] = 8
///&p[1] = 0x7ffeafbc9194	 p[1] = 9
///&p[2] = 0x7ffeafbc9198	 p[2] = 10
///&p[3] = 0x7ffeafbc919c	 p[3] = 11
///&p[4] = 0x7ffeafbc91a0	 p[4] = 12

//Example 2: Modifying elements of array using pointer
int main ()
{
	int p[5] = {8,9,10,11,12}, i;
	int *ptr = p;
	*(ptr+3) = 16;
	for (i=0; i<5; i++)
		printf ("&p[%d] = %p \t p[%d] = %d\n", i, ptr+i, i, *(ptr+i));
	return 0;	
}
///-----> The output:
///&p[0] = 0x7ffef151f3c0	 p[0] = 8
///&p[1] = 0x7ffef151f3c4	 p[1] = 9
///&p[2] = 0x7ffef151f3c8	 p[2] = 10
///&p[3] = 0x7ffef151f3cc	 p[3] = 16
///&p[4] = 0x7ffef151f3d0	 p[4] = 12
/*
26-Infinite For Loop
Description:
Infinite For Loop:

	for(;;){
	}

Infinite While Loop:

	while(1){
	}

Infinite Do-While Loop:
	
	do{
	}while(1);

*/

/*
27-write a program to print "hello world" without using a semicolon 
Example:
*/
#include <stdio.h>
void main(){
	if (printf("hello world")){} // it prints the hello world on the screen
}

/*
28-write a program to swap two numbers without using the third variable 
Example:
*/
#include<stdio.h>
#include<conio.h>
void main(){
int a=10, b=20; // declaration of variables.
clrscr(); //It clears the screen.
printf("before swap a=%d b=%d", a, b);
a= a+b; // a = 30 (10+20)
b = a-b; // b = 10 (30-20)
a = a-b; // a = 20 (39 - 10)
printf("\nAfter swap a=%d b=%d,a,b);
getch();
}

/*
29-print Fibonancci series without using recursion:
Example:
*/
#include <stdio.h>
#include <conio.h>
void main()
{
	int n1=0,n2=1,n3,i,number;
	clrscr();
	printf("Enter the number of elements:);
	scanf("%d",&number);
	printf("\n%d %d",n1,n2);//printing 0 and 1
	
	for (i=2;i<number;++i)//loop starts from 2 because 0 and 1 are already printed
	{
		n3 = n1+ n2;
		printf("%d",n3);
		n1=n2;
		n2=n3;
	}
	getch();
}
/*
30-print Fibonancci series with using recursion:
Example:
*/
#include <stdio.h>
#include <conio.h>
void printFibonacci(int n) // function to calculate the fibonacci series of a given number
{
	static int n1=0,n2=1,n3; //declaration of static variables.
	if (n>0){
		n3 = n1 + n2;
		n1=n2;
		n2=n3;
		printf("%d",n3);
		printFibonacci(n-1); //calling the function recursively.
	}
}
void main(){
	int n;
	clrcsr();
	printf("Enter the number of elements");
	scanf("%d",&n);
	printf("Fibonancci Series:");
	printf("%d%d",0,1);
	printFibonacci(n-2);//n-2 because 2 numbers are already printed
	getch();

}


/*
31-pointer using examples
Example:
*/
//below line declares a pointer of type uint32_t*, but the pointer
//is uninitialized, that is, the pointer does not to anywhere in particular.
//Trying to access memory through that pointer will cause undefined behaviour
// and your program might crash
uint32_t* ptr;
//below line is just a variable of type uint32_t
uint32_t num;
//in below line: ptr+num returns you a new pointer. It called pointer arithmetic.
//it's like regular arithmetic, only that compiler takes the size of type
//into consideration. think of ptr+num as the memory address based on
//original ptr pointer plus the number of bytes for nume uint32_t objects.
//The (uint32_t*) is a cast
*(uint32_t*)(ptr+num);




#Address mapping
/*
please read below example about Address maping:

*/

#Structure size
/*
please read below example about Structure size:

*/



