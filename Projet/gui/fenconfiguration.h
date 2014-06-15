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
    explicit FenConfiguration(Application* a, Observer *obs, QWidget *parent = 0);
    ~FenConfiguration();
    void notification(const QStringList& quoi);

private slots:
    void on_categorie_clicked(const QModelIndex& index) { setPanneau("editer", "categorie", index); }
    void on_credits_clicked(const QModelIndex& index) { setPanneau("editer", "credits", index); }
    void on_formation_clicked(const QModelIndex& index) { setPanneau("editer", "formation", index); }
    void on_note_clicked(const QModelIndex& index) { setPanneau("editer", "note", index); }
    void on_periode_clicked(const QModelIndex& index) { setPanneau("editer", "periode", index); }
    void on_uv_clicked(const QModelIndex& index) { setPanneau("editer", "uv", index); }

    void on_ajouterCategorie_clicked() { setPanneau("ajouter", "categorie"); }
    void on_ajouterCredits_clicked() { setPanneau("ajouter", "credits"); }
    void on_ajouterFormation_clicked() { setPanneau("ajouter", "formation"); }
    void on_ajouterNote_clicked() { setPanneau("ajouter", "note"); }
    void on_ajouterPeriode_clicked() { setPanneau("ajouter", "periode"); }
    void on_ajouterUV_clicked() { setPanneau("ajouter", "uv"); }

private:
    Ui::FenConfiguration *ui;
    Observer* mainwindow;

    void remplirCategorie();
    void remplirCredits();
    void remplirFormation();
    void remplirNote();
    void remplirPeriode();
    void remplirUV();

    void setPanneau(const QString& quoi, const QString& panneau, const QModelIndex& index = QModelIndex());
};

#endif // FENCONFIGURATION_H
