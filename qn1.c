#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int countVowels(char * S)
{
    int count = 0;

    int L =strlen(S);
    char temp[L];
    strcpy(temp,S);
    int j=0;

    for(int i=0;i<L;i++)
    {
        if(temp[i]=='a' || temp[i]=='A' || temp[i]== 'e' || temp[i]=='E' || temp[i]== 'i' 
            || temp[i]=='I' || temp[i]=='o' || temp[i]=='O' || temp[i]== 'u' || temp[i]=='U') 
        {
            count++;
            continue;
        }
        S[j++]=temp[i];
    }
    S[j]='\0';
    return count;

}

int main(int argc , char *argv[] )
{
    char * str;
    if(argc==2) str = argv[1];
    else{
        str = (char *)malloc(sizeof(char)*100);
        printf("Enter a string: ");
        scanf("%s",str);
        printf("\n");
    }
    int  c = countVowels(str);

    if(c!=0 ){
        printf("Vowel count = %d\n",c);
        printf("New string = %s\n",str);
    }
    else printf("No Vowels \n");
    return 0;
}