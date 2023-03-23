#include <stdio.h>
#include "GameEngine.h"
#include "Map.h"
#include "Player.h"
#include "Orders.h"
#include "Cards.h"
int main(){

    Deck* deck = new Deck();
    for(int i = 0; i < 50; i++){
        cout << deck->draw()->getType()<< endl;
    }

}