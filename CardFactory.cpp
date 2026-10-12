#include "CardFactory.h"

// On initialise la fabrique de cartes en créant toutes les cartes nécessaires pour le jeu.
// Les cartes sont ajoutées en fonction de leur quantité respective et mélangées pour un ordre aléatoire.
CardFactory::CardFactory() {
    for (int i = 0; i < 20; ++i) cards.push_back(new Blue());
    for (int i = 0; i < 18; ++i) cards.push_back(new Chili());
    for (int i = 0; i < 16; ++i) cards.push_back(new Stink());
    for (int i = 0; i < 14; ++i) cards.push_back(new Green());
    for (int i = 0; i < 12; ++i) cards.push_back(new Soy());
    for (int i = 0; i < 10; ++i) cards.push_back(new Black());
    for (int i = 0; i < 8; ++i) cards.push_back(new Red());
    for (int i = 0; i < 6; ++i) cards.push_back(new Garden());

    // On mélange les cartes pour assurer un ordre aléatoire.
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(std::random_device()()));
}

// On retourne l'instance unique de la fabrique. Si elle n'existe pas encore, on la crée.
CardFactory* CardFactory::getFactory() {
    if (!instance) instance.reset(new CardFactory());
   

    return instance.get();
}
std::unique_ptr<CardFactory> CardFactory::instance = nullptr;

// On génère un deck à partir des cartes disponibles dans la fabrique.
// Le deck contiendra toutes les cartes dans leur ordre mélangé.
Deck CardFactory::getDeck() {
    Deck deck;
    for (auto card : cards) deck.push_back(card);
    return deck;
}

// Destructeur: on libère la mémoire allouée pour chaque carte.
CardFactory::~CardFactory() {
    for (auto card : cards) delete card;
}

