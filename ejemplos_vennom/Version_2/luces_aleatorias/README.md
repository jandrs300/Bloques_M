# Luces Aleatroias

El objetivo de esta práctica es combinar la intensidad de luz del LED (LED RGB Rojo-Verde-Azul) para lograr diferentes tonos de colores, este cambio de colores sera con una frecuencia de 1 segundo.


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

Se conecta a GND usando un resistor a pin de GND del LED y mediante cables conductores conectamos al pin 3, 5 y 6 al pin del LED RGB (ver imagen).

![Esquema de conexion ](https://github.com/jandrs300/Bloques_M/blob/master/ejemplos_vennom/Version_2/luces_aleatorias/luces_aleatorias_f.png)



## Programación en MBLOCK
Al ejecutar el código que vemos a continuación tendremos el resultado de la práctica.

![programa en mblock luces Aleatorias LEDS Arduino](https://github.com/jandrs300/Bloques_M/blob/master/ejemplos_vennom/Version_2/luces_aleatorias/luces_aleatorias.png)



## Simulación
Para la simulación utilizamos un arduino UNO, es **igual** al arduino nano, la única diferencia es el tamaño, los pines y demás son los mismos.

A continuación podremos ver la simulación del programa realizado.  [Clic para ver la simulación]( https://www.tinkercad.com/things/bT6OARtBleP )


 
## Programación en Arduino
Para la correcta realización de la práctica nos ayudaremos de la función *random()*, la misma que generea números aleatorios, esto con la finalidad de que siempre tengamos un número diferente y lograr diferentes intensidades de iluminación y así al mezclarse las intensidades obtener varios tonos de colores.
Para más información sobre la [función random()](https://www.arduino.cc/reference/en/language/functions/random-numbers/random/)


- Primero declaramos los pines 3, 5 y 6 como salida.
- Dentro de un bucle *loop()*
	- *Activamos* el pin 6 (LED Rojo) y generamos un número aleatorio que indicará la intensidad del color Rojo.
    - *Activamos* el pin 5 (LED Verde) y generamos un número aleatorio que indicará la intensidad del color Verde.
    - *Activamos* el pin 3 (LED Azul) y generamos un número aleatorio que indicará la intensidad del color Azul.    
	- Esperamos 1000 milisegundos


```
void setup(){
    
     pinMode(3,OUTPUT);
     pinMode(5,OUTPUT);
     pinMode(6,OUTPUT);
}

void loop(){
    
     analogWrite(6,random(0,255));
     analogWrite(5,random(0,255));
     analogWrite(3,random(0,255));
    delay(1000);
    
}
```

