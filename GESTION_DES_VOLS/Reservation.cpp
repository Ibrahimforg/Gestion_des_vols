#include "Reservation.h"
#include <iostream>

// === Constructeurs ===

Reservation::Reservation()
    : passager(), numeroVol("UNKNOWN"), estConfirmee(false) {}

Reservation::Reservation(const Passager& p, const std::string& vol)
    : passager(p), numeroVol(vol), estConfirmee(false) {}


// === Opérations ===

void Reservation::confirmer() {
    estConfirmee = true;
}

void Reservation::afficher() const {
    std::cout << "\n--------------------------------------------------\n";
    std::cout << "RÉSERVATION POUR LE VOL : " << numeroVol << "\n";
    passager.afficher();
    std::cout << "STATUT : " << (estConfirmee ? "CONFIRMÉE ✅" : "NON CONFIRMÉE") << "\n";
    std::cout << "--------------------------------------------------\n";
}


// === Accesseurs ===

bool Reservation::estConfirmeeReservation() const {
    return estConfirmee;
}

std::string Reservation::getPasseport() const {
    return passager.getPasseport();
}

std::string Reservation::getNumeroVol() const {
    return numeroVol;
}


// === Sérialisation ===

std::string Reservation::toString() const {
    return passager.toString() + ";" + numeroVol + ";" + (estConfirmee ? "1" : "0");
}
