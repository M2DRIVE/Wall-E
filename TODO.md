# TODO
- ~~Play Music~~
- ~~Stop Music~~
- ~~Skip Music Tracks~~
- ~~Pause Music Tracks~~
- ~~Resume Music Tracks~~
- ~~Volume Potentiometer~~
- Configure PIR Sensor
- ~~Wave Detector~~
- Eye Servo Movement
- Arm Servo Movement
- Give Wall-E a voice
<br></br>

## BUGS
- ~~Once song ends, `isPlaying` is still set to true~~
  - Switched to `mp3module.readState()` to determine if song is playing
- Potentiometer might slowly decrease over time

<br></br>

## Module Documentation
DFPlayer Mini : https://wiki.dfrobot.com/DFPlayer_Mini_SKU_DFR0299#Connection_Diagram