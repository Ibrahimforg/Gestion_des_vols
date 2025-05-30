#ifndef SYSTEME_DE_GESTION_H
#define SYSTEME_DE_GESTION_H

#include <vector>
#include <string>
#include "Vol.h"
#include "Reservation.h"

/**
 * @brief Système global de gestion de vols pour une compagnie aérienne.
 * 
 * Gère les opérations de création de vols, de réservations, 
 * de confirmation, de recherche et de persistance dans un fichier texte.
 */
class SystemeDeGestion {
private:
    std::vector<Vol> vols;                  ///< Liste de tous les vols
    std::vector<Reservation> reservations;  ///< Liste des réservations (confirmées ou non)

public:
    // ==== Constructeur ====

    /**
     * @brief Initialise un gestionnaire vide.
     */
    SystemeDeGestion();

    // ==== GESTION DES VOLS ====

    /**
     * @brief Saisie et ajout d’un nouveau vol.
     */
    void ajouterVol();

    /**
     * @brief Affiche tous les vols disponibles.
     */
    void afficherVols() const;

    /**
     * @brief Annule un vol existant.
     * @param numeroVol Numéro du vol à annuler
     */
    void annulerVol(const std::string& numeroVol);

    /**
     * @brief Modifie la date de départ d’un vol.
     * @param numeroVol Numéro du vol concerné
     */
    void modifierVol(const std::string& numeroVol);

    // ==== GESTION DES RÉSERVATIONS ====

    /**
     * @brief Réserve un vol pour un nouveau passager.
     */
    void reserverVol();

    /**
     * @brief Confirme une réservation existante (non confirmée).
     */
    void confirmerReservation();

    /**
     * @brief Affiche les passagers d’un vol donné.
     * @param numeroVol Numéro du vol
     */
    void afficherPassagersVol(const std::string& numeroVol) const;

    // ==== RECHERCHE ====

    /**
     * @brief Recherche un vol par son numéro.
     * @param numeroVol Numéro du vol
     * @return Index dans la liste ou -1 si non trouvé
     */
    int rechercherVol(const std::string& numeroVol) const;

    /**
     * @brief Recherche une réservation par passeport et numéro de vol.
     * @param passeport Passeport du passager
     * @param numeroVol Vol concerné
     * @return Index dans la liste ou -1 si non trouvé
     */
    int rechercherReservation(const std::string& passeport, const std::string& numeroVol) const;

    // ==== SAUVEGARDE / CHARGEMENT ====

    /**
     * @brief Enregistre les vols et réservations dans un fichier texte (compact).
     * @param chemin Nom du fichier cible
     */
    void enregistrerFichier(const std::string& chemin) const;

    /**
     * @brief Charge les données depuis un fichier texte (compact).
     * @param chemin Nom du fichier source
     */
    void chargerFichier(const std::string& chemin);

    // ==== EXPORT LISIBLE POUR RAPPORT FINAL ====

    /**
     * @brief Génère un export lisible des données (vols + réservations) pour les professeurs ou les rapports.
     * @param chemin Nom du fichier .txt généré
     */
    void exporterLisible(const std::string& chemin) const;
};

#endif // SYSTEME_DE_GESTION_H
