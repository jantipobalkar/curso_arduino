


void setup() {
 Serial.begin(115200);
int limite = 10;
int contador = 0;

/*for(int i = 0; i < 10; i++){

  Serial.println("Número: " + String(i));
}*/

/*for(int i = 0; i <= 100; i += 2){
  Serial.println("Números: " + String(i));
}*/

/*for(int i = 100; i > 0; i--){
  Serial.println("Números: " + String(i));
}*/

/*
String salida = "";

for(int fila = 0; fila < 10; fila++){
  for(int col = 0; col < 10; col++){
    //Serial.print(String(fila) + ":" + String(col) + "\t");
    salida += (String(fila) + ":" + String(col) + "\t");
  }
  //Serial.println();
  salida += "\n";
}
Serial.print(salida);*/
/*
d
for(;;){

  if (contador == limite){
    break;
  }
Serial.print("Infinito: ");
Serial.println(contador);
contador ++;

}*/

while (contador < limite) {
Serial.print("Infinito: ");
Serial.println(contador);
contador ++;
}


}

void loop() {
  

}
