#include <iostream>
#include <deque>

using namespace std;

int main(int argc,char *argv[])
{
    deque<int> deq;
    auto n = 0;
    cin >> n;
    for (auto i = 1; i <= n; i++) {
        auto tp = 0;
        cin >> tp;
        deq.push_back(tp);
    }
    while (deq.begin() != deq.end()) {
        cout << deq.front() << " ";
        deq.pop_front();
        int tp = deq.front();
        deq.pop_front();
        deq.push_back(tp);
    }
    cout << endl;
    return 0;
}