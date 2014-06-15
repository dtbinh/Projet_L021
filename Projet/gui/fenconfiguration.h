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
    void on_categorie_clicked(const QModelIndex& index) { setPanneau("categorie", "editer", index); }
    void on_credits_clicked(const QModelIndex& index) { setPanneau("credits", "editer", index); }
    void on_formation_clicked(const QModelIndex& index) { setPanneau("formation", "editer", index); }
    void on_note_clicked(const QModelIndex& index) { setPanneau("note", "editer", index); }
    void on_periode_clicked(const QModelIndex& index) { setPanneau("periode", "editer", index); }
    void on_uv_clicked(const QModelIndex& index) { setPanneau("uv", "editer", index); }

    void on_ajouterCategorie_clicked() { setPanneau("categorie", "ajouter"); }
    void on_ajouterCredits_clicked() { setPanneau("credits", "ajouter"); }
    void on_ajouterFormation_clicked() { setPanneau("formation", "ajouter"); }
    void on_ajouterNote_clicked() { setPanneau("note", "ajouter"); }
    void on_ajouterPeriode_clicked() { setPanneau("periode", "ajouter"); }
    void on_ajouterUV_clicked() { setPanneau("uv", "ajouter"); }

private:
    Ui::FenConfiguration *ui;
    PanneauAction *panneauAction;

    void remplirCategorie();
    void remplirCredits();
    void remplirFormation();
    void remplirNote();
    void remplirPeriode();
    void remplirUV();

    void setPanneau(const QString& panneau, const QString& quoi, const QModelIndex& index = QModelIndex());
};

#endif // FENCONFIGURATION_H
