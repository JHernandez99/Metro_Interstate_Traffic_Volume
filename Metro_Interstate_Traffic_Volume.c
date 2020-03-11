#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <string.h>
#include <math.h>
// creamos una estructura para guardar los datos 
typedef struct db{
    int celebracion;
    float temperatura;
    float mmLluvia;
    float mmNieve;
    int porcentajeNubes;
    int descripcionClimaBreve;
    int descripcionClima;
    int personas;

    int celebracionCond;
    char celebracionS[50];
    float temperaturaCond;
    float mmLluviaCond;
    float mmNieveCond;
    int porcentajeNubesCond;
    int descripcionClimaBreveCond;
    int descripcionClimaCond;
    int personasCond;
    int tamCond;
}db;

typedef struct fecha{
    int anio;
    int mes;
    int dia;
    int diaSemana; // 1 domingo 2 lunes 3 martes 4 miercoles 5 jueves 6 viernes 7 sabado

    int anioCond;
    int mesCond;
    int diaCond;
    int diaSemanaCond;
}fecha;

typedef struct hora{
    int hora;
    int minutos;
    int segundos;

    int horaCond;
    int minutosCond;
    int segundosCond;
}hora;


typedef struct stadistics{
    
    int STpersonas;
    float STtemperatura;
    int mediana;
    float varianza;
    float desviacion;
    int moda;
    int frecuenciaAbsoluta;
    float STnubes;
    float STlluvia;
    float STnieve;


}stadistics;

int tamanio(FILE *archivo){
    int n=0;
    char caracter[125];
    while(!fgets(caracter,500,archivo) == NULL){
        n++;
    }
    rewind(archivo);
    return n;
    
}

void precargaDatos(FILE *archivo, db *datos){
    char delimitador[] = ",\n";
    char caracter[125];
    int tam = tamanio(archivo), i,aux=0;
    
    for(i=0;i<tam+1;i++){
            fgets(caracter,500,archivo);
            char *token  = strtok(caracter, delimitador);
                datos[i].celebracion = token;            
               // printf("[%d]%s\n",i+1,datos[i].celebracion);
                int tamc=strlen(datos[i].celebracion);
               switch(tamc){
                   case 4:
                         datos[i].celebracion=0;
                   break;
                   case 7:
                         datos[i].celebracion=1;
                   break;
                   case 9:
                         datos[i].celebracion=2; //Labor Day
                   break;
                   case 10:
                         datos[i].celebracion=3;
                   break;
                   case 12:
                        datos[i].celebracion=4; //veterans Day
                    
                   break;
                   case 13:
                        datos[i].celebracion=5;
                   break;
                   case 16:
                        datos[i].celebracion=6; //thanksgiving
                   break;
                   case 20:
                        datos[i].celebracion=7;
                   break;
                   case 25:
                        datos[i].celebracion=8;
                   break;
               }
               //printf("[%d]%i\n",i+1,datos[i].celebracion);
            if(token  != NULL){
                aux=0;
                while(token !=NULL){
                
                //printf(token);printf("\n");
                token  = strtok(NULL, delimitador);
                
                switch(aux){
                    case 0: // temperatura
                        datos[i].temperatura=atof(token);
                        //printf("[%d]%f\n",i+1, datos[i].temperatura);
                    break;
                    case 1:  // lluvia
                        datos[i].mmLluvia=atof(token);
                        //printf("[%d]%f\n",i+1, datos[i].mmLluvia);
                    break;
                    case 2: // nieve
                        datos[i].mmNieve=atof(token);
                       /* if(datos[i].mmNieve != 0){
                            printf("[%d]%f\n",i+1, datos[i].mmNieve);
                        }*/
                    break;
                    case 3:// nuves
                        datos[i].porcentajeNubes=atoi(token);
                        //printf("[%d]%d\n",i+1, datos[i].porcentajeNubes);
                    break;
                    case 4: //clima
                       datos[i].descripcionClimaBreve=token;
                       //switch //para volver a
                       //printf("[%d]%s\n",i+1, datos[i].descripcionClimaBreve);
                    break;
                    case 5: // clima
                        datos[i].descripcionClima = token;
                        //printf("[%d]%s\n",i+1, datos[i].descripcionClima);
                       // printf(datos->descripcionClimaBreve);
                    break;
                    case 6:// fecha
                        //datos[i].fechaHora =token;
                        
                       // printf("%s", token);
                        //printf("[%d]%s\n",i+1, datos[i].fechaHora);
                    break;
                    case 7: // trafico
                        datos[i].personas = atoi(token);
                        //printf("[%d]%d\n",i+1, datos[i].personas);
                    break;
                }
                aux++;


                }
            }
        }
       /* printf("el tamanio es : %d \n mostramos lo que ocupo",tam);
        for(i=0;i<500;i++){
         //   printf("datos[%d]: %c \n",i+1,datos->celebration[4]);
        }*/
    
}

void precargaCadenas(FILE *archivo, db *datos,fecha *fei, hora *tim){
    char delimitador[] = ",\n";
    char caracter[125];
    int tam = tamanio(archivo), i,aux=0;
    char *token, *token2;
    for(i=0;i<tam+1;i++){
            fgets(caracter,500,archivo);
            char *rest = caracter;
               // datos[i].celebracion = token;            
               // printf("[%d]%s\n",i+1,datos[i].celebracion);
            aux=0;
            while(token  = strtok_s(rest, ",-:\n",&rest)){
                //printf("%s\n",token);
                //printf(token);printf("\n");
                //token  = strtok(NULL, delimitador);
                
                switch(aux){
                 /*case 0:
                    printf("%s\n",token);

                    int  td = strlen(token);
                    int k;
                    datos[i].celebracionS = token;
                    for(k=0;k<td;k++){
                        printf("%s",datos[k].celebracion);
                    }
                    printf("\n");

                   // printf("%s\n",datos[i].celebracionS);
                 break;*/
                 /*   case 4: //clima
                       datos[i].descripcionClimaBreve=token;
                       //switch //para volver a
                       //printf("[%d]%s\n",i+1, datos[i].descripcionClimaBreve);
                    break;
                    case 5: // clima
                        datos[i].descripcionClima = token;
                        //printf("[%d]%s\n",i+1, datos[i].descripcionClima);
                       // printf(datos->descripcionClimaBreve);
                    break;
                    */case 7:// fecha año
                        
                        //datos[i].fechaHora = token;
                        fei[i].anio =atoi(token);
                    //printf("[%d] %d:",i+1, fei[i].anio);
                      //  printf("imprime datos\n");
                        //printf("[%d]%s\n",i+1, datos[i].fechaHora);
                    break;
                    case 8: //fecha mes
                        fei[i].mes = atoi(token);
                        //printf("%d:",fei[i].mes);
                    break;
                    case 9: 
                        
                        fei[i].dia = atoi(token);
                        //printf("%d\n----",fei[i].dia);
                        
                        //token2  = strtok(token, " ");
                        //printf("\nresult: %s",token2)
                    break;
                    

                  
                }
                aux++;


                }
               
            
        }
        //printf("rewind\n");
        rewind(archivo);
        for(i=0;i<tam+1;i++){
            fgets(caracter,500,archivo);
            char *rest = caracter;
            aux=0;
            while(token  = strtok_s(rest, ",-:\n",&rest)){
                switch(aux){
                case 8: 
                        //fei[i].Hora = atoi(token);

                        //printf("%s\n",token);
                        token  = strtok_s(rest, " ",&rest);
                        token  = strtok_s(rest, " ,:",&rest);
                        //printf("[%d] %s\n",i+1,token);
                        tim[i].hora = atoi(token);
                        tim[i].minutos = 0;
                        tim[i].segundos = 0;
                break;
            }
            aux++;
            }
        }


       /* printf("el tamanio es : %d \n mostramos lo que ocupo",tam);
        for(i=0;i<500;i++){
         //   printf("datos[%d]: %c \n",i+1,datos->celebration[4]);
        }*/
        

    
}

