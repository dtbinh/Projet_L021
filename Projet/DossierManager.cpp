#include "DossierManager.h"

using namespace std;

void DossierManager::load(QString& fichier,const FormationManager& forman,const PeriodeManager& periodeman)
{
    std::vector<const Formation*> tempformations;
    std::vector<const Inscription*> tempinscriptions;
    QString tempForma="NULL"; QString tempInscri="NULL";
    QDomDocument doc = load_xml(fichier);

    QDomElement racine = doc.documentElement();
    racine = racine.firstChildElement();

    while(!racine.isNull())
    {
        if(racine.tagName() == "dossier")
        {
            QString tempNom, tempPrenom,tempFormation,tempUv,tempNote;
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
                else if(unElement.tagName() == "formations"){
                    tempForma = unElement.text();
                    tempformations.push_back(&forman.getFormation(tempForma));
                }
                else if(unElement.tagName() == "inscription"){
                    QDomElement filsElement = unElement.firstChildElement();
                    while(!filsElement.isNull())
                    {
                    if(filsElement.tagName()=="code"){
                        tempInscri=filsElement.text();
                        cout<<tempInscri.toStdString()<<endl;
                    }
                    else if(filsElement.tagName() =="formation"){
                        tempFormation=filsElement.text();
                        //cout<<"Formation : " <<tempFormation.toStdString()<<endl;
                    }
                    else if(filsElement.tagName() == "uv"){
                        QDomElement filsUV=filsElement.firstChildElement();
                        while(!filsUV.isNull()){
                            if(filsUV.tagName()=="codeUV"){
                                tempUv=filsUV.text();
                                cout<<tempUv.toStdString()<<endl;
                            }
                            if(filsUV.tagName()=="note"){
                                tempNote=filsUV.text();
                                cout<<tempNote.toStdString()<<endl;
                            }
                            filsUV=filsUV.nextSiblingElement();
                        }
                    }
                    filsElement= filsElement.nextSiblingElement();
                    }
                    //Inscription temp(periodeman.getPeriode(tempInscri),forman.getFormation(tempFormation));
                    //tempinscriptions.push_back(&temp);
                }
                unElement = unElement.nextSiblingElement();

            }
            QString login=this->ajouterDossier(tempNom,tempPrenom);
            if (tempForma!="NULL"){
                for (unsigned int i = 0; i < tempformations.size(); i++)
                {
                   // this->getDossier(login).ajouterFormation(*tempformations[i]);
                }
                tempformations.clear();
                tempForma="NULL";
            }
            if (tempInscri!="NULL"){
                for(unsigned int i=0; i < tempinscriptions.size(); i++){
                    //this->getDossier(login).ajouterInscription(*tempinscriptions[i]);
                }
                tempinscriptions.clear();
                tempInscri="NULL";
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
    const Factory<const Formation> tempformation= this->getDossier(login).getFormations();
    for(unsigned int i=0;i<tempformation.size();++i){
        QDomElement formation = doc.createElement("formations");
        dossier.appendChild(formation);
        QDomText formationText = doc.createTextNode(tempformation[i]->getCode());
        formation.appendChild(formationText);
    }
    const Factory<const Inscription> tempinscription= this->getDossier(login).getInscriptions();
    for(unsigned int i=0;i<tempinscription.size();++i){
        QDomElement inscription = doc.createElement("inscription");
        dossier.appendChild(inscription);
        QDomElement codeinscription=doc.createElement("code");
        inscription.appendChild(codeinscription);
        QDomText inscriptionText = doc.createTextNode(tempinscription[i]->getPeriode().getCode());
        codeinscription.appendChild(inscriptionText);
        QDomElement formation = doc.createElement("formation");
        inscription.appendChild(formation);
        QDomText formationText=doc.createTextNode(tempinscription[i]->getFormation().getCode());
        formation.appendChild(formationText);
        std::map<QString, UV> tempUV= tempinscription[i]->getUVs();
        for (map<QString,UV>::const_iterator it = tempUV.begin(); it != tempUV.end(); it++)
        {
            QDomElement uv= doc.createElement("uv");
            inscription.appendChild(uv);
            QDomElement codeuv=doc.createElement("codeUV");
            uv.appendChild(codeuv);
            QDomText uvText=doc.createTextNode(it->second.getCode());
            codeuv.appendChild(uvText);
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
