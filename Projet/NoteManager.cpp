#include "NoteManager.h"

using namespace std;

void NoteManager::load()
{
    QDomDocument doc = load_xml("note_utc.xml");

    QDomElement racine = doc.documentElement();
    racine = racine.firstChildElement();

    while(!racine.isNull())
    {
        if(racine.tagName() == "note")
        {
            QString tempNote, tempMention;
            QDomElement unElement = racine.firstChildElement();

            while(!unElement.isNull())
            {
                if(unElement.tagName() == "code")
                {
                    tempNote = unElement.text();
                }
                else if(unElement.tagName() == "mention")
                {
                    tempMention = unElement.text();
                }
                unElement = unElement.nextSiblingElement();
            }

            this->ajouterNote(tempNote,tempMention);
        }

        racine = racine.nextSiblingElement();
    }
}


void NoteManager::save(){

    QDomDocument doc = save_xml();
    QDomElement root = doc.createElement("xml");
    doc.appendChild(root);

    for (map<QString,Note>::const_iterator it = notes.begin(); it != notes.end(); it++)
    {
        QDomElement note = doc.createElement("note");
        root.appendChild(note);
        QDomElement code = doc.createElement("code");
        note.appendChild(code);
        QDomText nomText = doc.createTextNode(it->second.getNote());
        code.appendChild(nomText);
        QDomElement mention = doc.createElement("mention");
        note.appendChild(mention);
        QDomText mentionText = doc.createTextNode(it->second.getMention());
        mention.appendChild(mentionText);
    }
    QFile file( "note_utc.xml" );
    file.open(QIODevice::WriteOnly);
    QTextStream ts(&file);
    int indent = 2;
    doc.save(ts, indent);
}

