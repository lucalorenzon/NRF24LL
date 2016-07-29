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
    uint8_t NRF24::getStatusRegister();
    void powerUp();
    uint8_t getByteRegister(NRF24_REGISTER register);
    void getRegister(NRF24_REGISTER register, uint8_t *value, uint32_t lenght);
    
private:
    static enum NRF24_COMMAND{NOP_COMMAND=0xFF, OP_R_REGISTER=0b00000000, OP_W_REGISTER=0b00100000, 
                        OP_R_RX_PAYLOAD=0b01100001, OP_W_TX_PAYLOAD=0b10100000, 
                        OP_FLUSH_TX=0b11100001, OP_FLUSH_RX=0b11100010,
                        OP_REUSE_TX_PL=0b11100011, OP_R_RX_PL_WID=0b01100000,
                        OP_W_ACK_PAYLOAD=0b10101000, OP_W_TX_PAYLOAD_NOACK=0b10110000};
    enum NRF24_STATUS {PWR_DOWN, STARTUP, STANDBY_1, STANDBY_2, RX_SETTING, RX_MODE, TX_SETTING, TX_MODE}; 
    enum NRF24_REGISTER {CONFIG=0x00, EN_AA=0x01, EN_RXADDR=0x02, SETUP_AW=0x03, SETUP_RETR=0x04, RF_CH=0x05,
                         RF_SETUP=0x06, STATUS_REG=0x07, OBSERVE_TX=0x08, RPD=0x09, 
                         RX_ADDR_P0=0x0A, RX_ADDR_P1=0x0B, RX_ADDR_P2=0x0C, RX_ADDR_P3=0x0D, RX_ADDR_P4=0x0E, RX_ADDR_P5=0x0F,
                         TX_ADDR=0x10, 
                         RX_PW_P0=0x11, RX_PW_P1=0x12, RX_PW_P2=0x13, RX_PW_P3=0x14, RX_PW_P4=0x15, RX_PW_P5=0x16,
                         FIFO_STATUS=0x17, DYNPLD=0x1C, FEATURE=0x1D};
    uint8_t lastStatus;
    time_t lstStatusUpdateTime;
    BCM283X *bcm2835;
    uint8_t cePin;
    uint8_t csnPin;
    void init(uint8_t cePin, uint8_t csnPin);
    
    
};

#endif /* NRF24_H */

