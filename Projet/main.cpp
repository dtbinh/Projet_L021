#include <iostream>
#include <QString>
#include "Application.h"
#include "Exception.h"

using namespace std;

int main()
{
    try
    {
        Application app("dossiers", "dossiers/default", "configuration.xml");
        /*app.charger("enormand");

        // Quelques essais en guise d'exemple
        app.getDossier().ajouterInscription("GI01", app.getPeriodeManager().getPeriode("A2013"), app.getFormationManager().getFormation("GI"));
        app.getDossier().getInscription("GI01").ajouterUV(app.getUVManager().getUV("NF16"));
        app.getDossier().getInscription("GI01").modifierNote("NF16", app.getNoteManager().getNote("C"));

        //app.getNoteManager().getNote("A").setMention("Mention");
        //app.getUVManager().getUV("LO21").setNom(app.getUVManager().getUV("LO21").getNom() + " (une UV qu'elle est bien !)");

        app.sauvegarder();
        app.fermer();*/

        // Les modifications sur la note A et sur l'UV LO21 ne me concernait que enormand, pas szewenic
        /*app.charger("szewenic");
        app.getDossier().ajouterInscription("GI01", app.getPeriodeManager().getPeriode("A2013"), app.getFormationManager().getFormation("GI"));
        app.getDossier().getInscription("GI01").ajouterUV(app.getUVManager().getUV("SR02"));
        app.getDossier().getInscription("GI01").modifierNote("SR02", app.getNoteManager().getNote("A"));

        app.sauvegarder();
        app.fermer();*/


        app.nouveau("germain", "audrey");

        app.getDossier().ajouterInscription("TC04", app.getPeriodeManager().getPeriode("P2013"), app.getFormationManager().getFormation("TC"));
        app.getDossier().getInscription("TC04").ajouterUV(app.getUVManager().getUV("SY02"));
        app.getDossier().getInscription("TC04").modifierNote("SY02", app.getNoteManager().getNote("B"));

        app.sauvegarder();
        app.fermer();

    } catch(Exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}

