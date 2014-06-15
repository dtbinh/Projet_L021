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

///
/// \class NoteManager
/// \brief Le manager des Notes
///
class NoteManager : public Manager
{
private:
    Factory<Note> notes;

public:
    ///
    /// \fn NoteManager
    /// \brief Constructeur du manager de Note. Initialise la map notes.
    /// \param f Le fichier d'intialiation des notes
    ///
    NoteManager(const QString& f = ""): Manager(f), notes() {}

    ///
    /// \fn charger
    /// \brief Chargement du fichier xml
    ///
    void charger();

    ///
    /// \fn sauvegarder
    /// \brief Sauvegarde du fichier xml
    ///
    void sauvegarder();

    ///
    /// \fn estVide
    /// \brief Teste si le notes manager contient des notes
    /// \return bool
    ///
    bool estVide() const { return notes.estVide(); }

    ///
    /// \fn vider
    /// \brief Vide le notes manager de ces notes
    ///
    void vider() { notes.vider(); }

    ///
    /// \fn getNotes
    /// \brief Permet d'obtenir l'ensemble des notes contenues dans le manager
    /// \return const Factory<Note>& -> ensemble des notes
    ///
    const Factory<Note>& getNotes() const { return notes; }

    ///
    /// \fn getNote
    /// \brief Permet d'obtenir une note particuliere de l'ensemble des notes du manager
    /// \param note Note a obtenir
    /// \return Note& Reference vers la note
    ///
    Note& getNote(const QString& note) { return notes.get(note); }

    ///
    /// \fn getNote
    /// \brief Permet d'obtenir une note particuliere de l'ensemble des notes du manager
    /// \param note Note a obtenir
    /// \return const Note& Reference vers la note
    ///
    const Note& getNote(const QString& note) const { return notes.get(note); }

    ///
    /// \fn ajouterNote
    /// \brief Pour ajouter une note au manager
    /// \param note Note de la note a ajouter
    /// \param mention Mention de la note a ajouter
    ///
    void ajouterNote(const QString& note, const QString& mention) { notes.ajouter(note, Note(note, mention)); }

    ///
    /// \fn retirerNote
    /// \brief Pour retirer une note du manager
    /// \param code Code de la note a retirer
    ///
    void retirerNote(const QString& note) { notes.retirer(note); }
};

#endif // NOTEMANAGER_H
