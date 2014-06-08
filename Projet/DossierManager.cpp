#include "DossierManager.h"

using namespace std;

void DossierManager::load(QString& fichier,const FormationManager& forman)
{
    std::vector<const Formation*> tempformations;
    QString tempForma="NULL";
    QDomDocument doc = load_xml(fichier);

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
                /*else if(unElement.tagName() == "inscription"){
                    tempInscri=unElement.text();
                    tempinscriptions.push_back()
                }
                */
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

void DossierManager::save(QString& fichier,QString& login)
{
    QDomDocument doc = save_xml();
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
    std::vector<const Formation*> tempformation= this->getDossier(login).getFormations();
    for(unsigned int i=0;i<tempformation.size();++i){
        QDomElement formation = doc.createElement("formation");
        dossier.appendChild(formation);
        QDomText formationText = doc.createTextNode(tempformation[i]->getCode());
        formation.appendChild(formationText);
    }
    std::vector<const Inscription*> tempinscription= this->getDossier(login).getInscriptions();
    for(unsigned int i=0;i<tempinscription.size();++i){
        QDomElement inscription = doc.createElement("inscription");
        dossier.appendChild(inscription);
        QDomText inscriptionText = doc.createTextNode(tempinscription[i]->getPeriode().getCode());
        inscription.appendChild(inscriptionText);
        QDomElement formation = doc.createElement("formation");
        inscription.appendChild(formation);
        QDomText formationText=doc.createTextNode(tempinscription[i]->getFormation().getCode());
        formation.appendChild(formationText);
        std::map<QString, UV> tempUV= tempinscription[i]->getUVs();
        for (map<QString,UV>::const_iterator it = tempUV.begin(); it != tempUV.end(); it++)
        {
            QDomElement uv= doc.createElement("uv");
            inscription.appendChild(uv);
            QDomText uvText=doc.createTextNode(it->second.getCode());
            uv.appendChild(uvText);
            QDomElement note=doc.createElement("note");
            uv.appendChild(note);
            QDomText notetext=doc.createTextNode(tempinscription[i]->getNotes().find(it->second.getCode())->second.getNote());
            note.appendChild(notetext);
         }
    }
    QFile file(fichier);
    file.open(QIODevice::WriteOnly);
    QTextStream ts(&file);
    int indent = 2;
    doc.save(ts, indent);
}
