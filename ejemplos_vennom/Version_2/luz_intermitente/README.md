# Luz Intermitente

El objetivo de esta práctica es programar el encendido y apagado del  LED (color Azul) con una frecuencia de 1 segundo.


www.insani-loja.com

| Autor de la práctica |
| Juan Andrés (INSANI) |


## Materiales
- Placa Vennom V2.
- Cable USB - miniUSB

![Placa de programacion Vennom](https://github.com/jandrs300/Bloques_M/blob/master/ejemplos_vennom/Version_2/placa-version2.png)



## Programación en MBLOCK
Al ejecutar el código que vemos a continuación tendremos el resultado de la práctica.

![programa en mblock luces intermitentes LEDS Arduino](https://github.com/jandrs300/Bloques_M/blob/master/ejemplos_vennom/Version_2/luz_intermitente/luz_intermitente.png)


## Programación en Arduino
- Primero declaramos el pin 3 como salida.
- Dentro de un bucle *loop()*
	- *Activamos* el pin 3 (LED Azul) 
	- Esperamos 1000 milisegundos
	- *Desactivamos* el pin 3 (LED Azul)
	- Esperamos 1000 milisegundos


```
void setup(){
    
    pinMode(3,OUTPUT);
}

void loop(){
    
    digitalWrite(3,1);
    delay(1000);
    digitalWrite(3,0);
    delay(1000);
}

```

