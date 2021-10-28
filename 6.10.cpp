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

void InThreading(BiThrTree p) 
{
    if (p){
        InThreading(p->lchild);
        if (!p->lchild) {
            p->lchild = pre;
            p->LTag = Thread;
        } 
        if (pre != nullptr && !pre->rchild) {
            pre->rchild = p;                                                                                   
            pre->RTag = Thread;
        }
        pre = p;
        InThreading(p->rchild);
    }
}

void pre_inthreading(BiThrTree root) 
{
    if (root) {
        if (root->lchild == nullptr) {
            root->LTag = Thread;
            root->lchild = pre;
        }
        if (pre != nullptr && pre->rchild == nullptr) {
            pre->RTag = Thread;
            pre->rchild = root;
        }
        pre = root;
        if (!root->LTag)  // 如果root-> LTag == 1 ，也就是说我们已经线索化了
        pre_inthreading(root->lchild);   // 防止栈溢出
        if (!root->RTag)
        pre_inthreading(root->rchild);
    }   
}

void hou_inthreading(BiThrTree root)
{
    if (root) {
        pre_inthreading(root->lchild);
        pre_inthreading(root->rchild);
         if (root->lchild == nullptr) {
            root->LTag = Thread;
            root->lchild = pre;
        }
        if (pre != nullptr && pre->rchild == nullptr) {
            pre->RTag = Thread;
            pre->rchild = root;
        }
        pre = root;
    }
}




void preorder(BiThrTree root)
{
    while (root ) 
    {
        while (root->LTag == Link) {
            cout << root->data << " ";
            root = root->lchild;
        }
        cout << root->data << endl;
        // 相当于左边的子树的左边的子树...的节点遍历了，接下来我们要处理右边的节点
        root = root->rchild;
        // 就是找root的后继节点,如果是线索的化，那么继续输出后继节点，
        // 如果不是线索的化，那就是右孩子，那么继续循环刚刚的过程。
    }
}


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

void pre_scan(BiThrTree t) {
    if (t) {
        cout << t->data << endl;//" " << t->LTag << " " << t->RTag << endl;
        pre_scan(t->lchild);
        pre_scan(t->rchild);
    }
}

void inorder(BiThrTree root) 
{
    while (root) {
        while (root->LTag == 0) {
            root = root->lchild;   
        }
        cout << root->data;
        while (root->RTag) {
            root = root ->rchild;
            cout << root->data ;
        }
        //也就是说root->rtag = link ，也就是说这里有右边的孩子。
        root = root->rchild;
    }
    cout << endl;
}

BiThrTree infirst(BiThrTree bt) {
    BiThrTree p = bt;
    if (!p) return nullptr;
    while (p->LTag == 0) p = p->lchild;
    return p;
}

int main(int argc, char *argv[])
{   
    
    BiThrTree t;
    Create_tree(&t);
    pre_scan(t);
    pre_inthreading(t);   
    preorder(t);
    return 0;
}