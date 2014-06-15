///
/// \file Note.h
/// \brief Lors d'une inscription, chaque uv est associé à un résultat
/// \author Erwan Normand, Nicolas Szewe
/// \date 15 juin 2014
///

#ifndef NOTE_H
#define NOTE_H

#include <iostream>
#include <QString>

class Note
{
private:
    QString note;
    QString mention;

public:
    ///
    /// \fn Note
    /// \brief Constructeur de la classe Note
    /// \param n La note obtenue à l'UV
    /// \param m La mention associé à cette note
    ///
    Note(const QString& n = "EC", const QString& m = ""): note(n), mention(m) {}

    ///
    /// \fn getNote
    /// \brief Accesseur à la note de l'UV
    /// \return const QString& -> Référence sur la note obtenue
    ///
    const QString& getNote() const { return note; }

    ///
    /// \fn setNote
    /// \brief Pour modifier une note
    /// \param n La nouvelle note obtenue
    ///
    void setNote(const QString& n) { note = n; }

    ///
    /// \fn getMention
    /// \brief Accesseur à la mention de l'UV
    /// \return const QString& -> Référence sur la mention obtenue
    ///
    const QString& getMention() const { return mention; }

    ///
    /// \fn setMention
    /// \brief Pour modifier une mention
    /// \param m La nouvelle mention obtenue
    ///
    void setMention(const QString& m) {mention = m; }
};

#endif // NOTE_H