void determinarDiaSemana(int tam, fecha *fei){
    // algoritmo para calcular que dia de la semana fue tal fecha
    int i = 0,A,B,C,D,E,F,aux,dia;
    
    for(i=0;i<47594;i++){
        A=0; // solo valido para años del 2000 al 2099
        B=(fei[i].anio)-2000;
        aux = B/4;
        B = B + aux;
        if(fei[i].anio == 2012 || fei[i].anio == 2016 && fei[i].mes <=2 ){
                C = -1;
        }else{
            C = 0;
        }
        switch (fei[i].mes)
        {
        case 1:
            D=6;
        break;
        case 2:
            D=2;
        break;
        case 3:
            D=2;
        break;
        case 4:
            D=5;
        break;
        case 5:
            D=0;
        break;
        case 6: 
            D=3;
        break;
        case 7:
            D=5;
        break;
        case 8:
            D=1;
        break;
        case 9: 
            D=4;
        break;
        case 10:
            D=6;
        break;
        case 11:
            D=2;
        break;
        case 12:
            D=4;
        break;
        }
        E= fei[i].dia;
        
        dia = A+B+C+D+E;
        dia = dia%7;    
        fei[i].diaSemana = dia;
    }
    
    
    
}
void consultaFecha(db *datos,fecha *fei,hora *tim,int dd,int mm,int yy,int tam){
    int i,contador=0;
    for(i=0;i<tam;i++){
        if(fei[i].anio == yy && fei[i].mes == mm && fei[i].dia == dd){
            //printf(" %d %f %f %f %d %d-%d-%d %d:%d:%d %d \n",datos[i].celebracion,datos[i].temperatura, datos[i].mmLluvia, datos[i].mmNieve, datos[i].porcentajeNubes,fei[i].dia,fei[i].mes,fei[i].anio,tim[i].hora,tim[i].minutos,tim[i].segundos,datos[i].personas);
            contador++;
            datos[contador].celebracionCond = datos[i].celebracion;
            datos[contador].temperaturaCond = datos[i].temperatura;
            datos[contador].mmLluviaCond = datos[i].mmLluvia;
            datos[contador].mmNieveCond = datos[i].mmNieve;
            datos[contador].porcentajeNubesCond = datos[i].porcentajeNubes;
            datos[contador].personasCond = datos[i].personas;
            fei[contador].diaCond = fei[i].dia;
            fei[contador].mesCond = fei[i].mes;
            fei[contador].anioCond = fei[i].anio;
            tim[contador].horaCond = tim[i].hora;
            tim[contador].minutosCond = tim[i].minutos;
            tim[contador].segundosCond = tim[i].segundos;
        }
    }
    datos[1].tamCond = contador;
}
void mostrarCelebraciones(){
    printf("");
}
void consultaTemperatura(float temperatura, db *datos, fecha *fei, hora *tim ,int tam){
    int i,contador=0;
    for(i=0;i<tam;i++){
        if(datos[i].temperatura == temperatura){
            //printf(" %d %f %f %f %d %d-%d-%d %d:%d:%d %d \n",datos[i].celebracion,datos[i].temperatura, datos[i].mmLluvia, datos[i].mmNieve, datos[i].porcentajeNubes,fei[i].dia,fei[i].mes,fei[i].anio,tim[i].hora,tim[i].minutos,tim[i].segundos,datos[i].personas);
            contador++;
            datos[contador].celebracionCond = datos[i].celebracion;
            datos[contador].temperaturaCond = datos[i].temperatura;
            datos[contador].mmLluviaCond = datos[i].mmLluvia;
            datos[contador].mmNieveCond = datos[i].mmNieve;
            datos[contador].porcentajeNubesCond = datos[i].porcentajeNubes;
            datos[contador].personasCond = datos[i].personas;
            fei[contador].diaCond = fei[i].dia;
            fei[contador].mesCond = fei[i].mes;
            fei[contador].anioCond = fei[i].anio;
            tim[contador].horaCond = tim[i].hora;
            tim[contador].minutosCond = tim[i].minutos;
            tim[contador].segundosCond = tim[i].segundos;
        }
    }
    datos[1].tamCond = contador;
}
void consultaMilimetrosLluvia(float lluvia,db *datos,fecha *fei,hora *tim,int tam){
    int i,contador=0;
    for(i=0;i<tam;i++){
        if(datos[i].mmLluvia == lluvia){
            //printf(" %d %f %f %f %d %d-%d-%d %d:%d:%d %d \n",datos[i].celebracion,datos[i].temperatura, datos[i].mmLluvia, datos[i].mmNieve, datos[i].porcentajeNubes,fei[i].dia,fei[i].mes,fei[i].anio,tim[i].hora,tim[i].minutos,tim[i].segundos,datos[i].personas);
            contador++;
            datos[contador].celebracionCond = datos[i].celebracion;
            datos[contador].temperaturaCond = datos[i].temperatura;
            datos[contador].mmLluviaCond = datos[i].mmLluvia;
            datos[contador].mmNieveCond = datos[i].mmNieve;
            datos[contador].porcentajeNubesCond = datos[i].porcentajeNubes;
            datos[contador].personasCond = datos[i].personas;
            fei[contador].diaCond = fei[i].dia;
            fei[contador].mesCond = fei[i].mes;
            fei[contador].anioCond = fei[i].anio;
            tim[contador].horaCond = tim[i].hora;
            tim[contador].minutosCond = tim[i].minutos;
            tim[contador].segundosCond = tim[i].segundos;
        }
    }
    datos[1].tamCond = contador;
}
void consultaMilimetrosNieve(float nieve,db *datos,fecha *fei,hora *tim,int tam){
    int i,contador=0;
    for(i=0;i<tam;i++){
        if(datos[i].mmNieve == nieve){
            //printf(" %d %f %f %f %d %d-%d-%d %d:%d:%d %d \n",datos[i].celebracion,datos[i].temperatura, datos[i].mmLluvia, datos[i].mmNieve, datos[i].porcentajeNubes,fei[i].dia,fei[i].mes,fei[i].anio,tim[i].hora,tim[i].minutos,tim[i].segundos,datos[i].personas);
            contador++;
            datos[contador].celebracionCond = datos[i].celebracion;
            datos[contador].temperaturaCond = datos[i].temperatura;
            datos[contador].mmLluviaCond = datos[i].mmLluvia;
            datos[contador].mmNieveCond = datos[i].mmNieve;
            datos[contador].porcentajeNubesCond = datos[i].porcentajeNubes;
            datos[contador].personasCond = datos[i].personas;
            fei[contador].diaCond = fei[i].dia;
            fei[contador].mesCond = fei[i].mes;
            fei[contador].anioCond = fei[i].anio;
            tim[contador].horaCond = tim[i].hora;
            tim[contador].minutosCond = tim[i].minutos;
            tim[contador].segundosCond = tim[i].segundos;
        }
    }
    datos[1].tamCond = contador;
}
void consultaPorcentajeNubes(int nubes , db *datos,fecha *fei, hora *tim,int tam){
    int i,contador=0;
    for(i=0;i<tam;i++){
        if(datos[i].porcentajeNubes == nubes){
           // printf(" %d %f %f %f %d %d-%d-%d %d:%d:%d %d \n",datos[i].celebracion,datos[i].temperatura, datos[i].mmLluvia, datos[i].mmNieve, datos[i].porcentajeNubes,fei[i].dia,fei[i].mes,fei[i].anio,tim[i].hora,tim[i].minutos,tim[i].segundos,datos[i].personas);
            contador++;
            datos[contador].celebracionCond = datos[i].celebracion;
            datos[contador].temperaturaCond = datos[i].temperatura;
            datos[contador].mmLluviaCond = datos[i].mmLluvia;
            datos[contador].mmNieveCond = datos[i].mmNieve;
            datos[contador].porcentajeNubesCond = datos[i].porcentajeNubes;
            datos[contador].personasCond = datos[i].personas;
            fei[contador].diaCond = fei[i].dia;
            fei[contador].mesCond = fei[i].mes;
            fei[contador].anioCond = fei[i].anio;
            tim[contador].horaCond = tim[i].hora;
            tim[contador].minutosCond = tim[i].minutos;
            tim[contador].segundosCond = tim[i].segundos;
        }
    }datos[1].tamCond = contador;
}
void consultaPersonas(int personas,db *datos,fecha *fei,hora *tim,int tam){
    int i,contador=0;
    for(i=0;i<tam;i++){
        if(datos[i].personas == personas){
          //  printf(" %d %f %f %f %d %d-%d-%d %d:%d:%d %d \n",datos[i].celebracion,datos[i].temperatura, datos[i].mmLluvia, datos[i].mmNieve, datos[i].porcentajeNubes,fei[i].dia,fei[i].mes,fei[i].anio,tim[i].hora,tim[i].minutos,tim[i].segundos,datos[i].personas);
            contador++;
            datos[contador].celebracionCond = datos[i].celebracion;
            datos[contador].temperaturaCond = datos[i].temperatura;
            datos[contador].mmLluviaCond = datos[i].mmLluvia;
            datos[contador].mmNieveCond = datos[i].mmNieve;
            datos[contador].porcentajeNubesCond = datos[i].porcentajeNubes;
            datos[contador].personasCond = datos[i].personas;
            fei[contador].diaCond = fei[i].dia;
            fei[contador].mesCond = fei[i].mes;
            fei[contador].anioCond = fei[i].anio;
            tim[contador].horaCond = tim[i].hora;
            tim[contador].minutosCond = tim[i].minutos;
            tim[contador].segundosCond = tim[i].segundos;
        }
    }
    datos[1].tamCond = contador;
}
void rangoFecha(int dd1, int mm1,int yy1,int dd2,int mm2,int yy2,db *datos,fecha *fei,hora *tim,int tam){
    int i,contador = 0;
    int lim1,lim2;
    for(i=0;i<tam;i++){
        if(fei[i].anio == yy1 && fei[i].mes== mm1 && fei[i].dia == dd1 && tim[i].hora==0){
            lim1=i;
        }
    }
    for(i=0;i<tam;i++){
        if(fei[i].anio == yy2 && fei[i].mes== mm2 && fei[i].dia == dd2 && tim[i].hora==0){
            lim2=i;
        }
    }
    for(i=lim1;i<=lim2;i++){
        // printf(" %d %f %f %f %d %d-%d-%d %d:%d:%d %d \n",datos[i].celebracion,datos[i].temperatura, datos[i].mmLluvia, datos[i].mmNieve, datos[i].porcentajeNubes,fei[i].dia,fei[i].mes,fei[i].anio,tim[i].hora,tim[i].minutos,tim[i].segundos,datos[i].personas);
            contador++;
            datos[contador].celebracionCond = datos[i].celebracion;
            datos[contador].temperaturaCond = datos[i].temperatura;
            datos[contador].mmLluviaCond = datos[i].mmLluvia;
            datos[contador].mmNieveCond = datos[i].mmNieve;
            datos[contador].porcentajeNubesCond = datos[i].porcentajeNubes;
            datos[contador].personasCond = datos[i].personas;
            fei[contador].diaCond = fei[i].dia;
            fei[contador].mesCond = fei[i].mes;
            fei[contador].anioCond = fei[i].anio;
            tim[contador].horaCond = tim[i].hora;
            tim[contador].minutosCond = tim[i].minutos;
            tim[contador].segundosCond = tim[i].segundos;
    }    
    datos[1].tamCond = contador;
    
}
void rangoFlujoPersonas(int personas1,int personas2,db *datos,fecha *fei,hora *tim,int tam){
    int i,contador = 0;
    for(i=0;i<tam;i++){
        if(datos[i].personas >= personas1 && datos[i].personas <=personas2){
           // printf(" %d %f %f %f %d %d-%d-%d %d:%d:%d %d \n",datos[i].celebracion,datos[i].temperatura, datos[i].mmLluvia, datos[i].mmNieve, datos[i].porcentajeNubes,fei[i].dia,fei[i].mes,fei[i].anio,tim[i].hora,tim[i].minutos,tim[i].segundos,datos[i].personas);
            contador++;
            datos[contador].celebracionCond = datos[i].celebracion;
            datos[contador].temperaturaCond = datos[i].temperatura;
            datos[contador].mmLluviaCond = datos[i].mmLluvia;
            datos[contador].mmNieveCond = datos[i].mmNieve;
            datos[contador].porcentajeNubesCond = datos[i].porcentajeNubes;
            datos[contador].personasCond = datos[i].personas;
            fei[contador].diaCond = fei[i].dia;
            fei[contador].mesCond = fei[i].mes;
            fei[contador].anioCond = fei[i].anio;
            tim[contador].horaCond = tim[i].hora;
            tim[contador].minutosCond = tim[i].minutos;
            tim[contador].segundosCond = tim[i].segundos;
        } 
    }
    datos[1].tamCond = contador;
}
void rangoTemperatura(float temperatura1,float temperatura2,db *datos,fecha *fei,hora *tim,int tam){
    int i,contador = 0;
    for(i=0;i<tam;i++){
        if(datos[i].temperatura >= temperatura1 && datos[i].temperatura <=temperatura2){
          //  printf(" %d %f %f %f %d %d-%d-%d %d:%d:%d %d \n",datos[i].celebracion,datos[i].temperatura, datos[i].mmLluvia, datos[i].mmNieve, datos[i].porcentajeNubes,fei[i].dia,fei[i].mes,fei[i].anio,tim[i].hora,tim[i].minutos,tim[i].segundos,datos[i].personas);
            contador++;
            datos[contador].celebracionCond = datos[i].celebracion;
            datos[contador].temperaturaCond = datos[i].temperatura;
            datos[contador].mmLluviaCond = datos[i].mmLluvia;
            datos[contador].mmNieveCond = datos[i].mmNieve;
            datos[contador].porcentajeNubesCond = datos[i].porcentajeNubes;
            datos[contador].personasCond = datos[i].personas;
            fei[contador].diaCond = fei[i].dia;
            fei[contador].mesCond = fei[i].mes;
            fei[contador].anioCond = fei[i].anio;
            tim[contador].horaCond = tim[i].hora;
            tim[contador].minutosCond = tim[i].minutos;
            tim[contador].segundosCond = tim[i].segundos;
        } 
    }
    datos[1].tamCond = contador;
}

