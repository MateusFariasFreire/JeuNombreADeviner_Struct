/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: JeuNombreADeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de création : 25/01/2021
// Rôle du fichier: Contient le code des fonctions du jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
//                              ctime
// Historique du fichier:
/*************************************************/
#include <iostream>
#include <time.h>
using namespace std;
#include "../include/JeuNombreAdeviner.h"

// Nom :InitJoueur
// Rôle : Crée un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagnées et de parties jouées seront à 0.
// Paramètres d'entrée : nom du joueur à créer
// Paramètres d'entrée/sortie : joueur à créer

void InitJoueur(TJoueur& joueurAcreer, string un_nom)
{
    joueurAcreer = {un_nom, 0, 0, 0};

}


// Nom :TirerNombreMystere
// Rôle : Tire aléatoirement un nombre à deviner entre 0 et 10
// Valeur de retour : nombre à deviner

int TirerNombreMystere()
{
    srand(time(NULL));
    return rand()%11;
}


// Nom :JouerPartie
// Rôle : Fait jouer une partie au joueur passé en paramètre
//        A la fin, met à jour les informations du joueur
// Paramètres d'entrée: nombre à deviner
// Paramètres d'entrée/sortie : joueur

void JouerPartie(TJoueur& un_joueur, int nombreADeviner)
{
    int nbSaisi;
    int nbEssais = 0;
    bool gagne;

    do{
        cin >> nbSaisi;
        if(nbSaisi > nombreADeviner){
            cout << "C'est moins\n";
        }else if(nbSaisi < nombreADeviner){
            cout << "C'est plus\n";
        }
        nbEssais ++;
    }while(nbSaisi != nombreADeviner && nbEssais < 4);

    if(nbSaisi == nombreADeviner){
        gagne = true;
    }else{
        gagne = false;
    }

    MajResultatsJoueur(un_joueur, nbEssais, gagne);
}


// Nom : MajResultatsJoueur
// Rôle : met à jour les informations du joueur passé en paramètre
// Paramètres d'entrée: joueur / nombre d'essais / victoire ou non du joueur
// Paramètres d'entrée/sortie : joueur

void MajResultatsJoueur(TJoueur & joueur, int nbEssais, bool gagne)
{
    if(gagne != false){
        joueur.nbPartiesGagnees++;
    }
    joueur.nbPartiesJouees++;
    joueur.nbTentatives += nbEssais;

}

// Nom : ResultatsJoueur
// Rôle : indique les résultats du joueur passé en paramètre
//        le nombre de parties gagnées, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations à l'écran
// Paramètres d'entrée: joueur
// Paramètres de sortie: aucun
// Paramètres d'entrée/sortie : nbsucces / nbechec / nbessais

void ResultatsJoueur(TJoueur joueur, int & nbsucces, int & nbechec, int & nbessais)
{
    nbsucces = joueur.nbPartiesGagnees;
    nbechec = joueur.nbPartiesJouees - nbsucces;
    nbessais = joueur.nbTentatives;
}

// Nom :Nom
// Rôle : retourne le nom du joueur
// Paramètres d'entrée: le joueur dont on veut le nom
// Valeur de retour : nom du joueur

string Nom(TJoueur joueur){

    return joueur.nom;
}

