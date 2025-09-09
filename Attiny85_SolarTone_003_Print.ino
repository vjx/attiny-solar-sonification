void setup() {
  Serial.begin(9600);
  
}

void loop() {
  int sum = 0; // Variável para armazenar a soma dos valores
  const int numReadings = 10; // Número de leituras para a média
  const int freq = 2000; // Frequência.
  
  // Realiza 3 leituras consecutivas com pequeno atraso
  for (int i = 0; i < numReadings; i++) {
    sum += analogRead(A2);
    delay(5); // Pequeno atraso entre as leituras
  } 
  int average = sum / numReadings; // Calcula a média
  int pause = 0;

  //Testa Condições e escolhe uma pausa:
  if (average <= 200) {
    pause = 1100;
  }
  else if (average > 200 && average <= 250) {
    pause = 600;
  }
  else if (average > 250 && average <= 300) {
    pause = 500;
  }
  else if (average > 300 && average <= 350) {
    pause = 450;
  }
  else if (average > 350 && average <= 450) {
    pause = 300;
  }
else if (average > 450 && average <= 500) {
    pause = 200;
  }
else if (average > 500 && average <= 520) {
    pause = 60;
  }
  else if (average > 520 && average <= 600) {
    pause = 30;
  }
  else { // Se for mais de 600:
    pause = 10;
   
  }
  

  tone(PB3,freq, 7);
  Serial.println(average);
  delay(pause);
}
