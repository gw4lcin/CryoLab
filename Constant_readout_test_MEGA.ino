//COUNTER 0
int Q1=22;
int Q2=23;
int Q3=24;
int Q4=25;
int Q5=26;
int Q6=27;
int Q7=28;
int Q8=29;
int Q9=30;
int Q10=31;
int Q11=32;
int Q12=33;

//COUNTER A
int Q13=34;
int Q14=35;
int Q15=36;
int Q16=37;
int Q17=38;
int Q18=39;
int Q19=40;
int Q20=41;
int Q21=42;
int Q22=43;
int Q23=44;
int Q24=45;

int RESET=50; //reset pin for the counters;
int CNT_ENABLE=51; //steering with the gate of the input signal; HIGH = open

bool readings[24]; //table of readings

long cnt=0;
long freq=0;

void setup() {
  pinMode(Q1, INPUT);
  pinMode(Q2, INPUT);
  pinMode(Q3, INPUT);
  pinMode(Q4, INPUT); 
  pinMode(Q5, INPUT);
  pinMode(Q6, INPUT);
  pinMode(Q7, INPUT);
  pinMode(Q8, INPUT);
  pinMode(Q9, INPUT);
  pinMode(Q10, INPUT);
  pinMode(Q11, INPUT);
  pinMode(Q12, INPUT);
  pinMode(Q13, INPUT);
  pinMode(Q14, INPUT);
  pinMode(Q15, INPUT);
  pinMode(Q16, INPUT);
  pinMode(Q17, INPUT);
  pinMode(Q18, INPUT);
  pinMode(Q19, INPUT);
  pinMode(Q20, INPUT);
  pinMode(Q21, INPUT);
  pinMode(Q22, INPUT);
  pinMode(Q23, INPUT);
  pinMode(Q24, INPUT);

  pinMode(RESET, OUTPUT);
  digitalWrite(RESET, LOW);
  digitalWrite(RESET, HIGH);
  digitalWrite(RESET, LOW);

  pinMode(CNT_ENABLE, OUTPUT);
  digitalWrite(CNT_ENABLE, LOW); //lets start with the gates closed

  TCCR1A = 0;
  TCCR1B = 0; 
  
  OCR1A = 25000;
  OCR1B = 5000;
  
  TCCR1B |= (1<<CS11) | (1<<WGM12); //preskaler 8
  TIMSK1 |= (1<<OCIE1A) | (1 << OCIE1B); //timer overflow in CTC mode
  
  Serial.begin(9600);
}

void loop() {
  
}

ISR(TIMER1_COMPA_vect){
  cnt = 0;
  digitalWrite(CNT_ENABLE, LOW);
  int n = 22;
  long k = 1;
  for(int i=0; i<22; i++){
    readings[i] = digitalRead(n);
    n = n + 1;
    cnt = cnt + readings[i]*k;
    k = k*2;
  }
  freq = cnt*100;
  Serial.println(freq);
}

ISR(TIMER1_COMPB_vect){
  digitalWrite(RESET, LOW);
}
