/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de cr�ation : 25/01/2021
// R�le du fichier: Contient le code jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
// Historique du fichier:
/*************************************************/
#include <iostream>
#include <string>
using namespace std;

#include "../include/JeuNombreADeviner.h"

int main()
{

    int wannaPlay = 0;
    int nbAdeviner = 0;
    TJoueur joueur;
    string nomJoueur;

    cout << "Vous allez jouer pour deviner un nombre secret\n";

    do{
        nbAdeviner = TirerNombreMystere();
        cout << "Saisir le nom du joueur : ";
        cin >> nomJoueur;
        InitJoueur(joueur, nomJoueur);
        cout << joueur.nom;
        cout << "Voulez-vous rejouer ?\n1 = OUI  2 = NON\n";
        cin >> wannaPlay;
    }while(wannaPlay == 1);

    return 0;
}

