#include "Manager.h"

using namespace std;

QDomDocument Manager::chargerXml(const QString& fichier)
{
    QFile file(fichier);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        throw Exception("Impossible d'ouvrir le fichier " + fichier + ".");
    }

    QDomDocument doc;
    doc.setContent(&file, false);

    return doc;
}

QDomDocument Manager::creerXml()
{
    QDomDocument doc;
    QDomNode xmlNode = doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");

    doc.insertBefore(xmlNode, doc.firstChild());

    return doc;
}

void Manager::sauvegarderXml(const QString& fichier, const QDomDocument& document)
{
    QFile file(fichier);
    if (!file.open(QIODevice::WriteOnly)) {
        throw Exception("Impossible d'ouvrir le fichier " + fichier + ".");
    }

    QTextStream ts(&file);
    int indent = 2;
    document.save(ts, indent);
}
