#include <iostream>
#include <QString>
#include "Exception.h"
#include "CreditsManager.h"
#include "CategorieManager.h"
#include "DossierManager.h"
#include "Inscription.h"
#include "UVManager.h"
#include "PeriodeManager.h"
#include "FormationManager.h"

using namespace std;

int main()
{
    try
    {
        DossierManager dosman;
        dosman.ajouterDossier("szewe", "nicolas");
        dosman.ajouterDossier("normand", "erwan");
        dosman.getDossier("enormand").afficher();
        cout << endl;

        CategorieManager catman;
        catman.load();
        catman.getCategorie("TM").afficher();
        cout << endl;

        catman.getCategorie("QZD").afficher();

        /*CreditManager credman;
        credman.load(catman);
        credman.getCredits("CS_Classique").afficher();
        cout << endl;*/

        /*UvManager uvman;
        uvman.load(credman,cm);
        uvman.getUv("LO21")->affichage();*/

        /*PeriodeManager periodeman;
        periodeman.load();
        periodeman.getPeriode("P14").afficher();
        cout<<endl;*/

        /*FormationManager forman;
        forman.load(credman);
        forman.getFormation("GI").ajouterUV(*uvman.getUv("NF01"));
        forman.getFormation("GI").retirerUV(*uvman.getUv("NF01"));
        forman.getFormation("GI").ajouterUV(*uvman.getUv("LO21"));
        forman.getFormation("GI").ajouterUV(*uvman.getUv("NF16"));
        forman.getFormation("GI").afficher();
        cout<<endl;*/

        /*PeriodeManager periodeman;
        periodeman.load();
        periodeman.getPeriode("P14").afficher();
        cout<<endl;*/

        /* Test Inscription */
        /*Inscription GI02(*periodeman.getPeriode("P14"), *forman.getFormation("GI"));
        GI02.ajouterUV(*uvman.getUv("NF16"));
        GI02.ajouterUV(*uvman.getUv("LO21"));
        GI02.retirerUV(*uvman.getUv("NF16"));
        GI02.modifierNote(*uvman.getUv("LO21"), A);
        GI02.afficher();*/

        /*D1.ajoutFormation(*forman.getFormation("GI"));
        D2.ajoutFormation(*forman.getFormation("GP"));
        D2.affichage();
        D1.ajoutInscription(GI02);
        D1.affichage();*/


    } catch(Exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}

