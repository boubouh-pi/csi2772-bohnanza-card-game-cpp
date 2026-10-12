#ifndef TRADEAREA_H
#define TRADEAREA_H

#include <list>
#include "Card.h"
using namespace std;

class TradeArea {
    list<Card*> cards; // Liste de cartes dans la TradeArea.

public:
    TradeArea& operator+=(Card* card); // Ajouter une carte à la TradeArea.
    bool legal(Card* card) const; // Vérifier la légalité d'une carte.
    Card* trade(const string& beanName); // Échanger une carte spécifique.
    int numCards() const; // Retourner le nombre de cartes.
    void print(ostream& out) const; // Afficher les cartes.
    friend ostream& operator<<(ostream& out, const TradeArea& tradeArea); // Opérateur d'insertion.
};

#endif
