#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>//Random

void AltEnter(){
    keybd_event(VK_MENU,
                0x38,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                KEYEVENTF_KEYUP,
                0);
    keybd_event(VK_MENU,
                0x38,
                KEYEVENTF_KEYUP,
                0);
    return;
}
void Bienvenida (){
    printf("\n        Preparate para ser el proximo millonario!\n\n Te damos la bienvenida a \"QUIEN QUIERE SER MILLONARIO?\"\n El juego de antiguo y respuestas mas emblematico de la television. Ponte a prueba y demuestra tus conocimientos en temas generales y especializados\n para ganar el gran premio!\n\n\n Listo para comenzar?\n\n\n\n\n (Pulse ENTER para continuar)");
    getchar();
    system("cls");
    return;
}
void Reglas (){
    printf("\n            REGLAS\n\n El juego Quien quiere ser millonario? Consiste en quince (15) antiguo que deben ser respondidas correctamente para ganar la suma de UN MILLON DE DOLARES!\n Cada respuesta correcta aumenta el premio final. Si el participante responde de manera incorrecta, se lleva la mitad del premio.\n El juego tiene dos CHECKPOINTS, que le aseguran al participante que se lleva esa cantidad de dinero si o si. Antes de cada pregunta, el participante puede elegir si\n continuar o irse con el premio acumulado.\n");
    printf("\n 1. 100 USD                                9.  16 mil USD\n 2. 200 USD                                10. 32 mil USD (CHECKPOINT)\n 3. 300 USD                                11. 64 mil USD\n 4. 500 USD                                12. 125 mil USD\n 5. 1.000 USD (CHECKPOINT)                 13. 250 mil USD\n 6. 2.000 USD                              14. 500 mil USD\n 7. 4.000 USD                              14. 1 millon USD\n 8. 8.000 USD\n\n\n\n\n (Pulse ENTER para continuar)");
    getchar();
    system("cls");
    return;
}
int Eleccion(int puntaje, int puntaje_ranking){
    int x;
    printf("\n\n Es MOMENTO DE ELEGIR...\n\n 1) Te quedas con tu puntuaje actual y te retiras                                 2) Sigues jugando y participando de la posibilidad de mas premios\n\n\n Tu puntaje actual es de: %d USD\n\n Ranking de la sesion %d USD\n\n RESPUESTA: ", puntaje, puntaje_ranking);
    scanf("%d", &x); fflush(stdin); system("cls");
    return x;
}
int PuntajePerdido(int puntaje, int checkpont){
    if (puntaje == 0){
        return 0;
    }else{
        return ((puntaje - checkpont)/2)+checkpont;
    }

}
int PuntajeGanado(int numPregunta, int puntaje, int checkpont){
    if (numPregunta <= 3){
        return (puntaje + 100);
    }

    if (numPregunta == 4){
        return (puntaje + 200);
    }

    // Del 5 al 11 || 13 al 14, comparten la misma fórmula
    if (((numPregunta >= 5)&&(numPregunta <= 11))||((numPregunta >= 13)&&(numPregunta <= 15))){
        return (puntaje * 2);
    }

    if (numPregunta == 12){
        //Para alcanzar los 125.000
        return puntaje + 61000;
    }

}

struct{
    char nombre[20];
    int puntaje;
}ranking[11];
struct{
    char pregunta[1000];
    char opciones[1000];
}preguntas[30];


