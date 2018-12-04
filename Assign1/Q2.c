/* CS261- Assignment 1 - Q.2*/
/* Name:Zhouxiang Meng
 * Date:04-10-2015
 * Solution description: double the value of x and half the value of y, then return x + y
 */

#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    *a = 2 * ( *a );
    /*Set a to double its original value*/
    * b = ( *b ) / 2;
    /*Set b to half its original value*/
    
    c = *a + *b;/*Assign a+b to c*/
    
    return c;/*Return c*/
}

int main(){
    int x = 7, y = 8, z = 9;
    int fooresult;
    /*Declare three integers x,y and z and initialize them to 7, 8, 9 respectively*/
    printf ("x = %d\n", x); /*Print the values of x, y and z*/
    printf ("y = %d\n", y);
    printf ("z = %d\n", z);
    
    fooresult = foo(&x, &y, z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
    
    printf("%d\n", fooresult);
    /*Print the value returned by foo*/
    
    printf ("x = %d\n", x);       /*Print the values of x, y and z again*/
    printf ("y = %d\n", y);
    printf ("z = %d\n", z);
    /*Is the return value different than the value of z?  Why?*/
    return 0;
}


