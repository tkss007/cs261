#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamicArray.h"
#include "math.h"


/* param: s the string
 param: num a pointer to double
 returns: true (1) if s is a number else 0 or false.
 postcondition: if it is a number, num will hold
 the value of the number
 */
int isNumber(char *s, double *num)
{
    char *end;
    double returnNum;
    
    if(strcmp(s, "0") == 0)
    {
        *num = 0;
        return 1;
    }
    else
    {
        returnNum = strtod(s, &end);
        /* If there's anythin in end, it's bad */
        if((returnNum != 0.0) && (strcmp(end, "") == 0))
        {
            *num = returnNum;
            return 1;
        }
    }
    return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their sum is pushed back onto the stack.
 */
void add (struct DynArr *stack)
{
    double i, j, sum;
    i = 0;
    j = 0;
    sum = 0;
    i = topDynArr(stack);
    popDynArr(stack);
    j = topDynArr(stack);
    popDynArr(stack);
    sum = i + j;
    pushDynArr(stack, sum);
    
    /* FIXME: You will write this function */
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their difference is pushed back onto the stack.
 */
void subtract(struct DynArr *stack)
{
    double i = 0;
    double j = 0;
    double sub = 0;
    i = topDynArr(stack);
    popDynArr(stack);
    j =topDynArr(stack);
    popDynArr(stack);
    sub = j-i;
    pushDynArr(stack, sub);

    /* FIXME: You will write this function */
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their quotient is pushed back onto the stack.
 */
void divide(struct DynArr *stack)
{
    double i = 0;
    double j = 0;
    double div  = 0;
    i = topDynArr(stack);
    popDynArr(stack);
    j =topDynArr(stack);
    popDynArr(stack);
    div = j / i;
    pushDynArr(stack, div);
    /* FIXME: You will write this function */
}

double calculate(int numInputTokens, char **inputString)
{
    int j;
    double result = 0.0;
    char *s;
    struct DynArr *stack;
    char *error = NULL;
    
    //set up the stack
    stack = createDynArr(20);
    
    // start at 1 to skip the name of the calculator calc
    for(j=1;j < numInputTokens;j++)
    {
        s = inputString[j];
        
        // Hint: General algorithm:
        // (1) Check if the string s is in the list of operators.
        //   (1a) If it is, perform corresponding operations.
        //   (1b) Otherwise, check if s is a number.
        //     (1b - I) If s is not a number, produce an error.
        //     (1b - II) If s is a number, push it onto the stack
        
        if(strcmp(s, "+") == 0)
            add(stack);
        else if(strcmp(s,"-") == 0)
            subtract(stack);
        else if(strcmp(s, "/") == 0)
            divide(stack);
        else if(strcmp(s, "x") == 0){
            double i, j, multiplying;
            i = 0;
            j = 0;
            multiplying = 0;
            if (sizeDynArr(stack) >= 2) {
                i = topDynArr(stack);
                popDynArr(stack);
                j = topDynArr(stack);
                popDynArr(stack);
                multiplying = i * j;
                pushDynArr(stack, multiplying);
            }
            printf("Multiplying\n");
        }
        /* FIXME: replace printf with your own function */
        
        else if(strcmp(s, "^") == 0)
            
        {
            double i = 0;
            double j = 0;
            double power  = 0;
            if(sizeDynArr(stack) >= 2)
            {
                i = topDynArr(stack);
                popDynArr(stack);
                j =topDynArr(stack);
                popDynArr(stack);
                power = pow(j,i);
                pushDynArr(stack, power);
                printf("Power\n");
            }
        }
        /* FIXME: replace printf with your own function */
        
        else if(strcmp(s, "^2") == 0)
        {
            double i = 0;
            double squaring  = 0;
            if (sizeDynArr(stack) >= 1)
            {
                i = topDynArr(stack);
                popDynArr(stack);
                squaring = pow(i, 2);
                pushDynArr(stack, squaring);
                printf("Squaring\n");
            }
        }
        /* FIXME: replace printf with your own function */
        else if(strcmp(s, "^3") == 0)
        {
            double i = 0;
            double cubing  = 0;
            if (sizeDynArr(stack) >= 1)
            {
                i = topDynArr(stack);
                popDynArr(stack);
                cubing = pow(i, 3);
                pushDynArr(stack, cubing);
                printf("Cubing\n");
            }
        }
        /* FIXME: replace printf with your own function */
        
        else if(strcmp(s, "abs") == 0)
        {
            double i = 0;
            double absolute  = 0;
            if (sizeDynArr(stack) >= 1)
            {
                i = topDynArr(stack);
                popDynArr(stack);
                absolute =  fabs(i);
                pushDynArr(stack, absolute);
                printf("Absolute value\n");
            }
        }
        /* FIXME: replace printf with your own function */
        
        else if(strcmp(s, "sqrt") == 0)
        {
            double i = 0;
            double square  = 0;
            if (sizeDynArr(stack) >= 1)
            {
                i = topDynArr(stack);
                popDynArr(stack);
                square = sqrt(i);
                pushDynArr(stack, square);
                printf("Square root\n");
            }
        }
        /* FIXME: replace printf with your own function */
        
        else if(strcmp(s, "exp") == 0)
        {
            double i = 0;
            double exp  = 0;
            if (sizeDynArr(stack) >= 1)
            {
                i = topDynArr(stack);
                popDynArr(stack);
                exp = pow(i, 2.7182818);
                pushDynArr(stack, exp);
                printf("Exponential\n");
            }
        }
        /* FIXME: replace printf with your own function */
        
        else if(strcmp(s, "ln") == 0)
        {
            double i = 0;
            double ln  = 0;
            if (sizeDynArr(stack) >= 1)
            {
                i = topDynArr(stack);
                popDynArr(stack);
                ln = log(i);
                pushDynArr(stack, ln);
                printf("Natural Log\n");
            }
        }
        /* FIXME: replace printf with your own function */
        
        else if(strcmp(s, "log") == 0)
        {
            double i = 0;
            double log  = 0;
            if (sizeDynArr(stack) >= 1)
            {
                i = topDynArr(stack);
                popDynArr(stack);
                log = log10(i);
                pushDynArr(stack, log);
                printf("Log\n");
            }
        }
        /* FIXME: replace printf with your own function */
        
        else
        {
            double other = 0;
            if (strcmp(s, "pi") == 0)
            {
                other = 3.14159265;
            }
            else if (strcmp(s, "e") == 0)
            {
                other = 2.7182818;
            }
            else
            {
                if (isNumber(s, &other) == 0)
                {
                    error = "not a number or operator";
                }
            }
            pushDynArr(stack, other);
        }
    }	//end for
    
    /* FIXME: You will write this part of the function (2 steps below)
     * (1) Check if everything looks OK and produce an error if needed.
     * (2) Store the final value in result and print it out.
     */
    if (error != NULL)
    {
        printf("%s\n", error);
    }
    if (sizeDynArr(stack) == 1)
    {
        result = topDynArr(stack);
    }
    else
    {
        printf("caculate wrong \n");
    }
    
    // FIXME: You need to develop the code here (when s is not an operator)
    // Remember to deal with special values ("pi" and "e")
    
    
    //end for
    
    /* FIXME: You will write this part of the function (2 steps below)
     * (1) Check if everything looks OK and produce an error if needed.
     * (2) Store the final value in result and print it out.
     */
    
    return result;
}





int main(int argc , char** argv){
    // assume each argument is contained in the argv array
    // argc-1 determines the number of operands + operators
    if (argc == 1)
        return 0;
    
    double result = calculate(argc,argv);
    printf("%f\n", result);
    return 0;
    
}

