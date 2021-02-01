/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de création : 25/01/2021
// Rôle du fichier: Contient le code jeu
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
    int nbsucces, nbechec, nbtentatives = 0;

    TJoueur joueur;
    string nomJoueur;
    cout << "Saisir le nom du joueur : ";
    cin >> nomJoueur;
    InitJoueur(joueur, nomJoueur);

    do{
        nbAdeviner = TirerNombreMystere();

        cout << "\nVous allez jouer pour deviner un nombre secret\n";
        JouerPartie(joueur, nbAdeviner);
        ResultatsJoueur(joueur, nbsucces, nbechec, nbtentatives);
        AfficherResultats(joueur);

        cout << "\nVoulez-vous rejouer ?\n1 = OUI  2 = NON\n";
        cin >> wannaPlay;

        system("cls");
    }while(wannaPlay == 1);

    return 0;
}

