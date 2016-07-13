/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NRF24.h
 * Author: X86
 *
 * Created on 10 luglio 2016, 15.44
 */

#ifndef NRF24_H
#define NRF24_H

#include <BCM283X.h>
#include <time.h>

class NRF24 {
protected:
    NRF24();
public:
    NRF24(uint8_t cePin, uint8_t csnPin);
    NRF24(const NRF24& orig);
    virtual ~NRF24();
    uint8_t NRF24::getStatus();
private:
    static enum COMMAND{NOP_COMMAND=0xFF};
    enum STATUS {PWR_DOWN, STARTUP, STANDBY_1, STANDBY_2, RX_SETTING, RX_MODE, TX_SETTING, TX_MODE} 
    uint8_t lastStatus;
    time_t lstStatusUpdateTime;
    BCM283X *bcm2835;
    uint8_t cePin;
    uint8_t csnPin;
    void init(uint8_t cePin, uint8_t csnPin);
};

#endif /* NRF24_H */

