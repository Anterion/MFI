# Practica 1

### Ejercicio 1
#### Que devuelve `red in ... : consume(- ^ - ^ nil)`?

El programa original devuelve `consume(- ^ - ^ nil)`.
Para arreglarlo, añadimos a la linea 13 `eq consume(nil) = nil .`. Esto hace que cuando se intente consumir nil devuelva la lista vacia y `consume (... nil)`.

### Ejercicio 2
#### _EBattery_ que no sea _ECell_ y _Battery_ que no sea _EBattery_ ni _ECell_

El ejemplo de término de tipo _EBattery_ pero no _ECell_ seria la bateria nil.
Cualquier batería distinta de nil valdria para el segundo enunciado.

### Ejercicio 3
#### Para que sirve diferenciar _ECell_ dentro de _Cell_?

Para poder representar casillas vacias.

### Ejercicio 4
#### Valores que pueden tomar un _EBattery_ y un _Battery_ con 2 celdas.

* _EBattery_ solo puede ser nil (es decir, `- ^ -`)
* _Battery_ tiene 9 valores posibles (todas las combinaciones de `o`, `+` y `-` en 2 espacios)

### Ejercicio 5
#### Que tipo devuelve la ejecucion de `red in ... : consume(- ^ -) .`?

Devuelve _EBattery_. Significa que sobre una batería vacía no se puede hacer `consume` porque no tiene ningún efecto.

### Ejercicio 6
#### Qué se obtiene al ejecutar `red in BATTERY-LEFT-RIGHT : consume-left-right(- ^ o ^ o) .` ?

Devuelve `consume-left-right(- ^ o ^ o)`. Intenta ejecutar una ecuación, pero en este caso casi todas las definiciones son reglas `rl`.

### Ejercicio 7
#### Qué se obtiene al ejecutar `rew in BATTERY-LEFT-RIGHT : consume-left-right(- ^ o ^ o) .` ?

Devuelve `Battery: - ^ + ^ +`. `rew` ejecuta una regla haciendo una sobreescritura.

### Ejercicio 8
#### Qué se obtiene al ejecutar `search in BATTERY-LEFT-RIGHT : consume-left-right(- ^ o ^ o) =>! Bt:Battery .` ?

```
Solution 1 (state 1)
states: 3  rewrites: 2 in 1ms cpu (0ms real) (2000 rewrites/second)
Bt --> - ^ + ^ o

Solution 2 (state 2)
states: 3  rewrites: 2 in 1ms cpu (0ms real) (2000 rewrites/second)
Bt --> - ^ o ^ +

No more solutions.
states: 3  rewrites: 2 in 1ms cpu (0ms real) (2000 rewrites/second)
```

`search` intenta hacer matching con las reglas definidas.

### Ejercicio 9
#### Qué se obtiene al ejecutar `search in BATTERY-LEFT-RIGHT : consume-left-right(- ^ o ^ o) =>* Bt:Battery .` ?

```
Solution 1 (state 0)
states: 1  rewrites: 0 in 0ms cpu (0ms real) (~ rewrites/second)
Bt --> consume-left-right(- ^ o ^ o)

Solution 2 (state 1)
states: 2  rewrites: 1 in 0ms cpu (0ms real) (~ rewrites/second)
Bt --> - ^ + ^ o

Solution 3 (state 2)
states: 3  rewrites: 2 in 0ms cpu (0ms real) (~ rewrites/second)
Bt --> - ^ o ^ +

No more solutions.
states: 3  rewrites: 2 in 0ms cpu (0ms real) (~ rewrites/second)
```

