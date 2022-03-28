#include <stdio.h>
#include <string.h>
#include <time.h>

//Estructuras
//Libros
typedef struct def_Libro
{
  int IDLibro;
  char ISBN[15];
  char Titulo[100];
  char AutorPrincipal[60];
  char Coautor1[60];
  char Coautor2[60];
  char AnioPublicacion[20];
  char Editorial[60];
  char Comentario[250];
  int Estado;
}TipoLibro;

//usuarios
typedef struct def_Usuario
{
  int IDUsuario;
  char Contrasenia[50];
  char Nombre[50];
  char ApellidoPaterno[50];
  char ApellidoMaterno[50];
  int DevolucionesTardias;
  int Estado;
  int LibrosPrestados;
}TipoUsuario;

//Prestamos
typedef struct def_Prestamo
{
  int IDUsuario;
  int IDLibro;
  char FechaPrestamo[50];
  char FechaLimiteDevolucion[50];
  char FechaRealDevolucion[50];
}TipoPrestamo;


/*Funciones multiuso*/
//Modulo 1
void ListaLibros (TipoLibro DatosLibros[], int *i)
{
  int x=0;
  FILE *Archivo;
  Archivo= fopen ("Libros.txt", "rt");
  while (!feof(Archivo))
  {
    if( fscanf (Archivo, "%d\n", &DatosLibros[x].IDLibro) == 1)
    {
      fgets (DatosLibros[x].ISBN, 15, Archivo);
      fgets (DatosLibros[x].Titulo, 100, Archivo);
      fgets (DatosLibros[x].AutorPrincipal, 60, Archivo);
      fgets (DatosLibros[x].Coautor1, 60, Archivo);
      fgets (DatosLibros[x].Coautor2, 60, Archivo);
      fgets (DatosLibros[x].AnioPublicacion, 20, Archivo);
      fgets (DatosLibros[x].Editorial, 60, Archivo);
      fgets (DatosLibros[x].Comentario, 250, Archivo);
      fscanf (Archivo, "%d\n", &DatosLibros[x].Estado);

      DatosLibros[x].AutorPrincipal[strlen (DatosLibros[x].AutorPrincipal)-1]='\0';
      DatosLibros[x].ISBN[strlen (DatosLibros[x].ISBN)-1]= '\0';
      DatosLibros[x].Titulo[strlen (DatosLibros[x].Titulo)-1]='\0';
      DatosLibros[x].Coautor1[strlen (DatosLibros[x].Coautor1)-1]='\0';
      DatosLibros[x].Coautor2[strlen (DatosLibros[x].Coautor2)-1]='\0';
      DatosLibros[x].AnioPublicacion[strlen (DatosLibros[x].AnioPublicacion)-1]='\0';
      DatosLibros[x].Editorial[strlen (DatosLibros[x].Editorial)-1]='\0';
      DatosLibros[x].Comentario[strlen (DatosLibros[x].Comentario)-1]='\0';
    }
    x++;
  }
  *i= x;
}
void GuardarListaLibros (TipoLibro DatosLibros[], int i)
{
  int x=0;
  FILE *Archivo;
  Archivo = fopen("Libros.txt","wt");
  for (x=0; x<i; x++)
  {
    fprintf(Archivo,"%d\n",DatosLibros[x].IDLibro);
    fputs(DatosLibros[x].ISBN, Archivo);
    fputs("\n", Archivo);
    fputs(DatosLibros[x].Titulo, Archivo);
    fputs("\n", Archivo);
    fputs(DatosLibros[x].AutorPrincipal, Archivo);
    fputs("\n", Archivo);
    fputs(DatosLibros[x].Coautor1, Archivo);
    fputs("\n", Archivo);
    fputs(DatosLibros[x].Coautor2, Archivo);
    fputs("\n", Archivo);
    fputs(DatosLibros[x].AnioPublicacion, Archivo);
    fputs("\n", Archivo);
    fputs(DatosLibros[x].Editorial, Archivo);
    fputs("\n", Archivo);
    fputs(DatosLibros[x].Comentario, Archivo);
    fputs("\n", Archivo);
    fprintf(Archivo,"%d\n",DatosLibros[x].Estado);
  }
  fclose(Archivo);
}

