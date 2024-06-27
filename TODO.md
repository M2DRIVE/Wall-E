# TODO
- ~~Play Music~~
- ~~Stop Music~~
- ~~Skip Music Tracks~~
- ~~Pause Music Tracks~~
- ~~Resume Music Tracks~~
- ~~Volume Potentiometer~~
- Configure PIR Sensor
- ~~Wave Detector~~
- ~~Eye Servo Movement~~
- ~~Arm Servo Movement~~
- Fix Wall-E voice volume
- Smooth out arm movement

<br></br>

## BUGS
- ~~Once song ends, `isPlaying` is still set to true~~
  - Switched to `mp3module.readState()` to determine if song is playing
- ~~Potentiometer might slowly decrease over time~~
  - I'm gonna ignore that probably won't happen
- ~~OLed screen takes a while to load~~
  - I was on crack when I wrote that it works fine
- ~~Button Debounce~~

<br></br>

## Module Documentation
DFPlayer Mini : https://wiki.dfrobot.com/DFPlayer_Mini_SKU_DFR0299#Connection_Diagram
https://github.com/ahmetdidarzafer/Components/tree/main/MP3%20Module

OLED : https://github.com/BasOnTech/Arduino-Beginners-EN/tree/master/E25-OLED-SPI-SSD1331-96x64-color

