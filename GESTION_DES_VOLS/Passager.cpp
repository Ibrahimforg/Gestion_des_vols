#include "Passager.h"
#include <iostream>
#include <limits>
#include <algorithm> // pour std::transform
#include <iomanip>   // pour setw, left

// === Constructeurs ===

Passager::Passager()
    : nom("Inconnu"), prenom("Inconnu"), titre("M"),
      numeroPasseport("000000"), age(0) {}

Passager::Passager(const std::string& nom, const std::string& prenom, const std::string& titre,
                   const std::string& numeroPasseport, int age)
    : nom(nom), prenom(prenom), titre(titre),
      numeroPasseport(numeroPasseport), age(age) {}


// === Saisie utilisateur avec validation ===

void Passager::saisir() {
    // Titre
    std::cout << "Titre (M / Mme / Mlle) : ";
    std::getline(std::cin >> std::ws, titre);
    std::transform(titre.begin(), titre.end(), titre.begin(), ::tolower);
    titre[0] = std::toupper(titre[0]);

    while (titre != "M" && titre != "Mme" && titre != "Mlle") {
        std::cout << "Titre invalide. Choisissez parmi : M, Mme, Mlle\nRéessayez : ";
        std::getline(std::cin >> std::ws, titre);
        std::transform(titre.begin(), titre.end(), titre.begin(), ::tolower);
        titre[0] = std::toupper(titre[0]);
    }

    // Nom
    std::cout << "Nom : ";
    std::getline(std::cin >> std::ws, nom);
    while (nom.empty()) {
        std::cout << "Nom requis. Réessayez : ";
        std::getline(std::cin >> std::ws, nom);
    }

    // Prénom
    std::cout << "Prénom : ";
    std::getline(std::cin >> std::ws, prenom);
    while (prenom.empty()) {
        std::cout << "Prénom requis. Réessayez : ";
        std::getline(std::cin >> std::ws, prenom);
    }

    // Âge
    std::cout << "Âge : ";
    std::cin >> age;
    while (std::cin.fail() || age <= 0 || age > 120) {
        std::cout << "Âge invalide. Réessayez : ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> age;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Passeport
    std::cout << "Numéro de passeport : ";
    std::getline(std::cin >> std::ws, numeroPasseport);
    while (numeroPasseport.empty()) {
        std::cout << "Champ requis. Réessayez : ";
        std::getline(std::cin >> std::ws, numeroPasseport);
    }
}


// === Affichage formaté (aligné) ===

void Passager::afficher() const {
    std::cout << std::left
              << std::setw(6)  << titre
              << std::setw(15) << nom
              << std::setw(15) << prenom
              << std::setw(5)  << age
              << "Passeport : " << numeroPasseport << "\n";
}


// === Accesseurs utiles ===

std::string Passager::getPasseport() const {
    return numeroPasseport;
}

std::string Passager::getNomComplet() const {
    return titre + " " + nom + " " + prenom;
}

std::string Passager::getNom() const {
    return nom;
}

std::string Passager::getPrenom() const {
    return prenom;
}

std::string Passager::getTitre() const {
    return titre;
}

int Passager::getAge() const {
    return age;
}


// === Export fichier ===

std::string Passager::toString() const {
    return titre + ";" + nom + ";" + prenom + ";" +
           std::to_string(age) + ";" + numeroPasseport;
}
