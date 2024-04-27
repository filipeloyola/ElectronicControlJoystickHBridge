
#define maximo 255 //regula o valor máximo de giro no motor, ou seja 255=100% de PWM 
#define fator 1  // Fator de calibraão de giro de um motor em relação ao outro. Isto foi necessário, pois, o motor 2 puxa mais corrente do que o motor 1.

int RPWM_DRIVER1=5;
int LPWM_DRIVER1=6;
int L_EN_DRIVER1=7;
int R_EN_DRIVER1=8;

int RPWM_DRIVER2=9;
int LPWM_DRIVER2=10;
int L_EN_DRIVER2=11;
int R_EN_DRIVER2=12;

int valorx = 0; //Armazena o valor lido do potenciometro - Eixo X  
int valory = 0; //Armazena o valor lido do potenciometro - Eixo Y  
//int valorz = 0; //Armazena o valor lido do botão - Eixo Z 
int estado = 0;
int est_ant = 0; 

void setPWMfrequency(int freq){
   TCCR0B = TCCR0B & 0b11111000 | freq;//Ajuste de frequência PWM - timer 0 pinos 5 e 6
   TCCR1B = TCCR1B & 0b11111000 | freq;//timer 1 pinos 9 e 10
  }
 
void MotorActiveStatus(char Side,boolean s){
    boolean state=s;
    if(Side=='R'){
      digitalWrite(R_EN_DRIVER1,s);
      digitalWrite(R_EN_DRIVER2,s);
      }
    if(Side=='L'){
      digitalWrite(L_EN_DRIVER1,s);
      digitalWrite(L_EN_DRIVER2,s);
      }    
  }
  
void setMotor1(char side,byte pwm){
   if(side=='R'){
      analogWrite(RPWM_DRIVER1,pwm);
      }
   if(side=='L'){
      analogWrite(LPWM_DRIVER1,pwm);
      }
  }

void setMotor2(char side,byte pwm){
   if(side=='R'){
      analogWrite(RPWM_DRIVER2,pwm);
      }
   if(side=='L'){
      analogWrite(LPWM_DRIVER2,pwm);
      }
  }

void closeMotor1(void){
     Serial.print(" CLOSE Motor1 ");
     setMotor1('R',0);
     setMotor1('L',0);
     delay(100);
     }

void closeMotor2(void){
     Serial.print(" CLOSE Motor2 ");
     setMotor2('R',0);
     setMotor2('L',0);
     delay(100);
     }

void moveFrente(int valorx){

    Serial.print(" FRENTE ");
   
    if(valorx>=550 && valorx<600){
      estado=1;
    }
    if(valorx>=600 && valorx<700){
      estado=2;
    }
    if(valorx>=700 && valorx<800){
      estado=3;
    }
    if(valorx>=800 && valorx<900){
      estado=4;
    }
    if(valorx>=900 && valorx<1000){
      estado=5;
    }
    if(valorx>=1000){
      estado=6;
    }
    
 switch(estado){   
  
    case 1:
      setMotor1('R',0.50*maximo);
      setMotor2('R',fator*0.50*maximo);
      break;
      
    case 2:
      setMotor1('R',0.60*maximo);
      setMotor2('R',fator*0.60*maximo);
      break;      
      
    case 3:
      setMotor1('R',0.70*maximo);
      setMotor2('R',fator*0.70*maximo); 
      break;
   
    case 4:
      setMotor1('R',0.80*maximo);
      setMotor2('R',fator*0.80*maximo); 
      break;
      
    case 5:
      setMotor1('R',0.90*maximo);
      setMotor2('R',fator*0.90*maximo);  
      break;
      
    case 6:
      setMotor1('R',maximo);
      setMotor2('R',fator*maximo);
      break;
  }
}

