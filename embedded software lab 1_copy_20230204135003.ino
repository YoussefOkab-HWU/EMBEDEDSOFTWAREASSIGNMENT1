//This code was written by Youssef Okab master student in robotics with industial applications from heriot watt university
//The esp32-c3-wroom-02 was used for this assignment while the code was being run on arduino IDE
//In this assignment pwm pulses are simulated while mode 3(c+3) will be used as the change caused by push button 2
#define BT1 5 //Defining button 1 as pin GPIO5
#define BT2 3 //Defining button 2 as pin GPIO3
#define LED1 19 //Defining LED1 as pin GPIO19
#define LED2 18 //Defining LED2 as pin GPIO18

const int a = 1200; //stating the constant integer as a = 1200
const int b = 1100; // stating the constant integer as b = 1100
const int d = 1000; // stating the constant integer as d = 1000
byte count = count; // stating byte count is equal to variable count
int addeddelay = -50; // stating the intial addeddelay value as negative 50 (since the first pulse will have to be zero)
int BT1_state = 0; // button 1 state is intially zero
int BT2_state = 0; // button 2 state is intially zero

void setup() {
  pinMode(LED1, OUTPUT); //setting LED1 Pin as output
  pinMode(LED2, OUTPUT); //setting LED2 Pin as output
  pinMode(BT1, INPUT); //setting Push button 1 Pin as input
  pinMode(BT2, INPUT); //setting push button 2 Pin as input
}
void button_State()
{
  if (digitalRead(BT1) == HIGH){
    
     BT1_state++; // if push button 1 is pressed increase BT1_state by 1
  }
  else {
    BT1_state = BT1_state; // BT1 state stays the same
  }
  if (BT1_state>1){
    BT1_state = 0; //if BT1_state is higher than 1 then BT1_state will go back to zero
  }
  if (digitalRead(BT2) == LOW){
    BT2_state = BT2_state; 
    count = 5; //Define the count variable by 5
  }
  else{
    BT2_state++; // if push button 2 is pressed increase BT2_state by 1
    count = 8; // Define the count variable by 8
  }
  if (BT2_state>1){
    BT2_state = 0;//if BT2_state is higher than 1 then BT2_state will go back to zero
    count = 5; //Define the count variable by 5
  }
  }

void loop() {  
button_State();

  if (digitalRead(BT1) == LOW) { //If BT1 is LOW
      delay(b+d); //Wait for b+d microseconds
      digitalWrite(LED1, HIGH); //turn on LED1
      delay(2000); //Delay for 2000 microseconds
      digitalWrite(LED1, LOW); //turn off LED1
        for (byte i = 0; i < count; i++) { //turn on and off LED2 for (count) times depending on BT2_state
          addeddelay = addeddelay + 50; //every time this line is passed the addeddelay will increase by 50 microseconds
          digitalWrite(LED2, HIGH); //turn on LED2
          delay(a + addeddelay); //wait for a+addeddelay microseconds
          digitalWrite(LED2, LOW);// turn off LED2
          delay(b);// Wait for b microseconds
          if(digitalRead(BT2) == HIGH){ //if state of button 2 is high
            if (addeddelay > 349){ //the maximum addeddelay value is 349 
            addeddelay = -50; //if maximum addeddelay is reached go back to negative 50
          }
          }
          else if(digitalRead(BT2) == LOW){//if state of button 2 is low
            if (addeddelay > 199){ // the maximum addeddelay value is 199
            addeddelay = -50; //if maximum addeddelay is reached go back to negative 50       
          }
          }
    }
    
  } 
  }

