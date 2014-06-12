#include "Completion.h"
#include <string>
#include <iostream>

using namespace std;

Completion::Completion(const UVManager& uvman) : solutions() {
    this->loadPreference(uvman);
}

void Completion::loadPreference(const UVManager& uvman){
        QFile file("dossiers/enormand/preferences.xml");
        if (!file.open(QFile::ReadOnly | QFile::Text)) {
            throw Exception("Impossible d'ouvrir le fichier " + fichier + ".");
        }

        QDomDocument doc;
        doc.setContent(&file, false);
        QDomElement racine = doc.documentElement();
        racine = racine.firstChildElement();

        while(!racine.isNull())
        {
            if(racine.tagName() == "preference")
            {
                QString tempCode, tempPref;
                QDomElement unElement = racine.firstChildElement();

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
                this->ajouterPreference(uvman,tempCode,tempPref);
            }

            racine = racine.nextSiblingElement();
        }
}

void Completion::savePreference(){
        QDomDocument doc = this->create_xml();
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

        QFile file("dossiers/enormand/preferences.xml");
        if (!file.open(QIODevice::WriteOnly)) {
            throw Exception("Impossible d'ouvrir le fichier " + fichier + ".");
        }
        QTextStream ts(&file);
        int indent = 2;
        doc.save(ts, indent);
    }
