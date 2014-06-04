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
        cm.getCategorie("TM")->affichage();

        CreditManager credman;
        credman.load(cm);
        credman.getCredit("CS_Classique").affichage();

        UvManager uvman;
        uvman.load(credman,cm);
        uvman.getUv("LO21")->affichage();

        Formation GI("GI", "Genie informatique");
        Formation GP("GP", "Genie des procedes");
        GI.ajouterCredits(credman.getCredit("CS_Branche"));
        GI.ajouterCredits(credman.getCredit("TM_Branche"));
        GI.ajouterUV(*uvman.getUv("NF01"));
        GI.retirerUV(*uvman.getUv("NF01"));
        GI.ajouterUV(*uvman.getUv("LO21"));
        GI.ajouterUV(*uvman.getUv("NF16"));

        Formation FDD("FDD", "Fouille de données");
        GI.ajouterSpecialite(FDD);
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
        GI02.ajouterUV(*uvman.getUv("NF16"));
        GI02.ajouterUV(*uvman.getUv("LO21"));
        GI02.retirerUV(*uvman.getUv("NF16"));
        GI02.modifierNote(*uvman.getUv("LO21"), A);
        GI02.afficher();

        D1.ajoutFormation(GI);
        D2.ajoutFormation(GP);
        D2.affichage();
        D1.ajoutInscription(GI02);
        D1.affichage();

    } catch(Exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}

