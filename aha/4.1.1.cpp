#include <iostream>

using namespace std;
int n,a[10],book[10]; // a[10] 代表的是 1 ～9 这9 个盒子，book这个数组记录的是手中牌的数量

void dfs(int step)
{
    if (step == n+1) {
        for (auto i = 1; i <= n ;i++) {
            cout << a[i];
        }
        cout << endl;
        return;
    }
    for (auto i = 1; i <= 9;i++) {
            if (book[i] == 0) {
            a[step] = i;
            book[i] = 1; 
            dfs(step+1);   
            book[i] = 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
        }  
    }
}

int main(int argc,char *argv[])
{
    cin >> n;
    dfs(1);    
    return 0;
}