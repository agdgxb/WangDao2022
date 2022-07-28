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


#图的广度优先遍历BFS
bool visited[Max_Vertex_Num];   #用来判断该结点是否被访问过
void BFSTraverse(Graph G){
  for(int i = 0; i < G.vernum;i++)
    visited[i] = false;   #初始化,都未被访问过
  InitQueue(Q);   #初始化辅助队列
  for(int i = 0;i < G.vernum;i++){  
    if(visited[i] == false)   #对每个连通分量遍历一次,共需要BFS次数 = 连通分量个数
      BFS(G,i);
  }
}
void BFS(Graph G,int i){
  visit(i);
  visited[i] = true;
  EnQueue(Q,i);   #顶点i入队
  while(!isEmpty(Q)){  #队列不为空
    DeQueue(Q,i);  #队头i出队
    for(j = FirstNeighbor(G,i);j >=0; j = NextNeighbor(G,i,j)){ #j为i的第一个相邻结点，遍历i的所有相邻结点
      if(visited[j] == false){  #判断该结点是否被访问过
        visit(j);
        visited[j] = true;
        EnQueue(Q,j);
      }
    }
  }
}


#图的深度优先遍历
bool visited[Max_Vertex_Num];
void DFSTraverse(Graph G){
  for(i = 0;i < G.vertex;i++)  #初始化
    visited[i] = false;
  for(i = 0;i < G.vertex;i++){
    if(visited[i] == false)  #为访问过,进行深度优先遍历
      DFS(G,i);
  }
}
void DFS(Graph G,int v){  #从结点v出发，深度优先遍历图G
  visit(v);
  visited[v] = true;
  for(w = FirstNeighbor(G,v);w >= 0;w = NextNeighbor(G,v,w)){  #进行递归
    if(visited[w] == false)
      DFS(w);
  }
}