//Modulo 2
void ListaUsuarios(TipoUsuario DatosUsuarios[], int *o)
{
  int x=0;
  FILE *Archivo;
  Archivo= fopen ("Usuarios.txt", "rt");
  while (!feof(Archivo))
    {
      if( fscanf (Archivo, "%d\n", &DatosUsuarios[x].IDUsuario) == 1)
	     {
    	  fgets(DatosUsuarios[x].Contrasenia,50, Archivo);
    	  fgets(DatosUsuarios[x].Nombre,50, Archivo);
    	  fgets(DatosUsuarios[x].ApellidoPaterno,50, Archivo);
    	  fgets(DatosUsuarios[x].ApellidoMaterno, 50, Archivo);
    	  fscanf(Archivo,"%d",&DatosUsuarios[x].DevolucionesTardias);
    	  fscanf(Archivo,"%d\n", &DatosUsuarios[x].Estado);
        fscanf(Archivo,"%d\n", &DatosUsuarios[x].LibrosPrestados);

    	  DatosUsuarios[x].ApellidoPaterno[strlen (DatosUsuarios[x].ApellidoPaterno)-1]='\0';
    	  DatosUsuarios[x].Contrasenia[strlen (DatosUsuarios[x].Contrasenia)-1]= 0;
    	  DatosUsuarios[x].Nombre[strlen (DatosUsuarios[x].Nombre)-1]='\0';
    	  DatosUsuarios[x].ApellidoMaterno[strlen (DatosUsuarios[x].ApellidoMaterno)-1]='\0';
	     }
      x++;
    }
  *o = x;
}
void GuardarListaUsuarios (TipoUsuario DatosUsuarios[], int o)
{
  int x=0;
  FILE *Archivo;
  Archivo = fopen("Usuarios.txt","wt");
  for (x=0; x<o; x++)
  {
    fprintf(Archivo,"%d\n",DatosUsuarios[x].IDUsuario);
    fputs(DatosUsuarios[x].Contrasenia, Archivo);
    fputs("\n", Archivo);
    fputs(DatosUsuarios[x].Nombre, Archivo);
    fputs("\n", Archivo);
    fputs(DatosUsuarios[x].ApellidoPaterno, Archivo);
    fputs("\n", Archivo);
    fputs(DatosUsuarios[x].ApellidoMaterno, Archivo);
    fputs("\n", Archivo);
    fprintf(Archivo,"%d\n",DatosUsuarios[x].DevolucionesTardias);
    fprintf(Archivo,"%d\n",DatosUsuarios[x].Estado);
    fprintf(Archivo,"%d\n",DatosUsuarios[x].LibrosPrestados);
  }
  fclose(Archivo);
}

/*Modulo 1
Fuciones externas*/
//Funciones con archivos
void ListaLibros (TipoLibro DatosLibros[], int *i);
void GuardarListaLibros (TipoLibro DatosLibros[], int i);
//Agregar libros
#include "AgregarLibros.h"
void PedirDatosLibro(TipoLibro DatosLibros[], int *ia);
void GuardarLibro (TipoLibro DatosLibros[], int *ia);

//Consultar libros
#include "ConsultarLibros.h"
void PedirLibro (char Titulo[], char Autor[], int *OpcionConsulta);
void CompararLibro (char Titulo[], char Autor[], int OpcionConsulta, TipoLibro DatosLibros[100], int i);

