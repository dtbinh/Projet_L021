#include "FormationManager.h"

using namespace std;

/*void FormationManager::load(CreditManager credman)
{
    QDomDocument doc = load_xml("formation_utc.xml");

    QDomElement racine = doc.documentElement();
    racine = racine.firstChildElement();

    while(!racine.isNull())
    {
        if(racine.tagName() == "formation")
        {
            QString tempCode,tempNom,tempCred,tempSpec;
            QDomElement unElement = racine.firstChildElement();

            while(!unElement.isNull())
            {
                if(unElement.tagName() == "code")
                {
                    tempCode = unElement.text();
                }
                else if(unElement.tagName() == "nom")
                {
                    tempNom = unElement.text();
                }
                else if(unElement.tagName() == "credits")
                {
                    tempCred = unElement.text();
                }
                else if(unElement.tagName() == "specialites")
                {
                    tempSpec = unElement.text();
                }
                unElement = unElement.nextSiblingElement();
            }

            Credits& credit=credman.getCredit(tempCred);
            Formation* specialite=this->getFormation(tempSpec);
            this->ajouterFormation(tempCode,tempNom);
            this->getFormation(tempCode)->ajouterCredits(credit);
            this->getFormation(tempCode)->ajouterSpecialite(*specialite);
            //Probleme, il faut faire un tableau de credits car la on ajoute que un des credits données.
            //Meme probleme pour specialité
        }

        racine = racine.nextSiblingElement();
    }
}*/
