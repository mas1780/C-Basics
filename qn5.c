#include<stdio.h>
#include<string.h>

int main(int argc, char * argv[])
{
    if(argc<4)
    {
        printf("Usage %s <str> <except> <dup>\n",argv[0]);
        return 1;
    }
    int E[26],D[26];
    for(int i=0;i<26;i++){
        E[i]=0;
        D[i]=0;
    }

    for(int i=0;i<strlen(argv[2]);i++)
    {
        if(argv[2][i]<='z' && argv[2][i]>='a') E[argv[2][i]-'a']=1;
    }

    for(int i=0;i<strlen(argv[3]);i++)
    {
        if(argv[3][i]<='z' && argv[3][i]>='a') D[argv[3][i]-'a']=1;
    }
    
    for(int i=0;i<strlen(argv[1]);i++)
    {
        if(argv[1][i]>'z' || argv[1][i]<'a')
        {
            printf("illegal\n");
            return 1;
        }

        if(E[argv[1][i]-'a']==1)continue;

        else if(E[argv[1][i]-'a']==0 && D[argv[1][i]-'a']==0){putchar(argv[1][i]);continue;}

        else if(E[argv[1][i]-'a']==0 && D[argv[1][i]-'a']==1)putchar(argv[1][i]);putchar(argv[1][i]);
    }
    printf("\n");
    return 1;
}