void moveTras(int valorx){

  Serial.print(" Ré ");

  if(valorx<=450 && valorx>400){
    estado=1;
    }
  if(valorx<=400 && valorx>300){
    estado=2;
    }
  if(valorx<=300 && valorx>200){
    estado=3;
    }
  if(valorx<=200 && valorx>100){
    estado=4;
    }
  if(valorx<=100){
    estado=5;
    }
  
  switch(estado){
    case 1:
      setMotor1('L',0.50*maximo);
      setMotor2('L',0.50*fator*maximo);
      break;
      
    case 2:
      setMotor1('L',0.60*maximo);
      setMotor2('L',0.60*fator*maximo);   
      break;
      
    case 3:
      setMotor1('L',0.70*maximo);
      setMotor2('L',0.70*fator*maximo); 
      break;
      
    case 4:
      setMotor1('L',0.80*maximo);
      setMotor2('L',0.80*fator*maximo);  
      break;
      
    case 5:
      setMotor1('L',0.90*maximo);
      setMotor2('L',0.90*fator*maximo); 
      break;
    }  
  }

  void moveDir(int valory){
     Serial.print(" Direita ");
   
    if(valory>=550 && valory<600){
      estado=1;
    }
    if(valory>=600 && valory<700){
      estado=2;
    }
    if(valory>=700 && valory<800){
      estado=3;
    }
    if(valory>=800 && valory<900){
      estado=4;
    }
    if(valory>=900 && valory<1000){
      estado=5;
    }
    if(valory>=1000){
      estado=6;
    }
    
 switch(estado){   
  
    case 1:
      setMotor1('L',0.50*maximo);
      setMotor2('R',fator*0.50*maximo);  
      break;
      
    case 2:
      setMotor1('L',0.40*maximo);
      setMotor2('R',fator*0.40*maximo);
   
      break;      
      
    case 3:
      setMotor1('L',0.50*maximo);
      setMotor2('R',fator*0.50*maximo);  
      break;
   
    case 4:
      setMotor1('L',0.60*maximo);
      setMotor2('R',fator*0.60*maximo); 
      break;
      
    case 5:
      setMotor1('L',0.70*maximo);
      setMotor2('R',fator*0.70*maximo); 
      break;
      
    case 6:
      setMotor1('L',0.80*maximo);
      setMotor2('R',0.80*fator*maximo);
      break;
  }
}

  void moveEsq(int valory){
    Serial.print(" Esquerda ");
   
   if(valory<=450 && valory>400){
    estado=1;
    }
  if(valory<=400 && valory>300){
    estado=2;
    }
  if(valory<=300 && valory>200){
    estado=3;
    }
  if(valory<=200 && valory>100){
    estado=4;
    }
  if(valory<=100){
    estado=5;
    }
  
  switch(estado){
    case 1:
      setMotor1('R',0.40*maximo);
      setMotor2('L',0.40*fator*maximo);  
      break;
      
    case 2:
      setMotor1('R',0.50*maximo);
      setMotor2('L',0.50*fator*maximo);   
      break;
      
    case 3:
      setMotor1('R',0.60*maximo);
      setMotor2('L',0.60*fator*maximo); 
      break;
      
    case 4:
      setMotor1('R',0.70*maximo);
      setMotor2('L',0.70*fator*maximo);   
      break;
      
    case 5:
      setMotor1('R',0.80*maximo);
      setMotor2('L',0.80*fator*maximo); 
      break;
  }
}

void move1quad(int valorx, int valory){
    Serial.print(" 1ºquadrante ");
    
    closeMotor1(); 
    
if(valory>=550 && valory<600){
      estado=1;
    }
    if(valory>=600 && valory<700){
      estado=2;
    }
    if(valory>=700 && valory<800){
      estado=3;
    }
    if(valory>=800 && valory<900){
      estado=4;
    }
    if(valory>=900 && valory<1000){
      estado=5;
    }
    if(valory>=1000){
      estado=6;
    }
    
 switch(estado){   
  
    case 1:    
      setMotor2('R',fator*0.50*maximo); 
      break;
      
    case 2:
      setMotor2('R',fator*0.60*maximo);     
      break;      
      
    case 3:
      setMotor2('R',fator*0.70*maximo); 
      break;
   
    case 4:
      setMotor2('R',fator*0.80*maximo);
      break;
      
    case 5:
      setMotor2('R',fator*0.90*maximo); 
      break;
      
    case 6:
      setMotor2('R',fator*maximo);
      break;
  }
}

void move2quad(int valorx, int valory){
  closeMotor2();
  Serial.print(" 2º Quadrante ");
   
   if(valory<=450 && valory>400){
    estado=1;
    }
  if(valory<=400 && valory>300){
    estado=2;
    }
  if(valory<=300 && valory>200){
    estado=3;
    }
  if(valory<=200 && valory>100){
    estado=4;
    }
  if(valory<=100){
    estado=5;
    }
  
  switch(estado){
    case 1:
      setMotor1('R',0.60*maximo); 
      break;
      
    case 2:
      setMotor1('R',0.70*maximo);  
      break;
      
    case 3:
      setMotor1('R',0.80*maximo);
      break;
      
    case 4:
      setMotor1('R',0.90*maximo);   
      break;
      
    case 5:
      setMotor1('R',maximo);
      break;
  }
}

