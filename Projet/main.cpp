#include <QString>
#include <iostream>
#include "qdir.h"
#include "Formation.h"
#include "Dossier.h"
#include "Inscription.h"
#include "CategorieManager.h"
#include "UvManager.h"
#include "CreditManager.h"
#include "PeriodeManager.h"

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
        cout<<endl;

        UvManager uvman;
        uvman.load(credman,cm);
        uvman.getUv("LO21")->affichage();

        PeriodeManager periodeman;
        periodeman.load();
        periodeman.getPeriode("P14")->afficher();
        cout<<endl;

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


        /* Test Inscription */
        Inscription GI02(*periodeman.getPeriode("P14"), GI);
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

