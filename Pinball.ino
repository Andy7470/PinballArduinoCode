int lastMultiball = 0;
unsigned long currentTime = 0;
unsigned long lasttimeBuzzer = 0;
unsigned long lastOff = 0;
int timesb = 0;


bool animationStart = 1;

//counters
int score = 0;
int ballCounter = 1;
int record = 0;
int balls = 0;


// GAMES IS ON?
int const gameRun = 23; // lid sensor
int game = 0;

//sensors SCORE -------------------------
int const points_20 = 24;
int const points2_20 = 25;
int const points_30 = 26;
int const points_90 = 27;
int const points_50 = 28;
int const points_80 = 29;
int const points_10 = 30;
int const points2_10 = 31;

// ends sensor
int const endGame = 32;

//multiball sensor
int const multiballSensor = 33;

// ACTION OUTPUTS-------------------------
//flips

int const flips = 48;

int const takeOut = 35;

// 
int const multiball = 36;

// Score Leds
int const points_20L = 38;
int const points2_20L = 39;
int const points_30L = 40;
int const points_80L = 43;
int const points_10L = 44;
int const points2_10L = 45;

int const buzzer = 46;

//---- Display ----
byte SCLK = 7;
byte RCLK = 6;
byte DIO = 5;
//-----------------

//##-----------------------------------
#include <TM74HC595Display.h>
#include <TimerOne.h>
TM74HC595Display disp(SCLK, RCLK, DIO);
unsigned char SYM[39];

//--------------------------------------


// Functions
void gameRunning();
void playBuzzer(int times = 1);
void pointsAnimation();
void waitingAnimation();
void offLeds();
// *******


void setup() {
  ///########
  Timer1.initialize(1500);           
  Timer1.attachInterrupt(timerIsr);  
  ///########

//OUTPUTS
  for (int i = 34; i <= 48; i++){
    pinMode(i, OUTPUT);
    digitalWrite(i,LOW);
    
  }
    for (int i = 23; i <= 33; i++){
    pinMode(i, INPUT_PULLUP);
    
  }
///////

  digitalWrite(flips,LOW);

  int record = 0;
  
  
}


void loop() {

  currentTime = millis();


if (digitalRead(gameRun) != 1){
  game = true;
}

if (game){
  gameRunning();
}
else{
  digitalWrite(flips,LOW);
  waitingAnimation();
}


}

void timerIsr() {   // прерывание таймера
  disp.timerIsr();  // пнуть дисплей
}
