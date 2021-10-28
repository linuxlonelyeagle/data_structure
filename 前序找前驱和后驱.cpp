#include <iostream>
using namespace std;
typedef enum{Link, Thread} PointerTag;
typedef struct BithrNode
{
    char data;
    struct BithrNode *lchild, *rchild;
    PointerTag LTag;
    PointerTag RTag;
}BiThrNode, *BiThrTree;

BiThrTree pre;

void Create_tree(BiThrTree *T)
{   
    
    char ch;
    cin >> ch;
    if (ch == '#') 
        *T = NULL;
    else {
        *T = (BiThrTree)malloc(sizeof(BithrNode));
        (*T)->data = ch;
        (*T)->LTag = Link;
        (*T)->RTag = Link;
        Create_tree(&(*T)->lchild);
        Create_tree(&(*T)->rchild);                                        
    }

}
void pre_theading(BiThrTree root)
{
    if (root) {
        if (root->lchild == nullptr) {
            root->lchild  = pre;
            root->LTag = Thread;
        } 
        if (pre != nullptr && pre->rchild == nullptr) {
            pre->rchild = root;
            pre->RTag = Thread;
        }
        pre = root;
        if (root->LTag == Link)
        pre_theading(root->lchild);
        if (root->RTag == Link)
        pre_theading(root->rchild);
    }   
}

BiThrTree find_next(BiThrTree root)
{
    if (root == nullptr)
    return nullptr;
    if (root->RTag == Thread)  // 有直接的后继
    return root->rchild;
    else if (root->LTag == Thread && root->rchild!= nullptr) // 没有左孩子，有右边孩子
    return root->rchild;
    else if (root->LTag == Link)  // 有左孩子
    return root->lchild; 

    else return nullptr;
}

void pre_scan(BiThrTree root)
{
    if (root) {
        cout << root->data << endl;
        pre_scan(root->lchild);
        pre_scan(root->rchild);
    }
}


BiThrTree find_pre(BiThrTree root)
{
    if (root == nullptr) return nullptr;
    if (root->LTag == Thread)
    return  root->lchild;


}

int main(int argc, char argv[])
{
    BiThrTree t;
    Create_tree(&t);
    pre_scan(t);
    pre_theading(t);
    for (;t != nullptr;t = find_next(t)) {
        cout << t->data << endl;
    }
    return 0;
}