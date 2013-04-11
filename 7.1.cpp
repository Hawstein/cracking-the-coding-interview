#include <iostream>
#include "7.1.h"
using namespace std;

int main(){
    Deck deck;
    deck.shuffle();
    vector<Card> vc = deck.deal_hand(5);
    cout<<deck.remain_cards()<<endl;
    for(int i=0; i<vc.size(); ++i)
        cout<<vc[i].value()<<" "<<(Suit)vc[i].suit()<<endl;
    return 0;
}
