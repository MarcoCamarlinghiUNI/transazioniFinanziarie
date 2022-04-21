#include "conto.h"

conto::conto(int id, const string &dataAperturaz, const string &titolarez) {
    idConto = id;
    dataApertura = convertiStringInData(dataAperturaz);
    titolare = titolarez;

    caricaDati();
    trovaProssimoIdTransazione();
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

void conto::caricaDati() {
    string contoDaVisualizzareNomeFile;
    contoDaVisualizzareNomeFile.append(to_string(idConto));
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
        shared_ptr<transazione> ptr (new transazione(stoi(contoDaVisualizzareVettore[i][0]), stoi(contoDaVisualizzareVettore[i][1]),
                                                     contoDaVisualizzareVettore[i][2], contoDaVisualizzareVettore[i][3],
                                                     contoDaVisualizzareVettore[i][4], contoDaVisualizzareVettore[i][5]));
        elencoTransazioni.push_back(ptr);
    }

    contoDaVisualizzareFile.close();
}

void conto::aggiungiTransazione(int importoz, const string &contropartez, const string &transazioneInUscitaFlagz) {

    shared_ptr<transazione> ptr = make_shared<transazione>();
    ptr->idTransazione = prossimoIdTransazione;
    ptr->importo = importoz;
    ptr->controparte = contropartez;
    if (transazioneInUscitaFlagz == "1"){
        ptr->transazioneInUscitaFlag = true;
    } else {
        ptr->transazioneInUscitaFlag = false;
    }
    ptr->transazioneConciliataFlag = false;

    time_t now1 = time(0);
    tm* localtm1 = localtime(&now1);
    ptr->dataContabile.tm_year = localtm1->tm_year + 1900;
    ptr->dataContabile.tm_mon = localtm1->tm_mon + 1;
    ptr->dataContabile.tm_mday = localtm1->tm_mday;

    elencoTransazioni.push_back(ptr);

    prossimoIdTransazione++;

    salvaDati();
}

void conto::eliminaTransazione(int idTransazioneDaEliminare) {
    try {
        elencoTransazioni.remove(cercaTransazionePerId(idTransazioneDaEliminare));
    } catch (const char* error) {
        cout << error << endl;
    }

    salvaDati();
}

void conto::trovaProssimoIdTransazione() {
    int prossimoId = 1;

    for (auto & transazione : elencoTransazioni){
        if(transazione->idTransazione > prossimoId)
            prossimoId = transazione->idTransazione;
    }

    prossimoIdTransazione = prossimoId + 1;
}

void conto::salvaDati() {
    // crea un csv con la lista delle transazioni
    std::ofstream myfile;
    myfile.open ("nuovoCSV.csv");
    for (auto & r : elencoTransazioni){
        myfile << r->idTransazione<<",";
        myfile << r->importo<<",";
        myfile << r->controparte<<",";
        myfile << r->dataContabile.tm_mday<<"-";
        myfile << r->dataContabile.tm_mon<<"-";
        myfile << r->dataContabile.tm_year<<",";
        myfile << r->transazioneInUscitaFlag<<",";
        myfile << r->transazioneConciliataFlag<<",\n";
    }
    myfile.close();

    // elimina il vecchio csv dello stesso conto
    string nomeDelFile;
    nomeDelFile.append(to_string(idConto));
    nomeDelFile.append(".csv");
    const char * nomeDelFileChar = nomeDelFile.c_str();
    remove(nomeDelFileChar);

    // rinomina il nuovv csv col nome di quello vecchio
    rename("nuovoCSV.csv", nomeDelFileChar);
}

int conto::getNumeroTransazioni() {
    return elencoTransazioni.size();
}

int conto::getBilancioTransazioni() {
    int bilancio = 0;

    for(auto& transazione : elencoTransazioni){
        if (transazione->transazioneInUscitaFlag){
            bilancio -= transazione->importo;
        } else {
            bilancio += transazione->importo;
        }
    }

    return bilancio;
}

void conto::modificaTransazione(int id, int importoz, const string &contropartez, const string &transazioneInUscitaFlagz) {
    shared_ptr<transazione> ptr = cercaTransazionePerId(id);

    if (!ptr->transazioneConciliataFlag) {
        ptr->importo = importoz;
        ptr->controparte = contropartez;
        ptr->transazioneInUscitaFlag = &transazioneInUscitaFlagz;

        salvaDati();
    } else {
        throw "Transazione conciliata, impossibile modificare";
    }
}

shared_ptr<transazione> conto::cercaTransazionePerId(int idTransazione) {
    for(auto& transazione : elencoTransazioni){
        if (idTransazione == transazione->idTransazione){
            return transazione;
        }
    }

    throw "Transazione non presente";
}
