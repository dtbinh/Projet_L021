#include "AbstractManager.h"

using namespace std;

QDomDocument AbstractManager::load_xml(const QString& file)
{
    QFile fichier(file);
    if (!fichier.open(QFile::ReadOnly | QFile::Text)) {
        throw Exception("Impossible d'ouvrir le fichier.");
    }

    QDomDocument doc;
    doc.setContent(&fichier, false);

    return doc;
}
