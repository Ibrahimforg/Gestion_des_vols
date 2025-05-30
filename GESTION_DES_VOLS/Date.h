#ifndef DATE_H
#define DATE_H

/**
 * @brief Représente une date complète avec heure.
 *
 * Utilisée pour les horaires de départ et d’arrivée dans la gestion des vols.
 */
class Date {
private:
    int jour;
    int mois;
    int annee;
    int heure;
    int minute;

public:
    // ==== Constructeurs ====

    /**
     * @brief Initialise une date par défaut (01/01/2025 00:00).
     */
    Date();

    /**
     * @brief Initialise une date personnalisée.
     * @param j Jour
     * @param m Mois
     * @param a Année
     * @param h Heure (défaut = 0)
     * @param min Minute (défaut = 0)
     */
    Date(int j, int m, int a, int h = 0, int min = 0);

    // ==== Méthodes principales ====

    /**
     * @brief Saisie utilisateur de la date (format guidé JJ/MM/AAAA HH:MM).
     *        Effectue une validation stricte des entrées.
     */
    void saisir();

    /**
     * @brief Affiche la date au format JJ/MM/AAAA HH:MM avec zéro-padding.
     */
    void afficher() const;

    /**
     * @brief Indique si la date est antérieure à la date système (au moment de l’exécution).
     * @return true si la date est dans le passé, false sinon.
     */
    bool estDansLePasse() const;

    /**
     * @brief Compare deux dates (utile pour tri, vérification, etc.).
     * @param autre L’autre date à comparer.
     * @return true si la date courante est antérieure à l’autre.
     */
    bool operator<(const Date& autre) const;

    // ==== Setters ====

    /**
     * @brief Modifie l’heure (si valide).
     */
    void setHeure(int h);

    /**
     * @brief Modifie les minutes (si valide).
     */
    void setMinute(int m);
};

#endif // DATE_H
