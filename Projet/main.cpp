#include <iostream>
#include <QString>
//#include "Application.h"
#include "Exception.h"
#include "Manager.h"
#include "Factory.h"
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

        UVManager uvman;
        uvman.load(credman,catman);

        FormationManager forman;
        FormationManager filman;
        QString tempfi = "filiere_utc.xml"; // Fichier à pousser dans le repo
        QString temp = "formation_utc.xml";
        filman.load(credman,tempfi);
        forman.load(credman,uvman,temp,filman);
        //forman.getFormation("GI").setCode("GQ"); Commande qui ne marche pas pour le moment
        //set formation , set credits et set uvs à définir

        PeriodeManager periodeman;
        periodeman.load();
        //set annee et set nom à définir

        DossierManager dosman;
        QString fichier="enormand.xml";
        dosman.load(fichier,forman,periodeman);
        QString fichier2="agermain.xml";
        dosman.load(fichier2,forman,periodeman);

        dosman.getDossier("enormand").ajouterInscription("GI02", periodeman.getPeriode("P2014"), forman.getFormation("GI"));
        dosman.getDossier("enormand").getInscription("GI02").ajouterUV(uvman.getUV("NF16"));
        dosman.getDossier("enormand").getInscription("GI02").ajouterUV(uvman.getUV("LO21"));
        dosman.getDossier("enormand").getInscription("GI02").retirerUV("NF16");
        dosman.getDossier("enormand").getInscription("GI02").modifierNote("LO21", notman.getNote("A"));
        dosman.getDossier("enormand").afficher();

        notman.save();
        catman.save();
        credman.save();
        forman.save(temp);
        filman.save(tempfi);
        uvman.save();
        periodeman.save();
        QString templogin="enormand";
        QString templogin2="agermain";
        dosman.save(fichier,templogin);
        dosman.save(fichier2,templogin2);

    } catch(Exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}

