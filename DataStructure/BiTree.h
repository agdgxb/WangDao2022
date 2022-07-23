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
