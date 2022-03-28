///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PedirDatosPrestamo(TipoPrestamo DatosPrestamo[], int *ip)
{
  printf("\n\n\t\tUsted ha seleccionado la opcion: Otorgar Prestamo.\n");
  printf("\n\tIngrese el ID de Usuario: ");
  __fpurge(stdin);
  scanf("%d",&DatosPrestamo[*ip].IDUsuario);
  printf("\tIngrese el ID de la publicacion: ");
  __fpurge(stdin);
  scanf("%d",&DatosPrestamo[*ip].IDLibro);
  //Guardar en el archivo
  FILE *Archivo;
  Archivo = fopen("Prestamos.txt","at");
  fprintf(Archivo,"%d\n",DatosPrestamo[*ip].IDUsuario);
  fprintf(Archivo,"%d\n",DatosPrestamo[*ip].IDLibro);
  fclose(Archivo);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void GuardarDatosPrestamo(TipoPrestamo DatosPrestamo[], int *ip)
{
  FILE *Archivo;
  Archivo = fopen("Prestamos.txt","at");
  fputs(DatosPrestamo[*ip].FechaPrestamo, Archivo);
  fputs("\n", Archivo);
  fputs(DatosPrestamo[*ip].FechaLimiteDevolucion, Archivo);
  fputs("\n", Archivo);
  fputs(DatosPrestamo[*ip].FechaRealDevolucion, Archivo);
  fputs("\n", Archivo);
  fclose(Archivo);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OtorgarPrestamo(TipoPrestamo DatosPrestamo[],int ip,TipoUsuario DatosUsuarios[],int o,TipoLibro DatosLibros[],int i)
{
  int x=0,y=0,PosicionUsuarios,PosicionLibro,aux=0,Confirmar;
  for(x=0;x<o;x++)
  {
    if(DatosUsuarios[x].IDUsuario == DatosPrestamo[ip].IDUsuario)
    {
      PosicionUsuarios=x;
      for(y=0;y<i;y++)
      {
        if(DatosLibros[y].IDLibro == DatosPrestamo[ip].IDLibro)
        {
          PosicionLibro=y;
          aux++;
        }
      }
    }
  }
  //Estructura para Definicion de Fecha
  struct tm *tm,*FechaDev,*FechaDev2;
  time_t Fecha,FechaDevolucion,FechaDevolucion2;
  Fecha=time(NULL);

  //Verificar que libro no este prestado
  if(aux>0){
    if((DatosLibros[PosicionLibro].Estado==0)||(DatosLibros[PosicionLibro].Estado==2))
    {
      printf("\n\tNo se puede otorgar el prestamo\n\tEl Libro se encuentra dado de baja o ya esta prestado.\n");
    }
    else//Verificar el usuario
    {
      //Si el usuario tiene maximo 3 devoluciones tardias, Dias de prestamo =15
      if((DatosUsuarios[PosicionUsuarios].Estado==1)&&(DatosUsuarios[PosicionUsuarios].DevolucionesTardias<=3)&&(DatosUsuarios[PosicionUsuarios].LibrosPrestados<3))
      {
        printf("\nPrestamo autorizado a: 15 días\n");
        tm=localtime(&Fecha);
        printf("Fecha de prestamo registrado: %s",asctime(tm));//Fecha en formato legible
        //Fecha en formato de segundos:
        FechaDevolucion=Fecha+(15*24*60*60);//El sistema nos da la fecha en terminos de segundos, añadimos 15 dias transformandolo en segundos con la operacion
        FechaDev=localtime(&FechaDevolucion);
        printf("Fecha limite para devolucion: %s",asctime(FechaDev));//Fecha en formato legible

        printf ("\n\n¿Confirmar accion?\n\t[1]Si \t\n\t[2]No\nRespuesta: ");
        __fpurge (stdin);
        scanf ("%d", &Confirmar);
        if(Confirmar==1)
        {
          DatosLibros[PosicionLibro].Estado=2;
          printf ("\nEl estado del Libro:\n\t Titulo:%s \t ID:%d \nHa cambiado a: (%d) Prestado\n",DatosLibros[PosicionLibro].Titulo,DatosLibros[PosicionLibro].IDLibro,DatosLibros[PosicionLibro].Estado);
          DatosUsuarios[PosicionUsuarios].LibrosPrestados++;
          printf("El usuario cuenta con: %d Libros Prestados\n",DatosUsuarios[PosicionUsuarios].LibrosPrestados);
          //Fecha
          tm=localtime(&Fecha);
          strftime(DatosPrestamo[ip].FechaPrestamo,80,"%c",tm);
          FechaDev=localtime(&FechaDevolucion);
          strftime(DatosPrestamo[ip].FechaLimiteDevolucion,80,"%c",FechaDev);
          //DatosPrestamo[ip].FechaLimiteDevolucion=strftime(FechaDev);
          printf("Fecha de Registro: %s \nFecha Limite de Devolucion: %s\n\n",DatosPrestamo[ip].FechaPrestamo,DatosPrestamo[ip].FechaLimiteDevolucion);
        }
      }

      //Si el usuario tiene mas de 3 devoluciones tardias, Dias de prestamo =8
      if((DatosUsuarios[PosicionUsuarios].Estado==1)&&(DatosUsuarios[PosicionUsuarios].DevolucionesTardias>3)&&(DatosUsuarios[PosicionUsuarios].LibrosPrestados<3))
      {
        printf("\nPrestamo autorizado a: 8 días\n");
        tm=localtime(&Fecha);
        printf("Fecha de prestamo registrado: %s",asctime(tm));//Fecha en formato legible
        //Fecha en formato de segundos:
        FechaDevolucion2=Fecha+(8*24*60*60);//El sistema nos da la fecha en terminos de segundos, añadimos 15 dias transformandolo en segundos con la operacion
        FechaDev2=localtime(&FechaDevolucion2);
        printf("Fecha limite para devolucion: %s",asctime(FechaDev2));//Fecha en formato legible
        printf ("\n\n¿Confirmar accion?\n\t[1]Si \t\n\t[2]No\nRespuesta: ");
        __fpurge (stdin);
        scanf ("%d", &Confirmar);
        if(Confirmar==1)
        {
          DatosLibros[PosicionLibro].Estado=2;
          printf ("\nEl estado del Libro:\n\t Titulo:%s \t ID:%d \nHa cambiado a: (%d) Prestado\n",DatosLibros[PosicionLibro].Titulo,DatosLibros[PosicionLibro].IDLibro,DatosLibros[PosicionLibro].Estado);
          DatosUsuarios[PosicionUsuarios].LibrosPrestados++;
          printf("El usuario cuenta con: %d Libros Prestados\n",DatosUsuarios[PosicionUsuarios].LibrosPrestados);
          //Fecha
          tm=localtime(&Fecha);
          strftime(DatosPrestamo[ip].FechaPrestamo,80,"%c",tm);
          FechaDev2=localtime(&FechaDevolucion2);
          strftime(DatosPrestamo[ip].FechaLimiteDevolucion,80,"%c",FechaDev2);
          //DatosPrestamo[ip].FechaLimiteDevolucion=strftime(FechaDev);
          printf("Fecha de Registro: %s \nFecha Limite de Devolucion: %s\n\n",DatosPrestamo[ip].FechaPrestamo,DatosPrestamo[ip].FechaLimiteDevolucion);

        }
      }
    }
  }
  else
  printf("Datos incorrectos");
}
////////////
