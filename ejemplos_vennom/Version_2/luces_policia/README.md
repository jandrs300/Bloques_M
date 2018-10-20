# Luces de Policia

El objetivo de esta práctica es realizar o simular con los LEDs de nuestra *placa Vennom* las luces de una patrulla de policia.


www.insani-loja.com

| Autor de la práctica |
| Juan Andrés (INSANI) |


## Materiales
- Placa Vennom V2.
- Cable USB - miniUSB

![Placa de programacion Vennom](https://github.com/jandrs300/Bloques_M/blob/master/ejemplos_vennom/Version_2/Guerra_Galaxias_buzzer/guerra%20de%20las%20galaxias.png)

## Programación en MBLOCK
Al ejecutar el código que vemos a continuación tendremos el resultado de la práctica.

![programa en mblock luces LEDS Arduino](https://github.com/jandrs300/Bloques_M/blob/master/ejemplos_vennom/Version_2/luces_policia/luces_policia.PNG)


## Programación en Arduino
- Primero declaramos los pines 3 y 6 como salida.
- A continuación activamos el pin 3 (LED Azul) y desactivamos el pin 6 (LED Rojo)
- Esperamos 200 milisegundos
- Desactivamos el pin 3 (LED Azul) y activamos el pin 6 (LED Rojo)
- Esperamos 200 milisegundos

```
void setup(){
    
    pinMode(3,OUTPUT);
    pinMode(6,OUTPUT);
}

void loop(){
    
    digitalWrite(3,1);
    digitalWrite(6,0);
    delay(200);
    digitalWrite(3,0);
    digitalWrite(6,1);
    delay(200);
}
```

