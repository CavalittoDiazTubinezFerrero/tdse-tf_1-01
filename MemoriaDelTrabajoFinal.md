<img src="https://github.com/user-attachments/assets/15600b18-f73b-4ba3-a959-47f0048a1ab6" alt="image2" width="30%">

**UNIVERSIDAD DE BUENOS AIRES**  
**Facultad de Ingeniería**  
**TA134 Taller de Sistemas Embebidos**

Memoria del Trabajo Final:

***BeepBuddy***

**Autores:**

**Sra. Emilia Cavalitto - 109394**

**Sra. María Teresa Diaz Tubiñez - 104838**

**Sr. Ulises Ferrero - 105034**

*Este trabajo fue realizado en la Ciudad Autónoma de Buenos Aires,*   
*entre Diciembre y Febrero de 2025 y 2026\.*

  
**RESUMEN**

En este trabajo se presenta el diseño e implementación de BeepBuddy, un sistema embebido destinado a la detección y notificación de eventos sonoros en tiempo real. El mismo fue concebido como una herramienta de asistencia para personas con discapacidad auditiva y como apoyo en el cuidado de personas, permitiendo alertar ante la presencia de sonidos relevantes del entorno. Su objetivo es ofrecer una solución portátil y configurable que facilite el monitoreo acústico en contextos cotidianos.

El sistema está compuesto por una plataforma de desarrollo provista por la cátedra de Taller de Sistemas Embebidos de la Facultad de Ingeniería de la Universidad de Buenos Aires que integra un microcontrolador con conversor analógico-digital, temporizadores y un módulo de comunicación Bluetooth de bajo consumo. El procesamiento de audio y la lógica de control fueron desarrollados en lenguaje C, mientras que la aplicación móvil utilizada para la configuración y recepción de notificaciones se implementó mediante la herramienta MIT App Inventor. El desarrollo del proyecto implicó la integración de hardware y software bajo criterios de diseño modular y uso eficiente de recursos. En esta memoria se describen la motivación, la arquitectura del sistema, las decisiones de diseño adoptadas y las pruebas realizadas para validar su funcionamiento.


**ABSTRACT**

This work presents the design and implementation of BeepBuddy, an embedded system for real-time detection and notification of acoustic events. The system is intended as an assistive solution for individuals with hearing impairments and as a support tool in caregiving scenarios, generating alerts when relevant environmental sounds are identified. The proposed device provides a portable and configurable platform for acoustic monitoring in everyday environments.

The system is based on a development board integrating a microcontroller with an analog-to-digital converter, hardware timers, and a low-energy Bluetooth communication module. Audio acquisition and control logic were implemented in the C programming language, while the mobile application for system configuration and notification reception was developed using MIT App Inventor. The project required the integration of hardware and software following modular design principles and efficient resource management typical of embedded systems. This document describes the system architecture, design methodology, implementation details, and validation results.
