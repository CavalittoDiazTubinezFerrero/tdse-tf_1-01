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

El sistema está compuesto por una plataforma de desarrollo provista por la cátedra de Taller de Sistemas Embebidos de la Facultad de Ingeniería de la Universidad de Buenos Aires que integra un microcontrolador con conversor analógico-digital, temporizadores y un módulo de comunicación Bluetooth de bajo consumo. El procesamiento de audio y la lógica de control fueron desarrollados en lenguaje C, mientras que la aplicación móvil utilizada para la configuración y recepción de notificaciones se implementó mediante la herramienta MIT App Inventor. El desarrollo del proyecto implicó la integración de hardware y software bajo criterios de diseño modular y uso eficiente de recursos. En esta memoria se describen la motivación, la arquitectura del sistema, las decisiones de diseño adoptadas y las pruebas realizadas para validar su funcionamiento.

<span style="color:red"><strong>⚠ REVISAR ÚLTIMA ORACIÓN!! VER SI DESP EFECTIVAMENTE SE HABLA DE ESTO EN EL INFORME</strong></span>


**ABSTRACT**

This work presents the design and implementation of BeepBuddy, an embedded system for real-time detection and notification of acoustic events. The system is intended as an assistive solution for individuals with hearing impairments and as a support tool in caregiving scenarios, generating alerts when relevant environmental sounds are identified. The proposed device provides a portable and configurable platform for acoustic monitoring in everyday environments.

The system is based on a development board integrating a microcontroller with an analog-to-digital converter, hardware timers, and a low-energy Bluetooth communication module. Audio acquisition and control logic were implemented in the C programming language, while the mobile application for system configuration and notification reception was developed using MIT App Inventor. The project required the integration of hardware and software following modular design principles and efficient resource management typical of embedded systems. This document describes the system architecture, design methodology, implementation details, and validation results.

<span style="color:red"><strong>⚠ REVISAR ÚLTIMA ORACIÓN!! VER SI DESP EFECTIVAMENTE SE HABLA DE ESTO EN EL INFORME</strong></span>


# Índice General

