#include<Servo.h>

const int Trigger=2;
const int Echo=3;
double distancia();
Servo sM;
int k=0, cObj=0,O1=0,O2=0,O3=0;
double t,d,dis,daux=0,res=0,prom=0,cont=0,dX=0,iX=0,ai,af,band=0;
double a1[180],aux[3][2]={},mP[3][2]={};

 
 
void setup(){ 
  
  Serial.begin(9600);
  sM.attach(9);
  pinMode(Trigger,OUTPUT);
  pinMode(Echo,INPUT);
  digitalWrite(Trigger,LOW);
}


void loop() {
  
Serial.println("");
  Serial.println("INICIO");
  Serial.print("angulo");
Serial.print("\t");
Serial.println("distancia");

 for(int i=0;i<=180;i++){
  sM.write(i);
  delay(60);
 
 dis=distancia();

 if(dis>70){
  dis=0;
  
Serial.print(i);
Serial.print("\t");
Serial.println(dis);

a1[i]=dis;

 }
 
 else if(dis<=70){
  
 
Serial.print(i);
Serial.print("\t");
Serial.println(dis);

a1[i]=dis;
 } 
 }

 //Encuentra Objs-----------
for(int j=0;j<181;j++){
if(a1[j]>0&&a1[j-1]==0){
  ai=j;
  dX=dX+a1[j];
  iX=iX+j;
  cont++;
}
if(a1[j]>0){
  dX=dX+a1[j];
  iX=iX+j;
  cont++;
}
if(a1[j+1]==0&&a1[j]>0&&a1[j-1]!=0){
  af=j;
 
}
if((af-ai)>8 &&a1[j-1]!=0&&(af-ai)!=0){

  aux[cObj][0]=mP[cObj][0];
  aux[cObj][1]=mP[cObj][1];
  
  mP[cObj][0]=iX/cont;
  mP[cObj][1]=dX/cont;
/* 
//---------------------------------------------------

  if((aux[cObj][0]+5)>=mP[cObj][0] && (aux[cObj][0]-5)<=mP[cObj][0]&&(aux[cObj][1]+5)>=mP[cObj][1] && (aux[cObj][1]-5)<=mP[cObj][1]){
   
    if(cObj==0){
      O1++;
    }
    if(cObj==1){
      O2++;
    }
    if(cObj==2){
      O3++;
    }
//-------------------
    if(cObj==0&&O1==2){
      band=1;
    }
    if(cObj==1&&O2==2){
      band=1;
    }
    if(cObj==2&&O3==2){
      band=1;
    }
//------------------
*/
  
  
  
    Serial.println("-----------------------");
  Serial.print("OBJETO  ");
  Serial.print(cObj+1);
  Serial.println(" ENCONTRADO EN: ");

   Serial.print("ANGULO ");
   Serial.print("\t");
   Serial.println("DISTANCIA ");
  Serial.print(iX/cont);
   Serial.print("\t");
  Serial.println(dX/cont);
  dX=0;
  iX=0;
  cont=0;
  ai=0;
  af=0;
  cObj++;
  
  

  
}
  
}
//---------------
/*
//---Imprimir Valores---
for(k=0;k<3;k++){
  Serial.println();
 Serial.print(mP[k][0]);
 Serial.print(" , ");
 Serial.println(mP[k][1]);
}

for(k=0;k<3;k++){
  Serial.println();
 Serial.print(aux[k][0]);
 Serial.print(" , ");
 Serial.println(aux[k][1]);
}
//---------------
*/

dX=0;
  iX=0;
  cont=0;
  ai=0;
  af=0;
cObj=0;


delay (1000);


for(int i=180;i>=0;i--){
   sM.write(i);
  delay(20);
   }
delay(1000);
}



double distancia(){
   digitalWrite(Trigger,HIGH);
  delayMicroseconds(30);
  digitalWrite(Trigger,LOW);
  t=pulseIn(Echo,HIGH);
  d=t/59;
  return d; 
  
  }
