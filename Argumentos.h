void ListaCompletaLibros (TipoLibro DatosLibros[], int i)
{
  int x;
  for (x=0; x<i; x++)
  {
    printf ("\n");
    printf ("Autor: ");
    puts (DatosLibros[x].AutorPrincipal);
    printf ("Titulo: ");
    puts (DatosLibros[x].Titulo);
    printf ("Editorial: ");
    puts (DatosLibros[x].Editorial);
  }
}

void ListaCompletaUsuarios (TipoUsuario DatosUsuarios[], int o)
{
  int x;
  for (x=0; x<o; x++)
  {
    printf ("\nApellido paterno: ");
    puts (DatosUsuarios[x].ApellidoPaterno);

    printf ("Apellido materno: ");
    puts (DatosUsuarios[x].ApellidoMaterno);

    printf ("Nombre(s): ");
    puts (DatosUsuarios[x].Nombre);

    printf ("Devoluciones tardias: ");
    printf("%d\n",DatosUsuarios[x].DevolucionesTardias);
  }
}

/*void ListaCompletaPrestamos (DatosPrestamos, DatosUsuarios, DatosLibros, i, o, u)
{
  while (DatosPrestamos[x].IDUsuario != Null)
  {
    //Buscar usuario
    for (y=0; y<o; y++)
    {
      if (strcmp (DatosPrestamos[x].IDUsuario, DatosUsuarios[y].IDUsuario)==0)
      {
        //Buscar libro
        for (z=0; z<o; z++)
        {
          if (strcmp (DatosPrestamos[x].IDLibro, DatosLibros[z].IDLibro)==0)
          {
            printf ("\nTitulo del libro: ");
            puts (DatosLibros[z].Titulo);
            printf ("Autor principal: ");
            puts (DatosLibros[z].AutorPrincipal);
            printf ("Nombre del usuario: ");
            puts (DatosUsuarios[y].Nombre);
            printf ("Apellidos del usuario: ");
            puts (DatosUsuarios[y].ApellidoPaterno);
            puts (DatosUsuarios[y].ApellidoMaterno);
          }
        }
      }
    }
    x++;
  }
}

void ListaCompletaDevoluciones (DatosPrestamos, DatosUsuarios, DatosLibros, i, o, u)
{
  while (DatosPrestamos[x].IDUsuario != Null)
  {
    //Buscar usuario
    for (y=0; y<o; y++)
    {
      if (strcmp (DatosPrestamos[x].IDUsuario, DatosUsuarios[y].IDUsuario)==0)
      {
        //Buscar libro
        for (z=0; z<o; z++)
        {
          if (strcmp (DatosPrestamos[x].IDLibro, DatosLibros[z].IDLibro)==0)
          {
            if (DatosPrestamos[x].FechaLimiteDevolucion == hoy mero)
            {
              printf ("\nTitulo del libro: ");
              puts (DatosLibros[z].Titulo);
              printf ("Autor principal: ");
              puts (DatosLibros[z].AutorPrincipal);
              printf ("Nombre del usuario: ");
              puts (DatosUsuarios[y].Nombre);
              printf ("Apellidos del usuario: ");
              puts (DatosUsuarios[y].ApellidoPaterno);
              puts (DatosUsuarios[y].ApellidoMaterno);
            }
          }
        }
      }
    }
    x++;
  }
}*/


