#include "gtest/gtest.h"

#include "../transazione.h"
#include "../conto.h"

TEST(transazioneTest, testSetTransazioneConciliataFlag){
    conto c1(1,"19_04_2022","titolare");
    c1.aggiungiTransazione(54,"baratta","0");
    transazione* t1 = c1.listaTransazioni[0];

    transazione::setTransazioneConciliataFlag(t1, true);

    ASSERT_TRUE(c1.listaTransazioni[0]->transazioneConciliataFlag);
}