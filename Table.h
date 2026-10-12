#ifndef TABLE_H
#define TABLE_H

#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"
#include <iostream>
#include <string>

class Table {
    Player player1, player2; // Les deux joueurs.
    Deck deck; // Le deck principal.
    DiscardPile discardPile; // La pile au rebut.
    TradeArea tradeArea; // La zone d'échange.

public:
    Table(const std::string& player1Name, const std::string& player2Name); // Constructeur.
    bool win(std::string& winnerName); // Méthode pour vérifier le gagnant.
    void printHand(bool allCards) const; // Afficher les mains des joueurs.
    friend std::ostream& operator<<(std::ostream& out, const Table& table); // Opérateur d'insertion.

    // Accesseurs pour les joueurs, le deck, la pile au rebut et la TradeArea.
    Player& getPlayer1();
    Player& getPlayer2();
    Deck& getDeck();
    DiscardPile& getDiscardPile();
    TradeArea& getTradeArea();
};

#endif
