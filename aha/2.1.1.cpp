#include <iostream>

using namespace std;


int main(int argc,char *argv[])
{
    int q[102] = {0,6,3,1,7,5,8,9,2,4};
    auto head = 1;
    auto tail = 10;   // 这个指向最后一个元素之后的位置
    while ( head < tail ) {     // 只要队列不位空，就说明没有出队完成
        cout << q[head] << " ";
        head++;   // 出队
        q[tail++] =  q[head];   
        head++;
    }
    cout << endl;
    return 0;
}