#include "conto.h"

conto::conto(int id, string dataAperturaz, string titolarez) {
    idConto = id;
    dataApertura = convertiStringInData(dataAperturaz);
    titolare = titolarez;
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
