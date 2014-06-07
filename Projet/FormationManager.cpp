#include "FormationManager.h"

using namespace std;

void FormationManager::load(const CreditsManager& credman)
{
    std::vector<const Credits*> tempcredits;
    std::vector<const Formation*> tempspecialites;
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
                    tempcredits.push_back(&credman.getCredits(tempCred));
                }
                else if(unElement.tagName() == "specialites")
                {
                    tempSpec = unElement.text();
                    tempspecialites.push_back(&this->getFormation(tempSpec));
                }
                unElement = unElement.nextSiblingElement();
            }

            this->ajouterFormation(tempCode,tempNom);
            if (tempCred!="NULL"){
                for (unsigned int i = 0; i < tempcredits.size(); i++)
                {
                    this->getFormation(tempCode).ajouterCredits(credman.getCredits(tempcredits[i]->getNom()));
                }
                tempCred="NULL";
                tempcredits.clear();
            }
            if (tempSpec!="NULL"){
                for (unsigned int i = 0; i < tempspecialites.size(); i++)
                {
                    this->getFormation(tempCode).ajouterSpecialite(this->getFormation(tempspecialites[i]->getCode()));
                }
                tempSpec="NULL";
                tempspecialites.clear();
            }
        }

        racine = racine.nextSiblingElement();
    }
}
