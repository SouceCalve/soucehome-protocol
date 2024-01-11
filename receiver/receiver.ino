//Settings
#define modepin 4
#define doorpin 3
#define addr_master "00"
#define addr_slave "01"
#define com_MPing "00"
#define com_SAnsw "02"
#define com_door "01"
#define com_read "04"
#define com_load "05"
#define com_data "06"
#define com_OK "03"
#define terminator "E"
//End of settings
String buf;
int transmit_mode=0;
int door_flag=0;
void setup() {
  // put your setup code here, to run once:
pinMode(doorpin,OUTPUT);
pinMode(modepin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  if(Serial.available()>4){
    buf=Serial.readStringUntil(terminator);
    char checkbuf[6]={};
    snprintf(checkbuf, sizeof checkbuf, "%s%s%s", addr_master, com_door, terminator);
    if(buf==checkbuf){
      door();
      char out[6]={};
      snprintf(out,sizeof out, "%s%s%s", addr_master, com_OK, terminator);
      Transmit(out);
      }
    snprintf(checkbuf, sizeof checkbuf, "%s%s%s", addr_master, com_MPing, terminator);
    if(buf==checkbuf){
      char out[6]={};
      snprintf(out,sizeof out, "%s%s%s", addr_master, com_SAnsw, terminator);
      Transmit(out);
      }
    }
  

}
void Transmit(String transbuf){
  digitalWrite(modepin,1);
  Serial.print(transbuf);
  digitalWrite(modepin,0);
  }

void door(){
  digitalWrite(3,0);
  delay(10);
  digitalWrite(3,1);
  }