//Modificar Libros
#include "ModificarLibros.h"
void OpcionModificar (int *OpcionModificar1);
void BuscarPorTitulo (TipoLibro DatosLibros[], int i, int Posicion[], int *Coincidencias, int CoincidenciasID[]);
void BuscarPorAutor (TipoLibro DatosLibros[], int i, int Posicion[], int *Coincidencias, int CoincidenciasID[]);
void IdentificarLibro (TipoLibro DatosLibros[], int i, int Posicion[], int Coincidencias, int CoincidenciasID[], int *y);
void ModificarLibro (TipoLibro DatosLibros[], int Posicion[], int Coincidencias, int y);
//Bajas Libros
#include "BajasLibros.h"
void OpcionBajas (int *OpcionBajas1);
void BuscarPorTitulo2 (TipoLibro DatosLibros[], int i, int Posicion[], int *Coincidencias, int CoincidenciasID[]);
void BuscarPorAutor2 (TipoLibro DatosLibros[], int i, int Posicion[], int *Coincidencias, int CoincidenciasID[]);
void IdentificarLibro2 (TipoLibro DatosLibros[], int i, int Posicion[], int Coincidencias, int CoincidenciasID[], int *y);
void BajaLibro (TipoLibro DatosLibros[], int Posicion[], int Coincidencias, int y);
//-------------------------
/*Modulo 2
Fuciones externas*/
//Funciones con archivos
void ListaUsuarios(TipoUsuario DatosUsuarios[], int *o);
void GuardarListaUsuarios (TipoUsuario DatosUsuarios[], int o);
//Agregar Usuarios
#include "AgregarUsuarios.h"
void PedirDatosUsuarios(TipoUsuario DatosUsuarios[], int *iu);
void GuardarUsuario(TipoUsuario DatosUsuarios[], int *iu);
//Consultar Usuarios
#include "ConsultarUsuarios.h"
void PedirUsuarios(char ApellidoTemp[], int *Opcion);
void CompararUsuarios(char ApellidoTemp[], int Opcion, TipoUsuario DatosUsuarios[], int o);
//Modificar Usuarios
#include "ModificarUsuarios.h"
void BuscarPorApellido(TipoUsuario DatosUsuarios[], int o, int PosicionUsuarios[], int *CoincidenciasUsuarios, int CoincidenciasIDUsuarios[]);
void IdentificarUsuario(TipoUsuario DatosUsuarios[], int o, int PosicionUsuarios[], int CoincidenciasUsuarios, int CoincidenciasIDUsuarios[], int *y1);
void ModificarUsuario(TipoUsuario DatosUsuarios[], int PosicionUsuarios[], int CoincidenciasUsuarios, int y1);
//Bajas usuarios
#include "BajaUsuarios.h"
void OpcionModificarUsuarios1 (int *OpcionModificarUsuarios2);
void MostrarListaUsuarios1(TipoUsuario DatosUsuarios[], int o);
void BuscarPorApellido1(TipoUsuario DatosUsuarios[], int o, int PosicionUsuarios[], int *CoincidenciasUsuarios, int CoincidenciasIDUsuarios[]);
void IdentificarUsuario1(TipoUsuario DatosUsuarios[], int o, int PosicionUsuarios[], int CoincidenciasUsuarios, int CoincidenciasIDUsuarios[], int *y1);
void BajaUsuario(TipoUsuario DatosUsuarios[], int PosicionUsuarios[], int CoincidenciasUsuarios, int y1);
//-------------------------

/*Modulo 3*/

#include "OtorgarPrestamo.h"
void PedirDatosPrestamo(TipoPrestamo DatosPrestamo[], int *ip);
void GuardarDatosPrestamo(TipoPrestamo DatosPrestamo[], int *ip);
void OtorgarPrestamo(TipoPrestamo DatosPrestamo[],int ip,TipoUsuario DatosUsuarios[],int o,TipoLibro DatosLibros[],int i);
//-------------------------

