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
#include "NoteManager.h"

using namespace std;

int main()
{
    try
    {

        NoteManager notman;
        notman.load();

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
        cout<<endl;
        QString fichier2="agermain.xml";
        dosman.load(fichier2,forman);
        dosman.getDossier("agermain").afficher();
        cout<<endl;

        Inscription GI02(periodeman.getPeriode("P2014"), forman.getFormation("GI"));
        GI02.ajouterUV(uvman.getUV("NF16"));
        GI02.ajouterUV(uvman.getUV("LO21"));
        GI02.retirerUV(uvman.getUV("NF16"));
        GI02.modifierNote(uvman.getUV("LO21"), notman.getNote("A"));

        dosman.getDossier("enormand").ajouterInscription(GI02);
        dosman.getDossier("enormand").afficher();

        notman.save();
        catman.save();
        credman.save();

    } catch(Exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}

