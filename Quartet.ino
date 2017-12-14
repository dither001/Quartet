#include <Adafruit_CircuitPlayground.h>
#include "pitches.h"
#include <SoftwareSerial.h>

SoftwareSerial port(9, 10);
boolean toggle = false;
int p = 0;
int i = 0;
int j = 0;
int colorCounter = 0;
int k = 0;

int solo[] = {
  NOTE_A5, NOTE_AS5, 0, NOTE_C6, NOTE_AS5, NOTE_A5, NOTE_D6, NOTE_C6,
  NOTE_AS5, 0, NOTE_A5, NOTE_AS5, NOTE_C6, 0, NOTE_D6, NOTE_C6,
  0, NOTE_AS5, NOTE_C6, 0, NOTE_AS5, NOTE_C6, NOTE_D6, NOTE_C6,
  NOTE_AS5, NOTE_AS5, NOTE_C6, NOTE_AS5, NOTE_A5, NOTE_AS5, NOTE_C6, NOTE_DS6,
  NOTE_D6, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_AS5, NOTE_C6, 0, NOTE_D6,
  NOTE_C6, NOTE_AS5, NOTE_C6, NOTE_C6, NOTE_AS5, NOTE_A5, NOTE_AS5, 0,
  0, NOTE_AS5, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_AS5, NOTE_C6, 0,
  NOTE_D6, NOTE_DS6, NOTE_DS6, NOTE_D6, NOTE_C6, NOTE_AS5, NOTE_C6, NOTE_C6,
  NOTE_AS5, NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5, NOTE_C6, NOTE_AS5, NOTE_A5,
  NOTE_D6, NOTE_C6, NOTE_AS5, NOTE_A5, NOTE_AS5, NOTE_C6, NOTE_D6, NOTE_C6,
  NOTE_C6, 0, NOTE_AS5, NOTE_C6, 0, NOTE_AS5, NOTE_C6, NOTE_D6,
  NOTE_C6, NOTE_AS5, NOTE_AS5, NOTE_AS5, NOTE_C6, NOTE_C6, NOTE_A5, NOTE_A5,
  NOTE_C6, NOTE_DS6, NOTE_D6, NOTE_D6, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_C6, 0, 0, NOTE_D6, NOTE_C6, NOTE_C6,
  NOTE_AS5, NOTE_C6, NOTE_AS5, NOTE_A5, NOTE_AS5, NOTE_F6, NOTE_DS6, NOTE_D6,
  NOTE_C6, NOTE_AS6, NOTE_C6, NOTE_D6, NOTE_D6, NOTE_C6, 0, NOTE_D6,
  NOTE_DS6, NOTE_DS6, NOTE_D6, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_AS5, NOTE_AS5,
  NOTE_C6, NOTE_D6, NOTE_C6, NOTE_AS5, NOTE_C6, NOTE_D6, NOTE_DS6, NOTE_DS6,
  NOTE_D6, NOTE_C6, NOTE_AS5, NOTE_C6, NOTE_C6, 0, NOTE_AS5, NOTE_A5,
  NOTE_AS5, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_AS5, NOTE_C6, NOTE_AS5, NOTE_A5,
  NOTE_AS5, NOTE_AS5, NOTE_C6, 0, NOTE_DS6, NOTE_DS6, NOTE_D6, NOTE_C6,
  NOTE_AS5, NOTE_C6, NOTE_D6
};

int soloDur[] = {
  100, 50, 50, 100, 50, 50, 50, 100,
  50, 50, 100, 50, 50, 100, 100, 100,
  100, 100, 100, 100, 50, 50, 100, 50,
  100, 100, 50, 50, 50, 50, 100, 100,
  50, 50, 100, 100, 100, 200, 100, 50,
  50, 50, 50, 100, 100, 100, 100, 100,
  100, 100, 100, 100, 50, 50, 50, 50,
  50, 50, 100, 100, 100, 50, 50, 200,
  100, 100, 200, 100, 100, 100, 50, 50,
  50, 50, 100, 100, 50, 50, 50, 50,
  100, 100, 100, 100, 100, 50, 50, 100,
  50, 50, 50, 200, 50, 50, 50, 100,
  100, 50, 50, 50, 50, 100, 100, 50,
  50, 50, 50, 100, 100, 50, 50, 100,
  50, 50, 100, 100, 100, 100, 50, 50,
  50, 50, 50, 50, 100, 100, 100, 50,
  50, 100, 100, 100, 100, 100, 100, 100,
  100, 100, 50, 50, 50, 50, 100, 100,
  100, 100, 50, 50, 100, 100, 100, 100,
  100, 100, 100, 50, 50, 50, 50, 50,
  100, 50, 50, 100, 100, 200, 200, 100,
  100, 200, 400
};

