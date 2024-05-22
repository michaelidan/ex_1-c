#include <stdio.h>
#include <math.h>

int isPrime(int n){
// 0 - is not prime, 1 - is prime
    if (n<0) return -1;
    if (n==0) return 0;
    if (n==1 || n==2 || n==3) return 1;
    int s = 0; // square root of n
    s = floor(sqrt(n));
    for (int i=2; i<=s; i++){
        if (n% i == 0) return 0;
    } 
    return 1;
}
int factorial(int n) {
    if (n == 0)  return 1;
    return n * factorial(n - 1);
}
int isStrong(int n){
    if (n<0) return -1;
    if (n==0) return 0;
    if (n==1 || n==2) return 1;
    int sum = 0;
    int t=0;
    int i=n;
    while (i>0){
        t=i%10;
        sum+= factorial(t);
        i/=10;
    }
    return n == sum ;
}

    