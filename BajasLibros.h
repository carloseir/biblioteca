/*
* @file BajasLibros.h
*
* @brief Este programa obtiene toda la informacion del archivo Libros.txt y la almacena
* en un arreglo, posteriormente pide al usuario que busque el libro indicado para dar de baja, al
* encontrarlo se cambia el estatus de disponible a dado de baja.
*
* @author Flores Sergio, Ibarra Carlos, Vergara Monica
* @date 02/12/2019
*/

/*
* Esta funcion pregunta la forma de buscar los datos de algun libro, ya sea titulo o
* autor, solo almacena la opcion, no empieza ningun metodo de busqueda
*
* @author       Flores Sergio, Ibarra Carlos, Vergara Monica
* @param  OpcionBajas1  Define si buscar por Titulo (1) o Autor (2)
* @return int
*/

void OpcionBajas (int *OpcionBajas1)
{
  printf("Usted a seleccionado la opcion de dar baja los libros\n");
  do
  {
    __fpurge (stdin);
    printf ("\nEscriba un numero para determinar como buscar el libro a modificar:\n");
    printf ("1. Titulo\n2. Autor\n");
    printf ("Opción: ");
    scanf ("%d", OpcionBajas1);
    if (*OpcionBajas1>3 || *OpcionBajas1<1)
      printf ("Opción invalida\n_______________\n");
  } while(*OpcionBajas1>3 || *OpcionBajas1<1);
}

/*
* Esta funcion pide al usuario el nombre del titulo del libro, para compararlo con
* un arreglo lleno de todos los libros de la biblioteca, al encontrar alguna coincidencia, almacena
* el Identificador de esa publicacion, posicion en el arreglo y numero de libros que son similares
*
* @author       Flores Sergio, Ibarra Carlos, Vergara Monica
* @param  DatosLibros  Arreglo de estructuras estatico con campos referentes a informacion sobre libros
* @param  i            Variable que indica hasta donde hay datos validos en el arreglo de estructuras
* @param  Posicion     Arreglo de enteros que indica la posicion de un libro en el arreglo de DatoslIbros
* @param  Coincidencias Numero de libros con titulos similares
* @param  CoincidenciasID   Arreglo lleno de Identificadores de los libros que coinciden en DatosLibros
* @return int
*/

void BuscarPorTitulo2 (TipoLibro DatosLibros[], int i, int Posicion[], int *Coincidencias, int CoincidenciasID[])
{
  char Titulo[100];
  //DatosLibros de salida
  int Coincidencias1=0, x=0;

  printf ("\nEscriba el Titulo del Libro: ");
  __fpurge (stdin);
  gets (Titulo);

  for (x=0; x<i; x++)
  {
    if (strcmp(DatosLibros[x].Titulo, Titulo) == 0)
    {
      //Por si se repite un autor, saber los id de cada libro
      CoincidenciasID[Coincidencias1]=DatosLibros[x].IDLibro;

      //Posicion de los libros, devuelve enteros
      Posicion[Coincidencias1]=x;

      //Saber numero de coincidencias de la busqueda
      Coincidencias1++;
    }
  }
  *Coincidencias = Coincidencias1;
}

/*
* Esta funcion pide al usuario el autor del titulo del libro, para compararlo con
* un arreglo lleno de todos los libros de la biblioteca, al encontrar alguna coincidencia, almacena
* el Identificador de esa publicacion, posicion en el arreglo y numero de libros que son similares
*
* @author       Flores Sergio, Ibarra Carlos, Vergara Monica
* @param  DatosLibros  Arreglo estatico con campos referentes a informacion sobre libros
* @param  i            Variable que indica hasta donde hay datos validos en el arreglo
* @param  Posicion     Arreglo de enteros que indica la posicion de un libro en el arreglo de DatoslIbros
* @param  Coincidencias Numero de libros con titulos similares
* @param  CoincidenciasID   Arreglo lleno de Identificadores de los libros que coinciden en DatosLibros
* @return int
*/

void BuscarPorAutor2 (TipoLibro DatosLibros[], int i, int Posicion[], int *Coincidencias, int CoincidenciasID[])
{
  char Autor[100];
  //DatosLibros de salida
  int Coincidencias1=0, x=0;

  printf ("\nEscriba el Autor del libro: ");
  __fpurge (stdin);
  gets (Autor);

  for (x=0; x<i; x++)
  {
    if (strcmp(DatosLibros[x].AutorPrincipal, Autor) == 0)
    {
      //Por si se repite un autor, saber los id de cada libro
      CoincidenciasID[Coincidencias1]= DatosLibros[x].IDLibro;

      //Posicion de los libros, devuelve enteros
      Posicion[Coincidencias1]=x;

      //Saber numero de coincidencias de la busqueda
      Coincidencias1++;
    }
  }
  *Coincidencias = Coincidencias1;
}

/*
* Esta funcion recibe la informacion sobre los libros que coincidieron con el parametro de
busqueda que dio el usuario, cuando las coincidencias son de mas de 1 libro, se muestra la
informacion de los libros repetidos y se pregunta al usuario cual es el ID correcto, para poder
modificar ese libro en especifico.
*
* @author       Flores Sergio, Ibarra Carlos, Vergara Monica
* @param  DatosLibros  Arreglo estatico con campos referentes a informacion sobre libros
* @param  i            Variable que indica hasta donde hay datos validos en el arreglo
* @param  Posicion     Arreglo de enteros que indica la posicion de un libro en el arreglo de DatoslIbros
* @param  Coincidencias Numero de libros con titulos similares
* @param  CoincidenciasID   Arreglo lleno de Identificadores de los libros que coinciden en DatosLibros
* @param  y             Indica cual de todos los libros en el arreglo de Posicion es el correcto
* @return int
*/

