
// This is the Protocol Receive, it works pair with the send, depending on the sending message the Receive will act accordingly
// This code is works based on the Hardware Serial as well as softserial

String  inputString = "";              // a string to hold incoming data
boolean hard_stringComplete = false;   // whether the string is complete
String  softString = "";
boolean soft_stringComplete = false;
char    inchar;

/*
 * Connectivity_Serial occurs once per cycle loop and its check either the receive flag
 * is high. If its high it will run a series of code to accomplish task
 */
 boolean check_soft_uart(){
    if (Connectivity_Serial.available() > 0) {
      softString = Connectivity_Serial.read();
      if (softString.startsWith("~")) {
        soft_stringComplete = true;
      }
    }
 }

/*
 * its check the ack code from the receive packet 
 */
 boolean check_ack(int lookout){
  boolean result = false;
  inputString = "";
  int a=0;
  while(a<lookout){
    while (Serial.available()>0) {
       inchar = (char)Serial.read();
       Serial.flush();
       inputString += inchar;
       if(inputString == "~a!"){   
        // Serial.print(inputString);
         a=100;
         return result = true;    //Means it completly receive.
       }
     }
    a++;
    delay(90);                    //sampling gap 90ms
  }
  return result = false;
 }

 String listen_hard_uart() {
  
 }

