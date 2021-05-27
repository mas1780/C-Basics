#include<stdio.h>
#include <ctype.h> 
#include<string.h>

int main(int argc, char * argv[])
{
    int type;
    if(argc==1)type=1;
    
    if(argc==2)
    {
        if(strcmp(argv[1],"-d")==0)type=2;
        if(strcmp(argv[1],"-u")==0)type=3;
    }
    if(argc==3)
    {
        if(strcmp(argv[1],"-d")==0 && strcmp(argv[2],"-u")==0)type=4;
        else if(strcmp(argv[2],"-d")==0 && strcmp(argv[1],"-u")==0)type=4;
    }
    char c = getchar();

    if(type==1)putchar(c);

    else if(type==2){putchar(c);putchar(c);}

    else if(type==3){putchar(toupper(c));}
    
    else if(type==4){
        putchar(toupper(c));
        putchar(toupper(c));
    }

    printf("\n");
    return 1;
}