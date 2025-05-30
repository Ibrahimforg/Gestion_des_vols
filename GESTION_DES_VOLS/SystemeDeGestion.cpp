#include "SystemeDeGestion.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>

SystemeDeGestion::SystemeDeGestion() {}

// ==== AJOUT DE VOL ====

void SystemeDeGestion::ajouterVol() {
    std::string numero;
    int maxPlaces;
    float prix;
    Date depart, arrivee;
    Destination dest;

    std::cout << "\n╔══════════════════════════════════════╗\n";
    std::cout <<   "║         AJOUT D’UN NOUVEAU VOL       ║\n";
    std::cout <<   "╚══════════════════════════════════════╝\n";

    std::cout << "Numéro du vol            : ";
    std::getline(std::cin >> std::ws, numero);

    std::cout << "Nombre de places max     : ";
    std::cin >> maxPlaces;

    std::cout << "Prix par place (FCFA)    : ";
    std::cin >> prix;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "\n--- DATE DE DEPART ---\n";
    depart.saisir();

    std::cout << "\n---- DATE D'ARRIVEE ----\n";
    arrivee.saisir();

    std::cout << "\n---- DESTINATION ----\n";
    dest.saisir();

    if (depart.estDansLePasse()) {
        std::cout << "Erreur : la date de départ est dans le passé. Vol non ajouté.\n";
        return;
    }

    Vol vol(numero, maxPlaces, prix, depart, arrivee, dest);
    vols.push_back(vol);
    std::cout << "Vol ajouté avec succès ✅.\n";
}

// ==== AFFICHAGE DES VOLS ====

void SystemeDeGestion::afficherVols() const {
    std::cout << "\n╔══════════════════════════════════════╗\n";
    std::cout <<   "║           LISTE DES VOLS             ║\n";
    std::cout <<   "╚══════════════════════════════════════╝\n";

    if (vols.empty()) {
        std::cout << "Aucun vol enregistré.\n";
    } else {
        for (const auto& v : vols)
            v.afficher();
    }
}

// ==== ANNULATION ====

void SystemeDeGestion::annulerVol(const std::string& numeroVol) {
    int index = rechercherVol(numeroVol);
    if (index != -1) {
        vols.erase(vols.begin() + index);
        std::cout << "Vol annulé avec succès ✅.\n";
    } else {
        std::cout << "Vol introuvable.\n";
    }
}

// ==== MODIFICATION ====

void SystemeDeGestion::modifierVol(const std::string& numeroVol) {
    std::cout << "\n╔══════════════════════════════════════╗\n";
    std::cout <<   "║     MODIFICATION D’UN VOL EXISTANT   ║\n";
    std::cout <<   "╚══════════════════════════════════════╝\n";

    int index = rechercherVol(numeroVol);
    if (index != -1) {
        std::cout << "Nouvelle date de départ! \n";
        Date nouvelleDate;
        nouvelleDate.saisir();
        vols[index].modifierDate(nouvelleDate);
        std::cout << "Date du vol modifiée avec succès ✅.\n";
    } else {
        std::cout << "Vol introuvable.\n";
    }
}

// ==== RÉSERVATION ====

void SystemeDeGestion::reserverVol() {
    std::string numero;
    std::cout << "\n╔══════════════════════════════════════╗\n";
    std::cout <<   "║        RÉSERVATION D’UN VOL          ║\n";
    std::cout <<   "╚══════════════════════════════════════╝\n";

    std::cout << "Numéro du vol à réserver : ";
    std::getline(std::cin >> std::ws, numero);

    int index = rechercherVol(numero);
    if (index == -1) {
        std::cout << "Vol introuvable.\n";
        return;
    }

    Passager p;
    std::cout << "\n--- Informations du passager ---\n";
    p.saisir();

    if (vols[index].ajouterPassager(p)) {
        Reservation r(p, numero);
        reservations.push_back(r);
        std::cout << "Réservation enregistrée (non confirmée).\n";
    }
}

// ==== CONFIRMATION ====

void SystemeDeGestion::confirmerReservation() {
    std::string passeport, numero;

    std::cout << "\n╔══════════════════════════════════════╗\n";
    std::cout <<   "║   CONFIRMATION D’UNE RÉSERVATION     ║\n";
    std::cout <<   "╚══════════════════════════════════════╝\n";

    std::cout << "Numéro du vol : ";
    std::getline(std::cin >> std::ws, numero);
    std::cout << "Numéro de passeport : ";
    std::getline(std::cin >> std::ws, passeport);

    int pos = rechercherReservation(passeport, numero);
    if (pos != -1) {
        reservations[pos].confirmer();
        std::cout << "Réservation confirmée ✅.\n";
    } else {
        std::cout << "Réservation introuvable.\n";
    }
}

