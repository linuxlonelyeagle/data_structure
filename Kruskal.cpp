#include "bjsz.h"
#include <iostream>
#include "ljjz.h"

using namespace std;
#define MAXEDGE 100

int find(int *parent, int f)
{
    while (parent[f] > 0) {
        f = parent[f];
    }
    return f;
}


void MiniSpanTree_Kruskal(MGraph g)
{
    int i, n ,m;
    Edge edges[MAXEDGE];
    int parent[MAXVEX];

    for (i = 0; i < g.numVertexes; i++) 
        parent[i] = 0;
    for (i = 0; i < g.numEdges; i++) 
    {
        n = find(parent, edges[i].begin);
        m = find(parent, edges[i].end);
        if (n != m) {
            parent[n] = m;
            printf("(%d, %d) %d ",edges[i].begin,edges[i].end,edges[i].weight);
        }
    }
    
}

int main(int argc, char *argv[])
{

    return 0;
}