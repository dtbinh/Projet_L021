#include <iostream>
#include <QString>
#include <QApplication>
#include <QString>
#include <QFileDialog>
#include "Application.h"
#include "Exception.h"
#include "Accueil.h"
#include "Completion.h"
#include "Solution.h"

using namespace std;

int main(int argc, char *argv[])
{
    //QApplication app(argc, argv);
    //MainWindow test;
    //test.show();
    try
    {
        Application app("dossiers", "dossiers/default", "configuration.xml");

        // Quelques essais en guise d'exemple
            app.charger("enormand");

            //app.getNoteManager().getNote("A").setMention("Mention");
            //app.getUVManager().getUV("LO21").setNom(app.getUVManager().getUV("LO21").getNom() + " (une UV qu'elle est bien !)");

            Completion comp(app.getUVManager());
            Solution("test",app.getDossier(),app.getCategorieManager());
            // comp.ajouterSolution("Test",app.getDossier(),app.getCategorieManager());
            comp.savePreference();

        app.sauvegarder();
        app.fermer();


        // Les modifications sur la note A et sur l'UV LO21 ne me concernait que enormand, pas szewenic
        /*app.charger("szewenic");
        app.getDossier().ajouterInscription("GI01", app.getPeriodeManager().getPeriode("A2013"), app.getFormationManager().getFormation("GI"));
        app.getDossier().getInscription("GI01").ajouterUV(app.getUVManager().getUV("SR02"));
        app.getDossier().getInscription("GI01").modifierNote("SR02", app.getNoteManager().getNote("A"));

        app.sauvegarder();
        app.fermer();*/


       /* app.nouveau("germain", "audrey");

        app.getDossier().ajouterInscription("TC04", app.getPeriodeManager().getPeriode("P2013"), app.getFormationManager().getFormation("TC"));
        app.getDossier().getInscription("TC04").ajouterUV(app.getUVManager().getUV("SY02"));
        app.getDossier().getInscription("TC04").modifierNote("SY02", app.getNoteManager().getNote("B"));

        app.sauvegarder();
        app.fermer();*/


        app.charger("agermain");
        app.getDossier().ajouterInscription("GP01", app.getPeriodeManager().getPeriode("A2014"), app.getFormationManager().getFormation("GP"));
        app.getDossier().getInscription("GP01").ajouterUV(app.getUVManager().getUV("TF06"));
        app.getDossier().getInscription("GP01").modifierNote("TF06", app.getNoteManager().getNote("A"));

        app.sauvegarder();
        app.fermer();

    } catch(Exception &e) {
        cerr << e.what() << endl;
    }

    //return app.exec();
    return 0;
}
