//Primero los include guards
#ifndef VENNOM_H
#define VENNOM_H
#include <Arduino.h>

class Vennom{
	public:
		Vennom();
		void activarMotor(String sel, String dire);
		void MotorTiempo( String sel, String sentido, int tiempo);
		void GiroVennom(int grados, String sentido);
		void MoverVennom( String sentido);
		void Cantante(String song);
		void tono_saludo();
		void tono_encendido();
		void tono_hand_eyes();
		void tono_mozart();
		void tono_contento();
		void tono_enojado();
		void tono_mario();
		void tono_policia();
		void tono_sirena();
		void tono_despacito();
		void buzz(int targetPin, long frequency, long length);
		void Selec_can(char *p);
		void Saludar();
		void mov_saludar();
		void luces_saludar(); 
		void LED_RGB(int r, int g, int b);
		int Distancia();
		void evitar_obstaculo();
		
	private:
		//		motor DEREHO
		int _M1_0 = 2;
	    int _M1_1 = 4;
		//		motor IZQUIERDO
	    int _M2_0 = 7;
	    int _M2_1 = 12;
	    //      ULTRASONIDO
	    int _triger = 13;
	    int _echo   = 10;
	    //      BUZZER
	    int _buzzer = 11;
		//      LED RGB
	    int _LED_R = 6;
	    int _LED_G = 5;
	    int _LED_B = 3;

	    int motor_sel = 0;
	    int dire = 0;

		int melody[];
		int tempo[];
		int notes[];
		int OCTAVE_OFFSET = 0;
};

#endif
