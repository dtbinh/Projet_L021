#include <iostream>
#include <QString>
#include "Application.h"
#include "Exception.h"
#include "Manager.h"
#include "Factory.h"
#include "CreditsManager.h"
#include "DossierManager.h"
#include "Inscription.h"
#include "UVManager.h"
#include "PeriodeManager.h"
#include "FormationManager.h"
#include "Completion.h"

using namespace std;

int main()
{
    try
    {
        Application app;
        app.load();

        CreditsManager credman;
        credman.load("credit_utc.xml", app.getCategorieManager());

        UVManager uvman;
        uvman.load("uv_utc.xml", credman, app.getCategorieManager());

        FormationManager forman;
        FormationManager filman;
        QString tempfi = "filiere_utc.xml";
        QString temp = "formation_utc.xml";
        filman.load(tempfi, credman);
        forman.load(temp, credman, uvman, filman);
        //forman.getFormation("GI").setCode("GQ"); Commande qui ne marche pas pour le moment
        //set formation , set credits et set uvs à définir //pas utile avec les méthodes ajouter et retirer

        PeriodeManager periodeman;
        periodeman.load("periode_utc.xml");

        DossierManager dosman;
        QString fichier="enormand.xml";
        dosman.load(fichier, forman, periodeman, uvman, app.getNoteManager());
        QString fichier2="agermain.xml";
        dosman.load(fichier2,forman,periodeman,uvman, app.getNoteManager());

        /*dosman.getDossier("enormand").ajouterInscription("GI02", periodeman.getPeriode("P2014"), forman.getFormation("GI"));
        dosman.getDossier("enormand").getInscription("GI02").ajouterUV(uvman.getUV("NF16"));
        dosman.getDossier("enormand").getInscription("GI02").ajouterUV(uvman.getUV("LO21"));
        dosman.getDossier("enormand").getInscription("GI02").retirerUV("NF16");
        dosman.getDossier("enormand").getInscription("GI02").ajouterUV(uvman.getUV("NF17"));
        dosman.getDossier("enormand").getInscription("GI02").modifierNote("LO21", notman.getNote("A"));
        dosman.getDossier("enormand").afficher();
        dosman.getDossier("enormand").ajouterInscription("GI01", periodeman.getPeriode("A2013"), forman.getFormation("GI"));
*/

        Completion compman=Completion(uvman);
        credman.save("credit_utc.xml");
        forman.save(temp);
        filman.save(tempfi);
        uvman.save("uv_utc.xml");
        periodeman.save("periode_utc.xml");
        QString templogin="enormand";
        QString templogin2="agermain";
        dosman.save(fichier,templogin);
        dosman.save(fichier2,templogin2);

    } catch(Exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}

