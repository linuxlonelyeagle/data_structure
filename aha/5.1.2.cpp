#include <iostream>
#include <queue>
using namespace std;
int main(int argc, char *argv[])
{
    int i, j, n, m, a, b, cur, book[101] ={0},e[101][101];
    int que[10001], head, tail;
    cin >> n >> m;
    for (i = 1 ; i <= n;i++) {
        for (j = 1; j <= m; j++) {
            if ( i == j) e[i][j] = 0;
            else e[i][j] = 9999999;
        }
    } 

    for ( i = 1; i <= m;i++) {
        cin >> a >> b;
        e[a][b] = 1;
        e[b][a] = 1;
    }
    
    head = tail = 1;
    que[tail] = 1;
    tail++;
    book[1] = 1;
    while (head < tail && tail <=n) {
        cur = que[head];
        for (i = 1; i <=n; i++) {
            if (e[cur][i] == 1 && book[i]==0) {
                que[tail] = i;
                tail++;
                book[i] = 1;
            }

            if (tail > n) 
            break;
        }
        head++;
    }

    for (i = 1; i < tail; i++) 
        cout << que[i];
    return 0;
}