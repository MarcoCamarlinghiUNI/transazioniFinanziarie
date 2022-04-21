#include "gtest/gtest.h"

#include "../transazione.h"
#include "../conto.h"

TEST(transazioneTest, testSetTransazioneConciliataFlag){
    conto c1(1,"19_04_2022","titolare");
    c1.aggiungiTransazione(54,"baratta","0");

    c1.elencoTransazioni.front()->setTransazioneConciliataFlag(1);

    ASSERT_TRUE(c1.elencoTransazioni.front()->transazioneConciliataFlag);
}