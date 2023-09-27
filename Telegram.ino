#include<ESP8266WiFi.h>
#include<WiFiClientSecure.h>
#include<UniversalTelegramBot.h>
#include<ArduinoJson.h>
const char* ssid = "realme 7 pro";
const char* password ="11223344";
//  with your network credentials

// Initialize Telegram BOT
#define BOTtoken "6097955292:AAEUD5LYSxIRyFCpQxtSTkfkp2faOSPHMRw"  // your Bot Token (Get from Botfather)

// Use @myidbot to find out the chat ID of an individual or a group
// Also note that you need to click "start" on a bot before it can
// message you
#define CHAT_ID "1375824230"
X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);


char Start_buff[70]; 
int i,z;             
char ch;
int str_len;
 char textmessage[20];



void MESSAGE_SEND();
void WAITING();
void setup() 
{
    // initialize the Serial
    Serial.begin(9600);
    Serial.println("Starting TelegramBot...");

    configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
  client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

//  bot.sendMessage(CHAT_ID, "Bot started up", "");
    bot.sendMessage(CHAT_ID, "Nano Tree Based streetlight and Traffic management");
   
    
}
void loop() 
{
  
  WAITING();
    
}
void MESSAGE_SEND()
{
  bot.sendMessage(CHAT_ID, "SEND START TO CONTINUE"); 
  // myBot.sendMessage(msg_sender_id1, "WELCOME TO ATM"); 
  
}


char Serial_read(void)
{
      char ch;
      while(Serial.available() == 0);
      ch = Serial.read(); 
      return ch;
}
void WAITING()
{
   Serial.println("WAITE");
  
  buffer_clear();
//  msg.text[0]='\0';
//        msg.text[1]='\0';
//         msg.text[2]='\0' ;
//         msg.text[3]='\0';
//          msg.text[4]='\0';
//           msg.text[5]='\0';
           
 while(1)
 { 
      if (Serial.available() > 0)
      {
         //Serial.println("halo");
        
          while(Serial_read()!='$');
          i=0;
          while((ch=Serial_read())!='#')
          {
            Start_buff[i] = ch;
             i++;
          }  
          Start_buff[i]='\0';
       }
       Serial.println(Start_buff);
       bot.sendMessage(CHAT_ID, Start_buff); 
      delay(100);
//    if((Start_buff[0]=='E'))
// {
//  String message = "EMERGECNY LOCATION AT:https://www.google.com/maps/place/East+West+Institute+of+Technology/@12.9759238,77.4805907,17z/data=!3m1!4b1!4m6!3m5!1s0x3bae3c11c4e33205:0x84408cc07d7019e5!8m2!3d12.9759238!4d77.4831656!16s%2Fm%2F0cr39nm";
////String two = "," ;   
////String message = one +"15.2644" +two + "76.3672";
//
//// Convert String to char array
//int str_len = message.length() + 1;
//char textmessage[str_len];
//message.toCharArray(textmessage,str_len);
//Serial.println(textmessage);
//  bot.sendMessage(CHAT_ID,textmessage);
//delay(100);
// }
//   if((Start_buff[0]=='S'))
// {
//  String one = "PACKAGE LOCATION AT:https://www.google.com/maps/?q=";
//String two = "," ;   
//String message = one +"13.0676" +two + "77.5045";
//
//// Convert String to char array
//int str_len = message.length() + 1;
//char textmessage[str_len];
//message.toCharArray(textmessage,str_len);
//Serial.println(textmessage);
//  bot.sendMessage(CHAT_ID,textmessage);
//delay(100);
// }
//  if((Start_buff[0]=='V'))
// {
//  String one = "ACCIDENT OCCURS LOCATION AT:https://www.google.com/maps/?q=";
//String two = "," ;   
//String message = one +"12.8999" +two + "77.4958";
//
//// Convert String to char array
//int str_len = message.length() + 1;
//char textmessage[str_len];
//message.toCharArray(textmessage,str_len);
//Serial.println(textmessage);
//  bot.sendMessage(CHAT_ID,textmessage);
//delay(100);
// }
//      if((Start_buff[0]=='R') ||(Start_buff[0]=='L')||(Start_buff[0]=='C')||(Start_buff[0]=='F')  )
//      {
//
//           bot.sendMessage(CHAT_ID, Start_buff); 
//           delay(100);
//          
//      }
// }

}
}
void buffer_clear()
{
  for(z=0;z<60;z++)
  {
    Start_buff[z]='\0';
//    textmessage[z]='\0';
    
  } 
}
void buffer1_clear()
{
  for(z=0;z<5;z++)
  {
   
   textmessage[z]='\0';
    
  } 

}
//void TEST()
//{
// Serial.begin(9600);
//    Serial.println("Starting TelegramBot...");
//
//    configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
//  client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org
//const char* ssid = "vivo1802 ";
//const char* password = "password";
//
//// Initialize Telegram BOT
//#define BOTtoken "5339691493:AAEWdnw4-gZCQEAe2dPmKhRVUOWt15QgC-o"  // your Bot Token (Get from Botfather)
//
//  // Attempt to connect to Wifi network:
//  Serial.print("Connecting Wifi: ");
//  Serial.println(ssid);
//
//  WiFi.mode(WIFI_STA);
//  WiFi.begin(ssid, password);
//
//  while (WiFi.status() != WL_CONNECTED) {
//    Serial.print(".");
//    delay(500);
//  }
//
//  Serial.println("");
//  Serial.println("WiFi connected");
//  Serial.print("IP address: ");
//  Serial.println(WiFi.localIP());
//
//  bot.sendMessage(CHAT_ID, "NIGHT PATROLLING ROBOT");
//
//
////MESSAGE_SEND();
//WAITING();
//  
////while(1) {
////    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
////
////    while (numNewMessages)
////    {
////      Serial.println("got response");
////     handleNewMessages(numNewMessages);
////      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
////
////
////      
////    }

