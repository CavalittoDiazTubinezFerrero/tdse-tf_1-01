<img src="https://github.com/user-attachments/assets/15600b18-f73b-4ba3-a959-47f0048a1ab6" alt="image2" width="30%">

**UNIVERSIDAD DE BUENOS AIRES**  
**Facultad de Ingeniería**  
**TA134 Taller de Sistemas Embebidos**

Memoria del Trabajo Final:

***BeepBuddy* - Dispositivo de monitoreo acústico**

**Autores:**

**Sra. Emilia Cavalitto - 109394**

**Sra. María Teresa Diaz Tubiñez - 104838**

**Sr. Ulises Ferrero - 105034**

*Este trabajo fue realizado en la Ciudad Autónoma de Buenos Aires,*   
*entre Diciembre y Febrero de 2025 y 2026\.*

  
**RESUMEN**

En este trabajo se presenta el diseño e implementación de BeepBuddy, un sistema embebido destinado a la detección y notificación de eventos sonoros en tiempo real. El mismo fue concebido como una herramienta de asistencia para personas con discapacidad auditiva y como apoyo en el cuidado de personas, permitiendo alertar ante la presencia de sonidos relevantes del entorno. Su objetivo es ofrecer una solución portátil y configurable que facilite el monitoreo acústico en contextos cotidianos.

El sistema está compuesto por una plataforma de desarrollo provista por la cátedra de Taller de Sistemas Embebidos de la Facultad de Ingeniería de la Universidad de Buenos Aires que integra un microcontrolador con conversor analógico-digital, temporizadores y un módulo de comunicación Bluetooth de bajo consumo. El procesamiento de audio y la lógica de control fueron desarrollados en lenguaje C, mientras que la aplicación móvil utilizada para la configuración y recepción de notificaciones se implementó mediante la herramienta MIT App Inventor. El desarrollo del proyecto implicó la integración de hardware y software bajo criterios de diseño modular y uso eficiente de recursos, para lo cual se empleó la plataforma itemis CREATE.

En esta memoria se describen la motivación, la arquitectura del sistema, las decisiones de diseño adoptadas y las pruebas realizadas para validar su funcionamiento.


**ABSTRACT**

This work presents the design and implementation of BeepBuddy, an embedded system for real-time detection and notification of acoustic events. The system is intended as an assistive solution for individuals with hearing impairments and as a support tool in caregiving scenarios, generating alerts when relevant environmental sounds are identified. The proposed device provides a portable and configurable platform for acoustic monitoring in everyday environments.

The system is based on a development board integrating a microcontroller with an analog-to-digital converter, hardware timers, and a low-energy Bluetooth communication module. Audio acquisition and control logic were implemented in the C programming language, while the mobile application for system configuration and notification reception was developed using MIT App Inventor. The project required the integration of hardware and software following modular design principles and efficient resource management typical of embedded systems, for which the itemis CREATE modeling environment was employed.

This document describes the system architecture, design methodology, implementation details, and validation results.


# Índice General

