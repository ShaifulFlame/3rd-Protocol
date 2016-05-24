/*
 * 
 *  //This is the 3rd work of creating messaging protocol for IoT used by the WSN, thus I named it 3rd Protocol 
 * 
 *  //There are 32 bytes per message packet due to limitation of connectivity module (nrf24L01)
 *  
 *  //This code is a process to transmit a string of request/query to the gateway, so that the gateway can make HTTPS/HTTP request to the server
 *  //WSN act as a client that send a request to the gateway
 * 
 *  **Future Works
 *  //WSN as a Server, 
 *  
 *  //comm_module;node_id;message_id;ack;payload
 *  
 *  
 */
