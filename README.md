# Algoritmo_VFC
Algoritmo de Variabilidad de la frecuencia cardiaca a partir de una señal de electrocardiografía EKG.

#### Teoria

La variabilidad de la frecuencia cardiaca se conoce como la variación en el tiempo que transcurre entre los intervalos RR del electrocardiograma y refleja la actividad del sistema nervioso autónomo sobre la función cardiaca.

#### Conectividad sensor EKG con arduino NANO

Microcontrolador ATMEGA-328P

Es una placa pequeña pero muy completa, totalmente compatible con Protoboards, con capacidades que igualan a la placa de desarrollo Arduino UNO R3. Está basada en el ATmega328 y posee 13 pines de Entrada / Salida digital y 7 pines de entrada analógica. Esta placa utiliza un cable Mini B-USB en lugar de uno normal. Los pines de conexión ya se encuentran soldados para un rápido manejo de la placa de desarrollo Arduino Nano.

Sensor de electrocardiografia AD8232 

El monitor de ritmo cardíaco AD8232 es una tarjeta de costo bajo usado para medir la actividad eléctrica del corazón. Esta actividad eléctrica puede ser registrada como un electrocardiograma -ECG- o una salida como una lectura analógica. Los electrocardiogramas pueden ser extremadamente ruidosos, por lo que el AD8232 actúa como un amplificador operacional que ayuda a obtener una señal clara de los intervalos PR y QT fácilmente.
El AD8232 es un bloque de señales integradas condicionadas para ECG y otras aplicaciones de medición biopotenciales. Está diseñado para extraer, amplificar y filtrar pequeñas señales biopotenciales en presencia de condiciones ruidosas, así como aquellas creadas por el movimiento o la colocación de electrodos.
El AD8232 proporciona nueve conexiones desde el circuito en el que puedes soldar pines, cables u otras conexiones. Las salidas SDN, LO , LO-, OUTPUT, 3.3 V y GND proporcionan los pines esenciales para operar el monitor con un Arduino u otra tarjeta de desarrollo. También se proporcionan en esta tarjeta los pines RA (Right Arm), LA (Left Arm) yRL (Right Leg) para conectarlos y usar tus propios sensores. Adicionalmente hay un LED indicador que emite pulsos luminosos al ritmo del bombeo del corazón. Los sensores biomédicos -electrodos- y los cables para electrodos se requieren para usar el monitor.


![alt text](image2.jpg)

#### Logica implementada
Sistema detector de picos con ventanas movibles a traves del tiempo.

![alt text](image3.jpg)


#### Señal lograda
![alt text](image4.jpg)

#### Equipo biomedico de adquisición de señales corporales
![alt text](image1.jpg)
