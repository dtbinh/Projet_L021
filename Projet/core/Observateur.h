///
/// \file Observateur.h
/// \brief Observateur
/// \author Erwan Normand,Nicolas Szewe
/// \date 15 juin 2014
///

#ifndef OBSERVATEUR_H
#define OBSERVATEUR_H

#include <QString>

class Observateur
{
public:
    Observateur() {}
    virtual void notification(const QString& quoi) = 0;
};

#endif // OBSERVATEUR_H
