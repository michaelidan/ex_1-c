#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int range(int start, int end){
    if (end < start) {
    int st = start;
    start = end;
    end = st;    
    }
    printf("The Armstrong numbers are:");
    for (int i = start; i<= end; i++){
        if (isArmstrong(i)) printf(" %d", i);
    }
    printf("\n");

    printf("The Palindromes are:");
    for (int i = start; i<= end; i++){
    if (isPalindrome(i)) printf(" %d", i);
    } 
    printf("\n");
    printf("The Prime numbers are:");
    for (int i = start; i<= end; i++){
        if (isPrime(i)) printf(" %d", i);
    }
    printf("\n");
    printf("The Strong numbers are:");
    for (int i = start; i<= end; i++){
    if (isStrong(i)) printf(" %d", i);
    }
    printf("\n");
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



    return 0;
}
