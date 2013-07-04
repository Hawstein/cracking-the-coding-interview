#include <iostream>
#include <cstring>
using namespace std;

struct Result{
    int hits;
    int pseudo_hits;
};

Result Estimate(const char* solution, const char* guess){
    Result res;
    res.hits = 0;
    res.pseudo_hits = 0;
    int solution_mask = 0;
    for(int i=0; i<4; ++i){
        solution_mask |= 1 << (solution[i] - 'A');
    }
    for(int i=0; i<4; ++i){
        if(guess[i] == solution[i])
            ++res.hits;
        else if(solution_mask & ( 1<<(guess[i] - 'A')))
            ++res.pseudo_hits;
    }
    return res;
}

int Min(int a, int b){
    return a < b ? a : b;
}
Result Estimate1(const char* solution, const char* guess){
    Result res;
    res.hits = 0;
    res.pseudo_hits = 0;
    int num = 26 + 5;
    int guess_count[num], solution_count[num];
    memset(guess_count, 0, sizeof(guess_count));
    memset(solution_count, 0, sizeof(solution_count));
    for(int i=0; i<4; ++i){
        if(guess[i] == solution[i])
            ++res.hits;
        ++guess_count[(int)(guess[i]-'A')];
        ++solution_count[(int)(solution[i]-'A')];
    }
    char color[] = "RGBY";
    for(int i=0; i<4; ++i){
        int idx = (int)(color[i] - 'A');
        res.pseudo_hits += Min(guess_count[idx], solution_count[idx]);
    }
    res.pseudo_hits -= res.hits;
    return res;
}
int main(){
    char solution[] = "RYGB";
    char guess[] = "YRRR";
    Result res = Estimate(solution, guess);
    cout<<res.hits<<" "<<res.pseudo_hits<<endl;
    Result res1 = Estimate1(solution, guess);
    cout<<res1.hits<<" "<<res1.pseudo_hits<<endl;
    return 0;
}
