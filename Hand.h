#ifndef HAND_H
#define HAND_H

#include <list>
#include "Card.h"
#include <iostream>
#include <stdexcept>

// La classe Hand représente la main d'un joueur et gère les cartes qu'il possède.
class Hand {
    std::list<Card*> hand; // On stocke les cartes de la main dans une liste.

public:
    Hand& operator+=(Card* card); // On ajoute une carte à la main.
    Card* play(); // On joue la première carte de la main.
    Card* top() const; // On retourne la première carte sans la retirer.
    Card* operator[](int index); // On accède à une carte par son index et on la retire.
    bool empty() const; // On vérifie si la main est vide.
    void print(std::ostream& out) const; // On affiche toutes les cartes de la main.

    friend std::ostream& operator<<(std::ostream& out, const Hand& hand); // On surcharge l'opérateur pour afficher la main.
};

#endif
