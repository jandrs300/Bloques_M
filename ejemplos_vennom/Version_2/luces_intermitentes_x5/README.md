# Luz Intermitente x5

El objetivo de esta práctica es realizar la siguiente secuencia.
- Encender y Apagar el LED (ROJO) 5 veces, con frecuencia de 1 segundo.
- Encender el LED RGB de color **MORADO** durante 1 segundo
- Encender y Apagar el LED (Verde) 5 veces, con frecuencia de 1 segundo.
- Encender el LED RGB de color **MORADO** durante 1 segundo
- Encender y Apagar el LED (Azul) 5 veces, con frecuencia de 1 segundo.
- Encender el LED RGB de color **MORADO**


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
- 1 LED RGB Cátodo Común
- 1 Resistor de 220 Ohm

## Esquema eléctrico

![Placa arduino encender LED RGB catado](https://github.com/jandrs300/Bloques_M/blob/master/ejemplos_vennom/Version_2/luces_intermitentes_x5/luces_intermitentes_x5_c.PNG)


## Programación en MBLOCK
Al ejecutar el código que vemos a continuación tendremos el resultado de la práctica.

![programa en mblock luces intermitentes x5 LEDS Arduino](https://github.com/jandrs300/Bloques_M/blob/master/ejemplos_vennom/Version_2/luces_intermitentes_x5/luces_intermitentes_x5.png)


## Simulación
Para la simulación utilizamos un arduino UNO, es **igual** al arduino nano, la única diferencia es el tamaño, los pines y demás son los mismos.

A continuación podremos ver la simulación del programa realizado.  [Clic para ver la simulación](https://www.tinkercad.com/things/cEBX1utyiVz)


## Programación en Arduino
Para el correcto desarrollo de la práctica hacemos uso de la función digitalWrite() y analogWrite().


- Primero declaramos el pin 3,5 y 6 como salida.
- Creamos un bucle para que se repita 5 veces la secuencia.
   - *Activamos* el pin 6 (LED Rojo)
   - Esperamos 1 segundo
   - *Desactivamos* el pin 6 (LED Rojo)
   - Esperamos 1 segundo
- Activamos el pin 3, 5 y 6 con sus respectivos valores para obtener el color *Morado* 
- Esperamos 1000 milisegundos
- *Desactivamos* el pin 3, 5 y 6 para la nueva secuencia 
- Creamos un bucle para que se repita 5 veces la secuencia.
   - *Activamos* el pin 5 (LED Verde)
   - Esperamos 1 segundo
   - *Desactivamos* el pin 5 (LED Verde)
   - Esperamos 1 segundo
- Activamos el pin 3, 5 y 6 con sus respectivos valores para obtener el color *Morado* 
- Esperamos 1000 milisegundos
- *Desactivamos* el pin 3, 5 y 6 para la nueva secuencia 
- Creamos un bucle para que se repita 5 veces la secuencia.
   - *Activamos* el pin 3 (LED Azul)
   - Esperamos 1 segundo
   - *Desactivamos* el pin 3 (LED Azul)
   - Esperamos 1 segundo
- Activamos el pin 3, 5 y 6 con sus respectivos valores para obtener el color *Morado* 



```
void setup() {
  pinMode(6, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  for (int i = 0; i < 5; ++i)
  {
    digitalWrite(6, 1);
    delay(1000);
    digitalWrite(6, 0);
    delay(1000);
  }
  analogWrite(6, 150);
  analogWrite(5, 0);
  analogWrite(3, 255);
  delay(1000);
  analogWrite(6, 0);
  analogWrite(5, 0);
  analogWrite(3, 0);
  for (int i = 0; i < 5; ++i)
  {
    digitalWrite(5, 1);
    delay(1000);
    digitalWrite(5, 0);
    delay(1000);
  }
  analogWrite(6, 150);
  analogWrite(5, 0);
  analogWrite(3, 255);
  delay(1000);
  analogWrite(6, 0);
  analogWrite(5, 0);
  analogWrite(3, 0);
  for (int i = 0; i < 5; ++i)
  {
    digitalWrite(3, 1);
    delay(1000);
    digitalWrite(3, 0);
    delay(1000);
  }
  analogWrite(6, 150);
  analogWrite(5, 0);
  analogWrite(3, 255);
  delay(1000);

}

void loop() {

}

```

