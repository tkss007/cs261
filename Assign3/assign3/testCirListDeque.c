#include "cirListDeque.h"
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
    
    
    struct cirListDeque *clk = createCirListDeque();
    
    printf("\nTesting circular linked list......\n\n");
    
    printf("Add 12.3 at back:\n");
    addBackCirListDeque(clk, 12.3);
    printCirListDeque(clk);
    printf("Add 8.9 at front:\n");
    addFrontCirListDeque(clk, 8.9);
    printCirListDeque(clk);
    printf("Add 1.4 at front:\n");
    addFrontCirListDeque(clk, 1.4);
    printCirListDeque(clk);
    printf("Add 21.2 at front:\n");
    addFrontCirListDeque(clk, 21.2);
    printCirListDeque(clk);
    printf("Add 7.2 at back:\n");
    addBackCirListDeque(clk, 7.2);
    printCirListDeque(clk);
    printf("Add 13.3 at front:\n");
    addFrontCirListDeque(clk, 13.3);
    printCirListDeque(clk);
    printf("Add 4.5 at back:\n");
    addBackCirListDeque(clk, 4.5);
    printCirListDeque(clk);
    printf("Add 15 at back:\n");
    addBackCirListDeque(clk, 15);
    printCirListDeque(clk);
    printf("Add 6.62 at back:\n");
    addBackCirListDeque(clk, 6.62);
    printCirListDeque(clk);
    
    
    
    assertTrue(EQ(frontCirListDeque(clk),13.3),"Test first node == 13.3");
    assertTrue(EQ(backCirListDeque(clk),6.62),"Test last node == 6.62");
    
    
    printf("Remove front node:\n");
    removeFrontCirListDeque(clk);
    printCirListDeque(clk);
    printf("Remove back node:\n");
    removeBackCirListDeque(clk);
    printCirListDeque(clk);
    
    printf("Reverse the Deque:\n");
    reverseCirListDeque(clk);
    printCirListDeque(clk);
    isEmptyCirListDeque(clk);
    
    assertTrue(EQ(isEmptyCirListDeque(clk),0),"Test Circular list is not empty");
    
    //    freeCirListDeque(clk);
    
    deleteCirListDeque(clk);
    /* Test your linked list in here! */
    
    
    return 0;
}


