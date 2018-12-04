/* CS261- Assignment 1 - Q.3*/
/* Name:Zhouxiang Meng
 * Date:04-10-2015
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>

void sort(int* number, int n){
    
    int j, k, currscore, currid;
    for (j = (n - 1); j > 0; j--){
        for (k = 1; k <= j; k++){
            if (students[k - 1].score > students[k].score){
                currscore = students[k-1].score;
                currid = students[k-1].id;
                students[k-1].score = students[k].score;
                students[k-1].id = students[k].id;
                students[k].score = currscore;
                students[k].id = currid;
            }
        }
    /*Sort the given array number , of length n*/
}

int main(){
    
    int n = 20;
    /*Declare an integer n and assign it a value of 20.*/
    
    int *Array = (int *)malloc(sizeof(int)*n);
    /*Allocate memory for an array of n integers using malloc.*/
    
    for (int i = 0; i < n; i++) {
        Array[i] = rand();
    }
    /*Fill this array with random numbers between 0 and n, using rand().*/
    
    for (int i = 0; i < n; i++) {
        printf("%d\n", *(Array + i));
    }
    /*Print the contents of the array.*/
    
    sort(Array, n);
    /*Pass this array along with n to the sort() function.*/
    
    for (int i = 0; i < n; i++) {
        printf("%d\n", *(Array + i));
    }
    /*Print the contents of the array.*/
    
    return 0;
}
