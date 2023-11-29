// HW11
int STATE_0 = 0;
int STATE_1 = 1;

int cState = STATE_0;
int cCount = 0;


void setup() {
  pinMode(2, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int a0v = analogRead(A0);
  int a6v = analogRead(A6);
  int v2 = digitalRead(2);

  Serial.println(a6v);

  if (cState == STATE_0 && v2 == 1){
    cCount += 1;
    cState = STATE_1;
  } else if(cState == STATE_1 && v2 == 0){
    cState = STATE_0;
  }


if (a0v < 200 && a6v > 4000 && cState == STATE_1 ) {
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
} else {
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}

  delay(20);
}
