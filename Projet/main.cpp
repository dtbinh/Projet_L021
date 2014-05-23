#include <string>
#include <iostream>
#include "Uv.h"
#include "Formation.h"
#include "Periode.h"
#include "Dossier.h"
#include "Categorie.h"
#include "Credits.h"

using namespace std;

int main()
{
    try
    {
        Dossier D1("szewe","nicolas");
        Dossier D2("germain","audrey");
        Dossier D3("chan","li");

        D1.affichage();
        D2.affichage();
        D3.affichage();

        /* Test Categorie, Credit et UV */
        Categorie TM("TM","Techniques et Methodes");
        Categorie CS("CS","Connaissance Scientifique");

        Credit CS_Classique(6,CS);
        Credit TM_Classique(6,TM);

        UV NF01("NF01","Algorithmique","On apprend le Pascal",&TM_Classique,TM);
        UV NF16("NF16","Complexité et Structure de donnée","Tous est dans le titre",&CS_Classique,CS);
        UV NF92("NF92","Decouverte du Genie Informatique","Decouverte de tous ce que l'on peut faire en GI",&TM_Classique,TM);
        UV LO21("LO21","Programmation orienté objet","Une UV ou l'on apprend le C++",&TM_Classique,TM,&NF01);

        LO21.ajoutPrerequis(&NF92);
        LO21.ajoutPrerequis(&NF16);
        LO21.retirePrerequis(&NF92);
        LO21.ajoutPrerequis(&NF92);
        LO21.ajoutCredits(&CS_Classique);
        LO21.retireCredits(&CS_Classique);
        LO21.retireCredits(&TM_Classique);

        NF01.affichageUV();
        NF16.affichageUV();
        NF92.affichageUV();
        LO21.affichageUV();
        cout << endl;

        /* Test Formations */
        Credit CS_branche(30,CS);
        Credit TM_branche(30,TM);

        Formation GI("GI", "Genie informatique");
        GI.ajouterCredit(CS_branche);
        GI.ajouterCredit(TM_branche);
        GI.ajouterUV(LO21);
        GI.ajouterUV(NF16);
        GI.ajouterUV(NF01);
        GI.afficher();
        cout << endl;

        GI.retirerUV(NF01);
        GI.afficher();
        cout << endl;

        /* Test Periode */
        Periode P14("Printemps", 2014);
        Periode A70("Automne", 1970);

        P14.afficher();
        A70.afficher();

        Periode A71("Automne", 2171); // Génère une Exception

    } catch(Exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}
