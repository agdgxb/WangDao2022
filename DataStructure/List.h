#include<stdio.h>
#include<stdlib.h>

#定义单链表
typedef struct LNode {
  int data;
  struct LNode* next;
}LNode, *LinkList;

#初始化不带头结点的单链表
bool initList_nohead(LinkList &L){
  #不必初始化，直接NULL
  L = NULL;
  return true;
}

#初始化带头结点的单链表
bool initList_withhead(LinkList &L){
  L = (LNode *) malloc (sizeof(LNode));
  if ( L == NULL )  #未能成功分配空间
     return false;
  L -> next = NULL;
  return true;
}

#判断单链表是否为空
bool empty(LinkList L){
  #不带头结点
  return (L == NULL);
  #带头结点
  if(L -> next == NULL)
    return true;
  else
    return false;
}
