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

    vector<const transazione*> letturaTransazioni(int idContoz);
    tm convertiStringInData(string s);
    int trovaProssimoIdTransazione ();

    const transazione* aggiungiTransazione(int importoz, string contropartez, string transazioneInUscitaFlagz);
    void eliminaTransazione(int idTransazioneDaEliminare);

//private:
    int idConto;
    tm dataApertura;
    string titolare;

    vector<const transazione*> listaTransazioni;
    int prossimoIdTransazione;
};


#endif //TRANSAZIONIFINANZIARIE_CONTO_H
