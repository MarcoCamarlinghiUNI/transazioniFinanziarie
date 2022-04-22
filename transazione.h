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
                         const string &transazioneInUscitaz, const string &transazioneConciliataz);


    void setIdTransazione(int i);
    void setImporto(int i);
    void setControparte(string c);
    void setDataContabile(string d);
    void setTransazioneInUscita(bool b);
    void setTransazioneConciliata(bool b);

    int getIdTransazione();
    int getImporto();
    string getControparte();
    tm getDataContabile();
    bool getTransazioneInUscita();
    bool getTransazioneConciliata();

private:
    tm convertiStringInData(string s);

    int idTransazione;
    int importo;
    string controparte;         // chi riceve o invia il denaro
    tm dataContabile;
    bool transazioneInUscita;
    bool transazioneConciliata;
};


#endif //TRANSAZIONIFINANZIARIE_TRANSAZIONE_H
