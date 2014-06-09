#include "Manager.h"

using namespace std;

QDomDocument Manager::load_xml(const QString& fichier)
{
    QFile file(fichier);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        throw Exception("Impossible d'ouvrir le fichier " + fichier + ".");
    }

    QDomDocument doc;
    doc.setContent(&file, false);

    return doc;
}

QDomDocument Manager::save_xml()
{
    QDomDocument doc;
    QDomNode xmlNode = doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");

    doc.insertBefore(xmlNode, doc.firstChild());

    return doc;
}
