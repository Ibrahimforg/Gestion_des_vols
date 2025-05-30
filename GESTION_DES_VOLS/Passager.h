#ifndef PASSAGER_H
#define PASSAGER_H

#include <iostream>
#include <string>

/**
 * @brief Représente un passager d’un vol.
 * 
 * Contient les informations personnelles et le numéro de passeport
 * servant à l’identification lors des réservations.
 */
class Passager {
private:
    std::string nom;
    std::string prenom;
    std::string titre;             // "M", "Mme", ou "Mlle"
    std::string numeroPasseport;
    int age;

public:
    // === Constructeurs ===

    /**
     * @brief Construit un passager par défaut avec des valeurs initiales.
     */
    Passager();

    /**
     * @brief Construit un passager avec les informations complètes.
     * @param nom Nom du passager
     * @param prenom Prénom du passager
     * @param titre Civilité ("M", "Mme", "Mlle")
     * @param numeroPasseport Numéro de passeport
     * @param age Âge du passager
     */
    Passager(const std::string& nom,
             const std::string& prenom,
             const std::string& titre,
             const std::string& numeroPasseport,
             int age);

    // === Saisie & Affichage ===

    /**
     * @brief Saisie interactive des données du passager (avec validation).
     */
    void saisir();

    /**
     * @brief Affiche les informations du passager dans un format lisible.
     */
    void afficher() const;

    // === Accesseurs ===

    /**
     * @return Le numéro de passeport du passager.
     */
    std::string getPasseport() const;

    /**
     * @return Le nom complet formaté du passager.
     */
    std::string getNomComplet() const;

    /**
     * @return Le nom du passager.
     */
    std::string getNom() const;

    /**
     * @return Le prénom du passager.
     */
    std::string getPrenom() const;

    /**
     * @return Le titre (civilité) du passager.
     */
    std::string getTitre() const;

    /**
     * @return L'âge du passager.
     */
    int getAge() const;

    // === Export fichier ===

    /**
     * @brief Sérialise les informations du passager dans une ligne de texte.
     * @return Chaîne de caractères au format CSV compatible avec les fichiers.
     */
    std::string toString() const;
};

#endif // PASSAGER_H
