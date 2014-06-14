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
    Solution(const Dossier& D,const CategorieManager& catman,std::map <QString,QString> preferences,const UVManager& uvman,bool activation);
    Solution(){}
    const QString& getChoix()const {return choix;}
    void setChoix(QString c) {choix=c;}
    const std::vector<UV>& getStrategie() const {return strategie;}
    void affichage()const;

};

#endif // SOLUTION_H
