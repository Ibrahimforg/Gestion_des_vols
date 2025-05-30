#include "Date.h"
#include <iostream>
#include <ctime>
#include <limits>
#include <iomanip> // pour setw et setfill

// === Constructeurs ===

Date::Date() : jour(1), mois(1), annee(2025), heure(0), minute(0) {}

Date::Date(int j, int m, int a, int h, int min)
    : jour(j), mois(m), annee(a), heure(h), minute(min) {}


// === Validation de date ===

bool Date::estDansLePasse() const {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    if (annee < now->tm_year + 1900) return true;
    if (annee == now->tm_year + 1900 && mois < now->tm_mon + 1) return true;
    if (annee == now->tm_year + 1900 && mois == now->tm_mon + 1 && jour < now->tm_mday) return true;
    if (annee == now->tm_year + 1900 && mois == now->tm_mon + 1 && jour == now->tm_mday) {
        if (heure < now->tm_hour) return true;
        if (heure == now->tm_hour && minute < now->tm_min) return true;
    }

    return false;
}


// === Saisie utilisateur ===

void Date::saisir() {
    char slash1, slash2;

    std::cout << "Entrez la date (JJ/MM/AAAA) : ";
    while (true) {
        std::cin >> jour >> slash1 >> mois >> slash2 >> annee;
        if (!std::cin.fail() && slash1 == '/' && slash2 == '/' &&
            jour >= 1 && jour <= 31 &&
            mois >= 1 && mois <= 12 &&
            annee >= 2024) {
            break;
        }

        std::cout << "Format invalide. Exemple : 27/05/2025\nNouvelle tentative : ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    char colon;
    std::cout << "Entrez l’heure (HH:MM) : ";
    while (true) {
        std::cin >> heure >> colon >> minute;
        if (!std::cin.fail() && colon == ':' &&
            heure >= 0 && heure <= 23 &&
            minute >= 0 && minute <= 59) {
            break;
        }

        std::cout << "Format invalide. Exemple : 14:30\nNouvelle tentative : ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


// === Affichage formaté ===

void Date::afficher() const {
    std::cout << std::setfill('0') << std::setw(2) << jour << "/"
              << std::setw(2) << mois << "/"
              << annee << " "
              << std::setw(2) << heure << ":"
              << std::setw(2) << minute;
}


// === Comparaison (tri ou test) ===

bool Date::operator<(const Date& autre) const {
    if (annee != autre.annee) return annee < autre.annee;
    if (mois != autre.mois) return mois < autre.mois;
    if (jour != autre.jour) return jour < autre.jour;
    if (heure != autre.heure) return heure < autre.heure;
    return minute < autre.minute;
}


// === Setters heure/minute ===

void Date::setHeure(int h) {
    if (h >= 0 && h <= 23)
        heure = h;
}

void Date::setMinute(int m) {
    if (m >= 0 && m <= 59)
        minute = m;
}
