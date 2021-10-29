#include <iostream>
#define MAXSIZE 10
typedef struct {
    int r[MAXSIZE+1];   // r[0] 当作哨兵
    int length;          // length 就相当于是长度
}Sqlist;
using namespace std;

void InsertSort(Sqlist *L)
{
    int i,j;
    for (i = 2; i <= L->length; i++) {
        if (L->r[i] < L->r[i-1]) {
            L->r[0] = L->r[i];
            for (j = i-1; L->r[j]>L->r[0];j--) 
            L->r[j+1] = L->r[j];
            L->r[j+1] = L->r[0];
        }
    }
}

int main(int argc,char *argv[])
{
    Sqlist a;
    cin >> a.length;
    for (auto i = 1; i <= a.length; i++) 
        cin >> a.r[i];  
    InsertSort(&a);
    for (auto i = 1; i <= a.length;i++) 
        cout << a.r[i] << " ";
        cout << endl;  
    return 0;
}