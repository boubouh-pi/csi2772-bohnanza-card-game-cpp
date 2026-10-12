#include "Player.h"
#include <iostream>
#include <stdexcept>

// Constructeur: on initialise un joueur avec un nom donné.
Player::Player(const std::string& playerName) : name(playerName) {}

// Accesseurs
std::string Player::getName() const {
    // On retourne le nom du joueur.
    return name;
}

int Player::getNumCoins() const {
    // On retourne le nombre de pièces du joueur.
    return coins;
}

int Player::getMaxNumChains() const {
    // On retourne le nombre maximum de chaînes que le joueur peut posséder.
    return maxChains;
}

int Player::getNumChains() const {
    // On retourne le nombre de chaînes actuelles du joueur.
    return chains.size();
}

// Modificateurs
Player& Player::operator+=(int amount) {
    // On ajoute un certain nombre de pièces au joueur.
    coins += amount;
    return *this;
}

void Player::buyThirdChain() {
    // On vérifie si le joueur a suffisamment de pièces pour acheter une troisième chaîne.
    if (coins < 3) {
        throw std::runtime_error("Not enough coins to buy a third chain.");
    }
    coins -= 3;
    maxChains = 3;
}

void Player::addChain(Chain<Card>* newChain) {
    // On ajoute une nouvelle chaîne au joueur si le maximum n'est pas atteint.
    if (chains.size() >= static_cast<size_t>(maxChains)) {
        throw std::runtime_error("Maximum number of chains reached.");
    }
    chains.emplace_back(newChain);
}

void Player::removeChain(int index) {
    // On supprime une chaîne à l'index spécifié, après avoir vérifié sa validité.
    if (index < 0 || index >= static_cast<int>(chains.size())) {
        throw std::out_of_range("Invalid chain index.");
    }
    chains.erase(chains.begin() + index);
}

// Accès aux chaînes
Chain<Card>& Player::operator[](int index) {
    // On retourne une référence à la chaîne située à l'index donné.
    if (index < 0 || index >= static_cast<int>(chains.size())) {
        throw std::out_of_range("Invalid chain index.");
    }
    return *chains[index];
}

// Accès à la main
Hand& Player::getHand() {
    // On retourne une référence à la main du joueur.
    return hand;
}

void Player::printHand(std::ostream& out, bool allCards) const {
    // On affiche la main du joueur, partiellement ou totalement selon le paramètre.
    if (allCards) {
        hand.print(out);
    } else if (hand.top() != nullptr) {
        hand.top()->print(out);
    }
}

// Opérateur d'insertion: on affiche les informations du joueur.
std::ostream& operator<<(std::ostream& out, const Player& player) {
    out << player.name << " " << player.coins << " coins\n";
    for (const auto& chain : player.chains) {
        if (chain) {
            out << *chain << "\n";
        }
    }
    return out;
}
