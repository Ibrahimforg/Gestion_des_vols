#ifndef VOL_H
#define VOL_H

#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
#include "Destination.h"
#include "Passager.h"

/**
 * @brief Représente un vol d’une compagnie aérienne.
 * 
 * Contient les informations essentielles pour gérer un vol :
 * - numéro, dates, prix, destination
 * - liste des passagers
 * - méthodes de réservation, d’affichage et de modification.
 */
class Vol {
private:
    std::string numeroVol;                 // Identifiant du vol
    int nbPlacesMax;                       // Capacité totale
    int nbPlacesReservees;                // Nombre de réservations faites
    float prix;                            // Prix d’une place
    Date dateDepart;                       // Date/heure de départ
    Date dateArrivee;                      // Date/heure d’arrivée
    Destination destination;               // Ville de départ/arrivée
    std::vector<Passager> passagers;       // Liste des passagers

public:
    // ==== Constructeurs ====
    Vol();
    Vol(const std::string& numero,
        int maxPlaces,
        float prix,
        const Date& depart,
        const Date& arrivee,
        const Destination& dest);

    // ==== Réservation / Contrôle ====
    bool estComplet() const;
    bool ajouterPassager(const Passager& p);
    bool contientPassager(const std::string& passeport) const;

    // ==== Affichage ====
    void afficher() const;
    void afficherPassagers() const;

    // ==== Modification ====
    void modifierDate(const Date& nouvelleDate);
    void modifierHeure(int heure, int minute);

    // ==== Accesseurs ====
    std::string getNumeroVol() const;
    int getNbPlacesDispo() const;

    // ==== Export fichier ====
    std::string toString() const;
};

#endif // VOL_H
