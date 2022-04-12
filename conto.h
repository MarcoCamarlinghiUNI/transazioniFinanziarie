#ifndef TRANSAZIONIFINANZIARIE_CONTO_H
#define TRANSAZIONIFINANZIARIE_CONTO_H

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <ctime>
#include "transazione.h"

using namespace std;

class conto {
private:
    unsigned int idConto;
    tm dataApertura;
    string titolare;

    unsigned int prossimoIdTransazione;
};


#endif //TRANSAZIONIFINANZIARIE_CONTO_H
