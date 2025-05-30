#include <iostream>
#include <limits>
#include <string>
#include "SystemeDeGestion.h"

/**
 * @brief Affiche le menu principal de manière lisible et sobre.
 */
void afficherMenu() {
    std::cout << "\n"
              << "╔═══════════════════════════════════════════════════════╗\n"
              << "║                  GESTION DES VOLS                     ║\n"
              << "╠═══════════════════════════════════════════════════════╣\n"
              << "║  1. Ajouter un vol                                    ║\n"
              << "║  2. Afficher tous les vols                            ║\n"
              << "║  3. Modifier la date d’un vol                         ║\n"
              << "║  4. Annuler un vol                                    ║\n"
              << "║  5. Réserver un vol                                   ║\n"
              << "║  6. Confirmer une réservation                         ║\n"
              << "║  7. Afficher les passagers d’un vol                   ║\n"
              << "║  8. Sauvegarder les données                           ║\n"
              << "║  9. Exporter un rapport lisible                       ║\n"
              << "║ 10. Quitter le programme                              ║\n"
              << "╚═══════════════════════════════════════════════════════╝\n"
              << "Votre choix : ";
}

/**
 * @brief Saisie protégée d’un entier compris entre min et max.
 */
int demanderChoix(int min, int max) {
    int choix;
    std::cin >> choix;

    while (std::cin.fail() || choix < min || choix > max) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Choix invalide. Réessayez : ";
        std::cin >> choix;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choix;
}

/**
 * @brief Point d’entrée principal de l’application.
 */
int main() {
    SystemeDeGestion systeme;

    // Chargement automatique des données au démarrage
    systeme.chargerFichier("data.txt");

    int choix;
    do {
        afficherMenu();
        choix = demanderChoix(1, 10);

        switch (choix) {
            case 1:
                systeme.ajouterVol();
                break;

            case 2:
                systeme.afficherVols();
                break;

            case 3: {
                std::string num;
                std::cout << "Numéro du vol à modifier : ";
                std::getline(std::cin, num);
                systeme.modifierVol(num);
                break;
            }

            case 4: {
                std::string num;
                std::cout << "Numéro du vol à annuler : ";
                std::getline(std::cin, num);
                systeme.annulerVol(num);
                break;
            }

            case 5:
                systeme.reserverVol();
                break;

            case 6:
                systeme.confirmerReservation();
                break;

            case 7: {
                std::string num;
                std::cout << "Numéro du vol : ";
                std::getline(std::cin, num);
                systeme.afficherPassagersVol(num);
                break;
            }

            case 8: {
                std::string chemin;
                std::cout << "Nom du fichier (.txt) : ";
                std::getline(std::cin, chemin);
                systeme.enregistrerFichier(chemin);
                break;
            }

            case 9:
                systeme.exporterLisible("rapport_data.txt");
                break;

            case 10:
                std::cout << "\nMerci d’avoir utilisé le système de gestion des vols.\n";
                systeme.enregistrerFichier("data.txt");
                break;
        }

    } while (choix != 10);

    return 0;
}
