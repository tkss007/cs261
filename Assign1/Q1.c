/* CS261- Assignment 1 - Q.1*/
/* Name:Zhouxiang Meng
 * Date:04-10-2015
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
    int id;
    int score;
};

struct student* allocate(){
    
    struct student *students = (struct student*)malloc(sizeof(struct student)*10);    /*Allocate memory for ten students*/
    
    return students;
    /*return the pointer*/
}

void generate(struct student* students){
    
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
    /*Generate random ID and scores for 10 students, ID being between 1 and 10, scores between 0 and 100*/
    
}

void output(struct student* students){
    
    for (int i = 0; i < 10; i++) {
        printf("%d, %d\n", (students + i)->id, (students + i)->score);
    }
    /*Output information about the ten students in the format:
     ID1 Score1
     ID2 score2
     ID3 score3
     ...
     ID10 score10*/
}

void summary(struct student* students){
    
    int minimum = 100;
    int maximum = 0;
    int sum = 0;
    float average = 0.00;
    /*Compute and print the minimum, maximum and average scores of the ten students*/
    
    int i = 0;
    
    
    for (i = 0; i < 10; i++) {
        if (students[i].score < minimum) {
            minimum = students[i].score;
        }
    }
    
    for (i = 0; i < 10; i++) {
        if (students[i].score > maximum) {
            maximum = students[i].score;
        }
    }
    
    for (i = 0; i < 10; i++) {
        sum += students[i].score;
    }
    average = sum / 10;
    
    printf("minimum score is: %d\n", minimum);
    printf("maximum score is: %d\n", maximum);
    printf("average score is: %f\n", average);
}

void deallocate(struct student* stud){
    
    if (stud != NULL) {
        free(stud);
        stud = 0;
    }
    /*Deallocate memory from stud*/
}

int main(){
    struct student* stud = NULL;
    
    stud = allocate();
    /*call allocate*/
    
    generate(stud);
    /*call generate*/
    
    output(stud);
    /*call output*/
    
    summary(stud);
    /*call summary*/
    
    deallocate(stud);
    /*call deallocate*/
    
    return 0;
}
