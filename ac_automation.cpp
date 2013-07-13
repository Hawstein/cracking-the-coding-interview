#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

class ACAutomation{
public:
    static const int MAX_N = 1000 * 50;
    static const int CLD_NUM = 26;

    int size;
    int fail[MAX_N];
    int tag[MAX_N];
    int trie[MAX_N][CLD_NUM];

    void reset();
    void insert(const char* s);
    void construct();
    int query(const char* s);
};

void ACAutomation::reset(){
    memset(trie[0], -1, sizeof(trie[0]));
    tag[0] = 0;
    size = 1;
}

void ACAutomation::insert(const char* s){
    int p = 0;
    while(*s){
        int i = *s - 'a';
        if(-1 == trie[p][i]){
            memset(trie[size], -1, sizeof(trie[size]));
            tag[size] = 0;
            trie[p][i] = size++;
        }
        p = trie[p][i];
        ++s;
    }
    ++tag[p];
}

void ACAutomation::construct(){
    queue<int> q;
    fail[0] = 0;
    for(int i=0; i<CLD_NUM; ++i){
        if(-1 != trie[0][i]){
            fail[trie[0][i]] = 0;
            q.push(trie[0][i]);
        }
        else
            trie[0][i] = 0;
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0; i<CLD_NUM; ++i){
            int &v = trie[u][i];
            if(-1 != v){
                q.push(v);
                fail[v] = trie[fail[u]][i];
                //tag[u] += tag[fail[u]];
            }
            else
                v = trie[fail[u]][i];
        }
    }
}

//返回匹配的模式串个数
int ACAutomation::query(const char* s){
    int p = 0, cnt = 0;
    while(*s){
        int i = *s - 'a';
        while(-1==trie[p][i] && p!=0)//无法匹配当前字符，回退到其fail指针
            p = fail[p];
        p = trie[p][i];
        p = p==-1 ? 0 : p;
        int t = p;
        while(t!=0 && tag[t]!=-1){
            cnt += tag[t];
            tag[t] = -1;
            t = fail[t];//跳到当前字符的最大后缀，统计模式串出现个数
        }
        ++s;
    }
    return cnt;
}

int main(){
    ACAutomation ac;
    ac.reset();
    string patt[] = {
        "is", "sip", "is", "sis", "mississipp"
    };
    int n = 5;
    for(int i=0; i<n; ++i)
        ac.insert((char*)&patt[i][0]);
    ac.construct();
    cout<<ac.query("mississippi")<<endl;
    return 0;
}
