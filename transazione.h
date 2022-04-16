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

    explicit transazione(int idTransazionez, int importoz, string contropartez, string dataContabilez,
                         string transazioneInUscitaFlagz, string transazioneConciliataFlagz);
    virtual ~transazione() = default;

    tm convertiStringInData(string s);
    static void setTransazioneConciliataFlag(transazione* t, bool b);

//private:
    int idTransazione;
    int importo;
    string controparte;         // chi riceve o invia il denaro
    tm dataContabile;
    bool transazioneInUscitaFlag;
    bool transazioneConciliataFlag;
};


#endif //TRANSAZIONIFINANZIARIE_TRANSAZIONE_H
