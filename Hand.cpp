#include "Hand.h"

// On ajoute une carte à la main en la plaçant à la fin.
Hand& Hand::operator+=(Card* card) {
    hand.push_back(card);
    return *this;
}

// On joue la première carte de la main et on la retourne.
// Si la main est vide, on retourne nullptr.
Card* Hand::play() {
    if (hand.empty()) return nullptr;
    Card* topCard = hand.front(); // On récupère la première carte.
    hand.pop_front(); // On la retire de la main.
    return topCard;
}

// On retourne la première carte de la main sans la retirer.
// Si la main est vide, on retourne nullptr.
Card* Hand::top() const {
    return hand.empty() ? nullptr : hand.front();
}

// On accède à une carte spécifique dans la main par son index.
// La carte est retirée de la main après son accès.
Card* Hand::operator[](int index) {
    if (index < 0 || index >= static_cast<int>(hand.size())) {
        throw std::out_of_range("Index out of range.");
    }
    auto it = hand.begin();
    std::advance(it, index); // On se déplace jusqu'à l'index demandé.
    Card* selectedCard = *it;
    hand.erase(it); // On retire la carte de la main.
    return selectedCard;
}

// On vérifie si la main est vide.
bool Hand::empty() const {
    return hand.empty();
}

// On affiche toutes les cartes de la main.
void Hand::print(std::ostream& out) const {
    for (const auto& card : hand) {
        card->print(out);
    }
}

// On surcharge l'opérateur d'insertion pour afficher la main.
std::ostream& operator<<(std::ostream& out, const Hand& hand) {
    hand.print(out);
    return out;
}