void IdentificarLibro2 (TipoLibro DatosLibros[], int i, int Posicion[], int Coincidencias, int CoincidenciasID[], int *y)
{
  //Contadores
  int IDErroneo, x=0;
  int IDCorrecto;

  if (Coincidencias== 1)
  {
    *y=0;
  }
    else
    {
      x=0;
      printf ("Existen %d libros con el mismo titulo, escriba el ID del libro correcto:", Coincidencias);
      while (x<Coincidencias)
      {
        printf ("\n");
        printf ("\nID de libro: ");
        printf ("%d\n", DatosLibros[Posicion[x]].IDLibro);

        printf ("ISBN: ");
        puts (DatosLibros[Posicion[x]].ISBN);

        printf ("Titulo: ");
        puts (DatosLibros[Posicion[x]].Titulo);

        printf ("Autor: ");
        puts (DatosLibros[Posicion[x]].AutorPrincipal);

        printf ("Coautor 1: ");
        puts (DatosLibros[Posicion[x]].Coautor1);

        printf ("Coautor 2: ");
        puts (DatosLibros[Posicion[x]].Coautor2);

        printf ("Anio de Publicacion: ");
        puts (DatosLibros[Posicion[x]].AnioPublicacion);

        printf ("Editorial: ");
        puts (DatosLibros[Posicion[x]].Editorial);

        printf ("Comentarios: ");
        puts (DatosLibros[Posicion[x]].Comentario);

        printf ("Estado del libro: ");
        if (DatosLibros[Posicion[x]].Estado == 1)
          printf ("Disponible\n");
        else
          if (DatosLibros[Posicion[x]].Estado ==2)
            printf ("Prestado\n");
          else
            printf ("Dado de baja");
          x++;
      }
      //Checar si el ID del usuarrio coincide con el que esta guardado
      IDErroneo=0;
      while (IDErroneo==0)
      {
        printf ("\nEscriba el ID Correcto: ");
        __fpurge (stdin);
        scanf ("%d", &IDCorrecto);
        for (x=0; x<Coincidencias; x++)
        {
          if (IDCorrecto == CoincidenciasID[x])
          {
            *y=x;
            IDErroneo++;
          }
        }
        if (IDErroneo==0)
          printf ("\nID Invalido\n");
      }
    }
}

/*
* Esta funcion muestra la informacion del libro que selecciono el usuario y le pregunta si
quiere dar de baja el libro, si acepta la accion, el estado del libro cambia de 1 (disponible) a
0 (dado de baja).
*
* @author       Flores Sergio, Ibarra Carlos, Vergara Monica
* @param  DatosLibros  Arreglo de estructuras estatico lleno de informacion del archivo Libros.txt
* @param  Coincidencias Numero de libros con titulos similares
* @param  y             Indica cual de todos los libros en el arreglo de Posicion es el correcto
* @return void
*/

void BajaLibro (TipoLibro DatosLibros[100], int Posicion[100], int Coincidencias,  int y)
{
  int Confirmar;
  printf ("-----------------\nLibro seleccionado:");
  printf ("\n");
  printf ("\nID de libro: ");
  printf ("%d\n", DatosLibros[Posicion[y]].IDLibro);
  printf ("ISBN: ");
  puts (DatosLibros[Posicion[y]].ISBN);
  printf ("Titulo: ");
  puts (DatosLibros[Posicion[y]].Titulo);
  printf ("Autor: ");
  puts (DatosLibros[Posicion[y]].AutorPrincipal);
  printf ("Coautor 1: ");
  puts (DatosLibros[Posicion[y]].Coautor1);
  printf ("Coautor 2: ");
  puts (DatosLibros[Posicion[y]].Coautor2);
  printf ("Anio de Publicacion: ");
  puts (DatosLibros[Posicion[y]].AnioPublicacion);
  printf ("Editorial: ");
  puts (DatosLibros[Posicion[y]].Editorial);
  printf ("Comentarios: ");
  puts (DatosLibros[Posicion[y]].Comentario);
  printf ("Estado del libro: ");
  if (DatosLibros[Posicion[y]].Estado == 1)
    printf ("Disponible\n");
  else
    if (DatosLibros[Posicion[y]].Estado ==2)
      printf ("Prestado\n");
    else
      printf ("Dado de baja");

  if (DatosLibros[Posicion[y]].Estado == 1 && Coincidencias > 0)
  {
    printf ("\n¿Confirmar accion?\n1. Si,dar de baja \n2. Cancelar\n");
    printf ("Opcion: ");
    __fpurge (stdin);
    scanf ("%d", &Confirmar);
    if (Confirmar == 1)
    {
      DatosLibros[Posicion[y]].Estado = 0;
    }
    else
      printf ("\nNos vemos\n");
  }
  else
    if (DatosLibros[Posicion[y]].Estado == 0 && Coincidencias > 0)
      printf ("\nEl libro ya esta previamente dado de baja\n");
    else
      if (DatosLibros[Posicion[y]].Estado == 2 && Coincidencias > 0)
        printf ("\nNo se puede dar de baja el libro, ya que este esta prestado\n");
}
