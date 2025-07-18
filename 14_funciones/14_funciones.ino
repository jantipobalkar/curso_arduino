void setup() {
  Serial.begin(115200);  
  delay(500);
  
  
  /* int numero = sumar(3, 2);
  Serial.println(numero);
  */
  int acumulador = 0; 
  int valores[] = {1,3,4,5,8,12,34};

  for(int i = 0; i < 7; i++){

    acumulador = sumar(acumulador, valores[i]);

    Serial.println(acumulador);

  }
  char cadena[] = "Hola mundo";
  int largo = longitudCadena(cadena);
  Serial.println(largo);

  char * reves;
  reves = leerReves(cadena);
  Serial.println(reves);


  
}

void loop() {
  // put your main code here, to run repeatedly:

}

// Fuinciones 

int sumar(int primero, int segundo){

  int temp = primero + segundo;

  return temp; 


}

// Funcion calcular longitud

int longitudCadena(char cadena[]){

  int i = 0;

  while (cadena[i] != '\0') {

    i++;


  
  } 
return i;

}

// Funcion leer del reves

char * leerReves(char * cadena){
  int largo = longitudCadena(cadena);
  // variable para guardar la cadena
  char temp[largo];
   
  for(int i = 0; i < largo; i++){

    temp[largo - 1 - i] = cadena[i];
    
  }
}



