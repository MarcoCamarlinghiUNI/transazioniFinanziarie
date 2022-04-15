#include "conto.h"

conto::conto(int id, string dataAperturaz, string titolarez) {
    idConto = id;
    dataApertura = convertiStringInData(dataAperturaz);
    titolare = titolarez;

    listaTransazioni = letturaTransazioni(idConto);
    prossimoIdTransazione = trovaProssimoIdTransazione();
}

tm conto::convertiStringInData(string s) {
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

vector<const transazione*> conto::letturaTransazioni(int idContoz) {
    vector<const transazione*> v;

    string contoDaVisualizzareNomeFile;
    contoDaVisualizzareNomeFile.append(to_string(idContoz));
    contoDaVisualizzareNomeFile.append(".csv");

    vector<vector<string>> contoDaVisualizzareVettore;
    vector<string> contoDaVisualizzareRow;
    string contoDaVisualizzareLine, contoDaVisualizzareWord;

    fstream contoDaVisualizzareFile (contoDaVisualizzareNomeFile, ios::in);
    while(getline(contoDaVisualizzareFile, contoDaVisualizzareLine))
    {
        contoDaVisualizzareRow.clear();

        stringstream str(contoDaVisualizzareLine);

        while(getline(str, contoDaVisualizzareWord, ','))
            contoDaVisualizzareRow.push_back(contoDaVisualizzareWord);
        contoDaVisualizzareVettore.push_back(contoDaVisualizzareRow);
    }

    for ( int i = 0; i<contoDaVisualizzareVettore.size(); i++)
    {
        v.push_back(new transazione(stoi(contoDaVisualizzareVettore[i][0]), stoi(contoDaVisualizzareVettore[i][1]),
                                    contoDaVisualizzareVettore[i][2], contoDaVisualizzareVettore[i][3],
                                    contoDaVisualizzareVettore[i][4], contoDaVisualizzareVettore[i][5]));
    }
    return v;
}

const transazione *conto::aggiungiTransazione(int importoz, string contropartez, string transazioneInUscitaFlagz) {
    transazione* t = new transazione;
    t->idTransazione = prossimoIdTransazione;
    t->importo = importoz;
    t->controparte = contropartez;
    if (transazioneInUscitaFlagz == "1"){
        t->transazioneInUscitaFlag = true;
    } else {
        t->transazioneInUscitaFlag = false;
    }
    t->transazioneConciliataFlag = false;

    time_t now = time(0);
    tm* localtm = localtime(&now);
    t->dataContabile.tm_year = localtm->tm_year + 1900;
    t->dataContabile.tm_mon = localtm->tm_mon;
    t->dataContabile.tm_mday = localtm->tm_mday;

    prossimoIdTransazione++;
    listaTransazioni.push_back(t);
    return listaTransazioni[listaTransazioni.size()-1];
}

void conto::eliminaTransazione(int idTransazioneDaEliminare) {
    bool transazioneEliminata = false;
    for(int i = 0; i<listaTransazioni.size(); i++){
        if(idTransazioneDaEliminare == listaTransazioni[i]->idTransazione){
            listaTransazioni.erase(listaTransazioni.begin()+i);
            transazioneEliminata = true;
        }
    }

    if(!transazioneEliminata)
        cout<<"eccezione transazione non trovata?";
}

int conto::trovaProssimoIdTransazione() {
    int prossimoId = 1;

    for (auto & i : listaTransazioni){
        if(i->idTransazione > prossimoId)
            prossimoId = i->idTransazione;
    }
    return prossimoId+1;
}
