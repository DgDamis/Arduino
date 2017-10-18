int redLED = 3;
int greenLED = 5;
int blueLED = 6;
int red = 0;
int green = 0;
int blue = 0;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  analogWrite(redLED, red);
  analogWrite(greenLED, green);
  analogWrite(blueLED, blue);
  Serial.begin(9600);
}

void loop() {
    if(Serial.available()) {
    String rgb = Serial.readString();
    int index = rgb.indexOf(",");
    int index2 = rgb.indexOf(",", index+1);
    String r = rgb.substring(0,index);
    String g = rgb.substring(index+1,index2);
    String b = rgb.substring(index2+1);
    Serial.println(r);
    Serial.println(g);
    Serial.println(b);
    red = r.toInt();
    green = g.toInt();
    blue = b.toInt();
    analogWrite(redLED, red);
    analogWrite(greenLED, green);
    analogWrite(blueLED, blue);
  }
}
