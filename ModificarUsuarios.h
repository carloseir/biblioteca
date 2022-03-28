/*
* @file ModificarUsuarios.h
*
* @brief Este programa permite mostrar informacion sobre un usuario (almacenado en el
archivo Usuarios.txt), para posteriormente modificar  alguno de los datos
* que conforman la estructura del Usuario, tomando encuenta que el usuario no puede estar dado de baja.
*
* @author Sergio Flores, Carlos Ibarra, Monica Ivette
* @date 03/12/2019
*/

/*
* Esta funcion pide al usuario un apellido paterno que exista en el sistema,despues, comparara ese valor con
* un arreglo lleno de todos los usuarios de la biblioteca, al encontrar alguna coincidencia, almacena
* el Identificador unico de ese usuario, posicion en el arreglo y numero de libros que son similares, en variables
* locales
*
* @author       Flores Sergio, Ibarra Carlos, Vergara Monica
* @param  DatosUsuarios  Arreglo de estructuras lleno de informacion sobre los usuarios
* @param  o            Variable que indica hasta donde hay datos validos en la estructra DatosUsuarios
* @param  PosicionUsuarios     Arreglo de enteros que indica la posicion de un libro en el arreglo de DatosUsuarios
* @param  CoincidenciasUsuarios Numero de usuarios con apellidos similares
* @param  CoincidenciasIDUsuarios   Arreglo lleno de Identificadores de los usuarios que tienen apellido similar
* @return int
*/

void BuscarPorApellido (TipoUsuario DatosUsuarios[], int o, int PosicionUsuarios[], int *CoincidenciasUsuarios, int CoincidenciasIDUsuarios[])
{
  char ApellidoPaterno[100];
  //DatosLibros de salida
  int Coincidencias1=0, x=0;

  printf ("\nEscriba el Apellido Paterno del usuario: ");
  __fpurge (stdin);
  gets (ApellidoPaterno);

  for (x=0; x<o; x++)
  {
    if (strcmp(DatosUsuarios[x].ApellidoPaterno, ApellidoPaterno) == 0)
    {
      CoincidenciasIDUsuarios[Coincidencias1]= DatosUsuarios[x].IDUsuario;
      PosicionUsuarios[Coincidencias1]=x;
      Coincidencias1++;
    }
  }
  *CoincidenciasUsuarios = Coincidencias1;
}

/*
* Esta funcion recibe la informacion sobre los libros que coincidieron con el parametro de
busqueda que dio el usuario, cuando las coincidencias son de mas de 1 libro, se muestra la
informacion de los libros repetidos y se pregunta al usuario cual es el ID correcto, para poder
modificar ese libro en especifico.
*
* @author       Flores Sergio, Ibarra Carlos, Vergara Monica
* @param  DatosUsuarios  Arreglo estatico con campos referentes a informacion sobre libros
* @param  i            Variable que indica hasta donde hay datos validos en el arreglo
* @param  PosicionUsuarios     Arreglo de enteros que indica la posicion de un libro en el arreglo de DatoslIbros
* @param  CoincidenciasUsuarios Numero de libros con titulos similares
* @param  CoincidenciasIDUsuarios   Arreglo lleno de Identificadores de los libros que coinciden en DatosLibros
* @param  y1             Indica cual de todos los libros en el arreglo de Posicion es el correcto
* @return int
*/

void IdentificarUsuario (TipoUsuario DatosUsuarios[], int o, int PosicionUsuarios[], int CoincidenciasUsuarios, int CoincidenciasIDUsuarios[], int *y1)
{
  int CorroborarID, x=0, IDCorrecto;

  if (CoincidenciasUsuarios== 1)
  {
    *y1=0;
  }
    else
    {
      x=0;
      printf ("Existen %d usuarios con el mismo apellido, escriba el ID correspondiente al usuario correcto:", CoincidenciasUsuarios);
      while (x<CoincidenciasUsuarios)
      {
        printf ("\n");
        printf("ID de  Usuario: %d\n",DatosUsuarios[x].IDUsuario);
        printf ("Contrasenia: ");
        puts(DatosUsuarios[x].Contrasenia);
        printf ("Nombre: ");
        puts(DatosUsuarios[x].Nombre);
        printf ("Apellido Paterno: ");
        puts(DatosUsuarios[x].ApellidoPaterno);
        printf ("Apellido Materno: ");
        puts(DatosUsuarios[x].ApellidoMaterno);
        printf("Devoluciones Tardias: %d\n",DatosUsuarios[x].DevolucionesTardias);
        printf("Estado: ");
        if (DatosUsuarios[x].Estado ==1)
          printf ("Usuario activo");
        else
          printf ("Dado de baja");
        printf("\nLibros prestados: %d\n",DatosUsuarios[x].LibrosPrestados);
        x++;
      }

      CorroborarID=0;
      while (CorroborarID==0)
      {
        printf ("\nEscriba el ID Correcto: ");
        __fpurge (stdin);
        scanf ("%d", &IDCorrecto);
        for (x=0; x<CoincidenciasUsuarios; x++)
        {
          if (IDCorrecto == CoincidenciasIDUsuarios[x])
          {
            *y1=x;
            CorroborarID++;
          }
        }
        if (CorroborarID==0)
          printf ("\nID Invalido\n");
      }
    }
}

/*
* Esta funcion muestra la informacion correcta del usuario, y pregunta al usuario cual de los campos
* quiere modificar (a excepcion de campos asignados por el sistema como devoluciones tardias...)y/o actualizar,
* todo esto mientras el usuario no este dado de baja .
*
* @author       Flores Sergio, Ibarra Carlos, Vergara Monica
* @param  DatosUsuarios  Arreglo estatico con campos referentes a la informacion del archivo Usuarios.txt
* @param  CoincidenciasUsuarios Numero de libros con titulos similares
* @param   Numero de libros con titulos similares
* @param  y1             Indica cual de todos los libros en el arreglo de Posicion es el correcto
* @return void
*/

