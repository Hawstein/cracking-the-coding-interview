#include <iostream>
#include <cstring>
#include <vector>
#include <list>
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
void createMinimalTree(Node* &head, Node *parent, int a[], int start, int end){
    if(start <= end){
        int mid = (start + end)>>1;
        node[cnt].key = a[mid];
        node[cnt].parent = parent;
        head = &node[cnt++];
        createMinimalTree(head->lchild, head, a, start, mid-1);
        createMinimalTree(head->rchild, head, a, mid+1, end);
    }
}

vector<list<Node*> > find_level_linklists(Node *head){
    vector<list<Node*> > res;
    int level = 0;
    list<Node*> li;
    li.push_back(head);
    res.push_back(li);
    while(!res[level].empty()){
        list<Node*> l;
        list<Node*>::iterator it;
        for(it=res[level].begin(); it!=res[level].end(); ++it){
            Node *n = *it;
            if(n->lchild) l.push_back(n->lchild);
            if(n->rchild) l.push_back(n->rchild);
        }
        ++level;
        res.push_back(l);
    }
    return res;
}
void print(vector<list<Node*> > res){
    vector<list<Node*> >::iterator vit;
    for(vit=res.begin(); vit!=res.end(); ++vit){
        list<Node*> li = *vit;
        list<Node*>::iterator lit;
        for(lit=li.begin(); lit!=li.end(); ++lit){
            Node *n = *lit;
            cout<<n->key<<" ";
        }
        cout<<endl;
    }
}
int main(){
    init();
    int a[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8
    };
    Node *head = NULL;
    createMinimalTree(head, NULL, a, 0, 6);
    vector<list<Node*> > res;
    res = find_level_linklists(head);
    print(res);
    return 0;
}
