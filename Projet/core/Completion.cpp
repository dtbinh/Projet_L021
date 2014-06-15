#include "Completion.h"
#include <string>
#include <iostream>

using namespace std;

Completion::Completion(const QString &cf, const QString &f, const UVManager& uvman) : Manager(cf,f), solutions()
{
    fichier_preferences = "preferences.xml";
    this->chargerPreference();
    //this->chargerSolution(uvman);
}

void Completion::chargerSolution(const UVManager& uvman)
{
    QDomDocument doc = this->chargerXml(chemin_fichier + "/" + fichier);
    QDomElement racine = doc.documentElement();
    racine = racine.firstChildElement();

    while(!racine.isNull())
    {
        Solution temp;
        unsigned int i=0;
        if(racine.tagName() == "solution")
       {
            QDomElement unElement = racine.firstChildElement();
            QString strCode,choix;

            while(!unElement.isNull())
            {
                if(unElement.tagName() == "uv")
                {
                        strCode = unElement.text();
                        temp.ajouterUVStrategie(uvman.getUV(strCode));
                }
                else if (unElement.tagName()=="choix")
                    choix=unElement.text();
                unElement = unElement.nextSiblingElement();
            }
            temp.setChoix(choix);

        }
        solutions.push_back(temp);
        racine = racine.nextSiblingElement();
        i++;

}}

void Completion::sauvegarderSolution()
{
    QDomDocument doc = this->creerXml();
    QDomElement root = doc.createElement("Solutions");
    doc.appendChild(root);

    for (unsigned int i=0;i<solutions.size();i++)
    {
        QDomElement solution = doc.createElement("solution");
        root.appendChild(solution);
        for(unsigned int j=0;j<solutions[i].getStrategie().size();j++){
            QDomElement uv = doc.createElement("uv");
             solution.appendChild(uv);
             QDomText codeUv = doc.createTextNode(solutions[i].getStrategie()[j].getCode());
             uv.appendChild(codeUv);
    }
    QDomElement choix=doc.createElement("choix");
    solution.appendChild(choix);
    QDomText textchoix=doc.createTextNode(solutions[i].getChoix());
    choix.appendChild(textchoix);
    this->sauvegarderXml(chemin_fichier + "/" + fichier, doc);
}}

void Completion::ajouterSolution(const Dossier& D,const CategorieManager& catman,const UVManager& uvman,const NoteManager& notman,bool activation){
    solutions.push_back(Solution(D,catman,this->preferences,uvman,notman,activation));
    unsigned int i = solutions.size()-1;
    solutions[i].affichage();
    cout<<"Souhaitez vous l'accepter?"<<endl;
    solutions[i].setChoix("Accepter");
    if (solutions[i].getChoix()=="Accepter"){
        sauvegarderSolution();
    }
}

void Completion::affichageSolution(){
    for (unsigned int i=0; i<solutions.size();i++){
        cout<<"SOlUTION : "<<endl;
        solutions[i].affichage();
    }
}

void Completion::chargerPreference()
{
    QDomDocument doc = this->chargerXml(chemin_fichier + "/" + fichier_preferences);

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


void Completion::sauvegarderPreference()
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

    this->sauvegarderXml(chemin_fichier + "/" + fichier_preferences, doc);
}
