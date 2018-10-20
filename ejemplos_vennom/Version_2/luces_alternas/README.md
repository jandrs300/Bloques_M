# Luces Alternas

El objetivo de esta práctica es programas tres luces (LED RGB) que parpadean de forma alterna con una frecuencia de 1 segundo.


www.insani-loja.com

| Autor de la práctica |
| Juan Andrés (INSANI) |


## Materiales
- Placa Vennom V2.
- Cable USB - miniUSB

![Placa de programacion Vennom](https://github.com/jandrs300/Bloques_M/blob/master/ejemplos_vennom/Version_2/placa-version2.png)

## Programación en MBLOCK
Al ejecutar el código que vemos a continuación tendremos el resultado de la práctica.

![programa en mblock luces LEDS Arduino](https://github.com/jandrs300/Bloques_M/blob/master/ejemplos_vennom/Version_2/luces_policia/luces_policia.PNG)


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