int soprano[] = {
  0, NOTE_AS5, 0, NOTE_AS5, 0, NOTE_AS5, 0, NOTE_AS5,
  0, 0, NOTE_G5, 0, NOTE_G5, 0, NOTE_G5, 0,
  NOTE_FS5, 0, NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0,
  NOTE_F5, 0, NOTE_G5, 0, NOTE_G5, 0, NOTE_G5, 0,
  NOTE_G5, 0, NOTE_F5, 0, NOTE_F5, 0, 0, 0,
  NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0, 0, 0,
  0, 0, NOTE_D5, NOTE_DS5, NOTE_F5, NOTE_F5, NOTE_DS5, NOTE_D5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_D5, NOTE_A5, NOTE_AS5, NOTE_AS5,
  NOTE_G5, NOTE_F5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_AS5, NOTE_AS5,
  NOTE_F5, NOTE_G5, NOTE_G5, NOTE_DS6, NOTE_C6, NOTE_AS5, NOTE_G5, NOTE_C6,
  0, 0, 0, NOTE_F6, NOTE_G6, NOTE_A6, NOTE_F6, 0,
  NOTE_G5, NOTE_F6, NOTE_DS6, NOTE_G5, NOTE_AS5, NOTE_A5, NOTE_AS5
};

int sopranoDur[] = {
  100, 100, 100, 100, 100, 100, 100, 100,
  100, 100, 100, 100, 100, 100, 100, 100,
  100, 100, 100, 100, 100, 100, 100, 100,
  100, 100, 100, 100, 100, 100, 100, 100,
  100, 100, 100, 100, 100, 100, 100, 100,
  100, 100, 100, 100, 100, 100, 100, 100,
  100,
  100, 100, 100, 100, 100, 100, 100, 100,
  100, 100, 100, 100, 100, 100, 100, 100,
  100, 100, 100, 100, 100, 100, 100, 100,
  100, 100, 100, 100, 100, 100, 100, 100,
  100, 100, 100, 100,
  // 36 for some reason, not sure why it isn't a multiple of 8?
  50, 50, 100, 50, 50, 100, 200, 100,
  100, 100, 100, 100, 100, 200, 200, 200,
  200, 50, 50, 50, 50, 100, 100, 100,
  100, 50, 50, 50, 50, 100, 100, 100,
  100, 300, 50, 200, 100, 100, 100, 100,
  100, 100, 400, 400, 400
};

