#include <cstdlib>
#include <iostream>
#include <initializer_list>

using namespace std;
class linklist {
    public:

    typedef struct node {
        int data;
        node *next;   
    }Lnode, *Linklist;

    linklist() { head = nullptr; }
    linklist(initializer_list<int> t);
    linklist(istream&);

    ~linklist() {};
    int& operator[](int idx);

    void create_node_head();
    void create_node_end();
    void scan_node();
    void reverse_linklist();
    void extend_sort(linklist &);     // 合并链表
    void free();

    private :
        Linklist head;        
};

int& linklist::operator[](int idx)
{
    idx;
    auto it = head->next;
    int i = 0;
    while (it && idx!=i){
        it = it->next;
        i++;
    }
    return it->data;
}

linklist::linklist(istream& cin)
{
    head = (Linklist)malloc(sizeof(node));
    if (head == nullptr) {
        cout << "申请节点失败" << endl;
    }
    auto it = head;
    Linklist tp;
    int a;
    cin >> a;
    while (a != -1) {
        tp = (Linklist)malloc(sizeof(node));
        tp->data = a;
        it->next = tp;
        it = tp;
        cin >> a;
    }
    it->next = nullptr;
}

linklist::linklist(initializer_list<int> t)
{
    head = (Linklist)malloc(sizeof(node));
    auto it = head;
    Linklist tp;
    for (auto i : t) {
        tp = (Linklist)malloc(sizeof(node));
        tp->data = i;
        it->next = tp;
        it = tp;                
    }
    it->next =nullptr;            
}

void linklist::extend_sort(linklist &tp)
{
    auto i = head;
    auto a = head->next;
    auto b = tp.head->next;
    while (a!=nullptr && b !=nullptr) {
        if (a->data < b->data) {
            i->next = a; 
            i = a;             
            a = a->next;
        } 
        else if (a->data >= b->data)  
        {
            i->next = b;
            i = b;
            b = b->next;
        }
    }
    if (a)
        i->next = a;
    if (b)
        i->next = b; 
    std::free(tp.head); 
}

void linklist::free() 
{
    while (head) {
        auto tp = head;
        head = head->next;
        std::free(tp);
    }
    cout << "释放链表成功" << endl;
}

void linklist::create_node_end()
{
    head = (Linklist)malloc(sizeof(node));
    if ( head == nullptr ) {
        cout << "申请空间失败" <<endl;
        return;
    }         
    Linklist end = head;
    int temp;
    cin >> temp;
    while (temp != -1) {
        Linklist tp = (Linklist)malloc(sizeof(node));
        if (tp == nullptr) {
            cout << "申请空间失败" << endl;
        }
        tp->data = temp;
        tp->next = nullptr;
        end->next = tp;
        end = tp;
        cin >> temp;
    }
}

void linklist::reverse_linklist() 
{
    Linklist r, t;
    r = head->next;    // 相当与创建一个没有头节点的链表
    head->next = nullptr;  // 相当与创建一个空链表 
    while (r) {
        t = r; 
        r = r->next;
        t->next = head->next;
        head->next = t;
    }   
}


void linklist::scan_node()
{
    auto tp = head->next;
    while (tp) {
        cout << tp->data << " ";
        tp = tp->next;
    }
    cout << endl;
}

void linklist::create_node_head()
{

    head = (Linklist)malloc(sizeof(Lnode));
    if (head == nullptr) {
        cout << "申请空间失败" << endl;
    }

    head->next=nullptr;
    int temp;
    cin >> temp;
    while (temp != -1) {
        Linklist tp = (Linklist)malloc(sizeof(Lnode));
        tp->data =  temp;
        tp->next =   head->next;
        head->next = tp;
        cin >> temp;
    }       
}

int main(void) 
{
    linklist a({1,2,3,4,5});
    a.scan_node();
    a[2] = 6;
    a.scan_node();
    a.free();
    return 0;
}