//Argumentos
#include "Argumentos.h"
void ListaCompletaLibros (TipoLibro DatosLibros[], int i);
void ListaCompletaUsuarios (TipoUsuario DatosUsuarios[], int o);
void Ayuda ();
//Main
///////////////////////////////////////////////////////////////////////////////
int main (int argc, char *argv[])
{
  //Variables Biblos.c
  char Inicio[1];
  int Menu=0, Submenu1=0, Submenu2=0, Submenu3=0;
  char Argumento[50], FechaHoy[50];
  /*Variables modulo 1*/
  //Estrurtura libros
  TipoLibro DatosLibros[100];
  int i=0;
  //AgregarLibros.h
  int RepetirModulo1, ia=0;
  //ConsultarLibros.h-
  char Titulo[100], Autor [100];
  int OpcionConsulta=0;
  //ModificarLibros.h &BajasLibros.h
  int Posicion[100], Coincidencias, CoincidenciasID[100];
  int y, OpcionModificar1, OpcionBajas1;

  /*Variables modulo 2*/
  //Estructura Usuarios
  TipoUsuario DatosUsuarios[150];
  int o=0;
  //AgregarUsuarios.h
  int repetir, iu=0;
  //ConsultarUsuarios.h
  char ApellidoTemp[100];
  int Opcion=0;
  //ModificarUsuarios.h
  int OpcionModificarUsuarios1=0, OpcionModificarUsuarios2=0, CoincidenciasUsuarios=0, y1=0;
  int PosicionUsuarios[100], CoincidenciasIDUsuarios[100];

  /*Variables modulo 3*/
  //Estrurtura
  TipoPrestamo DatosPrestamo[150];
  //OtorgarPrestamo.h
  int u=0;
  int ip=0;
  int RepetirOtorgarPrestamo,Confirmar;

////////////////////////////////////////////
//Argumentos
  if (argc ==2)
  {
    strcpy (Argumento, argv[1]);
    if (strcmp (Argumento, "-lc") == 0)
    {
      ListaLibros (DatosLibros, &i);
      ListaCompletaLibros (DatosLibros, i);
    }
    else
    {
      if (strcmp (Argumento, "-lu") == 0)
      {
        ListaUsuarios(DatosUsuarios, &o);
        ListaCompletaUsuarios (DatosUsuarios, o);
      }
      else
      {
        if (strcmp (Argumento, "-h")==0)
          Ayuda();
        /*else
        {
          if (strcmp (Argumento, "-lp") == 0)
          {
            ListaPrestamos(DatosPrestamos, &u);
            ListaUsuarios(DatosUsuarios, &o);
            ListaLibros (DatosLibros, &i);
            ListaCompletaPrestamos (DatosPrestamos, DatosUsuarios, DatosLibros, i, o, u);
          }
          else
          {
            if (strcmp (Argumento, "-ldh") == 0)
            {
              ListaPrestamos(DatosPrestamos, &u);
              ListaUsuarios(DatosUsuarios, &o);
              ListaLibros (DatosLibros, &i);
              ListaCompletaDevoluciones (DatosPrestamos, DatosUsuarios, DatosLibros, i, o, u);
            }
            else
            {
              if (strcmp (Argumento, "-f") == 0)
              {
                strcpy (FechaHoy, argv[2]);
                puts (Argumento);
              }
            }
          }
        }*/
      }
    }
  }
  else
  {
    printf ("\n\nFUNDAMENTOS DE PROGRAMACION Y LAB.\n\n");
    printf ("SISTEMA DE GESTION BIBLIOTECARIA\nProyecto Final\n\n");
    printf ("Autores: \nFlores Fernandez Sergio Javier\nIbarra Rodriguez Carlos Emilio \nVergara Mendoza Monica Ivette\n");
    printf ("\nPresione enter para continuar....");
    gets (Inicio);
    do
    {
      Submenu1=0;
      Submenu2=0;
      printf ("\nSeleccione una opcion:\n");
      printf ("1. Administracion del catalogo de libros.\n");
      printf ("2. Administracion de usuarios.\n");
      printf ("3. Administracion de prestamos.\n");
      printf ("4. Salir del programa.\n");
      printf ("\nOpcion: ");
      scanf ("%d", &Menu);
      switch (Menu)
      {
        case 1://Administracion del catalogo de libros
          printf ("\nElige una opcion: \n");
          printf ("1. Añadir Libros.\n");
          printf ("2. Consultar Libros.\n");
          printf ("3. Modificar Libros.\n");
          printf ("4. Dar de baja Libros.\n");
          printf ("5. Regresar.\n");
          printf ("\nOpcion: ");
          scanf ("%d", &Submenu1);

          switch (Submenu1)
          {
            case 1:
              do
              {
                PedirDatosLibro(DatosLibros, &ia);
                GuardarLibro (DatosLibros, &ia);
                ia++;
                printf("\n¿Desea registrar otro libro? 1=SI 2=NO ");
                scanf("%d",&RepetirModulo1);
              } while(RepetirModulo1== 1 && ia<100);
              printf("\nCambios guardados\n");
            break;

            case 2:
              ListaLibros (DatosLibros, &i);
              do
              {
                PedirLibro (Titulo, Autor, &OpcionConsulta);
                CompararLibro (Titulo, Autor, OpcionConsulta, DatosLibros, i);
                printf("\n¿Desea consultar otro libro? 1=SI 2=NO ");
                scanf("%d",&RepetirModulo1);
              } while(RepetirModulo1== 1);
              printf("\nFin de la cosulta\n");
            break;

            case 3:
              ListaLibros (DatosLibros, &i);
              do
              {
                OpcionModificar (&OpcionModificar1);
                if (OpcionModificar1==1)
                {
                  BuscarPorTitulo (DatosLibros, i, Posicion, &Coincidencias, CoincidenciasID);
                }
                else
                  if (OpcionModificar1==2)
                  {
                    BuscarPorAutor (DatosLibros, i, Posicion, &Coincidencias, CoincidenciasID);
                  }
                if (Coincidencias != 0)
                {
                  IdentificarLibro (DatosLibros, i, Posicion, Coincidencias, CoincidenciasID, &y);
                  ModificarLibro (DatosLibros, Posicion, Coincidencias, y);
                }
                else
                printf ("No se encontro el libro a modificar\n");
                printf("\n¿Desea modificar otro libro? 1=SI 2=NO ");
                scanf("%d",&RepetirModulo1);
              } while(RepetirModulo1== 1);
            GuardarListaLibros (DatosLibros, i);
            printf("\nCambios guardados\n");
            break;

            case 4:
              ListaLibros (DatosLibros, &i);
              do
              {
                OpcionBajas (&OpcionBajas1);
                if (OpcionBajas1==1)
                {
                  BuscarPorTitulo2 (DatosLibros, i, Posicion, &Coincidencias, CoincidenciasID);
                }
                else
                  if (OpcionBajas1==2)
                  {
                    BuscarPorAutor2 (DatosLibros, i, Posicion, &Coincidencias, CoincidenciasID);
                  }
                if (Coincidencias != 0)
                {
                  IdentificarLibro2 (DatosLibros, i, Posicion, Coincidencias, CoincidenciasID, &y);
                  BajaLibro (DatosLibros, Posicion, Coincidencias, y);
                }
                else
                printf ("No se encontro el libro a modificar\n");
                printf("\n¿Desea dar de baja otro libro? 1=SI 2=NO ");
                scanf("%d",&RepetirModulo1);
              } while(RepetirModulo1== 1);
            GuardarListaLibros (DatosLibros, i);
            printf("\nCambios guardados\n");
            break;
            case 5:
            break;
          default:
            printf ("\nBoton equivocado\n");
          break;
          }
          break;
          //Fin del Modulo 1

          case 2://Administracion de usuarios
          printf ("\nElige una opcion: \n");
          printf ("1. Añadir Usuarios.\n");
          printf ("2. Consultar Usuario.\n");
          printf ("3. Modificar Usuarios.\n");
          printf ("4. Dar de baja Usuarios.\n");
          printf ("5. Regresar.\n");
          printf ("\nOpcion: ");
          scanf ("%d", &Submenu2);

          switch (Submenu2)
          {

            case 1:
              do
              {
                PedirDatosUsuarios(DatosUsuarios, &iu);
                GuardarUsuario(DatosUsuarios, &iu);
                iu++;
                printf("\n¿Desea registrar otro usuario? \n[SI],Oprima 1 \n[NO],Oprima 2.\nRespuesta: ");
                scanf("%d",&repetir);
              } while(repetir== 1 && iu<150);
            break;

            case 2:
              ListaUsuarios(DatosUsuarios, &o);
              do
              {
                PedirUsuarios(ApellidoTemp,&Opcion);
                CompararUsuarios(ApellidoTemp, Opcion, DatosUsuarios, o);
                printf("\n¿Desea seguir consultando? \n[SI] Oprima 1. \n[NO] Oprima 2.\nRespuesta: ");
                scanf("%d",&repetir);
              } while(repetir== 1 && o<150);
            break;

            case 3:
            ListaUsuarios(DatosUsuarios, &o);
            do
            {
              BuscarPorApellido(DatosUsuarios, o, PosicionUsuarios, &CoincidenciasUsuarios, CoincidenciasIDUsuarios);
              if (CoincidenciasUsuarios != 0)
              {
                IdentificarUsuario(DatosUsuarios, o, PosicionUsuarios, CoincidenciasUsuarios, CoincidenciasIDUsuarios, &y1);
                ModificarUsuario(DatosUsuarios, PosicionUsuarios, CoincidenciasUsuarios, y1);
              }
              else
                printf ("No hay coincidencias\n");
            printf("\n¿Desea modificar otro Usuario? \n[SI] Oprima 1. \n[NO] Oprima 2.\n Respuesta: ");
            scanf("%d",&repetir);
            } while(repetir == 1);
            GuardarListaUsuarios (DatosUsuarios, o);
            printf("\nCambios guardados\n");
            break;

            case 4:
            ListaUsuarios(DatosUsuarios, &o);
            do
            {
              BuscarPorApellido1(DatosUsuarios, o, PosicionUsuarios, &CoincidenciasUsuarios, CoincidenciasIDUsuarios);
              if (CoincidenciasUsuarios != 0)
              {
                IdentificarUsuario1(DatosUsuarios, o, PosicionUsuarios, CoincidenciasUsuarios, CoincidenciasIDUsuarios, &y1);
                BajaUsuario(DatosUsuarios, PosicionUsuarios, CoincidenciasUsuarios, y1);
              }
              else
                printf ("No hay coincidencias\n");
              printf("\n¿Desea dar de baja otro usuario? \n[SI] Oprima 1. \n[NO] Oprima 2.\nRespuesta: ");
              scanf("%d",&repetir);
            } while(repetir == 1);
            GuardarListaUsuarios (DatosUsuarios, o);
            printf("\nCambios guardados\n");
            break;
            case 5:
            break;
          default:
            printf ("\nBoton equivocado\n");
          break;
          }
          break;
          //Fin del Modulo 2

          case 3://Administracion de Prestamos
          printf ("\nElige una opcion: \n");
          printf ("1. Otorgar Prestamo.\n");
          printf ("2. Devolucion de libro.\n");
          printf ("3. Consulta.\n");
          printf ("\nOpcion: ");
          scanf ("%d", &Submenu3);

          switch (Submenu3)
          {
            case 1:
            /*Funciones externas*/
            ListaLibros(DatosLibros,&i);
            ListaUsuarios(DatosUsuarios,&o);
            do
            {
              printf ("Hola");
              PedirDatosPrestamo(DatosPrestamo,&ip);
              OtorgarPrestamo(DatosPrestamo,ip,DatosUsuarios,o,DatosLibros,i);
              ip++;
              printf("\n¿Desea registrar otro prestamo? \n[SI],Oprima 1\t[NO],Oprima 2 \n Opcion seleccionada: ");
              scanf("%d",&RepetirOtorgarPrestamo);
            } while(RepetirOtorgarPrestamo== 1 && ip<150);
            GuardarListaUsuarios(DatosUsuarios,o);
            GuardarListaLibros(DatosLibros,i);
            GuardarDatosPrestamo(DatosPrestamo,&ip);
            printf("\nCambios guardados\n");
            break;
            case 5:
            break;
          default:
            printf ("\nBoton equivocado\n");
          break;
          }
          break;
          //Fin del Modulo 3

          break;

        default:
        break;
      }
    } while (Menu !=4 || Submenu1 ==5 || Submenu2==5);
  }
}
