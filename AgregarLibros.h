/*
* @file AgregarLibros.h
*
* @brief Este programa permite capturar 8 datos esenciales para poder
* registar un libro fisico, posteriormente se guarda este libro en un archivo de texto,
* agregando automaticamente un Identificador Unico de libro (sacado de Id.txt).
*
* @author Flores Sergio, Ibarra Carlos, Vergara Monica
* @date 02/12/2019
*/

/*
* Esta función pregunta al usuario datos como el ISBN, titulo, autor, etc... de
* algun libro, para almacenarlos temporalmente en una estructura de arreglos.
*
* @author       Flores Sergio, Ibarra Carlos, Monica Vergara
* @param  DatosLibros    Arreglo estatico que almacena hasta 100 datos sobre libros
* @param  ia             Contador que indica el total de libros almacenados en memoria
* @return int
*/

void PedirDatosLibro(TipoLibro DatosLibros[], int *ia)
{
  int coautores;
  __fpurge(stdin);
  printf("\nIngrese los siguientes datos:\n");

  printf("ISBN del libro(12 digitos): ");
  __fpurge(stdin);
  gets(DatosLibros[*ia].ISBN);

  printf("Titulo del Libro: ");
  __fpurge(stdin);
  gets(DatosLibros[*ia].Titulo);
  printf("Autor Principal: ");
  __fpurge(stdin);
  gets(DatosLibros[*ia].AutorPrincipal);

  printf("Indique el numero de coautores del libro (Maximo 2): ");
  scanf("%d",&coautores);
  if(coautores==2)
    {
      printf("Coautor 1: ");
      __fpurge(stdin);
      gets(DatosLibros[*ia].Coautor1);

      printf("Coautor 2: ");
      __fpurge(stdin);
      gets(DatosLibros[*ia].Coautor2);
    }
  else
    if(coautores==1)
      {
        printf("Coautor 1: ");
        __fpurge(stdin);
        gets(DatosLibros[*ia].Coautor1);

        strcpy(DatosLibros[*ia].Coautor2, "-");
      }
    else
      {
        strcpy(DatosLibros[*ia].Coautor1, "-");
        strcpy(DatosLibros[*ia].Coautor2, "-");
      }

    printf("Anio de Publicacion: ");
    __fpurge(stdin);
    gets(DatosLibros[*ia].AnioPublicacion);

    printf("Editorial: ");
    __fpurge(stdin);
    gets(DatosLibros[*ia].Editorial);

    printf("Comentario sobre el estado del libro: ");
    __fpurge(stdin);
    gets(DatosLibros[*ia].Comentario);
    __fpurge(stdin);

    DatosLibros[*ia].Estado=1;
}

/*
* Esta función abre el archivo Id.txt para obtener el id mas reciente, despues
* abre el archivo de Libros.txt para guardar el Identificador mas reciente y
* toda la informacion que introdujo el usuario.
*
* @author Sergio Flores, Carlos Ibarra, Monica Ivette
* @param DatosLibros    Arreglo de estructuras con toda la informacion de Libros.txt
* @param  ia            Contador que indica el total de libros registrados en memoria
* @return int
*/

void GuardarLibro (TipoLibro DatosLibros[], int *ia)
{
  int IDTemp;
  //Obtener ID del libro
  FILE *Archivo1;
  Archivo1 = fopen("Id.txt","rt");
  fscanf (Archivo1, "%d", &IDTemp);
  fclose(Archivo1);
  IDTemp++;

  FILE *Archivo2;
  Archivo2 = fopen("Id.txt","wt");
  fprintf (Archivo2, "%d", IDTemp);
  fclose(Archivo2);

  FILE *Archivo3;
  Archivo3 = fopen("Libros.txt","at");

  fprintf(Archivo3,"%d\n",IDTemp);
  fputs(DatosLibros[*ia].ISBN, Archivo3);
  fputs("\n", Archivo3);
  fputs(DatosLibros[*ia].Titulo, Archivo3);
  fputs("\n", Archivo3);
  fputs(DatosLibros[*ia].AutorPrincipal, Archivo3);
  fputs("\n", Archivo3);
  fputs(DatosLibros[*ia].Coautor1, Archivo3);
  fputs("\n", Archivo3);
  fputs(DatosLibros[*ia].Coautor2, Archivo3);
  fputs("\n", Archivo3);
  fputs(DatosLibros[*ia].AnioPublicacion, Archivo3);
  fputs("\n", Archivo3);
  fputs(DatosLibros[*ia].Editorial, Archivo3);
  fputs("\n", Archivo3);
  fputs(DatosLibros[*ia].Comentario, Archivo3);
  fputs("\n", Archivo3);
  fprintf(Archivo3,"%d\n",DatosLibros[*ia].Estado);

  printf ("\nSe ha asignado el ID %d al libro\n",IDTemp);
  fclose(Archivo3);
}
