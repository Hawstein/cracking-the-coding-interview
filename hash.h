#include <cstring>

const int kWordSize = 26 + 5;
const int kNodeSize = 1200 + 5;
const int kHashSize = 10001; //大质数

struct Node{
    char word[kWordSize];
    Node *next;
};
Node node[kNodeSize + 1];
Node* head[kHashSize + 1];

class Hash{
public:
    Hash();
    unsigned int hash(const char* str);
    void insert(const char* str);
    bool find(const char* str);
private:
    unsigned int seed;
    unsigned int size;
};

Hash::Hash():seed(131),size(0){
    memset(head, 0, sizeof(head));
}

unsigned int Hash::hash(const char* str){
    unsigned int hash = 0;
    while(*str++)
        hash = hash * seed + (*str);
    return (hash & 0x7FFFFFFF) % kHashSize;
}

void Hash::insert(const char* str){
    unsigned int id = hash(str);
    char *dst = (char*)node[size].word;
    while(*dst++ = *str++);
    node[size].next = head[id];
    head[id] = &node[size];
    ++size;
}

bool Hash::find(const char* str){
    unsigned int id = hash(str);
    for(Node* p=head[id]; p ; p=p->next){
        char *dst = (char*)p->word;
        int i = 0;
        while(*(str+i) && *(dst+i)==*(str+i))
            ++i;
        if(*(str+i)=='\0' && *(dst+i)=='\0')
            return true;
    }
    return false;
}
