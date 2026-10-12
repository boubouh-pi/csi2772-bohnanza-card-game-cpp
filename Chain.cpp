#include "Chain.h"

// On ajoute une carte à la chaîne après avoir vérifié que son type correspond.
// Si le type ne correspond pas, on lance une exception.
template <typename T>
Chain<T>& Chain<T>::operator+=(Card* card) {
    if (dynamic_cast<T*>(card) == nullptr) throw std::runtime_error("IllegalType");
    cards.push_back(static_cast<T*>(card));
    return *this;
}

// On calcule combien de pièces peuvent être gagnées en vendant les cartes de la chaîne.
// Cela dépend du nombre de cartes et des règles associées au type de carte.
template <typename T>
int Chain<T>::sell() const {
    if (cards.empty()) return 0; // On ne gagne rien si la chaîne est vide.
    return cards.size() / cards.front()->getCardsPerCoin(1);
}

// On retourne la première carte de la chaîne, ou nullptr si la chaîne est vide.
template <typename T>
T* Chain<T>::getTopCard() const {
    return cards.empty() ? nullptr : cards.front();
}

// On affiche toutes les cartes de la chaîne en commençant par leur nom.
template <typename T>
void Chain<T>::print(std::ostream& out) const {
    if (!cards.empty()) {
        out << cards.front()->getName() << " "; // On affiche le nom de la chaîne.
        for (const auto& card : cards) {
            card->print(out); // On affiche chaque carte.
        }
    }
}
