# **BeepBuddy**
 ## **Informe de Avances**

**Autores:**
 - Cavalitto, Emilia - 109394
 - Diaz Tubiñez, María Teresa - 104838
 - Ferrero, Ulises - 105034

**Fecha: 2do cuatrimestre 2025**

A continuación se detalla el informe de avances del trabajo práctico final a partir de los requerimientos:

| Estado | Descripción      |
|-----|---------------------|
| ✅ | Ya implementado |
| 🟡 | En proceso |
| ❌ | No se implementará |

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
<td>El sistema contará con un micrófono para captar sonidos del entorno.</td>
<td>✅</td>
</tr>
<tr>
<td></td>
<td>1.2</td>
<td>El sistema digitalizará la señal sonora mediante el ADC de la placa STM.</td>
<td>✅</td>
</tr>

<tr>
<td>Procesamiento</td>
<td>2.1</td>
<td>El sistema deberá detectar sonidos relevantes (llanto, alarma, golpes, palabra clave).</td>
<td>✅</td>
</tr>
<tr>
<td></td>
<td>2.2</td>
<td>El usuario podrá configurar sensibilidad y parámetros mediante botones o interfaz sencilla</td>
<td>✅</td>
</tr>
<tr>
<td></td>
<td>2.3</td>
<td>El sistema almacenará parámetros configurables en memoria.</td>
<td>🟡</td>
</tr>

<tr>
<td>Notificación</td>
<td>3.1</td>
<td>El sistema enviará notificaciones a un dispositivo móvil vía Bluetooth .</td>
<td>🟡</td>
</tr>
<tr>
<td></td>
<td>3.2</td>
<td>Las notificaciones deberán incluir el tipo de sonido detectado.</td>
<td></td>
</tr>
<tr>
<td></td>
<td>3.3</td>
<td>Las notificaciones deberán ser inmediatas ante detección de eventos críticos.</td>
<td></td>
</tr>

<tr>
<td>Aplicación</td>
<td>4.1</td>
<td>La aplicación mostrará alertas visuales asociadas a los sonidos detectados.</td>
<td>🟡</td>
</tr>
<tr>
<td></td>
<td>4.2</td>
<td>La aplicación deberá permitir consultar el historial de alertas.</td>
<td></td>
</tr>
<tr>
<td></td>
<td>4.3</td>
<td>La aplicación deberá indicar el estado de conexión Bluetooth del dispositivo.</td>
<td></td>
</tr>

<tr>
<td>Interfaz física</td>
<td>5.1</td>
<td>El sistema contará con botones o switches para seleccionar modo de operación.</td>
<td>✅</td>
</tr>
<tr>
<td></td>
<td>5.2</td>
<td>El sistema tendrá un indicador LED básico de funcionamiento (encendido / alerta).</td>
<td>✅</td>
</tr>
<tr>
<td></td>
<td>5.2</td>
<td>El sistema emitirá un pitido al ser encendido.</td>
<td></td>
</tr>

<tr>
<td>Requisitos de operación</td>
<td>6.1</td>
<td>El dispositivo deberá funcionar sin conexión a internet.</td>
<td>✅</td>
</tr>
<tr>
<td></td>
<td>6.2</td>
<td>El sistema deberá tener bajo consumo energético.</td>
<td></td>
</tr>
<tr>
<td></td>
<td>6.3</td>
<td>El sistema deberá ser seguro y confiable, priorizando evitar omitir eventos reales.</td>
<td></td>
</tr>

</tbody>
</table>

<p align="center"><em>Tabla 2.1: Requisitos del proyecto</em></p>


**Comentarios:**

2.1 La detección de palabras clave o sonidos específicos nos está tomando más del tiempo estimado, por lo que decidimos limitar este punto, por ahora, a la detección de sonidos solo cuando sobrepasa un umbral configurable, de esta manera podemos avanzar con tópicos más relevantes para la materia.
