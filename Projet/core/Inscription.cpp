﻿#include "Inscription.h"

using namespace std;

void Inscription::ajouterUV(const UV& uv)
{
    uvs.ajouter(uv.getCode(), uv);
    notes.ajouter(uv.getCode(), Note());
}

void Inscription::retirerUV(const QString& code)
{
    uvs.retirer(code);
    notes.retirer(code);
}
