<div align="center">

<p align="center">
<img src="Figuras/logo-fiuba.png" width="300">
</p>

<strong>UNIVERSIDAD DE BUENOS AIRES</strong><br>
<strong>Facultad de Ingeniería</strong><br>

<h2 style="margin: 10px 0 10px 0;">
TA134 – Taller de Sistemas Embebidos<br>
Memoria del Trabajo Final
</h2>
<h2 style="margin: 10px 0 10px 0;">
<em>BeepBuddy</em> – Dispositivo de monitoreo acústico
</h2>

<strong>Autores:</strong><br>
**Emilia Cavalitto** – Legajo 109394<br>
**María Teresa Diaz Tubiñez** – Legajo 104838<br>
**Ulises Ferrero** – Legajo 105034

<br>

_Este trabajo fue realizado en la<br>
Ciudad Autónoma de Buenos Aires,<br>
entre Diciembre 2025 y Febrero 2026_

<br><br><br>

</div>



**RESUMEN**

En este trabajo se presenta el diseño e implementación de _BeepBuddy_, un sistema embebido destinado a la detección y notificación de eventos sonoros en tiempo real. El mismo fue concebido como una herramienta de asistencia para personas con discapacidad auditiva y como apoyo en el cuidado de personas, permitiendo alertar ante la presencia de sonidos relevantes del entorno. Su objetivo es ofrecer una solución portátil y configurable que facilite el monitoreo acústico en contextos cotidianos.

