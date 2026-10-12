#include "Deck.h"

// On tire une carte du dessus du deck et on la retourne.
// Si le deck est vide, on retourne nullptr.
Card* Deck::draw() {
    if (empty()) return nullptr;
    Card* topCard = back(); // On récupère la carte au sommet.
    pop_back(); // On la retire du deck.
    return topCard;
}

// On surcharge l'opérateur d'insertion pour afficher toutes les cartes du deck.
// Chaque carte est affichée en utilisant sa méthode print().
ostream& operator<<(ostream &out, const Deck &deck) {
    for (const auto &card : deck) card->print(out); // On affiche chaque carte.
    return out;
}
