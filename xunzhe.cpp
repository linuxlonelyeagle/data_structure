#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    int a[n];
    for (auto i = 0; i < n ; i++) {
        cin >> a[i];
    }
    for (auto i = 0; i < n-1; i++) {
        auto min = i;
        for (auto j = i+1; j < n-1;j++) {
            if (a[i] > a[j]) {
                min = j;
            }
        }
        if (i != min) {
            auto t = a[i];
            a[i] = a[min];
            a[min] = t;
        }
    }
    for (auto i : a) 
    cout << i << " ";
    cout << endl;
    return 0;
}