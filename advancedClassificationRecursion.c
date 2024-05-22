#include <stdio.h>
#include <math.h>

int CountOfDigit(int n){
    if (n<10) return 1;
    return 1+ CountOfDigit(n/10);
}

int lDigit(int n){
    if (n<10) return n;
    return lDigit(n/10);         
}
int l_1_Digit(int n){
    if (n<100) return n%10;
    return l_1_Digit(n/10);         
}
int rDigit(int n){
    return n%10;
}
int r_1_Digit(int n){
    return (n%100)/10;
}
int cutRight(int n){
    return n/10;
}

int recurToPali(int n, int EndToSt) {
    if (n == 0) return EndToSt;
    return recurToPali(n / 10, EndToSt * 10 + n % 10);
}
int isPalindrome(int n) {
    if (n<0) return -1;
    if (n == 0) return 0;
    if (recurToPali(n, 0) == n) return 1;
    return 0;
}

int sumPowerDigit(int num, int countDigits, int sum) {
    if (num == 0) {
        return sum;
    }
    
    sum += pow(rDigit(num), countDigits);
    return sumPowerDigit(cutRight(num), countDigits, sum);
}
int isArmstrong(int n) {
    if (n<0) return -1;
    if (n<10) return 1;

    int countDigits = CountOfDigit(n);
    int num = n;
    return (sumPowerDigit(num, countDigits, 0) == n);
}   

