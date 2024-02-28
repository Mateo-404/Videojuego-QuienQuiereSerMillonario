#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
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

int main()
{
    short unsigned int menu, preguntas, ganador;
    int puntaje, puntaje_ranking, checkpoint;
    puntaje = puntaje_ranking = checkpoint = 0;
    char respuesta, participar, let1 = '?', let2 = '?', let3 = '?';
    //Iniciar programa en pantalla completa
    AltEnter();
    //Pantalla de Bienvenida
    printf("\n        Preparate para ser el proximo millonario!\n\n Te damos la bienvenida a \"QUIEN QUIERE SER MILLONARIO?\"\n El juego de preguntas y respuestas mas emblematico de la television. Ponte a prueba y demuestra tus conocimientos en temas generales y especializados\n para ganar el gran premio!\n\n\n Listo para comenzar?\n\n\n\n\n (Pulse ENTER para continuar)");
    getchar(); system("cls");
    //Reglas
    printf("\n            REGLAS\n\n El juego Quien quiere ser millonario? Consiste en quince (15) preguntas que deben ser respondidas correctamente para ganar la suma de UN MILLON DE DOLARES!\n Cada respuesta correcta aumenta el premio final. Si el participante responde de manera incorrecta, se lleva la mitad del premio.\n El juego tiene dos CHECKPOINTS, que le aseguran al participante que se lleva esa cantidad de dinero si o si. Antes de cada pregunta, el participante puede elegir si\n continuar o irse con el premio acumulado.\n");
    //Puntajes (Lo separo para que sea m�s legible el c�digo)
    printf("\n 1. 100 USD                                9.  16 mil USD\n 2. 200 USD                                10. 32 mil USD (CHECKPOINT)\n 3. 300 USD                                11. 64 mil USD\n 4. 500 USD                                12. 125 mil USD\n 5. 1.000 USD (CHECKPOINT)                 13. 250 mil USD\n 6. 2.000 USD                              14. 500 mil USD\n 7. 4.000 USD                              14. 1 millon USD\n 8. 8.000 USD\n\n\n\n\n (Pulse ENTER para continuar)");
    getchar(); system("cls");
    //Menu principal
    do{
        printf(" \n \"QUIEN QUIERE SER MILLONARIO?\"\n\n\n");
        printf(" 1. Juego nuevo\n\n 2. Ranking\n\n 3. Salir\n\n ");
        scanf("%hu", &menu); fflush(stdin); system("cls");
        if (menu == 1)
        {
                for (preguntas = 1; preguntas <= 15; preguntas++){
                    switch (preguntas){
                    case 1:
                        //Pregunta 1
                        printf("\n 1. Empecemos con una pregunta sencilla... \"Quien fue el primer presidente argentino?\"\n\n a) Juan Manuel de Rosas                            c) Domingo Faustino Sarmiento\n b) Bartolome Mitre                                 d) Bernardino Rivadavia\n\n RESPUESTA: ");
                        scanf("%c", &respuesta); fflush(stdin); system("cls");
                        if (respuesta == 'd'){
                            //Respuesta Correcta
                            puntaje += 100;
                            ganador = 1;
                            printf("\n RESPUESTA CORRECTA, Eres una persona muy informada en la historia argentina!\n\n");
                        }else{
                            ganador = 9;
                        }
                        break;
                    case 2:
                        //Pregunta 2
                            printf("\n 2. Suerte de principiante, veremos como te va ahora... \"Quien fue el lider y vocalista de la mitica banda de rock argentino Soda Stereo?\"\n\n a) Gustavo Cerati                                c) Andres Calamaro\n b) Charly Garcia                                 d) Fito Paez\n\n RESPUESTA:  ");
                            scanf("%c", &respuesta); fflush(stdin); system("cls");
                            if (respuesta == 'a'){
                                //RESPUESTA CORRECTA
                                puntaje += 100;
                                printf("\n RESPUESTA CORRECTA, Vaya, vaya! No solo eres un/a experto/a en historia argentina, sino que tambi�n tienes buen gusto musical\n\n");
                            }else{
                                ganador = 9;}
                        break;
                    case 3:
                        //Pregunta 3
                        printf("\n 3. Ahora te pondremos a prueba en matematicas: \"2+5*2-2\" Cual seria el resultado en C?:\n\n a) 7                                  c) 0\n b) 10                                 d) 8\n\n RESPUESTA: ");
                        scanf("%c", &respuesta); fflush(stdin); system("cls");
                        if (respuesta == 'b'){
                                //RESPUESTA CORRECTA
                                printf("\n RESPUESTA CORRECTA, ya puedes guardar la calculadora\n\n");
                                puntaje += 100;
                                }else{
                                    ganador = 9;}
                                    break;

                    case 4:
                        //Pregunta 4
                        printf("\n 4. Respondeme... Que es un \"software\" en informatica?\n\n a) Es un componente fisico de una computadora                                \n\n b) Es un lenguaje de programacion utilizado para crear aplicaciones\n\n c) Es un conjunto de programas y datos que le permiten a la computadora realizar una tarea especifica                                \n\n d) Es un dispositivo de entrada utilizado para interactuar con la computadora\n\n RESPUESTA: ");
                        scanf("%c", &respuesta); fflush(stdin); system("cls");
                        if (respuesta == 'c'){
                            //RESPUESTA CORRECTA
                            puntaje += 200;
                            printf("\n RESPUESTA CORRECTA, Eres una verdadera enciclopedia ambulante!\n\n");
                        }else{
                            ganador = 9;
                        }
                        break;
                    case 5:
                        //Pregunta 5 (CHECKPOINT)
                        printf("\n 5. A veces miro el cielo y me pregunto... \"Cual es el planeta mas cercano al sol?\"\n\n a) Venus                                     c) Marte\n b) Mercurio                                  d) Jupiter\n\n RESPUESTA: ");
                        scanf("%c", &respuesta); fflush(stdin); system("cls");
                        if (respuesta == 'b'){
                            puntaje = 1000;
                            checkpoint = 1000;
                            printf("\n RESPUESTA CORRECTA, llegaste al CHECKPOINT\n\n");
                            }else{
                                ganador = 9;
                            }
                        break;
                    case 6:
                        //Pregunta 6
                         printf("\n 6. Los cuadros siempre me llamaron la atencion. Sabes quien es el autor de \"La noche estrellada\"?\n\n a) Salvador Dali                                 c) Claude Monet\n b) Pablo Picasso                                 d) Vincent van Gogh\n\n RESPUESTA: ");
                         scanf("%c", &respuesta); fflush(stdin); system("cls");
                         if (respuesta == 'd'){
                            puntaje += 1000;
                            printf("\n RESPUESTA CORRECTA, parece que a ambos nos llama la atencion el arte!\n\n");
                            }else{
                                ganador = 9;
                            }
                            break;
                    case 7:
                        //Pregunta 7
                        printf("\n 7. Pregunta de Tecnologia: Que empresa es conocida por su sistema operativo Windows?\n\n a) Apple                                  c) Amazon\n b) Google                                 d) Microsoft\n\n RESPUESTA: ");
                        scanf("%c", &respuesta); fflush(stdin); system("cls");
                        if (respuesta == 'd'){
                            puntaje *= 2;
                            printf("\n RESPUESTA CORRECTA, me sorprende lo actualizado que te encuentras...\n");
                        }else{
                            ganador = 9;
                        }
                        break;
                    case 8:
                        //Pregunta 8
                        printf("\n 8. Espero que te guste la musica...\"Quien es el cantante y compositor de \"Bohemian Rhapsody\" de la banda Queen?\"\n\n a) Freddie Mercury                             c) Mick Jagger\n b) David Bowie                                 d) Elton John\n\n RESPUESTA: ");
                        scanf("%c", &respuesta); fflush(stdin); system("cls");
                        if (respuesta = 'a'){
                            puntaje *= 2;
                            printf("\n Is this the real life? Is this just fantasy?\n\n");
                        }else{
                            ganador = 9;
                        }
                        break;
                    case 9:
                        //Pregunta 9
                        printf("\n 9. Imagina que un cientifico te pregunta... Cual es el simbolo quimico del agua?\n\n a) H2SO4                               c) CO2\n b) H2O                                 d) NaCl\n\n RESPUESTA: ");
                        scanf("%c", &respuesta); fflush(stdin); system("cls");
                        if (respuesta == 'b'){
                            puntaje *= 2;
                            printf("\n RESPUESTA CORRECTA, al parecer todas las areas se te dan bien...\n");
                        }else{
                            ganador = 9;
                        }
                        break;
                    case 10:
                        //Pregunta 10 (CHECKPOINT)
                        printf("\n 10. Llegaste al checkpoint!...Quien es el actual presidente de los Estados Unidos?\n\n a) Barack Obama                              c) Hillary Clinton\n b) Joe Biden                                 d) Donald Trump\n\n RESPUESTA: ");
                        scanf("%c", &respuesta); fflush(stdin); system("cls");
                        if (respuesta == 'b'){
                            printf("\n RESPUESTA CORRECTA, es importante estar actualizado con lo que sucede en el mundo!");
                            puntaje = 32000;
                            checkpoint = 32000;
                        }else{
                            ganador = 9;
                        }
                        break;
                    case 11:
                        printf("\n 11. El final se encuentra cada vez mas cerca... Quien es el autor de \"El Quijote\"?\n\n a) Miguel de Cervantes                                 c) Pablo Neruda\n b) Gabriel Garcia Marquez                              d) Jorge Luis Borges\n\n RESPUESTA: ");
                        scanf("%c", &respuesta); fflush(stdin); system("cls");
                        if (respuesta == 'a'){
                            puntaje *= 2;
                            printf("\n RESPUESTA CORRECTA, se empieza a sentir la tension en el ambiente...\n");
                        }else{
                            ganador = 9;
                        }
                        break;
                    case 12:
                        printf("\n 12. Pregunta de Tecnologia: Quien es el fundador de SpaceX? \n\n a) Jeff Bezos                                c) Bill Gates\n b) Mark Zuckerberg                           d) Elon Musk\n\n RESPUESTA: ");
                        scanf("%c", &respuesta); fflush(stdin); system("cls");
                        if (respuesta == 'd'){
                            puntaje = 125000;
                            printf("\n RESPUESTA CORRECTA, sabias que la empresa de Elon quiere colonizar Marte en un futuro?\n");
                        }else{
                            ganador = 9;
                        }
                        break;
                    case 13:
                        printf("\n 13. Hay una historia muy curiosa con una manzana...Cual de las siguientes unidades mide la fuerza?\n\n a) Newton                               c) Watt\n b) Volt                                 d) Amperio\n\n RESPUESTA: ");
                        scanf("%c", &respuesta); fflush(stdin); system("cls");
                        if (respuesta == 'a'){
                            puntaje *= 2;
                            printf("\n RESPUESTA CORRECTA, se dice que Isaac Newton era un hombre muy distraido e incluso una vez se cayo por una ventana mientras estaba absorto en sus pensamientos.\n Afortunadamente, sobrevivio a la caida y pudo seguir contribuyendo a la ciencia.\n\n");
                        }else{
                            ganador = 9;
                        }
                        break;
                    case 14:
                        printf("\n 14. Esta respuesta podria cambiar tu futuro... Quien pinto la famosa obra \"La Gioconda\"?\n\n a) Pablo Picasso                                c) Vincent van Gogh\n b) Michelangelo Buonarroti                      d) Leonardo da Vinci\n\n RESPUESTA: ");
                        scanf("%c", &respuesta); fflush(stdin); system("cls");
                        if (respuesta == 'd'){
                            puntaje *= 2;
                            printf("\n FELICIDADES LLEGASTE A LA FINAL,\n\n Si decides irte, ganas 500 mil dls. Si te arriesgas y pierdes, te llevas 266 mil dls (32mil mas la mitad de 468 mil dls). Si ganas, seras la nueva persona millonaria!\n");
                        }else{
                            ganador = 9;
                        }
                        break;
                    case 15:
                        printf("\n DESDE QUE TE VI CONFIE EN VOS, VOS PODES!...Cual es el punto mas bajo de la Tierra?\n\n a) El Monte Everest                              c) La Cuenca del Congo\n b) El Mar Muerto                                 d) La Fosa de las Marianas\n\n RESPUESTA: ");
                        scanf("%c", &respuesta); fflush(stdin); system("cls");
                        if (respuesta == 'b'){
                            puntaje = 1000000;
                            ganador = 2;
                            printf("\n \"Felicitaciones! Eres el ganador o ganadora del juego \"Quien quiere ser millonario?\".\n\n\n Has demostrado un gran conocimiento y habilidad para responder correctamente a las preguntas,\n y has alcanzado el objetivo final de ganar un millon de dolares. Esto es un logro increible\n que muy pocas personas pueden alcanzar, y te mereces todas las felicitaciones y el reconocimiento\n por tu esfuerzo y dedicacion. Espero que este premio cambie tu vida y te permita cumplir todos\n tus deseos y metas. Disfruta de tu merecida victoria!\"\n\n\n MUCHAAACHOS AHORA NOS VOLVIMOS A ILUSIONAR\n");
                        }else{
                            puntaje = 500000;
                            ganador = 9;
                        }
                        break;
                    }//Llave del switch PREGUNTAS

                    //EL BUCLE DE LA RESPUESTA CORRECTA O RESPUESTA INVALIDA
                    if (ganador == 1){
                            printf("\n\n Es MOMENTO DE ELEGIR...\n\n a) Te quedas con tu puntuaje actual y te retiras                                 b) Sigues jugando y participando de la posibilidad de mas premios\n\n\n Tu puntaje actual es de: %u USD\n\n Ranking de la sesion %u USD\n\n RESPUESTA: ", puntaje, puntaje_ranking);
                            scanf("%c", &participar); fflush(stdin); system("cls");

                            //En caso de que se retire se sube el valor de "preguntas" para que se rompa el ciclo
                            if (participar == 'a'){
                                    preguntas = 20;
                            }
                            }else if (ganador == 2){
                                printf("\n\n\n\n\n (Pulse ENTER para continuar)");
                                getchar(); system("cls");
                                      }else{
                                          //Respuesta Incorrecta
                                          if (puntaje != 0){
                                              puntaje -= checkpoint;
                                              puntaje /= 2;
                                              puntaje += checkpoint;
                                              printf("\n FALLASTE EN LA PREGUNTA %u \n\n Respuesta incorrecta :( , vuelve a intentarlo!\n\n Tu puntaje fue de \" %d \" USD. \n\n\n\n\n (Pulse ENTER para salir al menu)", preguntas, puntaje);
                                              getchar();system("cls");
                                            }else{
                                                //Si perdes en la primer pregunta
                                                puntaje = 0;
                                                puntaje += checkpoint;
                                                printf("\n FALLASTE EN LA PREGUNTA %u \n\n Respuesta incorrecta :( , vuelve a intentarlo!\n\n Tu puntaje fue de \" %d \" USD. \n\n\n\n\n (Pulse ENTER para salir al menu)", preguntas, puntaje);
                                                getchar();system("cls");
                                            }
                            //Se sube el valor de "preguntas" para que se rompa el ciclo
                            preguntas = 20;
                            }
                }//Llave del FOR

                //SISTEMA DE RANKING
                if (puntaje >= puntaje_ranking){
                    //asignacion del nuevo ranking
                    puntaje_ranking = puntaje;
                    printf("\n FELICIDADES! eres el nuevo TOP 1 en el juego\n\n Tu cantidad de puntos fue de %d USD \n\n\n\n\n A continuacion digite 3 caracteres (1 y ENTER, otro y ENTER)", puntaje_ranking);
                    //Letras del ranking
                    for (int p = 1; p <= 3; p++){
                        printf("\n\n Letra %hu: ", p);
                        switch (p){
                            case 1:
                                scanf("%c", &let1); fflush(stdin);
                                break;
                            case 2:
                                printf("\n\n %c ", let1);
                                scanf("%c", &let2); fflush(stdin);
                                break;
                            case 3:
                                printf("\n\n %c %c ", let1, let2);
                                scanf("%c", &let3); fflush(stdin);
                                break;
                        }
                        system("cls");
                        }
                    printf("\n Felicidades %c %c %c ERES EL NUEVO TOP 1 \n\n\n\n\n (Pulse ENTER para salir al menu)", let1, let2, let3);
                    }
                    getchar(); system("cls");
                    //Se reinician los puntajes
                    puntaje = checkpoint = 0;
        }//Llave del if MENU
            if (menu == 2){
                printf("\n El ranking de la sesion es de\n\n %c%c%c                      %u USD\n\n\n\n\n (Pulse ENTER para salir)", let1, let2, let3, puntaje_ranking);
                getchar(); system("cls");
            }
        }while(menu != 3);
    return 0;
}
