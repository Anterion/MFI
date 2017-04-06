SEMAPHORE:

Dos procesos con un semáforo para que haya un dispensador de tickets y cada proceso interesado en entrar en la zona crítica
obtenga un número de ticket y sólo pueda entrar cuando le toque.

ELEVATOR:

Modelar el comportamiento de un ascensor de 4 plantas. Cada una de las plantas tiene un botón de llamada. El recorrido 
del ascensor de una planta a otra durará una única unidad de tiempo, es decir, el cambio de la planta 2 a la planta 3 debe
realizarse en un único cambio de estado. Cuando llega a una de las plantas, el ascensor abre las puertas y las mantiene
abiertas durante una unidad de tiempo, luego las cierra y procede a servir otra petición. El ascensor deberá mantener una
dirección hasta satisfacer todas las peticiones existentes en esa dirección.

ABP:

Cuando A tiene un mensaje para enviar a B, lo repite indefinidamente por el canal de A a B utilizando el mismo bit de
protocolo hasta que recibe una confirmación (acknowledgement) de B con el mismo bit de protocolo. Al recibir la confirmación,
A empieza a transmitir el siguiente mensaje disponible con el bit de protocolo cambiado, es decir, mensaje anterior: 0,
siguiente mensaje: 1 o al revés. Cuando B recibe un mensaje, lo acepta para procesar y manda a A una confirmación incluyendo el
mismo bit de protocolo del mensaje recibido. Ante sucesivos mensajes con el mismo bit de protocolo, lo único que hace es mandar
la misma confirmación con el mismo bit de protocolo. Es decir, básicamente, el bit de protocolo identifica cada uno de los
mensajes y el emisor repite el mensaje hasta que recibe una confirmación del receptor, a su vez el receptor repite siempre la
confirmación del mensaje que le llega. Para modelar la pérdida de mensajes, el canal de comunicación deberá escoger de forma
indeterminista entre copiar el mensaje en la salida o desecharlo.

TRAINS:

Cuatro trenes que salen de estaciones distintas y deben llegar todos a la misma estación. Los trenes todos viajan a 1 km/h pero
tienen distintas características:

Tren 1 tiene cuatro vagones y la distancia a recorrer es de 10 kilómetros.
Tren 2 tiene diez vagones y la distancia a recorrer es de 10 kilómetros.
Tren 3 tiene seis vagones y la distancia a recorrer es de 10 kilómetros.
Tren 4 tiene dos vagones y la distancia a recorrer es de 20 kilómetros.

Sin embargo hay un túnel por el que todos los trenes deben pasar antes de llegar a la estación de destino y en el cual sólo
cabe un tren cada vez y, debido al peso, sólo puede llevar dos vagones a la vez. El túnel se encuentra a 5 kilómetros antes de
la estación de llegada.
