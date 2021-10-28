#include "ljjz.h"
#include <iostream>
using namespace std;
#define MAX 9    // 9个顶点 
bool visited[MAX];   // 全部是false;

void dfs(MGraph g, int i)
{
    visited[i] = true;
    cout << g.vexs[i];
    for (auto j = 0; j < g.numVertexes; j++) 
        if (visited[j] == 1 && visited[j] == false)
            dfs(g,j);
}

void DFSTraverse(MGraph g)
{
    for (auto i = 0;i < g.numVertexes; i++) 
        visited[i] = false;
    for (auto i = 0; i < g.numVertexes; i++)   
        if (visited[i] == false)
            dfs(g,i);     
}



int main(int argc, char *argv[])
{
    MGraph g;
    CreateMGraph(&g);
    DFSTraverse(g);   
    return 0;
}