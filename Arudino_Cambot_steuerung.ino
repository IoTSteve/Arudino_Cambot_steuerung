const int Kette1_1 = 10; // vorwärts R
const int Kette1_2 = 11; // rückwärts R
const int Kette2_1 = 9; // vorwärts L
const int Kette2_2 = 8; // rückwärts L
 

void setup() {
  Serial.begin(9600);
  pinMode(Kette1_1, INPUT);
  pinMode(Kette1_2, INPUT);
  pinMode(Kette2_1, INPUT);
  pinMode(Kette2_2, INPUT);

  

//digitalWrite(Kette1_1, LOW);
//digitalWrite(Kette2_1, LOW);


}

String serialInput = "";
void loop() {

  while (Serial.available() > 0) {
    char serialChar = Serial.read();
    if (isDigit(serialChar) || serialChar == 'v' || 's' || 'r' || 'l' ) {
      serialInput += serialChar;
    }
    if (serialChar == '\n') {
      if (serialInput.charAt(0) == 'v') {
        serialInput.remove(0, 1);
        digitalWrite(Kette1_1, HIGH); //Panzer fährt
        digitalWrite(Kette2_1, HIGH);
        digitalWrite(Kette1_2, LOW);
        digitalWrite(Kette2_2, LOW);
        
      }
       if (serialInput.charAt(0) == 's') {
        serialInput.remove(0, 1);      //Panzer Stoppt
        digitalWrite(Kette1_1, LOW);
        digitalWrite(Kette2_1, LOW);
        digitalWrite(Kette1_2, LOW);
        digitalWrite(Kette2_2, LOW);
        
      }
       if (serialInput.charAt(0) == 'l') {
        serialInput.remove(0, 1);      //Panzer dreht links
        digitalWrite(Kette1_1, HIGH);
        digitalWrite(Kette2_1, LOW);
        digitalWrite(Kette1_2, LOW);
        digitalWrite(Kette2_2, HIGH);
      }
       if (serialInput.charAt(0) == 'r') {
        serialInput.remove(0, 1);      //Panzer dreht rechts
        digitalWrite(Kette1_1, LOW);
        digitalWrite(Kette2_1, HIGH);
        digitalWrite(Kette1_2, HIGH);
        digitalWrite(Kette2_2, LOW);
      }
      serialInput = "";
    }
  }

  
}
