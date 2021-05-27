#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node1d{
  struct node1d*next;
  char*name;
};

struct node2d{
  struct node1d*first;
  struct node1d*curr;
  char*name;
  struct node2d*down;
};

struct node2d*head=NULL;
struct node2d*current=NULL;

void insertFront2D(char*data){
  struct node2d*temp=malloc(sizeof(struct node2d));
  temp->down=NULL;
  temp->first=NULL;
  temp->curr=NULL;
  temp->name=malloc(sizeof(char)*20);
  strcpy(temp->name,data);

  if(head==NULL){
    head=temp;
    current=temp;
    current->down=NULL;
    head->down=NULL;
  }else{
    current->down=temp;
    current=temp;
  }
}

int insertBefore2D(char*data,char*search){
  struct node2d*temp=malloc(sizeof(struct node2d));
  temp->down=NULL;
  temp->first=NULL;
  temp->curr=NULL;
  temp->name=malloc(sizeof(char)*20);
  strcpy(temp->name,data);

  struct node2d*tempSear=head;
  if(strcmp(tempSear->name,search)==0){
    head=temp;
    head->down=tempSear;
    return 1;
  }
  struct node2d*prev=head;
  while(tempSear!=NULL){
    if(strcmp(tempSear->name,search)==0){
      prev->down=temp;
      temp->down=tempSear;
      return 1;
    }
    prev=tempSear;
    tempSear=tempSear->down;
  }
  return 0;
}

int insertFront1D(char*data,char*search){

  struct node2d*tempSear=head;
  while(tempSear!=NULL){
    if(strcmp(tempSear->name,search)==0){
      struct node1d*add=malloc(sizeof(struct node1d));
      add->name=malloc(sizeof(char)*20);
      strcpy(add->name,data);
      add->next=NULL;
      if(tempSear->first==NULL){
        tempSear->first=add;
        tempSear->curr=add;
      }else{
        tempSear->curr->next=add;
        tempSear->curr=add;
      }
      return 1;
    }
    tempSear=tempSear->down;
  }
  return 0;
}

int insertBeforeName1D(char*data,char*search){
  struct node1d*temp=malloc(sizeof(struct node1d));
  temp->name=malloc(sizeof(char)*20);
  strcpy(temp->name,data);
  temp->next=NULL;

  struct node2d*tempSear=head;
  while(tempSear!=NULL){
    struct node1d*add=tempSear->first;
    struct node1d*prev=tempSear->first;
    if(add!=NULL && strcmp(add->name,search)==0){
      tempSear->first=temp;
      tempSear->first->next=add;
      return 1;
    }
    while(add!=NULL){
      if(strcmp(add->name,search)==0){
        prev->next=temp;
        temp->next=add;
        return 1;
      }
      prev=add;
      add=add->next;
    }
    tempSear=tempSear->down;
  }
  return 0;
}

void printAll(){
  struct node2d*temp=head;
  while(temp!=NULL){
    printf("> %s",temp->name);
    if(temp->first!=NULL){
      struct node1d*add=temp->first;
      while(add!=NULL){
        printf(" : %s ",add->name);
        add=add->next;
      }
    }
    printf("\n");
    temp=temp->down;
  }
}

int print1DList(char*search){
  struct node2d*temp=head;
  while(temp!=NULL){
    if(strcmp(search,temp->name)==0){
      printf("> %s",temp->name);
      if(temp->first!=NULL){
        struct node1d*add=temp->first;
        while(add!=NULL){
          printf(" : %s ",add->name);
          add=add->next;
        }
        printf("\n");
      }
      return 1;
    }
    temp=temp->down;
  }
  return 0;
}

int find1D(char*search){
  struct node2d*temp=head;
  while(temp!=NULL){
    if(temp->first!=NULL){
      struct node1d*add=temp->first;
      while(add!=NULL){
        if(strcmp(add->name,search)==0){
          return 1;
        }
        add=add->next;
      }
    }
    temp=temp->down;
  }
  return 0;
}

int find2D(char*search){
  struct node2d*temp=head;
  while(temp!=NULL){
    if(strcmp(search,temp->name)==0){
      return 1;
    }
    temp=temp->down;
  }
  return 0;
}

void Menu(){
  printf("\nEnter \"insertFront2D name\" to Insert 2D Node\n");
  printf("Enter \"insertBefore2D name beforeName\" to Insert Before 2D Node\n");
  printf("Enter \"insertFront1D name name2D\" to Insert 1D Node\n");
  printf("Enter \"insertBefore1D name beforeName1D\" to Insert Before 1D Node\n");
  printf("Enter \"printAll\" to Print All\n");
  printf("Enter \"print1DList name2D\" to Print 1D List\n");
  printf("Enter \"find1D name1D\" to Find 1D Node\n");
  printf("Enter \"find2D name2D\" to Find 2D Node\n");
  printf("Enter your choice\n");
}

int getch(int*i,char*temp) {
    return (*i > 0) ? temp[--*i] : getchar();
}

void ungetch(int c,char*temp,int*i) {
    if (*i >= 20)
        fprintf(stderr, "ERROR.\n");
    else
        temp[*i++] = c;
}

void getword(char *word, int lim) {
    int c;
    char *w = word;
    int i=0;
    char temp[lim];
    while (isspace(c=getch(&i,temp)) && c != '\n');
    if (c != EOF){
        *w++ = c;
    }
    if (!isalnum(c)) {
        *w = '\0';
        return;
    }
    for (; --lim >= 0; w++){
        if (!isalnum(*w = getch(&i,temp))) {
            ungetch(*w,temp,&i);
            break;
        }
    }
    *w = '\0';
}

int main(void) {
  int check=1;
  Menu();
  do{
    char*command=malloc(sizeof(char)*20);
    char*name=malloc(sizeof(char)*20);
    char*name1=malloc(sizeof(char)*20);
    getword(command,20);
    getword(name,20);
    getword(name1,20);

    if(strcmp("insertFront2D",command)==0){
      insertFront2D(name);
    }else if(strcmp("insertBefore2D",command)==0){
      check=insertBefore2D(name,name1);
    }else if(strcmp("insertFront1D",command)==0){
      check=insertFront1D(name,name1);
    }else if(strcmp("insertBefore1D",command)==0){
      check=insertBeforeName1D(name,name1);
    }else if(strcmp("printAll",command)==0){
      printAll();
    }else if(strcmp("print1DList",command)==0){
      check=print1DList(name);
    }else if(strcmp("find1D",command)==0){
      if(find1D(name)){
        printf("> FOUND\n");
      }else{
        printf("> NOT FOUND\n");
      }
    }else if(strcmp("find2D",command)==0){
      if(find2D(name)){
        printf("> FOUND\n");
      }else{
        printf("> NOT FOUND\n");
      }
    }else{
      printf("> INVALID COMMAND\n");
    }
  }while(check!=0);
  printf("GOODBYE!\n");
  return 0;
}