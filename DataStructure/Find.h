#二叉排序树的查找,key < T.data 则向左子树查找，否则向右子树查找
#非递归算法
BSTNode *BST_Search(BiTree T,ElemType key){
  while(T != NULL & key != T.data){
    if(key < T->data) 
      T = T->lchild;
    else
      T = T->rchild;
  }
  return T;
}

#二叉排序树的插入,只能插入到查找路径中最后一个结点的左孩子或右孩子
int BST_Insert(BiTree &T,ElemType key){
  if(T == NULL){ #是一棵空树
   T = (BiTree)malloc(sizeof(BSTNode);
   Tdata = key;
   T->lchild = T->rchild = NULL;
   return 1;  #返回1,则表示成功插入
  }
  else if(key == T->data)  #在二叉排序树种找到了要插入的结点
    return 0;  
              
}
