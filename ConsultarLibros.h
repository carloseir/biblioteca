/*
* @file ConsultarLibros.h
*
* @brief Este programa permite mostrar informacion sobre un libro (almacenado en el
archivo Libros.txt), en base al titulo o autor que nos indique el usuario.
Esta busqueda se hace comparando la informacion que nos dio el usuario, con la base de datos
de libros, previamente almacenada en un arreglo de estructuras llamado DatosLibros
*
* @author Sergio Flores, Carlos Ibarra, Monica Ivette
* @date 02/12/2019
*/

/*
* Esta función pregunta al usuario como buscar los libros, ya sea introduciendo el titulo o autor,
* o mostrar todo el listado de libros disponibles en el archivo de Libros.txt
*
* @author Sergio Flores, Carlos Ibarra, Monica Ivette
* @param Titulo  Cadena de texto con el titulo introducido por el usuario
* @param Autor  Cadena de texto con el autor introducido por el usuario
* @return OpcionConsulta  Parametro para saber como consultar
*/

void PedirLibro (char Titulo[], char Autor[], int *OpcionConsulta)
{
  printf("Usted a seleccionado la opcion de buscar libros\n");
  do
  {
    printf ("\nEscriba un numero para determinar como buscar el libro:\n");
    printf ("1. Titulo\n2. Autor\n3. Mostrar listado completo\n");
    printf ("Opción: ");
    scanf ("%d", OpcionConsulta);
    __fpurge (stdin);
    if (*OpcionConsulta==1)
    {
      __fpurge (stdin);
      printf ("\nEscriba el titulo del libro: ");
      gets (Titulo);
    }
    else
      if (*OpcionConsulta==2)
      {
        __fpurge (stdin);
        printf ("\nEscriba el nombre del autor del libro: ");
        gets (Autor);
      }
      else
        if (*OpcionConsulta==3)
          printf ("Buscando libros...\n\n");
        else
          printf ("Opción invalida\n_______________\n");
  } while(*OpcionConsulta>3 || *OpcionConsulta<1);
}

/*
* Esta función compara el valor que introdujo el usuario (Titulo, Autor), con la
informacion de Libros.txt, que se encuentra almacenada temporalmente en la estructura TipoLibro
*
* @author Sergio Flores, Carlos Ibarra, Monica Ivette
* @param Titulo  Cadena de texto con el titulo introducido por el usuario
* @param Autor  Cadena de texto con el autor introducido por el usuario
* @param OpcionConsulta  Parametro para saber que funcion ejecutar
* @param DatosLibros  Arreglo de estructuras con toda la informacion de Libros.txt
* @param i  Indica el ultimo valor de DatosLibros
* @return void
*/

void CompararLibro (char Titulo[], char Autor[], int OpcionConsulta, TipoLibro DatosLibros[], int i)
{
  int coincidencias=0, x, LibroAdicional, AutorAdicional;

  //Buscar por Titulo del Libro
  if (OpcionConsulta==1)
  {
    printf ("Se encontraron las siguientes coincidencias:\n");
    for (x=0; x<i; x++)
    {
      if (strcmp(DatosLibros[x].Titulo, Titulo) == 0)
      {
        printf ("\n");
        printf ("ID de libro: ");
        printf ("%d\n", DatosLibros[x].IDLibro);

        printf ("ISBN: ");
        puts (DatosLibros[x].ISBN);

        printf ("Titulo: ");
        puts (DatosLibros[x].Titulo);

        printf ("Autor: ");
        puts (DatosLibros[x].AutorPrincipal);

        printf ("Coautor 1: ");
        puts (DatosLibros[x].Coautor1);

        printf ("Coautor 2: ");
        puts (DatosLibros[x].Coautor2);

        printf ("Anio de Publicacion: ");
        puts (DatosLibros[x].AnioPublicacion);

        printf ("Editorial: ");
        puts (DatosLibros[x].Editorial);

        printf ("Comentarios: ");
        puts (DatosLibros[x].Comentario);

        printf ("Estado del libro: ");
        if (DatosLibros[x].Estado == 1)
          printf ("Disponible\n");
        else
          if (DatosLibros[x].Estado ==2)
            printf ("Prestado\n");
          else
            printf ("Dado de baja");
        coincidencias++;
      }
    }
    if (coincidencias==0)
      printf ("\nNo se encontraron coincidencias\n");
  }

  else
    if (OpcionConsulta==2)
    {
      printf ("Se encontraron las siguientes coincidencias:\n");
      for (x=0; x<i; x++)
      {
        if (strcmp(DatosLibros[x].AutorPrincipal, Autor) == 0)
        {
          printf ("\n");
          printf ("ID de libro: ");
          printf ("%d\n", DatosLibros[x].IDLibro);

          //Borrar saltos de linea e imprimir
          printf ("ISBN: ");
          puts (DatosLibros[x].ISBN);

          printf ("Titulo: ");
          puts (DatosLibros[x].Titulo);

          printf ("Autor: ");
          puts (DatosLibros[x].AutorPrincipal);

          printf ("Coautor 1: ");
          puts (DatosLibros[x].Coautor1);

          printf ("Coautor 2: ");
          puts (DatosLibros[x].Coautor2);

          printf ("Anio de Publicacion: ");
          puts (DatosLibros[x].AnioPublicacion);

          printf ("Editorial: ");
          puts (DatosLibros[x].Editorial);

          printf ("Comentarios: ");
          puts (DatosLibros[x].Comentario);

          printf ("Estado del libro: ");
          if (DatosLibros[x].Estado == 1)
            printf ("Disponible\n");
          else
            if (DatosLibros[x].Estado ==2)
              printf ("Prestado\n");
            else
              printf ("Dado de baja");
          coincidencias++;
          printf ("\n");
        }
      }
      if (coincidencias==0)
        printf ("\nNo se encontraron coincidencias\n");
    }

    else
    {
      printf ("Se han encontrado %d libros en la biblioteca:\n", i);
      for (x=0; x<i; x++)
      {
            printf ("\n");
            printf ("ID de libro: ");
            printf ("%d\n", DatosLibros[x].IDLibro);

            //Borrar saltos de linea e imprimir
            printf ("ISBN: ");
            puts (DatosLibros[x].ISBN);

            printf ("Titulo: ");
            puts (DatosLibros[x].Titulo);

            printf ("Autor: ");
            puts (DatosLibros[x].AutorPrincipal);

            printf ("Coautor 1: ");
            puts (DatosLibros[x].Coautor1);

            printf ("Coautor 2: ");
            puts (DatosLibros[x].Coautor2);

            printf ("Anio de Publicacion: ");
            puts (DatosLibros[x].AnioPublicacion);

            printf ("Editorial: ");
            puts (DatosLibros[x].Editorial);

            printf ("Comentarios: ");
            puts (DatosLibros[x].Comentario);

            printf ("Estado del libro: ");
            if (DatosLibros[x].Estado == 1)
              printf ("Disponible\n");
            else
              if (DatosLibros[x].Estado ==2)
                printf ("Prestado\n");
              else
                printf ("Dado de baja");
            printf ("\n");
      }
    }
  }
