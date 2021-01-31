/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: JeuNombreADeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de cr�ation : 25/01/2021
// R�le du fichier: Contient le code des fonctions du jeu
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
// R�le : Cr�e un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagn�es et de parties jou�es seront � 0.
// Param�tres d'entr�e : nom du joueur � cr�er
// Param�tres d'entr�e/sortie : joueur � cr�er

void InitJoueur(TJoueur& joueurAcreer, string un_nom)
{
    joueurAcreer = {un_nom, 0, 0, 0};

}


// Nom :TirerNombreMystere
// R�le : Tire al�atoirement un nombre � deviner entre 0 et 10
// Valeur de retour : nombre � deviner

int TirerNombreMystere()
{
    srand(time(NULL));
    return rand()%11;
}


// Nom :JouerPartie
// R�le : Fait jouer une partie au joueur pass� en param�tre
//        A la fin, met � jour les informations du joueur
// Param�tres d'entr�e: nombre � deviner
// Param�tres d'entr�e/sortie : joueur

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
// R�le : met � jour les informations du joueur pass� en param�tre
// Param�tres d'entr�e: joueur / nombre d'essais / victoire ou non du joueur
// Param�tres d'entr�e/sortie : joueur

void MajResultatsJoueur(TJoueur & joueur, int nbEssais, bool gagne)
{
    if(gagne != false){
        joueur.nbPartiesGagnees++;
    }
    joueur.nbPartiesJouees++;
    joueur.nbTentatives += nbEssais;

}

// Nom : ResultatsJoueur
// R�le : indique les r�sultats du joueur pass� en param�tre
//        le nombre de parties gagn�es, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations � l'�cran
// Param�tres d'entr�e: joueur
// Param�tres de sortie: aucun
// Param�tres d'entr�e/sortie : nbsucces / nbechec / nbessais

void ResultatsJoueur(TJoueur joueur, int & nbsucces, int & nbechec, int & nbessais)
{
    nbsucces = joueur.nbPartiesGagnees;
    nbechec = joueur.nbPartiesJouees - nbsucces;
    nbessais = joueur.nbTentatives;
}

// Nom :Nom
// R�le : retourne le nom du joueur
// Param�tres d'entr�e: le joueur dont on veut le nom
// Valeur de retour : nom du joueur

string Nom(TJoueur joueur){

    return joueur.nom;
}

