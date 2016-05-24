
//This is the messaging protocol for sending, it work pair with receive as each transmitting packet require the node to listen to ack before sending another packet
//comm_module;node_id;message_id;ack;payload

//maximum payload is 22 character

int     payload_per_packet = 22;    
String  TEMP_Packet_Buff = "";
String  Transmitting_Packet_Buffer[30];
char    ack = 'b';                            //Indicator for successful packet transfer


boolean wiseSEND(String _comm_module, String _node_id, String _payload, int retry) {
  int    remaining_payload = _payload.length();
  int    NumOfPacket = (remaining_payload / payload_per_packet) + 1;
  String Packet = "";
  int    buff = 0;
  ack = 'b';            //ack for new request
  retry--;
  inputString = "";             //
  hard_stringComplete = false;  // Both are use for Serial Event
  
  //----------------------------------------------Splitting the payload
  for(char x=0; x < NumOfPacket; x++) {
    if(remaining_payload >= payload_per_packet) {
      for(char z = 0; z<payload_per_packet; z++) {
        Packet += _payload[z];
      }
      Transmitting_Packet_Buffer[buff] = _comm_module + ';' + _node_id + ';' + String(buff) + ';' + 'a' + ';' + String(Packet);  //Create a packet of message out of spliting the http request
      _payload.remove(0,(payload_per_packet));             //Delete data 
      Packet="";
      remaining_payload = _payload.length();            //Recalculate length
      buff++;                                           //Increment to create next buff

      if(remaining_payload < payload_per_packet) {         //Last packet whatever that is remain
        Transmitting_Packet_Buffer[buff] = _comm_module + ';' + _node_id + ';' + String(buff) + ';' + 'a' + ';' + String(_payload); // last packet
        buff++;   
      } 
    }
  }

  //----------------------------------------------Sending with retry
  for(int i=0; i<NumOfPacket; i++) {
    int _retry = retry;
    for(int z=0; z <= (_retry); z++) {
      Serial.println(Transmitting_Packet_Buffer[i]);
      if(check_ack(10) == true) {  //check ack 10 times with 90ms gap 
        ack = 'a';
        _retry = 0;
        //Serial.print("YES");
      }
      if(z==(_retry)) {
        ack = 'b';
        i = NumOfPacket;    
        break;
      }
    }
  }

  if(ack == 'a') {
    return true;
    //Serial.println("Success");
  }
  else if(ack == 'b') {
    return false;
    //Serial.println("Fail");
  }
}

//Serial handler 
  
//  for(int i=0; i<NumOfPacket; i++) {
//   Serial.println(Transmitting_Packet_Buffer[i]);
//   Serial.println(Transmitting_Packet_Buffer[i].length());
//   Serial.println(NumOfPacket);
//  }
