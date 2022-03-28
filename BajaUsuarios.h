/*
* @file BajaUsuarios.h
*
* @brief Este programa obtiene toda la informacion del archivo Usuarios.txt y la almacena
* en un arreglo, posteriormente pide al usuario que indique cual usuario dar de baja, al
* encontrarlo en el arreglo lleno de datos de todos los usuarios,se cambia el estatus de disponible
* a dado de baja.
*
* @author Flores Sergio, Ibarra Carlos, Vergara Monica
* @date 02/12/2019
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

void BuscarPorApellido1 (TipoUsuario DatosUsuarios[], int o, int PosicionUsuarios[], int *CoincidenciasUsuarios, int CoincidenciasIDUsuarios[])
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

void IdentificarUsuario1 (TipoUsuario DatosUsuarios[], int o, int PosicionUsuarios[], int CoincidenciasUsuarios, int CoincidenciasIDUsuarios[], int *y1)
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
        printf ("Contraseña: ");
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
* Esta funcion muestra la informacion correcta del usuario y le pregunta si quiere dar de baja el libro,
* si acepta la accion, el estado del usuario cambia de 1 (disponible) a 0 (dado de baja).
*
* @author       Flores Sergio, Ibarra Carlos, Vergara Monica
* @param  DatosUsuarios  Arreglo estatico con campos referentes a la informacion del archivo Usuarios.txt
* @param  CoincidenciasUsuarios Numero de libros con titulos similares
* @param   Numero de libros con titulos similares
* @param  y1             Indica cual de todos los libros en el arreglo de Posicion es el correcto
* @return void
*/

void BajaUsuario (TipoUsuario DatosUsuarios[], int PosicionUsuarios[], int CoincidenciasUsuarios,  int y1)
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
    printf ("\n¿Confirmar accion?\n1. Si,dar de baja \n2. Cancelar\n");
    printf ("Opcion: ");
    __fpurge (stdin);
    scanf ("%d", &Confirmar);
    if (Confirmar == 1)
    {
      DatosUsuarios[PosicionUsuarios[y1]].Estado = 0;
    }
    else
      printf ("\nAccion cancelada, el usuario no se dio de baja\n");
  }
  else
    if (DatosUsuarios[PosicionUsuarios[y1]].Estado == 0 && CoincidenciasUsuarios > 0)
      printf ("\nEl usuario ya esta dado de baja\n");
}