int alto[] = {
  0, NOTE_D5, 0, NOTE_D5, 0, NOTE_D5, 0, NOTE_D5, // measure 1
  0, 0, NOTE_DS5, 0, NOTE_DS5, 0, NOTE_DS5, 0, // measure 2
  NOTE_DS5, 0, NOTE_D5, 0, NOTE_D5, 0, NOTE_D5, 0, // measure 3
  NOTE_D5, 0, NOTE_DS5, 0, NOTE_DS5, 0, NOTE_DS5, 0, // measure 4
  NOTE_DS5, 0, NOTE_D5, 0, NOTE_D5, 0, 0, 0, // measure 5
  NOTE_D5, 0, NOTE_D5, 0, NOTE_D5, // only 5 counts, incomplete?
  0, // 3 counts
  // this last rest was reduced from 4 counts to add to measure 6
  0, 0, 0, 0, 0, 0, 0, 0, // x1 8-count rest made into x8 1-count rests
  // ==== Sweetly
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, // measure 8
  NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, // measure 9
  NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, // measure 10
  NOTE_AS4, NOTE_DS5, // - 1/8
  NOTE_G5,
  NOTE_DS5, NOTE_AS4, // - 1/8
  NOTE_G5, NOTE_F5, 0, 0, 0, // measure 11
  0, // - 4 counts
  0, // - 2 counts
  NOTE_G5, NOTE_F5, // - 1/8
  NOTE_F5, // measure 12
  NOTE_DS5, NOTE_F5, // - 1/8
  NOTE_DS5, NOTE_D5, NOTE_DS5, NOTE_AS5,
  NOTE_A5, NOTE_G5, NOTE_F5, NOTE_DS5, NOTE_F5, NOTE_G5, // x6 @ 1/8 - measure 13
  NOTE_G5, NOTE_F5, 0,
  NOTE_G5, NOTE_A5, // - 1/8
  NOTE_A5, NOTE_G5, NOTE_F5, NOTE_G5, // measure 14
  NOTE_F5, NOTE_DS5, NOTE_DS5, NOTE_F5, NOTE_F5, 0, 0, 0, // measure 15
  NOTE_D5, NOTE_C4, NOTE_D5, NOTE_DS5, // x4 @ 1/8
  NOTE_F5, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_AS5, NOTE_F5, // measure 16
  NOTE_F5, NOTE_G5, NOTE_G5, NOTE_AS5,
  NOTE_G5, NOTE_F5, // 2 counts - measure 17
  NOTE_F5, NOTE_DS5, // 2 counts
  NOTE_D5 // 4 counts - measure 18
};

int altoDur[] = {
  100, 100, 100, 100, 100, 100, 100, 100,
  100, 100, 100, 100, 100, 100, 100, 100,
  100, 100, 100, 100, 100, 100, 100, 100,
  100, 100, 100, 100, 100, 100, 100, 100,
  100, 100, 100, 100, 100, 100, 100, 100,
  100, 100, 100, 100, 100,
  400,
  100, 100, 100, 100, 100, 100, 100, 100,
  // ==== Sweetly
  100, 100, 100, 100, 100, 100, 100, 100,
  100, 100, 100, 100, 100, 100, 100, 100,
  100, 100, 100, 100, 100, 100, 100, 100,
  50, 50, 100, 50, 50, 100, 100, 100, 100, 100,
  400, 200, 100, 100,
  100, 100, 100, 100, 100, 100, 100, 50, 50,
  50, 50, 50, 50, 100, 100, 100, 50, 50, 100, 100,
  100, 100, 100, 100, 100, 100, 100, 100,
  100, 100, 50, 50, 50, 50, 100, 100, 100, 100,
  100, 100, 100, 100, 100, 100, 200,
  200, 200, 200,
  400
};

int tenor[] = {
  NOTE_AS4, 0, NOTE_AS4, 0, NOTE_AS4, 0, NOTE_AS4, 0,
  0, NOTE_AS4, 0, NOTE_AS4, 0, NOTE_AS4, 0, NOTE_AS4,
  0, NOTE_AS4, 0, NOTE_AS4, 0, NOTE_AS4, 0, NOTE_AS4,
  0, NOTE_C5, 0, NOTE_C5, 0, NOTE_C5, 0, NOTE_C5,
  0, NOTE_C5, 0, NOTE_C5, 0, NOTE_AS4, 0, NOTE_AS4,
  0, 0, 0, NOTE_AS4, 0, NOTE_AS4, 0, NOTE_AS4,
  0,
  0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  // == == Sweetly
  NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_G4, //200
  NOTE_DS4, NOTE_DS4, NOTE_F4, NOTE_A4, //200
  NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_F4, //200
  NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_F4, //200
  // == == Section B
  NOTE_F4, //400,
  NOTE_C5, NOTE_D5, //200
  NOTE_AS4, //400,
  NOTE_G4, NOTE_AS4, //200,
  NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_A4, //50
  NOTE_G4, NOTE_AS4,
  NOTE_F5, NOTE_DS5, //50
  NOTE_DS5, 0, NOTE_F4, NOTE_AS4, NOTE_AS4, NOTE_G4, NOTE_AS4, NOTE_F4,
  0, 0, 0,
  NOTE_AS4, //200
  NOTE_C5,
  NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_C5, //50
  NOTE_D5, //200
  NOTE_AS4, NOTE_A4, //50
  NOTE_AS4, NOTE_C5, //200
  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_AS4,
  NOTE_C5, NOTE_F4, //200
  NOTE_F4 //400
};

