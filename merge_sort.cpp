#include <iostream>
using namespace std;

#define MAXSIZE 50
typedef struct {
    int r[MAXSIZE];
    int length;
}Sqlist;


void Merge(int SR[], int TR[], int i,int m,int n)
{
    int j, k ,l;
    for ( j = m + 1,k = i; i<= m && j <= n;k++){
        if (SR[i] < SR[j])
            TR[k] = SR[i++];
        else 
            TR[k] = SR[j++];                
    }
    if ( i <= m) {
        for (l = 0; l <= m-i;l++)
            TR[k+l] = SR[i+l];
    } 
    if ( j <= n) {
        for ( l = 0; l <= n-j;l++)
            TR[k+l] = SR[j+l];
    }
}

//将SR[s...t] 归并序列为TR1[s...t]
void Msort(int SR[], int TR1[], int s,int t)
{
    int m;
     int TR2[MAXSIZE+1];
    if (s == t)
        TR1[s] = SR[s];
    else {
        m = (s+t)/2;
        Msort(SR,TR2,s,m);   // 将sr[s...m]归并为有序tr2[s...m]      
        Msort(SR,TR2,m+1,t);    // 将sr[s...m]归并为有序tr2[m+1,t]
        Merge(TR2,TR1,s,m,t);   // 将SR[s...m] 和TR2[m+1...t]
                                // 归并到TR1[s...t];        
    }
}


void MergeSort(Sqlist *L)
{
    Msort(L->r,L->r,1,L->length);
}


int main(int argc,char *argv[])
{

    Sqlist l;
    cin >> l.length;
    for (auto i = 1; i <= l.length; i++)
        cin >> l.r[i];
    MergeSort(&l);
    for (auto i = 1; i <=l.length; i++)
        cout << l.r[i] << " ";
        cout << endl;
    return 0;
}
