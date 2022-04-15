#include "conto.h"

conto::conto(int id, string dataAperturaz, string titolarez) {
    idConto = id;
    dataApertura = convertiStringInData(dataAperturaz);
    titolare = titolarez;
    listaTransazioni = letturaTransazioni(idConto);
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

vector<transazione*> conto::letturaTransazioni(int idContoz) {
    vector<transazione*> v;

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
