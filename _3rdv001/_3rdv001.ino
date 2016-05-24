
// WSN firmware to send data to the gateway, check README
// write by: SHAIFUL MDALIMON (shaiful.mdalimon@gmail.com)

#include <SoftwareSerial.h>

SoftwareSerial Connectivity_Serial(2,3);  //RX, TX

//*----Communication Module Setting
#include _baudrate_HC11    9600

//*----Device Identification
String comm_module   = "D7";     //*check README, This is the codename for communication module
String node_id       = "01";     //*2 character space for naming your node

//*----String of data that need to be push out
//String payload = "https://www.googleapis.com/fusiontables/v2/query?sql=SELECT%20*%20FROM%201VlpdDfZli504NhPMBXBpzI8lXHGH0T6062KyuXav&key=AIzaSyAm9yWCV7JPCTHCJut8whOjARd7pwROFDQ~"; //EX
String payload = "";

//*----String of received data from the gateway
String data_in = "";

//*----State 
char App_state = '0';


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Connectivity_Serial.begin(4800);
  pinMode(13, OUTPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  //while(request_token(10) == false);    // request token to transmit gateway 10times retry. UDP

  if(App_state == '0') {    //Sense and Construct payload
    //Sense Something and Construct the payload
    App_state == '1';       //If done update App_state
  }

  else if(App_state == '1') {   //State to push data to gateway
    int retry = 4;              //number of retry to retransmission
    
   /* x siap lagi bawah nie.*/ 
    while(wiseSEND(comm_module, node_id, payload, retry) == false); //xleyh freeze
    if (wiseSEND("D7", "01", payload, retry) == true) {  //Push payload to gateway
      Serial.print("Success");                           //if success means the packet is successfully send 
    }
    
  }
  
  String data_in = listen_hard_uart();        //Check if HardUart receive incoming data.
  delay(2000);
}
