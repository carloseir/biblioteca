/*
* @file ConsultarUsuarios.h
*
* @brief Este programa permite consultar toda la informacion que se encuentra
* almacenada en el archivo Usuarios.txt), esta informacion puede ser consultada en forma
de listado general o hacer una busqueda especifica, comparando un apellido que es
introducido por el usuario
*
* @author Flores Sergio, Ibarra Carlos, Vergara Monica
* @date 03/12/2019
*/

/*
* Esta función pregunta al usuario el metodo para visualizar usuarios, ya sea mediante
una busqueda especifica, usando un apellido paterno o,mostrar toda la lista de usuarios que existen.
*
* @author Sergio Flores, Carlos Ibarra, Monica Ivette
* @param ApellidoTemp  Cadena de texto con el apellido introducido por el usuario
* @param Opcion   Muestra la opcion de busqueda del usuario
* @return int
*/

void PedirUsuarios(char ApellidoTemp[], int *Opcion)
{
  printf("Usted ha seleccionado la opcion de buscar usuarios.\n");
  do
    {
      printf ("\nEscriba un numero para determinar como buscar el usuario:\n");
      printf ("1. Apellido paterno.\n2. Mostrar listado completo\n");
      printf ("Opción: ");
      scanf ("%d", Opcion);
      __fpurge (stdin);
      if (*Opcion==1)
	     {
    	    __fpurge (stdin);
    	    printf ("\nEscriba el apellido paterno del usuario: ");
    	    gets (ApellidoTemp);
	     }
      else
        if (*Opcion==2)
          printf ("Buscando usuarios...\n\n");
        else
          printf ("Opcion invalida\n\n");
    } while(*Opcion>2 || *Opcion<1);
}

/*
* Esta función compara el apellido que introdujo el usuario, con la
* informacion de Libros.txt, que se encuentra almacenada temporalmente en la estructura TipoLibro,
* posteriormente muestra los resultados de la comparacion.
*
* @author Flores Sergio, Ibarra Carlos, Vergara Monica
* @param ApellidoTemp  Cadena de texto con el apellido introducido por el usuario
* @param Opcion  Indica la forma de visualizar la informacion
* @param DatosUsuarios  Arreglo de estructuras con toda la informacion de Usuarios.txt
* @param o  Valor que indica el numero maximo de valores en el arreglo DatosUsuarios
* @return void
*/

void CompararUsuarios(char ApellidoTemp[], int Opcion, TipoUsuario DatosUsuarios[], int o)
{
  int coincidencias=0, x;

  if (Opcion==1)
    {
      printf ("Se encontraron las siguientes coincidencias:\n");
      for (x=0; x<o; x++)
	     {
         if (strcmp(DatosUsuarios[x].ApellidoPaterno, ApellidoTemp) == 0)
	       {
  	      printf ("\nID del usuario: ");
  	      printf ("%d\n", DatosUsuarios[x].IDUsuario);

  	      printf ("Contrasenia: ");
  	      puts (DatosUsuarios[x].Contrasenia);

  	      printf ("Nombre(s): ");
  	      puts (DatosUsuarios[x].Nombre);

  	      printf ("Apellido paterno: ");
  	      puts (DatosUsuarios[x].ApellidoPaterno);

  	      printf ("Apellido materno: ");
  	      puts (DatosUsuarios[x].ApellidoMaterno);

  	      printf ("Devoluciones tardias: ");
  	      printf("%d\n",DatosUsuarios[x].DevolucionesTardias);

  	      printf ("Estado del usuario: ");
  	      if (DatosUsuarios[x].Estado == 1)
  		      printf ("Disponible.\n");
  	      else
  		      printf ("Dado de baja.\n");

          printf ("Numero de libros prestados: ");
    	    printf ("%d\n", DatosUsuarios[x].LibrosPrestados);

  	      coincidencias++;
  	      printf ("\n");
	       }
	    }
      if (coincidencias==0)
	      printf ("\nNo se encontraron usuarios con este parametro.\n\n");
  }

    else
    {
      printf ("Se han encontrado %d Usuarios en el sistema:\n", o);
      for (x=0; x<o; x++)
	    {
    	  printf ("\n");
    	  printf ("ID del usuario: ");
    	  printf ("%d\n", DatosUsuarios[x].IDUsuario);

    	  printf ("Contrasenia: ");
    	  puts (DatosUsuarios[x].Contrasenia);

    	  printf ("Nombre(s): ");
    	  puts (DatosUsuarios[x].Nombre);

    	  printf ("Apellido paterno: ");
    	  puts (DatosUsuarios[x].ApellidoPaterno);

    	  printf ("Apellido materno: ");
    	  puts (DatosUsuarios[x].ApellidoMaterno);

    	  printf ("Devoluciones tardias: ");
    	  printf("%d\n",DatosUsuarios[x].DevolucionesTardias);

    	  printf ("Estado del usuario: ");
    	  if (DatosUsuarios[x].Estado == 1)
    	    printf ("Disponible.\n");
    	  else
    	    printf ("Dado de baja.\n");

        printf ("Numero de libros prestados: ");
        printf ("%d\n", DatosUsuarios[x].LibrosPrestados);
	     }
     }
}
