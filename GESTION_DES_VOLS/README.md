# GESTION DE VOLS – Application C++ Orientée Objet

## Présentation

Ce projet consiste à développer une application console de gestion des vols pour une compagnie aérienne. Il est réalisé en langage **C++** selon les principes de la **programmation orientée objet**, avec une architecture modulaire.

Le système permet d’enregistrer des vols, de gérer des passagers, d’effectuer des réservations, de modifier ou annuler des vols, de confirmer des réservations, et de générer des rapports clairs.

## Fonctionnalités principales

| Fonction                       | Description                                                             |
|-------------------------------|-------------------------------------------------------------------------|
| Ajouter un vol                | Saisie du numéro, destination, capacité, dates, prix                    |
| Afficher tous les vols        | Liste complète et structurée des vols enregistrés                       |
| Modifier un vol               | Mise à jour de la date de départ d’un vol existant                      |
| Annuler un vol                | Suppression d’un vol identifié par son numéro                           |
| Réserver un vol               | Ajout d’un passager (si vol non complet et non déjà réservé)           |
| Confirmer une réservation     | Validation manuelle d’une réservation enregistrée                       |
| Afficher les passagers        | Affiche tous les passagers liés à un vol donné                          |
| Sauvegarde / Chargement       | Persistance des données dans un fichier texte (`data.txt`)              |
| Export lisible pour rapport   | Génération d’un fichier lisible (`rapport_data.txt`) avec synthèse      |

## Architecture et organisation

Le projet est organisé en classes C++ réparties dans des fichiers `*.h` et `*.cpp` :

| Composant            | Rôle principal                                                       |
|----------------------|----------------------------------------------------------------------|
| `main.cpp`           | Interface utilisateur et boucle de menu                              |
| `SystemeDeGestion`   | Classe centrale gérant les vols et les réservations                  |
| `Vol`                | Représente un vol aérien complet (détails, passagers, méthodes)      |
| `Passager`           | Informations personnelles d’un passager (saisie, affichage)          |
| `Date`               | Manipulation et validation des dates et heures                       |
| `Destination`        | Ville de départ et ville d’arrivée                                   |
| `Reservation`        | Lien entre passager et vol avec statut (confirmé ou non)             |

## Outils utilisés

- Langage : **C++**
- Compilation : `g++` 
- IDE recommandés : Visual Studio code
- Fichiers d’entrée/sortie : `data.txt`, `rapport_data.txt`

## Cas de tests (éléments documentés)

| Test                          | Entrée                                      | Sortie attendue                                  |
|-------------------------------|---------------------------------------------|--------------------------------------------------|
| Ajout de vol valide           | Numéro : AB123, 100 places, date future     | Vol ajouté et affiché                            |
| Réservation possible          | Vol AB123, passager non encore enregistré   | Passager ajouté, réservation non confirmée       |
| Réservation déjà existante    | Même passeport pour AB123                   | Message d’erreur : passager déjà enregistré      |
| Réservation sur vol complet   | Réservation au-delà des places max          | Message d’erreur : vol complet                   |
| Confirmation de réservation   | Vol AB123, passeport correspondant          | Statut mis à jour : réservation confirmée        |
| Annulation de vol             | Numéro de vol existant                      | Vol supprimé                                     |
| Modification de date          | Nouvelle date future                       | Vol mis à jour avec succès                       |
| Chargement depuis fichier     | `data.txt` existant                         | Données rechargées sans perte                    |
| Export rapport lisible        | Export vers `rapport_data.txt`              | Fichier généré avec informations formatées       |

## Rapport associé

Le rapport complet `Rapport_Projet_GestionDeVols.pdf` contient :

- Présentation des outils utilisés
- Justification du découpage orienté objet
- Description des classes et relations
- Méthodes implémentées
- Défis techniques rencontrés
- Innovations de structuration et robustesse
- Code complet commenté en annexe

## Déploiement sur GitHub (optionnel)

Le projet peut être déployé et partagé via GitHub pour permettre une lecture facilitée :

- `main.cpp`
- Fichiers `.h` et `.cpp` par classe
- `README.md`
- `Rapport_Projet_GestionDeVols.pdf`
- Exécutable compilé (Windows ou Linux)
- `data.txt` et `rapport_data.txt` de test

---

