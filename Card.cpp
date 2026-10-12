#include "Card.h"

// Implémentation de la classe Blue
int Blue::getCardsPerCoin(int coins) const {
    // On retourne le nombre de cartes nécessaires pour obtenir le nombre de pièces spécifié.
    if (coins == 1) return 4;
    if (coins == 2) return 6;
    if (coins == 3) return 8;
    if (coins == 4) return 10;
    throw invalid_argument("Invalid number of coins."); // On gère les cas invalides.
}

// On retourne le nom de la carte Blue.
string Blue::getName() const { return "Blue"; }

// On affiche le caractère associé à la carte Blue.
void Blue::print(ostream &out) const { out << "B"; }

// Implémentation de la classe Chili
int Chili::getCardsPerCoin(int coins) const {
    // On retourne le nombre de cartes nécessaires pour obtenir le nombre de pièces spécifié.
    if (coins == 1) return 3;
    if (coins == 2) return 6;
    if (coins == 3) return 8;
    if (coins == 4) return 9;
    throw invalid_argument("Invalid number of coins.");
}

string Chili::getName() const { return "Chili"; }
void Chili::print(ostream &out) const { out << "C"; }

// Implémentation de la classe Stink
int Stink::getCardsPerCoin(int coins) const {
    // On retourne le nombre de cartes nécessaires pour obtenir le nombre de pièces spécifié.
    if (coins == 1) return 3;
    if (coins == 2) return 5;
    if (coins == 3) return 7;
    if (coins == 4) return 8;
    throw invalid_argument("Invalid number of coins.");
}

string Stink::getName() const { return "Stink"; }
void Stink::print(ostream &out) const { out << "S"; }

// Implémentation de la classe Green
int Green::getCardsPerCoin(int coins) const {
    // On retourne le nombre de cartes nécessaires pour obtenir le nombre de pièces spécifié.
    if (coins == 1) return 3;
    if (coins == 2) return 5;
    if (coins == 3) return 6;
    if (coins == 4) return 7;
    throw invalid_argument("Invalid number of coins.");
}

string Green::getName() const { return "Green"; }
void Green::print(ostream &out) const { out << "G"; }

// Implémentation de la classe Soy
int Soy::getCardsPerCoin(int coins) const {
    // On retourne le nombre de cartes nécessaires pour obtenir le nombre de pièces spécifié.
    if (coins == 1) return 2;
    if (coins == 2) return 4;
    if (coins == 3) return 6;
    if (coins == 4) return 7;
    throw invalid_argument("Invalid number of coins.");
}

string Soy::getName() const { return "Soy"; }
void Soy::print(ostream &out) const { out << "s"; }

// Implémentation de la classe Black
int Black::getCardsPerCoin(int coins) const {
    // On retourne le nombre de cartes nécessaires pour obtenir le nombre de pièces spécifié.
    if (coins == 1) return 2;
    if (coins == 2) return 4;
    if (coins == 3) return 5;
    if (coins == 4) return 6;
    throw invalid_argument("Invalid number of coins.");
}

string Black::getName() const { return "Black"; }
void Black::print(ostream &out) const { out << "b"; }

// Implémentation de la classe Red
int Red::getCardsPerCoin(int coins) const {
    // On retourne le nombre de cartes nécessaires pour obtenir le nombre de pièces spécifié.
    if (coins == 1) return 2;
    if (coins == 2) return 3;
    if (coins == 3) return 4;
    if (coins == 4) return 5;
    throw invalid_argument("Invalid number of coins.");
}

string Red::getName() const { return "Red"; }
void Red::print(ostream &out) const { out << "R"; }

// Implémentation de la classe Garden
int Garden::getCardsPerCoin(int coins) const {
    // On retourne le nombre de cartes nécessaires pour obtenir le nombre de pièces spécifié.
    if (coins == 2) return 2;
    if (coins == 3) return 3;
    throw invalid_argument("Invalid number of coins.");
}

string Garden::getName() const { return "Garden"; }
void Garden::print(ostream &out) const { out << "g"; }
