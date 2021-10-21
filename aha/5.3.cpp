#include <iostream>
#include <queue>

using namespace std;

struct node {
    node(int x, int s):x(x),s(s) {}
    int x;   // 城市的编号
    int s;   // 转机的次数
};

int main(int argc, char *argv[])
{
    queue<node> que;
    int e[51][51] ={0}, book[51] = {0};
    int head, tail;
    int i, j, n, m, a, b,cur,start,end;
    bool flag = false;
    cin >> n >> m >> start >> end;
    //初始化二维矩阵
    for ( i = 1; i <= n; i++) {
        for ( j = 1; j <= n;j++) {
            if (i == j) e[i][j] = 0;
            else e[i][j] = 99999999;
        }
    }    
    for (i = 1; i <= m; i++) {
        cin >> a >> b;
        e[a][b] = 1;
        e[b][a] = 1;
    }

    que.emplace(start,0);
    book[start] = 1;
    while (!que.empty()) {
        cur = que.front().x;
        for (i = 1; i <= n;i++) {
            if (e[cur][i] != 99999999 && book[i] ==0) {
                book[i] = 1;
                que.emplace(i, que.front().s+1);
            }
            if (que.back().x == end) {
                flag = true;
                break;
            }
        }
        if (flag)
        break;
        que.pop();        
    }
    cout << " 转机的次数:" <<  que.back().s << endl;
    return 0;
}