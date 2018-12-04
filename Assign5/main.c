#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{
    char cmd = ' ';
    FILE *fptr;
    char temp[TASK_DESC_SIZE];
    char priorityTemp[5];
    int priority;
    char lFileName [100];
    char sFileName [100];
    DynArr* mainList = createDynArr(10);
    
  printf("\n\n** TO-DO LIST APPLICATION **\n\n");

  do
    {
      printf("Press:\n"
             "'l' to load to-do list from a file\n"
             "'s' to save to-do list to a file\n"
             "'a' to add a new task\n"
             "'g' to get the first task\n"
             "'r' to remove the first task\n"
             "'p' to print the list\n"
             "'e' to exit the program\n"
             );
      /* get input command (from the keyboard) */
      cmd = getchar();
      /* clear the trailing newline character */
      while (getchar() != '\n');

      /* Fixme:  Your logic goes here! */

        switch (cmd) {
            case 'l':
            {
                printf("Please enter the filename: ");
                fgets(lFileName, sizeof(lFileName), stdin);
                lFileName[strlen(lFileName)-1] = 0;
                fptr = fopen(lFileName, "r");
                if (fptr != NULL) {
                    loadList(mainList, fptr);
                    printf("The list has been loaded from file successfully.\n");
                }else{
                    printf("Load failed!\n");
                }
                fclose(fptr);
                break;
            }
            case 's':
            {
                printf("Please enter the filename: ");
                fgets(sFileName, sizeof(sFileName), stdin);
                sFileName[strlen(sFileName)-1] = 0;
                fptr = fopen(sFileName, "wr");
                if (fptr != NULL) {
                    saveList(mainList, fptr);
                    printf("The list has been saved into the file successfully.\n");
                }
                fclose(fptr);
                break;
            }
            case 'a':
            {
                TaskP task;
                printf("Please enter the task description: ");
                fgets(temp, sizeof(temp), stdin);
                temp[strlen(temp)-1] = 0;
                printf("Please enter the task priority (0-999): ");
                fgets(priorityTemp, sizeof(priorityTemp), stdin);
                priority = atoi(priorityTemp);
                task = createTask(priority,temp);
                addHeap(mainList, task, compare);
                if (containsDynArr(mainList, task, compare) == 1) {
                    printf("The task ");
                    print_type(task);
                    printf(" has been added to your to-do list.\n");
                }else{
                    printf("Add failed!\n");
                }
                
                break;
            }
            case 'g':{
                if (isEmptyDynArr(mainList)) {
                    printf("Your to-do list is empty!\n");
                }else{
                    
                    printf("Your first task is: ");
                    print_type(getMinHeap(mainList));
                    printf("\n");
                }
                break;
            }
            case 'r':
            {
                TaskP val;
                val = getMinHeap(mainList);
                removeMinHeap(mainList, compare);
                if (val != getMinHeap(mainList)) {
                    printf("Your first task ");
                    print_type(val);
                    printf(" has been removed from the list.\n");
                }else{
                    printf("Remove failed!\n");
                }
                break;
            }
            case 'p':
                if (isEmptyDynArr(mainList)) {
                    printf("You to-do List is empty!\n");
                }else{
                    printList(mainList);
                }
                break;
            default:
                break;
        }

      /* Note: We have provided functions called printList(), saveList() and loadList() for you
         to use.  They can be found in toDoList.c */
    }
  while(cmd != 'e');
  /* delete the list */
    print("ByeBye!!\n");
  deleteDynArr(mainList);

  return 0;
}
