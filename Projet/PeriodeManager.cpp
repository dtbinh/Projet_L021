#include "PeriodeManager.h"

using namespace std;

void PeriodeManager::load()
{
    QDomDocument doc = periodes.load_xml("periode_utc.xml");

    QDomElement racine = doc.documentElement();
    racine = racine.firstChildElement();

    while(!racine.isNull())
    {
        if(racine.tagName() == "periode")
        {
            QString tempNom;
            unsigned int annee;
            QDomElement unElement = racine.firstChildElement();

            while(!unElement.isNull())
            {
                if(unElement.tagName() == "nom")
                {
                    tempNom = unElement.text();
                }
                else if(unElement.tagName() == "annee")
                {
                    QString temp = unElement.text();
                    annee=temp.toInt();
                }
                unElement = unElement.nextSiblingElement();
            }
            cout << tempNom.toStdString() << " " << annee << endl;
            this->ajouterPeriode(tempNom,annee);
        }

        racine = racine.nextSiblingElement();
    }
}
