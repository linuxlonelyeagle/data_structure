#include <iostream>

using namespace std;

int arr[100],n;

void quick_sort(int left, int right) {
    if (left >right)
    return;
    int temp = arr[left];
    int i = left,j = right;
    while (i != j) {
        while (arr[j] >= temp && i < j) 
            j--;
        while (arr[i] <= temp && i < j) 
            j++;
        if (i < j) {    //也就是说当两个哨兵没有相遇的时候
            auto t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
        arr[left] = arr[i];
        arr[i] = temp;
    }    
    quick_sort(left,i-1);
    quick_sort(i+1,right);

}

int main(int argc,char *argv[]) 
{
    cin >> n;
    for (auto i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    quick_sort(1,n);
    for (auto i = 1; i <=n ;i++) {
        cout << arr[i] << " ";
    }    
    cout << endl;
    return 0;
}