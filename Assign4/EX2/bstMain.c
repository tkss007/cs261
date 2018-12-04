//
//  bstMain.c
//  HW4 Extra credit 2
//
//  Created by ZXL on 11/1/14.
//  Copyright (c) 2014 ZXL. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"
#include "structs.h"


double getMilliseconds() {
    return 1000.0 * clock() / CLOCKS_PER_SEC;
}

int main(){
    struct BSTree *tree;
    int n;
    struct data *val;
    double t1,t2,t3;
    srand(2);
    val = (struct data *)malloc(sizeof(struct data));
    for (n = 10000; n <=100000; n = n+10000) {
        struct data **temp;
        temp = (struct data **)malloc(sizeof(struct data*)*n);
        tree = newBSTree();
       
        t1 = getMilliseconds();
        for (int i = 0; i < n; i++) {
            
            temp[i] = (struct data *)malloc(sizeof(struct data));
            val->number = rand()%n;
            val->name = "111";
            temp[i] = val;
            addBSTree(tree, val);
        }
        
        t2 = getMilliseconds();
        printf("Time for running addBSTree() on %d elements: %g ms\n", n, t2-t1);

        for (int i = 0; i < n; i++) {
            removeBSTree(tree, temp[i]);
        }
        
        t3 = getMilliseconds();
        
        printf("Time for running removeBSTree() on %d elements: %g ms\n", n, t3-t2);
        
        deleteBSTree(tree);
    }
    
    
    
    
    
    
    return 1;
}