/*___C instruction___*/

/*
///Volatile Variable///
///Introduction:
The Volatile used to inform the compiler
that the variable value can be changed any
time without any task given by the source code.
///Syntax:
volatile data_type variable_name;
volatile data_type *variable_name;
///Example:
*/
volatile int x;
volatile int *a;

/*
///Void pointer///
//Introduction:
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
///Syntax:
void *pointer name;
///Example:
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







#Interrupts (latancy, process,...)
/*
please read below example about Interrupts:

*/

#Address mapping
/*
please read below example about Address maping:

*/

#Structure size
/*
please read below example about Structure size:

*/