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
        QString fichier="enormand.xml";
        dosman.load(fichier);
        dosman.getDossier("enormand").afficher();

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

        /*Inscription GI02(periodeman.getPeriode("P2014"), forman.getFormation("GI"));
        GI02.ajouterUV(uvman.getUV("NF16"));
        GI02.ajouterUV(uvman.getUV("LO21"));
        GI02.retirerUV(uvman.getUV("NF16"));
        GI02.modifierNote(uvman.getUV("LO21"), A);
        GI02.afficher();

        dosman.getDossier("szewenic").ajouterFormation((forman.getFormation("GI")));
        dosman.getDossier("enormand").ajouterFormation(forman.getFormation("TC"));
        dosman.getDossier("enormand").afficher();
        dosman.getDossier("szewenic").ajouterInscription(GI02);
        dosman.getDossier("szewenic").afficher();
        */


    } catch(Exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}

