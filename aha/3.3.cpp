#include <iostream>

using namespace std;

int fun(int x)
{
    int sum = 0;
    int f[10] = {6,2,5,5,4,5,6,3,7,6};
    while (x/10!=0) {  //说明有余数
        sum += f[x%10];
        x /= 10;
    }
    sum += f[x];
    return sum;
}

int main(int argc,char *argv[])
{
    int n,c,sum = 0;
    cin >> n;
    for (auto a = 0; a <=1111; a++) {
        for (auto b = 0; b <=1111;b++) {
            c = a + b;
            if (fun(a)+fun(b)+fun(c) == n-4) {
                printf("%d + %d = %d\n",a,b,c);
                sum++;
            }
        }
    }
    cout << sum << endl;
    return 0;
}