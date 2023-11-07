//#include <SPI.h>
#define RDID 0x90
#define CLOCKRATE 25000000

const int RE=A0;//=0;
const int CE=A1;//=1;
const int CLE=2;
const int ALE=3;
const int WE=4;
const int WP=5;
const int ioPins[] {6,7,8,9,10,11,12,13};

void setup() {
  Serial.begin(9600);
  Serial.println("[+] Initializing...");
  //SPI.begin();
  pinMode(RE, OUTPUT);
  pinMode(CE, OUTPUT);
  pinMode(CLE, OUTPUT);
  pinMode(ALE, OUTPUT);
  pinMode(WE, OUTPUT);
  pinMode(WP, OUTPUT);
  for ( int ioPin = 0; ioPin < 8; ioPin++){
    pinMode(ioPins[ioPin],OUTPUT);
  }
  delay(100);

  Serial.println("[+] Beginning Transaction...");
  //SPI.beginTransaction(SPISettings(CLOCKRATE, MSBFIRST, SPI_MODE0));
  byte a,b,c,d,e;

  digitalWrite(CE,LOW);   //SET PINS
  digitalWrite(CLE,HIGH);
  digitalWrite(ALE,LOW);
  digitalWrite(RE,HIGH);
  digitalWrite(WE,HIGH);
  digitalWrite(WP,HIGH);


  digitalWrite(WE,LOW);
  //send RDID
  for ( int ioPin = 0; ioPin < 8; ioPin++){
    Serial.print("PIN "); Serial.print(ioPins[ioPin]); Serial.print("   val: "); Serial.println(bitRead(RDID, ioPin));
    digitalWrite(ioPins[ioPin],bitRead(RDID, ioPin));
  }
  digitalWrite(WE,HIGH);
  digitalWrite(CLE,LOW);

  digitalWrite(ALE,HIGH);
  digitalWrite(WE,LOW);
  //send 00h
  for ( int ioPin = 0; ioPin < 8; ioPin++){
    digitalWrite(ioPins[ioPin],0);
  }  
  digitalWrite(WE,HIGH);
  digitalWrite(ALE,LOW); 
  for ( int ioPin = 0; ioPin < 8; ioPin++){
    pinMode(ioPins[ioPin],INPUT);
  }
  //**delay(tAR)?
  digitalWrite(RE,LOW);
  //read byte a
  for ( int ioPin = 0; ioPin < 8; ioPin++){
    bitWrite(a, ioPin, digitalRead(ioPins[ioPin]));
  }
  digitalWrite(RE,HIGH);
  digitalWrite(RE,LOW);
  //read byte b
 for ( int ioPin = 0; ioPin < 8; ioPin++){
    bitWrite(b, ioPin, digitalRead(ioPins[ioPin]));
  }  
  digitalWrite(RE,HIGH);
  digitalWrite(RE,LOW);
  //read byte c
 for ( int ioPin = 0; ioPin < 8; ioPin++){
    bitWrite(c, ioPin, digitalRead(ioPins[ioPin]));
  }  
  digitalWrite(RE,HIGH);
  digitalWrite(RE,LOW);
  //read byte d
 for ( int ioPin = 0; ioPin < 8; ioPin++){
    bitWrite(d, ioPin, digitalRead(ioPins[ioPin]));
  }  
  digitalWrite(RE,HIGH);
  digitalWrite(RE,LOW);
  //read byte e
 for ( int ioPin = 0; ioPin < 8; ioPin++){
    bitWrite(e, ioPin, digitalRead(ioPins[ioPin]));
  }  
  digitalWrite(RE,HIGH);        


  // PRINT BYTES:
  Serial.println("[+] Received Bytes:");
  Serial.print(a);Serial.print("\t");
  Serial.print(b);Serial.print("\t");
  Serial.print(c);Serial.print("\t");
  Serial.print(d);Serial.print("\t");
  Serial.print(e);
}
//END
void loop() {
}
