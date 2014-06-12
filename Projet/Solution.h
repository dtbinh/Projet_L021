#ifndef SOLUTION_H
#define SOLUTION_H

#include <QString>
#include <QtXml>
#include "DossierManager.h"
#include "UVManager.h"


class Solution
{
    QString code;
    Factory<Inscription> strategie;
public:
    Solution(const Dossier& D);
};

#endif // SOLUTION_H
