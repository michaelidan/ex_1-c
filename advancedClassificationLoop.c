#include <stdio.h>
#include <math.h>

int CountOfDigit(int n){
    if (n<10) return 1;
    int CountDigit = 0;
    while (n>0)
    {
        CountDigit++;
        n/=10;
    }
    return CountDigit;
}

int lDigit(int n){
    if (n<10) return n;
    while (n>=10){
    n/=10;
    }
    return n;         
}
int rDigit(int n){
    return n%10;
}
int cutRight(int n){
    return n/10;
}

int isPalindrome(int n){
    int revers = 0;
    int original = n;
    while(n>0){
        int digit = n % 10;
        revers = revers*10 + digit;
        n /= 10;
    }
    return original == revers;
}

int isArmstrong(int n){
    if (n<0) return -1;
    if (n<10) return 1;
    int num = n;
    int CountDigit = CountOfDigit(n); 
    
    int Sum = 0;
    while(num>0){
        Sum += pow(rDigit(num), CountDigit);
        num = cutRight(num);
    }
    return Sum == n;
}