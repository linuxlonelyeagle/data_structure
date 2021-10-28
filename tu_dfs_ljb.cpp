#include <iostream>
#include "ljb.h"
using namespace std;
bool visited[MAXVEX];

void DFS(GraphAdjList GL, int i)
{
    EdgeNode *p; 
    visited[i] = true;
    cout << GL.adjList[i].data;   // 打印顶点
    p = GL.adjList[i].firstedge;
    while (p) {
        if (!visited[p->adjvex])
        DFS(GL,p->adjvex);
        p = p->next;
    }
}

void DFSTraverse(GraphAdjList GL)
{
    int i; 
    for (i = 0; i < GL.numVertexes; i++) {
        if (visited[i] == false)
            DFS(GL, i);
    }
}

int main(int argc, char *argv[])
{

    return 0;
}