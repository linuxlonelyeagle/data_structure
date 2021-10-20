#include <iostream>
#include <stack>

using namespace std;

int main(int argc,char *argv[])
{
    string str;
    cin >> str;
    auto mid = str.size() / 2 - 1;
    int next;
    stack<char> sta_char;

    for (auto i = 0; i <= mid; i++) {
        sta_char.push(str[i]);
    }

    if (str.size()%2)    // 如果是基数的话
        next = mid + 2;
    else  if (str.size()%2 == 0) 
        next = mid +1;
   

    for (auto i = next ; i < str.size() ; i++) {
        if (sta_char.top() == str[i]) {
            sta_char.pop();
        } else {
            break;
        }
    }

    if ( sta_char.size() == 0 ) 
        cout << "yes" << endl;
    else 
        cout << "no"  << endl;
    return 0;
}