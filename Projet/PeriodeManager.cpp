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
                    annee=temp.toUInt();
                }
                unElement = unElement.nextSiblingElement();
            }
            this->ajouterPeriode(tempNom,annee);
        }

        racine = racine.nextSiblingElement();
    }
}

void PeriodeManager::save(){
    QDomDocument doc = periodes.save_xml();
    QDomElement root = doc.createElement("xml");
    doc.appendChild(root);

    for (map<QString,Periode>::const_iterator it = periodes.begin(); it != periodes.end(); it++)
    {
        QDomElement periode = doc.createElement("periode");
        root.appendChild(periode);
        QDomElement nom = doc.createElement("nom");
        periode.appendChild(nom);
        QDomText nomText = doc.createTextNode(it->second.getNom());
        nom.appendChild(nomText);
        QDomElement annee = doc.createElement("annee");
        periode.appendChild(annee);
        QDomText anneeText = doc.createTextNode(QString::number(it->second.getAnnee()));
        annee.appendChild(anneeText);
    }
    QFile file( "periode_utc.xml" );
    file.open(QIODevice::WriteOnly);
    QTextStream ts(&file);
    int indent = 2;
    doc.save(ts, indent);
}