void rangoLluvia(float lluvia1,float lluvia2,db *datos,fecha *fei,hora *tim,int tam){
    int i,contador = 0;
    for(i=0;i<tam;i++){
        if(datos[i].mmLluvia >= lluvia1 && datos[i].mmLluvia <=lluvia2){
          //  printf(" %d %f %f %f %d %d-%d-%d %d:%d:%d %d \n",datos[i].celebracion,datos[i].temperatura, datos[i].mmLluvia, datos[i].mmNieve, datos[i].porcentajeNubes,fei[i].dia,fei[i].mes,fei[i].anio,tim[i].hora,tim[i].minutos,tim[i].segundos,datos[i].personas);
            contador++;
            datos[contador].celebracionCond = datos[i].celebracion;
            datos[contador].temperaturaCond = datos[i].temperatura;
            datos[contador].mmLluviaCond = datos[i].mmLluvia;
            datos[contador].mmNieveCond = datos[i].mmNieve;
            datos[contador].porcentajeNubesCond = datos[i].porcentajeNubes;
            datos[contador].personasCond = datos[i].personas;
            fei[contador].diaCond = fei[i].dia;
            fei[contador].mesCond = fei[i].mes;
            fei[contador].anioCond = fei[i].anio;
            tim[contador].horaCond = tim[i].hora;
            tim[contador].minutosCond = tim[i].minutos;
            tim[contador].segundosCond = tim[i].segundos;
        } 
    }
    datos[1].tamCond = contador;
}
void rangoNieve(float nieve1,float nieve2,db *datos,fecha *fei,hora *tim,int tam){
    int i,contador = 0;
    for(i=0;i<tam;i++){
        if(datos[i].mmNieve >= nieve1 && datos[i].mmNieve <=nieve2){
            //printf(" %d %f %f %f %d %d-%d-%d %d:%d:%d %d \n",datos[i].celebracion,datos[i].temperatura, datos[i].mmLluvia, datos[i].mmNieve, datos[i].porcentajeNubes,fei[i].dia,fei[i].mes,fei[i].anio,tim[i].hora,tim[i].minutos,tim[i].segundos,datos[i].personas);
            contador++;
            datos[contador].celebracionCond = datos[i].celebracion;
            datos[contador].temperaturaCond = datos[i].temperatura;
            datos[contador].mmLluviaCond = datos[i].mmLluvia;
            datos[contador].mmNieveCond = datos[i].mmNieve;
            datos[contador].porcentajeNubesCond = datos[i].porcentajeNubes;
            datos[contador].personasCond = datos[i].personas;
            fei[contador].diaCond = fei[i].dia;
            fei[contador].mesCond = fei[i].mes;
            fei[contador].anioCond = fei[i].anio;
            tim[contador].horaCond = tim[i].hora;
            tim[contador].minutosCond = tim[i].minutos;
            tim[contador].segundosCond = tim[i].segundos;
        } 
    }
    datos[1].tamCond = contador;
}
void rangoNubes(int nubes1 , int nubes2,db *datos,fecha *fei,hora *tim,int tam){
    int i,contador = 0;
    for(i=0;i<tam;i++){
        if(datos[i].porcentajeNubes >= nubes1 && datos[i].porcentajeNubes <= nubes2){
           // printf(" %d %f %f %f %d %d-%d-%d %d:%d:%d %d \n",datos[i].celebracion,datos[i].temperatura, datos[i].mmLluvia, datos[i].mmNieve, datos[i].porcentajeNubes,fei[i].dia,fei[i].mes,fei[i].anio,tim[i].hora,tim[i].minutos,tim[i].segundos,datos[i].personas);
            contador++;
            datos[contador].celebracionCond = datos[i].celebracion;
            datos[contador].temperaturaCond = datos[i].temperatura;
            datos[contador].mmLluviaCond = datos[i].mmLluvia;
            datos[contador].mmNieveCond = datos[i].mmNieve;
            datos[contador].porcentajeNubesCond = datos[i].porcentajeNubes;
            datos[contador].personasCond = datos[i].personas;
            fei[contador].diaCond = fei[i].dia;
            fei[contador].mesCond = fei[i].mes;
            fei[contador].anioCond = fei[i].anio;
            tim[contador].horaCond = tim[i].hora;
            tim[contador].minutosCond = tim[i].minutos;
            tim[contador].segundosCond = tim[i].segundos;
        } 
    }
    datos[1].tamCond = contador;
}

