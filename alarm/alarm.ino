int foto = A3;
int speaker = 3;
int light = 0;
int button = 13;
int AlarmStop = 1;


void setup() {
  pinMode(speaker, OUTPUT);
  pinMode(foto, INPUT);
  pinMode(button, INPUT);
 // for(int x = 0; x<=2;x++)
//      pinMode(led[x], OUTPUT);
  Serial.begin(9600);

}

void loop() {
 light = analogRead(foto);
 Serial.println(light);
 
 
 
 
 
 if(light > 500){
  AlarmStop = 0;
 }

 Serial.println(AlarmStop);
 Serial.println(digitalRead(button));
 
 if (AlarmStop == 0 ) {
 tone(speaker,1000, 200); 
 }
 
 if((digitalRead(button) == HIGH) && (light < 500)) {
  noTone(speaker);
  delay(200);
  AlarmStop = 1;  
 }

}

/*  830
 *  820
 *  660
 *  320
 *  /
 */
