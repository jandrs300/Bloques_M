# Tono Navidad

El objetivo de esta práctica es reproducir con ayuda de un zumbador (buzzer) el tono de **Jingle Bells** mediante frecuencias. 


www.insani-loja.com

| Autor de la práctica |
| Juan Andrés (INSANI) |


## Materiales
- Placa Vennom V2.
- Cable USB - miniUSB

![Placa de programacion Vennom](https://github.com/jandrs300/Bloques_M/blob/master/ejemplos_vennom/Version_2/placa-version2.png)

*En caso de no tener placa Vennom los materiales son:*
- 1 Arduino
- 1 Protoboard
- 1 Buzzer o Zumbador
- 1 LED RGB Cátodo Común
- 1 Resistor de 220 Ohm


## Esquema eléctrico

Se conecta a GND usando un resistor a pin de GND del LED y mediante cables conductores conectamos al pin 3, 5 y 6 al pin del LED RGB (ver imagen).

![Placa arduino encender LED RGB catado](https://github.com/jandrs300/Bloques_M/blob/master/ejemplos_vennom/Version_2/Navidad_buzzer/Navidad_c.PNG)


## Programación en MBLOCK
Al ejecutar el código que vemos a continuación tendremos el resultado de la práctica.

![programa en mblock buzzer tono Jingle Bells Arduino](https://github.com/jandrs300/Bloques_M/blob/master/ejemplos_vennom/Version_2/Navidad_buzzer/navidad.png)

## Simulación
Para la simulación utilizamos un arduino UNO, es **igual** al arduino nano, la única diferencia es el tamaño, los pines y demás son los mismos.

A continuación podremos ver la simulación del programa realizado.  [Clic para ver la simulación](https://www.tinkercad.com/things/6ez4tt1edD2)


## Programación en Arduino
- Declaramos el pin 3,5 y 6 como salida para los LEDs.
- Declaramos el pin 11 como salida para el Buzzer o Zumbador.
- La funcion **tone** *genera una onda cuadrada de la frecuencia especificada* en un pin, debemos especificar la duración. Para más información [función tone()](https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/)


```
void setup() {

  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {

  analogWrite(6, 0);
  analogWrite(5, 100);
  analogWrite(3, 255);
  tone(11, 330, 250); // write to buzzer
  delay(250);
  tone(11, 330, 250); // write to buzzer
  delay(250);
  tone(11, 330, 500); // write to buzzer
  delay(500);
  tone(11, 330, 250); // write to buzzer
  delay(250);
  tone(11, 330, 250); // write to buzzer
  delay(250);
  tone(11, 330, 500); // write to buzzer
  delay(500);
  tone(11, 330, 250); // write to buzzer
  delay(250);
  tone(11, 392, 250); // write to buzzer
  delay(250);
  tone(11, 262, 250); // write to buzzer
  delay(250);
  tone(11, 294, 250); // write to buzzer
  delay(250);
  tone(11, 330, 1000); // write to buzzer
  delay(1000);
  tone(11, 349, 250); // write to buzzer
  delay(250);
  tone(11, 349, 250); // write to buzzer
  delay(250);
  tone(11, 349, 250); // write to buzzer
  delay(250);
  tone(11, 349, 250); // write to buzzer
  delay(250);
  tone(11, 349, 250); // write to buzzer
  delay(250);
  tone(11, 330, 250); // write to buzzer
  delay(250);
  tone(11, 330, 250); // write to buzzer
  delay(250);
  tone(11, 330, 500); // write to buzzer
  delay(500);
  tone(11, 294, 250); // write to buzzer
  delay(250);
  tone(11, 294, 250); // write to buzzer
  delay(250);
  tone(11, 330, 250); // write to buzzer
  delay(250);
  tone(11, 294, 500); // write to buzzer
  delay(500);
  tone(11, 392, 500); // write to buzzer
  delay(500);
  analogWrite(6, 0);
  analogWrite(5, 0);
  analogWrite(3, 0);
  delay(1000);

}


```