int tenorDur[] = {
  100, 100, 100, 100, 100, 100, 100, 100,
  100, 100, 100, 100, 100, 100, 100, 100,
  100, 100, 100, 100, 100, 100, 100, 100,
  100, 100, 100, 100, 100, 100, 100, 100,
  100, 100, 100, 100, 100, 100, 100, 100,
  100, 100, 100, 100, 100, 100, 100, 100,
  100,
  100, 100, 100, 100,
  100, 100, 100, 100, 100, 100, 100, 100,
  // == == Sweetly
  200, 200, 200, 200, 200, 200, 200, 200,
  200, 200, 200, 200, 200, 200, 200, 200,
  // == == Section B
  400, 200, 200,
  400, 200, 200,
  50, 50, 50, 50, 100, 100, 50, 50, 100,
  100, 100, 100, 100, 100, 100, 100, 100,
  100, 100, 100, 100, 100, 100, 100, 100,
  100, 100, 200, 100, 50, 50, 50, 50, // is this measure only 7 counts?
  200, 50, 50, 200, 200, 100,
  100, 100, 100, 200, 200,
  400
};

int part1[] = {
  0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4,
  0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, //measure 2
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4,
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, //measure 4
  0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4,
  0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, //measure 6
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4,
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, //measure 8
  0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4,
  0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, //measure 10
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4,
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, //measure 12
  0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4,
  0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, //measure 14
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4,
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, //measure 16
  0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4,
  0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, //measure 18
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4,
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, //measure 20
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4,
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, //measure 22
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, //measure 23
  0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, //measure 24
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4,
  0, NOTE_AS4, 0, NOTE_AS4, 0, NOTE_AS4, 0, NOTE_AS4, //measure 26
  0, NOTE_BS4, 0, NOTE_BS4, 0, NOTE_BS4, 0, NOTE_BS4,
  0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4,
  0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4, 0, NOTE_DS4
};

