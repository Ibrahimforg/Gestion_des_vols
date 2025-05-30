#ifndef DESTINATION_H
#define DESTINATION_H

#include <string>
#include <iostream>

/**
 * @brief Représente une destination d’un vol.
 * 
 * Contient la ville de départ et la ville d’arrivée, utilisées pour créer un itinéraire.
 */
class Destination {
private:
    std::string villeDepart;   ///< Ville de départ
    std::string villeArrivee;  ///< Ville d’arrivée

public:
    // ==== Constructeurs ====

    /**
     * @brief Crée une destination vide (Inconnue -> Inconnue).
     */
    Destination();

    /**
     * @brief Crée une destination avec départ et arrivée.
     */
    Destination(const std::string& depart, const std::string& arrivee);

    // ==== Saisie & Affichage ====

    /**
     * @brief Saisie guidée depuis la console avec validation.
     */
    void saisir();

    /**
     * @brief Affiche la destination au format "VilleDépart -> VilleArrivée".
     */
    void afficher() const;

    // ==== Accesseurs ====

    /**
     * @brief Retourne la ville de départ.
     */
    std::string getDepart() const;

    /**
     * @brief Retourne la ville d’arrivée.
     */
    std::string getArrivee() const;

    // ==== Exportation ====

    /**
     * @brief Convertit la destination en ligne texte pour sauvegarde.
     */
    std::string toString() const;
};

#endif // DESTINATION_H
