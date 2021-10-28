#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    int arr[n];
    for (auto i = 0; i < n; i++)
        cin >> arr[i];
    cout << "请输入你要查找的值:" << endl;
    int key;
    cin >> key;
    auto low = 0, high = n-1;
   int weizhi = 0;
    while (low <= high) {
        weizhi = low + (key - arr[low]) * (high - low) / (arr[high] - arr[low]);
        if (weizhi > n-1) {
            cout << "数组下标越界" << endl;
            return 0;
        }
        if (key == arr[weizhi])
        break;
        else if (key > arr[weizhi])
        low  = weizhi+1;
        else if (key < arr[weizhi])
        high = weizhi-1;
    }
    if (low > high)
    cout << "没有找到指定的元素" << endl;
    else 
    cout << "找到了指定的元素:" << arr[weizhi] << endl;
    return 0;
}