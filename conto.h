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
    virtual ~conto() {}

    tm convertiStringInData(string s);

//private:
    int idConto;
    tm dataApertura;
    string titolare;

    unsigned int prossimoIdTransazione;
};


#endif //TRANSAZIONIFINANZIARIE_CONTO_H
