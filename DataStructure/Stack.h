#第三章 栈

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
