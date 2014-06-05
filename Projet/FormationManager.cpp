#include <fstream>
#include <QtXml>
#include "FormationManager.h"
#include "Exception.h"

using namespace std;

void FormationManager::load(CreditManager credman){
    QString file="formation_utc.xml";
    QFile fichier(file);
    if(!fichier.open(QFile::ReadOnly | QFile::Text)) throw Exception("Ouverture fichier impossible!");
    // Ouverture du fichier XML en lecture seule et en mode texte
    QDomDocument doc;
    doc.setContent(&fichier, false);
    QDomElement racine = doc.documentElement();//<xml>
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
                    //cout<<tempCode.toStdString()<<endl;
                }
                else if(unElement.tagName() == "nom")
                {
                    tempNom = unElement.text();
                    //cout<<tempNom.toStdString()<<endl;

                }
                else if(unElement.tagName() == "credits")
                {
                    tempCred = unElement.text();
                    //cout<<tempCred.toStdString()<<endl;

                }
                else if(unElement.tagName() == "specialites")
                {
                    tempSpec = unElement.text();
                    //cout<<tempSpec.toStdString()<<endl;

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
}
