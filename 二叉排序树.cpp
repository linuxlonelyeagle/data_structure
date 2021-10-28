#include <iostream>
using namespace std;

typedef struct  BiTNode
{
    int data;
    struct BiTNode *lchild,*rchild;
}Binode, *BiTree;
// 查找操作
bool SearchBST(BiTree T,int key, BiTree f, BiTree *p) {
    if (!T) {
        *p = f;
        return false;
    }
    else if (key == T->data) {
        *p = T;   // p是为了能够得到查到的位置
        return true;
    }
    else if (key < T->data) {
        return SearchBST(T->lchild,key,T,p);
    }
    else 
        return SearchBST(T->rchild,key,T,p);
}
// 二叉树的插入操作

bool InsertBST(BiTree *T,int key) {
    BiTree p,s;
    if (!SearchBST(*T,key,nullptr,&p)) {  // 先要看是不是查找到了
        s = new(BiTNode);
        s->data = key;
        s->lchild = s->rchild = nullptr;
        if (!p) {
            *T = s;
            return true;
        } else if (key < p->data) {
            p->lchild = s;
        } else 
            p->rchild = s;
        return true;
    } else 
        return false; // 如果没有查找到
}

bool Delete(BiTree *p) {
    BiTree q,s;
    if ((*p)->rchild == nullptr) {   // 也就是没有右子树
        q = *p;
        *p = (*p)->lchild;
        delete(q);
    } else if ((*p)->lchild == nullptr) {   // 也就是说没有左子树
        q = *p;
        *p = (*p)->rchild;
        delete(q);
    } else {
        q = *p;
        s = (*p)->lchild;
        while (s->rchild) {
            q = s;
            s = s->rchild;
        }
        (*p)->data = s->data;
        if (q != *p)    
            q->rchild = s->lchild; //q 相当是s 的父节点
        else 
            q->lchild = s->lchild;  
        // 这里的意思也就是说要删除的节点的左子树右边的孩子为空的情况
    }
    return true;
}


bool DeleteBST(BiTree* T,int key) {
    if (!*T)   // 也就是说这个是一颗空树
        return false;
    else {
        if (key > (*T)->data) 
            return DeleteBST(&(*T)->rchild,key);
        else if (key < (*T)->data)
            return DeleteBST(&(*T)->lchild,key);
        else 
            return Delete(T);
    }
}

void pre_scan(BiTree p) {
    if (p) {
        pre_scan(p->lchild); 
        cout << p->data << endl;
        pre_scan(p->rchild);
    }
}


int main(int argc, char *argv[])
{
    BiTree t = nullptr;
    for (auto i = 0; i < 10;i++) {
        InsertBST(&t,i);
    }
    pre_scan(t);
    return 0;
}