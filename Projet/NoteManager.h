///
/// \file NoteManager.h
/// \brief Manager des Notes.
/// \author Erwan Normand
/// \date 07 juin 2014
///

#ifndef NOTEMANAGER_H
#define NOTEMANAGER_H

#include <QString>
#include <QtXml>
#include "Manager.h"
#include "Note.h"
#include "Exception.h"

class NoteManager
{
private:
    Manager<Note> notes;

public:
    NoteManager(): notes() {}
    void load();
    void save();
    Note& getNote(const QString& note) { return notes.get(note); }
    const Note& getNote(const QString& note) const { return notes.get(note); }
    void ajouterNote(const QString& note, const QString& mention) { notes.ajouter(note, Note(note, mention)); }
    void retirerNote(const QString& note) { notes.retirer(note); }
};

#endif // NOTEMANAGER_H
