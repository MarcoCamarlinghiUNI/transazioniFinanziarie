#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "transazione.h"
#include "conto.h"

int main() {
    transazione* a;

    string fname;
    fname = "listaConti.csv";

    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    fstream file (fname, ios::in);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();

            stringstream str(line);

            while(getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
        cout<<"Could not open the file\n";

    for(int i=0;i<content.size();i++)
    {
        for(int j=0;j<content[i].size();j++)
        {
            cout<<content[i][j]<<" ";

        }
        cout<<"\n";
    }

    cout<<content[0][0]<<" ";
    cout<<content[1][1]<<" ";
    cout<<content[2][2]<<" ";

    conto c (stoi(content[0][0]), content[0][1], content[0][1]);

    cout<<c.dataApertura.tm_year<<" ";

    return 0;
}
