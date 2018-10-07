#include "Arduino.h"
#include "Vennom.h"

Vennom::Vennom() {  // seteo de pines

  pinMode(_M1_0, OUTPUT);
  pinMode(_M1_1, OUTPUT);

  pinMode(_M2_0, OUTPUT);
  pinMode(_M2_1, OUTPUT);

  pinMode(_buzzer, OUTPUT);

  pinMode(_LED_R, OUTPUT);
  pinMode(_LED_G, OUTPUT);
  pinMode(_LED_B, OUTPUT);

  pinMode(_triger, OUTPUT);
  pinMode(_echo, INPUT);


}

void Vennom::LED_RGB(int r, int g, int b) {
  analogWrite(_LED_R, r);
  analogWrite(_LED_G, g);
  analogWrite(_LED_B, b);
}
/*========================= MOVIMIENTOS =============================*/
void Vennom::activarMotor( String sel, String sentido) {
  if (sel == "derecho") {
    motor_sel = 1;
  } else if (sel == "izquierdo") {
    motor_sel = 2;
  }

  if (sentido == "adelante") {
    dire = 0;
  } else if (sentido == "atras") {
    dire = 1;
  } else if (sentido == "detener") {
    dire = 2;
  }

  switch (motor_sel) {
    case 1:
      if (dire == 0) {
        digitalWrite(_M1_0, LOW);
        digitalWrite(_M1_1, HIGH);
      } else if (dire  == 1) {
        digitalWrite(_M1_0, HIGH);
        digitalWrite(_M1_1, LOW);
      } else {
        digitalWrite(_M1_0, LOW);
        digitalWrite(_M1_1, LOW);
      }
      break;
    case 2:
      if (dire == 0) {
        digitalWrite(_M2_0, LOW);
        digitalWrite(_M2_1, HIGH);
      } else if (dire  == 1) {
        digitalWrite(_M2_0, HIGH);
        digitalWrite(_M2_1, LOW);
      } else {
        digitalWrite(_M2_0, LOW);
        digitalWrite(_M2_1, LOW);
      }
      break;
  }
}
void Vennom::MotorTiempo( String sel, String sentido, int tiempo) {
  int aa = 0;
  tiempo = tiempo / 2;
  while (tiempo > aa) {
    activarMotor(sel, sentido);
    aa = aa + 1;
    delay(2);
  }
  activarMotor(sel, "detener");
}
void Vennom::GiroVennom( int grados, String sentido) {
  int bb = 0;
  grados = grados * 7.15;
  if (sentido == "derecho") {
    while (grados > bb) {
      digitalWrite(_M1_0, HIGH);
      digitalWrite(_M1_1, LOW);
      digitalWrite(_M2_0, LOW);
      digitalWrite(_M2_1, HIGH);
      bb = bb + 1;
      delay(2);
    }
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);

  } else if (sentido == "izquierdo") {
    while (grados > bb) {
      digitalWrite(_M1_0, LOW);
      digitalWrite(_M1_1, HIGH);
      digitalWrite(_M2_0, HIGH);
      digitalWrite(_M2_1, LOW);
      bb = bb + 1;
      delay(2);
    }
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
  }
}
void Vennom::MoverVennom( String sentido) {
  if (sentido == "adelante") {
    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, LOW);

  } else if (sentido == "atras") {
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, HIGH);
    
  } else if (sentido == "detener") {
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
  } if (sentido == "derecha") {
    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, HIGH);
  } else if (sentido == "izquierda") {
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, LOW);
  }
}
/*========================= SALUDAR =============================*/
void Vennom::Saludar() {
  tono_saludo();
  mov_saludar();
  luces_saludar();
}
void Vennom::mov_saludar() {
  int g = 10;
  GiroVennom(g, "derecho");
  GiroVennom(g, "izquierdo");
  GiroVennom(g, "izquierdo");
  GiroVennom(g, "derecho");

  digitalWrite(_M1_0, LOW);
  digitalWrite(_M1_1, LOW);
  digitalWrite(_M2_0, LOW);
  digitalWrite(_M2_1, LOW);
}
void Vennom::luces_saludar() {
  int aa = 50;
  digitalWrite(_LED_B, LOW);
  delay(aa);
  digitalWrite(_LED_R, HIGH);
  delay(aa);
  digitalWrite(_LED_R, LOW);
  delay(aa);
  digitalWrite(_LED_R, HIGH);
  delay(aa);
  digitalWrite(_LED_R, LOW);
  delay(aa);
  digitalWrite(_LED_R, HIGH);
  delay(aa);
  digitalWrite(_LED_R, LOW);
  delay(aa);
  digitalWrite(_LED_B, HIGH);
  delay(aa);
  digitalWrite(_LED_B, LOW);
  delay(aa);
  digitalWrite(_LED_B, HIGH);
  delay(aa);
  digitalWrite(_LED_B, LOW);
  delay(aa);
  digitalWrite(_LED_B, HIGH);
  digitalWrite(_LED_R, LOW);
  digitalWrite(_LED_G, LOW);
  digitalWrite(_LED_B, LOW);
}

