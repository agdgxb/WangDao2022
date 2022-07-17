#第三章 栈、队列和数组

#3.1 栈
#顺序栈的定义
#define MaxSize 100    #定义该栈所能包含的最大个数
typedef struct{
  Elemtype data[MaxSize];   #存放栈中的元素
  int top;  #栈顶指针
}SqStack;

#顺序栈的初始化 
void InitStack(SqStack &L){
  L.top = -1;   #初始化时只需将栈顶指针赋值
}

#顺序栈的判空,只需要判断 L.top == -1 即可

#顺序栈的入栈
bool Push(SqStack &S,Elemtype x){
  #先判断栈是否已满
  if(S.top == MaxSize - 1)
    return false;
  S.top += 1;
  S.data[S.top] = x;
  return true;
}

#顺序栈的出栈
bool Pop(SqStack &S,ElemType &x){
  if(S.top == -1)  #栈空
    return false;
  x = S.data[S.top];
  top--;
  return true;
}

#栈的链式存储类型描述
typedef struct Linknode{
  ElemType data;
  struct Linknode *next;
}LiStack;

#不带头结点的入栈操作(注意参数和返回值，以及malloc)
LiStack * Pop(LiStack *s,ElemType a){
  LiStack *tmp = (LiStack *)malloc(sizeof(LiStack)); 
  tmp->data = a;
  tmp->next = s;
  s = tmp;
  return s;
}


#不带头结点的出栈操作(注意参数和返回值，以及malloc)
LiStack * Push(LiStack *s){
  if(s == NULL)
    return false;
  LiStack *tmp = s;  #tmp即要弹出的栈顶结点
  s = s->next;
  return s;
}



#3.2  队列
#队列的顺序定义(静态申请内存空间)
typedef struct {
  ElemType data[MaxSize];
  #定义队头指针front指向队头元素,队尾指针rear指向队尾元素的下一个位置（即下一个要插入的位置）
  int front,rear;  
}

#初始化队列
void InitQueue(SqQueue &Q){
  Q.front = Q.rear = 0;  #初始化时将队头指针、队尾指针指向0
}   
#队列判空时只需要判断Q.front == Q.rear 即可

#入队(从队尾进行插入) 注意判断队满的条件
bool EnQueue(SqQueue &Q,ElemType x){
  #队尾指针指向的是队尾元素的下一个位置，此时队列浪费一个空间无法存放数据元素
  if( (Q.rear + 1) % MaxSize == Q.front)  #判断队满的条件
    return false;
  Q.data[Q.rear] = x;
  Q.rear =( Q.rear + 1 ) % Maxsieze;
  return true;
}


#出队(从队头进行删除) 注意判断队空的条件
bool DeQueue(SqQueue &Q,ElemType &x){
  if(Q.front == Q.rear)  #判断条件
    return false;
  x = Q.data[Q.front];
  Q.front = (Q.front + 1) % MaxSize;
  return true;
}

#队列的链式实现
typedef struct LinkNode{  #链式队列结点
  ElemType data;
  struct LinkNode *next;
}LinkNode;
typedef struct{   #链式队列
  LinkNode *front,*rear;
}LinkQueue;

#带头结点的初始化,此时判空判断 Q.front == Q.rear
bool InitQueue_withhead(LinkQueue &Q){
  #初始时front、rear都指向头结点，利用malloc建立头结点
  Q.front = Q.rear =(LinkQueue *)malloc(sizeof(LinkQueue));
  Q.front->next = NULL;
  return true;
}

#不带头结点的初始化,判空需判断Q.front == NULL即可
bool InitQueue_nohead(LinkQueue &Q){
  Q.front = NULL;
  Q.rear = NULL;
}

#入队（带头结点）
void EnQueue(LinkQueue &Q,ElemType x){
  #先创建结点s，将x->data = x；
  LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
  s->data = x;
  s->next = NULL;
  Q.rear->next = s;  #新结点插入到rear之后
  Q.rear = s;  #修改表尾指针
}

#入队（不带头结点）
void EnQueue(LinkQueue &Q,ElemType x){
  LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
  s->data = x;
  s->next = NULL;
  #判断插入的是否是第一个元素
  if(Q.front == NULL){  #是第一个元素，此时队头队尾指针都指向s
    Q.front = s;
    Q.rear = s;
  }
  else {
    Q.rear->next = s;
    Q.rear = s;
  }
}

#出队（带头结点）,此时队头指针指向头结点
bool DeQueue(LinkQueue &Q,ElemType &x){
  if(Q.front == Q.rear)  #队列为空，注意判断条件
    return false;
  LinkQueue *p = Q.front->next;
  x = p->data;
  Q.front->next = p->next;
  if(Q.rear == p)   #判断出队的结点是否是最后一个结点
    Q.rear = Q.front;
  free(p);   #释放结点空间
  return true;
}

#出队（不带头结点）
bool DeQueue(LinkQueue &Q,ElemType &x){
  if(Q.front == NULL)
    return false;
  x = Q.front[data];
  LinkNode *p = Q.front;
  Q.front = p->next;
  if(p == Q.rear){  #判断出队的结点是否是最后一个结点
    Q.front = NULL;
    Q.rear = NULL;
  }
  free(p);
  return true;
}









