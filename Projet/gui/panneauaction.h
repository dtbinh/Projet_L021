#ifndef PANNEAUACTION_H
#define PANNEAUACTION_H

#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QPushButton>
#include "core/Observer.h"
#include "applicationcomposant.h"

namespace Ui {
class PanneauAction;
}

class PanneauAction : public QWidget, public ApplicationComposant
{
    Q_OBJECT

public:
    explicit PanneauAction(Application* a, Observer* obs, QWidget *parent = 0);
    ~PanneauAction();

    void setPanneau(const QString &q, const QString& panneau, const QString& c = "");

private slots:
    void categorieModifier_clicked();
    void creditsModifier_clicked();
    void formationModifier_clicked();
    void noteModifier_clicked();
    void periodeModifier_clicked();
    void uvModifier_clicked();
    void inscriptionModifier_clicked();
    void formationDossierModifier_clicked();
    void preferenceModifier_clicked();

private:
    Ui::PanneauAction *ui;
    Observer* fenconfiguration;
    QString code;
    QString quoi;

    QMap<QString, QWidget*> panneaux;

    QLineEdit* categorieCode;
    QLineEdit* categorieNom;
    QPushButton* categorieModifier;

    QLineEdit* creditsCode;
    QSpinBox* creditsNombre;
    QComboBox* creditsCategorie;
    QPushButton* creditsModifier;

    QLineEdit* formationCode;
    QLineEdit* formationNom;
    QPushButton* formationModifier;

    QLineEdit* noteNote;
    QLineEdit* noteMention;
    QPushButton* noteModifier;

    QLineEdit* periodeNom;
    QSpinBox* periodeAnnee;
    QPushButton* periodeModifier;

    QLineEdit* uvCode;
    QLineEdit* uvNom;
    QComboBox* uvCategorie;
    QPushButton* uvModifier;

    QLineEdit* inscriptionCode;
    QComboBox* inscriptionPeriode;
    QComboBox* inscriptionFormation;
    QPushButton* inscriptionModifier;

    QComboBox* formationDossierCode;
    QPushButton* formationDossierModifier;

    QComboBox* preferenceCode;
    QComboBox* preferencePref;
    QPushButton* preferenceModifier;

    QWidget *creerPanneau(const QString& panneau);
    void cacherPanneaux();
};

#endif // PANNEAUACTION_H
