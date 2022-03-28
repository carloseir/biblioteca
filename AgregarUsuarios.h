/*
* @file AgregarUsuarios.h
*
* @brief Este programa permite capturar 4 datos basicos sobre un usuario, almacenando
* esa informacion en un archivo junto con un Identificador Unico, y permitir que
* el usuario pueda pedir libros prestados.
*
* @author Flores Sergio, Ibarra Carlos, Vergara Monica
* @date 03/12/2019
*/

/*
* Esta función pregunta al usuario datos personales como nombre, apellidos, para
almacenar esa informacion en una arreglo estatico.
*
* @author       Flores Sergio, Ibarra Carlos, Vergara Monica
* @param  DatosUsuario   Arreglo estatico que almacena hasta 100 datos sobre usuarios
* @param  iu             Contador que indica el total de libros almacenados en memoria
* @return int
*/

void PedirDatosUsuarios(TipoUsuario DatosUsuarios[], int *iu)
{
  __fpurge(stdin);
  printf("\nPor favor, ingrese los siguientes datos:\n");

  printf("Contrasenia: ");
  __fpurge(stdin);
  gets(DatosUsuarios[*iu].Contrasenia);

  printf("Nombre(s): ");
  __fpurge(stdin);
  gets(DatosUsuarios[*iu].Nombre);

  printf("Apelido paterno: ");
  __fpurge(stdin);
  gets(DatosUsuarios[*iu].ApellidoPaterno);

  printf("Apellido materno: ");
  __fpurge(stdin);
  gets(DatosUsuarios[*iu].ApellidoMaterno);
  __fpurge(stdin);

  DatosUsuarios[*iu].DevolucionesTardias=0;
  DatosUsuarios[*iu].Estado=1;
  DatosUsuarios[*iu].LibrosPrestados=0;
}

/*
* Esta función transfiere la informacion que se encuentra en el arreglo estatico, a un
archivo de texto de nombre Usuarios.txt, agregando un Identificador Unico obtenido del
archivo IDLibros.txt.
*
* @author       Flores Sergio, Ibarra Carlos, Vergara Monica
* @param  DatosUsuario   Arreglo estatico que almacena hasta 100 datos sobre usuarios
* @param  iu             Contador que indica el total de libros almacenados en memoria
* @return int
*/

void GuardarUsuario(TipoUsuario DatosUsuarios[], int *iu)
{
  int IDTemp=0;
  FILE *Archivo;
  Archivo = fopen("IdUsuarios.txt","rt");
  fscanf (Archivo, "%d", &IDTemp);
  fclose(Archivo);
  IDTemp++;

  FILE *Archivo2;
  Archivo2 = fopen("IdUsuarios.txt","wt");
  fprintf (Archivo2, "%d", IDTemp);
  fclose(Archivo2);

  FILE *Archivo3;
  Archivo3 = fopen("Usuarios.txt","at");

  fprintf(Archivo3,"%d\n",IDTemp);
  fputs(DatosUsuarios[*iu].Contrasenia, Archivo3);
  fputs("\n", Archivo3);
  fputs(DatosUsuarios[*iu].Nombre, Archivo3);
  fputs("\n", Archivo3);
  fputs(DatosUsuarios[*iu].ApellidoPaterno, Archivo3);
  fputs("\n", Archivo3);
  fputs(DatosUsuarios[*iu].ApellidoMaterno, Archivo3);
  fputs("\n", Archivo3);
  fprintf(Archivo3,"%d\n",DatosUsuarios[*iu].DevolucionesTardias);
  fprintf(Archivo3,"%d\n",DatosUsuarios[*iu].Estado);
  fprintf(Archivo3,"%d\n",DatosUsuarios[*iu].LibrosPrestados);

  printf ("Se ha asignado el ID %d al usuario\n",IDTemp);
  fclose(Archivo3);
}