int main(){
    int menu, i, j, numpreguntas[15], puntaje, checkpoint, repetido, auxx, w, flag, respuesta, rtaa[30], puntaje_mostrar;
    char aux[20], usuario_actual[20];

    puntaje = checkpoint = menu = 0;
    srand(time(0));
    //Iniciar programa en pantalla completa
    AltEnter();
    //Pantalla de Bienvenida y Reglas
    Bienvenida();
    Reglas();

    //Menú principal
    do
    {
        printf(" \n \"QUIEN QUIERE SER MILLONARIO?\"\n\n\n");
        printf(" 1. Juego nuevo\n\n 2. Ranking\n\n 3. Nombre del jugador\n\n 4. Reglas\n\n 5. Salir\n\n\n");
        scanf("%d", &menu); fflush(stdin); system("cls");

        //<-- Carga de ranking -->
        FILE *ARCHIVO_RANKING = fopen("ranking.txt", "r");
        if (ARCHIVO_RANKING == NULL) {
            printf("ERROR AL CARGAR EL ARCHIVO \"ranking.txt\"\n");
            fclose(ARCHIVO_RANKING);
        } else {
            for (i = 0; i < 10; i++) {
                fgets(ranking[i].nombre, 1000, ARCHIVO_RANKING);
                ranking[i].nombre[strcspn(ranking[i].nombre, "\n")] = '\0';
                fscanf(ARCHIVO_RANKING, "%d\n", &ranking[i].puntaje);
            }
            fclose(ARCHIVO_RANKING);
        }

        if (menu == 1){
            if (flag == 0){
                printf("\n\n Ingrese su nombre en la seccion \"Nombre del jugador\"\n\n");
                getchar(); system("cls");
            }else
            {
                FILE *fp = fopen("preguntas.txt", "r");
                FILE * rta = fopen("rta.txt", "r");
                if (rta == NULL)
                {
                    printf(" ERROR AL CARGAR EL ARCHIVO \"rta.txt\"\n");
                    getchar(); system("cls");
                }

                if (fp == NULL)
                {
                    printf(" ERROR AL CARGAR EL ARCHIVO \"preguntas.txt\"\n");
                    getchar(); system("cls");
                    fclose(fp);
                }else
                {
                    // Lectura del archivo para ALMACENAR PREGUNTAS Y OPCIONES.
                    for (i = 0; i < 30; i++){
                        fgets(preguntas[i].pregunta, 1000, fp);
                        preguntas[i].pregunta[strcspn(preguntas[i].pregunta, "\n")] = '\0';
                        fgets(preguntas[i].opciones, 1000, fp);
                        preguntas[i].opciones[strcspn(preguntas[i].opciones, "\n")] = '\0';
                        fscanf(rta, "%d", &rtaa[i]);
                    }
                    fclose(fp);
                    fclose(rta);


                    //<-- Generar los 10 números sin repetir -->
                    for (i = 0; i < 15; i++) {
                        //1 = true || 0 = false

                        // Generar un número aleatorio
                        numpreguntas[i] = rand() % 30;

                        // Verificar si el número ya existe en el arreglo
                        repetido = 0;
                        for (j = 0; j < i; j++) {
                            if (numpreguntas[i] == numpreguntas[j]) {
                                repetido = 1;
                                j = 50;
                            }
                        }
                        // Si el número está repetido, generar otro número nuevo y va a volver a comparar todo de nuevo
                        if (repetido) {
                            i--;
                        }
                    }

                    //<-- Juego en sí -->
                    for (w=0; w < 15; w++){
                        printf("\t\n Pregunta numero %d\n\n", w+1);
                        //Pregunta numero aleatorio [numpreguntas]
                        puts(preguntas[numpreguntas[w]].pregunta);
                        printf("\n\n");
                        puts(preguntas[numpreguntas[w]].opciones);
                        printf("\n");
                        scanf("%d", &respuesta); fflush(stdin); system("cls");
                        if (respuesta == rtaa[numpreguntas[w]]){
                            //Respuesta correcta, se le asigna el puntaje correspondiente
                            puntaje = PuntajeGanado(w+1, puntaje, checkpoint);
                            //CHECKPOINTS
                            if (w+1 == 5){
                                printf("\t\n CHECKPOINT \n");
                                checkpoint = 1000;
                            }else if (w+1 == 10){
                                printf("\t\n CHECKPOINT \n");
                                checkpoint = 32000;
                            }
                            //Si el usuario desea continuar o no
                            if ((Eleccion(puntaje, ranking[0].puntaje) == 1)&&(w != 14)){
                                //Aumento "w" para romper el ciclo
                                w = 20;
                            }
                        }else{
                            //Respuesta incorrecta :(
                            puntaje = PuntajePerdido(puntaje, checkpoint);
                            printf("\n RESPUESTA INCORRECTA :(, vuelve a intentarlo!\n\n");
                            printf("\n Fallaste en la pregunta %d y tu puntaje es de: %d USD\n\n", w+1, puntaje);

                            printf("\n\n\n\n\n (Pulse ENTER para salir)");
                            getchar(); system("cls");
                            //Aumento "i" para romper el ciclo
                            w = 20;
                        }
                        //Mensaje de ganador
                        if (w == 14){
                            printf("\n \"Felicitaciones! Eres el ganador o ganadora del juego \"Quien quiere ser millonario?\".\n\n\n Has demostrado un gran conocimiento y habilidad para responder correctamente a las preguntas,\n y has alcanzado el objetivo final de ganar un millon de dolares. Esto es un logro increible\n que muy pocas personas pueden alcanzar, y te mereces todas las felicitaciones y el reconocimiento\n por tu esfuerzo y dedicacion. Espero que este premio cambie tu vida y te permita cumplir todos\n tus deseos y metas. Disfruta de tu merecida victoria!\"\n\n\n MUCHAAACHOS AHORA NOS VOLVIMOS A ILUSIONAR\n");
                            printf("\n\n\n\n (Pulse ENTER para salir)");
                            getchar(); system("cls");
                        }
                    }//Llave del FOR DE PREGUNTAS
                }//Llave del IF DE PREGUNTAS

                //<-- SISTEMA DE RANKING -->
                for(i = 0; i < 10; i++)
                {
                    //Puntaje
                    if (puntaje > ranking[i].puntaje){
                        ranking[10].puntaje = puntaje;
                        printf("\n Felicitaciones! %s ERES EL NUEVO TOP %d en el juego\n\n Tu cantidad de puntos fue de %d USD \n\n\n\n\n (Pulse ENTER para salir al menu)", ranking[10].nombre, i+1, ranking[10].puntaje);
                        getchar(); system("cls");
                        //-Metodo burbuja para ordenar el ranking
                        for (w = 0; w < 10; w++) {
                            for (j = 0; j < 10; j++) {
                                if (ranking[j].puntaje <= ranking[j+1].puntaje) {
                                    // Puntaje
                                    auxx = ranking[j].puntaje;
                                    ranking[j].puntaje = ranking[j+1].puntaje;
                                    ranking[j+1].puntaje = auxx;
                                    // Nombre
                                    strcpy(aux, ranking[j].nombre);
                                    strcpy(ranking[j].nombre, ranking[j+1].nombre);
                                    strcpy(ranking[j+1].nombre, aux);
                                }
                            }
                        }
                        //Aumento "i" para romper el ciclo
                        i = 20;
                    }

                }
                for ( w = 0; w < 10; w++)
                {
                    //-Copiar el nuevo ranking en el txt
                    FILE * ARCHIVO_RANKING = fopen("ranking.txt", "w");
                    if (ARCHIVO_RANKING == NULL)
                    {
                        printf("ERROR AL CARGAR EL ARCHIVO (Para copiar el ranking) \"ranking.txt\"\n");
                        fclose(ARCHIVO_RANKING);
                    }else{
                        for (w = 0; w < 10; w++) {
                        fprintf(ARCHIVO_RANKING, "%s\n", ranking[w].nombre);
                        fprintf(ARCHIVO_RANKING, "%d\n", ranking[w].puntaje);
                        }
                        fclose(ARCHIVO_RANKING);
                    }
                    //Aumento "i" para romper el ciclo
                    i = 20;
                }
                
                //Por si el usuario desea entra a nombre y quiere consultar su ultimo puntaje
                puntaje_mostrar = puntaje;
                //Reinicio de los puntajes
                puntaje = checkpoint = 0;
            }
        }//Llave del if MENU
        if(menu == 2){
            //Ranking de la sesión
            printf("\n |  RANKING  |\n\n");
            for (i = 0; i < 10; i++){
                printf("%d. %s                      %d USD\n", i+1, ranking[i].nombre, ranking[i].puntaje);
            }
            printf("\n\n\n\n\n (Pulse ENTER para salir)");
            getchar(); system("cls");
        }
        if (menu == 3){
            if (flag != 1){
                printf("\n Ingrese el nombre de usuario: \n\n");
                ranking[10].puntaje = 0;
                gets(ranking[10].nombre); system("cls");
                ranking[10].nombre[strcspn(ranking[10].nombre, "\n")] = '\0';
                printf("\n Bienvenido %s a la sesion! \n\n (Pulse ENTER para continuar) \n\n", ranking[10].nombre);
                getchar(); fflush(stdin); system("cls");
                strcpy(usuario_actual, ranking[10].nombre);
                flag = 1;
            }else{
                printf("\n Tu nombre de usuario es %s y tu ultimo puntaje fue de %d USD \n\n Recuerda que para cambiar de usuario es necesario reiniciar el juego. \n\n (Pulse ENTER para continuar) \n\n", usuario_actual, puntaje_mostrar);
                getchar(); system("cls");
            }
        }
        if (menu == 4){
            Reglas();
        }
        if (menu == 5){
            printf("\n Gracias por jugar!\n\n (Pulse ENTER para salir) \n\n");
            getchar(); system("cls");
            break;
        }
        /* Volver a copiar el nombre por si vuelve a jugar.
        strcpy(ranking[10].nombre, usuario_actual);
        ranking[10].nombre[strcspn(ranking[10].nombre, "\n")] = '\0'; */
    }while (menu != 5);
    return 0;
}
