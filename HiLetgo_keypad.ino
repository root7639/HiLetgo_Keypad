#include <Key.h>
#include <Keypad.h>
 
const byte ROWS = 4; //4行のキーパッドを使用
const byte COLS = 4; //4列のキーパッドを使用
 
char keys[ROWS][COLS] = {
  //配列を表す
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
 
byte rowPins[ROWS] = {9, 8, 7, 6}; //接続するピン番号
byte colPins[COLS] = {5, 4, 3, 2}; 
 
Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS); //キーパッドの初期化
 
void setup(){
  Serial.begin(9600);
}
  
void loop(){
  char customKey = customKeypad.getKey();//押されたキーを検出
  
  if (customKey){
    Serial.println(customKey);
  }
}

/*
 * {{s4, s8, s12, s16},
 *  {s3, s7, s11, s15},
 *  {s2, s6, s10, s14},
 *  {s1, s5, s9, s13}}
 *  =
 *  {1, 2, 3, A},
 *  {4, 5, 6, B},
 *  {7, 8, 9, C},
 *  {*, 0, #, D}}
 * 
 */
