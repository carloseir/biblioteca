/*
* @file ModificarLibros.h
*
* @brief Este programa permite mostrar informacion sobre un libro (almacenado en el
archivo Libros.txt), para posteriormente modificar el contenido de algun campo, tomando en
cuenta que el libro no puede estar prestado o dado de baja.
*
* @author Sergio Flores, Carlos Ibarra, Monica Ivette
* @date 02/12/2019
*/

/*
* Esta función pregunta al usuario como buscar los libros, ya sea introduciendo el titulo o autor,
* o mostrar todo el listado de libros disponibles en el archivo de Libros.txt.
*
* @author Sergio Flores, Carlos Ibarra, Monica Ivette
* @param OpcionModificar  Valor que indica la forma de buscar el libro
* @return int
*/

void OpcionModificar (int *OpcionModificar1)
{
  printf("Usted a seleccionado la opcion de modificar libros\n");
  do
  {
    __fpurge (stdin);
    printf ("\nEscriba un numero para determinar como buscar el libro a modificar:\n");
    printf ("1. Titulo\n2. Autor\n");
    printf ("Opción: ");
    scanf ("%d", OpcionModificar1);
    if (*OpcionModificar1>3 || *OpcionModificar1<1)
      printf ("Opción invalida\n_______________\n");
  } while(*OpcionModificar1>3 || *OpcionModificar1<1);
}

/*
* Esta función pide el titulo del libro a buscar, posteriormente empieza a comparar
con todos los titulos de la estructura de arreglos LibrosDatos, cuando encuentra
una coincidencia, guarda el Identificar de ese libro, posicion en el arreglo y aumenta
unitariamente el valor de la variable de coincidencias de libros.
*
* @author Sergio Flores, Carlos Ibarra, Monica Ivette
* @param DatosLibros  Arreglo de estructuras con todos la informacion de Libros.txt
* @param i  Posicion del ultimo valor de DatosLibros
* @param Posicion Arreglo con las posiciones de los libros que coinciden con la busqueda
* @param Coincidencias  Numero de libros encontrados
* @param CoincidenciasID  ID de los libros encontrados
* @return int
*/

void BuscarPorTitulo (TipoLibro DatosLibros[], int i, int Posicion[], int *Coincidencias, int CoincidenciasID[])
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
      CoincidenciasID[Coincidencias1]= DatosLibros[x].IDLibro;

      //Posicion d e los libros, devuelve enteros
      Posicion[Coincidencias1]=x;

      //Saber numero de coincidencias de la busqueda
      Coincidencias1++;
    }
  }
  *Coincidencias = Coincidencias1;
}

/*
* Esta función pide el autor del libro a buscar, posteriormente empieza a comparar
con todos los autores que se ecnuentren en la  estructura de arreglos LibrosDatos, cuando encuentra
una coincidencia, guarda el Identificar de ese libro, posicion en el arreglo y aumenta
unitariamente el valor de la variable de coincidencias de libros.
*
* @author Sergio Flores, Carlos Ibarra, Monica Ivette
* @param DatosLibros  Arreglo de estructuras con todos la informacion de Libros.txt
* @param i  Posicion del ultimo valor de DatosLibros
* @param Posicion Arreglo con las posiciones de los libros que coinciden con la busqueda
* @param Coincidencias  Numero de libros encontrados
* @param CoincidenciasID  ID de los libros encontrados
* @return int
*/

void BuscarPorAutor (TipoLibro DatosLibros[], int i, int Posicion[], int *Coincidencias, int CoincidenciasID[])
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
* Esta función ayuda a identificar la posicion exacta del libro a modificar, cuando
hay mas de una coincidencia en la busqueda, muestra los datos de todos los libros con
parametros de busqueda validos y pide al usuario que ingrese el Identificador del libro correcto
*
* @author Sergio Flores, Carlos Ibarra, Monica Ivette
* @param DatosLibros  Arreglo de estructuras con todos la informacion de Libros.txt
* @param i  Posicion del ultimo valor de DatosLibros
* @param Posicion Arreglo con las posiciones de los libros que coinciden con la busqueda
* @param Coincidencias  Numero de libros encontrados
* @param CoincidenciasID  ID de los libros encontrados
* @param y  Posicion del libro en la variable Posicion[]
* @return int
*/

