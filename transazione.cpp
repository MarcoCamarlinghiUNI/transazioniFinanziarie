#include "transazione.h"

transazione::transazione(int idTransazionez, int importoz, const string &contropartez, const string &dataContabilez,
                         const string &transazioneInUscitaFlagz, const string &transazioneConciliataFlagz) {
    idTransazione = idTransazionez;
    importo = importoz;
    controparte = contropartez;
    dataContabile = convertiStringInData(dataContabilez);

    if (transazioneInUscitaFlagz == "1"){
        transazioneInUscita = true;
    } else {
        transazioneInUscita = false;
    }

    if (transazioneConciliataFlagz == "1"){
        transazioneConciliata = true;
    } else {
        transazioneConciliata = false;
    }
}

tm transazione::convertiStringInData(string s) {
    tm data;

    std::replace(s.begin(), s.end(), '-', ' ');

    vector<int> array;
    stringstream ss(s);
    int temp;
    while (ss >> temp)
        array.push_back(temp);

    data.tm_mday = array[0];
    data.tm_mon = array[1];
    data.tm_year = array[2];

    return data;
}

void transazione::setTransazioneConciliata(bool b) {
    transazioneConciliata = b;
}

transazione::transazione() {}

void transazione::setImporto(int i) {
    importo = i;
}

void transazione::setControparte(string c) {
    controparte = c;
}

void transazione::setDataContabile(string d) {
    dataContabile = convertiStringInData(d);
}

void transazione::setTransazioneInUscita(bool b) {
    transazioneInUscita = b;
}

bool transazione::getTransazioneConciliata() {
    return transazioneConciliata;
}

bool transazione::getTransazioneInUscita() {
    return transazioneInUscita;
}

int transazione::getIdTransazione() {
    return idTransazione;
}

int transazione::getImporto() {
    return importo;
}

string transazione::getControparte() {
    return controparte;
}

tm transazione::getDataContabile() {
    return dataContabile;
}

void transazione::setIdTransazione(int i) {
    idTransazione = i;
}
