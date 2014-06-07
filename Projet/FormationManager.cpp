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

void FormationManager::save(){
    QDomDocument doc = formations.save_xml();
    QDomElement root = doc.createElement("xml");
    doc.appendChild(root);

    for (map<QString,Formation>::const_iterator it = formations.begin(); it != formations.end(); it++)
    {
        QDomElement formation = doc.createElement("formation");
        root.appendChild(formation);
        QDomElement code = doc.createElement("code");
        formation.appendChild(code);
        QDomText codeText = doc.createTextNode(it->second.getCode());
        code.appendChild(codeText);
        QDomElement nom = doc.createElement("nom");
        formation.appendChild(nom);
        QDomText nomText = doc.createTextNode(it->second.getNom());
        nom.appendChild(nomText);
        std::vector<const Credits*> tempcredits= it->second.getCredits();
        for(unsigned int i=0;i<tempcredits.size();++i){
            QDomElement credits = doc.createElement("credits");
            formation.appendChild(credits);
            QDomText creditText = doc.createTextNode(tempcredits[i]->getNom());
            credits.appendChild(creditText);
        }
        std::vector<const Formation*> tempspecialite= it->second.getSpecialites();
        for(unsigned int i=0;i<tempspecialite.size();++i){
            QDomElement specialite = doc.createElement("specialite");
            formation.appendChild(specialite);
            QDomText specialiteText = doc.createTextNode(tempspecialite[i]->getCode());
            specialite.appendChild(specialiteText);
        }

        //Les uvs doivent ils apparaitre dans le fichier de formation. On avait dit que non mais j'ai un doute
        /*std::vector<const UV*> tempUV= it->second.getUVs();
        for(unsigned int i=0;i<tempUV.size();++i){
            QDomElement uv = doc.createElement("uvs");
            formation.appendChild(uv);
            QDomText UVText = doc.createTextNode(tempUV[i]->getCode());
            uv.appendChild(UVText);
        }*/
    }
    QFile file( "formation_utc.xml" );
    file.open(QIODevice::WriteOnly);
    QTextStream ts(&file);
    int indent = 2;
    doc.save(ts, indent);
}
