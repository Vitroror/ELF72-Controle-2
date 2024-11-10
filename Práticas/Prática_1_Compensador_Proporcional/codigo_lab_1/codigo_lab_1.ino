float Vref=2;
float Vsaida;
float u;
float erro, c;

int sensorPin = A0;
int outPin = 6;


void setup() {
  pinMode(outPin, OUTPUT); // configura pino como saída
}

void loop() {
  Vsaida = analogRead(sensorPin)*(5.0/1024.0);  // ajusta ganho
  erro=Vref-Vsaida;
  c=  1.598;   // colocar  o  compensador aqui, ele função do erro
       
 u=c*erro*255.0/5.0;   // ajusta ganho

 if (u>255) {analogWrite(6, 255); u=255;} else if(u<0) {analogWrite(6,0); u=0;} else {analogWrite(6,u);}   
 
 delay(5);   //Ts=5ms
 }
