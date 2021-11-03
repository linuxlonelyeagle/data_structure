#include <iostream>
#define MAXSIZE 10
using namespace std;
typedef struct 
{
    int r[MAXSIZE + 1];  // 用于存储要排序数组，r[0] 用做哨兵或临时变量
    int length;     // 用于记录顺序表的长度
}SqList;

void swap(SqList *l, int low,int high)
{
    int temp = l->r[low];
    l->r[low] = l->r[high];
    l->r[high] = temp;
}
int Partition(SqList *L, int low, int high)
{
    int pivokey;
    pivokey = L->r[low];  
    while (low < high) {   // low 和 high 其中一个的下标所指向的数组的值一定是pivokey
        while (low < high && L->r[high] >=pivokey)
        high--;
        swap(L,low,high);
        while (low < high && L->r[low] <= pivokey)
        low++;
        swap(L,low,high);
    }
    return low;  //其实我们这个函数最主要的作用就是查找pivokey的下标
    // 并且让左边的数组都小雨pivokey,右边的都大于
}

void QSort(SqList *L, int low, int high)
{
    int pivot;
    if (low < high) {
        pivot = Partition(L,low,high);
        QSort(L,low,pivot-1);
        QSort(L,pivot+1,high);
    }
}

// 对顺序表l作快速排序
void QuickSort(SqList*L)
{
    QSort(L,1,L->length);
}

int main(int argc,char *argv[])
{
    SqList l;
    cin >> l.length;
    for (auto i = 1; i <= l.length; i++)
         cin >> l.r[i];
    QuickSort(&l);
    for (auto i = 1; i<= l.length;i++)
        cout << l.r[i] << " ";
        cout << endl;
    return 0;
}