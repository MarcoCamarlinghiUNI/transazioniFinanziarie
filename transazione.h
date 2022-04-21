#ifndef TRANSAZIONIFINANZIARIE_TRANSAZIONE_H
#define TRANSAZIONIFINANZIARIE_TRANSAZIONE_H

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <ctime>
using namespace std;

class transazione {
public:
    transazione();
    transazione(int idTransazionez, int importoz, const string &contropartez, const string &dataContabilez,
                         const string &transazioneInUscitaFlagz, const string &transazioneConciliataFlagz);

    tm convertiStringInData(string s);      //passare per riferimento?
    void setTransazioneConciliataFlag(bool b);


    int idTransazione;
    int importo;
    string controparte;         // chi riceve o invia il denaro
    tm dataContabile;
    bool transazioneInUscitaFlag;
    bool transazioneConciliataFlag;
};


#endif //TRANSAZIONIFINANZIARIE_TRANSAZIONE_H
