#include <iostream>
//#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "transazione.h"
#include "conto.h"

int main() {

    string listaContiNomeFile;
    listaContiNomeFile = "listaConti.csv";

    vector<vector<string>> listaContiVettore;
    vector<string> listaContiRow;
    string listaContiLine, listaContiWord;

    fstream listaContiFile (listaContiNomeFile, ios::in);
    if(listaContiFile.is_open())
    {
        while(getline(listaContiFile, listaContiLine))
        {
            listaContiRow.clear();

            stringstream str(listaContiLine);

            while(getline(str, listaContiWord, ','))
                listaContiRow.push_back(listaContiWord);
            listaContiVettore.push_back(listaContiRow);
        }
    }
    else
        cout<<"Could not open the file\n";

    listaContiFile.close();

    for(auto & i : listaContiVettore)
    {
        for(auto & j : i)
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }


    conto c1 (stoi(listaContiVettore[0][0]), listaContiVettore[0][1], listaContiVettore[0][2]);
    conto c2 (stoi(listaContiVettore[1][0]), listaContiVettore[1][1], listaContiVettore[2][2]);
    conto c3 (stoi(listaContiVettore[2][0]), listaContiVettore[2][1], listaContiVettore[2][2]);



    c2.conciliaTransazione(c2.listaTransazioni[2]);

    c2.aggiungiTransazione(10,"gelato","0");



    return 0;
}