// nuevo funciones de estadistica 
void media(db *datos, int tam, stadistics *stats){
    int media=0,i;
    float medianube=0,mediat=0,medialluvia=0,medianieve=0;
   // printf("\nCalculo de la media\n");
    for( i=0; i<tam;i++){
     media += datos[i].personas;
     mediat +=datos[i].temperatura;
     medialluvia +=datos[i].mmLluvia;
     medianube +=datos[i].porcentajeNubes; 
     medianieve +=datos[i].mmNieve;
    }
    media/=tam;
    mediat/=tam;
    medianube/=tam;
    medialluvia/=tam;
    medianieve/=tam;
   // printf("la media es: %d\n",media);
    //printf("la media temp es: %f\n",mediat);
    //printf("la media nubosidad es: %f\n",medianube);
    //printf("la media lluvia es: %f\n",medialluvia);
    //printf("la media nieve es: %f\n",medianieve);
    stats[1].STpersonas= media;
    stats[1].STtemperatura= mediat;
    stats[1].STnubes= medianube;
    stats[1].STlluvia= medialluvia;
    stats[1].STnieve= medianieve;

    //printf(" la media es : %d\n", media);
}
void mediaCondicionada(db *datos, stadistics *stats){
    int media=0,i;
    int tam = datos[1].tamCond;
    float medianube=0,mediat=0,medialluvia=0,medianieve=0;
    //printf("\nCalculo de la media\n");
    for( i=0; i<tam;i++){
     media += datos[i].personasCond;
     mediat +=datos[i].temperaturaCond;
     medialluvia +=datos[i].mmLluviaCond;
     medianube +=datos[i].porcentajeNubesCond; 
     medianieve +=datos[i].mmNieveCond;
    }
    media/=tam;
    mediat/=tam;
    medianube/=tam;
    medialluvia/=tam;
    medianieve/=tam;
    //printf("la media es: %d\n",media);
    //printf("la media temp es: %f\n",mediat);
    //printf("la media nubosidad es: %f\n",medianube);
    //printf("la media lluvia es: %f\n",medialluvia);
    //printf("la media nieve es: %f\n",medianieve);
    stats[10].STpersonas= media;
    stats[10].STtemperatura= mediat;
    stats[10].STnubes= medianube;
    stats[10].STlluvia= medialluvia;
    stats[10].STnieve= medianieve;
}
void maximos(db *datos, int tam, stadistics *stats){
    int maximo=0,i;
    int may=datos[0].personas;
    float maytemp=datos[0].temperatura,maynube=datos[0].porcentajeNubes,maylluvia=datos[0].mmLluvia,maynieve=datos[0].mmNieve;
    for(i=0;i<tam;i++){
        if(datos[i].personas>may){
            may=datos[i].personas;
        }
        if(datos[i].porcentajeNubes>maynube)
        {
            maynube=datos[i].porcentajeNubes;
        }
        if(datos[i].temperatura>maytemp)
        {
            maytemp=datos[i].temperatura;
        }
        if(datos[i].mmLluvia>maylluvia)
        {
            maylluvia=datos[i].mmLluvia;
        }
        if(datos[i].mmNieve>maynieve)
        {
            maynieve=datos[i].mmNieve;
        }
    }
    //printf("Maximo:%d\n",may);
    //printf("Maximo nube:%f\n",maynube);
    //printf("Maximo temp:%f\n",maytemp);
    //printf("Maximo lluvia:%f\n",maylluvia);
    //printf("Maximo nieve:%f\n",maynieve);
    stats[2].STpersonas= may;
    stats[2].STtemperatura= maytemp;
    stats[2].STnubes= maynube;
    stats[2].STlluvia= maylluvia;
    stats[2].STnieve= maynieve;
}
void maximoCondicionado(db *datos, stadistics *stats){
    int maximo=0,i;
    int tam = datos[1].tamCond;
    int may=datos[0].personasCond;
    float maytemp=datos[0].temperaturaCond,maynube=datos[0].porcentajeNubesCond,maylluvia=datos[0].mmLluviaCond,maynieve=datos[0].mmNieveCond;
    for(i=0;i<tam;i++){
        if(datos[i].personasCond>may){
            may=datos[i].personasCond;
        }
        if(datos[i].porcentajeNubesCond>maynube)
        {
            maynube=datos[i].porcentajeNubesCond;
        }
        if(datos[i].temperaturaCond>maytemp)
        {
            maytemp=datos[i].temperaturaCond;
        }
        if(datos[i].mmLluviaCond>maylluvia)
        {
            maylluvia=datos[i].mmLluviaCond;
        }
        if(datos[i].mmNieveCond>maynieve)
        {
            maynieve=datos[i].mmNieveCond;
        }
    }
    stats[11].STpersonas= may;
    stats[11].STtemperatura= maytemp;
    stats[11].STnubes= maynube;
    stats[11].STlluvia= maylluvia;
    stats[11].STnieve= maynieve;
}
void minimo(db *datos, int tam, stadistics *stats){
    int maximo=0,i;
    int may=datos[0].personas;
    float maytemp=datos[0].temperatura,maynube=datos[0].porcentajeNubes,maylluvia=datos[0].mmLluvia,maynieve=datos[0].mmNieve;
    for(i=0;i<tam;i++){
        if(datos[i].personas<may){
            may=datos[i].personas;
        }
        if(datos[i].porcentajeNubes<maynube)
        {
            maynube=datos[i].porcentajeNubes;
        }
        if(datos[i].temperatura<maytemp)
        {
            maytemp=datos[i].temperatura;
        }
        if(datos[i].mmLluvia<maylluvia)
        {
            maylluvia=datos[i].mmLluvia;
        }
        if(datos[i].mmNieve<maynieve)
        {
            maynieve=datos[i].mmNieve;
        }
    }
    //printf("Minimo:%d\n",may);
    //printf("Minimo nube:%f\n",maynube);
    //printf("Minimo temp:%f\n",maytemp);
    //printf("Minimo lluvia:%f\n",maylluvia);
    //printf("Minimo nieve:%f\n",maynieve);
    stats[3].STpersonas= may;
    stats[3].STtemperatura= maytemp;
    stats[3].STnubes= maynube;
    stats[3].STlluvia= maylluvia;
    stats[3].STnieve= maynieve;
}
void minimoCondicionado(db *datos, stadistics *stats){
    int maximo=0,i;
    int may=datos[0].personasCond;
    int tam = datos[1].tamCond;
    float maytemp=datos[0].temperaturaCond,maynube=datos[0].porcentajeNubesCond,maylluvia=datos[0].mmLluviaCond,maynieve=datos[0].mmNieveCond;
    for(i=0;i<tam;i++){
        if(datos[i].personasCond<may){
            may=datos[i].personasCond;
        }
        if(datos[i].porcentajeNubesCond<maynube)
        {
            maynube=datos[i].porcentajeNubesCond;
        }
        if(datos[i].temperaturaCond<maytemp)
        {
            maytemp=datos[i].temperaturaCond;
        }
        if(datos[i].mmLluviaCond<maylluvia)
        {
            maylluvia=datos[i].mmLluviaCond;
        }
        if(datos[i].mmNieveCond<maynieve)
        {
            maynieve=datos[i].mmNieveCond;
        }
    }
    //printf("Minimo:%d\n",may);
    //printf("Minimo nube:%f\n",maynube);
    //printf("Minimo temp:%f\n",maytemp);
    //printf("Minimo lluvia:%f\n",maylluvia);
    //printf("Minimo nieve:%f\n",maynieve);
    stats[12].STpersonas= may;
    stats[12].STtemperatura= maytemp;
    stats[12].STnubes= maynube;
    stats[12].STlluvia= maylluvia;
    stats[12].STnieve= maynieve;

}

