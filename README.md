# STM32F103RB-NUCLEO-SPI-SLAVE-ESP8266-12E-MASTER-COMMUNATION-HAL-
stm32F103rb ve esp8266 12e Wifi Modlünün SPI üzerinden haberleşmesi çalışmasıdır (HAL LIBRARY)

# Bu örnek tamamen test amaçlı oluşturulmuştur.
## Proje IAR Embedded Workbench IDE 8.11.2 üzerinde oluşturulmuştur.

Bu çalışmada ESP8266-12e Wifi Modülü ile stm32f103rb nucleo kartının spi haberleşmesi gerçekleştirilmiştir. 

ESP8266-12e --> Master Seçilmiştir.<br>
STM32f103RB --> Slave Seçilmiştir. <br>


Extra olarak STM32f103RB SPI1 hattı master olarak ayarlanmıştır ve veri gönderme işlemi yapılmıştır. BU işlemi stm' yi esp12e ile haberleştirmeden önce stm üzerinde SPI1 Hattını master yapıp SPI2 hattını slave yaparak birbiri ile haberleşmesini test etmek için yaptım.

Bu örnekte stm üzerinde spi2 hattı kullanılmıştır, esp üzerinde ise hspi hattı kullanılmıştır. Aşağıda pin sıralamalarını görebilirsiniz.

## STM32F103RB NUCLEO <br>

![Screen Shot](https://github.com/zafersn/STM32F103RB-NUCLEO-SPI-SLAVE-ESP8266-12E-MASTER-COMMUNATION-SPL/blob/master/image/cyfnl9cezh8k0buaz.gif)<br>

## ESP8266-12E WiFi Module <br>

![Screen Shot](https://github.com/zafersn/STM32F103RB-NUCLEO-SPI-SLAVE-ESP8266-12E-MASTER-COMMUNATION-SPL/blob/master/image/esp8266_devkit_horizontal-01.png)<br>