int part2[] = {
  0, 0, 0, 0, 0, 0, 0, 0, // measure 1
  NOTE_AS4, NOTE_AS5, NOTE_AS4, NOTE_AS5, // dur 1/16
  0, 0, 0, 0, 0, 0, // measure 2
  0, 0, 0, 0, 0, 0, 0, 0, // measure 3
  0, 0, 0, 0, 0, 0, 0, 0, // measure 4
  0, 0, 0, 0,
  NOTE_AS4, NOTE_AS5, NOTE_AS4, NOTE_AS5, // dur 1/16
  0, 0, // measure 5
  0, NOTE_AS4, NOTE_CS5, NOTE_AS4, NOTE_F5, NOTE_AS4, NOTE_CS5, NOTE_DS5,
  0, NOTE_AS4, NOTE_CS5, NOTE_AS4, NOTE_F5, NOTE_AS4, NOTE_DS5, NOTE_B4,
  0, NOTE_A4, NOTE_C4, NOTE_GS4, NOTE_DS5, NOTE_GS4, NOTE_C5, NOTE_CS5, // measure 9
  0, NOTE_AS4, NOTE_CS5, NOTE_AS4, NOTE_F5, NOTE_AS4, NOTE_CS5, NOTE_DS5,
  0, NOTE_AS4, NOTE_CS5, NOTE_AS4, NOTE_F5, NOTE_AS4, NOTE_C5, NOTE_CS5,
  0, NOTE_GS5, NOTE_DS5, NOTE_CS5, NOTE_DS5, NOTE_CS5, NOTE_C5, NOTE_CS5,
  0, NOTE_DS5, NOTE_CS5, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_AS4, NOTE_A4, // measure 13
  NOTE_AS6, // 3 counts
  NOTE_B5,
  NOTE_G5, // 3 counts
  NOTE_G5, // measure 14
  NOTE_GS5,
  NOTE_A6, // 4 counts
  0, NOTE_C5, NOTE_AS4, // measure 15
  NOTE_CS5, // 3 counts
  NOTE_C5,
  NOTE_AS4, // 3 counts
  NOTE_CS5, // measure 16
  NOTE_C5, // 4 counts
  0, 0, 0, NOTE_DS5, // measure 17
  NOTE_CS5, // 3 counts
  NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_CS5, // dur 1/16
  NOTE_CS5, NOTE_DS5, 0, // measure 18
  NOTE_F5,
  NOTE_DS5, // 3 counts
  NOTE_CS5, // 2 counts
  NOTE_CS5, NOTE_C5, NOTE_CS5, NOTE_C5, // dur 1/16 measure 19
  NOTE_CS5, // 3 counts
  NOTE_C5, NOTE_AS4, // 2 counts
  NOTE_AS4, NOTE_A4, NOTE_GS4, // measure 20
  // {NOTE_AS4, NOTE_A4, NOTE_GS4} SPECIAL duration of 1/8 divided by 3
  // I modified the last 3 notes
  // by instead using each at 1/8 in part because 1/16 notes sound awful
  // and there's like, no point to making one even shorter; also timing?
  NOTE_G4, // 3 counts
  NOTE_A4, // 4 counts
  NOTE_AS4,
  // measure 21
  NOTE_C5, // 3 counts
  NOTE_CS5,
  NOTE_C5, // 3 counts
  NOTE_CS5,
  // measure 22
  NOTE_F5, NOTE_DS5, // 2 counts
  NOTE_DS5, // 3 counts
  NOTE_DS5, NOTE_F5, // dur 1/16 measure 23
  NOTE_FS5, // 2 counts
  NOTE_F5,
  NOTE_DS5, // 2 counts
  NOTE_CS5, NOTE_DS5, // dur 1/16 measure 24
  NOTE_C5, // 4 counts
  0, 0, 0,
  NOTE_DS5, NOTE_F5, // dur 1/16 measure 25
  NOTE_FS5, // 3 counts
  NOTE_DS5,
  NOTE_FS5, // 3 counts
  NOTE_A6, // measure 26
  NOTE_GS5, // 2 counts
  NOTE_FS5, // 4 counts
  0,
  NOTE_FS5, NOTE_GS5, // dur 1/16 measure 27
  NOTE_FS2, // 2 counts
  NOTE_F5, // 2 counts
  NOTE_DS5, // 3 counts
  NOTE_F5, NOTE_DS5, // dur 1/16 measure 28
  NOTE_C5, // 2 counts
  NOTE_A4, // 2 counts
  0, 0, 0, 0 // added 4 rests to complete measure 29
};

int part2dur[] = {
  42, 42, 42, 42, 42, 42, 42, 42, // measure 1
  21, 21, 21, 21, 42, 42, 42, 42, 42, 42, // measure 2
  42, 42, 42, 42, 42, 42, 42, 42, // measure 3
  42, 42, 42, 42, 42, 42, 42, 42, // measure 4
  42, 42, 42, 42, 21, 21, 21, 21, 42, 42, // measure 5
  42, 42, 42, 42, 42, 42, 42, 42,
  42, 42, 42, 42, 42, 42, 42, 42,
  42, 42, 42, 42, 42, 42, 42, 42, // "measure 9"
  42, 42, 42, 42, 42, 42, 42, 42,
  42, 42, 42, 42, 42, 42, 42, 42,
  42, 42, 42, 42, 42, 42, 42, 42,
  42, 42, 42, 42, 42, 42, 42, 42, // "measure 13"
  125, 42, 125, 42, // measure 14
  42, 167, 42, 42, 42, // measure 15
  125, 42, 125, 42, // measure 16
  167, 42, 42, 42, 42, // measure 17
  125, 21, 21, 21, 21, 42, 42, 42, // measure 18
  42, 125, 83, 21, 21, 21, 21,
  125, 83, 83, 14, 14, 14, // measures 20
  125, 167, 42, // measure 21
  125, 42, 125, 42, // measure 22
  83, 83, 125, 21, 21, // measure 23
  83, 42, 83, 21, 21, // measure 24
  167, 42, 42, 42, 21, 21, // measure 25
  125, 42, 125, 42, // measure 26
  83, 167, 42, 21, 21, // measure 27
  83, 83, 125, 21, 21, // measure 28
  83, 83, 42, 42, 42, 42 // measure 29
};

