#include <iostream>

using namespace std;

int main(int argc,char *argv[])
{
    int n;
    cin >> n;
    int a[n];
    for (auto i=0; i < n;i++) {
        cin >> a[i];
    }
    //冒泡排序
    for (auto i = 0; i < n -1; i++) {  // 只需要n-1次循环
        for (auto j = n - 1; j >= i;j--) {   //我们要从后面开始开始循环
            if (a[j] > a[j+1]) {
                auto k = a[j];
                a[j] = a[j+1];
                a[j+1] = k;
            }
        }
    }
    for (auto i : a) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}