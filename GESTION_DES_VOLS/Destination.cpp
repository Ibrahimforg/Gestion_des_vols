#include "Destination.h"
#include <iostream>
#include <limits>

// === Constructeurs ===

Destination::Destination() 
    : villeDepart("Inconnue"), villeArrivee("Inconnue") {}

Destination::Destination(const std::string& depart, const std::string& arrivee)
    : villeDepart(depart), villeArrivee(arrivee) {}


// === Saisie utilisateur ===

void Destination::saisir() {


    std::cout << "Ville de départ   : ";
    std::getline(std::cin >> std::ws, villeDepart);
    while (villeDepart.empty()) {
        std::cout << "Champ requis. Réessayez : ";
        std::getline(std::cin >> std::ws, villeDepart);
    }

    std::cout << "Ville d'arrivée   : ";
    std::getline(std::cin >> std::ws, villeArrivee);
    while (villeArrivee.empty()) {
        std::cout << "Champ requis. Réessayez : ";
        std::getline(std::cin >> std::ws, villeArrivee);
    }
}


// === Affichage de la destination ===

void Destination::afficher() const {
    std::cout << villeDepart << " -> " << villeArrivee;
}


// === Méthodes utilitaires ===

std::string Destination::toString() const {
    return villeDepart + ";" + villeArrivee;
}

std::string Destination::getDepart() const {
    return villeDepart;
}

std::string Destination::getArrivee() const {
    return villeArrivee;
}
