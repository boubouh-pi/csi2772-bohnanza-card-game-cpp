#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <memory>
#include "Card.h"
#include "Hand.h"
#include "Chain.h"

class Player {
    std::string name; // Nom du joueur
    int coins = 0;    // Nombre de pièces
    int maxChains = 2; // Nombre maximum de chaînes
    std::vector<std::unique_ptr<Chain<Card>>> chains; // Liste des chaînes
    Hand hand; // Main du joueur

public:
    Player(const std::string& playerName); // Constructeur

    // Accesseurs
    std::string getName() const;
    int getNumCoins() const;
    int getMaxNumChains() const;
    int getNumChains() const;

    // Modificateurs
    Player& operator+=(int coins);
    void buyThirdChain();
    void addChain(Chain<Card>* newChain);
    void removeChain(int index);

    // Accès aux chaînes
    Chain<Card>& operator[](int index);

    // Accès à la main
    Hand& getHand();
    void printHand(std::ostream& out, bool allCards) const;

    // Opérateur d'insertion
    friend std::ostream& operator<<(std::ostream& out, const Player& player);
};

#endif
