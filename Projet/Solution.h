#ifndef SOLUTION_H
#define SOLUTION_H

#include <QString>
#include <QtXml>
#include "Application.h"
#include "Dossier.h"

class Solution
{
    QString code;
    Factory<Inscription> strategie;
public:
    Solution(const QString& c,const Dossier& D,const CategorieManager& catman);
    Solution();
};

#endif // SOLUTION_H
