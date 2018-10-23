# Luces Alternas

El objetivo de esta práctica es programar tres luces (LED RGB) que parpadean de forma alterna con una frecuencia de 1 segundo.


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

![Placa arduino encender LED RGB catado](https://github.com/jandrs300/Bloques_M/blob/master/ejemplos_vennom/Version_2/luces_alternas/luces_alternas_c.PNG)




## Programación en MBLOCK
Al ejecutar el código que vemos a continuación tendremos el resultado de la práctica.

![programa en mblock luces alternadas LEDS Arduino](https://github.com/jandrs300/Bloques_M/blob/master/ejemplos_vennom/Version_2/luces_alternas/luces_alternas.png)


## Simulación
Para la simulación utilizamos un arduino UNO, es **igual** al arduino nano, la única diferencia es el tamaño, los pines y demás son los mismos.

A continuación podremos ver la simulación del programa realizado.  [Clic para ver la simulación](https://www.tinkercad.com/things/jEoykusrGeE)

 

## Programación en Arduino
- Primero declaramos los pines 3, 5 y 6 como salida.
- Dentro de un bucle *loop()*
	- A continuación *activamos* el pin 6 (LED Rojo) y *desactivamos* el pin 3 y 5 (LED Azul y Verde)
	- Esperamos 1000 milisegundos
	- *Activamos* el pin 5 (LED Verde) y *desactivamos* el pin 3 y 6 (LED Azul y Rojo)
	- Esperamos 1000 milisegundos
	- *Activamos* el pin 3 (LED Azul) y desactivamos el pin 5 y 6 (LED Verde y Rojo)
	- Esperamos 1000 milisegundos


```
void setup(){
    
    pinMode(6,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(3,OUTPUT);
}

void loop(){
    
    digitalWrite(6,1);
    digitalWrite(5,0);
    digitalWrite(3,0);
    delay(1000);
    digitalWrite(6,0);
    digitalWrite(5,1);
    digitalWrite(3,0);
    delay(1000);
    digitalWrite(6,0);
    digitalWrite(5,0);
    digitalWrite(3,1);
    delay(1000);   
}
```

