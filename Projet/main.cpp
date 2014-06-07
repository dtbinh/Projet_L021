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
        CategorieManager catman;
        catman.load();

        CreditsManager credman;
        credman.load(catman);

        FormationManager forman;
        forman.load(credman);

        UVManager uvman;
        uvman.load(credman,catman,forman);

        PeriodeManager periodeman;
        periodeman.load();

        DossierManager dosman;
        QString fichier="enormand.xml";
        dosman.load(fichier,forman);
        dosman.getDossier("enormand").afficher();
        QString fichier2="agermain.xml";
        dosman.load(fichier2,forman);
        dosman.getDossier("agermain").afficher();

        /*Inscription GI02(periodeman.getPeriode("P2014"), forman.getFormation("GI"));
        GI02.ajouterUV(uvman.getUV("NF16"));
        GI02.ajouterUV(uvman.getUV("LO21"));
        GI02.retirerUV(uvman.getUV("NF16"));
        GI02.modifierNote(uvman.getUV("LO21"), A);
        GI02.afficher();


        dosman.getDossier("szewenic").ajouterInscription(GI02);
        */


    } catch(Exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}

