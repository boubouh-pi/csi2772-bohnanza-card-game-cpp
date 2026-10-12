#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include <vector>
#include <memory>
#include <random>
#include <algorithm>
#include "Card.h"
#include "Deck.h"

// On utilise la classe CardFactory pour gérer la création et la gestion des cartes du jeu.
// Cette classe suit le modèle Singleton, donc une seule instance existera dans tout le programme.
class CardFactory {
    static std::unique_ptr<CardFactory> instance; // Instance unique de la fabrique.
    std::vector<Card*> cards; // Stockage de toutes les cartes.

    CardFactory(); // Constructeur privé pour empêcher l'instanciation directe.

public:
    // On fournit un accès à l'instance unique de la fabrique.
    static CardFactory* getFactory();

    // On génère un deck contenant toutes les cartes mélangées.
    Deck getDeck();

    // Destructeur pour libérer la mémoire des cartes créées.
    ~CardFactory();
};

#endif
