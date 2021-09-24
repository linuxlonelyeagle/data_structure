#include <iostream>

using namespace std;

class cur_list{
public:
    typedef struct cur_li{
        int id;
        struct cur_li* next;
    }node, *pcur_list;
    cur_list(){};
    cur_list(int);
    void scan_list();
    void jos(int );
private:
    pcur_list head = nullptr;
};

void cur_list::jos(int m)
{
    pcur_list cur, pre, del;
    cur  = pre = head;
    del = nullptr;
    bool flag = true;
    while (pre->next != head) {
        pre = pre->next;
    }

    while (flag) {
        for (auto i = 1;i < m ;i++) {
            pre = pre->next;
            cur = cur->next;
        }
        if (cur == pre) 
            flag = false;
        del = cur;
        pre->next = cur->next;
        cur = cur->next;
        cout << del->id << " ";
        delete del;
    }
        
}
void  cur_list::scan_list()
{
    auto it = head;
    cout << it->id<< " ";
    it = it->next;
    while (it!=head) {
        cout << it->id <<" ";
        it = it->next;
    }
}

cur_list::cur_list(int n)
{
    auto i = 1;
    head = new(node);
    head->next = head;
    head->id = i ;
    auto it = head;
    while (i < n) {
        auto tp = new(node);
        tp->id = ++i;
        tp->next = it->next;
        it->next = tp;
        it = tp;
    }   
}

int main(void )
{
    int n;
    cin >> n;
    cur_list a(n);
    cin >> n;
    a.jos(n);
    return 0;
}
