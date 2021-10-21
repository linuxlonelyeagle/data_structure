#include <iostream>

using namespace std;

int book[101], sum, n, e[101][101];

void dfs(int cur) {
    cout << cur << endl;
    sum++;
    if (sum == n) return;
    for (int i =1 ; i <= n;i++) {
        if (e[cur][i] == 1 && book[i] == 0) {
            book[cur] = 1;
            dfs(i);
        }
    }

}

int main(int argc,char *argv[])
{

    int i,j,m,a,b;
    cin >> n >> m;
    for (i = 1;i<=n;i++) {
        for (j = 1;j <= m;j++) {
            if (i==j) e[i][j] =0;
            else e[i][j] =9999999;
        }
    }

    for (i = 1;i<=m;i++) {
        cin >> a >> b;
        e[a][b] = 1;
        e[b][a] = 1;
    }
    book[1] = 1;
    dfs(1);
    return 0;
}