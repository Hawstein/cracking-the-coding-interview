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

node* findNthToLast(node *head, int n){
    if(head==NULL || n<1) return NULL;
    node *p=head, *q=head;
    while(n>0 && q){
        q = q->next;
        --n;
    }
    if(n>0) return NULL;
    while(q){
        p = p->next;
        q = q->next;
    }
    return p;
}
node *pp;
int nn;
void findNthToLast1(node *head){
    if(head==NULL) return;
    findNthToLast1(head->next);
    if(nn==1) pp = head;
    --nn;
}
int main(){
    int n = 10;
    int a[] = {
        9, 2, 1, 3, 5, 6, 2, 6, 3, 1 
    };
    node *head = init(a, n);
    node *p = findNthToLast(head, 6);
    if(p) cout<<p->data<<endl;
    else cout<<"the length of link is not long enough"<<endl;
    nn = 6;
    findNthToLast1(head);
    if(pp) cout<<pp->data<<endl;
    return 0;
}
