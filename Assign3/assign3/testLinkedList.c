#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>


void assertTrue(int predicate, char *message)
{
    printf("%s: ", message);
    if (predicate)
        printf("PASSED\n\n");
    else
        printf("FAILED\n\n");
}


int main(int argc, char* argv[]) {
        

    struct linkedList *lk = createLinkedList();
    
    printf("\nTesting Linked List......\n\n");
    
    printf("Add 1 at back:\n");
    addBackList(lk, 1);
    printf("Add 2 at back:\n");
    addBackList(lk, 2);
    printf("Add 3 at front:\n");
    addFrontList(lk, 3);
    printf("Add 4 at back:\n");
    addBackList(lk, 4);
    printf("Add 5 at front:\n");
    addFrontList(lk, 5);
    printf("Add 6 at front:\n");
    addFrontList(lk, 6);
    
    
    printf("\n");
    assertTrue(EQ(frontList(lk), 6), "Test first node == 6");
    assertTrue(EQ(backList(lk), 4), "Test last node == 4");
    printf("\n");
    
    printf("Remove the front node:\n");
    removeFrontList(lk);
    
    
    printf("Add 7 at front:\n");
    addFrontList(lk, 7);
    
    printf("Remove the back node:\n");
    removeBackList(lk);
    
    assertTrue(EQ(isEmptyList(lk), 0), "Test linked list is no empty");
    
    printf("Add 8 at back:\n");
    addBackList(lk, 8);
    printf("Add 9 at back:\n");
    addBackList(lk, 9);
    printf("Add 10 at back:\n");
    addBackList(lk, 10);
    
    
    printf("Remove the front node:\n");
    removeFrontList(lk);
    
    printf("Remove the back node:\n");
    removeBackList(lk);
    
    assertTrue(EQ(containsList(lk,8), 1), "Test 8 is in the linked list");
    assertTrue(EQ(containsList(lk,7), 0), "Test 7 is not in the linked list");
    
    printf("Add 4 to bag\n");
    addList(lk,4);
    
    printf("Remove 3 from bag\n");
    removeList(lk,3);
    
    printf("Delete the linked list:\n");
    deleteLinkedList(lk);
	/* Test your linked list in here! */

	//printf("Hello from test code!\n");
	return 0;
}


