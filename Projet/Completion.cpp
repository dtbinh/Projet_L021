#include "Completion.h"
#include <string>
#include <iostream>

using namespace std;

void Completion::ajouterSolution(const Dossier& D,const CategorieManager& catman,const UVManager& uvman,bool activation){
    solutions.push_back(Solution(D,catman,this->preferences,uvman,activation));
    unsigned int i = solutions.size()-1;
    solutions[i].affichage();
    cout<<"Souhaitez vous l'accepter?"<<endl;
    solutions[i].setChoix("Accepter");
}

Completion::Completion(const UVManager& uvman) : solutions() {
    this->loadPreference();
    //this->loadSolution(); Chargement des solutions déja existante et de leur état.
}

void Completion::affichageSolution(){
    for (unsigned int i=0; i<solutions.size();i++){
        cout<<"SOlUTION : "<<endl;
        solutions[i].affichage();
    }
}

void Completion::loadPreference()
{
    QDomDocument doc = this->chargerXml("dossiers/enormand/preferences.xml");

    QDomElement racine = doc.documentElement();
    racine = racine.firstChildElement();

    while(!racine.isNull())
    {
        if(racine.tagName() == "preference")
        {
            QString tempCode, tempPref;
            QDomElement unElement=racine.firstChildElement();

           while(!unElement.isNull())
            {
                if(unElement.tagName() == "code")
                {
                    tempCode = unElement.text();
                }
                else if(unElement.tagName() == "pref")
                {
                    tempPref = unElement.text();
                }
                unElement = unElement.nextSiblingElement();
            }
            this->ajouterPreference(tempCode,tempPref);
        }

        racine = racine.nextSiblingElement();
    }}


void Completion::savePreference()
{
    QDomDocument doc = this->creerXml();
    QDomElement root = doc.createElement("preferences");
    doc.appendChild(root);

    for (map<QString,QString>::const_iterator it = preferences.begin(); it != preferences.end(); it++)
    {
        QDomElement preference = doc.createElement("preference");
        root.appendChild(preference);
        QDomElement code = doc.createElement("code");
        preference.appendChild(code);
        QDomText codeText = doc.createTextNode(it->first);
        code.appendChild(codeText);
        QDomElement pref = doc.createElement("pref");
        preference.appendChild(pref);
        QDomText prefText = doc.createTextNode(it->second);
        pref.appendChild(prefText);
    }

    this->sauvegarderXml("dossiers/enormand/preferences.xml", doc);
}
