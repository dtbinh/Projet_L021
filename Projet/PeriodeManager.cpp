#include <fstream>
#include <QtXml>
#include "PeriodeManager.h"
#include "Exception.h"

using namespace std;

void PeriodeManager::load(){
    QString file="periode_utc.xml";
    QFile fichier(file);
    if(!fichier.open(QFile::ReadOnly | QFile::Text)) throw Exception("Ouverture fichier impossible!");
    // Ouverture du fichier XML en lecture seule et en mode texte
    QDomDocument doc;
    doc.setContent(&fichier, false);
    QDomElement racine = doc.documentElement();//<xml>
    racine = racine.firstChildElement();

    while(!racine.isNull())
    {
        if(racine.tagName() == "periode")
        {
            QString tempCode,tempNom;
            unsigned int annee;
            QDomElement unElement = racine.firstChildElement();
            while(!unElement.isNull())
            {
                if(unElement.tagName() == "nom")
                {
                    tempNom = unElement.text();
                    //cout<<tempNom.toStdString();

                }
                else if(unElement.tagName() == "annee")
                {
                    QString temp = unElement.text();
                    annee=temp.toInt();
                    //cout<<annee<<endl;

                }
                unElement = unElement.nextSiblingElement();
            }
        this->ajouterPeriode(tempNom,annee);

        }

        racine = racine.nextSiblingElement();
    }
}
