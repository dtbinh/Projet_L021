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
    Factory<Formation> tempformation= this->getDossier(login).getFormations();
    for(map<QString,Formation>::const_iterator it = tempformation.begin(); it != tempformation.end(); it++)
    {
        QDomElement formation = doc.createElement("formations");
        dossier.appendChild(formation);
        QDomText formationText = doc.createTextNode(it->second.getCode());
        formation.appendChild(formationText);
    }
    Factory<Inscription> tempinscription= this->getDossier(login).getInscriptions();
    for(map<QString,Inscription>::const_iterator it = tempinscription.begin(); it != tempinscription.end(); it++)
    {
        QDomElement inscription = doc.createElement("inscription");
        dossier.appendChild(inscription);
        QDomElement codeinscription=doc.createElement("code");
        inscription.appendChild(codeinscription);
        QDomText inscriptionText = doc.createTextNode(it->second.getPeriode().getCode());
        codeinscription.appendChild(inscriptionText);
        QDomElement formation = doc.createElement("formation");
        inscription.appendChild(formation);
        QDomText formationText=doc.createTextNode(it->second.getFormation().getCode());
        formation.appendChild(formationText);
        Factory<UV> tempUV= it->second.getUVs();
        for (map<QString,UV>::const_iterator ituv = tempUV.begin(); ituv != tempUV.end(); ituv++)
        {
            QDomElement uv= doc.createElement("uv");
            inscription.appendChild(uv);
            QDomElement codeuv=doc.createElement("codeUV");
            uv.appendChild(codeuv);
            QDomText uvText=doc.createTextNode(ituv->second.getCode());
            codeuv.appendChild(uvText);
            QDomElement note=doc.createElement("note");
            uv.appendChild(note);
            QDomText notetext=doc.createTextNode(it->second.getNotes().find(ituv->second.getCode())->second.getNote());
            note.appendChild(notetext);
         }
    }
    QFile file(fichier);
    file.open(QIODevice::WriteOnly);
    QTextStream ts(&file);
    int indent = 2;
    doc.save(ts, indent);
}
