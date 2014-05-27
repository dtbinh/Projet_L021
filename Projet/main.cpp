#include <string>
#include <iostream>
#include "UV.h"
#include "Formation.h"
#include "Periode.h"
#include "Dossier.h"
#include "Categorie.h"
#include "Credits.h"
#include "Inscription.h"

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

        Credits CS_Classique(6,CS);
        Credits TM_Classique(6,TM);

        UV NF01("NF01","Algorithmique","On apprend le Pascal",TM);
        UV NF16("NF16","Complexité et Structure de donnée","Tous est dans le titre",CS);
        UV NF92("NF92","Decouverte du Genie Informatique","Decouverte de tous ce que l'on peut faire en GI",TM);
        UV LO21("LO21","Programmation orienté objet","Une UV ou l'on apprend le C++",TM);

        NF01.ajoutCredits(TM_Classique);
        NF16.ajoutCredits(CS_Classique);
        NF92.ajoutCredits(TM_Classique);
        LO21.ajoutCredits(TM_Classique);

        LO21.ajoutPrerequis(NF01);
        LO21.ajoutPrerequis(NF92);
        LO21.ajoutPrerequis(NF16);
        LO21.retirePrerequis(NF92);
        LO21.ajoutPrerequis(NF92);
        LO21.ajoutCredits(CS_Classique);
        LO21.retireCredits(CS_Classique);
        LO21.retireCredits(TM_Classique);

        NF01.affichageUV();
        NF16.affichageUV();
        NF92.affichageUV();
        LO21.affichageUV();
        cout << endl;


        UV LO21P13(LO21);
        cout<<"TEST CONSTRUCTEUR RECOPIE :"<<endl;
        LO21P13.affichageUV();

        /*
        cout<<"TEST DESTRUCTEUR UV"<<endl;
        LO21P13.~UV();
        LO21P13.affichageUV();
        */

        /* Test Formations */
        Credits CS_branche(30,CS);
        Credits TM_branche(30,TM);

        Formation GI("GI", "Genie informatique");
        GI.ajouterCredits(CS_branche);
        GI.ajouterCredits(TM_branche);
        GI.ajouterUV(NF01);
        GI.ajouterUV(LO21);
        GI.ajouterUV(NF16);
        GI.afficher();
        cout << endl;

        Formation FDD("FDD", "Fouille de données");
        GI.ajouterFormationFille(FDD);
        GI.retirerCredits(CS_branche);
        GI.retirerUV(NF01);
        GI.afficher();
        cout << endl;

        /* Test Periode */
        Periode P14("Printemps", 2014);
        Periode A70("Automne", 1970);

        P14.afficher();
        A70.afficher();
        cout << endl;

        //Periode A71("Automne", 2171); // Génère une Exception

        /* Test Inscription */
        Inscription GI02(P14, GI);
        GI02.ajouterUV(NF16);
        GI02.ajouterUV(LO21);
        GI02.afficher();
        GI02.retirerUV(NF16);
        GI02.afficher();

    } catch(Exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}
