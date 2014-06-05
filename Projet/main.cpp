#include <QString>
#include <iostream>
#include "qdir.h"
#include "Dossier.h"
#include "Inscription.h"
#include "CategorieManager.h"
#include "UvManager.h"
#include "CreditManager.h"
#include "PeriodeManager.h"
#include "FormationManager.h"

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

        FormationManager forman;
        forman.load(credman);

        UvManager uvman;
        uvman.load(credman,cm,forman);
        uvman.getUv("LO21")->affichage();

        forman.getFormation("GI")->ajouterUV(*uvman.getUv("NF01"));
        forman.getFormation("GI")->retirerUV(*uvman.getUv("NF01"));
        forman.getFormation("GI")->ajouterUV(*uvman.getUv("LO21"));
        forman.getFormation("GI")->ajouterUV(*uvman.getUv("NF16"));
        forman.getFormation("GI")->afficher();
        cout<<endl;


        PeriodeManager periodeman;
        periodeman.load();
        periodeman.getPeriode("P14")->afficher();
        cout<<endl;


        /* Test Inscription */
        Inscription GI02(*periodeman.getPeriode("P14"), *forman.getFormation("GI"));
        GI02.ajouterUV(*uvman.getUv("NF16"));
        GI02.ajouterUV(*uvman.getUv("LO21"));
        GI02.retirerUV(*uvman.getUv("NF16"));
        GI02.modifierNote(*uvman.getUv("LO21"), A);
        GI02.afficher();

       D1.ajoutFormation(*forman.getFormation("GI"));
        D2.ajoutFormation(*forman.getFormation("GP"));
        D2.affichage();
        D1.ajoutInscription(GI02);
        D1.affichage();


    } catch(Exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}

