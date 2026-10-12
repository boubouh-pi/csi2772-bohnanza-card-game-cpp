#include "Table.h"

// Constructeur: on initialise la table avec deux joueurs et leurs noms respectifs.
Table::Table(const std::string& player1Name, const std::string& player2Name)
    : player1(player1Name), player2(player2Name) {}

// Méthode pour vérifier si un joueur a gagné.
bool Table::win(std::string& winnerName) {
    if (deck.empty()) {
        // On compare le nombre de pièces des deux joueurs.
        if (player1.getNumCoins() > player2.getNumCoins()) {
            winnerName = player1.getName();
        } else if (player2.getNumCoins() > player1.getNumCoins()) {
            winnerName = player2.getName();
        } else {
            winnerName = "Draw"; // Cas d'égalité.
        }
        return true;
    }
    return false;
}

// Méthode pour afficher les mains des joueurs.
void Table::printHand(bool allCards) const {
    std::cout << "Player 1: ";
    player1.printHand(std::cout, allCards);
    std::cout << "\nPlayer 2: ";
    player2.printHand(std::cout, allCards);
    std::cout << "\n";
}

// Opérateur d'insertion: on affiche l'état de la table.
std::ostream& operator<<(std::ostream& out, const Table& table) {
    out << "===== Table State =====\n"
        << "Player 1: " << table.player1 << "\n"
        << "Player 2: " << table.player2 << "\n"
        << "Trade Area:\n";
    table.tradeArea.print(out);
    out << "\nDiscard Pile:\n";
    table.discardPile.print(out);
    out << "=======================\n";
    return out;
}

// Accesseurs pour les composants de la table.
Player& Table::getPlayer1() { return player1; }
Player& Table::getPlayer2() { return player2; }
Deck& Table::getDeck() { return deck; }
DiscardPile& Table::getDiscardPile() { return discardPile; }
TradeArea& Table::getTradeArea() { return tradeArea; }