void move3quad(int valorx, int valory){

  Serial.print(" 3º Quadrante ");

  closeMotor2();
  //closeMotor1();//desligado porque pode inverter o sentido de rotação

if(valory<=450 && valory>400){
    estado=1;
    }
  if(valory<=400 && valory>300){
    estado=2;
    }
  if(valory<=300 && valory>200){
    estado=3;
    }
  if(valory<=200 && valory>100){
    estado=4;
    }
  if(valory<=100){
    estado=5;
    }
  
  switch(estado){
    case 1:
      setMotor1('L',0.60*maximo); 
      break;
      
    case 2:
      setMotor1('L',0.70*maximo);   
      break;
      
    case 3:
      setMotor1('L',0.80*maximo);
      break;
      
    case 4:
      setMotor1('L',0.90*maximo);  
      break;
      
    case 5:
      setMotor1('L',maximo);
      break;
  }
}


void move4quad(int valorx, int valory){
  
  Serial.print(" 4º Quadrante");
  
  closeMotor1(); 
  //closeMotor2();// presisa ser desligado, pois será invertido o sentido de rotação
  delay(100);
  
  if(valory>=550 && valory<600){
    estado=1;
    }
  if(valory<700 && valory>=600){
    estado=2;
    }
  if(valory<800 && valory>=700){
    estado=3;
    }
  if(valory<900 && valory>=800){
    estado=4;
    }
  if(valory<1000 && valory>=900){
    estado=5;
    }
  if(valory>=1000){
    estado=6;
  }
  
  switch(estado){
    case 1:
      setMotor2('L',0.50*fator*maximo);  
      break;
      
    case 2:
      setMotor2('L',0.60*fator*maximo);   
      break;
      
    case 3:
      setMotor2('L',0.70*fator*maximo); 
      break;
      
    case 4:
      setMotor2('L',0.80*fator*maximo);   
      break;
      
    case 5:
      setMotor2('L',0.9*fator*maximo); 
      break;
    case 6:
      setMotor2('L',fator*maximo);
      break;
  }
}
  
     
void setup() {
  
  setPWMfrequency(0x01);// timer 0, 3.92KHz
  
  for(int i=5;i<13;i++){
    pinMode(i,OUTPUT);
    }
  
  for(int i=5;i<13;i++){
    digitalWrite(i,LOW);
    }
    
   delay(1000);
   
   MotorActiveStatus('R',true);
   MotorActiveStatus('L',true);
   
   Serial.begin(9600);
   est_ant = 0;
  }

void loop() {

   //Le o valor do potenciometro ligado à porta analogica A0 Eixo X  e A1 Eixo Y
  valorx = analogRead(0);
  valory = analogRead(1);
  Serial.print("    Loop    ");
  
  //Mostra o valor dos eixos X e Y no monitor serial  
  Serial.print("   X:");
  Serial.print(valorx, DEC);
  Serial.print("   Y:");
  Serial.print(valory, DEC);
 
  
  if(valory>450 && valory<550){
    if(valorx>=550){
      //Função Movimento para frente 
      moveFrente(valorx);
    }
    if(valorx<=450){
      //Função Movimento para trás Movimento para trás
      moveTras(valorx);
    }
    if(valorx>450 && valorx<550){
      //caso 3 Parado
      closeMotor1();
      closeMotor2();
    }
  }
  else{
    if(valorx>450 && valorx<550){
    //Caso4 Movimento Sobre o eixo
      if(valory<450){
      moveEsq(valory);        
      }
      if(valory>550){
      moveDir(valory);
      }
    }
    if(valorx>=550 && valory>=550){
    //Movimento 1º Quadrante
      move1quad(valorx,valory);
      }
    if(valorx>=550 && valory<=450){
    //Movimento 2º Quadrante
      move2quad(valorx,valory);
      }
    if(valorx<=450 && valory<=450){
      //Movimento 3º Quadrante
      move3quad(valorx, valory);
      }
    if(valorx<=450 && valory>=550){
    //Movimento 4º Quadrante
      move4quad(valorx, valory);
      }       
  }
delay(100);
}

