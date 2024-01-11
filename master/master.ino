//Settings
#define modepin 4
#define addr_master "00"
#define com_MPing "00"
#define com_SAnsw "02"
#define com_door "01"
#define com_read "04"
#define com_load "05"
#define com_data "06"
#define com_OK "03"
#define terminator "E"
String addresses_slaves[]={"01","02","03","04","05","06","07","08","09","0A"};
//End of settings
String buf;
int transmit_mode=0;
void setup() {
  // put your setup code here, to run once:
//pinMode(doorpin,OUTPUT);
pinMode(modepin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  if(Serial.available()>4){
    buf=Serial.readStringUntil(terminator);
    }
  char checkbuf[6]={};
  char out[6]={};
  snprintf(checkbuf, sizeof checkbuf, "%s%s%s", addr_master, com_OK, terminator);
  //if(String(buf[0])+String(buf[1])==addr_master and String(buf[2])+String(buf[3])==com_OK and buf[5]==terminator){
  if(buf==checkbuf){
    Serial.print("OK");
    }
  if(buf=='openE'){
    //Transmit("0101E");
    //Transmit(strcat(strcat(addresses_slaves[0],com_door),terminator));
    snprintf(out, sizeof out, "%s%s%s", addresses_slaves[0], com_door, terminator);
    //Transmit(addresses_slaves[0]+com_door+terminator);
    Transmit(out);
    }
  for(int x;x<256;x++){
     snprintf(checkbuf, sizeof checkbuf, "%s%s%s", addresses_slaves[x], com_SAnsw, terminator);
     //if(String(buf[0])+String(buf[1])==addresses_slaves[x] and String(buf[2])+String(buf[3])== "02" and buf[5]=='E'){
     if(buf==checkbuf){
          Serial.print("PING OK");
        }
      }
  if(buf=='PINGDOORE'){
  //Transmit(strcat(strcat(addresses_slaves[0],com_door),terminator));
  snprintf(out, sizeof out, "%s%s%s", addresses_slaves[0], com_MPing, terminator);
  //Transmit(addresses_slaves[0]+com_MPing+terminator);
  Transmit(out);
    }
}
void Transmit(String transbuf){
  digitalWrite(modepin,1);
  Serial.print(transbuf);
  digitalWrite(modepin,0);
  }

void Screen_print(String buf){
  }
