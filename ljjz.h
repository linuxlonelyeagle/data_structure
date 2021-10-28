typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 65535
typedef struct {
    VertexType vexs[MAXVEX];  // 顶点表
    EdgeType arc[MAXVEX][MAXVEX];   // 邻接矩阵
    int numVertexes, numEdges; 
}MGraph;

void CreateMGraph(MGraph *G);
