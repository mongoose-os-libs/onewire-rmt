# Onewire library for Mongoose OS using theESP32's RMT device
Based on https://github.com/nodemcu/nodemcu-firmware/blob/dev-esp32/components/platform/onewire.c

It uses 2 RMT channels, one for RX and one for TX.
Create the onewire object like this:
```
OnewireRmt* mgos_onewire_rmt_create(int pin,int rmt_rx,int rmt_tx);
```
or
```
OnewireRmt(uint8_t pin,uint8_t rmt_rx,uint8_t rmt_tx);
```



