# CERRADURA ELECTRÓNICA
Prototipo completamente funcional de cerradura electrónica para una puerta donde el usuario deba ingresar una contraseña de N dígitos como requisito de su apertura

# TESTING ONLINE
- TinkerCAD: https://www.tinkercad.com/things/crxJpdY4iwy
- Contraseña actual: 95013

![Imgur](http://imgur.com/I4gXalj.png)
![Imgur](http://imgur.com/TWuYNWy.png)

# PARTES DEL PROYECTO
- `Parte Analógica`
  - Alimentación + rectificación + regulación de voltaje
- `Parte Digital`
  - Lógica + control
 
![Imgur](http://imgur.com/abHHBmf.png)
![Imgur](http://imgur.com/oDu06ab.png)

# MATERIALES
- Cerradura electromagnética (12v AC)
- Teclado matricial 4x4
- Protoboard
- Arduino NANO (5v CC)

- Opto-TRIAC (MOC 3052)
- TRIAC (BTA 08-600)

- Transformador reductor (220v/12v)
- Puente de diodos (x4 - 1N 4007)
- Capacitor electrolítico (4.7 µF - 50v)
- Regulador de tensión (LM7805)

- Resistores de 220Ω y 470Ω (+Opcional 1kΩ para LED rojo)
- Cables monofilares

![Imgur](http://imgur.com/mvyKiDW.png)
![Imgur](http://imgur.com/YyN85aF.png)

# CONCLUSIONES

Luego de verificar el correcto funcionamiento de la cerradura electrónica en ambas partes (analógica y digital) podemos concluir que:
- Arduino NANO es muy versátil y se adapta perfectamente a cualquier proyecto, se puede cargar y modificar instrucciones fácilmente con código abierto y documentación gratuita, lo cual es muy útil para realizar mejoras en un futuro, ejemplo lectores de tarjetas o seguridad biométrica.
- Una fuente de alimentación puede ser compartida, teniendo una salida de 12v AC para el circuito de potencia y otra salida rectificada-regulada de 5v CC para alimentar el microcontrolador.
- No existe una única forma de controlar un circuito de potencia, en lugar de utilizar un Opto-TRIAC podríamos colocar un transistor TBJ que funcione en corte y saturación con su respectivo relé (CC) conectado a la cerradura. Cada método tendrá sus ventajas y desventajas asociadas.
- Es de extrema importancia revisar las hojas de datos asociadas a cada componente utilizado en cada proyecto, el valor de las corrientes limitadas puede variar drásticamente (cambian valores de R elegidos)
- En ocasiones incluso la temperatura y humedad pueden alterar las prestaciones de circuitos integrados y dispositivos semiconductores como los transistores y diodos, por lo que la etapa de diseño debe contemplar este criterio, no es lo mismo exponer una cerradura a un desierto de 40°C con tormentas de arena que exponerla a una zona helada -10°C, estas variaciones se muestran con mayor claridad en las hojas de datos.

# REFERENCIAS

- Hojas de datos - https://www.alldatasheet.com/
- Programación - https://www.arduino.cc/reference/en/
- Simulador online - https://www.tinkercad.com
- LTSpice - Simulador para circuitos
- Libro “Electronics, A system approach” - Neil Storey - 4th Edition
