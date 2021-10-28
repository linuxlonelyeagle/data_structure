#include <iostream>
#include "ljjz.h"
using namespace std;
void MiniSpanTree_Prim(MGraph g)
{
    int min, i ,j ,k;
    int adjvex[MAXVEX]; // 保存相关顶点下标,
    //也就是说这个数组是用来记录路径的数组
    int lowcost[MAXVEX]; // 保存相关顶点间边的权值
    lowcost[0] = 0;   // 初始化第一个权值为0， 即v0加入生成树
    adjvex[0] = 0;   //       初始化第一个顶点的下标
    // 初始化
    for (i = 1; i < g.numVertexes; i++) {
        lowcost[i] = g.arc[0][i];
        adjvex[i] = 0;      // 初始化都为v0的下标
    }
    for ( i = 1; i = g.numVertexes; i++)
    {
        min = 65535;
        j = 1; k = 0;
        while ( j < g.numVertexes) {
            if (lowcost[j] != 0 && lowcost[j] < min) {
                min = lowcost[j];
                k = j;
            }
            j++;
        }
    }
    printf("(%d,%d)",adjvex[k],k);
    lowcost[k] = 0;
    for (j = 1; j < g.numVertexes; j++) {
        if (lowcost[j] != 0 && g.arc[k][j] < lowcost[j]) {
            lowcost[j] = g.arc[k][j];
            adjvex[j] = k;       
        }
    }
}


int main(int argc, char *argv[])
{    
    return 0;
}