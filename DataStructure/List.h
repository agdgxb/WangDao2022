#include<stdio.h>
#include<stdlib.h>

#定义顺序表(静态分配空间)
#define MaxSize 10
typedef struct{
  Elemtype data[MaxSize];  #顺序表的元素
  int length;   #顺序表的当前长度
}SqList;

#动态分配空间方式
typedef struct{
  Elemtype *data;   #指示动态分配数组的指针
  int MaxSize,length;   #数组的最大容量和当前长度
}SqList;
L.data = (Elemtype *)malloc(sizeof(Elemtype)*InitSize);  #初始动态分配
然后利用 L.data[i]进行访问即可


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

#尾插法建立带头结点的单链表
LinkList List_TailInsert(LinkList &L){
  int x;  #设Elemtype 为 int
  L = (LinkList) malloc(sizeof(LNode));  #申请内存
  L->next = NULL:
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

#头插法建立带头结点的单链表
LinkList List_HeadList(LinkList &L){
  int x;
  L = (LinkList)malloc (sizeof(LNode)); #申请内存
  L->next = NULL;  #创建带有头结点
  LNode *s;  #与尾插法相比少了个指针
  scanf("%d",&x);
  while(x != 999){
    s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    s->next = L->next;
    L ->next = s;
    scanf("%d",&x);
  }
  return L;
}

#双链表
typedef struct DNode{
  Elemtype data;
  struct DNode *prior,*next;   #prior表示前驱
}DNode,*DLinkList;

#初始化双链表（带头结点）
#要想判断双链表是否为空，判断L->next == NULL 即可
bool initDLinkList(DLinkList &L){
  L = (DNode *)malloc(sizeof(DNode));  #分配一个头结点
  if(L == NULL)
    return false;
  L->prior = NULL;   #头结点的prior永远指向NULL
  L->next = NULL;
  return true;
  }

#前插操作：找到要插入的结点p，然后根据p->prior找到前插的位置，进行后插操作即可
#按位序插入：找到第i-1个结点，进行后插操作
#双链表的插入----后插操作：在p结点之后插入结点s(两个参数:结点p 结点s)
bool InsertNextDNode(DNode *p,DNode *s){
  if(p == NULL || s == NULL)   #非法参数
    return false;
  s->next = p->next;
  if(p->next != NULL)   #判断p是否是最后一个结点,若是最后一个，则p->next = NULL
    p->next->prior = s;
  s->prior = p;
  p->next = s;
  return true;
}

#双链表的删除，删除结点p的后继结点(一个参数：结点p)
bool DeleteDNode(DNode *p){
  # p=NULL表明p非法，p->next=NULL表示p是最后一个结点，没有后继
  if(p == NULL || p->next == NULL)  
    return fasle;
  DNode * q = p->next;
  p->next = q->next;
  if(q->next != NULL)  #p不是倒数第二个结点,若为倒数第二个，则p->next=NULL
     p->next->prior = p;
  free(q);   #释放结点空间
  return true;
}

#销毁双链表(带头结点)
void destoryList(DLinkList &L){
  while(L->next != NULL)
    DeleteDNode(L);   #按照双链表的删除
  free(L);   #释放头结点
  L = NULL;   #头结点指向NULL
}

#循环链表的初始化
bool InitDLinkList(DLinkList &L){
  L = (DNode *)malloc(sizeof(DNode));  #先分配空间
  if(L == NULL)
    return false;
  #双链表的初始化
  L->prior = L;  #头结点的prior指向头结点
  L->next = L;   #头结点的next指向头结点
  
  #单链表的初始化
  L->next = L;
  
  return true;
}

















































