#include <initializer_list>
#include <iostream>

using namespace std;

int main(void)
{
    initializer_list<int> a = {1,2,3,4,5,6,7};
    for (auto i : a) {
        cout << i << " ";
    }    
    cout << endl;
    for (auto i = a.begin(); i != a.end() ;i++) {
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}