void ModificarUsuario (TipoUsuario DatosUsuarios[], int PosicionUsuarios[], int CoincidenciasUsuarios,  int y1)
{
  int DatoModificar, Confirmar;
  //Nuevos valores a guardar
  char ContraseniaTemp[50];
  char NombreTemp[50];
  char ApellidoPaternoTemp[50];
  char ApellidoMaternoTemp[50];
  printf ("-----------------");
  printf ("\nUsuario Seleccionado:\n");
  printf("ID de  Usuario: %d\n",DatosUsuarios[PosicionUsuarios[y1]].IDUsuario);
  printf ("Contraseña: ");
  puts(DatosUsuarios[PosicionUsuarios[y1]].Contrasenia);
  printf ("Nombre: ");
  puts(DatosUsuarios[PosicionUsuarios[y1]].Nombre);
  printf ("Apellido Paterno: ");
  puts(DatosUsuarios[PosicionUsuarios[y1]].ApellidoPaterno);
  printf ("Apellido Materno: ");
  puts(DatosUsuarios[PosicionUsuarios[y1]].ApellidoMaterno);
  printf("Devoluciones Tardias: %d\n",DatosUsuarios[PosicionUsuarios[y1]].DevolucionesTardias);
  printf("Estado: ");
  if (DatosUsuarios[PosicionUsuarios[y1]].Estado ==1)
    printf ("Usuario activo");
  else
    printf ("Dado de baja");
  printf("\nLibros prestados: %d\n",DatosUsuarios[PosicionUsuarios[y1]].LibrosPrestados);

  if (DatosUsuarios[PosicionUsuarios[y1]].Estado == 1 && CoincidenciasUsuarios > 0)
  {
    //Pedir dato nuevo
    printf ("\n\n¿Que dato desea modificar: \n");
    printf ("1. Contrasenia\n2. Nombre\n3. Apellido Paterno\n4. Apellido Materno\n5. Salir\n");
    printf ("Opcion: ");
    __fpurge (stdin);
    scanf ("%d", &DatoModificar);
    //Editar cada campo en especifico
    Confirmar=0;
    switch (DatoModificar)
    {
      case 1:
        do
        {
          printf ("\nEscriba la nueva contrasenia: ");
          __fpurge (stdin);
          gets (ContraseniaTemp);
          printf ("\nValor antiguo: ");
          puts (DatosUsuarios[PosicionUsuarios[y1]].Contrasenia);
          printf ("Nuevo Valor: ");
          puts (ContraseniaTemp);
          printf ("\n¿Confirmar accion?\n1. Si \n2. Volver a modificar\n");
          printf ("Opcion: ");
          __fpurge (stdin);
          scanf ("%d", &Confirmar);
        } while (Confirmar != 1);
        strcpy(DatosUsuarios[PosicionUsuarios[y1]].Contrasenia, ContraseniaTemp);
      break;

      case 2:
        do
        {
          printf ("\nEscriba el nuevo Nombre: ");
          __fpurge (stdin);
          gets (NombreTemp);
          printf ("\nValor antiguo: ");
          puts (DatosUsuarios[PosicionUsuarios[y1]].Nombre);
          printf ("Nuevo Valor: ");
          puts (NombreTemp);
          printf ("\n¿Confirmar accion?\n1. Si \n2. Volver a modificar\n");
          printf ("Opcion: ");
          __fpurge (stdin);
          scanf ("%d", &Confirmar);
        } while (Confirmar != 1);
        strcpy(DatosUsuarios[PosicionUsuarios[y1]].Nombre, NombreTemp);
      break;

      case 3:
        do
        {
          printf ("\nEscriba el nuevo Apellido Paterno: ");
          __fpurge (stdin);
          gets (ApellidoPaternoTemp);
          printf ("\nValor antiguo: ");
          puts (DatosUsuarios[PosicionUsuarios[y1]].ApellidoPaterno);
          printf ("Nuevo Valor: ");
          puts (ApellidoPaternoTemp);
          printf ("\n¿Confirmar accion?\n1. Si \n2. Volver a modificar\n");
          printf ("Opcion: ");
          __fpurge (stdin);
          scanf ("%d", &Confirmar);
        } while (Confirmar != 1);
        strcpy(DatosUsuarios[PosicionUsuarios[y1]].ApellidoPaterno, ApellidoPaternoTemp);
      break;

      case 4:
        do
        {
          printf ("\nEscriba el nuevo Apellido Materno: ");
          __fpurge (stdin);
          gets (ApellidoMaternoTemp);
          printf ("\nValor antiguo: ");
          puts (DatosUsuarios[PosicionUsuarios[y1]].ApellidoMaterno);
          printf ("Nuevo Valor: ");
          puts (ApellidoMaternoTemp);
          printf ("\n¿Confirmar accion?\n1. Si \n2. Volver a modificar\n");
          printf ("Opcion: ");
          __fpurge (stdin);
          scanf ("%d", &Confirmar);
        } while (Confirmar != 1);
        strcpy(DatosUsuarios[PosicionUsuarios[y1]].ApellidoMaterno, ApellidoMaternoTemp);
      break;

      case 5:
        printf ("\nNos vemos\n");
      break;

      default:
        printf ("\nNumero invalido\n");
      break;
    }
  }
  else
    if (DatosUsuarios[PosicionUsuarios[y1]].Estado == 0 && CoincidenciasUsuarios > 0)
      printf ("\nNo se puede modificar el usuario, ya que este esta dado de baja\n");
}
