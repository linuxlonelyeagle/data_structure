typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 50

typedef struct EdgeNode  // 边表节点
{
    int adjvex;
    EdgeType wight;
    struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode
{
    VertexType data;
    EdgeNode *firstedge;
}VertexNode,AdjList[MAXVEX];

typedef struct 
{
    AdjList adjList;  // 这个是一个数组
    int numVertexes, numEdges; 
}GraphAdjList;

void CreateALGraph(GraphAdjList *G);



