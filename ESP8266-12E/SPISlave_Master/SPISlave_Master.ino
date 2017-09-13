

/*
    SPI Master Demo Sketch
    Connect the SPI Master device to the following pins on the esp8266:

    GPIO    NodeMCU   Name  |   Uno
   ===================================
     15       D8       SS   |   D10
     13       D7      MOSI  |   D11
     12       D6      MISO  |   D12
     14       D5      SCK   |   D13

    Note: If the ESP is booting at a moment when the SPI Master has the Select line HIGH (deselected)
    the ESP8266 WILL FAIL to boot!
    See SPISlave_SafeMaster example for possible workaround

*/
#include <SPI.h>

class ESPMaster
{
private:

public:

    uint8_t _ss_pin;
 //SPISettings  settingsA= SPISettings (2000000, MSBFIRST, SPI_MODE0);

    ESPMaster(uint8_t pin):_ss_pin(pin) {}
     
    void begin()
    {
        pinMode(_ss_pin, OUTPUT);
        digitalWrite(_ss_pin, HIGH);
    }
    uint32_t readStatus()
    {
     // SPI.beginTransaction(settingsA);
        digitalWrite(_ss_pin, LOW);
        SPI.transfer(0x04);
        uint32_t status = (SPI.transfer(0) | ((uint32_t)(SPI.transfer(0)) << 8) | ((uint32_t)(SPI.transfer(0)) << 16) | ((uint32_t)(SPI.transfer(0)) << 24));
        digitalWrite(_ss_pin, HIGH);
     //   SPI.endTransaction();
        return status;
        
    }

    void writeStatus(uint32_t status)
    {
     // SPI.beginTransaction(settingsA);
        digitalWrite(_ss_pin, LOW);
        SPI.transfer(0x01);
        SPI.transfer(status & 0xFF);
        SPI.transfer((status >> 8) & 0xFF);
        SPI.transfer((status >> 16) & 0xFF);
        SPI.transfer((status >> 24) & 0xFF);
        digitalWrite(_ss_pin, HIGH);
    //    SPI.endTransaction();
    }

    void readData(uint8_t * data)
    {
     // SPI.beginTransaction(settingsA);
        digitalWrite(_ss_pin, LOW);
        SPI.transfer(0x03);
        SPI.transfer(0x00);
        for(uint8_t i=0; i<32; i++) {
            data[i] = SPI.transfer(0);
        }
        digitalWrite(_ss_pin, HIGH);
    //    SPI.endTransaction();
    }

    void writeData(uint8_t * data, size_t len)
    {
        uint8_t i=0;
       //  SPI.beginTransaction(settingsA);
        digitalWrite(_ss_pin, LOW);
        //SPI.transfer(0x02);
      //  SPI.transfer(0x00);
        while(len-- && i < 32) {
            SPI.transfer(data[i++]);
        }
        while(i++ < 32) {
            SPI.transfer(0);
        }
        digitalWrite(_ss_pin, HIGH);
       /// SPI.endTransaction();

    }

    String readData()
    {
        char data[33];
        data[32] = 0;
        readData((uint8_t *)data);
        return String(data);
    }

    void writeData(const char * data)
    {
        writeData((uint8_t *)data, strlen(data));
    }
};

ESPMaster esp(SS);

void send(const char * message)
{
    Serial.print("Master: ");
    Serial.println(message);
    esp.writeData(message);
    delay(10);
    Serial.print("Slave: ");
    Serial.println(esp.readData());
    Serial.println();
    delay(10);
    Serial.print("dd: ");
    Serial.println(esp.readStatus());
    Serial.println();
    
}

void setup()
{
    Serial.begin(115200);
    SPI.begin();
    esp.begin();
    delay(1000);
    send("Hello Slave!");
}
String a="null";
int s=0;
void loop()
{
    delay(1000);
   /* if(Serial.available()){
      a= Serial.readString().c_str();;
      Serial.print("sa: ");
      Serial.println(a);
      send(a.c_str());
    }else{
      s++;
      if(s==254)
      s=0;
     // send(String(s).c_str());*/
      //esp.writeData("10");
     // send("123");
   //   }
   Serial.println(s);
   digitalWrite(esp._ss_pin, LOW);
       
            
            SPI.transfer('s');
            SPI.transfer('e');
            SPI.transfer('l');
            SPI.transfer('a');
            SPI.transfer('m');
            SPI.transfer(s++);
            if(s==255)
            s=0;
        
        digitalWrite(esp._ss_pin, HIGH);
    
}
