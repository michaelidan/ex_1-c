#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int range(int start, int end){
    if (end < start) {
    int st = start;
    start = end;
    end = st;    
    }
    printf("The Armstrong numbers are: ");
    for (int i = start; i<= end; i++){
        if (isArmstrong(i)) printf("%d ", i);
    }
    printf("\n");

    printf("The Palindromes are: ");
    for (int i = start; i<= end; i++){
    if (isPalindrome(i)) printf("%d ", i);
    } 
    printf("\n");
    printf("The Prime numbers are: ");
    for (int i = start; i<= end; i++){
        if (isPrime(i)) printf("%d ", i);
    }
    printf("\n");
    printf("The Strong numbers are: ");
    for (int i = start; i<= end; i++){
    if (isStrong(i)) printf("%d ", i);
    }
     
    return 0;
}

int main() {
    int start;
    int end;
    // printf("choose number to start of the range: \n");
    scanf("%d", &start);
    // printf("choose number to end of the range: \n");
    scanf("%d", &end);
    range(start, end);

/*
gcc -c advancedClassificationLoop.c -o advancedClassificationLoop.o
gcc -c basicClassification.c -o basicClassification.o
gcc -c myMain.c -o myMain.o
gcc -o myMain basicClassification.o advancedClassificationLoop.o myMain.o -lm
*/
/*
gcc -c advancedClassificationRecursion.c -o advancedClassificationRecursion.o
gcc -c basicClassification.c -o basicClassification.o
gcc -c myMain.c -o myMain.o
gcc -o myMain basicClassification.o advancedClassificationRecursion.o myMain.o -lm
*/
/*
gcc myMain.c basicClassification.c advancedClassificationRecursion.c -o myMain -lm

*/

    return 0;
}
