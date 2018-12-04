/* CS261- Assignment 1 - Q.4*/
/* Name:Zhouxiang Meng
 * Date:04-10-2015
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>

struct student{
    int id;
    int score;
};

void sort(struct student* students, int n){
    
    
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
    }
    
    
    /*Sort the n students based on their score*/
    /* Remember, each student must be matched with their original score after sorting */
}

int main(){
    
    int n = 10;
    /*Declare an integer n and assign it a value.*/
    
    struct student *students = (struct student*)malloc(sizeof(struct student)*n);
    /*Allocate memory for n students using malloc.*/
    
    int randID;
    for (int i = 0; i < 10; i++) {
        
        int flag;
        do{
            
            flag = 1;
            randID = (rand() % 10 + 1);
            for (int j=0; j<10&&flag == 1; j++) {
                if((students + j)->id == randID){
                    flag = 0;
                }
            }
        }
        while (flag ==0);
        
        (students + i) -> id = randID;
        (students + i) -> score = rand() % 101;
    }
    /*Generate random IDs and scores for the n students, using rand().*/
    
    for (int i = 0; i < n; i++) {
        printf("%d, %d\n", (students + i)->id, (students + i)->score);
    }
    /*Print the contents of the array of n students.*/
    
    printf("\n");
    
    sort(students, n);
    /*Pass this array along with n to the sort() function*/
    
    for (int i = 0; i < n; i++) {
        printf("%d, %d\n", (students + i)->id, (students + i)->score);
    }
    /*Print the contents of the array of n students.*/
    
    return 0;
}