/*========================= SONIDOS =============================*/
void Vennom::Cantante(String song) {
  if (song == "saludo")
    tono_saludo();
  if (song == "encendido")
    tono_encendido();
  if (song == "deteccion")
    tono_hand_eyes();
  if (song == "mozart")
    tono_mozart();
  if (song == "contento")
    tono_contento();
  if (song == "enojado")
    tono_enojado();
  if (song == "mario")
    tono_mario();
  if (song == "despacito")
    tono_despacito();
  if (song == "policia")
    tono_policia();
  if (song == "sirena")
    tono_sirena();
  if (song == "mision") {
    //char *songg = "MissionImp:d=16,o=6,b=95:32d,32d#,32d,32d#,32d,32d#,32d,32d#,32d,32d,32d#,32e,32f,32f#,32g,g,8p,g,8p,a#,p,c7,p,g,8p,g,8p,f,p,f#,p,g,8p,g,8p,a#,p,c7,p,g,8p,g,8p,f,p,f#,p,a#,g,2d,32p,a#,g,2c#,32p,a#,g,2c,a#5,8c,2p,32p,a#5,g5,2f#,32p,a#5,g5,2f,32p,a#5,g5,2e,d#,8d";
    //Selec_can(songg);
  }
  if (song == "simpsons") {
    //char *songg = "The Simpsons:d=4,o=5,b=160:c.6,e6,f#6,8a6,g.6,e6,c6,8a,8f#,8f#,8f#,2g,8p,8p,8f#,8f#,8f#,8g,a#.,8c6,8c6,8c6,c6";
    //Selec_can(songg);
  }
  if (song == "starWars") {
    //char *songg = "StarWars:d=4,o=5,b=45:32p,32f#,32f#,32f#,8b.,8f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32e6,8c#.6,32f#,32f#,32f#,8b.,8f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32e6,8c#6";
    //Selec_can(songg);
  }
}
void Vennom::tono_saludo() {
  int melody[] = {
    1568, 2093, 2637, 0,
    3136, 0, 0,  0,
  };
  //Mario main them tempo
  int tempo[] = {
    12, 12, 12, 60,
    12, 12, 12, 12,
  };

  int size = sizeof(melody) / sizeof(int);
  for (int thisNote = 0; thisNote < size; thisNote++) {
    int noteDuration = 1000 / tempo[thisNote];
    buzz(_buzzer, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    buzz(_buzzer, 0, noteDuration);
  }
}
void Vennom::tono_encendido() {
  int melody[] = {
    1568, 2093, 2637, 0,
    3136, 0, 0,  0,
  };
  int tempo[] = {
    12, 12, 12, 60,
    12, 12, 12, 12,
  };

  int size = sizeof(melody) / sizeof(int);
  for (int thisNote = 0; thisNote < size; thisNote++) {
    int noteDuration = 1000 / tempo[thisNote];
    buzz(_buzzer, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    buzz(_buzzer, 0, noteDuration);
  }
}
void Vennom::tono_hand_eyes() {
  int melody[] = {
    2637, 2637, 0, 2637,
    0, 2093, 2637, 0,
    3136, 0, 0,  0,
    1568, 0, 0, 0,
  };
  int tempo[] = {
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,
  };

  int size = sizeof(melody) / sizeof(int);
  for (int thisNote = 0; thisNote < size; thisNote++) {
    int noteDuration = 1000 / tempo[thisNote];
    buzz(_buzzer, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    buzz(_buzzer, 0, noteDuration);
  }
}
void Vennom::tono_mozart() {
	/*
  int melody_m[] = {
    659, 622, 659, 622,
    659, 494, 587, 523,
    440, 262, 330, 440,
    494, 330, 415, 494,

    523, 330, 659, 622,
    659, 622, 659, 494,
    587, 523, 440, 262,
    330, 440, 494, 330,

    523, 494, 440, 494,
    523, 587, 659, 392,
    698, 659, 587, 349,
    659, 587, 523, 330,

    587, 523, 494, 330,
    659, 330, 659, 330,
    659, 330, 659, 311,
    659, 294, 659, 311,
  };
  
  int tempo_m[] = {
    9, 9, 9, 9,
    9, 9, 9, 9,
    3, 9, 9, 9,
    3, 9, 9, 9,

    3, 9, 9, 9,
    9, 9, 9, 9,
    9, 9, 3, 9,
    9, 9, 3, 9,

    9, 9, 3, 9,
    9, 9, 3, 9,
    9, 9, 3, 9,
    9, 9, 3, 9,

    9, 9, 9, 9,
    9, 9, 9, 9,
    9, 9, 9, 9,
    9, 9, 9, 9,
  };

  int size = sizeof(melody_m) / sizeof(int);
  for (int thisNote = 0; thisNote < size; thisNote++) {
    int noteDuration = 1000 / tempo_m[thisNote];
    buzz(_buzzer, melody_m[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    buzz(_buzzer, 0, noteDuration);
  }*/
}
void Vennom::tono_contento() {
  int melody[] = {
    2637, 2637, 0, 2637,
    0, 2093, 2637, 0,
    3136, 0, 0,  0,
    1568, 0, 0, 0,
  };
  //Mario main them tempo
  int tempo[] = {
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,
  };

  int size = sizeof(melody) / sizeof(int);
  for (int thisNote = 0; thisNote < size; thisNote++) {
    int noteDuration = 1000 / tempo[thisNote];
    buzz(_buzzer, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    buzz(_buzzer, 0, noteDuration);
  }
}
void Vennom::tono_enojado() {
  int melody[] = {
    2637, 2637, 0, 2637,
    0, 2093, 2637, 0,
    3136, 0, 0,  0,
    1568, 0, 0, 0,
  };
  //Mario main them tempo
  int tempo[] = {
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,
  };

  int size = sizeof(melody) / sizeof(int);
  for (int thisNote = 0; thisNote < size; thisNote++) {
    int noteDuration = 1000 / tempo[thisNote];
    buzz(_buzzer, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    buzz(_buzzer, 0, noteDuration);
  }
}
void Vennom::tono_mario() {
  int melody[] = {
    2637, 2637, 0, 2637,
    0, 2093, 2637, 0,
    3136, 0, 0,  0,
    1568, 0, 0, 0,

    2093, 0, 0, 1568,
    0, 0, 1319, 0,
    0, 1760, 0, 1976,
    0, 1865, 1760, 0,

    1568, 2637, 3136,
    3520, 0, 2794, 3136,
    0, 2637, 0, 2093,
    2349, 1976, 0, 0,

    2093, 0, 0, 1568,
    0, 0, 1319, 0,
    0, 1760, 0, 1976,
    0, 1865, 1760, 0,

    1568, 2637, 3136,
    3520, 0, 2794, 3136,
    0, 2637, 0, 2093,
    2349, 1976, 0, 0
  };
  //Mario main them tempo
  int tempo[] = {
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,

    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,

    9, 9, 9,
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,

    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,

    9, 9, 9,
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,
  };

  int size = sizeof(melody) / sizeof(int);
  for (int thisNote = 0; thisNote < size; thisNote++) {
    int noteDuration = 1000 / tempo[thisNote];
    buzz(_buzzer, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    buzz(_buzzer, 0, noteDuration);
  }
}
void Vennom::tono_policia() {
  digitalWrite(_LED_B, LOW);
  delay(50);
  digitalWrite(_LED_R, HIGH);
  delay(50);
  digitalWrite(_LED_R, LOW);
  delay(50);
  digitalWrite(_LED_R, HIGH);
  delay(50);
  digitalWrite(_LED_R, LOW);
  delay(50);
  digitalWrite(_LED_R, HIGH);
  delay(50);

  noTone(11);
  tone(_buzzer, 440, 200);

  digitalWrite(_LED_R, LOW);
  delay(50);
  digitalWrite(_LED_B, HIGH);
  delay(50);
  digitalWrite(_LED_B, LOW);
  delay(50);
  digitalWrite(_LED_B, HIGH);
  delay(50);
  digitalWrite(_LED_B, LOW);
  delay(50);
  digitalWrite(_LED_B, HIGH);

  noTone(6);
  tone(_buzzer, 494, 500);

  noTone(7);
  tone(_buzzer, 523, 300);
}
void Vennom::tono_sirena() {
  int i = 0;
  for (i = 2000; i <= 4000; i++)
    tone(_buzzer, i, 250);

  for (i = 4000; i >= 2000; i--)
    tone(_buzzer, i, 250);
}
void Vennom::tono_despacito() {
  tone(_buzzer, 587, 709.720327982);
  delay(788.578142202);
  delay(10.3082110092);
  tone(_buzzer, 554, 709.720327982);
  delay(788.578142202);
  delay(5.15410550459);
  tone(_buzzer, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(_buzzer, 369, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(_buzzer, 369, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 369, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 369, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 369, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 369, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(_buzzer, 440, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(_buzzer, 391, 412.843850917);
  delay(458.715389908);
  delay(5.15410550459);
  tone(_buzzer, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(_buzzer, 554, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 587, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(_buzzer, 440, 412.843850917);
  delay(458.715389908);
  delay(5.15410550459);
  tone(_buzzer, 440, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 440, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 440, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 440, 41.7482545872);
  delay(46.3869495413);
  delay(36.0787385321);
  tone(_buzzer, 440, 37.109559633);
  delay(41.2328440367);
  delay(30.9246330275);
  tone(_buzzer, 440, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 587, 46.3869495413);
  delay(51.5410550459);
  delay(30.9246330275);
  tone(_buzzer, 587, 46.3869495413);
  delay(51.5410550459);
  delay(20.6164220183);
  tone(_buzzer, 587, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(_buzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 659, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(_buzzer, 554, 691.165548165);
  delay(767.961720183);
  delay(314.40043578);
  tone(_buzzer, 587, 552.004699541);
  delay(613.338555046);
  delay(5.15410550459);
  tone(_buzzer, 554, 552.004699541);
  delay(613.338555046);
  delay(5.15410550459);
  tone(_buzzer, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(_buzzer, 369, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(_buzzer, 369, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 369, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 369, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 369, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 369, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 493, 46.3869495413);
  delay(51.5410550459);
  delay(30.9246330275);
  tone(_buzzer, 493, 46.3869495413);
  delay(51.5410550459);
  delay(20.6164220183);
  tone(_buzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(_buzzer, 440, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(_buzzer, 391, 273.683002294);
  delay(304.092224771);
  delay(159.777270642);
  tone(_buzzer, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 391, 41.7482545872);
  delay(46.3869495413);
  delay(30.9246330275);
  tone(_buzzer, 391, 37.109559633);
  delay(41.2328440367);
  delay(36.0787385321);
  tone(_buzzer, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(_buzzer, 554, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 587, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(_buzzer, 440, 412.843850917);
  delay(458.715389908);
  delay(5.15410550459);
  tone(_buzzer, 440, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 440, 64.9417293578);
  delay(72.1574770642);
  delay(5.15410550459);
  tone(_buzzer, 440, 64.9417293578);
  delay(72.1574770642);
  delay(5.15410550459);
  tone(_buzzer, 440, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 440, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 440, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 587, 51.0256444954);
  delay(56.6951605505);
  delay(30.9246330275);
  tone(_buzzer, 587, 51.0256444954);
  delay(56.6951605505);
  delay(10.3082110092);
  tone(_buzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(_buzzer, 659, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(_buzzer, 659, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
}
void Vennom::buzz(int targetPin, long frequency, long length) {
  digitalWrite(_LED_B, HIGH);
  long delayValue = 1000000 / frequency / 2;
  long numCycles = frequency * length / 1000;
  for (long i = 0; i < numCycles; i++) {
    digitalWrite(targetPin, HIGH);
    delayMicroseconds(delayValue);
    digitalWrite(targetPin, LOW);
    delayMicroseconds(delayValue);
  }
  digitalWrite(_LED_B, LOW);
}

/*
void Vennom::Selec_can(char *p) {
  int notes[] = { 0,
                  262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494,
                  523, 554, 587, 622, 659, 698, 740, 784, 831, 880, 932, 988,
                  1047, 1109, 1175, 1245, 1319, 1397, 1480, 1568, 1661, 1760, 1865, 1976,
                  2093, 2217, 2349, 2489, 2637, 2794, 2960, 3136, 3322, 3520, 3729, 3951
                };
  byte default_dur = 4;
  byte default_oct = 6;
  int bpm = 63;
  int num;
  long wholenote;
  long duration;
  byte note;
  byte scale;

  while (*p != ':') p++;
  p++;

  if (*p == 'd') {
    p++; p++;
    num = 0;
    while (isdigit(*p)) {
      num = (num * 10) + (*p++ - '0');
    }
    if (num > 0) default_dur = num;
    p++;
  }

  if (*p == 'o') {
    p++; p++;
    num = *p++ - '0';
    if (num >= 3 && num <= 7) default_oct = num;
    p++;
  }

  if (*p == 'b') {
    p++; p++;
    num = 0;
    while (isdigit(*p)) {
      num = (num * 10) + (*p++ - '0');
    }
    bpm = num;
    p++;
  }

  wholenote = (60 * 1000L / bpm) * 4;
  while (*p) {
    num = 0;
    while (isdigit(*p)) {
      num = (num * 10) + (*p++ - '0');
    }

    if (num) duration = wholenote / num;
    else duration = wholenote / default_dur;
    note = 0;

    switch (*p) {
      case 'c':
        note = 1;
        break;
      case 'd':
        note = 3;
        break;
      case 'e':
        note = 5;
        break;
      case 'f':
        note = 6;
        break;
      case 'g':
        note = 8;
        break;
      case 'a':
        note = 10;
        break;
      case 'b':
        note = 12;
        break;
      case 'p':
      default:
        note = 0;
    }
    p++;
    if (*p == '#') {
      note++;
      p++;
    }


    if (*p == '.') {
      duration += duration / 2;
      p++;
    }

    if (isdigit(*p)) {
      scale = *p - '0';
      p++;
    } else {
      scale = default_oct;
    }

    scale += OCTAVE_OFFSET;

    if (*p == ',')
      p++;

    if (note) {
      tone(_buzzer, notes[(scale - 4) * 12 + note]);
      delay(duration);
      noTone(_buzzer);
    } else {
      delay(duration);
    }
  }
}*/

/*=========================  =============================*/
int Vennom::Distancia() {
  long duration, distanceCm;
  digitalWrite(_triger, LOW);  //para generar un pulso limpio ponemos a LOW 4us
  delayMicroseconds(5);
  digitalWrite(_triger, HIGH);  //generamos Trigger (disparo) de 10us
  delayMicroseconds(10);
  //digitalWrite(_triger, LOW);
  duration = pulseIn(_echo, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
  distanceCm = duration * 10 / 292 / 2;  //convertimos a distancia, en cm
  return distanceCm;
}

void Vennom::evitar_obstaculo() {
  long distancia;
  long tiempo;
  digitalWrite(_triger, LOW);
  delayMicroseconds(5);
  digitalWrite(_triger, HIGH);
  delayMicroseconds(10);
  tiempo = pulseIn(_echo, HIGH);
  distancia = int(0.017 * tiempo);

  if (distancia > 11) {
    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, LOW);
  } else {
    delay(100);
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    delay(100);
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, HIGH);
    delay(100);
    GiroVennom(180, "derecho");
    delay(100);
    }
}