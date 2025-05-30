#include "Vol.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

// === Constructeurs ===

Vol::Vol()
    : numeroVol("UNKNOWN"), nbPlacesMax(0), nbPlacesReservees(0), prix(0.0f),
      dateDepart(), dateArrivee(), destination() {}

Vol::Vol(const std::string& numero, int maxPlaces, float prix,
         const Date& depart, const Date& arrivee, const Destination& dest)
    : numeroVol(numero), nbPlacesMax(maxPlaces), nbPlacesReservees(0), prix(prix),
      dateDepart(depart), dateArrivee(arrivee), destination(dest) {}


// === Réservation / Passagers ===

bool Vol::estComplet() const {
    return nbPlacesReservees >= nbPlacesMax;
}

bool Vol::ajouterPassager(const Passager& p) {
    if (estComplet()) {
        std::cout << "Le vol est complet. Impossible d'ajouter un passager.\n";
        return false;
    }
    if (contientPassager(p.getPasseport())) {
        std::cout << "Ce passager est déjà enregistré sur ce vol.\n";
        return false;
    }

    passagers.push_back(p);
    nbPlacesReservees++;
    return true;
}

bool Vol::contientPassager(const std::string& passeport) const {
    for (const auto& p : passagers) {
        if (p.getPasseport() == passeport)
            return true;
    }
    return false;
}


// === Affichage du vol ===

void Vol::afficher() const {
    std::cout << "\n--------------------------------------------------\n";
    std::cout << "VOL N°           : " << numeroVol << "\n";
    std::cout << "DESTINATION      : "; destination.afficher(); std::cout << "\n";
    std::cout << "DÉPART           : "; dateDepart.afficher(); std::cout << "\n";
    std::cout << "ARRIVÉE          : "; dateArrivee.afficher(); std::cout << "\n";
    std::cout << "PLACES RÉSERVÉES : " << nbPlacesReservees << " / " << nbPlacesMax << "\n";
    std::cout << "PRIX PAR PLACE   : " << std::fixed << std::setprecision(2) << prix << " FCFA\n";
    std::cout << "--------------------------------------------------\n";
}


// === Affichage professionnel des passagers ===

void Vol::afficherPassagers() const {
    std::cout << "\n╔═════════════════════════════════════════════════════════════════╗\n";
    std::cout << "║            PASSAGERS ENREGISTRÉS POUR LE VOL " << std::setw(6) <<  numeroVol << "             ║\n";
    std::cout << "╠════╦═══════╦════════════════╦════════════════╦═════╦════════════║\n";
    std::cout << "║ N° ║ Titre ║      Nom       ║    Prénom      ║ Âge ║ Passeport  ║\n";
    std::cout << "╠════╬═══════╬════════════════╬════════════════╬═════╬════════════╣\n";

    if (passagers.empty()) {
        std::cout << "║                       Aucun passager enregistré sur ce vol                      ║\n";
    } else {
        for (size_t i = 0; i < passagers.size(); ++i) {
            const Passager& p = passagers[i];
            std::cout << "║ "
                      << std::setw(2) << i + 1 << " ║ "
                      << std::setw(5) << p.getTitre() << " ║ "
                      << std::setw(14) << p.getNom() << " ║ "
                      << std::setw(14) << p.getPrenom() << " ║ "
                      << std::setw(3) << p.getAge() << " ║ "
                      << std::setw(10) << p.getPasseport() << " ║\n";
        }
    }

    std::cout << "╚════╩═══════╩════════════════╩════════════════╩═════╩════════════╝\n";
}


// === Modifications ===

void Vol::modifierDate(const Date& nouvelleDate) {
    dateDepart = nouvelleDate;
}

void Vol::modifierHeure(int heure, int minute) {
    dateDepart.setHeure(heure);
    dateDepart.setMinute(minute);
}


// === Accesseurs / utilitaires ===

std::string Vol::getNumeroVol() const {
    return numeroVol;
}

int Vol::getNbPlacesDispo() const {
    return nbPlacesMax - nbPlacesReservees;
}


// === Sérialisation ===

std::string Vol::toString() const {
    return numeroVol + ";" +
           std::to_string(nbPlacesMax) + ";" +
           std::to_string(nbPlacesReservees) + ";" +
           std::to_string(prix);
}
