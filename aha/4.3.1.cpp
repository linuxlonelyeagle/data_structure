#include <iostream>
#include <queue>


using namespace std;

struct node
{
    node (int i , int j , int s) : x(i),y(j),step(s){}
    int x,y;
    int step;
    
};

int main(int argc, char *argv[])
{
    int a[51][51], book[51][51] = {0};
    int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    queue<node> que_node;
    int n, m;
    cin >> n >> m;
    for (auto i = 1; i <= n ; i++) {
        for (auto j = 1; j <= m; j++) 
        cin >> a[i][j];
    }
    int startx, starty, x, y , tx ,ty;
    bool flag  = false;
    cin >> startx >> starty >> x >> y;
    que_node.emplace(startx, starty, 0);
    while (!que_node.empty()) {
        for (auto i = 0; i < 4; i++) {
            tx = que_node.front().x + next[i][0];
            ty = que_node.front().y + next[i][1];
            //判断是否越界
            if ( tx < 1 || tx > n || ty < 1 || ty > m) 
            continue;
            if (book[tx][ty] == 0 && a[tx][ty] == 0) {
                book[tx][ty] = 1;
                que_node.emplace(tx,ty,que_node.front().step+1);
            }
            if (tx == x && ty == y) {
                flag = true;
                break;
            }
        }
        if (flag == 1) 
        break;
        que_node.pop();
    }
    cout << que_node.back().step << endl;
    return 0;
}