- [**Registro de versiones**](#registro-de-versiones)
- [**Introducción general**](#introducción-general)
  - [1.1 Análisis de necesidad y objetivos](#11-análisis-de-necesidad-y-objetivos)
  - [1.2 Proyectos similares y análisis comparativo](#12-proyectos-similares-y-análisis-comparativo)
  - [1.3 Descripción general del sistema](#13-descripción-general-del-sistema)
  - 
- [**Bibliografía**](#bibliografía)
    
<span style="color:red"><strong>⚠ IR COMPLETANDO A MEDIDA QUE SE VAYAN ESCRIBIENDO CADA UNA DE LAS SECCIONES</strong></span>


## Registro de versiones

| Revisión | Cambios realizados | Fecha |
| :---: | ----- | ----- |
| 1.0 | Creación del documento | 10/02/2026 |
| 1.1 | Redacción del primer capítulo | 11/02/2026 |
| 1.2 | Redacción del segundo capítulo | ... |
| 1.3 | Redacción del tercer capítulo | ... |
| 1.4 | Redacción final | ... |

<span style="color:red"><strong>⚠ IR COMPLETANDO A MEDIDA QUE SE VAYAN ESCRIBIENDO CADA UNA DE LAS SECCIONES</strong></span>
 
### 

# **CAPÍTULO 1** 

# **Introducción general** 

## **1.1 Análisis de necesidad y objetivos** 

En los últimos años, el desarrollo de tecnologías embebidas ha permitido la creación de dispositivos dedicados a tareas específicas con mayor eficiencia, bajo consumo y mayor confiabilidad que otras opciones más generales. Sin embargo, en el ámbito del monitoreo sonoro aplicado al cuidado infantil o supervisión del entorno, muchas soluciones comerciales no contemplan las necesidades de personas con discapacidad auditiva.

Los monitores de bebé convencionales, por ejemplo, transmiten audio hacia un receptor portátil, pero requieren que el usuario pueda escuchar los sonidos detectados. Por otro lado, los monitores inteligentes con video suelen depender de conectividad Wi-Fi, servicios en la nube y aplicaciones complejas, lo que incrementa su costo como así también el consumo energético. Asimismo, las aplicaciones móviles de detección de sonido utilizan el micrófono del teléfono, lo que implica alto consumo de batería y baja confiabilidad.

En este contexto, surge la necesidad de desarrollar un dispositivo embebido dedicado, autónomo y configurable, capaz de detectar eventos sonoros relevantes y notificar de manera inmediata mediante comunicación Bluetooth, sin requerir conexión a internet. Así, el objetivo de este trabajo fue diseñar e implementar un sistema que permita asistir a personas con discapacidad auditiva en tareas de cuidado, particularmente en contextos donde la detección rápida de sonidos como llanto, alarmas o golpes resulta crítica. BeepBuddy se propuso como un producto mínimo viable que integrara adquisición de audio, procesamiento en tiempo real y notificación inalámbrica, priorizando confiabilidad, facilidad de uso y bajo consumo energético.

## **1.2 Proyectos similares y análisis comparativo**

Existen distintas soluciones relacionadas con la detección sonora, entre ellas:
- Monitores de bebé convencionales.
- Monitores inteligentes con video y conectividad Wi-Fi.
- Aplicaciones móviles de detección de llanto o sonidos ambientales.

Los monitores de audio son económicos y simples, pero no resultan adecuados para personas con discapacidad auditiva, ya que dependen exclusivamente de la percepción sonora. Los monitores inteligentes con video incorporan funcionalidades avanzadas, pero presentan mayor complejidad técnica, costos elevados y dependencia de servicios externos. Las aplicaciones móviles, por su parte, no constituyen dispositivos dedicados, presentan alta demanda energética y menor robustez frente a ruido ambiental.

A diferencia de estas alternativas, BeepBuddy se plantea como un sistema embebido autónomo, diseñado específicamente para la detección de eventos sonoros y la generación de alertas visuales en un dispositivo móvil mediante Bluetooth de bajo consumo. Esto permite eliminar la dependencia de infraestructura Wi-Fi, reducir costos y mejorar la confiabilidad del sistema.

El valor agregado del proyecto radica en la posibilidad de configurar parámetros como sensibilidad y modos de operación, junto con la implementación de un menú interactivo accesible, todo ello sin requerir conexión a internet. Esta característica lo diferencia de soluciones comerciales que dependen de plataformas externas o servicios en la nube.

## **1.3 Descripción general del sistema**

BeepBuddy está compuesto por dos subsistemas principales: el dispositivo embebido de detección sonora y la aplicación móvil de notificación y configuración.
El primero integra un micrófono para la captación de señales acústicas, el microcontrolador con conversor analógico-digital para la digitalización de la señal, temporizadores para el control del muestreo y un módulo de comunicación Bluetooth para el envío de alertas. Asimismo, cuenta con una interfaz física básica compuesta por botones de configuración y un indicador luminoso de estado.
La aplicación móvil fue desarrollada utilizando la herramienta MIT App Inventor, permitiendo la visualización de alertas, consulta de historial y verificación del estado de conexión [1].

En la Figura 1.3.1 se presenta el diagrama en bloques general del sistema, donde se observan los principales módulos y su interconexión.

<img width="600" src="DiagramaenBloques.jpg" >

**Figura 1.3.1**: Diagrama en bloques general de BeepBuddy.

El funcionamiento general del dispositivo puede resumirse de la siguiente manera: el micrófono capta continuamente los sonidos del entorno y el microcontrolador digitaliza la señal mediante el conversor analógico-digital a una frecuencia de muestreo controlada por temporizadores internos. Las muestras adquiridas son procesadas en tiempo real para determinar si el sonido detectado cumple con los criterios configurados de sensibilidad o corresponde a un evento relevante previamente definido. En caso de detectarse una condición válida, el sistema genera una alerta y la transmite mediante el módulo Bluetooth al dispositivo móvil emparejado. La aplicación recibe la notificación, la muestra de forma visual al usuario y la registra en el historial de eventos. En ausencia de eventos significativos, el sistema continúa monitoreando el entorno de manera autónoma y con bajo consumo energético.

En las próximas secciones se describirá con mayor detalle los módulos utilizados y sus características.

# **Bibliografía** 
\[1\] MIT App Inventor. [Online]. Available: https://appinventor.mit.edu/
