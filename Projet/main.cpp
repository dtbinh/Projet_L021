#include "uv_profil.h"

using namespace std;

int main()
{
    Dossier D1 ("szewe","nicolas");
    Dossier D2("germain","audrey");
    Dossier D3("chan","li");
    D1.Affichage();
    D2.Affichage();
    D3.Affichage();
    Categorie TM("TM","Techniques et Methodes");
    Categorie CS("CS","Connaissance Scientifique");
    Credit CS_Classique(6,CS);
    Credit TM_Classique(6,TM);
    UV NF01("NF01","Algorithmique","On apprend le Pascal",&TM_Classique,TM);
    UV NF16("NF16","Complexité et Structure de donnée","Tous est dans le titre",&CS_Classique,CS);
    UV NF92("NF92","Decouverte du Genie Informatique","Decouverte de tous ce que l'on peut faire en GI",&TM_Classique,TM);
    UV LO21("LO21","Programmation orienté objet","Une UV ou l'on apprend le C++",&TM_Classique,TM,&NF01);
    LO21.AjoutPrerequis(&NF92);
    LO21.AjoutPrerequis(&NF16);
    LO21.RetirePrerequis(&NF92);
    LO21.AjoutPrerequis(&NF92);
    LO21.AjoutCredits(&CS_Classique);
    LO21.RetireCredits(&CS_Classique);
    LO21.RetireCredits(&TM_Classique);
    NF01.AffichageUV();
    NF16.AffichageUV();
    NF92.AffichageUV();
    LO21.AffichageUV();
    return 0;
}
