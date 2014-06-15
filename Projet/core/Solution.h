///
/// \file Solution.h
/// \brief Objet Solution, construit une completion automatique
/// \author Erwan Normand,Nicolas Szewe
/// \date 15 juin 2014
///

#ifndef SOLUTION_H
#define SOLUTION_H

#include <QString>
#include <QtXml>
#include "Application.h"
#include "Factory.h"
#include "Dossier.h"

class Solution
{
    QString choix;
    std::vector<UV> strategie;
public:
    Solution(const Dossier& D,const CategorieManager& catman,std::map <QString,QString> preferences,const UVManager& uvman,const NoteManager& notman,bool activation);
    Solution(){}
    const QString& getChoix()const {return choix;}
    void setChoix(QString c) {choix=c;}
    const std::vector<UV>& getStrategie() const {return strategie;}
    void ajouterStrategie(const UV& c){strategie.push_back(c);}
    void affichage()const;

};

#endif // SOLUTION_H
