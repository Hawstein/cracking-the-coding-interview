#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100;
struct Node{
    int key;
    Node *lchild, *rchild, *parent;
};
Node node[maxn];
int cnt;

void init(){
    memset(node, '\0', sizeof(node));
    cnt = 0;
}
void create_minimal_tree(Node* &head, Node *parent, int a[], int start, int end){
    if(start <= end){
        int mid = (start + end)>>1;
        node[cnt].key = a[mid];
        node[cnt].parent = parent;
        head = &node[cnt++];
        create_minimal_tree(head->lchild, head, a, start, mid-1);
        create_minimal_tree(head->rchild, head, a, mid+1, end);
    }
}
bool match(Node* r1, Node* r2){
    if(r1 == NULL && r2 == NULL) return true;
    else if(r1 == NULL || r2 == NULL) return false;
    else if(r1->key != r2->key) return false;
    else return match(r1->lchild, r2->lchild) && match(r1->rchild, r2->rchild);
}
bool subtree(Node* r1, Node* r2){
    if(r1 == NULL) return false;
    else if(r1->key == r2->key){
        if(match(r1, r2)) return true;
    }
    else return subtree(r1->lchild, r2) || subtree(r1->rchild, r2);
}
bool contain_tree(Node* r1, Node* r2){
    if(r2 == NULL) return true;
    else return subtree(r1, r2);
}
int main(){
    init();
    int a1[] = {
        0, 1, 2, 3, 4, 5, 6
    };
    int a2[] = {
        0, 1, 2
    };
    Node *r1 = NULL, *r2 = NULL;
    create_minimal_tree(r1, NULL, a1, 0, 6);
    create_minimal_tree(r2, NULL, a2, 0, 2);
    if(contain_tree(r1, r2))
        cout<<"tree r1 contains r2"<<endl;
    else cout<<"tree r1 does not contaions r2"<<endl;
    return 0;
}
