#include <stdio.h>
#include <stdlib.h>
#include "stulist2.h"

void stuprint(Record);

int main()
{
  int num;
  Record data;
  FILE *fp;

  head = make_1node(data, NULL);
if((fp=fopen("Student1.dat","r"))==NULL){
  printf("File open error\n");
  exit(1);
}
while(1){
    if(fscanf(fp,"%d %s %d %d %d",&data.id,data.name,&data.score[0],&data.score[1],&data.score[2])==EOF)break;
    if (insert(data) == NULL) printf("Data %d is already on the list\n", data.id);
}
listprint();

  while (1) {
    printf("Insert new data:(ID name score1 score2 score3)->");
    if(scanf("%d %s %d %d %d",&data.id,data.name,&data.score[0],&data.score[1],&data.score[2])==EOF)break;
    if (insert(data) == NULL) printf("Data %d is already on the list\n", data.id);
    listprint();
  }
  /*削除関数追加*/
  rewind(stdin);
  while(1){
      printf("\nDelete ID-> ");
      if(scanf("%d",&num)==EOF)break;
      if(delete(num)==NULL)printf("Data %d is not found.\n",num);
      listprint();
  }
  fclose(fp);
  return 0;
}

NodePointer insert(Record keydata)
{
  NodePointer newnode,n;

  n =head;
  if (finditem(keydata.id) != NULL)return NULL;
  while(1){
    if(n->next==NULL)break;
    n=n->next;
  }
newnode = make_1node(keydata, n->next);//make_1nodeで確保したメモリのアドレスを代入する
    n->next = newnode;

    return newnode;
  
}

void listprint(void)
{
  NodePointer n;

  printf("Head-\n");
  for (n = head->next; n != NULL; n = n->next) {
    printf("   %10d %-13s %3d %3d %3d \n", n->data.id,n->data.name,n->data.score[0],n->data.score[1],n->data.score[2]);
  }
  printf("\n");
}

NodePointer finditem(int keydata)
{
  NodePointer n;

  for (n = head; n->next != NULL; n = n->next) {
    if (n->next->data.id == keydata) return n;//以前にあるものとアドレスが一致したら抜け出す
  }

  return NULL;
}

NodePointer make_1node(Record keydata, NodePointer p)
{
  NodePointer n;//node型のポインタn
  
  /*struct nodeの領域を確保してnという名前にする、そしてその先頭のアドレスを返す、これがNULLならError*/
  if ((n = (NodePointer)malloc(sizeof(struct node))) == NULL) {
    printf("Error in memory allocation\n");
    exit(8);
  }

  n->data = keydata;
  n->next = p;

  return n;
}

/*削除関数*/
NodePointer delete(keydata){

    NodePointer n,delnode;

if((n=finditem(keydata))!=NULL){
    delnode=n->next;
    n->next=delnode->next;
    free(delnode);
    return n;
}
    else return NULL;
}