- [**Registro de versiones**](#registro-de-versiones)
- [**Introducción general**](#introducción-general)
  - [1.1 Análisis de necesidad y objetivos](#11-análisis-de-necesidad-y-objetivos)
  - [1.2 Descripción general del sistema](#12-descripción-general-del-sistema)
- [**Introducción específica**](#introducción-específica) 
  - [2.1 Requisitos](#21-requisitos)
  - [2.2 Descripción de uso y máquinas de estado](#22-descripción-de-uso-y-máquinas-de-estado)
  - [2.3 Descripción de los módulos del sistema](#23-descripción-de-los-módulos-del-sistema)
    - [2.3.1 Alimentación](#231-alimentación)
    - [2.3.2 Microcontrolador](#232-microcontrolador)
    - [2.3.3 Módulo de micrófono](#233-módulo-de-micrófono)
    - [2.3.4 Módulo _Bluetooth_](#234-módulo-bluetooth)
    - [2.3.5 Módulo _buzzer_](#235-módulo-buzzer)
    - [2.3.6 Interfaz de usuario: _DIP switch_ y LEDs](#236-interfaz-de-usuario-dip-switch-y-leds)
  - [**Diseño e implementación**](#diseño-e-implementación)
    - [3.1 Diseño del _hardware_](#31-diseño-del-hardware)
      - [3.1.1 Conexión del módulo del micrófono](#311-conexión-del-módulo-del-micrófono)
      - [3.1.2 Conexión del del módulo _Bluetooth_](#311-conexión-del-módulo-bluetooth)
      - [3.1.3 Conexión del módulo del _buzzer_](#312-conexión-del-módulo-del-buzzer)
      - [3.1.3 Conexión de los _LEDs_](#313-conexión-de-los-leds)
    - [3.2 _Firmware_ de _BeepBuddy_](#32-firmware-de-beepbuddy)
    - [3.3 Diseño de la aplicación](#33-diseño-de-la-aplicación)
  - [**Ensayos y resultados**](#ensayos-y-resultados)
    - [4.1 Mediciones](#41-mediciones)
      - [4.1.1 Consumo energético](#411-consumo-energético)
      - [4.1.2 Tiempos de ejecución de cada tarea (WCET)](#412-tiempos-de-ejecución-de-cada-tarea-(wcet))
      - [4.1.3 Cálculo del factor de uso (U) de la CPU](#413-cálculo-del-factor-de-uso-(u)-de-la-cpu)
    - [4.2 Metodología de desarrollo](#42-metodología-de-desarrollo)
    - [4.3 Cumplimiento de requisitos](#43-cumplimiento-de-requisitos)
    - [4.4 Comparación con otros sistemas similares](#44-comparación-con-otros-sistemas-similares)
    - [4.5 Documentación del desarrollo realizado](#45-documentación-del-desarrollo-realizado)
- [**Bibliografía**](#bibliografía)

<span style="color:red"><strong>⚠ LAS SECCIONES DEL CAPÍTULO 3 NO ESTÁN HECHAS!!!</strong></span>

<span style="color:red"><strong>⚠ IR COMPLETANDO A MEDIDA QUE SE VAYAN ESCRIBIENDO CADA UNA DE LAS SECCIONES</strong></span>

## Registro de versiones

| Revisión | Cambios realizados | Fecha de finalización |
| :---: | ----- | ----- |
| 1.0 | Creación del documento | 10/02/2026 |
| 1.1 | Redacción del primer capítulo | 11/02/2026 |
| 1.2 | Redacción del segundo capítulo | 14/02/2026 |
| 1.3 | Redacción del tercer capítulo | ... |
| 1.4 | Redacción del cuarto capítulo | 16/02/2026 |
| 1.5 | Redacción del quinto capítulo | ... |
| 1.6 | Revisión y ajustes finales | ... |

<span style="color:red"><strong>⚠ IR COMPLETANDO A MEDIDA QUE SE VAYAN ESCRIBIENDO CADA UNA DE LAS SECCIONES</strong></span>
 
### 

# **CAPÍTULO 1** 

# **Introducción general** 

## **1.1 Análisis de necesidad y objetivos** 

En los últimos años, el desarrollo de diferentes tecnologías ha permitido la creación de dispositivos dedicados a tareas específicas con mayor eficiencia, bajo consumo y mayor confiabilidad que otras opciones más generales. Sin embargo, en el ámbito del monitoreo sonoro aplicado al cuidado infantil o supervisión del entorno, muchas soluciones comerciales no contemplan las necesidades de personas con discapacidad auditiva.

Los monitores de bebé convencionales, por ejemplo, transmiten audio hacia un receptor portátil, pero requieren que el usuario pueda escuchar los sonidos detectados. Por otro lado, los monitores inteligentes con video suelen depender de conectividad Wi-Fi, servicios en la nube y aplicaciones complejas, lo que incrementa su costo como así también el consumo energético. Asimismo, las aplicaciones móviles de detección de sonido utilizan el micrófono del teléfono, lo que implica alto consumo de batería y baja confiabilidad.

En este contexto, surge la necesidad de desarrollar un dispositivo embebido dedicado, autónomo y configurable, capaz de detectar eventos sonoros relevantes y notificar de manera inmediata mediante comunicación Bluetooth, sin requerir conexión a internet. Así, el objetivo de este trabajo fue diseñar e implementar un sistema que permitiera asistir a personas con discapacidad auditiva en tareas de cuidado, particularmente en contextos donde la detección rápida de sonidos como llanto, alarmas o golpes resulta crítica. BeepBuddy se propuso como un producto mínimo viable que solventara cada una de estas características, priorizando confiabilidad, facilidad de uso y bajo consumo energético. A su vez, el valor agregado del proyecto radica en la posibilidad de configurar parámetros como sensibilidad y modos de operación, junto con la implementación de un menú interactivo accesible.

## **1.2 Descripción general del sistema**

BeepBuddy está compuesto por dos subsistemas principales: el dispositivo embebido de detección sonora y la aplicación móvil de notificación y configuración.
El primero integra un micrófono para la captación de señales acústicas, el microcontrolador con conversor analógico-digital para la digitalización de la señal, temporizadores para el control del muestreo y un módulo de comunicación Bluetooth para el envío de alertas. Asimismo, cuenta con una interfaz física básica compuesta por botones de configuración y un indicador luminoso de estado.
La aplicación móvil fue desarrollada utilizando la herramienta MIT App Inventor, permitiendo la visualización de alertas, consulta de historial y verificación del estado de conexión [1].

En la Figura 1.2.1 se presenta el diagrama en bloques general del sistema, donde se observan los principales módulos y su interconexión.

<img width="600" src="DiagramaenBloquesdetallado.png" >

**Figura 1.2.1**: Diagrama en bloques general de BeepBuddy.

El funcionamiento general del dispositivo puede resumirse de la siguiente manera: el micrófono capta continuamente los sonidos del entorno y el microcontrolador digitaliza la señal mediante el conversor analógico-digital a una frecuencia de muestreo controlada por temporizadores internos. Las muestras adquiridas son procesadas en tiempo real para determinar si el sonido detectado cumple con los criterios configurados de sensibilidad o corresponde a un evento relevante previamente definido. En caso de detectarse una condición válida, el sistema genera una alerta y la transmite mediante el módulo Bluetooth al dispositivo móvil emparejado. La aplicación recibe la notificación, la muestra de forma visual al usuario y la registra en el historial de eventos. En ausencia de eventos significativos, el sistema continúa monitoreando el entorno de manera autónoma y con bajo consumo energético.

En las próximas secciones se describirá con mayor detalle los módulos utilizados y sus características.

# **CAPÍTULO 2**

# **Introducción específica** 

## **2.1 Requisitos**

Habiendo analizado las características principales del monitor, se definieron los principales requisitos para que el sistema cumpla con su función de forma correcta y resulte útil para su propósito. Para esto, se realizó una tabla definiendo los principales requisitos a implementar, mostrado en la Tabla 2.1.1.

**Tabla 2.1.1**: Requisitos del proyecto.

<table>
<thead>
<tr>
<th>Grupo</th>
<th>ID</th>
<th>Descripción</th>
</tr>
</thead>

<tbody>

<tr>
<td>Adquisición</td>
<td>1.1</td>
<td>El sistema cuenta con un micrófono para captar sonidos del entorno.</td>
</tr>
<tr>
<td></td>
<td>1.2</td>
<td>El sistema digitaliza la señal sonora mediante el ADC de la placa STM.</td>
</tr>

<tr>
<td>Procesamiento</td>
<td>2.1</td>
<td>El sistema detecta sonidos relevantes (llanto, alarma, golpes, palabra clave).</td>
</tr>
<tr>
<td></td>
<td>2.2</td>
<td>El usuario puede configurar sensibilidad y parámetros mediante un switch.</td>
</tr>
<tr>
<td></td>
<td>2.3</td>
<td>El sistema almacena parámetros configurables en memoria.</td>
</tr>

<tr>
<td>Notificación</td>
<td>3.1</td>
<td>El sistema envía notificaciones a un dispositivo móvil vía Bluetooth.</td>
</tr>
<tr>
<td></td>
<td>3.2</td>
<td>Las notificaciones son inmediatas ante detección de eventos.</td>
</tr>

<tr>
<td>Aplicación</td>
<td>4.1</td>
<td>La aplicación muestra alertas visuales asociadas a los sonidos detectados.</td>
</tr>
<tr>
<td></td>
<td>4.2</td>
<td>La aplicación permite consultar el historial de alertas.</td>
</tr>
<tr>
<td></td>
<td>4.3</td>
<td>La aplicación indica el estado de conexión Bluetooth del dispositivo.</td>
</tr>
<tr>
<td></td>
<td>4.4</td>
<td>La aplicación permite definir el umbral de sensibilidad.</td>
</tr>
<tr>
<td></td>
<td>4.5</td>
<td>La aplicación permite elegir diferentes modos de funcionamiento.</td>
</tr>

<tr>
<td>Interfaz física</td>
<td>5.1</td>
<td>El sistema cuenta con un switch para seleccionar el modo de operación.</td>
</tr>
<tr>
<td></td>
<td>5.2</td>
<td>El sistema cuenta con indicadores LEDs básicos de funcionamiento (encendido/apagado, modo y estado de conexión Bluetooth).</td>
</tr>
<tr>
<td></td>
<td>5.3</td>
<td>El sistema emite un pitido al ser encendido.</td>
</tr>

<tr>
<td>Requisitos de operación</td>
<td>6.1</td>
<td>El dispositivo funciona sin conexión a internet.</td>
</tr>
<tr>
<td></td>
<td>6.2</td>
<td>El sistema tiene bajo consumo energético.</td>
</tr>
<tr>
<td></td>
<td>6.3</td>
<td>El sistema es seguro y confiable.</td>
</tr>

</tbody>
</table>

<span style="color:red"><strong>⚠ IR VIENDO SI SE AGREGAN NUEVOS REQUISITOS Y SUS ESTADOS EN EL INFORME DE AVANCES</strong></span>

## **2.2 Descripción de uso y máquinas de estado**

**Tabla 2.2.1**: Descripción de uso.

| Elemento | Definición |
| :---- | :---- |
| Disparador | Se produce un sonido en el entorno que supera el umbral de sensibilidad configurado. |
| Precondiciones | El sistema se encuentra encendido. El dispositivo está correctamente alimentado. El módulo Bluetooth se encuentra emparejado con la aplicación móvil. Los parámetros de sensibilidad están configurados.  |
| Flujo principal | El micrófono capta el sonido del entorno y lo convierte en una señal eléctrica analógica. El microcontrolador digitaliza la señal mediante el conversor analógico-digital y procesa las muestras adquiridas en tiempo real. Si el nivel del sonido supera el umbral configurado, el algoritmo de detección valida el evento como relevante. El microcontrolador envía una notificación a través del módulo Bluetooth al dispositivo móvil. La aplicación recibe el evento, lo muestra en pantalla y genera una alerta visual para el usuario. |
| Flujos alternativos | a. El sonido detectado no supera el umbral configurado. El sistema continúa monitoreando sin generar notificación. b. El módulo Bluetooth no se encuentra conectado al dispositivo móvil. El evento puede registrarse localmente, pero no se envía notificación. c. El usuario modifica los parámetros de sensibilidad desde la aplicación. El sistema actualiza la configuración y continúa operando con los nuevos valores. |

A continuación, se incorporan los diagramas de estado correspondientes al sistema desarrollado. En primer lugar, en la Figura 2.2.1, se presenta la máquina de estados asociada a la placa, donde se describe el comportamiento del _hardware_ del microcontrolador, incluyendo los estados de inicialización, monitoreo, detección de eventos, notificación y configuración. El modelado fue realizado utilizando la herramienta itemis CREATE, y puede consultarse tanto el archivo _Placa_Statechart.ysc_ como el archivo _Statecharts.exe_ adjunto (ambos en la carpeta _Statecharts_), donde se detallan los estados, eventos y transiciones implementadas \[15\]\[16\].

<span style="color:red"><strong>⚠ AGREGAR LA MÁQUINA DE ESTADO DE LA PLACA (SUBIR LOS ARCHIVOS DEL STATECHART Y EL EXCEL)</strong></span>

Posteriormente, se incluye la máquina de estados correspondiente a la aplicación móvil (Figura 2.2.2), en la cual se representan los distintos estados vinculados a la conexión _Bluetooth_, recepción de eventos, visualización de alertas y configuración de parámetros. Del mismo modo, el diagrama puede observarse en el archivo _App_Statechart.ysc_ junto con el archivo _Statecharts.exe_ asociado (ambos en la carpeta _Statecharts_), donde se documenta formalmente su estructura \[17\].

<img width="600" src="App_Statechart.png" >

**Figura 2.2.2**: Máquina de estados de la aplicación móvil.

## **2.3 Descripción de los módulos del sistema**
## **2.3.1 Alimentación**
La alimentación de BeepBuddy se realizó mediante la placa de desarrollo NUCLEO-F103RB, la cual se conectó a una computadora portátil a través de un cable _USB Type A Type mini B_ \[2\].

El puerto _USB_ proporcionó una tensión nominal de 5 V _DC_. La placa NUCLEO incorpora reguladores de tensión internos que generan 3,3 V para el microcontrolador y permiten disponer de líneas de 5 V y 3,3 V para la alimentación de dispositivos externos (como se muestra en la Figura 2.3.1.1), tales como el _buzzer_ y el módulo _Bluetooth BLE_, ambos conectados a 3,3 V.

<img width="600" src="MicrocontroladorReferenciadeDiseño.jpg" >

**Figura 2.3.1.1**: Referencia de diseño de la placa NUCLEO-F103RB tomada de las guías de trabajo de la cátedra \[3\].

Por otro lado, el módulo del micrófono se alimentó directamente desde el pin de 5 V provisto por la placa, compartiendo masa común con el resto del sistema.

Cabe destacar que esta configuración resultó adecuada para la etapa de prototipo (_MVP_). En una versión autónoma futura del dispositivo sería necesario incorporar una fuente regulada independiente.

## **2.3.2 Microcontrolador**
Como microcontrolador del sistema se utilizó la placa NUCLEO-F103RB conectada a la computadora portátil a través de un cable _USB Type A Type mini B_. La elección de la misma recayó exclusivamente en que fue la propuesta por la cátedra de la asignatura y fue con la que se trabajó a lo largo del ciclo lectivo. La placa se programó en C a través de la aplicación *STM32CubeIDE 1.19.0* y se muestra en la Figura 2.3.2.1 \[4\].

<img width="300" src="Microcontrolador.webp" >

**Figura 2.3.2.1**: Placa NUCLEO-F103RB.

El sistema utiliza la memoria de la _flash_ interna del microcontrolador como almacenamiento no vólatil para conservar la configuración de usuario (_SET_UP_ en los archivos _config.h_ y _config.c_ del proyecto), evitando la pérdida de parámetros ante reinicios o cortes de energía \[5\]. Así, las variables inicializadas en el código se recargan desde la misma a la _RAM_ en cada _reset_, por lo que cualquier modificación realizada en tiempo de ejecución se pierde.

## **2.3.3 Módulo de micrófono**
Para la detección acústica se utilizó un módulo sensor de sonido con micrófono regulable Arduino Nubbeo del tipo KY-037 como se observa en la Figura 2.3.3.1 \[6\].

<img width="300" src="MóduloMicrófono.jpg" >

**Figura 2.3.3.1**: Módulo de micrófono.

El mismo, permite detectar la presencia de sonido ambiente y generar una salida digital cuando el nivel de sonido supera el umbral configurable a partir del potenciómetro incorporado en la placa (el cual se ajustó aproximadamente a la mitad del rango de operación del micrófono), y una salida analógica proporcional a la amplitud de la señal captada por el sensor.

El micrófono electret convierte la onda sonora en una señal eléctrica analógica de baja amplitud, la cual es amplificada por el circuito interno del módulo. Posteriormente, el comparador interno evalúa si la señal amplificada supera el umbral y, si esto ocurre, la salida digital cambia de estado y se enciende el LED indicador de detección. Por útlimo, la salida analógica entrega una señal proporcional a la amplitud del sonido captado, permitiendo su lectura mediante el conversor analógico-digital del microcontrolador.

## **2.3.4 Módulo _Bluetooth_**
Para la comunicación inalámbrica entre BeepBuddy y el dispositivo móvil receptor, se utilizó un módulo _Bluetooth_ compatible con _Bluetooth Low Energy (BLE)_ del tipo HM-10, como se observa en las Figuras 2.3.4.1 y 2.3.4.2 \[7\]\[8\].

<img width="300" src="MóduloBluetooth.webp" >

**Figura 2.3.4.1**: Módulo _Bluetooth_ (vista superior).

<img width="300" src="MóduloBluetooth2.webp" >

**Figura 2.3.4.2**: Módulo _Bluetooth_ (vista inferior).

El módulo HM-10 es un adaptador inalámbrico que implementa la especificación _Bluetooth 4.0 BLE_, permitiendo la transmisión de datos en la banda _ISM_ de 2.4 GHz (_Industrial, Scientific and Medical_, rango de frecuencias de radio libre de licencia que cualquier dispositivo puede usar sin necesidad de permiso especial). Este módulo facilita el enlace inalámbrico entre el microcontrolador y el dispositivo móvil emparejado, posibilitando el envío de notificaciones y la configuración remota del sistema.

Desde el punto de vista funcional, el HM-10 dispone de una interfaz de comunicación serial _UART_ (_Universal Asynchronous Receiver/Transmitter_, el cual envía y recibe datos de a un bit a la vez, de forma secuencial) que permite intercambiar datos entre el microcontrolador y el módulo _Bluetooth_. Cuando el microcontrolador detecta un evento de sonido que cumple los criterios de detección configurados, transmite un paquete de datos a través de la interfaz _UART_ al módulo HM-10, el cual lo reenvía inalámbricamente al dispositivo móvil emparejado previamente.

## **2.3.5 Módulo _buzzer_**
En el dispositivo desarrollado, el _buzzer_ (observado en las Figuras 2.3.5.1 y 2.3.5.2) se implementó exclusivamente para emitir un breve pitido cuando el _switch_ principal pasa del estado _OFF_ a _ON_, indicando al usuario que el sistema ha sido energizado correctamente \[9\]\[10\].

<img width="300" src="MóduloBuzzer.jpg">

**Figura 2.3.5.1:** Módulo _buzzer_ (vista superior).

<img width="300" src="MóduloBuzzer2.jpg">

**Figura 2.3.5.2:** Módulo _buzzer_ (vista inferior).

El mismo, está basado en un transductor piezoeléctrico, el cual produce sonido cuando se le aplica una señal eléctrica alterna que provoca la vibración mecánica de un diafragma cerámico.

Si bien el módulo fue comercializado como un _buzzer_ activo (es decir, con oscilador interno y capaz de funcionar al aplicarle una tensión continua), experimentalmente se verificó que no generaba sonido ante la aplicación de una señal continua. Por este motivo, fue necesario excitarlo mediante una señal cuadrada generada por el microcontrolador mediante modulación por ancho de pulso (_PWM_), suministrando así la señal alterna requerida para su funcionamiento.

## **2.3.6 Interfaz de usuario: _DIP switch_ y LEDs**
La interfaz de usuario del dispositivo está compuesta por un _DIP switch_ (_Dual In-line Package switch_) de tres posiciones y cuatro _LEDs_ (_Light Emitting Diodes_), los cuales permiten visualizar el estado de funcionamiento y el modo de operación seleccionado \[11\]. Los mismos se muestran a continuación en las Figuras 2.3.6.1 y 2.3.6.2.

<img width="150" src="DipSwitch.webp">

**Figura 2.3.6.1:** _DIP switch_.

<img width="150" src="LEDs.jpeg">

**Figura 2.3.6.2:** _LEDs_.

La primera posición del _switch_ corresponde al encendido general del sistema. Cuando se la coloca en posición _ON_, el dispositivo se energiza, se enciende el _LED_ verde y el _buzzer_ emite un breve pitido. En caso de que no se seleccione ningún modo de operación, también se enciende el _LED_ rojo, indicando estado por defecto (modo no definido).

La segunda posición del interruptor _DIP_ habilita el modo día, encendiéndose el _LED_ amarillo como indicador visual, mientras que, al colocarlo en la tercera posición, se activa el modo noche encendiéndose el _LED_ azul.

Los modos de operación (día/noche) solo pueden activarse cuando la primera posición (encendido general, inidicada con el _LED_ verde) se encuentra en estado _ON_. Si las tres posiciones del _switch_ se encuentran activadas simultáneamente, el sistema entra nuevamente en el estado de _default_, encendiéndose el _LED_ rojo.

# **CAPÍTULO 3**

# **Diseño e implementación**

## **3.1 Diseño del _hardware_**
El diseño de _hardware_ del sistema se basó en la placa, cuya configuración de pines fue realizado mediante la herramienta de inicialización de periféricos (_STM32CubeIDE 1.19.0_), permitiendo asignar las funciones correspondientes a cada módulo externo. Esto se puede observar en la Figura 3.1.a a continuación.

<img width="600" src="ConfigPinesPlaca.jpeg">

**Figura 3.1.a:** Configuración de los pines del NUCLEO-F103RB.

Dado que la placa dispone de un único pin de salida de 3.3 V, se realizó una distribución de dicha tensión mediante la placa para alimentar los módulos correspondientes. Todas las masas fueron unificadas para garantizar referencia común en el sistema.

En las Figuras 3.1.b y 3.1.c se incluyen las vistas <span style="color:red"><strong>⚠ PONER FOTO CUANDO ESTÉ SOLDADO Y TERMINADO</strong></span> deL _hardware_ una vez finalizado el proceso de soldadura, permitiendo visualizar la disposición física de los componentes y las conexiones realizadas.

A continuación, se describe la conexión de cada uno de los módulos externos, acompañada por sus respectivos esquemas eléctricos.

## **3.1.1 Conexión del módulo del micrófono**
El micrófono utilizado posee salida analógica (_AO_), la cual fue conectada al pin _PA0_ (_MIC_) del microcontrolador, configurado como entrada del conversor analógico-digital (_ADC_). La alimentación del módulo se realizó con 5 V y masa común del sistema. La salida digital (_DO_) del módulo no fue utilizada en esta implementación.

Como se muestra en la Figura 3.1.1, el procesamiento de la señal se realiza a partir de la lectura analógica directa del pin _PA0_.

<img width="400" src="EsquemáticoMicro.jpg">

**Figura 3.1.1:** Esquemático del módulo del micrófono.

## **3.1.2 Conexión del módulo _Bluetooth_**
El pin _TX_ del módulo _Bluetooth_ fue conectado al pin _PA10_ (_USART1_RX_) y el pin _RX_ al _PA9_ (_USART1_TX_), estableciendo la comunicación serial cruzada correspondiente. El módulo fue alimentado con 3.3 V provenientes del pin de alimentación de la placa, el cual fue distribuido a través de la placa para alimentar tanto el _Bluetooth_ como el _buzzer_, ya que el microcontrolador dispone de un único pin de 3.3 V.

Los pines _STATE_ y _EN_ no fueron utilizados en esta implementación. La Figura 3.1.2 presenta el esquema de conexión del módulo.

<img width="400" src="EsquemáticoBlue.jpg">

**Figura 3.1.1:** Esquemático del módulo _Bluetooth_.

## **3.1.2 Conexión del módulo del _buzzer_**
El _buzzer_ fue conectado al pin _PC7_ (_TIM3_CH2_) del microcontrolador configurado como salida del temporizador, permitiendo la generación de señal _PWM_ para la emisión del sonido. La alimentación del módulo se realizó a 3.3 V y masa común.

El esquema correspondiente se presenta en la Figura 3.1.2 a continuación.

<span style="color:red"><strong>⚠ HACER Y AGREGAR ESQUEMA BUZZER</strong></span>

## **3.1.3 Conexión del _DIP switch_**
El _DIP switch_ se conectó configurando cada línea como entrada digital del microcontrolador. Los terminales posteriores fueron conectados a _GND_, mientras que los terminales frontales se vincularon a _PA1_ (_DIP_SWITCH_1_), _PA4_ (_DIP_SWITCH_2_) y a _TB0_ (_DIP_SWITCH_3_). Esta configuración permite detectar el estado lógico de cada interruptor mediante lectura digital directa.

La conexión se muestra en la Figura 3.1.3.

<span style="color:red"><strong>⚠ HACER Y AGREGAR ESQUEMA DIP SWITCH</strong></span>

## **3.1.4 Conexión de los _LEDs_**
Se colocaron los cuatro _LEDs_ indicadores (verde, rojo, amarillo y azul) a los pines del microcontrolador indicados a continuación (configurados como salida digital) y, a través de una resistencia limitadora, a masa:

- _LED_ verde → _PA8_ (1 kΩ)

- _LED_ rojo → _PB10_ (10 Ω)

- _LED_ amarillo → _PB4_ (1,8 kΩ)

- _LED_ azul → _PB5_ (1 kΩ)

## **3.2 _Firmware_ de _BeepBuddy_**
<span style="color:red"><strong>⚠ CONTINUAR DESDE ACÁ</strong></span>

## **3.3 Diseño de la aplicación**
<span style="color:red"><strong>⚠ CONTINUAR DESDE ACÁ</strong></span>

# **CAPÍTULO 4**

# **Ensayos y resultados**

## **4.1 Mediciones**
## **4.1.1 Consumo energético**
<span style="color:red"><strong>⚠ MARI DEBERÍA MEDIRLO Y PASAR LA INFO</strong></span>

## **4.1.2 Tiempos de ejecución de cada tarea (WCET)**
<span style="color:red"><strong>⚠ MARI DEBERÍA MEDIRLO Y PASAR LA INFO (YA PUDO PONERLO EN EL CÓDIGO)</strong></span>

<span style="color:red"><strong>⚠ Captura de pantalla de "Console & Build Analyzer" luego de compilar la versión final MARI DEBERÍA MEDIRLO Y PASAR LA INFO.</strong></span>

## **4.1.3 Cálculo del factor de uso (U) de la CPU**
<span style="color:red"><strong>⚠ MARI DEBERÍA MEDIRLO Y PASAR LA INFO</strong></span>


## **4.2 Metodología de desarrollo**
El desarrollo del trabajo se llevó a cabo de manera incremental, organizándose en distintas etapas que permitieron estructurarlo y recibir devoluciones parciales antes de avanzar a la siguiente instancia. Cada etapa estuvo respaldada por la elaboración de archivos específicos que concentraron la información relevante para su revisión y validación.

En una primera instancia se elaboró el archivo _README.md_, en el cual se presentó el proyecto, se definió su objetivo, la necesidad que motivó su desarrollo, los requisitos funcionales y se realizó una comparación general con productos preexistentes en el mercado \[12\]. Este documento permitió establecer el marco conceptual del trabajo.

Posteriormente, se confeccionó el archivo _Lista_componentes_a_confirmar.txt_, que consistió en un listado preliminar de los componentes electrónicos a utilizar en el prototipo, incluyendo enlaces a las publicaciones correspondientes para su compra \[13\]. Este documento tuvo como finalidad someter la selección de _hardware_ a la revisión del docente antes de efectuar la compra.

Finalmente, se elaboró el _InformeDeAvances.md_, donde se retomaron los requisitos definidos inicialmente y se actualizó periódicamente el estado de cumplimiento de cada uno \[14\]. Este archivo permitió documentar el progreso del desarrollo.

## **4.3 Cumplimiento de requisitos**
Una vez finalizado el trabajo, se tomó la Tabla 2.1.1 (definida anteriormente en la Sección 2.1) y se definió el estado de cada uno de los requisitos iniciales del dispositivo, detallados a continuación en la Tabla 4.3.1.

**Tabla 4.3.1:** Estado de los requisitos del proyecto. 

<table>
<thead>
<tr>
<th>Grupo</th>
<th>ID</th>
<th>Descripción</th>
<th>Estado</th>
</tr>
</thead>

<tbody>

<tr>
<td>Adquisición</td>
<td>1.1</td>
<td>El sistema cuenta con un micrófono para captar sonidos del entorno.</td>
<td>COMPLETADO</td>
</tr>
<tr>
<td></td>
<td>1.2</td>
<td>El sistema digitaliza la señal sonora mediante el ADC de la placa STM.</td>
<td>COMPLETADO</td>
</tr>

<tr>
<td>Procesamiento</td>
<td>2.1</td>
<td>El sistema detecta sonidos relevantes (llanto, alarma, golpes, palabra clave).</td>
<td>COMPLETADO</td>
</tr>
<tr>
<td></td>
<td>2.2</td>
<td>El usuario puede configurar sensibilidad y parámetros mediante un switch.</td>
<td>COMPLETADO</td>
</tr>
<tr>
<td></td>
<td>2.3</td>
<td>El sistema almacena parámetros configurables en memoria.</td>
<td>COMPLETADO</td>
</tr>

<tr>
<td>Notificación</td>
<td>3.1</td>
<td>El sistema envía notificaciones a un dispositivo móvil vía Bluetooth.</td>
<td>COMPLETADO</td>
</tr>
<tr>
<td></td>
<td>3.2</td>
<td>Las notificaciones son inmediatas ante detección de eventos.</td>
<td>COMPLETADO</td>
</tr>

<tr>
<td>Aplicación</td>
<td>4.1</td>
<td>La aplicación muestra alertas visuales asociadas a los sonidos detectados.</td>
<td>COMPLETADO</td>
</tr>
<tr>
<td></td>
<td>4.2</td>
<td>La aplicación permite consultar el historial de alertas.</td>
<td>COMPLETADO</td>
</tr>
<tr>
<td></td>
<td>4.3</td>
<td>La aplicación indica el estado de conexión Bluetooth del dispositivo.</td>
<td>COMPLETADO</td>
</tr>
<tr>
<td></td>
<td>4.4</td>
<td>La aplicación permite definir el umbral de sensibilidad.</td>
<td>COMPLETADO</td>
</tr>
<tr>
<td></td>
<td>4.5</td>
<td>La aplicación permite elegir diferentes modos de funcionamiento.</td>
<td>COMPLETADO</td>
</tr>

<tr>
<td>Interfaz física</td>
<td>5.1</td>
<td>El sistema cuenta con un switch para seleccionar el modo de operación.</td>
<td>COMPLETADO</td>
</tr>
<tr>
<td></td>
<td>5.2</td>
<td>El sistema cuenta con indicadores LEDs básicos de funcionamiento (encendido/apagado, modo y estado de conexión Bluetooth).</td>
<td>COMPLETADO</td>
</tr>
<tr>
<td></td>
<td>5.3</td>
<td>El sistema emite un pitido al ser encendido.</td>
<td>COMPLETADO</td>
</tr>

<tr>
<td>Requisitos de operación</td>
<td>6.1</td>
<td>El dispositivo funciona sin conexión a internet.</td>
<td>COMPLETADO</td>
</tr>
<tr>
<td></td>
<td>6.2</td>
<td>El sistema tiene bajo consumo energético.</td>
<td>COMPLETADO</td>
</tr>
<tr>
<td></td>
<td>6.3</td>
<td>El sistema es seguro y confiable.</td>
<td>COMPLETADO</td>
</tr>

</tbody>
</table>

<span style="color:red"><strong>⚠ IR VIENDO SI SE AGREGAN NUEVOS REQUISITOS Y SUS ESTADOS EN EL INFORME DE AVANCES Y SI ALGUNO NO SE COMPLETA O ALGO ACLARAR CON UN COMENTARIO ACÁ</strong></span>

## **4.4 Comparación con otros sistemas similares**
Como se mencionó previamente en la Sección 1.1, el mercado actual cuenta con diversos dispositivos de monitoreo con características relacionadas a la captación y transmisión de sonido. Sin embargo, la mayoría de estos están pensados para usuarios sin limitaciones auditivas y no contemplan específicamente la problemática abordada en este trabajo. Por este motivo, y considerando la diversidad de enfoques presentes en el mercado, resulta complejo establecer una comparación estrictamente equivalente entre el prototipo desarrollado y los dispositivos disponibles, ya que cada uno prioriza distintos criterios de diseño y aplicación.

En este contexto, el aporte principal del presente desarrollo radica en su enfoque inclusivo, orientado a brindar una alternativa accesible frente a soluciones convencionales existentes. Asimismo, el sistema presenta posibilidades de evolución futura, tales como la incorporación de dispositivos de notificación háptica (por ejemplo, mediante una pulsera con vibración) o el uso de sensores portátiles, lo que permitiría mejorar la comodidad y adaptabilidad del usuario.

## **4.5 Documentación del desarrollo realizado**
A continuación, en la Tabla 4.5.1 muestra la documentación del desarrollo del proyecto.

**Tabla 4.5.1**: Desarrollo del proyecto.
| Nombre                 | Fecha de Finalización     |
|------------------------|---------------------------|
| _README.md_    | 11 de Diciembre del 2025    |
| _Lista_componentes_a_confirmar.txt_    | 23 de Diciembre del 2025    |
| _InformeDeAvances.md_    | <span style="color:red"><strong>⚠ SE SIGUE ACTUALIZANDO</strong></span>  |
| _MemoriaDelTrabajoFinal.md_ | <span style="color:red"><strong>⚠ SE SIGUE ACTUALIZANDO</strong></span>   |


<span style="color:red"><strong>⚠ CONTINUAR DESDE ACÁ EL CAPÍTULO 5</strong></span>

# **Bibliografía** 
\[1\] MIT App Inventor. [Online]. Available: https://appinventor.mit.edu/

\[2\] Manual de usuario de la placa NUCLEO-F103RB. [Online]. Available: https://www.st.com/en/evaluation-tools/nucleo-f103rb.html

\[3\] Aula virtual de la cátedra TA134 TALLER DE SISTEMAS EMBEBIDOS. [Online]. Available: https://campusgrado.fi.uba.ar/course/view.php?id=1217

\[4\] STM32CubeIDE. Integrated Development Environment for STM32. [Online]. Available:https://www.st.com/en/development-tools/stm32cubeide.html

\[5\] Carpeta donde se pueden hallar los archivos _config.h_ y _config.c_. [Online]. Available: https://github.com/CavalittoDiazTubinezFerrero/tdse-tf_1-01/tree/23b1ec407466f7fa20007029bb58381ecce89ee9/config

\[6\] Manual de usuario del módulo de micrófono. [Online]. Available: https://www.alldatasheet.com/datasheet-pdf/download/1284506/JOY-IT/KY037.html

\[7\] Módulo HM-10 bluetooth 4.0 BLE a UART. TodoMicro. [Online]. Available: https://www.todomicro.com.ar/comunicacion/637-modulo-hm-10-bluetooth-40-ble-a-uart.html?srsltid=AfmBOopp0r5laITQYUaryYYiX3FX0pVC3rmiN0xScYLpI9sgNRYFOCRr

\[8\] Manual de usuario del módulo _Bluetooth_. [Online]. Available: https://www.alldatasheet.com/datasheet-pdf/download/1179058/ETC1/HM-10.html

\[9\] Módulo Buzzer Activo 3.3v A 5v. [Online]. Available: https://www.mercadolibre.com.ar/modulo-buzzer-activo-33v-a-5v/p/MLA2048303554?pdp_filters=seller_id%3A302249631#polycard_client=recommendations_vip-seller_data_items-above&reco_backend=ranker-retsys-same-seller&reco_model=rk_entity_sameseller&reco_client=vip-seller_data_items-above&reco_item_pos=0&reco_backend_type=low_level&reco_id=4009794f-8183-4ec4-8aa5-5448369b409f&wid=MLA752290080&sid=recos

\[10\] Manual de usuario del módulo _buzzer_. [Online]. Available: https://www.alldatasheet.com/datasheet-pdf/pdf/169124/ETC2/EFM-236L.html

\[11\] Manual de usuario del _DIP switch_. [Online]. Available: https://www.alldatasheet.es/datasheet-pdf/view/2015587/AGELECTRONICA/DIP-3.html

\[12\] Archivo _README.md_. [Online]. Available: https://github.com/CavalittoDiazTubinezFerrero/tdse-tf_1-01/blob/887ec480aa596c8a60271f712966aa281ff874fb/README.md

\[13\] Archivo _Lista_componentes_a_confirmar.txt_. [Online]. Available: https://github.com/CavalittoDiazTubinezFerrero/tdse-tf_1-01/blob/887ec480aa596c8a60271f712966aa281ff874fb/Lista_componentes_a_confirmar.txt

\[14\] Archivo _InformeDeAvances.md_. [Online]. Available: https://github.com/CavalittoDiazTubinezFerrero/tdse-tf_1-01/blob/887ec480aa596c8a60271f712966aa281ff874fb/InformeDeAvances.md

\[15\] Archivo _Statecharts.exe_. [Online]. Available: <span style="color:red"><strong>⚠ SUBIR EXCEL AL REPO CUANDO SE TERMINE EL STATECHART DE LA PLACA</strong></span>

\[16\] Archivo _Placa_Statechart.ysc_. [Online]. Available: <span style="color:red"><strong>⚠ SUBIR ITEMIS AL REPO CUANDO SE TERMINE EL STATECHART DE LA PLACA</strong></span>

\[17\] Archivo _App_Statechart.ysc_. [Online]. Available: <span style="color:red"><strong>⚠ SUBIR ITEMIS AL REPO CUANDO SE TERMINE EL STATECHART DE LA PLACA</strong></span>

\[.\] Google Gemini. [Online]. Available: https://gemini.google.com/app?hl=es_419

\[.\] Chat GPT. [Online]. Available: https://chatgpt.com