void Ayuda ()
{
  int x=0,y=0;
  do
  {
    x=0;
    printf ("\nMenu de Ayuda");
    printf ("\nElige una opcion para ayudarte:\n ");
    printf ("\n1. ??Que es este programa?");
    printf ("\n2. ??Cuales son las formas de ejecucion adicionales?");
    printf ("\n3. ??Que opciones hay en el programa principal?");
    printf ("\n4. ??Como funciona -Administrar catalogo de libros-?");
    printf ("\n5. ??Como funciona -Administrar usuarios-?");
    printf ("\n6. ??Como funciona -Administrar prestamos-?");
    printf ("\n6. Salir");
    printf ("\nOpcion: ");
    scanf ("%d", &x);
    if (x == 7)
    {
      y=2;
    }
    else
    {
      switch (x)
      {
        case 1:
          printf ("\nEs un sistema de informaci??n que permite administrar digitalmente la informaci??n relacionada con:");
          printf ("\n???	Consulta y modificaci??n del acervo bibliogr??fico (libros)");
          printf ("\n???	Lista de usuarios registrados en el sistema y su historial de prestamos");
          printf ("\n???	Pr??stamos de libros disponibles a usuarios\n");
        break;

        case 2:
          printf ("\n./Biblos.exe -lc\n");
          printf ("Despliega una lista resumida de los libros registrados en el sistema, mostrando ??nicamente el autor principal, t??tulo del libro y editorial de cada libro, ??nicamente en modo lectura (no se pueden editar los datos).");

          printf ("\n\n./Biblos.exe -lu\n");
          printf ("Despliega una lista resumida de todos los usuarios registrados en el sistema, mostrando los campos de Apellido materno, Apellido paterno y Nombre(s) del usuario, junto con su historial de devoluciones tard??as. ");

          printf ("\n\n./Biblos.exe -lp\n");
          printf ("Despliega un resumen de todos los prestamos vigentes en la biblioteca, mostrando los datos del libro prestado (Titulo, Autor) y datos del usuario que tiene ese libro (Nombre y Apellidos). ");

          printf ("\n\n./Biblos.exe -ldh\n");
          printf ("Despliega un resumen de todos los pr??stamos que deban ser devueltos en el d??a vigente, mostrando los datos del libro prestado (Titulo, Autor) y datos del usuario que tiene ese libro (Nombre y Apellidos).");

          printf ("\n\n./Biblos.exe -f dd.mm.aaaa\n");
          printf ("Sobrescribe la fecha actual del sistema, con la fecha que se introdujo en formato dd.mm.aaaa .\n");
          printf ("ESTA EJECUCI??N ES PARA FINES ADMINISTRATIVOS, EVITAR EL USO DE ESTA FUNCI??N\n");
        break;

        case 3:
          printf ("\n1.	Administraci??n del cat??logo de libros");
          printf ("\n2.	Administraci??n de usuarios");
          printf ("\n3.	Administraci??n de prestamos");
          printf ("\n4.	Salir del programa");
        break;

        case 4:
          printf ("\nAl ingresar a este menu se pueden elegir 4 opciones relacionadas con informacion sobre libros");
          printf ("\n\n----------------------\n");
          printf ("\n1. A??adir Libros\n");
          printf ("Al seleccionar esta opci??n, se empieza con el registro de un nuevo libro que va a entrar al acervo de la biblioteca, el sistema empezara a indicar que campos llenar (rengl??n por rengl??n), se tiene que escribir de forma obligatoria todos los valores y dar enter para avanzar al siguiente dato (recuerde utilizar may??sculas al momento de empezar una palabra, los art??culos, conectores van en min??scula), al final se mostrara el ID que se le asigno al libro y una opci??n relacionada con repetir la ejecuci??n de este programa o simplemente salir al men?? anterior. ");

          printf ("\n\n----------------------\n");
          printf ("2. Consultar Libros\n");
          printf ("\nAl seleccionar esta opci??n, se abre un men?? que nos pide especificar el titulo o Autor, (para b??squedas concretas) o simplemente mostrar todo el acervo de libros.");
          printf ("\nAl seleccionar la opci??n 1 o 2, se debe escribir el nombre exacto del Titulo/Autor y presionar enter, si el sistema encuentra un libro que coincida con ese par??metro, despliega toda la informaci??n sobre ese libro.");
          printf ("\nSi se selecciona la opci??n 3, se muestra el listado de todos los libros que existen en la biblioteca, sin importar si est??n prestados o dados de baja.");

          printf ("\n\n----------------------\n");
          printf ("3. Modificar Libros\n");
          printf ("\nSimilar al men?? anterior, se debe especificar el Titulo o Autor del libro, para saber que libro en espec??fico modificar.");
          printf ("\nDespu??s de escribir el valor con el que se va a buscar el libro, hay 4 posibles escenarios:");
          printf ("\n\nEscenario 1. El Sistema encontr?? 1 libro en com??n\nEn este caso se muestra una pantalla con toda la informaci??n del libro y se pide especificar con un n??mero, cual de los datos modificar.");
          printf ("\nAl seleccionar una opci??n v??lida, se debe escribir el nuevo valor para el libro, despu??s el sistema mostrara el valor antiguo y el nuevo valor y debemos aceptar o cancelar el cambio.");
          printf ("\n\nEscenario 2. El Sistema encontr?? m??s de 1 libro en com??n\nCuando el valor que pusimos coincide con varios libros de la biblioteca, se van a mostrar los datos de todos los libros que coinciden con la b??squeda y en base a eso, debemos escribir el ID del libro que queramos modificar.");
          printf ("\nAl tener el libro correcto, se despliega un menu para seleccionar que valor modificar, cuando seleccionamos una opci??n valida, se debe escribir el nuevo valor para el libro, despu??s el sistema mostrara el valor antiguo y el nuevo valor y debemos aceptar o cancelar el cambio.");
          printf ("\n\nEscenario 3. El Sistema encontr?? un libro, pero este esta prestado/dado de baja\nEn este escenario, no es posible editar las propiedades del libro, ya que este no se encuentra actualmente f??sicamente en el acervo de libros");
          printf ("\n\nEscenario 4. El Sistema no encontr?? alg??n libro\nSimplemente, el par??metro de b??squeda no coincidi?? con alg??n libro del acervo y no se puede modificar nada.");

          printf ("\n\n----------------------\n");
          printf ("4. Dar de baja Libros\n");
          printf ("\nEsta opci??n tiene opciones similares a Modificar Libros, donde primero debemos establecer como buscar alg??n libro, en caso de haber mas de una coincidencia, especificar cual es el libro correcto y al final se muestra un dialogo donde debemos autorizar la baja definitiva del libro en el acervo de la biblioteca.");
        break;

        case 5:
          printf ("\nAl ingresar a este menu se pueden elegir 4 opciones relacionadas con informacion sobre usuarios");

          printf ("\n\n----------------------\n");
          printf ("\n1. A??adir Usuario\n");
          printf ("\nAl seleccionar esta opci??n, se empieza con el registro de un nuevo usuario en el sistema bibliotecario, se deben de llenar todos los campos correspondientes con la informaci??n de un nuevo usuario, al finalizar la captura de datos, el sistema guardara el registro y mostrara el nuevo ID de usuario.");

          printf ("\n\n----------------------\n");
          printf ("\n2. Consultar Usuarios\n");
          printf ("\nAl seleccionar esta opci??n, se abre un men?? que nos pide especificar algun apellido paterno de un registro (para b??squedas concretas) o simplemente mostrar todo la base de datos sobre usuarios.");
          printf ("\nAl seleccionar la opci??n 1 o 2, se debe escribir el apellido del usuario y presionar enter, si el sistema encuentra un libro que coincida con ese par??metro, despliega toda la informaci??n sobre ese libro.");
          printf ("\nSi se selecciona la opci??n 3, se muestra el listado de todos los usuarios que existen en la biblioteca.");

          printf ("\n\n----------------------\n");
          printf ("\n3. Modificar Usuarios\n");
          printf ("\nPrimero se debe especificar el apellido paterno para comparar ese valor con todos los usuarios que existen");
          printf ("\nDespu??s de escribir el valor con el que se va a buscar el usuario, hay 4 posibles escenarios:");
          printf ("\n\nEscenario 1. El Sistema encontr?? 1 usuario en com??n\nEn este caso se muestra una pantalla con toda la informaci??n del libro y se pide especificar con un n??mero, cual de los datos modificar.");
          printf ("\nAl seleccionar una opci??n v??lida, se debe escribir el nuevo valor para el libro, despu??s el sistema mostrara el valor antiguo y el nuevo valor y debemos aceptar o cancelar el cambio.");
          printf ("\n\nEscenario 2. El Sistema encontr?? m??s de 1 usuario en com??n\nCuando el valor que pusimos coincide con varios usuarios de la biblioteca, se van a mostrar los datos de todos los usuarios que coinciden con la b??squeda y en base a eso, debemos escribir el ID del usuario que queramos modificar.");
          printf ("\nAl tener el usuario correcto, se despliega un men?? para seleccionar que valor modificar, cuando seleccionamos una opci??n v??lida, se debe escribir el nuevo valor para el ese dato, despu??s el sistema mostrara el valor antiguo y el nuevo valor y debemos aceptar o cancelar el cambio.");
          printf ("\n\nEscenario 3. El Sistema encontr?? un usuario, pero esta dado de baja\nEn este escenario, no es posible editar los datos del usuario.");
          printf ("\nEscenario 4. El Sistema no encontr?? alg??n usuario\nSimplemente, el par??metro de b??squeda no coincidi?? con alg??n usuario registrado");

          printf ("\n\n----------------------\n");
          printf ("\n4. Dar de baja Libros\n");
          printf ("\nEsta opci??n tiene opciones similares a Modificar Usuarios, donde primero debemos escribir el apellido paterno del usuario y empieza la busqueda, en caso de haber m??s de una coincidencia, se debe especificar cu??l es el usuario correcto y al final se muestra un dialogo donde debemos autorizar la baja definitiva del libro en el acervo de la biblioteca.");
          printf ("\n");
        break;

        case 6:
          printf ("\nA traves de este menu, se pueden acceder a 3 opciones:");

          printf ("\n\n----------------------\n");
          printf ("\n1. Prestamo de libros\n");

          printf ("\n\n----------------------\n");
          printf ("\n1. Devolucion de libros \n");

          printf ("\n\n----------------------\n");
          printf ("\n1. Consulta de prestamos\n");
        break;

        case 7:
        break;

        default:
          printf ("\nNo existe esa opcion\n");
      }
      printf ("\n??Repetir Menu?\n1. Si\n2.No\n");
      scanf ("%d", &y);
    }
  } while (y ==1 );
}
