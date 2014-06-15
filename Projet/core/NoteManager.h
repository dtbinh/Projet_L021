///
/// \file NoteManager.h
/// \brief Manager des Notes.
/// \author Erwan Normand,Nicolas Szewe
/// \date 15 juin 2014
///

#ifndef NOTEMANAGER_H
#define NOTEMANAGER_H

#include <QString>
#include <QtXml>
#include "Manager.h"
#include "Factory.h"
#include "Note.h"
#include "Exception.h"

class NoteManager : public Manager
{
private:
    Factory<Note> notes;

public:
    NoteManager(const QString& f = ""): Manager(f), notes() {}

    void charger();
    void sauvegarder();

    bool estVide() const { return notes.estVide(); }
    void vider() { notes.vider(); }

    const Factory<Note>& getNotes() const { return notes; }
    Note& getNote(const QString& note) { return notes.get(note); }
    const Note& getNote(const QString& note) const { return notes.get(note); }
    void ajouterNote(const QString& note, const QString& mention) { notes.ajouter(note, Note(note, mention)); }
    void retirerNote(const QString& note) { notes.retirer(note); }
};

#endif // NOTEMANAGER_H
