
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int reorder(char **s1, char **s2, char **s3)
{
    int l1,l2,l3;
    l1=strlen(*s1);
    l2=strlen(*s2);
    l3=strlen(*s3);

    printf("%d %d %d\n",l1,l2,l3);

    if(l1==l2 && l1==l3) return 3;

    else if(l1==l2 || l2==l3 || l1==l3 ) return 2;

    if(l1>l2 && l2>l3)
    {
        printf("scenario1\n");
        return -1;
    }
    else if(l1>l3 && l3>l2)
    {
        printf("scenario2\n");
        char * temp = *s2;
        (*s2)= (*s3);
        (*s3) = temp;
    }

    else if(l2>l1 && l1>l3)
    {
        printf("scenario3\n");
        char *temp = *s2;
        (*s2) = (*s1);
        (*s1) = temp;
    }

    else if(l2>l3 && l3>l1)
    {
        printf("scenario4\n");
        char * temp = (*s1);
        (*s1) = (*s2);
        (*s2) = (*s3);
        (*s3) = temp;
    }

    else if(l3>l1 && l1>l2)
    {
        printf("scenario5\n");
        char * temp = (*s3);
        (*s3) = (*s2);
        (*s2) = (*s1);
        (*s1) = temp;
    }

    else if(l3>l2 && l2>l1)
    {
        printf("scenario6\n");
        char * temp = *s1;
        (*s1) = (*s3);
        (*s3) = temp;

    }

    return 1;
}
int main()
{
    char *s1="Hello";
    char *s2="Merhaba";
    char *s3="Hi";

    printf("%d \n",reorder(&s1,&s2,&s3));
    printf("%s %s %s \n",s1, s2, s3);;

}