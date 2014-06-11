#ifndef COMPOSANT_H
#define COMPOSANT_H

#include <QString>
#include <QtXml>
#include "Exception.h"

class Manager
{
protected:
    QString fichier;

    QDomDocument load_xml(const QString& fichier);
    QDomDocument create_xml();
    void save_xml(const QString& fichier, const QDomDocument& document);

public:
    Manager(const QString& f = ""): fichier(f) {}

    const QString& getFichier() { return fichier; }
    void setFichier(const QString& f) { fichier = f; }
};

#endif // COMPOSANT_H
