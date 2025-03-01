#include <Arduino.h>

const int segmentA = 18;
const int segmentB = 19;
const int segmentC = 21;
const int segmentD = 22;
const int segmentE = 23;
const int segmentF = 2;
const int segmentG = 4;

int timeWait =0;

void all_off()
{
	digitalWrite(segmentA, LOW);
	digitalWrite(segmentB, LOW);
	digitalWrite(segmentC, LOW);
	digitalWrite(segmentD, LOW);
	digitalWrite(segmentE, LOW);
	digitalWrite(segmentF, LOW);
	digitalWrite(segmentG, LOW);
}

void CERO()
{
	all_off();
	digitalWrite(segmentA, HIGH);
	digitalWrite(segmentB, HIGH);
	digitalWrite(segmentC, HIGH);
	digitalWrite(segmentD, HIGH);
	digitalWrite(segmentE, HIGH);
	digitalWrite(segmentF, HIGH);
}

void UNO()
{
	all_off();
	digitalWrite(segmentB, HIGH);
	digitalWrite(segmentC, HIGH);
}

void DOS()
{
	all_off();
	digitalWrite(segmentA, HIGH);
	digitalWrite(segmentB, HIGH);
	digitalWrite(segmentG, HIGH);
	digitalWrite(segmentE, HIGH);
	digitalWrite(segmentD, HIGH);
}

void TRES()
{
	all_off();
	digitalWrite(segmentA, HIGH);
	digitalWrite(segmentB, HIGH);
	digitalWrite(segmentG, HIGH);
	digitalWrite(segmentC, HIGH);
	digitalWrite(segmentD, HIGH);
}

void CUATRO()
{
	all_off();
	digitalWrite(segmentF, HIGH);
	digitalWrite(segmentB, HIGH);
	digitalWrite(segmentG, HIGH);
	digitalWrite(segmentC, HIGH);
}

void CINCO()
{
	all_off();
	digitalWrite(segmentA, HIGH);
	digitalWrite(segmentF, HIGH);
	digitalWrite(segmentG, HIGH);
	digitalWrite(segmentC, HIGH);
	digitalWrite(segmentD, HIGH);
}

void SEIS()
{
	all_off();
	digitalWrite(segmentA, HIGH);
	digitalWrite(segmentF, HIGH);
	digitalWrite(segmentG, HIGH);
	digitalWrite(segmentC, HIGH);
	digitalWrite(segmentD, HIGH);
	digitalWrite(segmentE, HIGH);
}

void SIETE()
{
	all_off();
	digitalWrite(segmentA, HIGH);
	digitalWrite(segmentB, HIGH);
	digitalWrite(segmentC, HIGH);
}

void OCHO()
{
	all_off();
	digitalWrite(segmentA, HIGH);
	digitalWrite(segmentB, HIGH);
	digitalWrite(segmentC, HIGH);
	digitalWrite(segmentD, HIGH);
	digitalWrite(segmentE, HIGH);
	digitalWrite(segmentF, HIGH);
	digitalWrite(segmentG, HIGH);
}

void NUEVE()
{
	all_off();
	digitalWrite(segmentA, HIGH);
	digitalWrite(segmentB, HIGH);
	digitalWrite(segmentC, HIGH);
	digitalWrite(segmentD, HIGH);
	digitalWrite(segmentF, HIGH);
	digitalWrite(segmentG, HIGH);
}


void all_on()
{
	digitalWrite(segmentA, HIGH);
	digitalWrite(segmentB, HIGH);
	digitalWrite(segmentC, HIGH);
	digitalWrite(segmentD, HIGH);
	digitalWrite(segmentE, HIGH);
	digitalWrite(segmentF, HIGH);
	digitalWrite(segmentG, HIGH);

}
void setup() {
	// Iniciar la comunicación serial
	Serial.begin(115200);

	pinMode(segmentA, OUTPUT);
	pinMode(segmentB, OUTPUT);
	pinMode(segmentC, OUTPUT);
	pinMode(segmentD, OUTPUT);
	pinMode(segmentE, OUTPUT);
	pinMode(segmentF, OUTPUT);
	pinMode(segmentG, OUTPUT);
}

/*Segundera 0-9*/
void loop_segundera() {
  all_off();
  CERO();
  digitalWrite(segmentE, HIGH);
  delay(1000);
  UNO();
  delay(1000);
  DOS();
  delay(1000);
  TRES();
  delay(1000);
  CUATRO();
  delay(1000);
  CINCO();
  delay(1000);
  SEIS();
  delay(1000);
  SIETE();
  delay(1000);
  OCHO();
  delay(1000);
  NUEVE();
  delay(1000);
}

/*Selecciona desde consola el número a representar*/
void loop_seleccion_consola()
{
	if (Serial.available() > 0)
	{
		// Leer el dato ingresado
		char input = Serial.read();

		Serial.println(input);

		if(input == '0')
		{
			CERO();
		}
		else if (input == '1')
		{
			UNO();
		}
		else if (input == '2')
		{
			DOS();
		}
		else if (input == '3')
		{
			TRES();
		}
		else if (input == '4')
		{
			CUATRO();
		}
		else if (input == '5')
		{
			CINCO();
		}
		else if (input == '6')
		{
			SEIS();
		}
		else if (input == '7')
		{
			SIETE();
		}
		else if (input == '8')
		{
			OCHO();
		}
		else if (input == '9')
		{
			NUEVE();
		}
		else
		{
			Serial.println("ERROR!");
		}
	   // Limpiar el buffer serial
		while (Serial.available() > 0) {
		  Serial.read();
		}

		// Pedir otro número
		Serial.println("Por favor, ingresa un número del 0 al 9:");
	}
}

/*Representacion de un digito (8) conmutando el segmento encendido. La espera se puede decrementar o
 * incrementar en 10 ms usando '+' o '-' respectivamente*/
void loop_swap_segment()
{
	digitalWrite(segmentA, HIGH);
	delay(timeWait);
	all_off();
	digitalWrite(segmentB, HIGH);
	delay(timeWait);
	all_off();
	digitalWrite(segmentC, HIGH);
	delay(timeWait);
	all_off();
	digitalWrite(segmentD, HIGH);
	delay(timeWait);
	all_off();
	digitalWrite(segmentE, HIGH);
	delay(timeWait);
	all_off();
	digitalWrite(segmentF, HIGH);
	delay(timeWait);
	all_off();
	digitalWrite(segmentG, HIGH);
	delay(timeWait);
	all_off();
	if (Serial.available() > 0)
	{
		char input = Serial.read();
		if(input == '+')
		{
			timeWait +=10;
		}
		else if(input == '-')
		{
			if(timeWait >= 10)
			{
				timeWait -=10;
			}
		}
	}
	Serial.print("time:");
	Serial.println(timeWait);
}

void loop()
{
	loop_seleccion_consola();
}
