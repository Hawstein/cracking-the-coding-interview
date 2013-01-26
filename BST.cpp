#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100;

typedef struct BST{
    int key;
    BST *lchild, *rchild, *parent;
}BST;
BST *head, *p, node[maxn];
int cnt;

void init(){
    head = p = NULL;
    cnt = 0;
    memset(node, '\0', sizeof(node));
}

void insert(BST* &head, int x){
    if(head == NULL){
        node[cnt].key = x;
        node[cnt].parent = p;
        head = &node[cnt++];
        return;
    }
    p = head;
    if(head->key > x)
        insert(head->lchild, x);
    else
        insert(head->rchild, x);
}

void inorderTraver(BST *head){
    if(head == NULL) return;
    inorderTraver(head->lchild);
    cout<<head->key<<" ";
    inorderTraver(head->rchild);
}

BST* search(BST *head, int x){
    if(head == NULL) return NULL;
    if(head->key == x) return head;
    else if(head->key > x) 
        search(head->lchild, x);
    else
        search(head->rchild, x);
}

BST* minimum(BST *head){
    if(head == NULL) return NULL;
    while(head->lchild != NULL)
        head = head->lchild;
    return head;
}

BST* maximum(BST *head){
    if(head == NULL) return NULL;
    while(head->rchild != NULL)
        head = head->rchild;
    return head;
}

BST* successor(BST *head){
    if(head->rchild != NULL)
        return minimum(head->rchild);
    BST *y = head->parent;
    while(y!=NULL && y->rchild==head){
        head = y;
        y = y->parent;
    }
    return y;
}

BST* predecessor(BST *head){
    if(head->lchild != NULL)
        return maximum(head->lchild);
    BST *y = head->parent;
    while(y!=NULL && y->lchild==head){
        head = y;
        y = y->parent;
    }
    return y;
}

void delet(BST *z){
    if(z->lchild==NULL && z->rchild==NULL){
        if(z==head) head = NULL;
        else if(z->parent->lchild == z)
            z->parent->lchild = NULL;
        else
            z->parent->rchild = NULL;
    }

    else if(z->lchild==NULL || z->rchild==NULL){
        if(z==head){
            if(z->lchild) head = z->lchild;
            else head = z->rchild;
            head->parent = NULL;
        }
        else{
            if(z->parent->lchild==z && z->lchild){
                z->parent->lchild = z->lchild;
                z->lchild->parent = z->parent;
            }
            else if(z->parent->lchild==z && z->rchild){
                z->parent->lchild = z->rchild;
                z->rchild->parent = z->parent;
            }
            else if(z->parent->rchild==z && z->lchild){
                z->parent->rchild = z->lchild;
                z->lchild->parent = z->parent;
            }
            else{
                z->parent->rchild = z->rchild;
                z->rchild->parent = z->parent;
            }
        }
    }

    else{
        BST *s = predecessor(z);
        z->key = s->key;
        if(s->parent == z)
            s->parent->lchild = s->lchild;
        else
            s->parent->rchild = s->lchild;
        if(s->lchild)
            s->lchild->parent = s->parent;
    }
}
int main(){
    freopen("BST.in", "r", stdin);
    init();
    int x;
    while(cin>>x)
        insert(head, x);
    inorderTraver(head);
    cout<<endl;
    cout<<"Min: "<<(minimum(head))->key<<endl;
    cout<<"Max: "<<(maximum(head))->key<<endl;
    fclose(stdin);
    return 0;
}
