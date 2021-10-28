#include <iostream>

using namespace std;

typedef struct node {
    char data;
    struct node *lchild,*rchild;   
}node,*pnode;

void createbitree(pnode * T)
{
    char ch;
    cin >> ch;
    if (ch == '#')
    *T = nullptr;
    else {
        *T = (pnode)malloc(sizeof(node));
        if (*T == nullptr) {
            cout << "申请空间失败" << endl;
            return;
        }
        (*T)->data = ch;
        createbitree(&(*T)->lchild);
        createbitree(&(*T)->rchild);
    }    
}

void pre(pnode t)
{
    if (t == nullptr)
    return;
    cout << t->data << endl;
    pre(t->lchild);
    pre(t->rchild);
}

int main(int argc, char *argv[])
{
    pnode t;
    createbitree(&t);
    pre(t);
    return 0;
}