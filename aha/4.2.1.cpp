#include <iostream>

using namespace std;

int n,m,p,q,Min = 99999;
int a[51][51],book[51][51];
int Next[4][2] ={{0,1},{1,0},{0,-1},{-1,0}};

void dfs(int x,int y,int step) {
    if (x==p && y == q) {
        if (step < Min ) {
            Min = step;
            return;
        }
    }
    for (auto i = 0; i < 4;i++) {
        auto tx = x+ Next[i][0];
        auto ty = y + Next[i][1];
        if (tx <1 || tx > n || ty < 1 || ty >m)
        continue;
        if (book[tx][ty] == 0 && a[tx][ty] == 0 ) {
            book[tx][ty] = 1;
            dfs(tx,ty,step+1);
            book[tx][ty] = 0;
        }
    }
}


int main(int argc, char *argv[])
{
    
    int i, j, startx, starty;
    cin >> n >> m;
    for (i =1;i<=n;i++) {
        for (j = 1;j <= m;j++) {
            cin >> a[i][j];
        }
    }
    cin >> startx >> starty >> p  >> q;

    book[startx][starty] = 1;
    dfs(startx,starty,0);
    cout << Min << endl;
    return 0;
}