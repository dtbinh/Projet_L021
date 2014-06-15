#ifndef FENCONFIGURATION_H
#define FENCONFIGURATION_H

#include <QWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QComboBox>
#include <QMessageBox>
#include "core/Observer.h"
#include "applicationcomposant.h"
#include "panneauaction.h"

namespace Ui {
class FenConfiguration;
}

class FenConfiguration : public QWidget, public ApplicationComposant, public Observer
{
    Q_OBJECT

public:
    explicit FenConfiguration(Application* a, QWidget *parent = 0);
    ~FenConfiguration();
    void notification(const QStringList& quoi);

private slots:
    void on_categorie_clicked(const QModelIndex& index) { setPanneau("categorie", index); }
    void on_credits_clicked(const QModelIndex& index) { setPanneau("credits", index); }
    void on_formation_clicked(const QModelIndex& index) { setPanneau("formation", index); }
    void on_note_clicked(const QModelIndex& index) { setPanneau("note", index); }
    void on_periode_clicked(const QModelIndex& index) { setPanneau("periode", index); }
    void on_uv_clicked(const QModelIndex& index) { setPanneau("uv", index); }

private:
    Ui::FenConfiguration *ui;
    PanneauAction *panneauAction;

    void remplirCategorie();
    void remplirCredits();
    void remplirFormation();
    void remplirNote();
    void remplirPeriode();
    void remplirUV();

    void setPanneau(const QString& panneau, const QModelIndex& index);
};

#endif // FENCONFIGURATION_H
