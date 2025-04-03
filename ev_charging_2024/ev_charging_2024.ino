void setup()
{
  
  //IR's
      pinMode(2, INPUT);
      pinMode(3, INPUT);
      pinMode(4, INPUT);
      pinMode(5, INPUT);
      pinMode(6, INPUT);
      pinMode(7, INPUT);
      pinMode(8, INPUT);
      pinMode(9, INPUT);
     
    //Relays
         pinMode(10, OUTPUT);
      digitalWrite(10, HIGH);
      pinMode(11, OUTPUT);
      digitalWrite(11, HIGH);
      pinMode(12, OUTPUT);
      digitalWrite(12, HIGH);
      pinMode(A0, OUTPUT);
      digitalWrite(A0, HIGH);
      
      
    //Motors
      pinMode(A1, OUTPUT);
      digitalWrite(A1, HIGH);
      pinMode(A2, OUTPUT);
      digitalWrite(A2, HIGH);
      pinMode(A3, OUTPUT);
      digitalWrite(A3, HIGH);
      pinMode(A4, OUTPUT);
      digitalWrite(A4, HIGH);

      
   
}

void loop()
{  




   
     if(digitalRead(2)==0)
     {
        digitalWrite(10, LOW);
       
     }
     if(digitalRead(2)==1)
     {
       digitalWrite(10, HIGH);
       
     }
     if(digitalRead(3)==0)
     {
        digitalWrite(11, LOW);
       
     }
     if(digitalRead(3)==1)
     {
       digitalWrite(11, HIGH);
       
     }
       if(digitalRead(4)==0)
     {
        digitalWrite(12, LOW);
       
     }
     if(digitalRead(4)==1)
     {
       digitalWrite(12, HIGH);
       
     }
     if(digitalRead(5)==0)
     {
        digitalWrite(A0, LOW);
       
     }
     if(digitalRead(5)==1)
     {
       digitalWrite(A0, HIGH);
       
     }

 if(digitalRead(6)==0)
     {
        digitalWrite(A1, LOW);
       
     }
     if(digitalRead(6)==1)
     {
       digitalWrite(A1, HIGH);
       
     }
 if(digitalRead(7)==0)
     {
        digitalWrite(A2, LOW);
       
     }
     if(digitalRead(7)==1)
     {
       digitalWrite(A2, HIGH);
       
     }
 if(digitalRead(8)==0)
     {
        digitalWrite(A3, LOW);
       
     }
     if(digitalRead(8)==1)
     {
       digitalWrite(A3, HIGH);
       
     }

      if(digitalRead(9)==0)
     {
        digitalWrite(A4, LOW);
       
     }
     if(digitalRead(9)==1)
     {
       digitalWrite(A4, HIGH);
       
     }
   delay(200);
      

}