// ==== AFFICHAGE DES PASSAGERS ====

void SystemeDeGestion::afficherPassagersVol(const std::string& numeroVol) const {
    int index = rechercherVol(numeroVol);
    if (index != -1) {
        vols[index].afficherPassagers();
    } else {
        std::cout << "Vol introuvable.\n";
    }
}

// ==== RECHERCHES ====

int SystemeDeGestion::rechercherVol(const std::string& numeroVol) const {
    for (size_t i = 0; i < vols.size(); ++i) {
        if (vols[i].getNumeroVol() == numeroVol)
            return static_cast<int>(i);
    }
    return -1;
}

int SystemeDeGestion::rechercherReservation(const std::string& passeport, const std::string& numeroVol) const {
    for (size_t i = 0; i < reservations.size(); ++i) {
        if (reservations[i].getPasseport() == passeport && reservations[i].getNumeroVol() == numeroVol)
            return static_cast<int>(i);
    }
    return -1;
}

// ==== SAUVEGARDE / CHARGEMENT ====

void SystemeDeGestion::enregistrerFichier(const std::string& chemin) const {
    std::ofstream fichier(chemin);
    if (!fichier) {
        std::cout << "Erreur d’ouverture du fichier.\n";
        return;
    }

    for (const auto& v : vols)
        fichier << "VOL:" << v.toString() << "\n";

    for (const auto& r : reservations)
        fichier << "RES:" << r.toString() << "\n";

    std::cout << "Données sauvegardées dans '" << chemin << "'.\n";
}

void SystemeDeGestion::chargerFichier(const std::string& chemin) {
    std::ifstream fichier(chemin);
    if (!fichier) return;

    vols.clear();
    reservations.clear();

    std::string ligne;
    while (std::getline(fichier, ligne)) {
        if (ligne.rfind("VOL:", 0) == 0) {
            ligne = ligne.substr(4);
            std::istringstream iss(ligne);
            std::string numero;
            int max, reserves;
            float prix;
            char delim;
            std::getline(iss, numero, ';');
            iss >> max >> delim >> reserves >> delim >> prix;

            Vol v(numero, max, prix, Date(), Date(), Destination());
            vols.push_back(v);

        } else if (ligne.rfind("RES:", 0) == 0) {
            ligne = ligne.substr(4);
            std::istringstream iss(ligne);
            std::string titre, nom, prenom, ageStr, passeport, volNum, confStr;

            std::getline(iss, titre, ';');
            std::getline(iss, nom, ';');
            std::getline(iss, prenom, ';');
            std::getline(iss, ageStr, ';');
            std::getline(iss, passeport, ';');
            std::getline(iss, volNum, ';');
            std::getline(iss, confStr, ';');

            int age = std::stoi(ageStr);
            bool confirme = (confStr == "1");

            Passager p(nom, prenom, titre, passeport, age);
            Reservation r(p, volNum);
            if (confirme) r.confirmer();
            reservations.push_back(r);

            int i = rechercherVol(volNum);
            if (i != -1)
                vols[i].ajouterPassager(p);
        }
    }

    fichier.close();
    std::cout << "Données chargées depuis '" << chemin << "'.\n";
}

// ==== EXPORT LISIBLE ====

void SystemeDeGestion::exporterLisible(const std::string& chemin) const {
    std::ofstream fichier(chemin);
    if (!fichier) {
        std::cout << "Impossible de créer le fichier : " << chemin << "\n";
        return;
    }

    fichier << "\n========= RAPPORT DES VOLS =========\n\n";
    if (vols.empty()) {
        fichier << "Aucun vol disponible.\n";
    } else {
        for (const auto& v : vols) {
            fichier << "- Vol : " << v.getNumeroVol() << "\n";
            fichier << "  Places restantes : " << v.getNbPlacesDispo() << "\n";
            fichier << "  Prix : " << v.toString().substr(v.toString().find_last_of(';') + 1) << " FCFA\n\n";
        }
    }

    fichier << "\n========= RÉSERVATIONS =========\n\n";
    if (reservations.empty()) {
        fichier << "Aucune réservation.\n";
    } else {
        for (const auto& r : reservations) {
            fichier << "- Vol : " << r.getNumeroVol()
                    << ", Passeport : " << r.getPasseport()
                    << ", Statut : " << (r.estConfirmeeReservation() ? "Confirmée" : "Non confirmée") << "\n";
        }
    }

    fichier.close();
    std::cout << "Rapport exporté dans '" << chemin << "'.\n";
}
