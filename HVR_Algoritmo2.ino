int EMG; int ENV; int GSR; float Temperatura; float TEMPL;
const int SenalEMG = A1; const int SenalENV = A2; const int SenalGSR = A7;
const int SenalTEMP = A6;  double HumanResistance;
int sensorValue = 0;

//--------------------Variables ECG, FreqC y HVC---------------------------------
const int SenalECG = A0; int LOMas = 7 ; int LOMenos = 6;
int ECG; int FreqC; int ECGANT; int umbral=430; int flag1;
unsigned long TiempoECG; unsigned long TiempoPICOECGANT; unsigned long Variabilidad;
int Cont = 0; int ContC; unsigned long Reloj; int Freq; 
const long intervalo= 60000-(8*60);

void setup() {
  Serial.begin(38400);
  Reloj= millis();  ECGANT;  Cont=0; ContC=0;  TiempoPICOECGANT=0;
}

void loop() {
  // -----------------INTERVALOS DE UN MINUTO PARA LA FC------------------------
  TiempoECG= millis();
  if (TiempoECG-Reloj>= intervalo){
    Freq= ContC; ContC=0; Cont++; Reloj=TiempoECG;}
  String FreqC= String (Freq);
  if (FreqC.length()==1){ String A= "00"; A+=FreqC; FreqC=A; }
  else if (FreqC.length()==2){ String A= "0"; A+=FreqC; FreqC=A; }


  //-----------------------LECTURA SEÑAL ECG-----------------------------------
  ECG = (0.2214 * ECG) + (0.7786 * analogRead(SenalECG));
  //ECG = (0.024241 * ECG) + (0.9758 * analogRead(SenalECG));
  String EKG = String (ECG);
  if ((digitalRead(LOMas) == 1) || (digitalRead(LOMenos) == 1)) {
    ECG = 512;    String EKG = String(ECG);  }
    
  //-------ALGORITMO DETECCION DE PICOS SUPERANDO UMBRAL-----------------------
  if (ECG-ECGANT <0 && ECGANT>umbral && TiempoECG-TiempoPICOECGANT>300){
    Variabilidad= TiempoECG-TiempoPICOECGANT;    ContC++; TiempoPICOECGANT= TiempoECG; 
    }
  ECGANT= ECG; 

  //----------  CONCATENACION VARIABILIDAD Y EKG-------------------------------(Esto se hace para que la longitud de la trama siempre sea constante)
  String HVR = String (int (60000/Variabilidad));
  if (HVR.length() == 1) {    String A = "00";    A += HVR;       HVR = A;  }
  else if (HVR.length() == 2) {    String A = "0";    A += HVR;   HVR = A;  }
  //else if (HVR.length() == 3) {    String A = "0";    A += HVR;    HVR = A;  }
  if (EKG.length() == 1) {    String A = "00";    A += EKG;    EKG = A;  }
  else if (EKG.length() == 2) {    String A = "0";    A += EKG;    EKG = A;  }


  //---------------------RESPUSTA GALVANICA DE LA PIEL---------------------------
  float gsr_average=analogRead(SenalGSR);
  HumanResistance= int (((1024+(2*gsr_average))/(512-gsr_average))*100);
  String RHO= String (HumanResistance,0);
  

  if (RHO.length()==1){ String A= "000"; A+=RHO; RHO=A; }
  else if (RHO.length()==2){ String A= "00"; A+=RHO; RHO=A; }
  else if (RHO.length()==3){ String A= "0"; A+=RHO; RHO=A; }
  
  if (gsr_average>509){
    RHO="----";
    }
  
  String GSR= String (gsr_average,0);
  if (GSR.length()==1){ String A= "00"; A+=GSR; GSR=A; }
  else if (GSR.length()==2){ String A= "0"; A+=GSR; GSR=A; }

  //------------------------------TEMPERATURA-----------------------------------------------------------------------------------------------------------
  //--------------------------------------------------------------------------------------------------------------------------------
  //int TEMP = (0.9044 * TEMP) + (0.09564 * analogRead(SenalTEMP));
  //Temperatura= (0.9*Temperatura)+(0.1*analogRead(SenalTEMP));
  //float Temp= (1.57142 * ( Temperatura* 0.0048828125)) + 34.0428;
  float medida = ((9*analogRead(SenalTEMP)+medida)/10)*0.0048828;
  float Temperatura=medida*1.0888+34.193;
  String TempStr = String (Temperatura , 1);
  if (medida<0.5){ String A= "----"; TempStr=A; }
  //------------------------------EMG Y ENV---------------------------

  String EMG = String (analogRead(SenalEMG));
  String ENV = String (analogRead(SenalENV));
  
  if (EMG.length() == 1) {    String B = "00";    B += EMG;    EMG = B;}
  else if (EMG.length() == 2) {    String B = "0";    B += EMG;    EMG = B;  }

  if (ENV.length() == 1) {    String C = "00";    C += ENV;    ENV = C;  }
  else if (ENV.length() == 2) {    String C = "0";    C += ENV;    ENV = C;  }
  
  //------------------COMUNICACION SERIAL--------------------------------------
  //String Vector[] = { String(FreqC), HVR, EKG, "4"}; //Para 9600 baudios
  String Vector[] = { EKG, HVR, EMG, ENV, GSR, RHO, TempStr, ""};
  Serial.print (Vector[0]);  Serial.print(" ");
  Serial.print (Vector[1]);  Serial.print(" ");
  Serial.print (Vector[2]);  Serial.print(" ");
  Serial.print (Vector[3]);  Serial.print(" ");
  Serial.print (Vector[4]);  Serial.print(" ");
  Serial.print (Vector[5]);  Serial.print(" ");
  Serial.print (Vector[6]);  Serial.println(" ");
  delay(1);
}
