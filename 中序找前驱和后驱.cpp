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

// 中序线索化

void mid_thread(BiThrTree root)
{
    if (root) {
        mid_thread(root->lchild);
        if (root->lchild == nullptr) {
            root->LTag = Thread;
            root->lchild = pre;
        }
        if (pre != nullptr && pre->rchild == nullptr) {
            pre->RTag = Thread;
            pre->rchild = root;
        }
        pre = root;
        mid_thread(root->rchild);
    }
}

//查找前驱
//查找第一个节点
BiThrTree find_first(BiThrTree root)
{
    if (root == nullptr) return nullptr;
    while (root->LTag == Link) 
        root = root->lchild;
    return  root;            
}

BiThrTree next(BiThrTree root)
{
    if (root->RTag == Link) return find_first(root->rchild);
    else return root->rchild; 
}

void inorder(BiThrTree root) {
    for (auto i = find_first(root); i != nullptr ;i = next(i))
        cout << i->data << " ";
    cout << endl;
}

void pre_scan(BiThrTree root)
{
    if (root) {
        cout << root->data << endl;
        pre_scan(root->rchild);
        pre_scan(root->lchild);
    }
}


BiThrTree find_last(BiThrTree root)
{
    
    while (root->rchild != nullptr && root->RTag == Link) {
       // printf("geklll %c\n",root->data);
    root = root->rchild;
    }
    return root;
}


BiThrTree prenode(BiThrTree root)
{
    if (root == nullptr) return nullptr;
    if (root->LTag == Link) return find_last(root->lchild);
    else return root->lchild;
}

void rev_inorder(BiThrTree root)
{
    for (auto i = find_last(root); i != nullptr; i = prenode(i) ){
            cout << i->data << " ";
    }
    cout << endl;
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



int main(int argc, char *argv[])
{
    BiThrTree root;
    Create_tree(&root);
    pre_scan(root);
    mid_thread(root);
    inorder(root);
    rev_inorder(root);  
    return 0;
}
