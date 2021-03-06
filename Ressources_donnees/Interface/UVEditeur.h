﻿#ifndef UVEDITEUR_H
#define UVEDITEUR_H
#include <QWidget>
#include <QCheckBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QSpinBox>
#include <QComboBox>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include "UTProfiler.h"


class UVEditeur : public QWidget{ Q_OBJECT
    UV& uv;
    QLineEdit* code;
    QLabel* codeLabel;
    QTextEdit* titre;
    QLabel* titreLabel;
    QSpinBox* credits;
    QLabel* creditsLabel;
    QComboBox* categorie;
    QLabel* categorieLabel;
    QLabel* ouvertureLabel;
    QCheckBox* automne;
    QCheckBox* printemps;
    QPushButton* sauver;
    QPushButton* annuler;
    QVBoxLayout* couche;
    QHBoxLayout* coucheH1;
    QHBoxLayout* coucheH2;
    QHBoxLayout* coucheH3;
    QHBoxLayout* coucheH4;
public:
    explicit UVEditeur(UV& uvToEdit, QWidget *parent = 0);
    signals:
    public slots:
        void sauverUV();
    private slots:
        void activerSauver(QString str="");
};


#endif // UVEDITEUR_H
