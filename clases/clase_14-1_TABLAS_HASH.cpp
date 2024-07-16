// Tecnica para buscar, recuperar y almacenar datos de forma eficiente
// Las tablas hash son estructuras de datos que asocian claves con valores
// El hashing convierte una entrada (como una cadena de caracteres o string) en
// un valor numerico (el hash) Utilizando una fincion hash Este valor determina
// la posicion o indice donde la clave y el valor asociado se almacenaran en la
// tabla hash 1) Si X es un valor numerico funcion Hash(x)= |X| % L, donde L =
// longitud del Array - 1 2) Si X es una cadena de caracteres funcion Hash(x)=
// Valor ASCII % L, Donde L= Longitud del Array - 1
/*
HASHING:tecnica apara buscar, recuperar y almacenar datos de forma eficiente.
Las tablas HASH son estructuras de datos que asocian claves con valores. El
hashing convierte una entrada (str) en un valor numerico (HASH) usando la
funcion hash. Este valor determina la posicion o indice donde la clave y valor
asociado se almacenara en la tabla Hash.

        Cuando dos elementos diferentes reciben el mismo valor, es decir; cuando
se asignan claves diferentes a una misma posicion en el vector se produce lo que
se denomina "colision"


        Formas de resolver las coliciones:

            Exploracion: se busca una posicion libre en el vector para albergar
la insercion del elemento, visita la siguiente casilla, si esta libre realiza la
insercion, sino visita la siguiente hasta encontrar un espacio vacio.

            Exploracion cuadratica: visita la casilla i^2 mas allá de la que
causó la iesima colision. si esta libre inserta, sino repite el proceso hasta
encontrar una libre.

            Encadenamiento enlazado: se mantiene la lista simplemente enlazada
en la que se van insertando los elementos cuyo valor Hash les asigna la misma
posicion.



        Funcion Hash:
            Si x es un int: hash(x) = |x| % L, done L = longitud del arreglo - 1

            Si x es una string: hash(x) = Valor ASCII % L, done L = longitud del
arreglo - 1

*/
