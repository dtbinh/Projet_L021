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

        CreditsManager credman;
        credman.load(catman);
        credman.getCredits("CS_Classique").afficher();
        cout << endl;

        FormationManager forman;
        forman.load(credman);

        UVManager uvman;
        uvman.load(credman,catman,forman);
        uvman.getUV("LO21").affichage();
        cout << endl;

        forman.getFormation("GI").afficher();
        cout << endl;

        PeriodeManager periodeman;
        periodeman.load();
        periodeman.getPeriode("P2014").afficher();
        cout<<endl;

        Inscription GI02(periodeman.getPeriode("P2014"), forman.getFormation("GI"));
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


    } catch(Exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}

