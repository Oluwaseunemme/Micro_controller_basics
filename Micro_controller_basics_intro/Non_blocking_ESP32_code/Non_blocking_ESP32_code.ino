QueueHandle_t cmdQueue;
QueueHandle_t cmdQueue2;

void counter(void *parameter){
  (void)parameter;
  int cmd;
  int codes[]={0,1};
  while(1){
    //Serial.println("Doing another task for now....yummy!!!!!!!");
    if (xQueueReceive(cmdQueue, &cmd, 10) == pdTRUE){
          digitalWrite(2,cmd);
          Serial.println("Value Received:"+String(cmd));
          cmd==0? xQueueSend(cmdQueue2, &codes[0], 10):xQueueSend(cmdQueue2, &codes[1], 10);
          Serial.println("Status code sent.....");
    }
    delay(50);
  }}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2 ,OUTPUT);
  pinMode(5 ,INPUT_PULLDOWN);
  xTaskCreatePinnedToCore(counter,"my_counter", 8192, NULL, 1, NULL, 0);
  cmdQueue = xQueueCreate(5, sizeof(int));
  cmdQueue2 = xQueueCreate(5, sizeof(int));
}

int cmd=0;
int status_code;
void loop() {
  // put your main code here, to run repeatedly:
   //Serial.println("Trying to send......");
   if (digitalRead(5)==1){delay(200);
    cmd==0? cmd=1:cmd=0;
    xQueueSend(cmdQueue, &cmd, 10);
    Serial.println("Value Sent:"+String(cmd));
   }
   if (xQueueReceive(cmdQueue2, &status_code, 10) == pdTRUE){
       status_code==0? Serial.println("Command received and light is off"):Serial.println("Command received and light is on");
   }
}
