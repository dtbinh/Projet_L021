#include <QString>
#include <iostream>
#include "UV.h"
#include "qdir.h"
#include "Formation.h"
#include "Periode.h"
#include "Dossier.h"
#include "CategorieManager.h"
#include "Credits.h"
#include "Inscription.h"
#include "UvManager.h"
#include "CreditManager.h"

using namespace std;

int main()
{
    try
    {
        Dossier D1("szewe","nicolas");
        Dossier D2("germain","audrey");
        Dossier D3("chan","li");

        CategorieManager cm;
        cm.load();

        CreditManager credman;
        credman.load(cm);

        UV NF01("NF01","Algorithmique",*cm.getCategorie("TM"));
        UV NF16("NF16","Complexité et Structure de donnée",*cm.getCategorie("CS"));
        UV NF92("NF92","Decouverte du Genie Informatique",*cm.getCategorie("TM"));
        UV LO21("LO21","Programmation orienté objet",*cm.getCategorie("TM"));

        NF01.ajoutCredits(credman.getCredit("TM_Classique"));
        NF16.ajoutCredits(credman.getCredit("CS_Classique"));
        NF92.ajoutCredits(credman.getCredit("TM_Classique"));
        LO21.ajoutCredits(credman.getCredit("TM_Classique"));

        /*LO21.ajoutPrerequis(NF01);
        LO21.ajoutPrerequis(NF92);
        LO21.ajoutPrerequis(NF16);
        LO21.retirePrerequis(NF92);
        LO21.ajoutPrerequis(NF92);
        LO21.ajoutCredits(CS_Classique);
        LO21.retireCredits(CS_Classique);
        LO21.retireCredits(TM_Classique);*/

        NF01.affichage();
        NF16.affichage();
        NF92.affichage();
        LO21.affichage();
        cout << endl;


        UV LO21P13(LO21);
        cout<<"TEST CONSTRUCTEUR RECOPIE :"<<endl;
        LO21P13.affichage();
        cout << endl;

        Formation GI("GI", "Genie informatique");
        Formation GP("GP", "Genie des procedes");
        GI.ajouterCredits(credman.getCredit("CS_Branche"));
        GI.ajouterCredits(credman.getCredit("TM_Branche"));
        GI.retirerUV(NF01);
        GI.ajouterUV(NF01);
        GI.ajouterUV(LO21);
        GI.ajouterUV(NF16);
        GI.afficher();
        cout << endl;

        Formation FDD("FDD", "Fouille de données");
        GI.ajouterSpecialite(FDD);
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
        GI02.modifierNote(LO21, A);
        GI02.afficher();

        D1.ajoutFormation(GI);
        D2.ajoutFormation(GP);
        D1.affichage();
        D2.affichage();
        D1.ajoutInscription(GI02);
        D1.affichage();

    } catch(Exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}
