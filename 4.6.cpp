#include <iostream>
#include <map>
#include <cstring>
using namespace std;

const int maxn = 100;
struct Node{
    int key;
    Node *lchild, *rchild, *parent;
};
Node *p, node[maxn];
int cnt;

void init(){
    p = NULL;
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
Node* first_ancestor(Node* n1, Node* n2){
    if(n1 == NULL || n2 == NULL) return NULL;
    map<Node*, bool> m;
    while(n1){
        m[n1] = true;
        n1 = n1->parent;
    }
    while(n2 && !m[n2]){
        n2 = n2->parent;
    }
    return n2;
}
bool father(Node* n1, Node* n2){
    if(n1 == NULL) return false;
    else if(n1 == n2) return true;
    else return father(n1->lchild, n2) || father(n1->rchild, n2);
}
Node* first_ancestor1(Node* n1, Node* n2){
    if(n1 == NULL || n2 == NULL) return NULL;
    while(n1){
        if(father(n1, n2)) return n1;
        n1 = n1->parent;
    }
    return NULL;
}
void first_ancestor2(Node* head, Node* n1, Node* n2, Node* &ans){
    if(head==NULL || n1==NULL || n2==NULL) return;
    if(head && father(head, n1) && father(head, n2)){
        ans = head;
        first_ancestor2(head->lchild, n1, n2, ans);
        first_ancestor2(head->rchild, n1, n2, ans);
    }
}
Node* search(Node* head, int x){
    if(head == NULL) return NULL;
    else if(x == head->key) return head;
    else if(x <= head->key) search(head->lchild, x);
    else search(head->rchild, x);
}
int main(){
    init();
    int a[] = {
        0, 1, 2, 3, 4, 5, 6
    };
    Node *head = NULL;
    create_minimal_tree(head, NULL, a, 0, 6);
    Node *n1 = search(head, 0);
    Node *n2 = search(head, 4);
    cout<<n1->key<<" "<<n2->key<<endl;
    Node *ans = first_ancestor(n1, n2);
    cout<<ans->key<<endl;
    Node *ans1 = NULL;
    first_ancestor2(head, n1, n2, ans1);
    cout<<ans1->key<<endl;
    return 0;
}
