/* CS261- Assignment 1 - Q.5*/
/* Name:Zhouxiang Meng
 * Date:04-10-2015
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
    return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
    return ch-'A'+'a';
}

void studly(char* word){
    
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] >= 'a' && word[i] <= 'z'){
            word[i] = toUpperCase(word[i]);
        }
    }
    for (int n = 1; word[n] != '\0'; n = n + 2) {
        word[n] = toLowerCase(word[n]);
    }
    
    /*Convert to studly caps*/
}

int main(){
    
    char string[20];
    scanf("%s\n", string);
    /*Read word from the keyboard using scanf*/
    
    studly(string);
    /*Call studly*/
    
    printf("%s\n", string);
    /*Print the new word*/
    
    return 0;
}
