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

  
**RESUMEN** (sin revisar!!!!)
El sistema desarrollado se basa en una arquitectura modular, donde cada funcionalidad (adquisición de audio, comunicación Bluetooth, gestión de notificaciones y control de periféricos) se implementa en módulos independientes con interfaces bien definidas. La adquisición de señal de audio se realiza mediante el ADC del microcontrolador, disparado periódicamente por un temporizador, lo que garantiza una frecuencia de muestreo constante y desacoplada del flujo principal del programa. El procesamiento de las muestras se lleva a cabo dentro de callbacks de interrupción para minimizar la latencia y asegurar una respuesta determinística, mientras que la lógica de más alto nivel se ejecuta en el bucle principal. Para la comunicación inalámbrica se utiliza un módulo BLE configurado como dispositivo periférico, implementando un protocolo simple basado en cadenas de texto delimitadas por caracteres de fin de línea, lo que permite una interpretación robusta de comandos desde una aplicación externa. El manejo de buffers incluye la correcta terminación con el carácter nulo para garantizar la integridad de los strings en C y evitar comportamientos indefinidos. Asimismo, se emplean mecanismos de control explícitos para el inicio y detención de periféricos como timers y ADC, con el objetivo de optimizar el consumo de recursos y evitar ejecuciones innecesarias. Este enfoque permite un sistema escalable, mantenible y fácilmente depurable, adecuado para aplicaciones embebidas que requieren procesamiento en tiempo real y comunicación confiable.
