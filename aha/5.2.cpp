#include <iostream>
using namespace std;

int min = 9999999, book[101], n, e[101][101];

void dfs(int cur, int dis) {
    int j;
    if (dis > ::min) return;  //   如果走过的路径大于 min 就没有必要再走了
    if (n == cur ) {    // 如果已经到了当前的节点
        if ( dis < ::min) 
        ::min = dis;
        return;
    }
    for (j = 1; j <= n; j++) {
        if (book[j] == 0 && e[cur][j] != 9999999) {
            book[j] = 1;
            dfs(j,dis + e[cur][j]);
            book[j] = 0;
        }
    }
    return;
}

int main(int argc, char* argv[])
{
    int i, j, m, a, b, c;
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if ( i == j ) e[i][j] = 0;
            else e[i][j] = 9999999;
        }
    }

    for (i = 1; i <= m;i++) {
        cin >> a >> b >> c;
        e[a][b] = c;
    }
    book[1] = 1;
    dfs(1,0);
    cout << "最短路径:" << ::min << endl;
    return 0;
}