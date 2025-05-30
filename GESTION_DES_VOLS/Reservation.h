#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>
#include "Passager.h"

/**
 * @brief Représente une réservation pour un passager sur un vol.
 * 
 * Contient les informations du passager, le numéro du vol concerné,
 * et l’état de confirmation de la réservation.
 */
class Reservation {
private:
    Passager passager;         ///< Informations du passager
    std::string numeroVol;     ///< Numéro du vol concerné
    bool estConfirmee;         ///< Statut de confirmation

public:
    // ==== Constructeurs ====

    /**
     * @brief Crée une réservation vide.
     */
    Reservation();

    /**
     * @brief Initialise une réservation avec passager et numéro de vol.
     */
    Reservation(const Passager& p, const std::string& vol);

    // ==== Opérations ====

    /**
     * @brief Marque la réservation comme confirmée.
     */
    void confirmer();

    /**
     * @brief Affiche les informations de la réservation.
     */
    void afficher() const;

    // ==== Accesseurs ====

    /**
     * @brief Vérifie si la réservation est confirmée.
     * @return true si confirmée, false sinon
     */
    bool estConfirmeeReservation() const;

    /**
     * @brief Retourne le numéro de passeport du passager.
     */
    std::string getPasseport() const;

    /**
     * @brief Retourne le numéro du vol associé à la réservation.
     */
    std::string getNumeroVol() const;

    // ==== Sérialisation ====

    /**
     * @brief Convertit les données de la réservation en chaîne pour fichier.
     */
    std::string toString() const;
};

#endif // RESERVATION_H
