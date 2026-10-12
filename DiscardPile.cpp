#include "DiscardPile.h"

// On ajoute une carte à la pile au rebut.
DiscardPile& DiscardPile::operator+=(Card* card) {
    pile.push_back(card); // On insère la carte à la fin de la pile.
    return *this;
}

// On ramasse la carte située au sommet de la pile et on la retourne.
// Si la pile est vide, on retourne nullptr.
Card* DiscardPile::pickUp() {
    if (pile.empty()) return nullptr;
    Card* topCard = pile.back(); // On récupère la dernière carte.
    pile.pop_back(); // On la retire de la pile.
    return topCard;
}

// On retourne la carte au sommet de la pile sans la retirer.
// Si la pile est vide, on retourne nullptr.
Card* DiscardPile::top() const {
    return pile.empty() ? nullptr : pile.back();
}

// On affiche toutes les cartes de la pile, de la première à la dernière.
void DiscardPile::print(ostream &out) const {
    for (const auto &card : pile) card->print(out);
}

// On surcharge l'opérateur d'insertion pour afficher uniquement la dernière carte de la pile.
ostream& operator<<(ostream &out, const DiscardPile &pile) {
    if (!pile.pile.empty()) pile.pile.back()->print(out);
    return out;
}
