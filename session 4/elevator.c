bool botones[4];
int planta = 1;
mtype = { arriba, parado, abajo, abiertas, cerradas };
mtype puertas = cerradas;
mtype direccion = parado;
init{
	botones[0] = false;
	botones[1] = false;
	botones[2] = true;
	botones[3] = false;
	do
		::puertas == cerradas && direccion == parado && botones[planta] ->
			puertas = abiertas;
			botones[planta] = false;

			// Sube
		::planta == 0 && direccion == arriba && (botones[1] || botones[2] || botones[3]) && puertas == cerradas ->
			planta = planta + 1;

		::planta == 1 && direccion == arriba && (botones[2] || botones[3]) && puertas == cerradas ->
			planta = planta + 1;

		::planta == 2 && direccion == arriba && botones[3] && puertas == cerradas ->
			planta = planta + 1;

			// Baja
		::planta == 3 && direccion == abajo && (botones[2] || botones[1] || botones[0]) && puertas == cerradas ->
			planta = planta - 1;

		::planta == 2 && direccion == abajo && (botones[1] || botones[0]) && puertas == cerradas ->
			planta = planta - 1;

		::planta == 1 && direccion == abajo && botones[0] && puertas == cerradas ->
			planta = planta - 1;

			// Cierra puertas para subir
		::planta == 0 && puertas == abiertas && direccion == parado && (botones[1] || botones[2] || botones[3]) ->
			puertas = cerradas;
			direccion = arriba;

		::planta == 1 && puertas == abiertas && direccion == parado && (botones[2] || botones[3]) ->
			puertas = cerradas;
			direccion = arriba;

		::planta == 2 && puertas == abiertas && direccion == parado && (botones[3]) ->
			puertas = cerradas;
			direccion = arriba;

			// Cierra puertas para bajar
		::planta == 3 && puertas == abiertas && direccion == parado && (botones[2] || botones[1] || botones[0]) ->
			puertas = cerradas;
			direccion = abajo;

		::planta == 2 && puertas == abiertas && direccion == parado && (botones[1] || botones[0]) ->
			puertas = cerradas;
			direccion = abajo;

		::planta == 1 && puertas == abiertas && direccion == parado && botones[0] ->
			puertas = cerradas;
			direccion = abajo;

			// Para cuando llega donde iba (subiendo)
		::planta == 0 && direccion == arriba && !(botones[1] || botones[2] || botones[3]) && puertas == cerradas ->
      direccion = parado;

    ::planta == 1 && direccion == arriba && !(botones[2] || botones[3]) && puertas == cerradas ->
      direccion = parado;

    ::planta == 2 && direccion == arriba && !(botones[3]) && puertas == cerradas ->
      direccion = parado;

			// Para cuando llega donde iba (bajando)

		::planta == 3 && direccion == abajo && !(botones[1] || botones[2] || botones[0]) && puertas == cerradas ->
			direccion = parado;

		::planta == 2 && direccion == abajo && !(botones[1] || botones[0]) && puertas == cerradas ->
			direccion = parado;

		::planta == 1 && direccion == abajo && !(botones[0]) && puertas == cerradas ->
      direccion = parado;

			// Arranca para subir
		::planta == 0 && direccion == parado && (botones[1] || botones[2] || botones[3]) && puertas == cerradas ->
      direccion = arriba;

    ::planta == 1 && direccion == parado && (botones[2] || botones[3]) && puertas == cerradas ->
      direccion = arriba;

    ::planta == 2 && direccion == parado && (botones[3]) && puertas == cerradas ->
      direccion = arriba;

			// Arranca para bajar
		::planta == 3 && direccion == parado && (botones[1] || botones[2] || botones[0]) && puertas == cerradas ->
			direccion = abajo;

		::planta == 2 && direccion == parado && (botones[1] || botones[0]) && puertas == cerradas ->
			direccion = abajo;

		::planta == 1 && direccion == parado && (botones[0]) && puertas == cerradas ->
      direccion = abajo;

	od;
}
ltl closed {[] ((direccion != parado) -> (puertas == cerradas))}
ltl liveness0 {[] ((botones[0]) -> (<> (botones[0] == false)))}
ltl liveness1 {[] ((botones[1]) -> (<> (botones[1] == false)))}
ltl liveness2 {[] ((botones[2]) -> (<> (botones[2] == false)))}
ltl liveness3 {[] ((botones[3]) -> (<> (botones[3] == false)))}
