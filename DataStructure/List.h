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

#带头结点的按位序插入
bool insertList_withhead(LinkList &L,int i,Elemtype e){
  if(i < 1)
    return false;
  LNode *p = L;
  int j = 0;
  while(p != NULL && j < i-1){ # p!=NULL判断是否位序i超过指针长度，j < i-1想找到第i-1个结点
      p = p->next;
      j++;
   }
  LNode *s = (LNode *) malloc(sizeof(LNode));
  s ->data = e;
  s->next = p->next;
  p->next = s;
  return true;
}

#不带头结点的按位序插入
bool insertList_nohead(LinkList &L,int i,Elemtype e){
  if(i < 1)
    return false;
  if(i == 1){
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = L;
    L = s;
    retuen true;
  }
  LNode *p = L;
  int j = 1;
  while(p && j < i-1){
    p = p->next;
    j++;
  }
  LNode *s = (LNode *)malloc(sizeof(LNode));
  s->data = e;
  s->next = p->next;
  p->next = s;
  return true;
}

#前插操作：在给定的结点p之前插入元素e（在给定的结点p之前插入结点s也可利用该思想）
bool InsertPriorNode(LNode *p,Ememtype e){
  if(p ==NULL) #判断p的合法性
    ruturn false;
  LNode *s = (LNode *)malloc(sizeof(LNode));
  s->next = p->next;
  p->next = s;
  #将结点S插入到P的后面，然后互换二者的数据来实现前插操作
  s->data = p->data;
  p->data= e;
  return true;
}

#带头结点的链表按位序删除
bool deleteList_withhead(LinkList &L,int i,ElemType &e){
  if(i < 1)
    return false;
  LNode *p = L;
  int j = 0;
  while(p && j < i-1){
    p = p->next;
    j++;
  }
  if(p == NULL || p->next == NULL) #判断！！！
     return false;
  LNode *q = p->next;
  e = q->data;
  p->next = q->next;
  free(q);
  return true;
}

#删除指定结点
#将q = p->next，将q的data换到p上，然后删除q即可
bool deleteNode(LNode *p){
  if(p == NULL)
    return false;
  LNode *q = p->next;
  p->data = q->data;
  p->next = q->next;
  free(q);
  return true;
}

#按位查找，返回一个结点
LNode * GetElem(LinkList L,int i){
  if(i < 0)
    ruturn NULL;  #注意返回值
  LNode *p = L;
  int j = 0;
  while(p && j < i){
    p = p->next;
    j++;
  }
  return p;  #如果i超过链表的长度，p = NULL
}

#尾插法建立单链表
LinkList List_TailInsert(LinkList &L){
  int x;  #设Elemtype 为 int
  L = (LinkList) malloc(sizeof(LNode));
  LNode *s,*p = L;
  scanf("%d",&x);  #插入的数据就是x
  while(x != 999){
    s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    p->next = s;
    p = s;
    scanf("%d",&x);
  }
  p->next = NULL;
  return L;
}



















