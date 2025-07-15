int dia = 1;
String nombreDia = "";

void setup() {
  Serial.begin(115200);

  switch (dia) {
  case 1: 
    nombreDia = "Lunes.";
    break;
  case 2: 
    nombreDia = "Martes.";
    break;
  case 3: 
    nombreDia = "Miercoles.";
    break;
  case 4: 
    nombreDia = "Jueves.";
    break;
  case 5: 
    nombreDia = "Viernes.";
    break;
  case 6: 
    nombreDia = "Sabado.";
    break;
  case 7: 
    nombreDia = "Domingo.";
    break;          
  }

  Serial.println("El día de la semana es " + nombreDia);

int nota = 7;
String calif = "";

switch (nota) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
    calif = "Suspendido.";
    break;
  
  case 5:
    calif = "Aprobado.";
    break;

  case 6 ... 7:
    calif = "Bien.";
    break;

  case 8 ... 9:
    calif = "Notable.";
    break;
  
  default:
    calif = "Sobre.";
    break;
  

}
Serial.println("La nota es " + calif);

}

void loop() {
  // put your main code here, to run repeatedly:

}
