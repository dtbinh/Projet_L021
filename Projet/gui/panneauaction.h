#ifndef PANNEAUACTION_H
#define PANNEAUACTION_H

#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QPushButton>
#include "core/Observateur.h"
#include "applicationcomposant.h"

namespace Ui {
class PanneauAction;
}

class PanneauAction : public QWidget, public ApplicationComposant
{
    Q_OBJECT

public:
    explicit PanneauAction(Application* a, Observateur* obs, QWidget *parent = 0);
    ~PanneauAction();

    void setPanneau(const QString& panneau, const QString& c);

private slots:
    void categorieModifier_clicked();
    void creditsModifier_clicked();
    void formationModifier_clicked();
    void noteModifier_clicked();
    void periodeModifier_clicked();
    void uvModifier_clicked();

private:
    Ui::PanneauAction *ui;
    Observateur* observateur;
    QString code;

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

    QWidget *creerPanneau(const QString& panneau);
    void cacherPanneaux();
};

#endif // PANNEAUACTION_H