int part3[] = {
  NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3, NOTE_C4, NOTE_CS4,
  NOTE_AS3, NOTE_C4, // dur 1/16 @ 6 & 7
  NOTE_CS4, // measure 1 (8)
  NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3, NOTE_C4, NOTE_CS4,
  NOTE_AS3, NOTE_C4, // dur 1/16 @ 15 & 16
  NOTE_CS4, // measure 2 (17)
  NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_A3, NOTE_AS3, NOTE_C4,
  NOTE_GS3, NOTE_AS3, // dur 1/16 @ 24 & 25
  NOTE_C4, // measure 3 (26)
  NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_A3, NOTE_AS3, NOTE_C4,
  NOTE_GS3, NOTE_AS3, // dur 1/16 @ 33 & 34
  NOTE_C4, // measure 4 (35)
  NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3, NOTE_C4, NOTE_CS4,
  NOTE_AS3, NOTE_C4, // dur 1/16 @ 42 & 43
  NOTE_CS4,
  NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3, NOTE_C4, NOTE_CS4,
  NOTE_AS3, NOTE_C4, // dur 1/16
  NOTE_CS4,
  NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_A3, NOTE_AS3, NOTE_C4,
  NOTE_GS3, NOTE_AS3, // dur 1/16
  NOTE_C4,
  NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_A3, NOTE_AS3, NOTE_C4,
  NOTE_GS3, NOTE_AS3, // dur 1/16
  NOTE_C4,
  NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3, NOTE_C4, NOTE_CS4,
  NOTE_AS3, NOTE_C4, // dur 1/16
  NOTE_CS4,
  NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3, NOTE_C4, NOTE_CS4,
  NOTE_AS3, NOTE_C4, // dur 1/16
  NOTE_CS4,
  NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_A3, NOTE_AS3, NOTE_C4,
  NOTE_GS3, NOTE_AS3, // dur 1/16
  NOTE_C4,
  NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_A3, NOTE_AS3, NOTE_C4,
  NOTE_GS3, NOTE_AS3, // dur 1/16
  NOTE_C4,
  NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3, NOTE_C4, NOTE_CS4,
  NOTE_AS3, NOTE_C4, // dur 1/16
  NOTE_CS4,
  NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3, NOTE_C4, NOTE_CS4,
  NOTE_AS3, NOTE_C4, // dur 1/16
  NOTE_CS4,
  NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_A3, NOTE_AS3, NOTE_C4,
  NOTE_GS3, NOTE_AS3, // dur 1/16
  NOTE_C4,
  NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_A3, NOTE_AS3, NOTE_C4,
  NOTE_GS3, NOTE_AS3, // dur 1/16
  NOTE_C4,
  NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3, NOTE_C4, NOTE_CS4,
  NOTE_AS3, NOTE_C4, // dur 1/16
  NOTE_CS4,
  NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3, NOTE_C4, NOTE_CS4,
  NOTE_AS3, NOTE_C4, // dur 1/16
  NOTE_CS4,
  NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_A3, NOTE_AS3, NOTE_C4,
  NOTE_GS3, NOTE_AS3, // dur 1/16
  NOTE_C4,
  NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_A3, NOTE_AS3, NOTE_C4,
  NOTE_GS3, NOTE_AS3, // dur1/16
  NOTE_C4,
  NOTE_G3, NOTE_A3, NOTE_AS3, NOTE_G3, NOTE_A3, NOTE_AS3,
  NOTE_FS3, NOTE_GS3, // dur 1/16
  NOTE_AS3,
  NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_A3, NOTE_AS3, NOTE_C4,
  NOTE_GS3, NOTE_AS3, // dur 1/16
  NOTE_C4,
  NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3, NOTE_C4, NOTE_CS4,
  NOTE_AS3, NOTE_C4, // dur 1/16
  NOTE_CS4,
  NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_A3, NOTE_AS3, NOTE_C4,
  NOTE_GS3, NOTE_AS3, // dur 1/16
  NOTE_C4,
  NOTE_DS3, NOTE_F4, NOTE_AS4, NOTE_DS3, NOTE_F4, NOTE_FS4,
  NOTE_DS3, NOTE_F4, // dur 1/16
  NOTE_AS4,
  NOTE_CS4, NOTE_DS3, NOTE_F4, NOTE_CS4, NOTE_DS3, NOTE_F4,
  NOTE_CS4, NOTE_DS3, // dur 1/16
  NOTE_F4,
  NOTE_C4, NOTE_CS4, NOTE_DS3, NOTE_C4, NOTE_CS4, NOTE_DS3,
  NOTE_C4, NOTE_CS4, // dur 1/16
  NOTE_DS3,
  NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_A3, NOTE_AS3, NOTE_C4,
  NOTE_GS3, NOTE_AS3, // dur 1/16
  NOTE_C4
};

