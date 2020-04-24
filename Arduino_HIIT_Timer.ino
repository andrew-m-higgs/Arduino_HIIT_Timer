// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// FREQUNCIES used for the buzzer. These can be fun to play around with
int highPitch = 2200;
int lowPitch = 2100;
int alarmHighPitch = 2200;
int alarmLowPitch  = 2100;

// NEXT two need to be 1-9 only because of the screen size
int circuits   = 4;
int exercises  = 7;

// TIMES used in the code below
int warmUp        = 180; // Time to warm up at the begining
int warmDown      = 180; // Time to warm down at the end
int workTime      =  30; // Time spent on each exercise
int breakTime     =  15; // Rest between exercises
int restTime      =  60; // Rest between Circuits
int countDownTime =   5; // Seconds for Count Down

// KEEP exercise names at 17 characters for display (add blanks to the end)
String Exercises[7] = {"Mountain Climber ",
                       "Squat Jumps      ",
                       "Bicycle Crunch   ",
                       "Reverse Lunges   ",
                       "Push Ups         ",
                       "Star Jumps       ",
                       "High Knees       "};
/* 
 * UNLESS you want to customuse the firmware you should not need to edit anything below
 * 
 */

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);

  pinMode(10, INPUT_PULLUP);
  pinMode(9, OUTPUT);

  String message = "PRESS BEGIN";
  setScreen(message);
}

/*
 *---------------------------------------------------------------
 * RESET the screen
 *---------------------------------------------------------------
 */
void setScreen(String message) {
  // Print defaults to the LCD.
  lcd.setCursor(0,0);
  lcd.print("C: 0 of ");
  lcd.print(circuits);
  lcd.setCursor(11,0);
  lcd.print("E: 0 of ");
  lcd.print(exercises);
  lcd.setCursor(0,1);
  lcd.print("E: ");
  lcd.setCursor(0,2);
  lcd.print(message);
  lcd.setCursor(14,2);
  lcd.print("T: ");
  lcd.setCursor(0,3);
  lcd.print("N: ");
  lcd.setCursor(3,3);
  lcd.print(Exercises[0]);
  
}

/*
 *--------------------------------------------------------------- 
 * This displays the time left on the count down
 *--------------------------------------------------------------- 
 */
void displayTime(int secondsLeft) {
  lcd.setCursor(17,2);
  if (secondsLeft <= 9) {
    lcd.print("  ");
  } else if (secondsLeft <= 99) {
    lcd.print(" ");
  }
  lcd.print(secondsLeft);
}

/*
 *---------------------------------------------------------------
 * Used as timer for exercise, rest and break times
 *---------------------------------------------------------------
 */
void wait(int seconds, bool removeCountDownTime = true) {
  unsigned long start = millis();
  unsigned long waitFor = 0;
  
  if (removeCountDownTime) {
    waitFor = (unsigned long)(seconds - countDownTime)*1000; //Convert seconds given to milliseconds - the countDownTime
  }else {
    waitFor = (unsigned long)(seconds)*1000; //Convert seconds given to milliseconds - the countDownTime    
  }
  int old_elapsed = 9999;
  while (millis() - start <= waitFor) {
    int elapsed = (millis() - start) / 1000;
    if (elapsed != old_elapsed) {
      int secondsLeft = seconds - elapsed;
      displayTime(secondsLeft);
      old_elapsed = elapsed;
    }
  }
}

/*
 *---------------------------------------------------------------
 * Used as warning of exercise changeover coming
 *---------------------------------------------------------------
 */
void countDown(int count, int megahertzHigh, int megahertzLow){
  for (int val = 1; val < count; val++) {
    tone(9, megahertzHigh);
    delay(200);
    noTone(9);
    delay(900); 
    int secondsLeft = count - val;
    displayTime(secondsLeft);   
  }
  tone(9, megahertzLow);
  delay(700);
  noTone(9);
  delay(400);
}

/*
 *---------------------------------------------------------------
 * Used at the beginning and end of a workout
 *---------------------------------------------------------------
 */
void soundAlarm(int count, int megahertzHigh, int megahertzLow) {
  for (int i = 1; i < count; i++) {
    tone(9, megahertzHigh);
    delay(100);
    tone(9, megahertzLow);
    delay(100);  
  }
  noTone(9);
}

/*
 *---------------------------------------------------------------
 * Main program loop
 *---------------------------------------------------------------
 */
void loop() {
  int btnPressed = digitalRead(10);
  
  if (btnPressed == 0) {

    //SOUND THE ALARM FOR THE START
    soundAlarm(5, alarmHighPitch, alarmLowPitch);
    
    // WARM UP
    lcd.setCursor(0,2);
    lcd.print("WARM UP    ");
    wait(warmUp);
    
    for (int i = 1; i <= circuits; i++) {
      for (int j = 1; j <= exercises; j++) {
        countDown(countDownTime, highPitch, lowPitch);
        lcd.setCursor(3,0);
        lcd.print(i);
        lcd.setCursor(14,0);
        lcd.print(j);
        lcd.setCursor(3,1);
        lcd.print(Exercises[j-1]);
        lcd.setCursor(3,3);
        if (j >= exercises) {
          if (i < circuits) {
            lcd.print(Exercises[0]);
          } else {
            lcd.print("LAST EXERCIZE NOW");
          }
        } else {
          lcd.print(Exercises[j]);
        }
        lcd.setCursor(0,2);
        lcd.print("WORK OUT   ");
        wait(workTime);
        countDown(countDownTime, highPitch, lowPitch);
        lcd.setCursor(0,2);
        lcd.print("BREAK NOW  ");
        wait(breakTime);
      }
      
      countDown(countDownTime, highPitch, lowPitch);
      
      lcd.setCursor(3,1);
      lcd.print("                ");

      lcd.setCursor(0,2);
      lcd.print("REST A BIT ");
      wait(restTime);
    }

    // WARM DOWN
    lcd.setCursor(0,2);
    lcd.print("WARM DOWN  ");
    countDown(countDownTime, highPitch, lowPitch);
    wait(warmDown, false);

    //SOUND THE ALARM FOR THE END
    soundAlarm(5, alarmHighPitch, alarmLowPitch);
    setScreen("WELL DONE  ");
  }
}
