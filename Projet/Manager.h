#ifndef COMPOSANT_H
#define COMPOSANT_H

#include <QString>
#include <QtXml>
#include "Exception.h"

class Manager
{
public:
    Manager() {}

    QDomDocument load_xml(const QString& file);
    QDomDocument save_xml();
};

#endif // COMPOSANT_H
