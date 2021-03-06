// ledky a jejich pridelene piny
int led1 = 12;
int led2 = 11;
int led3 = 10;
int led4 = 9;
int led5 = 8;

// binarni cisla ve stringu
String sbin1 = "0";
String sbin2 = "0";
String sbin3 = "0";
String sbin4 = "0";
String sbin5 = "0";

// binarni cisla v intu
int bin1 = 0;
int bin2 = 0;
int bin3 = 0;
int bin4 = 0;
int bin5 = 0;


void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
      sbin1 = "0";
      sbin2 = "0";
      sbin3 = "0";
      sbin4 = "0";
      sbin5 = "0";
      
      // Nacteni dat
      String string = Serial.readString();
      Serial.println("Nactena data:");
      Serial.println(string);

      // Prevedeni nactenych data do binarni podoby
      String bin = String (string.toInt(),BIN);
      Serial.println("Nactena data prevedena do binarni podoby:");
      Serial.println(bin);
      
      // Zjisteni delky binarniho cisla
      int blength = bin.length();
       
       switch(blength) {
            case 1: sbin1 = bin[0];
                    bin1 = sbin1.toInt();
                    break;
            case 2: sbin1 = bin[1];
                    sbin2 = bin[0];
                    bin1 = sbin1.toInt();
                    bin2 = sbin2.toInt();
                    break;
            case 3: sbin1 = bin[2];
                    sbin2 = bin[1];
                    sbin3 = bin[0];
                    bin1 = sbin1.toInt();
                    bin2 = sbin2.toInt();
                    bin3 = sbin3.toInt();
                    break;
            case 4: sbin1 = bin[3];
                    sbin2 = bin[2];
                    sbin3 = bin[1];
                    sbin4 = bin[0];
                    bin1 = sbin1.toInt();
                    bin2 = sbin2.toInt();
                    bin3 = sbin3.toInt();
                    bin4 = sbin4.toInt();
                    break;
            case 5: sbin1 = bin[4];
                    sbin2 = bin[3];
                    sbin3 = bin[2];
                    sbin4 = bin[1];
                    sbin5 = bin[0];
                    bin1 = sbin1.toInt();
                    bin2 = sbin2.toInt();
                    bin3 = sbin3.toInt();
                    bin4 = sbin4.toInt();
                    bin5 = sbin5.toInt();
                    break;
          }
      /* 
       * 
       * Debuggovaci prostredi pro promenne
       * 
       * 
            Serial.print("sbinar5:");
            Serial.println(sbin5);
            Serial.print("sbinar4:");
            Serial.println(sbin4);
            Serial.print("sbinar3:");
            Serial.println(sbin3);
            Serial.print("sbinar2:");
            Serial.println(sbin2);
            Serial.print("sbinar1:");
            Serial.println(sbin1);
            
            Serial.print("binar5:");
            Serial.println(bin5);
            Serial.print("binar4:");
            Serial.println(bin4);
            Serial.print("binar3:");
            Serial.println(bin3);
            Serial.print("binar2:");
            Serial.println(bin2);
            Serial.print("binar1:");
            Serial.println(bin1);
      */
      
      //
      }

      // Zapnuti ledek podle binarniho cisla
      
            if(bin1 == 1) {
              digitalWrite(led1,HIGH);
            }
            else digitalWrite(led1,LOW);
            if(bin2 == 1) {
              digitalWrite(led2,HIGH);
            }
            else digitalWrite(led2,LOW);
            if(bin3 == 1) {
              digitalWrite(led3,HIGH);
            }
            else digitalWrite(led3,LOW);
            if(bin4 == 1) {
              digitalWrite(led4,HIGH);
            }
            else digitalWrite(led4,LOW);
            if(bin5 == 1) {
              digitalWrite(led5,HIGH);
            }
            else digitalWrite(led5,LOW);
      
  }

