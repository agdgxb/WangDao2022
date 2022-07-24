#树与二叉树

5.3  遍历
#二叉树的链式存储结构
typedef struct BiNode{
  ElemType data;
  struct BiNode *lchild,*rchlid;
}BiNode,*BiTree;

#二叉树的前序遍历(根左右)
void PreOrder(BiTree T){
  if(T != NULL){  #不是空树
    visit(T);  #对该结点进行输出等，访问根结点
    PreOrder(p->lchild);  #遍历左子树
    PreOrder(p->rchlid);  #遍历右子树
  }
}

#二叉树的中序遍历(左根右)
void InOrder(BiTree T){
  if(T != NULL){
    InOrder(T->lchild);
    visit(T);
    InOrder(T->rchlid);
  }
}

#二叉树的后序遍历(左右根)
void PostOrder(BiTree T){
  if(T != NULL){
    PostOrder(T->lchild);
    PostOrder(T->rchlid);
    visit(T);
  }
}

#层序遍历,利用队列
void LevelOrder(BiTree T){
  LinkQueue Q;   #初始化辅助队列
  InitQueue(Q);
  BiTree p;
  EnQueue(Q,T);  #根结点入队
  while(!isEmpty(Q)){  #队列不为空
    DeQueue(Q,p);   #队头结点出队
    visit(p);
    if(p->lchild != NULL)   #左孩子入队
      EnQueue(Q,p->lchild);
    if(p->rchild != NULL)   #右孩子入队
      EnQueue(Q,p->rchild);
  }
}


#线索二叉树结点
typedef struct ThreadNode{
  ElemType data;
  struct ThreadNode *lchild,*rchild;
  int ltag,rtag;
}ThreadNode,*ThreadTree;

#中序遍历对二叉树线索化
ThreadNode *pre = NULL;   #定义一个全局变量
void InThread(ThreadTree T){
  if(T != NULL){
    InThread(T->lchild);  #中序遍历左子树
    visit(T);  #访问根节点
    InThread(T->rchild);
  }
}

void visit(BiTree T){
  if(T->lchild == NULL){
    T>lchild = pre;
    T->ltag = 1;
  }
  if(pre != NULL && T->rchild == NULL){
    pre->rchild = T;
    pre->rtag = 1;
  }
  pre = p;
}

#中序线索化二叉树
void CreateInThread(BiTree){
  pre = NULL;
  if(T != NULL){  #非空二叉树才能线索化
    InThread(T);   #中序线索化
    if(pre->rchild == NULL)  #处理最后一个结点
      pre->rtag = 1;
  }
}

#先序线索化二叉树,仍然利用visit函数,Create函数也不变
#注意可能会出现lchild指向前一个结点的问题
void PreThread(BiTree T){
  if(T != NULL){
    visit(T);
    if(T->ltag == 0)  #判断lchild不是前驱线索才遍历左子树
      PreThread(T->lchild);
    PreThread(T->rchild);
  }
}

#找以P为根的子树中,第一个被中序遍历的结点,即P的最左下结点
ThreadNode *FirstNode(ThreadNode *p){
  if(p->ltag == 0)
    p = p->lchild;
  return p;
}
#在中序线索二叉树中找到结点p的后继结点
ThreadNode *NextNode(ThreadNode *p){
  if(p->rtag == 0)  #如果p的右结点不是指向后继
    return FirstNode(p->rchild);
  else
    return p->rchild;
}