void IdentificarLibro (TipoLibro DatosLibros[], int i, int Posicion[], int Coincidencias, int CoincidenciasID[], int *y)
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
* Esta función ayuda a identificar la posicion exacta del libro a modificar, cuando
hay mas de una coincidencia en la busqueda, muestra los datos de todos los libros con
parametros de busqueda validos y pide al usuario que ingrese el Identificador del libro correcto
*
* @author Sergio Flores, Carlos Ibarra, Monica Ivette
* @param DatosLibros  Arreglo de estructuras con todos la informacion de Libros.txt
* @param i  Posicion del ultimo valor de DatosLibros
* @param Posicion Arreglo con las posiciones de los libros que coinciden con la busqueda
* @param Coincidencias  Numero de libros encontrados
* @param CoincidenciasID  ID de los libros encontrados
* @param y  Posicion del libro en la variable Posicion[]
* @return int
*/

void ModificarLibro (TipoLibro DatosLibros[], int Posicion[], int Coincidencias,  int y)
{
  int DatoModificar, Confirmar;
  //Nuevos valores a guardar
  char ISBNTemp[15];
  char TituloTemp[100];
  char AutorPrincipalTemp[60];
  char Coautor1Temp[60];
  char Coautor2Temp[60];
  char AnioPublicacionTemp[20];
  char EditorialTemp[60];
  char ComentarioTemp[250];
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
    //Pedir dato nuevo
    printf ("\n\n¿Que dato desea modificar: \n");
    printf ("1. ISBN\n2. Titulo\n3. Autor Principal\n4. Coautor1\n5. Coautor2\n6. Anio de Publicacion\n7. Editorial\n8. Comentarios \n9.Salir\n");
    printf ("Numero de Opcion: ");
    __fpurge (stdin);
    scanf ("%d", &DatoModificar);
    //Editar cada campo en especifico
    Confirmar=0;
    switch (DatoModificar)
    {
      case 1:
        do
        {
          printf ("\nEscriba el nuevo ISBN: ");
          __fpurge (stdin);
          gets (ISBNTemp);
          printf ("\nValor antiguo: ");
          puts (DatosLibros[Posicion[y]].ISBN);
          printf ("Nuevo Valor: ");
          puts (ISBNTemp);
          printf ("\n¿Confirmar accion?\n1. Si \n2. Volver a modificar\n");
          printf ("Opcion: ");
          __fpurge (stdin);
          scanf ("%d", &Confirmar);
        } while (Confirmar != 1);
        strcpy(DatosLibros[Posicion[y]].ISBN, ISBNTemp);
      break;

      case 2:
        do
        {
          printf ("\nEscriba el nuevo Titulo: ");
          __fpurge (stdin);
          gets (TituloTemp);
          printf ("\nValor antiguo: ");
          puts (DatosLibros[Posicion[y]].Titulo);
          printf ("Nuevo Valor: ");
          puts (TituloTemp);
          printf ("\n¿Confirmar accion?\n1. Si \n2. Volver a modificar\n");
          printf ("Opcion: ");
          __fpurge (stdin);
          scanf ("%d", &Confirmar);
        } while (Confirmar != 1);
        strcpy(DatosLibros[Posicion[y]].Titulo, TituloTemp);
      break;

      case 3:
        do
        {
          printf ("\nEscriba el nuevo Autor Principal: ");
          __fpurge (stdin);
          gets (AutorPrincipalTemp);
          printf ("\nValor antiguo: ");
          puts (DatosLibros[Posicion[y]].AutorPrincipal);
          printf ("Nuevo Valor: ");
          puts (AutorPrincipalTemp);
          printf ("\n¿Confirmar accion?\n1. Si \n2. Volver a modificar\n");
          printf ("Opcion: ");
          __fpurge (stdin);
          scanf ("%d", &Confirmar);
        } while (Confirmar != 1);
        strcpy(DatosLibros[Posicion[y]].AutorPrincipal, AutorPrincipalTemp);
      break;

      case 4:
        do
        {
          printf ("\nEscriba el nuevo Coautor 1: ");
          __fpurge (stdin);
          gets (Coautor1Temp);
          printf ("\nValor antiguo: ");
          puts (DatosLibros[Posicion[y]].Coautor1);
          printf ("Nuevo Valor: ");
          puts (Coautor1Temp);
          printf ("\n¿Confirmar accion?\n1. Si \n2. Volver a modificar\n");
          printf ("Opcion: ");
          __fpurge (stdin);
          scanf ("%d", &Confirmar);
        } while (Confirmar != 1);
        strcpy(DatosLibros[Posicion[y]].Coautor1, Coautor1Temp);
      break;

      case 5:
        do
        {
          printf ("\nEscriba el nuevo Coautor 2: ");
          __fpurge (stdin);
          gets (Coautor2Temp);
          printf ("\nValor antiguo: ");
          puts (DatosLibros[Posicion[y]].Coautor2);
          printf ("Nuevo Valor: ");
          puts (Coautor2Temp);
          printf ("\n¿Confirmar accion?\n1. Si \n2. Volver a modificar\n");
          printf ("Opcion: ");
          __fpurge (stdin);
          scanf ("%d", &Confirmar);
        } while (Confirmar != 1);
        strcpy(DatosLibros[Posicion[y]].Coautor2, Coautor2Temp);
      break;

      case 6:
        do
        {
          printf ("\nEscriba el nuevo Anio de Publicacion: ");
          __fpurge (stdin);
          gets (AnioPublicacionTemp);
          printf ("\nValor antiguo: ");
          puts (DatosLibros[Posicion[y]].AnioPublicacion);
          printf ("Nuevo Valor: ");
          puts (AnioPublicacionTemp);
          printf ("\n¿Confirmar accion?\n1. Si \n2. Volver a modificar\n");
          printf ("Opcion: ");
          __fpurge (stdin);
          scanf ("%d", &Confirmar);
        } while (Confirmar != 1);
        strcpy(DatosLibros[Posicion[y]].AnioPublicacion, AnioPublicacionTemp);
      break;

      case 7:
        do
        {
          printf ("\nEscriba la nueva Editorial: ");
          __fpurge (stdin);
          gets (EditorialTemp);
          printf ("\nValor antiguo: ");
          puts (DatosLibros[Posicion[y]].Editorial);
          printf ("Nuevo Valor: ");
          puts (EditorialTemp);
          printf ("\n¿Confirmar accion?\n1. Si \n2. Volver a modificar\n");
          printf ("Opcion: ");
          __fpurge (stdin);
          scanf ("%d", &Confirmar);
        } while (Confirmar != 1);
        strcpy(DatosLibros[Posicion[y]].Editorial, EditorialTemp);
      break;

      case 8:
        do
        {
          printf ("\nEscriba el nuevo Comentario: ");
          __fpurge (stdin);
          gets (ComentarioTemp);
          printf ("\nValor antiguo: ");
          puts (DatosLibros[Posicion[y]].Comentario);
          printf ("Nuevo Valor: ");
          puts (ComentarioTemp);
          printf ("\n¿Confirmar accion?\n1. Si \n2. Volver a modificar\n");
          printf ("Opcion: ");
          __fpurge (stdin);
          scanf ("%d", &Confirmar);
        } while (Confirmar != 1);
        strcpy(DatosLibros[Posicion[y]].Comentario, ComentarioTemp);
      break;

      case 9:
        printf ("\nNos vemos\n");
      break;

      default:
        printf ("\nNumero invalido\n");
      break;
    }
  }
  else
    if (DatosLibros[Posicion[y]].Estado == 0 && Coincidencias > 0)
      printf ("\nNo se puede modificar el libro, ya que este esta dado de baja\n");
    else
      if (DatosLibros[Posicion[y]].Estado == 2 && Coincidencias > 0)
        printf ("\nNo se puede modificar el libro, ya que este esta prestado\n");
}
