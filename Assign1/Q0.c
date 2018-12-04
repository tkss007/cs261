/* CS261- Assignment 1 - Q. 0*/
/* Name:Zhouxiang Meng
 * Date:04-10-2015
 * Solution description: print the address and value of x
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
    printf("the value pointed to bt iptr: %d\n", *iptr);
    /*Print the value pointed to by iptr*/
    
    printf("the address pointed to bt iptr: %p\n", iptr);
     /*Print the address pointed to by iptr*/
    
    printf("the address of iptr: %p\n", &iptr);
     /*Print the address of iptr itself*/
}

int main(){
    
    int x = 0;
    /*declare an integer x*/
    
    printf("the address of x: %p\n", &x);
    /*print the address of x*/
    
    fooA(&x);
    /*Call fooA() with the address of x*/
    
    printf("the value of x: %d\n", x);
    /*print the value of x*/
    
    return 0;
}
