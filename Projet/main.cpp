#include <string>
#include <iostream>
#include "UV.h"
#include "Formation.h"
#include "Periode.h"
#include "Dossier.h"
#include "Categorie.h"
#include "Credits.h"
#include "Inscription.h"
#include "UvManager.h"
#include "CreditManager.h"


using namespace std;

int main()
{
    try
    {
        Dossier D1("szewe","nicolas");
        Dossier D2("germain","audrey");
        Dossier D3("chan","li");

        D1.affichageDossier();
        D2.affichageDossier();
        D3.affichageDossier();

        /* Test Categorie, Credit et UV */
        Categorie TM("TM","Techniques et Methodes");
        Categorie CS("CS","Connaissance Scientifique");

        Credits CS_Classique("CS_Classique",6,CS);
        Credits TM_Classique("TM_CLassique",6,TM);

        UV NF01("NF01","Algorithmique","On apprend le Pascal",TM);
        UV NF16("NF16","Complexité et Structure de donnée","Tous est dans le titre",CS);
        UV NF92("NF92","Decouverte du Genie Informatique","Decouverte de tous ce que l'on peut faire en GI",TM);
        UV LO21("LO21","Programmation orienté objet","Une UV ou l'on apprend le C++",TM);

        NF01.ajoutCredits(TM_Classique);
        NF16.ajoutCredits(CS_Classique);
        NF92.ajoutCredits(TM_Classique);
        LO21.ajoutCredits(TM_Classique);

        LO21.ajoutPrerequis(NF01);
        LO21.ajoutPrerequis(NF92);
        LO21.ajoutPrerequis(NF16);
        LO21.retirePrerequis(NF92);
        LO21.ajoutPrerequis(NF92);
        LO21.ajoutCredits(CS_Classique);
        LO21.retireCredits(CS_Classique);
        LO21.retireCredits(TM_Classique);

        NF01.affichageUV();
        NF16.affichageUV();
        NF92.affichageUV();
        LO21.affichageUV();
        cout << endl;


        UV LO21P13(LO21);
        cout<<"TEST CONSTRUCTEUR RECOPIE :"<<endl;
        LO21P13.affichageUV();

        /*
        cout<<"TEST DESTRUCTEUR UV"<<endl;
        LO21P13.~UV();
        LO21P13.affichageUV();
        */

        /* Test Formations */
        Credits CS_branche("CS_branche",30,CS);
        Credits TM_branche("TM_branche",30,TM);

        Formation GI("GI", "Genie informatique");
        Formation GP("GP","Genie des procedes");
        GI.ajouterCredits(CS_branche);
        GI.ajouterCredits(TM_branche);
        GI.ajouterUV(NF01);
        GI.ajouterUV(LO21);
        GI.ajouterUV(NF16);
        GI.afficher();
        cout << endl;

        Formation FDD("FDD", "Fouille de données");
        GI.ajouterFormationFille(FDD);
        GI.retirerCredits(CS_branche);
        GI.retirerUV(NF01);
        GI.afficher();
        cout << endl;

        /* Test Periode */
        Periode P14("Printemps", 2014);
        Periode A70("Automne", 1970);

        P14.afficherPeriode();
        A70.afficherPeriode();
        cout << endl;

        //Periode A71("Automne", 2171); // Génère une Exception

        /* Test Inscription */
        Inscription GI02(P14, GI);
        GI02.ajouterUV(NF16);
        GI02.ajouterUV(LO21);
        GI02.afficherInscription();
        GI02.retirerUV(NF16);
        GI02.afficherInscription();

        //modification dossier avec formation et inscription
        D1.ajoutFormation(GI);
        D2.ajoutFormation(GP);
        D1.affichageDossier();
        D2.affichageDossier();
        D1.ajoutInscription(GI02);
        D1.affichageDossier();


        //Test du Credit manager
        CreditManager& m_Cred=CreditManager::getInstance();
        m_Cred.ajouterCredit(CS_Classique);
        m_Cred.ajouterCredit(TM_Classique);
        m_Cred.ajouterCredit(CS_branche);
        m_Cred.ajouterCredit(TM_branche);
        m_Cred.affichage();

        //Test du UV manager
        UVManager& m=UVManager::getInstance();
        m.ajouterUV(LO21);
        m.ajouterUV(NF92);
        m.ajouterUV(NF01);
        m.ajouterUV(NF16);
        m.affichage();




    } catch(Exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}
