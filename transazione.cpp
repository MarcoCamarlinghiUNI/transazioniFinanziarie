#include "transazione.h"

transazione::transazione(int idTransazionez, int importoz, string contropartez, string dataContabilez,
                         string transazioneInUscitaFlagz,
                         string transazioneConciliataFlagz) {
    idTransazione = idTransazionez;
    importo = importoz;
    controparte = contropartez;
    dataContabile = convertiStringInData(dataContabilez);

    if (transazioneInUscitaFlagz == "1"){
        transazioneInUscitaFlag = true;
    } else {
        transazioneInUscitaFlag = false;
    }

    if (transazioneConciliataFlagz == "1"){
        transazioneConciliataFlag = true;
    } else {
        transazioneConciliataFlag = false;
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

void transazione::conciliaTransazione(transazione t) {
    t.transazioneConciliataFlag = true;
}
