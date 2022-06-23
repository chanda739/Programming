Implement the following functions using pointer arguments only

int Add(int *a, int *b) ;    //Add two numbers and return the sum
void AddVal(int *a, int *b, int *result); //Add two numbers and return the sum through the third pointer argument
void Swap(int *a, int *b) ;  //Swap the value of two integers
void Factorial(int *a, int *result);       //Generate the factorial of a number and return that through the second pointer argument


Implement the following functions

void Add(int a,int b, int &result) ;    //Add two numbers and return the result through a reference parameter
void Factorial(int a, int &result) ;    //Find factorial of a number and return that through a reference parameter
void Swap(int &a, int &b) ;            //Swap two numbers through reference arguments

Write the following code & do as instructed in the comments. Build and observe.

//Try to modify x1 & x2 and see the compilation output
int x = 5 ;
const int MAX = 12 ;
int &ref_x1 = x ;
const int &ref_x2 = x ;
 
//Try to modify the pointer (e.g. ptr1) and the pointee value (e.g. *ptr1)
const int *ptr1 = &x ;
int *const ptr2 = &x ;
const int * const ptr3 = &x ;
 
//Find which declarations are valid. If invalid, correct the declaration
const int *ptr3 = &MAX ;
int *ptr4 = &MAX ;
 
const int &r1 = ref_x1 ;
int &r2 = ref_x2 ;
 
int *&p_ref1 = ptr1 ;
const int*&p_ref2 = ptr2 ;
 