void mediana(db *datos, int tam, stadistics *stats,fecha *fei, hora *tim){
	int mediana;
	if(tam%2==0)
	{
		mediana=tam/2;
	}
	else
	{
		mediana= ((tam/2)+((tam/2)+1))/2;
	}
	 //printf(" Mediana %d %f %f %f %d %d-%d-%d %d:%d:%d %d \n",datos[mediana].celebracion,datos[mediana].temperatura, datos[mediana].mmLluvia, datos[mediana].mmNieve, datos[mediana].porcentajeNubes,fei[mediana].dia,fei[mediana].mes,fei[mediana].anio,tim[mediana].hora,tim[mediana].minutos,tim[mediana].segundos,datos[mediana].personas);
    stats[8].STpersonas= datos[mediana].personas;
    stats[8].STtemperatura= datos[mediana].temperatura;
    stats[8].STnubes= datos[mediana].porcentajeNubes;
    stats[8].STlluvia= datos[mediana].mmLluvia;
    stats[8].STnieve= datos[mediana].mmNieve;
}
void medianaCondicionada(db *datos, stadistics *stats, fecha *fei, hora *tim){
    int mediana;
    int tam = datos[1].tamCond;
	if(tam%2==0)
	{
		mediana=tam/2;
	}
	else
	{
		mediana= ((tam/2)+((tam/2)+1))/2;
	}
	 //printf(" Mediana %d %f %f %f %d %d-%d-%d %d:%d:%d %d \n",datos[mediana].celebracion,datos[mediana].temperatura, datos[mediana].mmLluvia, datos[mediana].mmNieve, datos[mediana].porcentajeNubes,fei[mediana].dia,fei[mediana].mes,fei[mediana].anio,tim[mediana].hora,tim[mediana].minutos,tim[mediana].segundos,datos[mediana].personas);
    stats[13].STpersonas= datos[mediana].personasCond;
    stats[13].STtemperatura= datos[mediana].temperaturaCond;
    stats[13].STnubes= datos[mediana].porcentajeNubesCond;
    stats[13].STlluvia= datos[mediana].mmLluviaCond;
    stats[13].STnieve= datos[mediana].mmNieveCond;
}
void varianza(db *datos, int tam, stadistics *stats){
    int i;
    float varianzapersona=0, varianzatemperatura=0,varianzalluvia=0,varianzanieve=0,varianzanube=0 ;
    for(i=0;i<tam;i++){
        varianzapersona +=pow((datos[i].personas-stats[1].STpersonas),2);
        varianzatemperatura +=pow((datos[i].personas-stats[1].STtemperatura),2);
        varianzalluvia +=pow((datos[i].mmLluvia-stats[1].STlluvia),2);
        varianzanieve +=pow((datos[i].mmNieve-stats[1].STnieve),2);
        varianzanube +=pow((datos[i].porcentajeNubes-stats[1].STnubes),2);
    }
    varianzapersona/=tam;
    varianzatemperatura/=tam;
    varianzalluvia/=tam;
    varianzanieve/=tam;
    varianzanube/=tam;
     stats[4].STpersonas= varianzapersona;
    stats[4].STtemperatura= varianzatemperatura;
    stats[4].STnubes= varianzanube;
    stats[4].STlluvia= varianzalluvia;
    stats[4].STnieve= varianzanieve;
    //printf( "Varianzas %f\t %f\t %f\t %f\t %f\n",varianzapersona,varianzatemperatura,varianzalluvia,varianzanieve,varianzanube);
}
void varianzaCondicionada(db *datos, stadistics *stats){
     int i;
     int tam = datos[1].tamCond;
    float varianzapersona=0, varianzatemperatura=0,varianzalluvia=0,varianzanieve=0,varianzanube=0 ;
    for(i=0;i<tam;i++){
        varianzapersona +=pow((datos[i].personasCond-stats[10].STpersonas),2);
        varianzatemperatura +=pow((datos[i].personasCond-stats[10].STtemperatura),2);
        varianzalluvia +=pow((datos[i].mmLluviaCond-stats[10].STlluvia),2);
        varianzanieve +=pow((datos[i].mmNieveCond-stats[10].STnieve),2);
        varianzanube +=pow((datos[i].porcentajeNubesCond-stats[10].STnubes),2);
    }
    varianzapersona/=tam;
    varianzatemperatura/=tam;
    varianzalluvia/=tam;
    varianzanieve/=tam;
    varianzanube/=tam;
     stats[14].STpersonas= varianzapersona;
    stats[14].STtemperatura= varianzatemperatura;
    stats[14].STnubes= varianzanube;
    stats[14].STlluvia= varianzalluvia;
    stats[14].STnieve= varianzanieve;
    //printf( "Varianzas %f\t %f\t %f\t %f\t %f\n",varianzapersona,varianzatemperatura,varianzalluvia,varianzanieve,varianzanube);
} 
void DesviacionEstandar(db *datos, int tam, stadistics *stats){
	float desp=0,dest=0,desl=0,desn=0,desnu=0;
	desp=sqrt(stats[4].STpersonas);
    desnu=sqrt(stats[4].STnubes);
    desl=sqrt(stats[4].STlluvia);
    desn=sqrt(stats[4].STnieve);
    dest=sqrt(stats[4].STtemperatura);
    stats[5].STpersonas= desp;
    stats[5].STtemperatura= dest;
    stats[5].STnubes= desnu;
    stats[5].STlluvia= desl;
    stats[5].STnieve= desn;
    //printf("desviaciones %f\t %f\t %f\t %f\t %f\n",desp,desnu,desl,desn,dest);
}
void desviacionEstandarCondicionada(db *datos, stadistics *stats){
    float desp=0,dest=0,desl=0,desn=0,desnu=0;
	desp=sqrt(stats[14].STpersonas);
    desnu=sqrt(stats[14].STnubes);
    desl=sqrt(stats[14].STlluvia);
    desn=sqrt(stats[14].STnieve);
    dest=sqrt(stats[14].STtemperatura);
    stats[15].STpersonas= desp;
    stats[15].STtemperatura= dest;
    stats[15].STnubes= desnu;
    stats[15].STlluvia= desl;
    stats[15].STnieve= desn;
    //printf("desviaciones %f\t %f\t %f\t %f\t %f\n",desp,desnu,desl,desn,dest);
}
void curtosis(db *datos, int tam, stadistics *stats){
    float curtosisp=0,curtosist=0,curtosisnu=0,curtosisn=0,curtosisl=0;
    int i;
    for(i=0;i<tam;i++){
        curtosisp+=pow((datos[i].personas-stats[1].STpersonas),4);
        curtosist+=pow((datos[i].temperatura-stats[1].STtemperatura),4);
        curtosisnu+=pow((datos[i].porcentajeNubes-stats[1].STnubes),4);
        curtosisn+=pow((datos[i].mmNieve-stats[1].STnieve),4);
        curtosisl+=pow((datos[i].mmLluvia-stats[1].STlluvia),4);
    }
    curtosisp/=tam;
    curtosist/=tam;
    curtosisnu/=tam;
    curtosisn/=tam;
    curtosisl/=tam;
     curtosisp/=(stats[4].STpersonas*stats[4].STpersonas);
    curtosist/=(stats[4].STtemperatura*stats[4].STtemperatura);
    curtosisnu/=(stats[4].STnubes*stats[4].STnubes);
    curtosisn/=(stats[4].STnieve*stats[4].STnieve);
    curtosisl/=(stats[4].STlluvia*stats[4].STlluvia);
    stats[6].STpersonas= curtosisp;
    stats[6].STtemperatura= curtosist;
    stats[6].STnubes= curtosisnu;
    stats[6].STlluvia= curtosisl;
    stats[6].STnieve= curtosisn;
 //   printf("curtosis %f\t %f\t %f\t %f\t %f\n",curtosisp,curtosist,curtosisnu,curtosisn,curtosisl);
}
void curtosisCondicionada(db *datos, stadistics *stats){
    float curtosisp=0,curtosist=0,curtosisnu=0,curtosisn=0,curtosisl=0;
    int i;
    int tam = datos[1].tamCond;
    for(i=0;i<tam;i++){
        curtosisp+=pow((datos[i].personasCond-stats[10].STpersonas),4);
        curtosist+=pow((datos[i].temperaturaCond-stats[10].STtemperatura),4);
        curtosisnu+=pow((datos[i].porcentajeNubesCond-stats[10].STnubes),4);
        curtosisn+=pow((datos[i].mmNieveCond-stats[10].STnieve),4);
        curtosisl+=pow((datos[i].mmLluviaCond-stats[10].STlluvia),4);
    }
    curtosisp/=tam;
    curtosist/=tam;
    curtosisnu/=tam;
    curtosisn/=tam;
    curtosisl/=tam;
     curtosisp/=(stats[14].STpersonas*stats[14].STpersonas);
    curtosist/=(stats[14].STtemperatura*stats[14].STtemperatura);
    curtosisnu/=(stats[14].STnubes*stats[14].STnubes);
    curtosisn/=(stats[14].STnieve*stats[14].STnieve);
    curtosisl/=(stats[14].STlluvia*stats[14].STlluvia);
    stats[16].STpersonas= curtosisp;
    stats[16].STtemperatura= curtosist;
    stats[16].STnubes= curtosisnu;
    stats[16].STlluvia= curtosisl;
    stats[16].STnieve= curtosisn;
    //printf("curtosis %f\t %f\t %f\t %f\t %f\n",curtosisp,curtosist,curtosisnu,curtosisn,curtosisl);
}
void coeficienteVariacion(db *datos, int tam, stadistics *stats){
    float CVp=0,CVt=0,CVnu=0,CVl=0,CVn=0;
    CVp=(stats[5].STpersonas)/fabs(stats[1].STpersonas);
     CVt=(stats[5].STtemperatura)/fabs(stats[1].STtemperatura);
      CVnu=(stats[5].STnubes)/fabs(stats[1].STnubes);
       CVl=(stats[5].STlluvia)/fabs(stats[1].STlluvia);
        CVn=(stats[5].STnieve)/fabs(stats[1].STnieve);
    stats[7].STpersonas= CVp;
    stats[7].STtemperatura= CVt;
    stats[7].STnubes= CVnu;
    stats[7].STlluvia= CVl;
    stats[7].STnieve= CVn;
   // printf("coeficiente Var %f\t %f\t %f\t %f\t %f\n",CVp,CVt,CVnu,CVl,CVn);
}
void coeficienteVariacionCondicionada(db *datos, stadistics *stats){
    float CVp=0,CVt=0,CVnu=0,CVl=0,CVn=0;
    int tam= datos[1].tamCond;
    CVp=(stats[15].STpersonas)/fabs(stats[10].STpersonas);
     CVt=(stats[15].STtemperatura)/fabs(stats[10].STtemperatura);
      CVnu=(stats[15].STnubes)/fabs(stats[10].STnubes);
       CVl=(stats[15].STlluvia)/fabs(stats[10].STlluvia);
        CVn=(stats[15].STnieve)/fabs(stats[10].STnieve);
    stats[17].STpersonas= CVp;
    stats[17].STtemperatura= CVt;
    stats[17].STnubes= CVnu;
    stats[17].STlluvia= CVl;
    stats[17].STnieve= CVn;
    //printf("coeficiente Var %f\t %f\t %f\t %f\t %f\n",CVp,CVt,CVnu,CVl,CVn);
}
//finalizan funciones estadisticas
//comienza lo de los dias
void mediaDia(db *datos, fecha *fei, hora*tim, stadistics *stats, int tam){
    int i;
    float mL=0,mM=0,mMi=0,mJ=0,mV=0,mS=0,mD=0; // para el flujo de personas
    for(i=0;i<tam;i++){
        if(fei[i].diaSemana == 1){ // domingo
            mD += datos[i].personas;
        }else if(fei[i].diaSemana == 2){
            mL += datos[i].personas;
        }else if(fei[i].diaSemana == 3){
            mM += datos[i].personas;
        }else if(fei[i].diaSemana == 4){
            mMi += datos[i].personas;
        }else if(fei[i].diaSemana == 5){
            mJ += datos[i].personas;
        }else if(fei[i].diaSemana == 6){
            mV += datos[i].personas;
        }else{
           // printf("es sabado");
            mS += datos[i].personas;
        }
    }
    mD/=tam;
    mL/=tam;
    mM/=tam;
    mMi/=tam;
    mJ/=tam;
    mV/=tam;
    mS/=tam;
    stats[18].STpersonas= mD;
    stats[19].STpersonas= mL;
    stats[20].STpersonas= mM;
    stats[21].STpersonas= mMi;
    stats[22].STpersonas= mJ;
    stats[23].STpersonas= mV;
    stats[24].STpersonas= mS;
   // printf("\nLa media del domingo es: %f %f %f %f %f %f sabado %f\n",mD,mL,mM,mMi,mJ,mV,mS);
}
//finaliza lo de los dias
void menu(db *datos, fecha *fei, hora *tim,int tam){
    int op,op2,celebracion,temperatura,nubes,personas;
    float tempT,lluvia,nieve;
    int dd,mm,yy;
    
    //variables para los rangos
    int dd1, dd2, mm1, mm2, yy1,yy2,personas1,personas2,nubes1,nubes2; 
    float lluvia1,lluvia2,nieve1,nieve2,temperatura1,temperatura2;
    int arTem;
    printf("============================================\n");
    printf("  =\t\t-BIENVENIDO-\t\t=\n");
    printf("============================================\n\n\n");
    printf("=\t-Metro Intersate Traffic Volume-\t=\n");


    printf("Deseas consultar un dato o un rango de datos?\n 1.- Un dato\n 2.- Rango de datos\n");
    scanf("%d",&op);
    switch (op)
    {
    case 1: // consulta de un dato
        printf("La consulta de datos puede generar mas de un valor\ndependiendo de tu busqueda\nConsultar por\n");
        printf("1.- Fecha\n2.- Celebracion\n3.- Temperatura\n4.- Milimetros de Lluvia\n5.- Miliemetros de nieve\n6.- Porcentaje de nubes\n");
        printf("7.- Flujo de personas\n");
        scanf("%d",&op2);
        switch (op2)
        {
            case 1: // fecha
            
                printf("Consulta de datos por fecha\nIngresa la fecha a buscar en el siguiente formado dd-mm-yy\n");
                scanf("%d-%d-%d",&dd,&mm,&yy);
                consultaFecha(datos,fei,tim,dd,mm,yy,tam);
            break;
            case 2: // celebracion
                printf("Celebracion no esta actualmente disponible\n");
                //mostrarCelebraciones(); // aqui tener las celebraciones guardadas para imprimirlas 
                //scanf("%d",&celebracion);
                exit(EXIT_SUCCESS);
            break;
            case 3: // temperatura
                printf("Ingresar temperatura por kelvin o en celcius?\n1.- Kelvin\n2.- Celcius\n");
                scanf("%d", &temperatura);
                if(temperatura == 1){ 
                    printf("Ingresa la temperatura\n");
                    scanf("%f",&tempT);
                    consultaTemperatura(tempT,datos,fei,tim,tam);
                }else{
                    //me la da en celcius
                    printf("Ingresa la temperatura\n");
                    scanf("%f",&tempT);
                    temperatura +=273;
                    consultaTemperatura(tempT,datos,fei,tim,tam);
                }
            break;
            case 4: // milimetros de lluvia
                printf("Ingresa los milimetros de lluvia\n");
                scanf("%f", &lluvia);
                consultaMilimetrosLluvia(lluvia, datos, fei, tim,tam);

            break;
            case 5: //Milimetros de nieve
                printf("Ingresa los milimetros de nieve\n");
                scanf("%f", &nieve);
                consultaMilimetrosNieve(nieve, datos, fei, tim,tam);
            break;
            case 6://porcentaje de nubes
                printf("Ingrese porcentaje de nubes\n");
                scanf("%d", &nubes);
                consultaPorcentajeNubes(nubes ,datos, fei,tim,tam);
            break;
            case 7:
                printf("Ingresa el flujo de personas\n");
                scanf("%d",&personas);
                consultaPersonas(personas, datos, fei, tim,tam);
            break;
        }
    break;
    case 2:// consulta de un rago de datos
        printf("1.- Fecha\n2.- Flujo de personas\n3.- Temperatura\n4.- Milimetros de Lluvia\n5.- Miliemetros de nieve\n6.- Porcentaje de nubes\n");
        scanf("%d",&op2);
        switch (op2)
        {
        case 1:
            printf("Ingresa el rango inferior de fecha dd-mm-yy\n");
            scanf("%d-%d-%d",&dd1,&mm1,&yy1);
            printf("Ingresa el rango superior de fecha dd-mm-yy\n");
            scanf("%d-%d-%d",&dd2,&mm2,&yy2);
            rangoFecha(dd1,mm1,yy1,dd2,mm2,yy2,datos,fei, tim,tam);

        break;
        case 2:
            printf("Ingresa el flujo inferior\n");
            scanf("%d",&personas1);
            printf("Ingresa el flujo superior\n");
            scanf("%d",&personas2);
            rangoFlujoPersonas(personas1,personas2,datos,fei,tim,tam);
        break;
        case 3:
            printf("Ingresarar temperaturas en kelvin o en celcius?\n1.- Kelvin\n2.- Celcius\n");
            scanf("%d",&arTem);
            if(arTem==1){ //kelvin
                printf("Ingresa temperatura inferior\n");
                scanf("%f",&temperatura1);
                printf("Ingresa temperatura superior\n");
                scanf("%f",&temperatura2);
                rangoTemperatura(temperatura1,temperatura2,datos,fei,tim,tam);
            }else{
                printf("Ingresa temperatura inferior\n");
                scanf("%f",&temperatura1);
                printf("Ingresa temperatura superior\n");
                scanf("%f",&temperatura2);
                temperatura1+=273;
                temperatura2+=273;
                rangoTemperatura(temperatura1,temperatura2,datos,fei,tim,tam);
            }
        break;
        case 4: //milimetros de lluvia
            printf("Ingresa el limite inferior para mm de lluvia\n");
            scanf("%f",&lluvia1);
            printf("Ingresa el limite superior para mm de lluvia\n");
            scanf("%f",&lluvia2);
            rangoLluvia(lluvia1,lluvia2,datos,fei,tim,tam);
        break;
        case 5://milimetros de nieve
            printf("Ingrese el limite inferior para mm de nieve\n");
            scanf("%d",&nieve1);
            printf("Ingresa el limite superior para mm de nieve\n");
            scanf("%d",&nieve2);
            rangoNieve(nieve1,nieve2,datos,fei,tim,tam);
        break;
        case 6://porcentaje de nubes
            printf("Ingresa el limite inferior de nubes\n");
            scanf("%d",&nubes1);
            printf("Ingresa el limite superior de nubes\n");
            scanf("%d",&nubes2);
            rangoNubes(nubes1 , nubes2,datos,fei,tim,tam);
        break;
        }
    break;
    
    default:
    menu(datos, fei, tim,tam);
    break;
    }
    

}
void generarReporte(db *datos, fecha *fei, hora *tim, stadistics *stats, int tam){
    FILE *report;
    report =fopen("reporte.txt","wt");
    if(report == NULL){
        printf("reporte mal generado");
        //return 1;
    }
    fputs("============================================\n",report);
    fputs("  =\t\t-BIENVENIDO-\t\t=\n",report);
    fputs("============================================\n\n\n",report);
    fputs("=\t-Metro Intersate Traffic Volume-\t=\n\n",report);

    fputs("Reporte de datos y estadisticas\n\n",report);
    fputs("Metro_Interstate_Traffic_Volume\n\n",report);
    fputs("Reporte basado en la consulta o rango de datos introducidos por el usuario\n",report);
    fputs("Estadisticas\n\n",report);
    fprintf(report,"Flujo medio: %d\n",stats[1].STpersonas);
    fprintf(report,"Temperatura media: %f\n",stats[1].STtemperatura);
    fprintf(report,"Lluvia media: %f\n",stats[1].STlluvia);
    fprintf(report,"Nieve media: %f\n",stats[1].STnieve);
    fprintf(report,"Porcentaje de nubes medio: %f\n",stats[1].STnubes);
    fputs("============================================================\n",report);
    fprintf(report,"Flujo maximo: %d\n",stats[2].STpersonas);
    fprintf(report,"Temperatura maxima: %f\n",stats[2].STtemperatura);
    fprintf(report,"Lluvia maxima: %f\n",stats[2].STlluvia);
    fprintf(report,"Nieve maxima: %f\n",stats[2].STnieve);
    fprintf(report,"Porcentaje de nubes maximo: %f\n",stats[2].STnubes);
    fputs("============================================================\n",report);
    fprintf(report,"Flujo minimo: %d\n",stats[3].STpersonas);
    fprintf(report,"Temperatura minimo: %f\n",stats[3].STtemperatura);
    fprintf(report,"Lluvia minimo: %f\n",stats[3].STlluvia);
    fprintf(report,"Nieve minimo: %f\n",stats[3].STnieve);
    fprintf(report,"Porcentaje de nubes mainimo: %f\n",stats[3].STnubes);
    fputs("============================================================\n",report);
    fprintf(report,"Flujo varianza: %d\n",stats[4].STpersonas);
    fprintf(report,"Temperatura varianza: %f\n",stats[4].STtemperatura);
    fprintf(report,"Lluvia varianza: %f\n",stats[4].STlluvia);
    fprintf(report,"Nieve varianza: %f\n",stats[4].STnieve);
    fprintf(report,"Porcentaje de nubes varianza: %f\n",stats[4].STnubes);
    fputs("============================================================\n",report);
    fprintf(report,"Flujo varianza: %d\n",stats[5].STpersonas);
    fprintf(report,"Temperatura varianza: %f\n",stats[5].STtemperatura);
    fprintf(report,"Lluvia varianza: %f\n",stats[5].STlluvia);
    fprintf(report,"Nieve varianza: %f\n",stats[5].STnieve);
    fprintf(report,"Porcentaje de nubes varianza: %f\n",stats[5].STnubes);
    fputs("============================================================\n",report);
    fprintf(report,"Flujo curtosis: %d\n",stats[6].STpersonas);
    fprintf(report,"Temperatura curtosis: %f\n",stats[6].STtemperatura);
    fprintf(report,"Lluvia curtosis: %f\n",stats[6].STlluvia);
    fprintf(report,"Nieve curtosis: %f\n",stats[6].STnieve);
    fprintf(report,"Porcentaje de nubes curtosis: %f\n",stats[6].STnubes);
    fputs("============================================================\n",report);
    fprintf(report,"Flujo coeficiente de variacion: %d\n",stats[7].STpersonas);
    fprintf(report,"Temperatura coeficiente de variacion: %f\n",stats[7].STtemperatura);
    fprintf(report,"Lluvia coeficiente de variacion: %f\n",stats[7].STlluvia);
    fprintf(report,"Nieve coeficiente de variacion: %f\n",stats[7].STnieve);
    fprintf(report,"Porcentaje de nubes coeficiente de variacion: %f\n",stats[7].STnubes);
    fputs("============================================================\n",report);
    fprintf(report,"Flujo coeficiente de mediana: %d\n",stats[8].STpersonas);
    fprintf(report,"Temperatura coeficiente de mediana: %f\n",stats[8].STtemperatura);
    fprintf(report,"Lluvia coeficiente de mediana: %f\n",stats[8].STlluvia);
    fprintf(report,"Nieve coeficiente de mediana: %f\n",stats[8].STnieve);
    fprintf(report,"Porcentaje de nubes coeficiente de mediana: %f\n",stats[8].STnubes);
    fputs("============================================================\n",report);
    fprintf(report,"Flujo media condicionada: %d\n",stats[10].STpersonas);
    fprintf(report,"Temperatura media condicionada: %f\n",stats[10].STtemperatura);
    fprintf(report,"Lluvia media condicionada: %f\n",stats[10].STlluvia);
    fprintf(report,"Nieve  media condicionada: %f\n",stats[10].STnieve);
    fprintf(report,"Porcentaje media condicionada: %f\n",stats[10].STnubes);
    fputs("============================================================\n",report);
    fprintf(report,"Flujo maximo condicionada: %d\n",stats[11].STpersonas);
    fprintf(report,"Temperatura maximo condicionada: %f\n",stats[11].STtemperatura);
    fprintf(report,"Lluvia maximo condicionada: %f\n",stats[11].STlluvia);
    fprintf(report,"Nieve maximo condicionada: %f\n",stats[11].STnieve);
    fprintf(report,"Porcentaje maximo condicionada: %f\n",stats[11].STnubes);
    fputs("============================================================\n",report);
    fprintf(report,"Flujo minimo condicionada: %d\n",stats[12].STpersonas);
    fprintf(report,"Temperatura minimo condicionada: %f\n",stats[12].STtemperatura);
    fprintf(report,"Lluvia minimo condicionada: %f\n",stats[12].STlluvia);
    fprintf(report,"Nieve minimo condicionada: %f\n",stats[12].STnieve);
    fprintf(report,"Porcentaje minimo condicionada: %f\n",stats[12].STnubes);
    fputs("============================================================\n",report);
    fprintf(report,"Flujo mediana condicionada: %d\n",stats[13].STpersonas);
    fprintf(report,"Temperatura mediana condicionada: %f\n",stats[13].STtemperatura);
    fprintf(report,"Lluvia mediana condicionada: %f\n",stats[13].STlluvia);
    fprintf(report,"Nieve mediana condicionada: %f\n",stats[13].STnieve);
    fprintf(report,"Porcentaje mediana condicionada: %f\n",stats[13].STnubes);
    fputs("============================================================\n",report);
    fprintf(report,"Flujo varianza condicionada: %d\n",stats[14].STpersonas);
    fprintf(report,"Temperatura varianza condicionada: %f\n",stats[14].STtemperatura);
    fprintf(report,"Lluvia varianza condicionada: %f\n",stats[14].STlluvia);
    fprintf(report,"Nieve varianza condicionada: %f\n",stats[14].STnieve);
    fprintf(report,"Porcentaje varianza condicionada: %f\n",stats[14].STnubes);
    fputs("============================================================\n",report);
    fprintf(report,"Flujo desviacion condicionada: %d\n",stats[15].STpersonas);
    fprintf(report,"Temperatura desviacion condicionada: %f\n",stats[15].STtemperatura);
    fprintf(report,"Lluvia desviacion condicionada: %f\n",stats[15].STlluvia);
    fprintf(report,"Nieve desviacion condicionada: %f\n",stats[15].STnieve);
    fprintf(report,"Porcentaje desviacion condicionada: %f\n",stats[15].STnubes);
    fputs("============================================================\n",report);
    fprintf(report,"Flujo curtosis condicionada: %d\n",stats[16].STpersonas);
    fprintf(report,"Temperatura curtosis condicionada: %f\n",stats[16].STtemperatura);
    fprintf(report,"Lluvia curtosis condicionada: %f\n",stats[16].STlluvia);
    fprintf(report,"Nieve curtosis condicionada: %f\n",stats[16].STnieve);
    fprintf(report,"Porcentaje curtosis condicionada: %f\n",stats[16].STnubes);
    fputs("============================================================\n",report);
    fprintf(report,"Flujo coeficiente de variacion condicionada: %d\n",stats[17].STpersonas);
    fprintf(report,"Temperatura coeficiente de variacion condicionada: %f\n",stats[17].STtemperatura);
    fprintf(report,"Lluvia coeficiente de variacion condicionada: %f\n",stats[17].STlluvia);
    fprintf(report,"Nieve coeficiente de variacion condicionada: %f\n",stats[17].STnieve);
    fprintf(report,"Porcentaje coeficiente de variacion condicionada: %f\n",stats[17].STnubes);
    fputs("============================================================\n",report);
    fprintf(report,"Flujo medio de las personas en Domingo: %d\n",stats[18].STpersonas);
    fprintf(report,"Flujo medio de las personas en Lunes: %d\n",stats[19].STpersonas);
    fprintf(report,"Flujo medio de las personas en Martes: %d\n",stats[20].STpersonas);
    fprintf(report,"Flujo medio de las personas en Miercoles: %d\n",stats[21].STpersonas);
    fprintf(report,"Flujo medio de las personas en Jueves: %d\n",stats[22].STpersonas);
    fprintf(report,"Flujo medio de las personas en Viernes: %d\n",stats[23].STpersonas);
    fprintf(report,"Flujo medio de las personas en Sabado: %d\n",stats[24].STpersonas);
    fputs("\n\tDATOS ANALIZADOS\n",report);
    fputs("\n\tFormato de retorno de datos:\n",report);
    fputs("\n\tTemperatura mmLluvia mmNieve dd-mm-yy hh:mm:ss FlujoPersonas \n",report);
    int i;
    for(i=0;i<datos[1].tamCond;i++){
        fprintf(report,"%f %f %f %d-%d-%d %d:%d:%d %d   \n",datos[i].temperatura, datos[i].mmLluviaCond,datos[i].mmNieveCond,fei[i].diaCond,fei[i].mesCond,fei[i].anioCond,tim[i].horaCond,tim[i].minutos,tim[i].segundos,datos[i].personasCond);
    }
    fflush(report);
    fclose(report);
    printf("Reporte generado");
}
int main(int argc, char *argv[]){
    
    if(argc<2){
        printf("Olvidó introducir el nombre del archivo");
        return 0;
    }
    

    
    printf("Analisis Trenes\nPoner el archivo de la base de datos al lado del ejecutable\n");
    char ruta,caracter[125];
    int op, tam=0, i;
    FILE * archivo;
    int*clouds, *tV;
    float *temp, *rain, *snow ;
    char *holiday, *wm, *wd, *dateTime;
  
    archivo = fopen(argv[1], "rt");
    if(archivo == NULL){
        printf("Hubo un problema al abrir el archivo\n");
        return 1;
    }
    db *datos;
    fecha *fei;
    hora *tim;
    stadistics *stats;
    tam = tamanio(archivo);
    datos = (db*)calloc(tam,sizeof(db));
    fei = (fecha*)malloc(tam*sizeof(fecha));
    tim = (hora*)malloc(tam*sizeof(hora));
    stats = (stadistics*)malloc(tam*sizeof(stadistics));
    fgets(caracter,500,archivo);
    precargaDatos(archivo, datos);
    rewind(archivo);
    fgets(caracter,500,archivo);
    precargaCadenas(archivo, datos,fei, tim);
    determinarDiaSemana(tam,fei);
    printf("\nDATOS PRECARGADOS CORRECTAMENTE\n");
    menu(datos, fei,tim,tam);

    media(datos, tam,stats);
    mediaCondicionada(datos,stats);

    maximos(datos, tam,stats);
    maximoCondicionado(datos, stats);

    minimo(datos, tam,stats);
    minimoCondicionado(datos, stats);

    mediana(datos,tam,stats,fei,tim);
    medianaCondicionada(datos,stats,fei,tim);

    varianza(datos, tam,stats);
    varianzaCondicionada(datos,stats);

    DesviacionEstandar(datos, tam,stats);
    desviacionEstandarCondicionada(datos,stats);

    curtosis(datos,tam,stats);
    curtosisCondicionada(datos,stats);

    coeficienteVariacion(datos,tam,stats);
    coeficienteVariacionCondicionada(datos,stats);

    mediaDia(datos,fei,tim,stats,tam);
    generarReporte(datos,fei,tim,stats,tam);
     

    fclose(archivo);
    free(datos);
    free(fei);
    free(tim);
    free(stats);
    
    
    return 0;
}