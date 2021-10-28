#include <iostream>
#include "ljjz.h"
using namespace std;
void CreateMGraph(MGraph *G)
{
    int i, j, k, w;
    cout << "输入顶点数和边数:" << endl;
    cin >> G->numVertexes >> G->numEdges;
    for (i = 0; i < G->numVertexes; i++)   // 建立顶点表
        cin >> G->vexs[i];
    for (i = 0; i < G->numVertexes; i++) {    // 领结矩阵初始化
        for (j = 0; j < G->numVertexes;i++) 
            G->arc[i][j] = INFINITY;   
    }
    for ( k = 0; k < G->numEdges; k++) {   // 读入numEdges条边
        cout << "输入边(vi,vj)上的下标i,下标j和权w:\n";
        cin >> i >> j >> w;
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];  // 因为是无向图，矩阵对称
    }
}
