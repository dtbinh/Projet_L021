#include "DossierManager.h"

using namespace std;

void DossierManager::load(QString& fichier,const FormationManager& forman)
{
    std::vector<const Formation*> tempformations;
    QString tempForma="NULL";
    QDomDocument doc = dossiers.load_xml(fichier);

    QDomElement racine = doc.documentElement();
    racine = racine.firstChildElement();

    while(!racine.isNull())
    {
        if(racine.tagName() == "dossier")
        {
            QString tempNom, tempPrenom;
            QDomElement unElement = racine.firstChildElement();

            while(!unElement.isNull())
            {
                if(unElement.tagName() == "nom")
                {
                    tempNom = unElement.text();
                }
                else if(unElement.tagName() == "prenom")
                {
                    tempPrenom = unElement.text();
                }
                else if(unElement.tagName() == "formation"){
                    tempForma = unElement.text();
                    tempformations.push_back(&forman.getFormation(tempForma));
                }
                unElement = unElement.nextSiblingElement();
            }
            QString login=this->ajouterDossier(tempNom,tempPrenom);
            if (tempForma!="NULL"){
                for (unsigned int i = 0; i < tempformations.size(); i++)
                {
                    this->getDossier(login).ajouterFormation(*tempformations[i]);
                }
                tempformations.clear();
                tempForma="NULL";
            }
        }
        racine = racine.nextSiblingElement();
    }
}

void DossierManager::save(QString& fichier,QString& login){
    QDomDocument doc = dossiers.save_xml();
    QDomElement root = doc.createElement("xml");
    doc.appendChild(root);
    QDomElement dossier = doc.createElement("dossier");
    root.appendChild(dossier);
    QDomElement nom = doc.createElement("nom");
    dossier.appendChild(nom);
    QDomText nomText = doc.createTextNode(this->getDossier(login).getNom());
    nom.appendChild(nomText);
    QDomElement prenom = doc.createElement("prenom");
    dossier.appendChild(prenom);
     QDomText prenomText = doc.createTextNode(this->getDossier(login).getPrenom());
    prenom.appendChild(prenomText);
    QFile file(fichier);
    file.open(QIODevice::WriteOnly);
    QTextStream ts(&file);
    int indent = 2;
    doc.save(ts, indent);
}



