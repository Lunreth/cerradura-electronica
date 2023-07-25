// PINES UTILIZADOS
#define CERRADURA 14
#define LED_ROJO 15
#define SENSOR 16

#define C1 9
#define F1 8

#define C2 7
#define F2 5

#define F3 6
#define C3 4

#define F4 3
#define C4 2

// REPRESENTACIÓN MATRICIAL DE TECLADO
const char filas = 4;
const char columnas = 4;
const char matriz[filas][columnas] = {
		{'1','2','3','A'},
		{'4','5','6','B'},
		{'7','8','9','C'},
		{'*','0','#','D'}
	};

// FILAS Y COLUMNAS
char pines_fila[filas] = {F1, F2, F3, F4};
char pines_col[columnas] = {C1, C2, C3, C4};

// CONTEO DE DIGITOS INGRESADOS
int count = 0;

// PASSWORD MAESTRA
const int digitos = 5;
const char password[digitos] = {'9','5','0','1','3'};

// ARRAY DE USUARIO
char ingreso[digitos];

// A FUTURO: Reemplazar delay() por otro tipo de contador que NO frene el programa
//unsigned long time_now = 0;

// SETUP
void setup()
{
	// 9600 Bits por segundo
	Serial.begin(9600);
	
	// CONFIGURACIÓN DE PINES
	pinMode(CERRADURA, OUTPUT);
	pinMode(LED_ROJO, OUTPUT);
	pinMode(SENSOR, INPUT_PULLUP);
	
	// POR DEFECTO - CERRADA
	digitalWrite(CERRADURA, LOW);
	digitalWrite(LED_ROJO, HIGH);
	
	for(int i = 0; i < columnas; i++) pinMode(pines_col[i], OUTPUT);
	for(int j = 0; j < filas; j++)
	{
		pinMode(pines_fila[j], INPUT);
		digitalWrite(pines_fila[j], HIGH);
	}
	
	ClearTerminal();
	Serial.println("--- TECLADO DE ACCESO INICIALIZADO ---");
}

// BUCLE PRINCIPAL
void loop()
{
	//time_now = millis();
	//Serial.println(time_now);
	
	char tecla = LecturaTecla();
	
	if(tecla != '_')
	{
		Serial.println(tecla);
		BTN_Press(tecla);
	}
}

// FUNCIÓN ITERATIVA PARA LEER FILAS Y COLUMNAS DE TECLADO
char LecturaTecla()
{
	// CARACTER INVALIDO POR DEFECTO
	char k = '_';
	
	// HACEMOS BUCLE EN TODAS LAS COLUMNAS Y FILAS
	for(int i = 0; i < columnas; i++)
	{
		digitalWrite(pines_col[i], LOW);
		for(int j = 0; j < filas; j++)
		{
			if(digitalRead(pines_fila[j]) == LOW)
			{
				digitalWrite(LED_ROJO, LOW);
				// 30 ms debounce
				delay(30);
				digitalWrite(LED_ROJO, HIGH);
				while(digitalRead(pines_fila[j]) == LOW)
				{
					// GUARDAMOS LA TECLA PRESIONADA EN LA VARIABLE
					k = matriz[j][i];
				}
            }
		}
		digitalWrite(pines_col[i], HIGH); 
	}
	return k;
}

// FUNCIÓN PRINCIPAL PARA ALMACENAR TECLAS PRESIONADAS
void BTN_Press(char tecla)
{
	ingreso[count] = tecla;
	
	if (count < digitos-1) count = count + 1;
	else
	{
		count = 0;
		bool acceso = true;
		for (int p = 0; p < digitos; p++)
		{
			if(ingreso[p] != password[p]) 
			{
				ClearTerminal();
				Serial.println("| ACCESO DENEGADO |");
				acceso = false;
				break;
			}
		}
		
		if (acceso == true)
		{
			// ABRE CERRADURA POR 10 SEGUNDOS Y AVISA CON LED VERDE
			ClearTerminal();
			Serial.println("--- CERRADURA DESBLOQUEADA ---");
			digitalWrite(CERRADURA, HIGH);
			digitalWrite(LED_ROJO, LOW);
			delay(10000);
			// CIERRA LA CERRADURA Y AVISA CON LED ROJO
			ClearTerminal();
			Serial.println("--- BLOQUEADO ---");
			digitalWrite(CERRADURA, LOW);
			digitalWrite(LED_ROJO, HIGH);
		}
	}
}

// FUNCIÓN EXTRA PARA LIMPIAR TERMINAL SERIE
void ClearTerminal()
{
	for (int i = 0; i < digitos; i++) Serial.println();
}