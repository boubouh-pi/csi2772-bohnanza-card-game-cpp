#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// On crée une classe abstraite Card qui sert de base pour représenter toutes les cartes du jeu.
// Cette classe contient des fonctions essentielles comme récupérer le nom d'une carte, 
// afficher un symbole qui la représente et calculer combien de cartes il faut pour gagner des pièces.
// Comme cette classe est abstraite, on ne peut pas créer directement d'objet de ce type.
class Card {
public:
    virtual int getCardsPerCoin(int coins) const = 0; // On détermine combien de cartes sont nécessaires pour obtenir un certain nombre de pièces.
    virtual string getName() const = 0; // On récupère le nom complet de la carte.
    virtual void print(ostream &out) const = 0; // On affiche un caractère représentant la carte.
    virtual ~Card() = default; // On utilise un destructeur virtuel pour permettre une gestion correcte des sous-classes.

    // On surcharge l'opérateur d'insertion pour faciliter l'affichage des cartes via un flux de sortie.
    friend ostream& operator<<(ostream &out, const Card &card) {
        card.print(out);
        return out;
    }
};

// On crée une classe Blue qui hérite de la classe Card.
// Cette classe représente une carte de type "Blue" (haricot bleu).
// Elle permet de connaître le nombre de cartes nécessaires pour obtenir des pièces,
// le nom de la carte ("Blue") et son symbole ("B").
class Blue : public Card {
public:
    int getCardsPerCoin(int coins) const override; // On implémente la logique pour calculer les pièces.
    string getName() const override; // On retourne "Blue" comme nom de la carte.
    void print(ostream &out) const override; // On affiche "B" comme symbole pour cette carte.
};

// On crée une classe Chili qui hérite de la classe Card.
// Cette classe représente une carte de type "Chili" (haricot chili).
// Elle permet de récupérer son nom ("Chili"), son symbole ("C") et le nombre de cartes nécessaires pour gagner des pièces.
class Chili : public Card {
public:
    int getCardsPerCoin(int coins) const override; // On calcule combien de cartes Chili donnent des pièces.
    string getName() const override; // On retourne "Chili" comme nom de la carte.
    void print(ostream &out) const override; // On affiche "C" comme symbole pour cette carte.
};

// On crée une classe Stink qui hérite de la classe Card.
// Cette classe représente une carte de type "Stink" (haricot puant).
// Elle permet d'obtenir son nom ("Stink"), son symbole ("S") et sa valeur en termes de pièces.
class Stink : public Card {
public:
    int getCardsPerCoin(int coins) const override; // On calcule le nombre de cartes nécessaires pour gagner des pièces.
    string getName() const override; // On retourne "Stink" comme nom de la carte.
    void print(ostream &out) const override; // On affiche "S" comme symbole pour cette carte.
};

// On crée une classe Green qui hérite de la classe Card.
// Cette classe représente une carte de type "Green" (haricot vert).
// Elle permet d'afficher son nom ("Green"), son symbole ("G") et le calcul pour les pièces.
class Green : public Card {
public:
    int getCardsPerCoin(int coins) const override; // On détermine combien de cartes Green sont nécessaires pour des pièces.
    string getName() const override; // On retourne "Green" comme nom de la carte.
    void print(ostream &out) const override; // On affiche "G" comme symbole pour cette carte.
};

// On crée une classe Soy qui hérite de la classe Card.
// Cette classe représente une carte de type "Soy" (haricot de soja).
// Elle fournit son nom ("Soy"), son symbole ("s") et la logique pour calculer le gain en pièces.
class Soy : public Card {
public:
    int getCardsPerCoin(int coins) const override; // On calcule combien de cartes Soy donnent des pièces.
    string getName() const override; // On retourne "Soy" comme nom de la carte.
    void print(ostream &out) const override; // On affiche "s" comme symbole pour cette carte.
};

// On crée une classe Black qui hérite de la classe Card.
// Cette classe représente une carte de type "Black" (haricot noir).
// Elle permet de connaître son nom ("Black"), son symbole ("b") et sa conversion en pièces.
class Black : public Card {
public:
    int getCardsPerCoin(int coins) const override; // On calcule le nombre de cartes Black nécessaires pour obtenir des pièces.
    string getName() const override; // On retourne "Black" comme nom de la carte.
    void print(ostream &out) const override; // On affiche "b" comme symbole pour cette carte.
};

// On crée une classe Red qui hérite de la classe Card.
// Cette classe représente une carte de type "Red" (haricot rouge).
// Elle fournit son nom ("Red"), son symbole ("R") et les règles pour obtenir des pièces.
class Red : public Card {
public:
    int getCardsPerCoin(int coins) const override; // On calcule le nombre de cartes Red nécessaires pour des pièces.
    string getName() const override; // On retourne "Red" comme nom de la carte.
    void print(ostream &out) const override; // On affiche "R" comme symbole pour cette carte.
};

// On crée une classe Garden qui hérite de la classe Card.
// Cette classe représente une carte de type "Garden" (haricot de jardin).
// Elle fournit les informations sur son nom ("Garden"), son symbole ("g") et son calcul de pièces.
class Garden : public Card {
public:
    int getCardsPerCoin(int coins) const override; // On détermine combien de cartes Garden donnent des pièces.
    string getName() const override; // On retourne "Garden" comme nom de la carte.
    void print(ostream &out) const override; // On affiche "g" comme symbole pour cette carte.
};

#endif
