#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QComboBox>
#include "applicationcomposant.h"

namespace Ui {
class Configuration;
}

class Configuration : public QWidget, public applicationcomposant
{
    Q_OBJECT

public:
    explicit Configuration(Application* a, QWidget *parent = 0);
    ~Configuration();

private:
    Ui::Configuration *ui;

    void remplirCategorie();
    void remplirCredits();
    void remplirFormation();
    void remplirNote();
    void remplirPeriode();
    void remplirUV();
};

#endif // CONFIGURATION_H
