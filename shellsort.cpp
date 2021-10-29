#include <iostream>
#define MAXSIZE 10

using namespace std;
typedef struct {
    int length;
    int r[MAXSIZE];
}Sqlist;

void shellsort(Sqlist *t)
{
    int i, j;
    int increment;
    do {
        increment = increment / 3 + 1;
        for ( i = increment + 1; i <= t->length ; i++) {
            if (t->r[i] < t->r[i - increment]) {
                t->r[0] = t->r[i];
                for ( j = i-increment; j > 0 &&  t->r[0] < t->r[j] ; j-= increment) 
                    t->r[j+increment] = t->r[j];
                    t->r[j+increment] = t->r[0];
            }
        }
    }while (increment > 1) ;       
}

int main(int argc,char *argv[])
{

    Sqlist a;
    cin >>  a.length;
    for (auto i = 1; i <= a.length ; i++)
        cin >> a.r[i];
    shellsort(&a);
    for (auto i = 1; i <= a.length ; i++) 
        cout << a.r[i] << " ";
        cout << endl;    
    return 0;
}