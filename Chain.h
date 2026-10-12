#ifndef CHAIN_H
#define CHAIN_H

#include <vector>
#include "Card.h"
#include <stdexcept>
#include <iostream>

// Classe template pour gérer une chaîne de cartes du même type.
template <typename T>
class Chain {
    std::vector<T*> cards; // Stocke les cartes de la chaîne.

public:
    Chain& operator+=(Card* card) { // Ajoute une carte à la chaîne.
        if (dynamic_cast<T*>(card) == nullptr) throw std::runtime_error("IllegalType");
        cards.push_back(static_cast<T*>(card));
        return *this;
    }

    int sell() const { // Calcule les pièces gagnées.
        try {
            if (cards.empty()) return 0;
            return cards.size() / cards.front()->getCardsPerCoin(1);
        } catch (std::invalid_argument& e) {
            std::cerr << "Error during chain selling: " << e.what() << "\n";
            return 0;
        }
    }

    T* getTopCard() const { // Retourne la première carte.
        if (cards.empty()) return nullptr;
        return cards.front();
    }

    void print(std::ostream& out) const { // Affiche la chaîne.
        if (!cards.empty()) {
            out << cards.front()->getName() << " ";
            for (const auto& card : cards) {
                card->print(out);
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const Chain& chain) { // Surcharge pour afficher.
        chain.print(out);
        return out;
    }
};

#endif
