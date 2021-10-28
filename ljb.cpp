#include <iostream>
#include "ljb.h"
using namespace std;

void CreateALGraph(GraphAdjList *G)
{
    int i, j, k;
    EdgeNode *e;
    cout << "输入顶点数和边数" << endl;
    cin >> G->numVertexes >> G->numEdges;
    // 读入顶点的信息，建立顶点表
    for ( i = 0; i < G->numVertexes; i++) {
        cin >> G->adjList[i].data;
        G->adjList[i].firstedge = nullptr;
    }
    //建立边表
    for ( k = 0; k < G->numEdges; k++) {
        cout << "输入边(vi,vj)上的顶点序号:" << endl;
        cin >> i >> j ;
        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        e->adjvex = j;  // 领结序号
        e->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = e;

        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        e->adjvex = i;
        e->next = G->adjList[j].firstedge;
        G->adjList[j].firstedge = e;
    }
}