#ifndef DISCARDPILE_H
#define DISCARDPILE_H

#include <vector>
#include "Card.h"
using namespace std;

// La classe DiscardPile représente la pile au rebut, où les cartes sont temporairement placées.
class DiscardPile {
    vector<Card*> pile; // On stocke les cartes de la pile.

public:
    DiscardPile& operator+=(Card* card); // On ajoute une carte à la pile.
    Card* pickUp(); // On ramasse la carte au sommet de la pile.
    Card* top() const; // On retourne la carte au sommet sans la retirer.
    void print(ostream &out) const; // On affiche toutes les cartes de la pile.

    friend ostream& operator<<(ostream &out, const DiscardPile &pile); // On affiche la dernière carte.
};

#endif
