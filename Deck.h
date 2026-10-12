#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"
using namespace std;

// La classe Deck représente un paquet de cartes, hérité de std::vector.
// Elle permet de gérer les cartes restantes dans le jeu.
class Deck : public vector<Card*> {
public:
    Card* draw(); // On tire la carte du dessus du deck.
    friend ostream& operator<<(ostream &out, const Deck &deck); // On affiche toutes les cartes du deck.
};

#endif
