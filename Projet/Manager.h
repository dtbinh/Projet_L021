#ifndef COMPOSANT_H
#define COMPOSANT_H

#include <QString>
#include <QtXml>
#include "Exception.h"

class Manager
{
protected:
    QString fichier;

    QDomDocument charger_xml(const QString& fichier);
    QDomDocument creer_xml();
    void sauvegarder_xml(const QString& fichier, const QDomDocument& document);

public:
    Manager(const QString& f = ""): fichier(f) {}

    const QString& getFichier() { return fichier; }
    void setFichier(const QString& f) { fichier = f; }
};

#endif // COMPOSANT_H
