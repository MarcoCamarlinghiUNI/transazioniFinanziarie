#ifndef TRANSAZIONIFINANZIARIE_CONTO_H
#define TRANSAZIONIFINANZIARIE_CONTO_H

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <ctime>
#include "transazione.h"

using namespace std;

class conto {
public:
    explicit conto(int id, string dataAperturaz, string titolarez);
    virtual ~conto() = default;

    vector<transazione*> letturaTransazioni(int idContoz);
    tm convertiStringInData(string s);

//private:
    int idConto;
    tm dataApertura;
    string titolare;

    vector<transazione*> listaTransazioni;
    unsigned int prossimoIdTransazione;
};


#endif //TRANSAZIONIFINANZIARIE_CONTO_H
