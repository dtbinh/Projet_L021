#include <iostream>
#include <QString>
#include "Application.h"
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
        notman.ajouterNote("A", "Excellent"); //Besoin d'ajouter le fichier note_utc.xml au repo
        //notman.load();

        CategorieManager catman;
        catman.load();

        CreditsManager credman;
        credman.load(catman);

        FormationManager forman;
        forman.load(credman);
        //forman.getFormation("GI").setCode("GQ"); Commande qui ne marche pas pour le moment
        //set formation , set credits et set uvs à définir

        UVManager uvman;
        uvman.load(credman,catman,forman);

        PeriodeManager periodeman;
        periodeman.load();
        //set annee et set nom à définir

        DossierManager dosman;
        /*QString fichier="enormand.xml";
        dosman.load(fichier,forman);
        dosman.getDossier("enormand").afficher();
        cout<<endl;
        QString fichier2="agermain.xml";
        dosman.load(fichier2,forman);
        dosman.getDossier("agermain").afficher();
        cout<<endl;*/

        Inscription GI02("GI02", periodeman.getPeriode("P2014"), forman.getFormation("GI"));
        GI02.ajouterUV(uvman.getUV("NF16"));
        GI02.ajouterUV(uvman.getUV("LO21"));
        GI02.retirerUV("NF16");
        GI02.modifierNote("LO21", notman.getNote("A"));

        //dosman.getDossier("enormand").ajouterInscription(GI02);
        //dosman.getDossier("enormand").afficher();

        notman.save();
        catman.save();
        credman.save();
        forman.save();
        uvman.save();
        periodeman.save();
        //QString templogin="enormand";
        //dosman.save(fichier,templogin);

    } catch(Exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}

