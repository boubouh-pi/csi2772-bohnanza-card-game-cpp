#include "TradeArea.h"
#include <algorithm>

// Opérateur += : on ajoute une carte à la TradeArea.
TradeArea& TradeArea::operator+=(Card* card) {
    cards.push_back(card);
    return *this;
}

// Méthode pour vérifier si une carte peut être ajoutée légalement.
bool TradeArea::legal(Card* card) const {
    return std::any_of(cards.begin(), cards.end(), [card](Card* c) {
        return c->getName() == card->getName();
    });
}

// Méthode pour échanger une carte spécifique basée sur son nom.
Card* TradeArea::trade(const std::string& beanName) {
    for (auto it = cards.begin(); it != cards.end(); ++it) {
        if ((*it)->getName() == beanName) {
            Card* card = *it;
            cards.erase(it);
            return card;
        }
    }
    return nullptr; // Retourne nullptr si aucune carte ne correspond.
}

// Retourne le nombre de cartes dans la TradeArea.
int TradeArea::numCards() const { return cards.size(); }

// Méthode pour afficher les cartes de la TradeArea.
void TradeArea::print(std::ostream& out) const {
    for (const auto& card : cards) card->print(out);
}

// Opérateur d'insertion: on affiche toutes les cartes de la TradeArea.
std::ostream& operator<<(std::ostream& out, const TradeArea& tradeArea) {
    tradeArea.print(out);
    return out;
}