// String text = bot.messages[i].text;
//
////    String from_name = bot.messages[i].from_name;
////    if (from_name == "")
////      from_name = "Guest";
//
//    if (text == "START")
//    {
// 
//      bot.sendMessage(CHAT_ID, "Led is ON", "");
//    }

//        if (text.equalsIgnoreCase("START")) {              // if the received message is "LIGHT ON"...
//                                        // turn on the LED (inverted logic!)
//            bot.sendMessage(CHAT_ID, "NON INVESSIVE BLOOD GLUCOSE MONITORING...  ");  // notify the sender
////         Serial.println(msg.sender.id);
//          WAITING();
//        }
//         else {                                                    // otherwise...
//            // generate the message for the sender
//            String reply;
//            reply = (String)"Welcome " + msg.sender.username + (String)". Try START";
//            bot.sendMessage(msg.sender.id, reply);             // and send it
//            
//        }
  //  }
    // wait 500 milliseconds
    //delay(500);
//}
 
  


void handleNewMessages(int numNewMessages)
{
  Serial.print("handleNewMessages ");
  Serial.println(numNewMessages);

//  for (int i = 0; i < numNewMessages; i++)
//  {
//    String chat_id = bot.messages[i].chat_id;
    String text = bot.messages[i].text;

//    String from_name = bot.messages[i].from_name;
//    if (from_name == "")
//      from_name = "Guest";

    if (text == "START")
    {
 
      bot.sendMessage(CHAT_ID, "Led is ON", "");
    }

//  }
}

///*
//  Rui Santos
//  Complete project details at https://RandomNerdTutorials.com/telegram-esp8266-nodemcu-motion-detection-arduino/
//  
//  Project created using Brian Lough's Universal Telegram Bot Library: https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot
//*/
//
//#include <ESP8266WiFi.h>
//#include <WiFiClientSecure.h>
//#include <UniversalTelegramBot.h>
//#include <ArduinoJson.h>
//
//// Replace with your network credentials
//const char* ssid = "smile123";
//const char* password = "12345678";
//
//// Initialize Telegram BOT
//#define BOTtoken "5344660356:AAHQfgW0d2RadVZtZB_LNIkp7YKJ3vj_nlQ"  // your Bot Token (Get from Botfather)
//
//// Use @myidbot to find out the chat ID of an individual or a group
//// Also note that you need to click "start" on a bot before it can
//// message you
//#define CHAT_ID "1302360775"
//
//X509List cert(TELEGRAM_CERTIFICATE_ROOT);
//WiFiClientSecure client;
//UniversalTelegramBot bot(BOTtoken, client);
//
//const int motionSensor = 14; // PIR Motion Sensor
//bool motionDetected = false;
//
//// Indicates when motion is detected
//void ICACHE_RAM_ATTR detectsMovement() {
//  //Serial.println("MOTION DETECTED!!!");
//  motionDetected = true;
//}
//
//void setup() {
//  Serial.begin(115200);
//  configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
//  client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org
//
//  // PIR Motion Sensor mode INPUT_PULLUP
//  pinMode(motionSensor, INPUT_PULLUP);
//  // Set motionSensor pin as interrupt, assign interrupt function and set RISING mode
//  attachInterrupt(digitalPinToInterrupt(motionSensor), detectsMovement, RISING);
//
//  // Attempt to connect to Wifi network:
//  Serial.print("Connecting Wifi: ");
//  Serial.println(ssid);
//
//  WiFi.mode(WIFI_STA);
//  WiFi.begin(ssid, password);
//
//  while (WiFi.status() != WL_CONNECTED) {
//    Serial.print(".");
//    delay(500);
//  }
//
//  Serial.println("");
//  Serial.println("WiFi connected");
//  Serial.print("IP address: ");
//  Serial.println(WiFi.localIP());
//
//  bot.sendMessage(CHAT_ID, "Bot started up", "");
//}
//
//void loop() {
//  if(motionDetected){
//    bot.sendMessage(CHAT_ID, "Motion detected!!", "");
//    Serial.println("Motion Detected");
//    motionDetected = false;
//  }
