///
/// \file Note.h
/// \brief Les cours des inscriptions obtiennent une note à l'issue de la période.
/// \author Erwan Normand
/// \date 07 juin 2014
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
    Note(const QString& n = "EC", const QString& m = ""): note(n), mention(m) {}

    const QString& getNote() const { return note; }
    const QString& getMention() const { return mention; }

    void setNote(const QString& n) { note = n; }
    void setMention(const QString& m) {mention = m; }
};

#endif // NOTE_H
