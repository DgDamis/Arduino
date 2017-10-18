int zelenaCesta = 7 ;
int zlutaCesta = 6 ;
int cervenaCesta = 5 ;

int zelenaChodci = 4 ;
int cervenaChodci = 3 ;

int tlacitko = 12 ;

void setup() {
pinMode(zelenaCesta, OUTPUT);
pinMode(zlutaCesta, OUTPUT);
pinMode(cervenaCesta, OUTPUT);
pinMode(zelenaChodci, OUTPUT);
pinMode(cervenaChodci, OUTPUT);
pinMode(tlacitko, INPUT);
}

void loop() {
 if ((digitalRead(tlacitko) == HIGH)) {
    digitalWrite(zelenaCesta, LOW);
    digitalWrite(zlutaCesta, HIGH);
    delay(500);
    digitalWrite(zlutaCesta, LOW);
    digitalWrite(cervenaCesta, HIGH);
    delay(500);
     digitalWrite(cervenaChodci, LOW);
    digitalWrite(zelenaChodci, HIGH);
    delay(5000);
    digitalWrite(zelenaChodci, LOW);
    digitalWrite(cervenaChodci, HIGH);
    delay(500);
    digitalWrite(cervenaCesta, LOW);
    digitalWrite(zlutaCesta, HIGH);
    delay(500);
    digitalWrite(zlutaCesta, LOW);
    delay(250);
    digitalWrite(zelenaCesta, HIGH);
    delay(10000);     
 }
 else {
  digitalWrite(zelenaCesta, HIGH);
 digitalWrite(cervenaChodci, HIGH);
 }

}
