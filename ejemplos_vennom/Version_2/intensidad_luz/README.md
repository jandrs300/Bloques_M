# Intensidad de Luz

El objetivo de esta práctica es programar y controlar la intensidad de la luz del LED (color Verde) con una frecuencia de 1 segundo.


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

## Esquema eléctrico
Se conecta el cable negro (negativo) del LED al pin GND de la placa de arduino y el cable verde  al pin  5 de la placa de arduino.

![Esquema de conexión](https://github.com/jandrs300/Bloques_M/blob/master/ejemplos_vennom/Version_2/intensidad_luz/intensidad_luz_f.png)



## Programación en MBLOCK
Al ejecutar el código que vemos a continuación tendremos el resultado de la práctica.

![programa en mblock intensidad de LEDS Arduino](https://github.com/jandrs300/Bloques_M/blob/master/ejemplos_vennom/Version_2/intensidad_luz/intensidad%20de%20luz.png)


## Simulación
Para la simulación utilizamos un arduino UNO, es **igual** al arduino nano, la única diferencia es el tamaño, los pines y demás son los mismos.

A continuación podremos ver la simulación del programa realizado.  [Clic para ver la simulación](https://www.tinkercad.com/things/d2fQJsbFrZA )
 

## Programación en Arduino
Para el control de intensidad de luz usaremos la función *analogWrite()* más información [función analogWrite()](https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/)
 
- Primero declaramos el pin 5 como salida.
- Dentro de un bucle *loop()*
	- *Activamos* el pin 5 (LED Verde) con un valor de 0
	- Esperamos 1000 milisegundos
	- *Activamos* el pin 5 (LED Verde) con un valor de 50
	- Esperamos 1000 milisegundos
    - *Activamos* el pin 5 (LED Verde) con un valor de 100
	- Esperamos 1000 milisegundos
    - *Activamos* el pin 5 (LED Verde) con un valor de 150
	- Esperamos 1000 milisegundos
    - *Activamos* el pin 5 (LED Verde) con un valor de 255
	- Esperamos 1000 milisegundos


```
void setup() {
  pinMode(5, OUTPUT);
}

void loop() {
  analogWrite(5, 0);
  delay(1000);
  analogWrite(5, 50);
  delay(1000);
  analogWrite(5, 100);
  delay(1000);
  analogWrite(5, 150);
  delay(1000);
  analogWrite(5, 255);
  delay(1000);

}

```

