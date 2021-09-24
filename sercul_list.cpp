#include <iostream>

using namespace std;

class cercul {
    public:
        typedef struct curcul_list {
            int id;
            int passwd;
            curcul_list* next;
        }Curcul_list, *Pcurcul_list;
        cercul() {};
        cercul(istream& cin);
        void scan_list();
        void josephus();
    private:
        Pcurcul_list head = nullptr;        
        int n = 0;
        int m = 0;

};

cercul::cercul(istream& cin)
{
    cin >> n >> m;
    Pcurcul_list it = nullptr;
    Pcurcul_list new_node;
    for (auto i = 1; i<= n; i++) {
        new_node = new(Curcul_list);
        cin >> new_node->passwd;
        new_node->id = i;
        if (it == nullptr) {
            it = new_node;
            head = new_node; 
            it->next = it;
        } else {
            new_node->next = it->next;
            it->next = new_node;
            it = new_node;
        }               
    }
}


void cercul::scan_list()
{
    auto it =head;
   if (it) {
       do {
        cout << it->passwd << " ";
        it = it->next;
       }while(it != head);
   }
}

void cercul::josephus()
{
    Pcurcul_list cur, pre, del;
    cur = pre = head;
    del = nullptr;
    while (pre->next != head)    // 这个是没有头指针的循环链表 
        pre = pre->next;          //让Pre指向最后一个元素，因为是从第一个元素开始
    bool flag = true;

    while (flag) {
        for (auto i = 1; i < m; i++) {    // 这里不能从 = ，因为我们从第一个节点开始的
           cur =cur->next;
           pre = pre->next;
        }
        if (cur == pre) 
            flag = false;
        del = cur;
        pre->next = cur->next;
        cur = cur->next;
        cout << del->id << " ";
        m = del->passwd;
        delete del;
    }
    head = nullptr;
    m = n = 0;
}

int main()
{
    cercul a(cin);
    a.josephus();
    return 0;
}