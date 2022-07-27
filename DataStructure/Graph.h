#第六章 图

#图的邻接矩阵存储(利用二维数组)
#define MaxVertexNum 100
typedef struct{
  char Vex[MaxVertexNum];  #储存顶点信息,如Vex[0] = A 
  int Edge[MaxVertexNum][MaxVertexNum];   #邻接矩阵
  int vexnum,arcnum;   #当前的顶点数,边数
}MGraph;

#图的邻接表存储
typedef struct ArcNode{  #边表结点
  int adjevx;  #该弧所指的顶点的位置
  struct ArcNode *next;  #指向下一个弧的指针
}ArcNode;

typedef struct VNode{   #顶点表结点
  char data;   #顶点的信息
  ArcNode *first;  #指向第一条该顶点的弧的指针
}VNode,AdjList[MaxVertexNum];

typedef struct{
  AdjList vertices;  #邻接表
  int vexnum,arcnum; #当前的顶点数,边数
}ALGraph;
