uint32_t prevMillis;
uint16_t lista[2500];
uint32_t sincValue = 512;
bool partida = 1;

void setup() {
  // declaração dos pinos de entrada/saída
  pinMode(9, OUTPUT);
  pinMode(A0, INPUT);
  delay(10);

  //uso de PWM com duty cycle de 50%
  analogWrite(9, 127);

  //Inicialização do serial com baud rate de 115200
  Serial.begin(115200);

  delay(10);

  Serial.println("Arduino MegaPlotter");
  Serial.println("Iniciando...");
}

void loop() {
  // temporização de 2 segundos
  if (((millis() - prevMillis) > 2000)and(partida)){
    prevMillis = millis();

    int8_t prevState = -1;
    
    for (uint16_t k = 0; k < 500; k++){
      int8_t state = (analogRead(A0) > sincValue);
      if ((prevState == 0)and(state == 1)) break;
      prevState = state;
    }
    
    for (uint16_t i = 0; i < 500; i++){
      lista[i] = analogRead(A0);
    }

    for (uint16_t j = 0; j < 500; j++){
      Serial.println(String(lista[j])+" 0 "+" 1100");
    }

    partida = 0;
  }
}
