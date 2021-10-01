#include <iostream>

using namespace std;

class PriorityQueue
{
public:
    typedef struct Node
    {
        int value;    // 数值越大，那么优先级就越高，如果要数值越小，优先级越高的话，就设置成成为value的相反数
        int priority; // 优先级
        struct Node *next;
    } Node, *Pnode;
    PriorityQueue();
    ~PriorityQueue() { delete head; }
    void push(int, int);
    Pnode peak();
    int pop();

private:
    Pnode head = nullptr;
};

PriorityQueue::PriorityQueue()
{
    head = new (Node);
    head->next = nullptr;
}

void PriorityQueue::push(int value, int priority)
{
    if (head->next == nullptr)
    { //也就是说我们没有节点，我们要先创建一个节点
        auto it = new (Node);
        it->value = value;
        it->priority = priority;
        it->next = head->next;
        head->next = it;
        return;
    }
    auto it = head->next;
    if (it->priority < priority)
    {                              // 先判断开头的节点是不是符合条件
        auto newnode = new (Node); // 这个时候我们有两个节点，一个是头指针和头节点
        newnode->priority = priority;
        newnode->value = value;
        newnode->next = it;
        head->next = newnode;
    }
    else
    {
        // 其实这个时候我们有两个节点，一个是it的下一个节点，一个是it 的前一个节点
        while (it->next != nullptr && it->next->priority > priority)
        {
            it = it->next;
        }
        // 如果到尾巴节点的时候，我们其实已经知道了尾巴节点的priortity是大于priority的
        auto newnode = new (Node);
        newnode->priority = priority;
        newnode->value = value;
        newnode->next = it->next;
        it->next = newnode;
    }
}

PriorityQueue::Pnode PriorityQueue::peak()
{
    return head->next;
}

int PriorityQueue::pop()
{
    auto temp = head->next;
    head->next = head->next->next;
    auto value = temp->value;
    delete temp;
    return value;
}

int main(void)
{
    PriorityQueue queue;
    queue.push(100, 100);
    queue.push(2000,2000);
    cout << queue.pop() << endl;
    return 0;
}