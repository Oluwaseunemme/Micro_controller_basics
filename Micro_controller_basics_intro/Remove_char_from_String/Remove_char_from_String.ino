String name="my name is Oluwaseun Emmanuel",new_string="";
void setup() {
  Serial.begin(9600);
}
String replace(String data,String Word_to_replace,String word_to_insert){
  for(int x=0;x<=data.length();x++){
    if(String(data.charAt(x))==Word_to_replace){
      new_string+=word_to_insert;
      continue;
    }
    new_string+=data.charAt(x);
  }
  return new_string;
}
void loop() {
  Serial.println(replace(name,"O",""));
  while(1){}
}
