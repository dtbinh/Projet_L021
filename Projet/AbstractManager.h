///
/// \file AbstractManager.h
/// \brief Composant de base permettant différentes opérations
/// \author Erwan Normand
/// \date 05 juin 2014
///

#ifndef ABSTRACTMANAGER_H
#define ABSTRACTMANAGER_H

#include <QtXml>
#include "Exception.h"

class AbstractManager
{
public:
    QDomDocument load_xml(const QString& file);
};

#endif // ABSTRACTMANAGER_H
