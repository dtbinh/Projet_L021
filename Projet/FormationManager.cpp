#include "FormationManager.h"

using namespace std;

void FormationManager::load(CreditsManager credman)
{
    QString tempCred="NULL"; QString tempSpec="NULL";
    QDomDocument doc = formations.load_xml("formation_utc.xml");

    QDomElement racine = doc.documentElement();
    racine = racine.firstChildElement();

    while(!racine.isNull())
    {
        if(racine.tagName() == "formation")
        {
            QString tempCode,tempNom;
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
            this->ajouterFormation(tempCode,tempNom);
            if (tempCred!="NULL"){
                this->getFormation(tempCode).ajouterCredits(credman.getCredits(tempCred));
                tempCred="NULL";
            }
            if (tempSpec!="NULL"){
                this->getFormation(tempCode).ajouterSpecialite(this->getFormation(tempSpec));
                tempSpec="NULL";
            }
            //Probleme, il faut faire un tableau de credits car la on ajoute que un des credits données.
            //Meme probleme pour specialité
        }

        racine = racine.nextSiblingElement();
    }
}
