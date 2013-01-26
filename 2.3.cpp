#include <iostream>
using namespace std;

typedef struct node{
    int data;
    node *next;
}node;

node* init(int a[], int n){
    node *head, *p;
    for(int i=0; i<n; ++i){
        node *nd = new node();
        nd->data = a[i];
        if(i==0){
            head = p = nd;
            continue;
        }
        p->next = nd;
        p = nd;
    }
    return head;
}

bool remove(node *c){
    if(c==NULL || c->next==NULL) return false;
    // if(c->next==NULL){//c为最后一个元素时直接删除，不行，最后还是会打印出一个为0的结点，需要特殊处理
    //     delete c;
    //     return;
    // }
    node *q = c->next;
    c->data = q->data;
    c->next = q->next;
    delete q;
    return true;
}
void print(node *head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    int n = 10;
    int a[] = {
        9, 2, 1, 3, 5, 6, 2, 6, 3, 1 
    };
    node *head = init(a, n);
    int cc = 3;
    node *c = head;
    for(int i=1; i<cc; ++i) c = c->next;
    print(head);
    if(remove(c))
        print(head);
    else
        cout<<"failure"<<endl;
    return 0;
}