int part4[] = {
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, // measure 2
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, // measure 4
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, // measure 6
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, // measure 8
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, NOTE_G4, NOTE_FS4, // measure 10
  0, 0, 0, 0, 0, 0, NOTE_FS4, NOTE_F4,
  0, 0, 0, 0, 0, 0, NOTE_F4, NOTE_FS4, // measure 12
  0, NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_F4, NOTE_FS4, NOTE_FS4, NOTE_F4,
  NOTE_AS4, //3 counts @104
  NOTE_BS4,
  NOTE_G4, //3 counts @106
  NOTE_G4, // measure 14
  NOTE_GS4, NOTE_A4, NOTE_A4, //4 counts @110
  0, 0, // measure 15 (112)
  0, 0, 0, 0, 0, 0, 0, 0, // measure 16 (120)
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, // measure 18 (136)
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, // measure 20 (152)
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, // measure 22 (168)
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, // measure 24 (184)
  0, 0, 0, 0, 0, 0, 0, 0, // measure 25 (192)
  0, 0,
  NOTE_AS4, //2 counts @195
  NOTE_AS4, //4 counts @196 -- measure 26
  0, 0,
  NOTE_FS4, //4 counts @199
  0, 0,
  0, 0,
  NOTE_FS4, //4 counts @204
  0, 0,
  NOTE_F4, //4 counts @207
  NOTE_DS4, //2 counts @208
  NOTE_C4 //2 counts @209
};

void setup()
{
  CircuitPlayground.begin();
  Serial.begin(9600);
  port.begin(9600);
}

void loop()
{
  if (CircuitPlayground.rightButton())
  {
    if (toggle) toggle = false;
    else toggle = true;
    p = 1;
    port.write('b');
    delay(250);
  }

  if (p == 0)
  {
    port.listen();
    if (port.peek() == -1)
    {

    }
    else
    {
      char input = port.read();
      if (input == 'b')
      {
        toggle = true;
        p = 2;
        port.write('c');
        delay(250);
      }
      if (input == 'c')
      {
        toggle = true;
        p = 3;
        port.write('d');
        delay(250);
      }
      if (input == 'd')
      {
        toggle = true;
        p = 4;
        delay(250);
      }
    }
  }

  if (toggle)
  {
    // changed delay from 250 to 50
    delay(50);
    if (p == 1) {
      port.write('b');
      int duration = soloDur[i];
      int maxSize = sizeof(solo);
      playNote(2, solo, duration, maxSize);
    }
    //    else if (p == 2) {
    //      port.write('c');
    //      int duration = sopranoDur[i];
    //      int maxSize = sizeof(soprano);
    //      playNote(2, soprano, duration, maxSize);
    //    }
    else if (p == 2) {
      port.write('d');
      int duration = altoDur[i];
      int maxSize = sizeof(alto);
      playNote(2, alto, duration, maxSize);
    }
    //    else if (p == 2) {
    //      int duration = tenorDur[i];
    //      int maxSize = sizeof(tenor);
    //      playNote(2, tenor, duration, maxSize);
    //    }
  }
}

void playNote(int mod, int current[], int noteDuration, int maxSize)
{
  noteDuration *= mod;
  CircuitPlayground.playTone(current[i], noteDuration);
  if (i < maxSize) i++;
  else
  {
    toggle = false;
    i = 0;
    p = 5;
  }
  CircuitPlayground.setPixelColor(random(0, 9), random(0, 255), random(0, 255), random(0, 255));
  if (j < 10) j++;
  else j = 0;
  delay(100);
  CircuitPlayground.setPixelColor(j - 1, 0, 0, 0);
}