El sistema está compuesto por una plataforma de desarrollo provista por la cátedra de Taller de Sistemas Embebidos de la Facultad de Ingeniería de la Universidad de Buenos Aires que integra un microcontrolador con conversor analógico-digital, temporizadores y un módulo de comunicación _Bluetooth_ de bajo consumo. El procesamiento de audio y la lógica de control fueron desarrollados en lenguaje C, mientras que la aplicación móvil utilizada para la configuración y recepción de notificaciones se implementó mediante la herramienta [MIT App Inventor](https://appinventor.mit.edu/) . El desarrollo del proyecto implicó la integración de _hardware_ y _software_ bajo criterios de diseño modular y uso eficiente de recursos, para lo cual se empleó la plataforma [itemis CREATE](https://www.itemis.com/en/products/itemis-create/).

En esta memoria se describen la motivación, la arquitectura del sistema, las decisiones de diseño adoptadas y las pruebas realizadas para validar su funcionamiento.


**ABSTRACT**

This work presents the design and implementation of _BeepBuddy_, an embedded system for real-time detection and notification of acoustic events. The system is intended as an assistive solution for individuals with hearing impairments and as a support tool in caregiving scenarios, generating alerts when relevant environmental sounds are identified. The proposed device provides a portable and configurable platform for acoustic monitoring in everyday environments.

The system is based on a development board integrating a microcontroller with an analog-to-digital converter, hardware timers, and a low-energy _Bluetooth_ communication module. Audio acquisition and control logic were implemented in the C programming language, while the mobile application for system configuration and notification reception was developed using [MIT App Inventor](https://appinventor.mit.edu/). The project required the integration of hardware and software following modular design principles and efficient resource management typical of embedded systems, for which the [itemis CREATE](https://www.itemis.com/en/products/itemis-create/) modeling environment was employed.

This document describes the system architecture, design methodology, implementation details, and validation results.

---

# Índice General

- [**Registro de versiones**](#registro-de-versiones)
- [**Introducción general**](#introducción-general)
  - [1.1 Análisis de necesidad y objetivos](#11-análisis-de-necesidad-y-objetivos)
  - [1.2 Descripción general del sistema](#12-descripción-general-del-sistema)
- [**Introducción específica**](#introducción-específica) 
  - [2.1 Requisitos](#21-requisitos)
  - [2.2 Descripción de uso y diagramas de estado](#22-descripción-de-uso-y-diagramas-de-estado)
  - [2.3 Descripción de los módulos del sistema](#23-descripción-de-los-módulos-del-sistema)
    - [2.3.1 Alimentación](#231-alimentación)
    - [2.3.2 Microcontrolador](#232-microcontrolador)
    - [2.3.3 Módulo del micrófono](#233-módulo-de-micrófono)
    - [2.3.4 Módulo _Bluetooth_](#234-módulo-bluetooth)
    - [2.3.5 Módulo _buzzer_](#235-módulo-buzzer)
    - [2.3.6 Interfaz de usuario: _DIP switch_ y _LEDs_](#236-interfaz-de-usuario-dip-switch-y-leds)
  - [**Diseño e implementación**](#diseño-e-implementación)
    - [3.1 Diseño del _hardware_](#31-diseño-del-hardware)
      - [3.1.1 Conexión del módulo del micrófono](#311-conexión-del-módulo-del-micrófono)
      - [3.1.2 Conexión del módulo _Bluetooth_](#311-conexión-del-módulo-bluetooth)
      - [3.1.3 Conexión del módulo del _buzzer_](#312-conexión-del-módulo-del-buzzer)
      - [3.1.4 Conexión del _DIP switch_](#314-conexión-del-dip-switch)
      - [3.1.5 Conexión de los _LEDs_](#315-conexión-de-los-leds)
    - [3.2 _Firmware_ de _BeepBuddy_](#32-firmware-de-beepbuddy)
      - [3.2.1 Organización modular del _firmware_](#321-organización-modular-del-firmware)
      - [3.2.2 Flujo de ejecución del _firmware_](#322-flujo-de-ejecución-del-firmware)
    - [3.3 Diseño de la aplicación](#33-diseño-de-la-aplicación)
  - [**Ensayos y resultados**](#ensayos-y-resultados)
    - [4.1 Mediciones](#41-mediciones)
      - [4.1.1 Consumo energético](#411-consumo-energético)
      - [4.1.2 Tiempos de ejecución de cada tarea (_WCET_)](#412-tiempos-de-ejecución-de-cada-tarea-(wcet))
      - [4.1.3 Cálculo del factor de uso (U) de la _CPU_](#413-cálculo-del-factor-de-uso-(u)-de-la-cpu)
    - [4.2 Metodología de desarrollo](#42-metodología-de-desarrollo)
    - [4.3 Cumplimiento de requisitos](#43-cumplimiento-de-requisitos)
    - [4.4 Comparación con otros productos similares](#44-comparación-con-otros-productos-similares)
    - [4.5 Documentación del desarrollo realizado](#45-documentación-del-desarrollo-realizado)
  - [**Conclusiones**](#conclusiones)
    - [5.1 Resultados obtenidos](#51-resultados-obtenidos)
    - [5.2 Próximos pasos y posibles futuras mejoras](#52-próximos-pasos-y-posibles-futuras-mejoras)
  - [**Uso de herramientas de _IA_**](#uso-de-herramientas-de-ia)
- [**Bibliografía**](#bibliografía)

---
## Registro de versiones

Inicialmente, se adjunta la Tabla 0, la cual registra las diferentes versiones de la memoria del trabajo práctico final.
<div align="center">

<p><strong>Tabla 0:</strong> Registro de versiones de <em>BeepBuddy</em>.</p>

</div>

| Revisión | Cambios realizados | Fecha de finalización |
| :---: | ----- | ----- |
| 1.0 | Creación del documento | 10/02/2026 |
| 1.1 | Redacción del primer capítulo | 11/02/2026 |
| 1.2 | Redacción del segundo capítulo | 14/02/2026 |
| 1.3 | Redacción del tercer capítulo | 22/02/2026 |
| 1.4 | Redacción del cuarto capítulo | 16/02/2026 |
| 1.5 | Redacción del quinto capítulo | 24/02/2026 |
| 1.6 | Redacción del sexto capítulo | 25/02/2026 |
| 1.7 | Revisión y ajustes finales | .../02/2026|

<span style="color:red"><strong>⚠ IR COMPLETANDO A MEDIDA QUE SE VAYAN ESCRIBIENDO CADA UNA DE LAS SECCIONES</strong></span>
 
---
### 

# **CAPÍTULO 1** 

# **Introducción general** 

## **1.1 Análisis de necesidad y objetivos** 

En los últimos años, el desarrollo de diferentes tecnologías ha permitido la creación de dispositivos dedicados a tareas específicas con mayor eficiencia, bajo consumo y mayor confiabilidad que otras opciones más generales. Sin embargo, en el ámbito del monitoreo sonoro aplicado al cuidado infantil o supervisión del entorno, muchas soluciones comerciales no contemplan las necesidades de personas con discapacidad auditiva.

Los monitores de bebé convencionales, por ejemplo, transmiten audio hacia un receptor portátil, pero requieren que el usuario pueda escuchar los sonidos detectados. Por otro lado, los monitores inteligentes con video suelen depender de conectividad _Wi-Fi_, servicios en la nube y aplicaciones complejas, lo que incrementa su costo como así también el consumo energético. Asimismo, las aplicaciones móviles de detección de sonido utilizan el micrófono del teléfono, lo que implica alto consumo de batería y baja confiabilidad.

En este contexto, surge la necesidad de desarrollar un dispositivo embebido dedicado, autónomo y configurable, capaz de detectar eventos sonoros relevantes y notificar de manera inmediata mediante comunicación _Bluetooth_, sin requerir conexión a internet. Así, el objetivo de este trabajo fue diseñar e implementar un sistema que permitiera asistir a personas con discapacidad auditiva en tareas de cuidado, particularmente en contextos donde la detección rápida de sonidos como llanto, alarmas o golpes resulta crítica. _BeepBuddy_ se propuso como un producto mínimo viable que solventara cada una de estas características, priorizando confiabilidad, facilidad de uso y bajo consumo energético. A su vez, el valor agregado del proyecto radica en la posibilidad de configurar parámetros como sensibilidad y modos de operación.

## **1.2 Descripción general del sistema**

_BeepBuddy_ está compuesto por dos subsistemas principales: el dispositivo embebido de detección sonora y la aplicación móvil de notificación y configuración.
El primero integra un micrófono para la captación de señales acústicas, el microcontrolador con conversor analógico-digital para la digitalización de la señal, temporizadores para el control del muestreo y un módulo de comunicación _Bluetooth_ para el envío y recepción de alertas. Asimismo, cuenta con una interfaz física básica compuesta por botones de configuración (_DIP switch_) e indicadores luminosos de estado (_LEDs_).
La aplicación móvil fue desarrollada utilizando la herramienta [MIT App Inventor](https://appinventor.mit.edu/), la cual permite la visualización de alertas, elección de estados, consulta de historial y verificación del estado de conexión.

En la Figura 1.2.1 se presenta el diagrama en bloques general del sistema, donde se observan los principales módulos y su interconexión.
<div align="center">

<img width="600" src="Figuras/DiagramaenBloquesdetallado.png">

<p><strong>Figura 1.2.1</strong>: Diagrama en bloques general de <em>BeepBuddy</em>.</p>

</div>

El funcionamiento general del dispositivo puede resumirse de la siguiente manera: el micrófono capta continuamente los sonidos del entorno y el microcontrolador digitaliza la señal mediante el conversor analógico-digital a una frecuencia de muestreo controlada por temporizadores internos. Las muestras adquiridas son procesadas en tiempo real para determinar si el sonido detectado cumple con los criterios configurados de sensibilidad o corresponde a un evento relevante previamente definido. En caso de detectarse una condición válida, el sistema genera una alerta y la transmite mediante el módulo _Bluetooth_ al dispositivo móvil emparejado. La aplicación recibe la notificación, la muestra de forma visual al usuario y la registra en el historial de eventos. En ausencia de eventos significativos, el sistema continúa monitoreando el entorno de manera autónoma y con bajo consumo energético.

En las próximas secciones se describen con mayor detalle los módulos utilizados y sus características.

---
# **CAPÍTULO 2**

# **Introducción específica** 

## **2.1 Requisitos**

Habiendo analizado las características principales del dispositivo, se definieron los principales requisitos para que el sistema cumpla con su función de forma correcta y resulte útil para su propósito. Para esto, se realizó la Tabla 2.1.1, en la cual se definieron los principales requisitos a implementar.

<div align="center">
<p><strong>Tabla 2.1.1:</strong> Requisitos del proyecto.</p>
</div>

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
<td>El sistema digitaliza la señal sonora mediante el <em>ADC</em> de la placa <em>STM</em>.</td>
</tr>

<tr>
<td>Procesamiento</td>
<td>2.1</td>
<td>El sistema detecta sonidos relevantes (llanto, alarma, golpes, palabra clave).</td>
</tr>
<tr>
<td></td>
<td>2.2</td>
<td>El usuario puede configurar sensibilidad y parámetros mediante un <em>switch</em>.</td>
</tr>
<tr>
<td></td>
<td>2.3</td>
<td>El sistema almacena parámetros configurables en memoria.</td>
</tr>

<tr>
<td>Notificación</td>
<td>3.1</td>
<td>El sistema envía notificaciones a un dispositivo móvil vía <em>Bluetooth</em>.</td>
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
<td>La aplicación indica el estado de conexión <em>Bluetooth</em> del dispositivo.</td>
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
<td>El sistema cuenta con un <em>switch</em> para seleccionar el modo de operación.</td>
</tr>
<tr>
<td></td>
<td>5.2</td>
<td>El sistema cuenta con indicadores <em>LEDs</em> básicos de funcionamiento (encendido/apagado, modos y estado de conexión <em>Bluetooth</em>).</td>
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


## **2.2 Descripción de uso y diagramas de estado**

<div align="center">
<p><strong>Tabla 2.2.1:</strong> Descripción de uso.</p>
</div>

| Elemento | Definición |
| :---- | :---- |
| Disparador | Se produce un sonido en el entorno que supera el umbral de sensibilidad configurado. |
| Precondiciones | El sistema se encuentra encendido. El dispositivo está correctamente alimentado. El módulo _Bluetooth_ se encuentra emparejado con la aplicación móvil. Los parámetros de sensibilidad están configurados.  |
| Flujo principal | El micrófono capta el sonido del entorno y lo convierte en una señal eléctrica analógica. El microcontrolador digitaliza la señal mediante el conversor analógico-digital y procesa las muestras adquiridas en tiempo real. Si el nivel del sonido supera el umbral configurado, el algoritmo de detección valida el evento como relevante. El microcontrolador envía una notificación a través del módulo _Bluetooth_ al dispositivo móvil. La aplicación recibe el evento, lo muestra en pantalla generando una alerta visual para el usuario y lo guarda en su historial. |
| Flujos alternativos | a. El sonido detectado no supera el umbral configurado. El sistema continúa monitoreando sin generar notificación. b. El módulo _Bluetooth_ no se encuentra conectado al dispositivo móvil. El evento puede registrarse localmente, pero no se envía notificación. c. El usuario modifica los parámetros de sensibilidad desde la aplicación. El sistema actualiza la configuración y continúa operando con los nuevos valores. |

A continuación, se incorporan los diagramas de estado correspondientes al sistema desarrollado. En primer lugar, en la Figura 2.2.1, se presenta la máquina de estados asociada a la placa, donde se describe el comportamiento del _hardware_ del microcontrolador, incluyendo los estados de inicialización, monitoreo, detección de eventos, notificación y configuración. El modelado fue realizado utilizando la herramienta [itemis CREATE](https://www.itemis.com/en/products/itemis-create/), y pueden consultarse tanto el archivo [`Placa_Statechart.ysc`](https://github.com/CavalittoDiazTubinezFerrero/tdse-tf_1-01/blob/829bed8b9a3a83fd0f2c6891f38c5a664aa42d09/Statecharts/Placa_Statechart.ysc) como el archivo [`Statecharts.xlsx`](https://github.com/CavalittoDiazTubinezFerrero/tdse-tf_1-01/blob/209e34cd15df3201a05f59f1aa5d7f0c5443c734/Statecharts/Statechart.xlsx) adjuntos (ambos en la carpeta [`Statecharts`](https://github.com/CavalittoDiazTubinezFerrero/tdse-tf_1-01/tree/Entrega-de-memoria-del-trabajo-final/Statecharts)), donde se detallan los estados, eventos y transiciones implementadas.

<div align="center">

<img width="600" src="Figuras/Placa_Statechart.png">

<p><strong>Figura 2.2.1</strong>: Máquina de estados de la placa.</p>

</div>

Posteriormente, se incluye la máquina de estados correspondiente a la aplicación móvil (Figura 2.2.2), en la cual se representan los distintos estados vinculados a la conexión _Bluetooth_, recepción de eventos, visualización de alertas y configuración de parámetros. Del mismo modo, el diagrama puede observarse en el archivo [`App_Statechart.ysc`](https://github.com/CavalittoDiazTubinezFerrero/tdse-tf_1-01/blob/829bed8b9a3a83fd0f2c6891f38c5a664aa42d09/Statecharts/App_Statechart.ysc) junto con el archivo [`Statecharts.xlsx`](https://github.com/CavalittoDiazTubinezFerrero/tdse-tf_1-01/blob/209e34cd15df3201a05f59f1aa5d7f0c5443c734/Statecharts/Statechart.xlsx) asociado (ambos en la carpeta [`Statecharts`](https://github.com/CavalittoDiazTubinezFerrero/tdse-tf_1-01/tree/Entrega-de-memoria-del-trabajo-final/Statecharts)), donde se documenta formalmente su estructura.

<div align="center">

<img width="600" src="Figuras/App_Statechart.png">

<p><strong>Figura 2.2.2</strong>: Máquina de estados de la aplicación móvil.</p>

</div>

## **2.3 Descripción de los módulos del sistema**

## **2.3.1 Alimentación**

La alimentación de _BeepBuddy_ se realizó mediante la placa de desarrollo NUCLEO-F103RB, la cual se conectó a una computadora portátil a través de un cable _USB Type A Type mini B_ \[1\].

El puerto _USB_ proporcionó una tensión nominal de 5 V _DC_. La placa NUCLEO incorpora reguladores de tensión internos que generan 3,3 V para el microcontrolador y permiten disponer de líneas de 5 V y 3,3 V para la alimentación de dispositivos externos (como se muestra en la Figura 2.3.1.1), tales como el _buzzer_ y el módulo _Bluetooth BLE_, ambos conectados a 3,3 V.

<div align="center">
  
<img width="600" src="Figuras/MicrocontroladorReferenciadeDiseño.jpg">

<p><strong>Figura 2.3.1.1</strong>: Referencia de diseño de la placa NUCLEO-F103RB tomada de las guías de trabajo de la cátedra [2].</p>

</div>

Por otro lado, el módulo del micrófono se alimentó directamente desde el pin de 5 V provisto por la placa, compartiendo masa común con el resto del sistema.

Cabe destacar que esta configuración resultó adecuada para la etapa de prototipo (_MVP_). En una versión autónoma futura del dispositivo sería necesario incorporar una fuente regulada independiente.

## **2.3.2 Microcontrolador**

Como microcontrolador del sistema se utilizó la placa [NUCLEO-F103RB](https://www.st.com/en/evaluation-tools/nucleo-f103rb.html) conectada a la computadora portátil a través de un cable _USB Type A Type mini B_ como se mencionó anteriormente. La elección de la misma recayó exclusivamente en que fue la propuesta por la cátedra de la asignatura y fue con la que se trabajó a lo largo del ciclo lectivo. La placa se programó en lenguaje C a través de la aplicación [STM32CubeIDE 1.19.0](https://www.st.com/en/development-tools/stm32cubeide.html) y se muestra en la Figura 2.3.2.1.

<div align="center">

<img width="300" src="Figuras/Microcontrolador.webp">

<p><strong>Figura 2.3.2.1</strong>: Placa NUCLEO-F103RB.</p>

</div>

El sistema utiliza la memoria _flash_ interna del microcontrolador como almacenamiento no vólatil para conservar la configuración de usuario (`SET_UP` en los archivos [`config.h`](https://github.com/CavalittoDiazTubinezFerrero/tdse-tf_1-01/blob/cabf6f2aa755565a832ac6392c2ffda81915aa82/stm32-project/config/config.h) y [`config.c`](https://github.com/CavalittoDiazTubinezFerrero/tdse-tf_1-01/blob/cabf6f2aa755565a832ac6392c2ffda81915aa82/stm32-project/config/config.c) del proyecto), evitando la pérdida de parámetros ante reinicios o cortes de energía. En cada reinicio, el sistema lee los parámetros previamente guardados en la memoria _flash_ y los carga en memoria _RAM_ para su utilización durante la operación. Por lo tanto, los valores almacenados en la memoria no volátil son los que el dispositivo utiliza de manera habitual, mientras que los definidos en [`config.c`](https://github.com/CavalittoDiazTubinezFerrero/tdse-tf_1-01/blob/cabf6f2aa755565a832ac6392c2ffda81915aa82/stm32-project/config/config.c) actúan únicamente como valores iniciales o de respaldo.

## **2.3.3 Módulo del micrófono**

Para la detección acústica se utilizó un módulo sensor de sonido con micrófono regulable [Arduino Nubbeo del tipo KY-037](https://www.alldatasheet.com/datasheet-pdf/download/1284506/JOY-IT/KY037.html) como se observa en la Figura 2.3.3.1 \[3\].

<div align="center">

<img width="300" src="Figuras/MóduloMicrófono.jpg">

<p><strong>Figura 2.3.3.1</strong>: Módulo del micrófono.</p>

</div>

El mismo, permite detectar la presencia de sonido ambiente y generar una salida digital cuando el nivel de sonido supera el umbral configurable a partir del potenciómetro incorporado en la placa (el cual se ajustó aproximadamente a la mitad del rango de operación del micrófono), y una salida analógica proporcional a la amplitud de la señal captada por el sensor.

El micrófono _electret_ convierte la onda sonora en una señal eléctrica analógica de baja amplitud, la cual es amplificada por el circuito interno del módulo. Posteriormente, el comparador interno evalúa si la señal amplificada supera el umbral y, si esto ocurre, la salida digital cambia de estado y se enciende el _LED_ indicador de detección. Por útlimo, la salida analógica entrega una señal proporcional a la amplitud del sonido captado, permitiendo su lectura mediante el conversor analógico-digital del microcontrolador.

## **2.3.4 Módulo _Bluetooth_**

Para la comunicación inalámbrica entre la placa y el dispositivo móvil receptor, se utilizó un módulo _Bluetooth_ compatible con [_Bluetooth Low Energy (BLE)_ del tipo _HM-10_](https://www.alldatasheet.com/datasheet-pdf/download/1179058/ETC1/HM-10.html), como se observa en las Figuras 2.3.4.1 y 2.3.4.2 \[4\]\[5\].

<div align="center">

<img width="300" src="Figuras/MóduloBluetooth.webp">

<p><strong>Figura 2.3.4.1</strong>: Módulo <em>Bluetooth</em> (vista superior).</p>

</div>

<div align="center">

<img width="300" src="Figuras/MóduloBluetooth2.webp">

<p><strong>Figura 2.3.4.2</strong>: Módulo <em>Bluetooth</em> (vista inferior).</p>

</div>

El módulo _HM-10_ es un adaptador inalámbrico que implementa la especificación _Bluetooth 4.0 BLE_, permitiendo la transmisión de datos en la banda _ISM_ de 2.4 GHz (_Industrial, Scientific and Medical_, rango de frecuencias de radio libre de licencia que cualquier dispositivo puede usar sin necesidad de permiso especial). Este módulo facilita el enlace inalámbrico entre el microcontrolador y el dispositivo móvil emparejado, posibilitando el envío de notificaciones y la configuración remota del sistema.

Desde el punto de vista funcional, el _HM-10_ dispone de una interfaz de comunicación serial _UART_ (_Universal Asynchronous Receiver/Transmitter_, el cual envía y recibe datos de a un bit a la vez, de forma secuencial) que permite intercambiar datos entre el microcontrolador y el módulo _Bluetooth_. Cuando el microcontrolador detecta un evento de sonido que cumple los criterios de detección configurados, transmite un paquete de datos a través de la interfaz _UART_ al módulo _HM-10_, el cual lo reenvía inalámbricamente al dispositivo móvil emparejado previamente.

## **2.3.5 Módulo _buzzer_**

En el dispositivo desarrollado, el [_buzzer_](https://www.alldatasheet.com/datasheet-pdf/pdf/169124/ETC2/EFM-236L.html) (observado en las Figuras 2.3.5.1 y 2.3.5.2) se implementó exclusivamente para emitir un breve pitido cuando el _switch_ principal pasa del estado _OFF_ a _ON_, indicando al usuario que el sistema ha sido energizado correctamente \[6\]\[7\].

<div style="display: flex; justify-content: center; gap: 40px;">

<div align="center">
<img width="300" src="Figuras/MóduloBuzzer.jpg">
<p><strong>Figura 2.3.5.1</strong>: Módulo <em>buzzer</em> (vista superior).</p>
</div>

<div align="center">
<img width="300" src="Figuras/MóduloBuzzer2.jpg">
<p><strong>Figura 2.3.5.2</strong>: Módulo <em>buzzer</em> (vista inferior).</p>
</div>

</div>

El mismo, está basado en un transductor piezoeléctrico, el cual produce sonido cuando se le aplica una señal eléctrica alterna que provoca la vibración mecánica de un diafragma cerámico.

Si bien el módulo fue comercializado como un _buzzer_ activo (es decir, con oscilador interno y capaz de funcionar al aplicarle una tensión continua), experimentalmente se verificó que no generaba sonido ante la aplicación de una señal continua. Por este motivo, fue necesario excitarlo mediante una señal cuadrada generada por el microcontrolador mediante modulación por ancho de pulso (_PWM_), suministrando así la señal alterna requerida para su funcionamiento.

## **2.3.6 Interfaz de usuario: _DIP switch_ y _LEDs_**

La interfaz de usuario del dispositivo está compuesta por un [_DIP switch_](https://www.alldatasheet.es/datasheet-pdf/view/2015587/AGELECTRONICA/DIP-3.html) (_Dual In-line Package switch_) de tres posiciones y cuatro _LEDs_ (_Light Emitting Diodes_), los cuales permiten visualizar el estado de funcionamiento y el modo de operación seleccionado \[8\]. Los mismos se muestran a continuación en las Figuras 2.3.6.1 y 2.3.6.2.

<div style="display: flex; justify-content: center; gap: 60px;">

<div align="center">
<img width="150" src="Figuras/DipSwitch.webp">
<p><strong>Figura 2.3.6.1</strong>: <em>DIP switch</em>.</p>
</div>

<div align="center">
<img width="150" src="Figuras/LEDs.jpeg">
<p><strong>Figura 2.3.6.2</strong>: <em>LEDs</em>.</p>
</div>

</div>

La primera posición del _switch_ corresponde al encendido general del sistema. Cuando se la coloca en posición _ON_, el dispositivo se energiza, se enciende el _LED_ verde y el _buzzer_ emite un breve pitido. El _LED_ verde comienza a titilar indicando que el sistema se encuentra en espera de vinculación _Bluetooth_; una vez establecida la conexión, el mismo permanece encendido de forma fija. En caso de que no se seleccione ningún modo de operación, también se enciende el _LED_ rojo, indicando estado por defecto (modo no definido).

La segunda posición del interruptor _DIP_ habilita el modo día, encendiéndose el _LED_ amarillo como indicador visual, mientras que, al colocarlo en la tercera posición, se activa el modo noche encendiéndose el _LED_ azul.

Los modos de operación (día/noche) solo pueden activarse cuando la primera posición (encendido general, inidicada con el _LED_ verde) se encuentra en estado _ON_. Si las tres posiciones del _switch_ se encuentran activadas simultáneamente, el sistema entra nuevamente en el estado de _default_, encendiéndose el _LED_ rojo.

---
# **CAPÍTULO 3**

# **Diseño e implementación**

## **3.1 Diseño del _hardware_**

El diseño de _hardware_ del sistema se basó en la placa, cuya configuración de pines fue realizado mediante la herramienta de inicialización de periféricos [STM32CubeIDE 1.19.0](https://www.st.com/en/development-tools/stm32cubeide.html), permitiendo asignar las funciones correspondientes a cada módulo externo. Esto se puede observar en la Figura 3.1.a a continuación.

<div align="center">

<img width="600" src="Figuras/ConfigPinesPlaca.jpeg">

<p><strong>Figura 3.1.a</strong>: Configuración de los pines del NUCLEO-F103RB.</p>

</div>

Dado que la placa dispone de un único pin de salida de 3,3 V, se realizó una distribución de dicha tensión mediante la placa para alimentar los módulos correspondientes. Todas las masas fueron unificadas para garantizar referencia común en el sistema.

En las Figuras 3.1.b y 3.1.c se incluyen las vistas deL _hardware_ una vez finalizado el proceso de soldadura, permitiendo visualizar la disposición física de los componentes y las conexiones realizadas.

<div align="center">

<img width="600" src="Figuras/DispositivoTerminado1.jpeg">

<p><strong>Figura 3.1.b</strong>: Montaje final del prototipo (vista superior).</p>

</div>
<div align="center">

<img width="600" src="Figuras/DispositivoTerminado2.jpeg">

<p><strong>Figura 3.1.c</strong>: Montaje final del prototipo (vista lateral).</p>

</div>

A continuación, se describe la conexión de cada uno de los módulos externos, acompañada por sus respectivos esquemas eléctricos.

## **3.1.1 Conexión del módulo del micrófono**

El micrófono utilizado posee salida analógica (`AO`), la cual fue conectada al pin `PA0` (`MIC`) del microcontrolador, configurado como entrada del conversor analógico-digital (_ADC_). La alimentación del módulo se realizó con 5 V y masa común del sistema. La salida digital (`DO`) del módulo no fue utilizada en esta implementación. Como se muestra en la Figura 3.1.1, el procesamiento de la señal se realiza a partir de la lectura analógica directa del pin `PA0`.

<div align="center">

<img width="400" src="Figuras/EsquemáticoMicro.jpg">

<p><strong>Figura 3.1.1</strong>: Esquemático del módulo del micrófono.</p>

</div>

## **3.1.2 Conexión del módulo _Bluetooth_**

El pin `TX` del módulo _Bluetooth_ fue conectado al pin `PA10` (`USART1_RX`) y el pin `RX` al `PA9` (`USART1_TX`), estableciendo la comunicación serial cruzada correspondiente. El módulo fue alimentado con 3,3 V provenientes del pin de alimentación de la placa, el cual fue distribuido a través de la placa para alimentar tanto el _Bluetooth_ como el _buzzer_, ya que el microcontrolador dispone de un único pin de 3,3 V.

Los pines `STATE` y `EN` no fueron utilizados en esta implementación. La Figura 3.1.2 presenta el esquema de conexión del módulo.

<div align="center">

<img width="400" src="Figuras/EsquemáticoBlue.jpg">

<p><strong>Figura 3.1.2</strong>: Esquemático del módulo <em>Bluetooth</em>.</p>

</div>.

## **3.1.3 Conexión del módulo del _buzzer_**

El _buzzer_ fue conectado al pin `PC7` (`TIM3_CH2`) del microcontrolador configurado como salida del temporizador, permitiendo la generación de señal _PWM_ para la emisión del sonido. La alimentación del módulo se realizó a 3,3 V y masa común.

El esquema correspondiente se presenta en la Figura 3.1.3 a continuación.

<div align="center">

<img width="400" src="Figuras/EsquemáticoBuzzer.png">

<p><strong>Figura 3.1.3</strong>: Esquemático del módulo del <em>buzzer</em>.</p>

</div>

## **3.1.4 Conexión del _DIP switch_**

El _DIP switch_ se conectó configurando cada línea como entrada digital del microcontrolador. Los terminales posteriores fueron conectados a `GND`, mientras que los terminales frontales se vincularon a `PA1` (`DIP_SWITCH_1`), `PA4` (`DIP_SWITCH_2`) y a `TB0` (`DIP_SWITCH_3`). Esta configuración permite detectar el estado lógico de cada interruptor mediante lectura digital directa.
La conexión se muestra en la Figura 3.1.4.

<div align="center">

<img width="400" src="Figuras/EsquemáticoDIPswitch.png">

<p><strong>Figura 3.1.4</strong>: Esquemático del <em>DIP switch</em>.</p>

</div>

## **3.1.5 Conexión de los _LEDs_**

Se colocaron los cuatro _LEDs_ indicadores (verde, rojo, amarillo y azul) a los pines del microcontrolador indicados a continuación (configurados como salida digital) y, a través de una resistencia limitadora, a masa:

- _LED_ verde: `PA8` (1 kΩ)

- _LED_ rojo: `PB10` (10 Ω)

- _LED_ amarillo: `PB4` (1,8 kΩ)

- _LED_ azul: `PB5` (1 kΩ)

## **3.2 _Firmware_ de _BeepBuddy_**

La implementación del _firmware_ se realizó en C utilizando el entorno [STM32CubeIDE 1.19.0](https://www.st.com/en/development-tools/stm32cubeide.html). La configuración inicial de la placa STM32F103RB y sus periféricos (_GPIO_, _ADC_, _USART_ y temporizadores) fue generada mediante [STM32CubeMX](https://www.st.com/content/st_com/en/stm32cubemx.html), lo que permitió establecer el mapeo de pines y la configuración base del microcontrolador.

El archivo principal del sistema ([`main.c`](https://github.com/CavalittoDiazTubinezFerrero/tdse-tf_1-01/blob/cabf6f2aa755565a832ac6392c2ffda81915aa82/stm32-project/Core/Src/main.c)) contiene la inicialización de _hardware_ generada automáticamente y, posteriormente, ejecuta un bucle infinito (`while(1)`) en el cual se invoca de manera periódica la función principal de la aplicación, como se muestra en la Figura 3.2.

<div align="center">

<img width="250" src="Figuras/main.jpeg">

<p><strong>Figura 3.2</strong>: Líneas de código del archivo <code>main.c</code>.</p>

</div>

## **3.2.1 Organización modular del _firmware_**

A diferencia de una implementación monolítica, el proyecto fue estructurado en módulos funcionales organizados en carpetas específicas, lo que facilita la lectura, mantenimiento y escalabilidad del código.

<span style="color:red"><strong>⚠MARI AGREGAR LOS ARCHIVOS QUE HAYA HECHO NUEVOS</strong></span>

La carpeta [`app`](https://github.com/CavalittoDiazTubinezFerrero/tdse-tf_1-01/tree/cabf6f2aa755565a832ac6392c2ffda81915aa82/stm32-project/app) concentra la lógica principal del sistema. En ella se encuentran:
- `app_main.c / .h`: núcleo de la aplicación y gestión general del flujo.
- `sound_detector.c / .h`: implementación del algoritmo de detección de sonido.
- `mode_manager.c / .h`: gestión de los distintos modos de funcionamiento.
- `notifications.c / .h`: administración del envío y recepción de notificaciones.
- `logger.c / .h`: registro de eventos del sistema.

<span style="color:red"><strong>⚠ MARI AGREGAR LOS ARCHIVOS QUE HAYA HECHO NUEVOS</strong></span>
<span style="color:red"><strong>⚠ LOA RCHIVOS CONFIG NO ESTÁN EN LA CARPETA DE HARDWARE. ver qué hacer con eso y si quedan acá tmb linkearlos</strong></span

Por su parte, la carpeta [`hardware`](https://github.com/CavalittoDiazTubinezFerrero/tdse-tf_1-01/tree/cabf6f2aa755565a832ac6392c2ffda81915aa82/stm32-project/hardware) contiene los archivos [`config.c`]() y [`config.h`]() (donde se centralizan parámetros configurables del sistema) e incluye los módulos encargados de la interacción directa con los periféricos físicos:
- `mic.c / .h_: adquisición de señal analógica del micrófono mediante el _ADC_.
- `bluetooth.c / .h`: comunicación serial a través de _USART1_.
- `dip_switch.c / .h`: lectura del estado de los interruptores.
- `buzzer.c / .h`: generación de señal _PWM_ utilizando el temporizador _TIM3_.
- `led.c / .h`: control de los indicadores visuales.

En el archivo [`main.c`] se implementaron dos _callbacks_ asociados a interrupciones de _hardware_. Por un lado, la función `HAL_UART_RxCpltCallback()` gestiona la recepción de datos por _UART_ mediante interrupciones. Cada vez que se recibe un _byte_ por _USART1_, la rutina invoca `Bluetooth_OnRxByte()` para procesarlo y re-habilita inmediatamente la recepción con `HAL_UART_Receive_IT()`. Este esquema evitó el uso de _polling_, redujo el tiempo de _CPU_ ocioso y garantizó una atención inmediata a los datos entrantes sin bloquear la ejecución principal.

Por otro lado, la función `HAL_TIM_PeriodElapsedCallback()` se ejecuta periódicamente a partir del desborde del temporizador _TIM2_. En cada interrupción se realiza la lectura de una muestra del micrófono y se evalúa si existe detección de sonido mediante `Sound_IsDetected()`. En caso afirmativo, se activa una bandera (_sound_alert_flag_) que luego será procesada en el lazo principal. Este enfoque desacopló la adquisición temporalmente crítica del procesamiento de alto nivel, manteniendo tiempos determinísticos y evitando sobrecargar la rutina de interrupción.

En conjunto, ambos _callbacks_ demuestran un uso adecuado de interrupciones para tareas asíncronas (comunicación serie) y periódicas (muestreo del sensor), favoreciendo una arquitectura eficiente, no bloqueante y coherente con buenas prácticas en sistemas embebidos.

Esta separación entre lógica de aplicación y acceso a _hardware_ permitió mantener una arquitectura clara, donde cada módulo cumplió una función específica y bien delimitada. Todos los archivos mencionados se encuentran a disposición en la carpeta [`stm32-proyect`](https://github.com/CavalittoDiazTubinezFerrero/tdse-tf_1-01/tree/cabf6f2aa755565a832ac6392c2ffda81915aa82/stm32-project).

## **3.2.2 Flujo de ejecución del _firmware_**

Durante su ejecución, el sistema inicializa los periféricos y luego entra en el ciclo principal, donde:
- Se adquieren muestras del micrófono.
- Se gestiona la comunicación _Bluetooth_ con la aplicación móvil.
- Se actualiza el estado del sistema según el modo seleccionado.
- Se evalúa el nivel de señal respecto al umbral configurado.
- Se activan indicadores visuales o sonoros cuando corresponde.

## **3.3 Diseño de la aplicación**

Como se indicó anteriormente, la aplicación móvil fue desarrollada en [MIT App Inventor](https://appinventor.mit.edu/) utilizando programación basada en bloques. Su función principal es permitir la comunicación con la placa mediante _Bluetooth Low Energy_ (_BLE_), configurar parámetros de funcionamiento y visualizar las alertas generadas por el sistema. En la Figura 3.3.1 se muestran estos bloques y a continuación se explica brevemente el funcionamiento de cada uno de ellos.

<div align="center">

<img width="300" src="Figuras/BloquesApp.png">

<p><strong>Figura 3.3.1</strong>: Bloques de la aplicación.</p>

</div>

En primer lugar, la gestión de conexión se realiza a través del componente `BluetoothLE`. El bloque `BtnBuscar.Click` inicia la búsqueda de dispositivos disponibles, mientras que `BluetoothLE1.DeviceFound` construye dinámicamente la lista de dispositivos detectados. Mediante `LP_list.AfterPicking`, el usuario selecciona el dispositivo deseado. Una vez establecida la conexión, `BluetoothLE1.Connected` actualiza el estado de la interfaz e identifica el dispositivo vinculado, mientras que `BluetoothLE1.Disconnected` informa cuando no existe conexión activa.

En segundo lugar, la configuración del sistema se realiza mediante el envío de comandos a la placa. El bloque `enviar_umbral.Click` transmite el valor de sensibilidad seleccionado por el usuario. Asimismo, `Btn_modo_dia.Click` y `Btn_modo_noche.Click` permiten seleccionar el modo de funcionamiento correspondiente, mientras que `Btn_off.Click` detiene el funcionamiento del dispositivo y desactiva las alertas persistentes.

Finalmente, la recepción y procesamiento de eventos se gestionan mediante `BluetoothLE1.StringsReceived`, que interpreta las cadenas enviadas por la placa y ejecuta las acciones correspondientes en la interfaz. Al iniciar la aplicación, `Screen1.Initialize` carga el historial previamente almacenado, permitiendo al usuario consultar eventos anteriores.

De esta manera, la aplicación actúa como interfaz de usuario del sistema embebido, centralizando la configuración y visualización de alertas de forma remota. Seguidamente, se adjuntan capturas de pantalla de la interfaz de la aplicación ante diferentes eventos (Figuras 3.3.2, 3.3.3 y 3.3.4).

<div align="center">

<img width="300" src="Figuras/CapturaApp1.jpeg">

<p><strong>Figura 3.3.2</strong>: Captura de pantalla de la interfaz de la aplicación en Modo Día con historial de alertas.</p>

</div>
<div align="center">

<img width="300" src="Figuras/CapturaApp2.jpeg">

<p><strong>Figura 3.3.3</strong>: Captura de pantalla de la interfaz de la aplicación en Modo Noche con historial de alertas.</p>

<span style="color:red"><strong>⚠ AGREGAR CAPTURA DE PANTALLA DE LA APP CUANDO LLEGA UNA ALERTA</strong></span>

</div>
<div align="center">

<img width="300" src="Figuras/CapturaApp4.jpeg">

<p><strong>Figura 3.3.4</strong>: Captura de pantalla de la interfaz de la aplicación al recibir la notificación de alerta.</p>

</div>

La descripción detallada de la implementación de cada bloque y su interconexión lógica puede consultarse en el archivo [`BeepBuddy.apk`](https://github.com/CavalittoDiazTubinezFerrero/tdse-tf_1-01/blob/b2a7b0f1fec3dafd1492798bf15d7c766927add9/BeepBuddy.apk).
 
---
# **CAPÍTULO 4**

# **Ensayos y resultados**

## **4.1 Mediciones**

## **4.1.1 Consumo energético**

Con el objetivo de evaluar el consumo energético del sistema, se realizaron mediciones de corriente sobre la placa NUCLEO-F103RB utilizando un multímetro digital configurado como miliamperímetro.

De acuerdo con lo especificado en el manual [`UM1724 (STM32 Nucleo-64 boards)`](https://www.st.com/resource/en/user_manual/um1724-stm32-nucleo64-boards-mb1136-stmicroelectronics.pdf) y en el esquema eléctrico [`MB1136`](https://www.st.com/resource/en/schematic_pack/mb1136-default-c04_schematic.pdf), la placa dispone de _jumpers_ específicos que permiten medir el consumo de las líneas de 5 V y 3,3 V \[9\]\[10\]. Para realizar la medición correctamente, se retiró el _jumper_ correspondiente a la línea a analizar y se conectó el miliamperímetro en serie entre los pines del mismo, de manera de registrar la corriente total consumida por dicha línea.

Las corrientes máximas medidas fueron las siguientes: 

Línea de 5 V: 26,5 mA

Línea de 3,3 V: 10,2 mA

## **4.1.2 Tiempos de ejecución de cada tarea (_WCET_)**

Para la estimación experimental del _Worst Case Execution Time_ (_WCET_) de cada tarea del sistema se utilizó el contador de ciclos del procesador (_DWT_). Cada función relevante fue instrumentada reiniciando el contador antes de su ejecución y leyendo el tiempo transcurrido en microsegundos inmediatamente después, almacenando el mayor valor observado durante el período de prueba. Con el objetivo de poder recorrer sistemáticamente todos los caminos posibles de ejecución (recepción de comandos, cambios de estado, envío de notificaciones y generación de alertas), el lazo principal del programa fue modificado temporalmente, reemplazando el `while(1)` infinito por un lazo con duración aproximada de tres minutos. Esto permitió ejecutar múltiples iteraciones bajo distintas condiciones de funcionamiento y registrar valores representativos del tiempo máximo observado para cada tarea. Finalizado el período de medición, los valores de _WCET_ obtenidos fueron impresos mediante _LOGGER_, y posteriormente se restauró la estructura original de ejecución infinita del sistema.

<span style="color:red"><strong>⚠ Captura de pantalla o valores obtenidos de "Console & Build Analyzer" luego de compilar la versión final</strong></span>

## **4.1.3 Cálculo del factor de uso (U) de la _CPU_**

Con el objetivo de evaluar la utilización de recursos del sistema embebido, se analizó el factor de uso (U) de la _CPU_ a partir de la información obtenida durante la compilación del proyecto. Dichos datos fueron extraídos desde la consola de compilación y del análisis de memoria generado por [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html) (Figura 4.1.3). En este caso, se evaluaron tanto la memoria _RAM_ como la memoria _FLASH_.

<div align="center">

<img width="600" src="Figuras/ConsolaFLASH.jpeg">

<p><strong>Figura 4.1.3</strong>: Captura de la consola <em>Build Analyzer</em>.</p>

</div>

Estos valores indican que el sistema utiliza una fracción reducida de los recursos disponibles del microcontrolador STM32F103RB, manteniendo un amplio margen para futuras ampliaciones funcionales o incorporación de nuevas características. Además, confirma que la arquitectura modular implementada y la organización del _firmware_ resultaron eficientes en términos de consumo de memoria.

## **4.2 Metodología de desarrollo**

El desarrollo del trabajo se llevó a cabo de manera incremental, organizándose en distintas etapas que permitieron estructurarlo y recibir devoluciones parciales antes de avanzar a la siguiente instancia. Cada etapa estuvo respaldada por la elaboración de archivos específicos que concentraron la información relevante para su revisión y posterior validación.

En una primera instancia se elaboró el archivo [`README.md`](https://github.com/CavalittoDiazTubinezFerrero/tdse-tf_1-01/blob/887ec480aa596c8a60271f712966aa281ff874fb/README.md), en el cual se presentó el proyecto, se definió su objetivo, la necesidad que motivó su desarrollo, los requisitos funcionales y se realizó una comparación general con productos preexistentes en el mercado. Este documento permitió establecer el marco conceptual del trabajo.

Posteriormente, se confeccionó el archivo [`Lista_componentes_a_confirmar.txt`](https://github.com/CavalittoDiazTubinezFerrero/tdse-tf_1-01/blob/887ec480aa596c8a60271f712966aa281ff874fb/Lista_componentes_a_confirmar.txt), que consistió en un listado preliminar de los componentes electrónicos a utilizar en el prototipo, incluyendo enlaces a las publicaciones correspondientes para su compra. Este documento tuvo como finalidad someter la selección de _hardware_ a la revisión del docente antes de efectuar la compra de cada uno de ellos.

Finalmente, se elaboró el [`InformeDeAvances.md`](https://github.com/CavalittoDiazTubinezFerrero/tdse-tf_1-01/blob/887ec480aa596c8a60271f712966aa281ff874fb/InformeDeAvances.md), donde se retomaron los requisitos definidos inicialmente y se actualizó periódicamente el estado de cumplimiento de cada uno. Este archivo permitió documentar el progreso del desarrollo.

## **4.3 Cumplimiento de requisitos**

Una vez finalizado el trabajo, se tomó la Tabla 2.1.1 (definida anteriormente en la [Sección 2.1](#21-requisitos)) y se definió el estado de cada uno de los requisitos iniciales del dispositivo, detallados a continuación en la Tabla 4.3.1.

<div align="center">
<p><strong>Tabla 4.3.1:</strong> Estado de los requisitos del proyecto.</p>
</div>

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
<td>El sistema digitaliza la señal sonora mediante el <em>ADC</em> de la placa <em>STM</em>.</td>
<td>COMPLETADO</td>
</tr>

<tr>
<td>Procesamiento</td>
<td>2.1</td>
<td>El sistema detecta sonidos relevantes (llanto, alarmas, golpes).</td>
<td>COMPLETADO</td>
</tr>
<tr>
<td></td>
<td>2.2</td>
<td>El usuario puede configurar sensibilidad y parámetros mediante un <em>switch</em>.</td>
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
<td>El sistema envía notificaciones a un dispositivo móvil vía <em>Bluetooth</em>.</td>
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
<td>La aplicación indica el estado de conexión <em>Bluetooth</em> del dispositivo.</td>
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
<td>El sistema cuenta con un <em>switch</em> para seleccionar el modo de operación.</td>
<td>COMPLETADO</td>
</tr>
<tr>
<td></td>
<td>5.2</td>
<td>El sistema cuenta con indicadores <em>LEDs</em> básicos de funcionamiento (encendido/apagado, modo y estado de conexión <em>Bluetooth</em>).</td>
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

## **4.4 Comparación con otros productos similares**

Como se mencionó previamente en la [Sección 1.1](#11-análisis-de-necesidad-y-objetivos), el mercado actual cuenta con diversos dispositivos de monitoreo con características relacionadas a la captación y transmisión de sonido. Sin embargo, la mayoría de estos están pensados para usuarios sin limitaciones auditivas y no contemplan específicamente la problemática abordada en este trabajo. Por este motivo, y considerando la diversidad de enfoques presentes en el mercado, resulta complejo establecer una comparación estrictamente equivalente entre el prototipo desarrollado y los dispositivos disponibles, ya que cada uno prioriza distintos criterios de diseño y aplicación.

En este contexto, el aporte principal del presente desarrollo radica en su enfoque inclusivo, orientado a brindar una alternativa accesible frente a soluciones convencionales existentes. Asimismo, el sistema presenta posibilidades de evolución futura, tales como la incorporación de dispositivos de notificación háptica (por ejemplo, mediante una pulsera con vibración) o el uso de sensores portátiles, lo que permitiría mejorar la comodidad y adaptabilidad del usuario.

## **4.5 Documentación del desarrollo realizado**

A continuación, en la Tabla 4.5.1 se muestra la documentación del desarrollo del proyecto.

<div align="center">
<p><strong>Tabla 4.5.1:</strong> Desarrollo del proyecto.</p>
</div>

| Nombre                 | Fecha de Finalización     |
|------------------------|---------------------------|
| [`README.md`](https://github.com/CavalittoDiazTubinezFerrero/tdse-tf_1-01/blob/887ec480aa596c8a60271f712966aa281ff874fb/README.md)    | 11 de Diciembre del 2025    |
| [`Lista_componentes_a_confirmar.txt`](https://github.com/CavalittoDiazTubinezFerrero/tdse-tf_1-01/blob/887ec480aa596c8a60271f712966aa281ff874fb/Lista_componentes_a_confirmar.txt)    | 23 de Diciembre del 2025    |
| [`InformeDeAvances.md`](https://github.com/CavalittoDiazTubinezFerrero/tdse-tf_1-01/blob/887ec480aa596c8a60271f712966aa281ff874fb/InformeDeAvances.md)    | 22 de Febrero del 2026  |
| [`MemoriaDelTrabajoFinal.md`](https://github.com/CavalittoDiazTubinezFerrero/tdse-tf_1-01/blob/209e34cd15df3201a05f59f1aa5d7f0c5443c734/MemoriaDelTrabajoFinal.md) | <span style="color:red"><strong>⚠ SE SIGUE ACTUALIZANDO</strong></span>   |

---
# **CAPÍTULO 5**

# **Conclsuiones**

## **5.1 Resultados obtenidos**

El presente trabajo logró implementar satisfactoriamente un sistema de detección sonora con notificación remota mediante _Bluetooth_, cumpliendo con los objetivos planteados al inicio del proyecto. Se desarrolló un sistema con arquitectura modular y organización mediante máquinas de estado, lo que permitió un funcionamiento ordenado y escalable. El dispositivo detectó eventos sonoros según un umbral configurable y permitió establecer una comunicación bidireccional estable que permitió configurar y supervisar el sistema.

Asimismo, se verificó el correcto funcionamiento eléctrico del sistema mediante mediciones de consumo y análisis de utilización de memoria, confirmando que los recursos del microcontrolador fueron empleados de manera eficiente y con amplio margen para futuras ampliaciones.

En términos generales, se cumplieron los objetivos técnicos propuestos, logrando un prototipo funcional que integró _hardware_, _firmware_ y una aplicación móvil en un sistema coherente y operativo.

## **5.2 Próximos pasos y posibles futuras mejoras**

La evolución del prototipo contempla su rediseño hacia una versión más compacta y autónoma, incorporando, por ejemplo, una batería recargable integrada que elimine la necesidad de conexión permanente a la _PC_ y permita un uso verdaderamente portátil.

En términos de interfaz física, se prevé la sustitución del _DIP switch_ por botones o controles digitales más ergonómicos, simplificando la selección de modos de operación mejorando así la experiencia del usuario. Asimismo, se plantea la optimización de la interfaz de la aplicación móvil, fortaleciendo el flujo de notificaciones y mejorando su presentación visual para lograr una interacción más clara.

Desde el punto de vista funcional, el sistema se proyecta hacia la incorporación de un módulo de notificación háptica portátil, como una banda o pulsera vibratoria destinada a la persona con dificultad auditiva. Esta mejora permitiría generar alertas por vibración directamente en el usuario, incrementando la accesibilidad y la efectividad del dispositivo.

Finalmente, el desarrollo futuro incluye la migración del prototipo actual a una placa _PCB_ diseñada específicamente para el sistema, integrando los módulos utilizados en un formato reducido y más adecuado para una implementación definitiva

---
# **CAPÍTULO 6**

# **Uso de herramientas de _IA_**

Durante la elaboración del presente trabajo se utilizaron herramientas de inteligencia artificial (tales como [ChatGPT](https://chatgpt.com) y [Gemini](https://gemini.google.com/app?hl=es_419)) como apoyo complementario. Su uso estuvo orientado principalmente a la organización y estructuración del informe, ayudando a ordenar ideas y definir una base sobre la cual desarrollar los contenidos de manera coherente. Asimismo, sirvieron como guía inicial para organizar el trabajo práctico de forma modular y para establecer un punto de partida claro en las distintas etapas del desarrollo.

También se emplearon para asistencia en la redacción y aspectos formales del documento, incluyendo cuestiones vinculadas al formato en _Markdown_ y correcciones menores de escritura. Las decisiones técnicas, el diseño del sistema y la implementación del _hardware_ y _software_ fueron desarrollados íntegramente por el equipo, utilizándose la _IA_ únicamente como herramienta de apoyo.

---
# **Bibliografía**

\[1\] Manual de usuario de la placa NUCLEO-F103RB. [Online]. Available: https://www.st.com/en/evaluation-tools/nucleo-f103rb.html

\[2\] Aula virtual de la cátedra TA134 TALLER DE SISTEMAS EMBEBIDOS. [Online]. Available: https://campusgrado.fi.uba.ar/course/view.php?id=1217

\[3\] Manual de usuario del módulo del micrófono. [Online]. Available: https://www.alldatasheet.com/datasheet-pdf/download/1284506/JOY-IT/KY037.html

\[4\] Módulo HM-10 bluetooth 4.0 BLE a UART. TodoMicro. [Online]. Available: https://www.todomicro.com.ar/comunicacion/637-modulo-hm-10-bluetooth-40-ble-a-uart.html?srsltid=AfmBOopp0r5laITQYUaryYYiX3FX0pVC3rmiN0xScYLpI9sgNRYFOCRr

\[5\] Manual de usuario del módulo _Bluetooth_. [Online]. Available: https://www.alldatasheet.com/datasheet-pdf/download/1179058/ETC1/HM-10.html

\[6\] Módulo Buzzer Activo 3,3v A 5v. [Online]. Available: https://www.mercadolibre.com.ar/modulo-buzzer-activo-33v-a-5v/p/MLA2048303554?pdp_filters=seller_id%3A302249631#polycard_client=recommendations_vip-seller_data_items-above&reco_backend=ranker-retsys-same-seller&reco_model=rk_entity_sameseller&reco_client=vip-seller_data_items-above&reco_item_pos=0&reco_backend_type=low_level&reco_id=4009794f-8183-4ec4-8aa5-5448369b409f&wid=MLA752290080&sid=recos

\[7\] Manual de usuario del módulo _buzzer_. [Online]. Available: https://www.alldatasheet.com/datasheet-pdf/pdf/169124/ETC2/EFM-236L.html

\[8\] Manual de usuario del _DIP switch_. [Online]. Available: https://www.alldatasheet.es/datasheet-pdf/view/2015587/AGELECTRONICA/DIP-3.html

\[9\] UM1724 - User manual - STM32 Nucleo-64 boards. [Online]. Available: https://www.st.com/resource/en/user_manual/um1724-stm32-nucleo64-boards-mb1136-stmicroelectronics.pdf

\[10\] MB1136 - Electrical Schematic - ST M32 Nucleo-64 boards. [Online]. Available: https://www.st.com/resource/en/schematic_pack/mb1136-default-c04_schematic.pdf


Fin de la memoria técnica
Autores: Cavalitto Emilia, Diaz Tubiñez María Teresa, Ferrero Ulises
Fecha de edición: 26 de febrero de 2026 <span style="color:red"><strong>⚠ SE SIGUE ACTUALIZANDO</strong></span>
