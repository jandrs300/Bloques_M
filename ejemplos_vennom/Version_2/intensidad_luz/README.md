# Intensidad de Luz

El objetivo de esta práctica es programar y controlar la intensidad de la luz del LED (color Verde) con una frecuencia de 1 segundo.


www.insani-loja.com

| Autor de la práctica |
| Juan Andrés (INSANI) |


## Materiales
- Placa Vennom V2.
- Cable USB - miniUSB

![Placa de programacion Vennom](https://github.com/jandrs300/Bloques_M/blob/master/ejemplos_vennom/Version_2/placa-version2.png)

## Programación en MBLOCK
Al ejecutar el código que vemos a continuación tendremos el resultado de la práctica.

![programa en mblock luces LEDS Arduino](https://github.com/jandrs300/Bloques_M/blob/master/ejemplos_vennom/Version_2/intensidad_luz/intensidad%20de%20luz.png)


## Programación en Arduino
Para el control de intensidad de luz usaremos la función *analogWrite()* mas información [funcion analogWrite()](https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/)
 
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

