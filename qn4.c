#include<stdio.h>
#include<stdlib.h>


int isPrime(int n)
{
    for(int i=2;(i*i)<=n;i++)
    {
        if(n%i == 0) return 0;
    }
    return 1;
}
int main(int argc , char *argv[])
{


    if(argc<3){
        printf("Usage %s <number1> <number2>\n",argv[0]); return 1;
    }
    int l=atoi(argv[1]);
    int r=atoi(argv[2]);
    for(int i=l;i<=r;i++)
    {
        if(isPrime(i))printf("%d is prime\n",i);
    }
    return 1;
    
}