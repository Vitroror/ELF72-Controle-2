float Vref=2;
float Vsaida;
float u;
float erro;
float u_anterior = 0;
float c =  0.15;   // colocar  o  compensador aqui, ele func do erro.

int sensorPin = A0;
int outPin = 6;


void setup() {
  
  //Serial.begin(9600);
  pinMode(outPin, OUTPUT); // configura pino como saída
  

}

void loop() {
  Vsaida = analogRead(sensorPin)*(5.0/1024.0);  // ajusta ganho
  erro=Vref-Vsaida;

       
 u=(c*erro+u_anterior);  // ajusta ganho

 u_anterior = u;

 u = u*255.0/5.0;

 if (u>255) {analogWrite(6, 255); u=255;} else if(u<0) {analogWrite(6,0); u=0;} else {analogWrite(6,u);}  
 delay(5);   //Ts=5ms
 }
