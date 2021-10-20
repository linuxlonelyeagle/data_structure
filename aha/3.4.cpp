#include <iostream>

using namespace std;



void f(int a,int b){
    if (a) {
        for (auto i = 1; i <= 9; i++) {
            cout << i +b*10 << endl;
            f(a-1,b*10+i);
        }
    }        
}

int main(int argc, char *argv[])
{
    int a;
    cin >> a;
    f(a,0);
    return 0;
}