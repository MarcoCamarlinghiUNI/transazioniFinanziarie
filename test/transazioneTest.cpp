#include "gtest/gtest.h"

#include "../transazione.h"
#include "../conto.h"

TEST(transazioneTest, testSetTransazioneConciliataFlag){
    conto c1(1,"19-04-2022","titolare");
    c1.aggiungiTransazione(54,"baratta","0");

    c1.cercaTransazionePerId(6)->setTransazioneConciliata("1");

    ASSERT_TRUE(c1.cercaTransazionePerId(6)->getTransazioneConciliata());
}