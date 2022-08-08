
//************** PROYECTO: BATALLA NAVAL (POR URUSOFT) ***************//

#include <conio.h>
#include <stdio.h>
#include <dos.h>

//******************** DECLARACION: FUNCIONES GLOBALES ***************//

int menu_principal(void);         // Muestra el men£ principal.
void inic_matrizjug1(void);       // Inicializa la matriz del Jugador 1.
void inic_matrizjug2(void);       // Inicializa la matriz del Jugador 2.
void tiro_jug1(void);             // Permite realizar disparos al jugador 1.
void tiro_jug2(void);             // Permite realizar disparos al jugador 2.
void interfase1a2(void);          // Muestra una pantalla que da paso a que el Jugador 2 ubique su flota.
void grilla(void);                // Muestra la grilla.
void pre_ubicar_barcos(void);     // Presentaci¢n de la ubicaci¢n de barcos.
void reglamento(void);            // Muestra el reglamento.
void creditos(void);              // Muestra los cr‚ditos (autores del proyecto).
void presentacion(void);          // Permite visualizar la presentaci¢n.
void comienzo_batalla(void);      // Muestra pantalla de presentaci¢n del comienzo de la batalla.
void mostrar_ganador_jug1(void);  // Muestra como ganador al Jugador 1.
void mostrar_ganador_jug2(void);  // Muestra como ganador al Jugador 2.
void estadisticas(void);          // Muestra estad¡sticas del juego (nø de aciertos y errores).
void primer_menu(void);           // Muestra la presentaci¢n y da paso al men£ principal.
void mostrar_fondo(void);         // Pinta la grilla al colocar barcos.
void pintar_menu_estad(void);     // Muestra el fondo de las estad¡sticas.
void boton(void);                 // Emite un sonido al ingresar una opci¢n del men£.

//************** FUNCIONES QUE UBICAN BARCOS ***************//

      // * JUGADOR 1 * //
void ubicar_patrulleros_jug1(void);   // Ubica Patrulleros del Jugador 1.
void ubicar_submarinos_jug1(void);    // Ubica Submarinos del Jugador 1.
void ubicar_acorazados_jug1(void);    // Ubica Acorazados del Jugador 1.
void ubicar_destructores_jug1(void);  // Ubica Destructores del Jugador 1.
void ubicar_portaaviones_jug1(void);  // Ubica Portaaviones del Jugador 1.

      // * JUGADOR 2 * //
void ubicar_patrulleros_jug2(void);   // Ubica Patrulleros del Jugador 2.
void ubicar_submarinos_jug2(void);    // Ubica Submarinos del Jugador 2.
void ubicar_acorazados_jug2(void);    // Ubica Acorazados del Jugador 2.
void ubicar_destructores_jug2(void);  // Ubica Destructores del Jugador 2.
void ubicar_portaaviones_jug2(void);  // Ubica Portaaviones del Jugador 2.

//****************** DECLARACION DE MATRICES Y VECTORES *******************//

int matrizjug1 [15][15];      // Declara matriz del Jugador 1.
int matrizjug2 [15][15];      // Declara matriz del Jugador 2.
int tiroscoljug1[100];        // Vector donde se almacenan solo las COLUMNAS a las que tir¢ el jug 1.
int tirosfilajug1[100];       // Vector donde se almacenan solo las FILAS a las que tir¢ el jug 1.
int tiroscoljug2[100];        // Vector donde se almacenan solo las COLUMNAS a las que tir¢ el jug 1.
int tirosfilajug2[100];       // Vector donde se almacenan solo las FILAS a las que tir¢ el jug 2.

//************************ VARIABLES GLOBALES **************************//

int col=0, fila=0, hov=0, salir=0; // Columna, fila, horizontal o vertical, salir.
int bpjug1=35, bpjug2=35;          // Blanco posible jug1, blanco posible jug2.
int x, y,j,k, a, b=0;              // Coordenadas horizontales y verticales, para inicializar las matrices.
int m=0;                           // m es un contador que recorre el vector tiroscoljug1, tirosfilajug1, tiroscoljug2, tirosfilajug2. (Almacena los tiros en dichos vectores).
int tenb1=0,tenb2=0;               // Tiros en blanco del Jugador 1 y 2.
int tirosjug1=0, tirosjug2=0;      // Tiros totales (agua y barco).
int efectiv1=0,efectiv2=0;         // Aciertos (resta entre tiros totales y tiros en blanco).
int contador_patrulleros=0;        // Funci¢n que permite contar y controlar el nøde patrulleros.
int contador_submarinos=0;         // Funci¢n que permite contar y contolar el nøde submarinos.
int contador_acorazados=0;         // Funci¢n que permite contar y controlar el nøde acorazados.
int contador_destructores=0;       // Funci¢n que permite contar y controlar el nøde destructores.

//**************************FUNCION PRINCIPAL******************************//

void main(void)
{
presentacion();
primer_menu();
}

//************************* PRIMER MENU ************************************//

void primer_menu(void)
{
inic_matrizjug1();
inic_matrizjug2();
while (!salir)
	salir=menu_principal();
return;
}

//*************************** MENU PRINCIPAL ******************************//

int menu_principal(void)
{
int opcion, salir=0;
clrscr();
textcolor(14); gotoxy(24,9); cprintf ("BIENVENIDOS A LA BATALLA NAVAL");
textcolor(4+BLINK);
gotoxy(20,9); cprintf("*");
gotoxy(22,9); cprintf("*");
gotoxy(55,9); cprintf("*");
gotoxy(57,9); cprintf("*");
textcolor(15+BLINK);
gotoxy(21,9); cprintf("*");
gotoxy(56,9); cprintf("*");

textcolor(5);  gotoxy(45,11); cprintf("por URUSoft");
textcolor(4);  gotoxy(27,17); cprintf ("(1) -");
textcolor(2);  gotoxy(34,17); cprintf ("Ver presentaci¢n");
textcolor(4);  gotoxy(27,21); cprintf ("(2) -");
textcolor(2);  gotoxy(34,21); cprintf ("¨C¢mo jugar?");
textcolor(4);  gotoxy(27,25); cprintf ("(3) -");
textcolor(2);  gotoxy(34,25); cprintf ("Comenzar a jugar");
textcolor(4);  gotoxy(27,29); cprintf ("(4) -");
textcolor(2);  gotoxy(34,29); cprintf ("Cr‚ditos");
textcolor(4);  gotoxy(27,33); cprintf ("(5) -");
textcolor(2);  gotoxy(34,33); cprintf ("Salir del juego");
textcolor(15); gotoxy(35,41); cprintf("OPCION: ");

gotoxy(25,15); cprintf("É                          »");
gotoxy(25,35); cprintf("È                          ¼");
for (x=26; x<=51; x++)
	{
	gotoxy(x,15); cprintf("Í");
	}
for (x=26; x<=51; x++)
	{
	gotoxy(x,35); cprintf("Í");
	}
for (x=16; x<=40; x++)
	{
	gotoxy(25,x); cprintf("º");
	}
for (x=16; x<=40; x++)
	{
	gotoxy(52,x); cprintf("º");
	}
gotoxy(25,41); cprintf("È");
gotoxy(26,41); cprintf("ÍÍÍÍÍÍÍÍ");
gotoxy(44,41); cprintf("ÍÍÍÍÍÍÍÍ");
gotoxy(52,41); cprintf("¼");

// COPYRIGHT
textcolor(4);  gotoxy(27,49); cprintf("Copyright 2004 - URUSoft");
gotoxy(42,41);
opcion=getchar();
		 switch (opcion)   // La opci¢n del men£ escogida, llama a una funci¢n determinada.
				{
				case '1': presentacion();      // Muestra la presentaci¢n del juego
				break;
				case '2': boton();
					  reglamento();        // Muestra el reglamento del juego
				break;
				case '3': boton();
					  pre_ubicar_barcos(); // Comienza el juego
				break;
				case '4': boton();
					  creditos();          // Muestra los cr‚ditos
				break;
				case '5': boton();
					  salir=1;             // Sale del programa
				break;
				}
return salir;
}


//*************************** BOTON ****************************************//

void boton(void)
{
sound(560);
delay(100);
nosound();
}

//****************** INICIALIZAR MATRICES DE AMBOS JUGADORES ****************//

   // * JUGADOR 1 * //
void inic_matrizjug1(void)
{
for (x=0; x<=14; x++)
	 {
	 for (y=0; y<=14; y++)
	 matrizjug1[x][y]=0;
	 }
x=0;
for (x=0; x<=100; x++)
	{
	tiroscoljug1[x]=0;
	tirosfilajug1[x]=0;
	}
return;
}

   // * JUGADOR 2 * //
void inic_matrizjug2(void)
{
for (j=0; j<=14; j++)
	 {
	 for (k=0; k<=14; k++)
	 matrizjug2[j][k]=0;
	 }
j=0;
for (j=0; j<=100;j++)
	{
	tiroscoljug1[j]=0;
	tirosfilajug1[j]=0;
	}
return;
}
//***********************************************************************


//*************************** PRESENTACION *******************************//

void presentacion(void)   // Muestra la presentaci¢n inicial.
{
int a,b; // Variables locales para dibujar entorno gr fico.
clrscr();
_setcursortype(_NOCURSOR);

textcolor(11);
gotoxy(11,8);	cprintf("  BBBB   AAAAAA  TTTTTTT  AAAAAA  L       L       AAAAAAA  ");
gotoxy(11,9);	cprintf("  B   B  A    A     T     A    A  L       L       A     A  ");
gotoxy(11,10);	cprintf("  BBBB   AAAAAA     T     AAAAAA  L       L       AAAAAAA  ");
gotoxy(11,11);	cprintf("  B   B  A    A     T     A    A  L       L       A     A  ");
gotoxy(11,12);	cprintf("  BBBB   A    A     T     A    A  LLLLLL  LLLLLL  A     A  ");
gotoxy(11,13);	cprintf("                                                           ");
gotoxy(11,14);	cprintf("                                                           ");
gotoxy(11,15);	cprintf("                                                           ");
gotoxy(11,16); 	cprintf("         NN   N  AAAAAA   V      V  AAAAAA  L              ");
gotoxy(11,17); 	cprintf("         NN   N  A    A   V      V  A    A  L              ");
gotoxy(11,18);	cprintf("         N N  N  AAAAAA   V      V  AAAAAA  L              ");
gotoxy(11,19);	cprintf("         N  N N  A    A    V    V   A    A  L              ");
gotoxy(11,20);	cprintf("         N   NN  A    A      VV     A    A  LLLLLL         ");
gotoxy(11,21);	cprintf("                                                           ");

//******************* Imprime un marco que parpadea **********************//

textcolor (14+BLINK);
gotoxy (5,3); cprintf ("É");     //alt+201
gotoxy (75,3); cprintf ("»");    //alt+187
gotoxy (5,25); cprintf ("È");    //alt+200
gotoxy (75,25); cprintf ("¼");   //alt+188
for (a=5+1;a<75;a++)
    {
    gotoxy (a,3); cprintf ("Í"); // alt+205 = Í
    gotoxy (a,25); cprintf ("Í");
    }
for (b=3+1;b<25;b++)
    {
    gotoxy (5,b); cprintf ("º"); // alt+186 = º
    gotoxy (75,b); cprintf ("º");
    }

textcolor(4);

gotoxy(10,32); cprintf("                                   .\n                  ");
gotoxy(10,33); cprintf("                                  /|~~\n     ");
gotoxy(10,34); cprintf("                             ,   / |~~\n                       ");
gotoxy(10,35); cprintf("                            /|  /  |\n             ");
gotoxy(10,36); cprintf("                           / |~~   |     ,~~~~\n               ");
gotoxy(10,37); cprintf("                          /  |~~   |    /|~~~~\n               ");
gotoxy(10,38); cprintf("                         /   |     |   / |\n                   ");
gotoxy(10,39); cprintf("                        /    |     |  /  |\n                   ");
gotoxy(10,40); cprintf("                       /     |     | /   |\n                   ");
gotoxy(10,41); cprintf("                      /      |     |/    |\n                   ");
gotoxy(10,42); cprintf("          =====______/       |     |=====|  __\n               ");
gotoxy(10,43); cprintf("             \   __ \========|=====|    / \|__)\n              ");
gotoxy(10,44); cprintf("              \'V` _\o_o_o_o_o_o_o_o_o_o_o_o__)\n              ");
gotoxy(10,45); cprintf("               \ -------  --  ---- - -  --- /\n                ");
gotoxy(10,46); cprintf("                 \  ----------- -  --- ----  |)\n               ");
textcolor(9);
gotoxy(10,47); cprintf("       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
gotoxy(10,48);  cprintf("    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

textcolor(7);
gotoxy(10,32); cprintf("          .. ...");
gotoxy(10,33); cprintf("       ...   .  ..");
gotoxy(10,34); cprintf("      ..   .   .. .");
gotoxy(10,35); cprintf("        ...  . ..");
gotoxy(10,36); cprintf("           ..");

gotoxy(60,32); cprintf("vv");
gotoxy(66,34); cprintf("vv");
gotoxy(62,36); cprintf("vv");

gotoxy(40,50);  textcolor(12);   cprintf("  Presione una tecla para continuar...");

//*** SONIDOS DE LA PRESENTACION ***//

sound(500); delay(300); nosound();
sound(600); delay(300); nosound();
sound(600); delay(300); nosound();
sound(600); delay(300); nosound();
sound(540); delay(300); nosound();
sound(500); delay(300); nosound();
sound(600); delay(300); nosound();
sound(600); delay(300); nosound();
sound(700); delay(300); nosound();
sound(550); delay(300); nosound();
sound(700); delay(300); nosound();
sound(850); delay(300); nosound();
sound(700); delay(300); nosound();
sound(600); delay(300); nosound();
sound(600); delay(300); nosound();
sound(780); delay(300); nosound();
sound(700); delay(300); nosound();
sound(800); delay(300); nosound();
sound(840); delay(300); nosound();
sound(800); delay(300); nosound();
sound(700); delay(300); nosound();
sound(600); delay(300); nosound();
sound(700); delay(300); nosound();
sound(600); delay(300); nosound();
sound(500); delay(300); nosound();
sound(600); delay(300); nosound();
sound(600); delay(300); nosound();
sound(600); delay(300); nosound();
sound(600); delay(300); nosound();

getch();
return;

}
//***********************************************************************


/****************************** REGLAMENTO ******************************/

void reglamento(void)
{
_setcursortype(_NOCURSOR); //para ocultar el cursor de la pantalla
clrscr();
gotoxy(30,7); textcolor(10); cprintf("R E G L A M E N T O");
gotoxy(28,9); textcolor(14 + BLINK); cprintf("ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ");

textcolor(7);
gotoxy(1,13);  cprintf("  Este juego es para dos personas, cada una con un tablero y una flota que    ");
gotoxy(1,15);  cprintf("  contiene 15 barcos: 1 Portaaviones, 2 Destructores, 3 Acorazados,  ");
gotoxy(1,17);  cprintf("  4 Submarinos y 5 Patrulleros.");
gotoxy(1,19);  cprintf("  Para comenzar se deben colocar todos los barcos de cada jugador en el tablero.");
gotoxy(1,21);  cprintf("  Una vez ubicados, se empieza a jugar de la siguiente manera:");
gotoxy(1,24);  cprintf("          El Jugador 1 indica una celda a trav‚s de su direcci¢n (columna y ");
gotoxy(1,26);  cprintf("          fila, por ejemplo D3) para efectuar un disparo.");
gotoxy(1,29);  cprintf("          El Jugador 2 indica si el disparo efectuado acert¢ alg£n barco de ");
gotoxy(1,31);  cprintf("          su flota o si cay¢ en el agua.");
gotoxy(1,34);  cprintf("          Cada jugador efect£a un disparo por turno. ");
gotoxy(1,37);  cprintf("          El ganador del juego es quien hunda primero con sus disparos la flota ");
gotoxy(1,39);  cprintf("          enemiga. ");

textcolor(14);
gotoxy(8,24); cprintf("*");
gotoxy(8,29); cprintf("*");
gotoxy(8,34); cprintf("*");
gotoxy(8,37); cprintf("*");
gotoxy(38,50); textcolor(10); cprintf("Presione una tecla para volver al men£...");
getch();
return;
}


//**************************** CREDITOS **********************************//

void creditos(void)
{
clrscr();
textcolor(11);
gotoxy(6,4); cprintf("                                                               .---.\n");
gotoxy(6,5); cprintf("                                                              /  .  \\ \n");
gotoxy(6,6); cprintf("                                                             |\\_/|   |\n");
gotoxy(6,7); cprintf("                                                             |   |  /|\n");
gotoxy(6,8); cprintf("  .----------------------------------------------------------------' |\n");
gotoxy(6,9); cprintf(" / .--.                                                              |\n");
gotoxy(6,10); cprintf("| /    \\      U  U   RRRR   U  U   SSSS   OOOO   FFFF   TTTTT        |\n");
gotoxy(6,11); cprintf("||      |     U  U   R  R   U  U   S      O  O   F        T          |\n");
gotoxy(6,12); cprintf("|\\     /|     U  U   R R    U  U   SSSS   O  O   FFF      T          |\n");
gotoxy(6,13); cprintf("| `---' |     U  U   R  R   U  U      S   O  O   F        T          |\n");
gotoxy(6,14); cprintf("|       |     UUUU   R  R   UUUU   SSSS   OOOO   F        T          |\n");
gotoxy(6,15); cprintf("|       |                                                           /\n");
gotoxy(6,16); cprintf("|       |----------------------------------------------------------'\n");
gotoxy(6,17); cprintf("\\       |\n");
gotoxy(6,18); cprintf(" \\     /\n");
gotoxy(6,19); cprintf("  `---'");

textcolor (2);
gotoxy(31,24); cprintf("VANESA FERNANDEZ");
gotoxy(31,27); cprintf("SABRINA LARRONDE");
gotoxy(31,30); cprintf("GERMAN RODRIGUEZ");
textcolor(4 + BLINK);
gotoxy(25,24); cprintf("***");
gotoxy(25,27); cprintf("***");
gotoxy(25,30); cprintf("***");
gotoxy(50,24); cprintf("***");
gotoxy(50,27); cprintf("***");
gotoxy(50,30); cprintf("***");

textcolor(7);
gotoxy(5,32);  cprintf("     ___________    ");
gotoxy(5,33);  cprintf("    | _________ |   ");
gotoxy(5,34);  cprintf("    ||         ||   ");
gotoxy(5,35);  cprintf("    ||         ||   ");
gotoxy(5,36);  cprintf("    || URUSOFT ||   ");
gotoxy(5,37);  cprintf("    ||         ||   ");
gotoxy(5,38);  cprintf("    ||_________||   ");
gotoxy(5,39);  cprintf("    |___________|   ");
gotoxy(5,40);  cprintf("       |     |      ");
gotoxy(5,41);  cprintf("    ___|_____|__    ");
gotoxy(5,42);  cprintf("   / ********** \\  ");
gotoxy(5,43);  cprintf("  / ************ \\ ");
gotoxy(5,44);  cprintf("  ---------------- ");

gotoxy(53,32);  cprintf("     ___________    ");
gotoxy(53,33);  cprintf("    | _________ |   ");
gotoxy(53,34);  cprintf("    ||         ||   ");
gotoxy(53,35);  cprintf("    ||         ||   ");
gotoxy(53,36);  cprintf("    || URUSOFT ||   ");
gotoxy(53,37);  cprintf("    ||         ||   ");
gotoxy(53,38);  cprintf("    ||_________||   ");
gotoxy(53,39);  cprintf("    |___________|   ");
gotoxy(53,40);  cprintf("       |     |      ");
gotoxy(53,41);  cprintf("    ___|_____|__    ");
gotoxy(53,42);  cprintf("   / ********** \\  ");
gotoxy(53,43);  cprintf("  / ************ \\ ");
gotoxy(53,44);  cprintf("  ---------------- ");

gotoxy (38,50);
textcolor(4);
gotoxy(40,52); textcolor(4); cprintf("Presione una tecla para volver al men£...");
getch();
return;

}
//************************************************************************


//************** PANTALLA DE COMIENZO DEL JUEGO ****************//

void pre_ubicar_barcos(void)
{
clrscr();
textcolor(1);
for (x=7;x<=73;x++)
	{
	gotoxy (x,3);
	cprintf("Í");
	}
for (x=4;x<=45;x++)
	{
	gotoxy(6,x);
	cprintf("º");
	}
for (x=4;x<=45;x++)
	{
	gotoxy(74,x);
	cprintf("º");
	}
for (x=7;x<=73;x++)
	{
	gotoxy (x,46);
	cprintf("Í");
	}
textcolor(14);
gotoxy(6,3);   cprintf("²");
gotoxy(74,3);  cprintf("²");
gotoxy(6,46);  cprintf("²");
gotoxy(74,46); cprintf("²");
textcolor(14); gotoxy(30,6); cprintf("COMIENZO DEL JUEGO");
textcolor(15);
gotoxy(9,8);   cprintf("Es aqui donde comienza el juego. Ahora los jugadores (1 y 2,");
gotoxy(9,10);  cprintf("rojo y verde respectivamente), deber n ubicar su flota por");
gotoxy(9,12);  cprintf("turnos sin ser vistos por el otro jugador.");
gotoxy(9,14);  cprintf("Una vez que ambos jugadores han ubicado su flota, se proceder ");
gotoxy(9,16);  cprintf("a una serie de disparos, uno por turno. Como ya se sabe, ganar ");
gotoxy(9,18);  cprintf("el juego el primer jugador que hunda la flota enemiga.");
textcolor(14); gotoxy(31,21); cprintf("ALGUNOS CONSEJOS:");
textcolor(12);
gotoxy(12,24); cprintf("Cuando est‚ posicionando su flota, aseg£rese de escribir la");
gotoxy(12,26); cprintf("COLUMNA (letra) con MAYUSCULAS.");
gotoxy(12,30); cprintf("ADMINISTRE EL ESPACIO. Recuerde que dos buques no se pueden");
gotoxy(12,32); cprintf("tocar y una mala administraci¢n de celdas provocar¡a el ");
gotoxy(12,34); cprintf("mal funcionamiento del programa.");
gotoxy(12,38); cprintf("Durante la serie de disparos, ser¡a de gran utilidad para");
gotoxy(12,40); cprintf("el jugador, anotar en una hoja los disparos que ya se");
gotoxy(12,42); cprintf("han efectuado. Esto facilitar¡a la victoria.");
textcolor(14+BLINK);
gotoxy(10,24); cprintf("*");
gotoxy(10,30); cprintf("*");
gotoxy(10,38); cprintf("*");
textcolor(4);
gotoxy(37,50); cprintf("Pulse cualquier tecla para continuar...");

// MUSICA 
sound(500); delay(200); nosound();
sound(400); delay(250); nosound();
sound(550); delay(200); nosound();
sound(900); delay(800); nosound();
sound(500); delay(200); nosound();
sound(600); delay(380); nosound();
sound(200); delay(150); nosound();
sound(150); delay(600); nosound();
sound(300); delay(500); nosound();
sound(450); delay(400); nosound();
sound(450); delay(400); nosound();
sound(500); delay(400); nosound();
sound(500); delay(700); nosound();
sound(450); delay(100); nosound();
sound(500); delay(200); nosound();
sound(400); delay(250); nosound();
sound(550); delay(200); nosound();
sound(400); delay(700); nosound();
sound(500); delay(200); nosound();
sound(300); delay(700); nosound();
sound(200); delay(150); nosound();
sound(200); delay(300); nosound();
sound(200); delay(600); nosound();
sound(500); delay(400); nosound();
sound(300); delay(600); nosound();
sound(200); delay(400); nosound();
sound(300); delay(400); nosound();

getch();
clrscr();
_setcursortype(_NORMALCURSOR);  // Vuelve al cursor normal.
grilla();
ubicar_patrulleros_jug1();
return;

}

/************************* DESPLIEGE DE LA GRILLA **********************/

void grilla(void)
{
int y2=25;    // Variable local que permite dibujar el agua en la grilla.
int letra=0;  // Variable local que permite colocar la letra en la grilla.
for (y2=25; y2<35; y2++)
     {
     gotoxy (12,y2);
     textcolor(1);
     cprintf("°°°°°°°°°°"); // Fondo de agua.
     }
gotoxy(12,23);
textcolor(15);
for (letra=65; letra<=74; letra++)
    cprintf ("%c", letra);

gotoxy(10,25);  cprintf ("1");
gotoxy(10,26);  cprintf ("2");
gotoxy(10,27);  cprintf ("3");
gotoxy(10,28);  cprintf ("4");
gotoxy(10,29);  cprintf ("5");
gotoxy(10,30);  cprintf ("6");
gotoxy(10,31);  cprintf ("7");
gotoxy(10,32);  cprintf ("8");
gotoxy(10,33);  cprintf ("9");
gotoxy(9,34);   cprintf ("10");
return;

}
//************************************************************************


/****************** UBICACION DE FLOTA DEL JUGADOR 1 *********************/
/* Cada barco presenta un control de su ubicaci¢n, para que el mismo
sea  colocado dentro de la matriz correspondiente, as¡ como tambi‚n
se controla que no se coloquen dos barcos en la misma celda, evitando
tambi‚n colisiones. */

//************** UBICACION DE PATRULLEROS DEL JUGADOR 1 ****************//

void ubicar_patrulleros_jug1(void)
{
textcolor(WHITE);
gotoxy(34,23); cprintf("      BUQUE          CELDAS");
gotoxy(34,27); cprintf(" 5 Patrulleros      1 celda");
gotoxy(34,29); cprintf(" 4  Submarinos      2 celdas");
gotoxy(34,31); cprintf(" 3  Acorazados      3 celdas");
gotoxy(34,33); cprintf(" 2 Destructores     4 celdas");
gotoxy(34,35); cprintf(" 1 Portaaviones     5 celdas");

textcolor(4);
gotoxy(50,23); cprintf("³");
gotoxy(50,24); cprintf("³");
gotoxy(33,25); cprintf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
gotoxy(50,26); cprintf("³");
gotoxy(50,27); cprintf("³");
gotoxy(50,28); cprintf("³");
gotoxy(50,29); cprintf("³");
gotoxy(50,30); cprintf("³");
gotoxy(50,31); cprintf("³");
gotoxy(50,32); cprintf("³");
gotoxy(50,33); cprintf("³");
gotoxy(50,34); cprintf("³");
gotoxy(50,35); cprintf("³");
gotoxy(50,36); cprintf("³");

textcolor(4 + BLINK);
gotoxy(5,49);  cprintf("ÄÄÄÄÄÄÄÄÄÄ");
gotoxy(5,47);  cprintf("ÄÄÄÄÄÄÄÄÄÄ");
textcolor(15);
gotoxy(6,48);  cprintf("RECUERDE:");
gotoxy(18,47); cprintf("Los buques no pueden tocarse entre si, ni");
gotoxy(18,49); cprintf("ocupar la misma celda dentro de la grilla.");

textcolor(4);
gotoxy (34,2); cprintf("JUGADOR 1");
textcolor(15);
gotoxy(4,4);   cprintf("Seleccione coordenadas para EL %d§ PATRULLERO",contador_patrulleros+1);
gotoxy(4,8);   cprintf("¨COLUMNA? (A-J):");
textcolor(4);
gotoxy(24,7);  cprintf("É");
gotoxy(25,7);  cprintf("ÍÍ");
gotoxy(27,7);  cprintf("»");
gotoxy(24,8);  cprintf("º  º");
gotoxy(24,9);  cprintf("È  ¼");
gotoxy(25,9);  cprintf("ÍÍ");
textcolor(15);
gotoxy (4,14); cprintf("¨FILA? (1-10):");
textcolor(4);
gotoxy(24,13); cprintf("É");
gotoxy(25,13); cprintf("ÍÍ");
gotoxy(27,13); cprintf("»");
gotoxy(24,14); cprintf("º  º");
gotoxy(24,15); cprintf("È  ¼");
gotoxy(25,15); cprintf("ÍÍ");
gotoxy(25,8);  cprintf("  ");
gotoxy(25,14); cprintf("  ");
textcolor(15);
gotoxy(25,8);
cscanf ("%s",&col);
col=col-65;
while ((col<0) || (col>9))   // Controla que se ubique la flota dentro de los par metros horizontales de la matriz.
	ubicar_patrulleros_jug1();
gotoxy(25,14);
cscanf ("%d",&fila);
fila=fila-1;
if ((fila<0) || (fila>9))    // Controla que se ubique la flota dentro de los par metros verticales de la matriz.
	ubicar_patrulleros_jug1();
if ((matrizjug1[col-1][fila]==1)||(matrizjug1[col+1][fila]==1)||(matrizjug1[col][fila-1]==1)||(matrizjug1[col][fila+1]==1)||(matrizjug1[col][fila]==1))
	ubicar_patrulleros_jug1();
matrizjug1[col][fila]=1;
gotoxy(col+12,fila+25);
textcolor(4);
cprintf ("²");
contador_patrulleros++;
if (contador_patrulleros==5) // Control del n£mero de Patrulleros.
	ubicar_submarinos_jug1();
ubicar_patrulleros_jug1();

}

//************** UBICACION DE SUBMARINOS DEL JUGADOR 1 ****************//

void ubicar_submarinos_jug1(void)
{
textcolor(15);
gotoxy(4,4);
cprintf("Seleccione coordenadas para EL %d§ SUBMARINO ",contador_submarinos+1);
gotoxy(25,8);  cprintf("  ");
gotoxy(25,14); cprintf("  ");
gotoxy(60,11); cprintf("  ");
gotoxy(25,8);
cscanf ("%s",&col);
col=col-65;
while ((col<0) || (col>9))
	ubicar_submarinos_jug1();
gotoxy(25,14);
cscanf ("%d",&fila);
fila=fila-1;
if ((fila<0) || (fila>9))
	ubicar_submarinos_jug1();
textcolor(15);
gotoxy(31,11); cprintf("Horiz.(H) o Vertical(V):");
textcolor(4);
gotoxy(59,10); cprintf("É");
gotoxy(60,10); cprintf("ÍÍ");
gotoxy(62,10); cprintf("»");
gotoxy(59,11); cprintf("º  º");
gotoxy(59,12); cprintf("È  ¼");
gotoxy(60,12); cprintf("ÍÍ");
textcolor(15);
gotoxy(60,11);
cscanf("%s",&hov);
if (hov==72) // Horizontal
   {
   if (col>=9)
	ubicar_submarinos_jug1();
   if ((matrizjug1 [col-1][fila]==1) || (matrizjug1 [col][fila]==1) || (matrizjug1 [col+1][fila]==1) || (matrizjug1 [col+2][fila]==1) || (matrizjug1 [col][fila-1]==1) || (matrizjug1 [col+1][fila-1]==1) || (matrizjug1 [col][fila+1]==1) || (matrizjug1 [col+1][fila+1]==1))
	ubicar_submarinos_jug1();
   matrizjug1 [col][fila]=1;
   matrizjug1 [col+1][fila]=1;
   gotoxy(col+12,fila+25);
   textcolor(4);
   cprintf ("²²");
   contador_submarinos++;
   if (contador_submarinos==4)
	ubicar_acorazados_jug1();
   ubicar_submarinos_jug1();
   }
if (hov==86) // Vertical
   {
   if (fila>=9)
	ubicar_submarinos_jug1();
   if ((matrizjug1[col][fila]==1) || (matrizjug1[col][fila+1]==1) || (matrizjug1[col][fila-1]==1) || (matrizjug1[col][fila+2]==1) || (matrizjug1[col-1][fila]==1) || (matrizjug1[col+1][fila]==1) || (matrizjug1[col-1][fila+1]==1) || (matrizjug1[col+1][fila+1]==1))
	ubicar_submarinos_jug1();
   matrizjug1 [col][fila]=1;
   matrizjug1 [col][fila+1]=1;
   gotoxy(col+12,fila+25);
   textcolor(4);
   cprintf ("²");
   gotoxy(col+12,fila+26);
   textcolor(4);
   cprintf("²");
   contador_submarinos++;
   if (contador_submarinos==4)  // Control del n£mero de Submarinos.
	ubicar_acorazados_jug1();
   ubicar_submarinos_jug1();
   }
else ubicar_submarinos_jug1();

}

//************** UBICAR ACORAZADOS DEL JUGADOR 1 ****************//

void ubicar_acorazados_jug1(void)
{
textcolor(15);
gotoxy(4,4);   cprintf("Seleccione coordenadas para EL %d§ ACORAZADO",contador_acorazados+1);
gotoxy(25,8);  cprintf("  ");
gotoxy(25,14); cprintf("  ");
gotoxy(60,11); cprintf("  ");
gotoxy(25,8);
cscanf ("%s",&col);
col=col-65;
while ((col<0) || (col>9))
	ubicar_acorazados_jug1();
gotoxy(25,14);
cscanf ("%d",&fila);
fila=fila-1;
if ((fila<0) || (fila>9))
	ubicar_acorazados_jug1();
gotoxy(60,11); cprintf("  ");
gotoxy(60,11);
cscanf("%s",&hov);
if (hov==72) // Horizontal
   {
   if (col>=8)
	ubicar_acorazados_jug1();
   if ((matrizjug1 [col][fila]==1) || (matrizjug1 [col+1][fila]==1) || (matrizjug1 [col+2][fila]==1) || (matrizjug1 [col-1][fila]==1) || (matrizjug1 [col+3][fila]==1) || (matrizjug1 [col][fila+1]==1) || (matrizjug1 [col][fila-1]==1) || (matrizjug1 [col+1][fila+1]==1) || (matrizjug1 [col+1][fila-1]==1) || (matrizjug1 [col+2][fila+1]==1) || (matrizjug1 [col+2][fila-1]==1))
	ubicar_acorazados_jug1();
   matrizjug1 [col][fila]=1;
   matrizjug1 [col+1][fila]=1;
   matrizjug1 [col+2][fila]=1;
   gotoxy(col+12,fila+25);
   textcolor(4);
   cprintf ("²²²");
   contador_acorazados++;
   if (contador_acorazados==3)
	ubicar_destructores_jug1();
   ubicar_acorazados_jug1();
   }
if (hov==86) // Vertical
   {
   if (fila>=8)
	ubicar_acorazados_jug1();
   if ((matrizjug1 [col][fila]==1) || (matrizjug1 [col][fila+1]==1) || (matrizjug1 [col][fila+2]==1) || (matrizjug1 [col][fila-1]==1) || (matrizjug1 [col][fila+3]==1) || (matrizjug1 [col-1][fila]==1) || (matrizjug1 [col-1][fila-1]==1) || (matrizjug1 [col-1][fila-2]==1) || (matrizjug1 [col+1][fila]==1) || (matrizjug1 [col+1][fila+1]==1) || (matrizjug1 [col+1][fila-2]==1))
	ubicar_acorazados_jug1();
   matrizjug1 [col][fila]=1;
   matrizjug1 [col][fila+1]=1;
   matrizjug1 [col][fila+2]=1;
   gotoxy(col+12,fila+25);
   textcolor(4);
   cprintf ("²");
   gotoxy(col+12,fila+26);
   textcolor(4);
   cprintf("²");
   gotoxy(col+12,fila+27);
   textcolor(4);
   cprintf("²");
   contador_acorazados++;
   if (contador_acorazados==3)  // Control del n£mero de Acorazados.
	ubicar_destructores_jug1();
   ubicar_acorazados_jug1();
   }
else ubicar_acorazados_jug1();

}

//************** UBICAR DESTRUCTORES DEL JUGADOR 1 ****************//

void ubicar_destructores_jug1(void)
{
textcolor(15);
gotoxy(4,4);   cprintf("Seleccione coordenadas para EL %d§ DESTRUCTOR",contador_destructores+1);
gotoxy(25,8);  cprintf("  ");
gotoxy(25,14); cprintf("  ");
gotoxy(60,11); cprintf("  ");
gotoxy(25,8);
cscanf ("%s",&col);
col=col-65;
while ((col<0) || (col>9))
	ubicar_destructores_jug1();
gotoxy(25,14);
cscanf ("%d",&fila);
fila=fila-1;
if ((fila<0) || (fila>9))
	ubicar_destructores_jug1();
gotoxy(60,11);
cscanf("%s",&hov);

if (hov==72) // Horizontal
   {
   if (col>=7)
	ubicar_destructores_jug1();
   if ((matrizjug1 [col][fila]==1) || (matrizjug1 [col+1][fila]==1) || (matrizjug1 [col+2][fila]==1) || (matrizjug1 [col+3][fila]==1) || (matrizjug1 [col+4][fila]==1) || (matrizjug1 [col-1][fila]==1) || (matrizjug1 [col][fila-1]==1) || (matrizjug1 [col][fila+1]==1) || (matrizjug1 [col+1][fila-1]==1) || (matrizjug1 [col+1][fila+1]==1) || (matrizjug1 [col+2][fila-1]==1) || (matrizjug1 [col+2][fila+1]==1) || (matrizjug1 [col+3][fila-1]==1) || (matrizjug1 [col+3][fila+1]==1))
	ubicar_destructores_jug1();
   matrizjug1 [col][fila]=1;
   matrizjug1 [col+1][fila]=1;
   matrizjug1 [col+2][fila]=1;
   matrizjug1 [col+3][fila]=1;
   gotoxy(col+12,fila+25);
   textcolor(4);
   cprintf ("²²²²");
   contador_destructores++;
   if (contador_destructores==2)
	ubicar_portaaviones_jug1();
   ubicar_destructores_jug1();
   }
if (hov==86) // Vertical
   {
   if (fila>=7)
	ubicar_destructores_jug1();
   if ((matrizjug1 [col][fila]==1) || (matrizjug1 [col][fila+1]==1) || (matrizjug1 [col][fila+2]==1) || (matrizjug1 [col][fila+3]==1) || (matrizjug1 [col][fila-1]==1) || (matrizjug1 [col][fila+4]==1) || (matrizjug1 [col-1][fila]==1) || (matrizjug1 [col+1][fila]==1) || (matrizjug1 [col-1][fila+1]==1) || (matrizjug1 [col+1][fila+1]==1) || (matrizjug1 [col-1][fila+2]==1) || (matrizjug1 [col+1][fila+2]==1) || (matrizjug1 [col-1][fila+3]==1) || (matrizjug1 [col+1][fila+3]==1))
	ubicar_destructores_jug1();
   matrizjug1 [col][fila]=1;
   matrizjug1 [col][fila+1]=1;
   matrizjug1 [col][fila+2]=1;
   matrizjug1 [col][fila+3]=1;
   gotoxy(col+12,fila+25);
   textcolor(4);
   cprintf ("²");
   gotoxy(col+12,fila+26);
   textcolor(4);
   cprintf("²");
   gotoxy(col+12,fila+27);
   textcolor(4);
   cprintf("²");
   gotoxy(col+12,fila+28);
   textcolor(4);
   cprintf("²");
   contador_destructores++;
   if (contador_destructores==2) // Control del n£mero de Destructores.
	ubicar_portaaviones_jug1();
   ubicar_destructores_jug1();
   }
else ubicar_destructores_jug1();

}

//************** UBICAR PORTAAVIONES DEL JUGADOR 1 ****************//

void ubicar_portaaviones_jug1(void)
{
textcolor(15);
gotoxy(4,4);   cprintf("Seleccione coordenadas para EL PORTAAVIONES");
gotoxy(25,8);  cprintf("  ");
gotoxy(25,14); cprintf("  ");
gotoxy(60,11); cprintf("  ");
gotoxy(25,8);
cscanf ("%s",&col);
col=col-65;
while ((col<0) || (col>9))
	ubicar_portaaviones_jug1();
gotoxy(25,14);
cscanf ("%d",&fila);
fila=fila-1;
if ((fila<0) || (fila>9))
	ubicar_portaaviones_jug1();
gotoxy(60,11);
cscanf("%s",&hov);

if (hov==72) // Horizontal
   {
   if (col>=6)
	ubicar_portaaviones_jug1();
   if ((matrizjug1 [col][fila]==1) || (matrizjug1 [col+1][fila]==1) || (matrizjug1 [col+2][fila]==1) || (matrizjug1 [col+3][fila]==1) || (matrizjug1 [col+4][fila]==1) || (matrizjug1 [col+5][fila]==1) || (matrizjug1 [col-1][fila]==1) || (matrizjug1 [col][fila-1]==1) || (matrizjug1 [col][fila+1]==1) || (matrizjug1 [col+1][fila-1]==1) || (matrizjug1 [col+1][fila+1]==1) || (matrizjug1 [col+2][fila-1]==1) || (matrizjug1 [col+2][fila+1]==1) || (matrizjug1 [col+3][fila-1]==1) || (matrizjug1 [col+3][fila+1]==1) || (matrizjug1 [col+4][fila-1]==1) || (matrizjug1 [col+4][fila+1]==1))
	ubicar_portaaviones_jug1();
   matrizjug1 [col][fila]=1;
   matrizjug1 [col+1][fila]=1;
   matrizjug1 [col+2][fila]=1;
   matrizjug1 [col+3][fila]=1;
   matrizjug1 [col+4][fila]=1;
   gotoxy(col+12,fila+25);
   textcolor(4);
   cprintf ("²²²²²");
   interfase1a2();
   }
if (hov==86) // Vertical
   {
   if (fila>=6)
	ubicar_portaaviones_jug1();
   if ((matrizjug1 [col][fila]==1) || (matrizjug1 [col][fila+1]==1) || (matrizjug1 [col][fila+2]==1) || (matrizjug1 [col][fila+3]==1) || (matrizjug1 [col][fila+4]==1) || (matrizjug1 [col][fila+5]==1) || (matrizjug1 [col][fila-1]==1) || (matrizjug1 [col-1][fila]==1) || (matrizjug1 [col+1][fila]==1) || (matrizjug1 [col-1][fila+1]==1) || (matrizjug1 [col+1][fila+1]==1) || (matrizjug1 [col-1][fila+2]==1) || (matrizjug1 [col+1][fila+2]==1) || (matrizjug1 [col-1][fila+3]==1) || (matrizjug1 [col+1][fila+3]==1) || (matrizjug1 [col-1][fila+4]==1) || (matrizjug1 [col+1][fila+4]==1))
	ubicar_portaaviones_jug1();
   matrizjug1 [col][fila]=1;
   matrizjug1 [col][fila+1]=1;
   matrizjug1 [col][fila+2]=1;
   matrizjug1 [col][fila+3]=1;
   matrizjug1 [col][fila+4]=1;
   gotoxy(col+12,fila+25);
   textcolor(4);
   cprintf ("²");
   gotoxy(col+12,fila+26);
   textcolor(4);
   cprintf("²");
   gotoxy(col+12,fila+27);
   textcolor(4);
   cprintf("²");
   gotoxy(col+12,fila+28);
   textcolor(4);
   cprintf("²");
   gotoxy(col+12,fila+29);
   textcolor(4);
   cprintf("²");
   interfase1a2();
   }
else ubicar_portaaviones_jug1();

}

//************ FIN DE UBICACION DE LOS BARCOS DEL JUGADOR 1 **************//


//*********************** PANTALLA INTERFASE ****************************//

void interfase1a2(void)
{
clrscr();
textcolor(2);
gotoxy(12,20); cprintf("AHORA ES EL TURNO DE QUE EL JUGADOR 2 UBIQUE SU FLOTA");
textcolor(14+BLINK);
gotoxy(22,30); cprintf("JUGADOR 1: RETIRESE DE LA PANTALLA");
textcolor(4);
gotoxy(41,50); cprintf ("Pulse cualquier tecla para continuar...");

// Re inicializaci¢n de todas las variables de ubicar barcos
contador_patrulleros=0;
contador_submarinos=0;
contador_acorazados=0;
contador_destructores=0;
getch();
getch();
clrscr();
grilla();
ubicar_patrulleros_jug2();
return;

}
//************************************************************************//

/****************** UBICACION DE FLOTA DEL JUGADOR 2 *********************/

//************** UBICACION DE PATRULLEROS DEL JUGADOR 2 ****************//

void ubicar_patrulleros_jug2(void)
{
textcolor(WHITE);
gotoxy(34,23); cprintf("   BUQUE         CELDAS");
gotoxy(34,27); cprintf(" Patrullero     1 celda");
gotoxy(34,29); cprintf(" Submarino      2 celdas");
gotoxy(34,31); cprintf(" Acorazado      3 celdas");
gotoxy(34,33); cprintf(" Destructor     4 celdas");
gotoxy(34,35); cprintf("Portaaviones    5 celdas");

textcolor(2);
gotoxy(47,23); cprintf("³");
gotoxy(47,24); cprintf("³");
gotoxy(33,25); cprintf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄ");
gotoxy(47,26); cprintf("³");
gotoxy(47,27); cprintf("³");
gotoxy(47,28); cprintf("³");
gotoxy(47,29); cprintf("³");
gotoxy(47,30); cprintf("³");
gotoxy(47,31); cprintf("³");
gotoxy(47,32); cprintf("³");
gotoxy(47,33); cprintf("³");
gotoxy(47,34); cprintf("³");
gotoxy(47,35); cprintf("³");
gotoxy(47,36); cprintf("³");

textcolor(2 + BLINK);
gotoxy(5,49);  cprintf("ÄÄÄÄÄÄÄÄÄÄ");
gotoxy(5,47);  cprintf("ÄÄÄÄÄÄÄÄÄÄ");
textcolor(15);
gotoxy(6,48);  cprintf("RECUERDE:");
gotoxy(18,47); cprintf("Los buques no pueden tocarse entre si, ni");
gotoxy(18,49); cprintf("ocupar la misma celda dentro de la grilla.");

textcolor(2);
gotoxy (34,2); cprintf("JUGADOR 2");
textcolor(15);
gotoxy(4,4);   cprintf("Seleccione coordenadas para EL %d§ PATRULLERO",contador_patrulleros+1);
gotoxy(4,8);   cprintf("¨COLUMNA? (A-J):");
textcolor(2);
gotoxy(24,7);  cprintf("É");
gotoxy(25,7);  cprintf("ÍÍ");
gotoxy(27,7);  cprintf("»");
gotoxy(24,8);  cprintf("º  º");
gotoxy(24,9);  cprintf("È  ¼");
gotoxy(25,9);  cprintf("ÍÍ");
textcolor(15);
gotoxy(4,14);  cprintf("¨FILA? (1-10):");
textcolor(2);
gotoxy(24,13); cprintf("É");
gotoxy(25,13); cprintf("ÍÍ");
gotoxy(27,13); cprintf("»");
gotoxy(24,14); cprintf("º  º");
gotoxy(24,15); cprintf("È  ¼");
gotoxy(25,15); cprintf("ÍÍ");
gotoxy(25,8);  cprintf("  ");
gotoxy(25,14); cprintf("  ");
gotoxy(60,11); cprintf("  ");
textcolor(15);
gotoxy(25,8);
cscanf ("%s",&col);
col=col-65;
while ((col<0) || (col>9))
	ubicar_patrulleros_jug2();
gotoxy(25,14);
cscanf ("%d",&fila);
fila=fila-1;
while ((fila<0) || (fila>9))
	ubicar_patrulleros_jug2();
if ((matrizjug2[col-1][fila]==1)||(matrizjug2[col+1][fila]==1)||(matrizjug2[col][fila-1]==1)||(matrizjug2[col][fila+1]==1)||(matrizjug2[col][fila]==1))
	ubicar_patrulleros_jug2();
matrizjug2 [col][fila]=1;
gotoxy(col+12,fila+25);
textcolor(2);
cprintf ("²");
contador_patrulleros++;
if (contador_patrulleros==5)    // Control del n£mero de Patrulleros.
	ubicar_submarinos_jug2();
ubicar_patrulleros_jug2();

}

//******************* UBICACION DE SUBMARINOS DEL JUGADOR 2 ****************//

void ubicar_submarinos_jug2(void)
{
textcolor(15);
gotoxy(4,4);   cprintf("Seleccione coordenadas para EL %d§ SUBMARINO ",contador_submarinos+1);
gotoxy(25,8);  cprintf("  ");
gotoxy(25,14); cprintf("  ");
gotoxy(60,11); cprintf("  ");
gotoxy(25,8);
cscanf ("%s",&col);
col=col-65;
while ((col<0) || (col>9))
	ubicar_submarinos_jug2();
gotoxy(25,14);
cscanf ("%d",&fila);
fila=fila-1;
if ((fila<0) || (fila>9))
	ubicar_submarinos_jug2();
gotoxy(31,11);
textcolor(15);
cprintf("Horiz.(H) o Vertical(V):");
textcolor(2);
gotoxy(59,10);  cprintf("É");
gotoxy(60,10);  cprintf("ÍÍ");
gotoxy(62,10);  cprintf("»");
gotoxy(59,11);  cprintf("º  º");
gotoxy(59,12);  cprintf("È  ¼");
gotoxy(60,12);  cprintf("ÍÍ");
gotoxy(60,11);  cprintf("  ");
textcolor(15);
gotoxy(60,11);
cscanf("%s",&hov);
if (hov==72) // Horizontal
   {
   if (col>=9)
	ubicar_submarinos_jug2();
   if ((matrizjug2 [col-1][fila]==1) || (matrizjug2 [col][fila]==1) || (matrizjug2 [col+1][fila]==1) || (matrizjug2 [col+2][fila]==1) || (matrizjug2 [col][fila-1]==1) || (matrizjug2 [col+1][fila-1]==1) || (matrizjug2 [col][fila+1]==1) || (matrizjug2 [col+1][fila+1]==1))
	ubicar_submarinos_jug2();
   matrizjug2 [col][fila]=1;
   matrizjug2 [col+1][fila]=1;
   gotoxy(col+12,fila+25);
   textcolor(2);
   cprintf ("²²");
   contador_submarinos++;
   if (contador_submarinos==4)
	ubicar_acorazados_jug2();
   ubicar_submarinos_jug2();
   }
if (hov==86) // Vertical
   {
   if (fila>=9)
	ubicar_submarinos_jug2();
   if ((matrizjug2[col][fila]==1) || (matrizjug2[col][fila+1]==1) || (matrizjug2[col][fila-1]==1) || (matrizjug2[col][fila+2]==1) || (matrizjug2[col-1][fila]==1) || (matrizjug2[col+1][fila]==1) || (matrizjug2[col-1][fila+1]==1) || (matrizjug2[col+1][fila+1]==1))
	ubicar_submarinos_jug2();
   matrizjug2 [col][fila]=1;
   matrizjug2 [col][fila+1]=1;
   gotoxy(col+12,fila+25);
   textcolor(2);
   cprintf ("²");
   gotoxy(col+12,fila+26);
   textcolor(2);
   cprintf("²");
   contador_submarinos++;
   if (contador_submarinos==4)  // Control del n£mero de Submarinos.
	ubicar_acorazados_jug2();
   ubicar_submarinos_jug2();
   }
else ubicar_submarinos_jug2();

}

//************************ UBICAR ACORAZADOS DEL JUGADOR 2 ****************//

void ubicar_acorazados_jug2(void)
{
textcolor(15);
gotoxy(4,4);   cprintf("Seleccione coordenadas para EL %d§ ACORAZADO",contador_acorazados+1);
gotoxy(25,8);  cprintf("  ");
gotoxy(25,14); cprintf("  ");
gotoxy(60,11); cprintf("  ");
gotoxy(25,8);
cscanf ("%s",&col);
col=col-65;
while ((col<0) || (col>9))
	ubicar_acorazados_jug2();
gotoxy(25,14);
cscanf ("%d",&fila);
fila=fila-1;
if ((fila<0) || (fila>9))
	ubicar_acorazados_jug2();
gotoxy(60,11);
cscanf("%s",&hov);
if (hov==72) // Horizontal
   {
   if (col>=8)
	ubicar_acorazados_jug2();
   if ((matrizjug2 [col][fila]==1) || (matrizjug2 [col+1][fila]==1) || (matrizjug2 [col+2][fila]==1) || (matrizjug2 [col-1][fila]==1) || (matrizjug2 [col+3][fila]==1) || (matrizjug2 [col][fila+1]==1) || (matrizjug2 [col][fila-1]==1) || (matrizjug2 [col+1][fila+1]==1) || (matrizjug2 [col+1][fila-1]==1) || (matrizjug2 [col+2][fila+1]==1) || (matrizjug2 [col+2][fila-1]==1))
	ubicar_acorazados_jug2();
   matrizjug2 [col][fila]=1;
   matrizjug2 [col+1][fila]=1;
   matrizjug2 [col+2][fila]=1;
   gotoxy(col+12,fila+25);
   textcolor(2);
   cprintf ("²²²");
   contador_acorazados++;
   if (contador_acorazados==3)
	ubicar_destructores_jug2();
   ubicar_acorazados_jug2();
   }
if (hov==86) // Vertical
   {
   if (fila>=8)
	ubicar_acorazados_jug2();
   if ((matrizjug2 [col][fila]==1) || (matrizjug2 [col][fila+1]==1) || (matrizjug2 [col][fila+2]==1) || (matrizjug2 [col][fila-1]==1) || (matrizjug2 [col][fila+3]==1) || (matrizjug2 [col-1][fila]==1) || (matrizjug2 [col-1][fila-1]==1) || (matrizjug2 [col-1][fila-2]==1) || (matrizjug2 [col+1][fila]==1) || (matrizjug2 [col+1][fila+1]==1) || (matrizjug2 [col+1][fila-2]==1))
	ubicar_acorazados_jug2();
   matrizjug2 [col][fila]=1;
   matrizjug2 [col][fila+1]=1;
   matrizjug2 [col][fila+2]=1;
   gotoxy(col+12,fila+25);
   textcolor(2);
   cprintf ("²");
   gotoxy(col+12,fila+26);
   textcolor(2);
   cprintf("²");
   gotoxy(col+12,fila+27);
   textcolor(2);
   cprintf("²");
   contador_acorazados++;
   if (contador_acorazados==3)  // Control del n£mero de Acorazados.
	ubicar_destructores_jug2();
   ubicar_acorazados_jug2();
   }
else
ubicar_acorazados_jug2();

}

//************** UBICAR DESTRUCTORES DEL JUGADOR 2 ****************//

void ubicar_destructores_jug2(void)
{
textcolor(15);
gotoxy(4,4);   cprintf("Seleccione coordenadas para EL %d§ DESTRUCTOR",contador_destructores+1);
gotoxy(25,8);  cprintf("  ");
gotoxy(25,14); cprintf("  ");
gotoxy(60,11); cprintf("  ");
gotoxy(25,8);
cscanf ("%s",&col);
col=col-65;
while ((col<0) || (col>9))
	ubicar_destructores_jug2();
gotoxy(25,14);
cscanf ("%d",&fila);
fila=fila-1;
if ((fila<0) || (fila>9))
	ubicar_destructores_jug2();
gotoxy(60,11);
cscanf("%s",&hov);

if (hov==72) // Horizontal
   {
   if (col>=7)
	ubicar_destructores_jug2();
   if ((matrizjug2 [col][fila]==1) || (matrizjug2 [col+1][fila]==1) || (matrizjug2 [col+2][fila]==1) || (matrizjug2 [col+3][fila]==1) || (matrizjug2 [col+4][fila]==1) || (matrizjug2 [col-1][fila]==1) || (matrizjug2 [col][fila-1]==1) || (matrizjug2 [col][fila+1]==1) || (matrizjug2 [col+1][fila-1]==1) || (matrizjug2 [col+1][fila+1]==1) || (matrizjug2 [col+2][fila-1]==1) || (matrizjug2 [col+2][fila+1]==1) || (matrizjug2 [col+3][fila-1]==1) || (matrizjug2 [col+3][fila+1]==1))
	ubicar_destructores_jug2();
   matrizjug2 [col][fila]=1;
   matrizjug2 [col+1][fila]=1;
   matrizjug2 [col+2][fila]=1;
   matrizjug2 [col+3][fila]=1;
   gotoxy(col+12,fila+25);
   textcolor(2);
   cprintf ("²²²²");
   contador_destructores++;
   if (contador_destructores==2)
	ubicar_portaaviones_jug2();
   ubicar_destructores_jug2();
   }
if (hov==86) // Vertical
   {
   if (fila>=7)
	ubicar_destructores_jug2();
   if ((matrizjug2 [col][fila]==1) || (matrizjug2 [col][fila+1]==1) || (matrizjug2 [col][fila+2]==1) || (matrizjug2 [col][fila+3]==1) || (matrizjug2 [col][fila-1]==1) || (matrizjug2 [col][fila+4]==1) || (matrizjug2 [col-1][fila]==1) || (matrizjug2 [col+1][fila]==1) || (matrizjug2 [col-1][fila+1]==1) || (matrizjug2 [col+1][fila+1]==1) || (matrizjug2 [col-1][fila+2]==1) || (matrizjug2 [col+1][fila+2]==1) || (matrizjug2 [col-1][fila+3]==1) || (matrizjug2 [col+1][fila+3]==1))
	ubicar_destructores_jug2();
   matrizjug2 [col][fila]=1;
   matrizjug2 [col][fila+1]=1;
   matrizjug2 [col][fila+2]=1;
   matrizjug2 [col][fila+3]=1;
   gotoxy(col+12,fila+25);
   textcolor(2);
   cprintf ("²");
   gotoxy(col+12,fila+26);
   textcolor(2);
   cprintf("²");
   gotoxy(col+12,fila+27);
   textcolor(2);
   cprintf("²");
   gotoxy(col+12,fila+28);
   textcolor(2);
   cprintf("²");
   contador_destructores++;
   if (contador_destructores==2) // Control del n£mero de Destructores.
	ubicar_portaaviones_jug2();
   ubicar_destructores_jug2();
   }
else ubicar_destructores_jug2();

}

//************** UBICAR PORTAAVIONES DEL JUGADOR 2 ****************//

void ubicar_portaaviones_jug2(void)
{
textcolor(15);
gotoxy(4,4);   cprintf("Seleccione coordenadas para EL PORTAAVIONES");
gotoxy(25,8);  cprintf("  ");
gotoxy(25,14); cprintf("  ");
gotoxy(60,11); cprintf("  ");
gotoxy(25,8);
cscanf ("%s",&col);
col=col-65;
while ((col<0) || (col>9))
	ubicar_portaaviones_jug2();
gotoxy(25,14);
cscanf ("%d",&fila);
fila=fila-1;
if ((fila<0) || (fila>9))
	ubicar_portaaviones_jug2();
gotoxy(60,11);
cscanf("%s",&hov);

if (hov==72) // Horizontal
   {
   if (col>=6)
	ubicar_portaaviones_jug2();
   if ((matrizjug2 [col][fila]==1) || (matrizjug2 [col+1][fila]==1) || (matrizjug2 [col+2][fila]==1) || (matrizjug2 [col+3][fila]==1) || (matrizjug2 [col+4][fila]==1) || (matrizjug2 [col+5][fila]==1) || (matrizjug2 [col-1][fila]==1) || (matrizjug2 [col][fila-1]==1) || (matrizjug2 [col][fila+1]==1) || (matrizjug2 [col+1][fila-1]==1) || (matrizjug2 [col+1][fila+1]==1) || (matrizjug2 [col+2][fila-1]==1) || (matrizjug2 [col+2][fila+1]==1) || (matrizjug2 [col+3][fila-1]==1) || (matrizjug2 [col+3][fila+1]==1) || (matrizjug2 [col+4][fila-1]==1) || (matrizjug2 [col+4][fila+1]==1))
	ubicar_portaaviones_jug2();
   matrizjug2 [col][fila]=1;
   matrizjug2 [col+1][fila]=1;
   matrizjug2 [col+2][fila]=1;
   matrizjug2 [col+3][fila]=1;
   matrizjug2 [col+4][fila]=1;
   gotoxy(col+12,fila+25);
   textcolor(2);
   cprintf ("²²²²²");
   comienzo_batalla();
   }
if (hov==86) // Vertical
   {
   if (fila>=6)
	ubicar_portaaviones_jug2();
   if ((matrizjug2 [col][fila]==1) || (matrizjug2 [col][fila+1]==1) || (matrizjug2 [col][fila+2]==1) || (matrizjug2 [col][fila+3]==1) || (matrizjug2 [col][fila+4]==1) || (matrizjug2 [col][fila+5]==1) || (matrizjug2 [col][fila-1]==1) || (matrizjug2 [col-1][fila]==1) || (matrizjug2 [col+1][fila]==1) || (matrizjug2 [col-1][fila+1]==1) || (matrizjug2 [col+1][fila+1]==1) || (matrizjug2 [col-1][fila+2]==1) || (matrizjug2 [col+1][fila+2]==1) || (matrizjug2 [col-1][fila+3]==1) || (matrizjug2 [col+1][fila+3]==1) || (matrizjug2 [col-1][fila+4]==1) || (matrizjug2 [col+1][fila+4]==1))
	ubicar_portaaviones_jug2();
   matrizjug2 [col][fila]=1;
   matrizjug2 [col][fila+1]=1;
   matrizjug2 [col][fila+2]=1;
   matrizjug2 [col][fila+3]=1;
   matrizjug2 [col][fila+4]=1;
   gotoxy(col+12,fila+25);
   textcolor(2);
   cprintf ("²");
   gotoxy(col+12,fila+26);
   textcolor(2);
   cprintf("²");
   gotoxy(col+12,fila+27);
   textcolor(2);
   cprintf("²");
   gotoxy(col+12,fila+28);
   textcolor(2);
   cprintf("²");
   gotoxy(col+12,fila+29);
   textcolor(2);
   cprintf("²");
   comienzo_batalla();
   }
else
ubicar_portaaviones_jug2();

}
//************ FIN DE UBICACION DE LOS BARCOS DEL JUGADOR 2 **************//

void comienzo_batalla(void) // Presenta el inicio del juego.
{
clrscr();
textcolor(14+BLINK); gotoxy(20,23); cprintf("­­­ QUE COMIENCE LA BATALLA NAVAL !!!");
textcolor(4); gotoxy(41,50); cprintf ("Pulse cualquier tecla para continuar...");

textcolor(4);
gotoxy(30,35);  cprintf("                 |`-:_\n");
gotoxy(30,36);  cprintf("   ---...___     |    `+.\n");
gotoxy(30,37);  cprintf("  (     _   ```..|____  |\n");
gotoxy(30,38);  cprintf("  \\    (_)               ````---...\n");
gotoxy(30,39);  cprintf("   \\                               ``--.._\n");
textcolor(9);
gotoxy(30,40);  cprintf(".   )`.\  )`.   )`.   )`.   )`.   )`.  )`.  )  \n");
gotoxy(30,41);  cprintf(" `-'  `-'   `-'   `-'   `-'   `-'   `-'  `-'    \n");

//	 MUSICA
sound(580); delay(200); nosound();
sound(700); delay(200); nosound();
sound(800); delay(200); nosound();
sound(950); delay(300); nosound();
sound(800); delay(200); nosound();
sound(950); delay(400); nosound();

getch();
getch();
tiro_jug1();
return;
}

//************************* COMIENZO DE LOS TIROS *************************//

void tiro_jug1(void)
{
clrscr();
mostrar_fondo();
textcolor(12);
gotoxy(11,40);  cprintf("LLEVAS EFECTUADOS %d DISPAROS.",tirosjug1);
gotoxy(11,42);  cprintf("%d DE ELLOS FUERON IMPACTOS DIRECTOS.",tenb1);
textcolor(11);
gotoxy(7,40);   cprintf("*");
gotoxy(7,42);   cprintf("*");
textcolor(4);
gotoxy(32,4);  cprintf("JUGADOR 1");
textcolor(15);
gotoxy(25,13);
cscanf ("%s",&col);
col=col-65;
while ((col<0) || (col>9))
	tiro_jug1();
col=col+65;
tiroscoljug1[b]=col;
col=col-65;
gotoxy(25,19);
scanf ("%d",&fila);
fila--;
while ((fila<0) || (fila>9))
	tiro_jug1();
fila++;
tirosfilajug1[b]=fila;
b++;
fila--;
if (matrizjug2[col][fila]==2)
	{
	textcolor(14+BLINK); gotoxy(26,31); cprintf("­USTED YA TIRO AHI!"); getch(); getch(); tiro_jug1();
	}
if (matrizjug2[col][fila]==1)
   {
   gotoxy(26,31);
   textcolor(12+BLINK);
   cprintf("­ IMPACTO DIRECTO !");
   matrizjug2[col][fila]=2; // Para asegurarse que ya tiro ah¡.
   bpjug2--;  // bpjug2 son los blacos posibles en el tablero del Jugador 2.
   tenb1++;
   tirosjug1++;
   if (bpjug2==0)
	mostrar_ganador_jug1();
   }
   else
   {
   gotoxy(29,31);
   textcolor(9+BLINK);
   cprintf("­­­ AGUA !!!");
   tirosjug1++;
   }
getch();
getch();
tiro_jug2();
return;
}

void tiro_jug2(void)
{
clrscr();
mostrar_fondo();
textcolor(2);
gotoxy(11,40);  cprintf("LLEVAS EFECTUADOS %d DISPAROS.",tirosjug2);
gotoxy(11,42);  cprintf("%d DE ELLOS FUERON IMPACTOS DIRECTOS.",tenb2);
textcolor(11);
gotoxy(7,40);   cprintf("*");
gotoxy(7,42);   cprintf("*");
textcolor(2); gotoxy(32,4); cprintf("JUGADOR 2");
textcolor(15);
gotoxy(25,13);
cscanf ("%s",&col);
col=col-65;
while ((col<0) || (col>9))
	tiro_jug2();
col=col+65;
tiroscoljug2[m]=col;
col=col-65;
gotoxy(25,19);
scanf ("%d",&fila);
fila--;
while ((fila<0) || (fila>9))
	tiro_jug2();
fila++;
tirosfilajug2[m]=fila;
m++;
fila--;
if (matrizjug1[col][fila]==2)
	{
	textcolor(YELLOW+BLINK); gotoxy(26,31); cprintf("­USTED YA TIRO AHI!"); getch(); getch(); tiro_jug2();
	}
if (matrizjug1[col][fila]==1)
   {
   gotoxy(26,31);
   textcolor(12+BLINK);
   cprintf("­ IMPACTO DIRECTO !");
   matrizjug1[col][fila]=2; // Para asegurarse que ya tiro ah¡.
   bpjug1--; // bpjug1 son los blancos posibles en el tablero del Jugador 1.
   tenb2++;
   tirosjug2++;
   if (bpjug1==0)
	mostrar_ganador_jug2();
   }
   else
   {
   gotoxy(29,31);
   textcolor(9+BLINK);
   cprintf("­­­ AGUA !!!");
   tirosjug2++;
   }
getch();
getch();
tiro_jug1();
return;
}
//**************************GANADOR JUGADOR 1******************************//

void mostrar_ganador_jug1(void)
{
_setcursortype(_NOCURSOR);
clrscr();
gotoxy(3,2);
textcolor(4+BLINK);

gotoxy(27,18); cprintf("ÛÛÛÛ   ÛÛ   Û  Û  ÛÛÛÛ");
gotoxy(27,19); cprintf("Û     Û  Û  ÛÛ Û  Û  Û");
gotoxy(27,20); cprintf("Û ÛÛ  ÛÛÛÛ  Û ÛÛ  Û  Û");
gotoxy(27,21); cprintf("ÛÛÛÛ  Û  Û  Û  Û  ÛÛÛÛ");

gotoxy(34,25); cprintf("ÛÛÛÛ  ÛÛ");
gotoxy(34,26); cprintf("ÛÜÜ   ÛÛ");
gotoxy(34,27); cprintf("Ûßß   ÛÛ");
gotoxy(34,28); cprintf("ÛÛÛÛ  ÛÛÛÛ");

gotoxy(15,32); cprintf("  ÛÛÛÛ  Û  Û  ÛÛÛÛ   ÛÛ   ÛßÜ   ÛÛÛÛ  ÛÛÛÛ      ÛÛ");
gotoxy(15,33); cprintf("   ÛÛ   Û  Û  Û     Û  Û  Û  Û  Û  Û  Û  Û     Û Û");
gotoxy(15,34); cprintf(" Û ÛÛ   Û  Û  Û ÛÛ  ÛÛÛÛ  Û  Û  Û  Û  Û ßÜ       Û");
gotoxy(15,35); cprintf(" ÛÛÛÛ   ÛÛÛÛ  ÛÛÛÛ  Û  Û  ÛÜß   ÛÛÛÛ  Û  Û     ÜÜÛÜÜ");

textcolor(11);
gotoxy(4,9);  cprintf("    .....     ");
gotoxy(4,10); cprintf("  ,,,,,,,,,   ");
gotoxy(4,11); cprintf(" ...........  ");
gotoxy(4,12); cprintf(",,,,,,,,,,,,, ");
gotoxy(4,13); cprintf(",,,,,,,,,,,,, ");
gotoxy(4,14); cprintf(",,,,,,,,,,,,, ");
gotoxy(4,15); cprintf(" ,,,,,,,,,,,  ");
gotoxy(4,16); cprintf("  ,,,,,,,,,   ");
gotoxy(4,17); cprintf("   ,,,,,,,    ");
gotoxy(4,18); cprintf("    .....     ");
gotoxy(4,19); cprintf("     ...      ");
gotoxy(4,20); cprintf("      .       ");
gotoxy(4,21); cprintf("     '        ");
gotoxy(4,22); cprintf("    `         ");
gotoxy(4,23); cprintf("   `          ");
gotoxy(4,24); cprintf("  `           ");
gotoxy(4,25); cprintf(" `            ");
gotoxy(4,26); cprintf(" `            ");
gotoxy(4,27); cprintf(" `            ");
gotoxy(4,28); cprintf("  `           ");
gotoxy(4,29); cprintf("   `          ");
gotoxy(4,30); cprintf("    `         ");
gotoxy(4,31); cprintf("     '        ");

gotoxy(65,9);  cprintf("    .....    ");
gotoxy(65,10); cprintf("  ,,,,,,,,,  ");
gotoxy(65,11); cprintf(" ........... ");
gotoxy(65,12); cprintf(",,,,,,,,,,,,,");
gotoxy(65,13); cprintf(",,,,,,,,,,,,,");
gotoxy(65,14); cprintf(",,,,,,,,,,,,,");
gotoxy(65,15); cprintf(" ,,,,,,,,,,, ");
gotoxy(65,16); cprintf("  ,,,,,,,,,  ");
gotoxy(65,17); cprintf("   ,,,,,,,   ");
gotoxy(65,18); cprintf("    .....     ");
gotoxy(65,19); cprintf("     ...      ");
gotoxy(65,20); cprintf("      .       ");
gotoxy(65,21); cprintf("      '       ");
gotoxy(65,22); cprintf("       `      ");
gotoxy(65,23); cprintf("        `     ");
gotoxy(65,24); cprintf("         `    ");
gotoxy(65,25); cprintf("          `    ");
gotoxy(65,26); cprintf("          `    ");
gotoxy(65,27); cprintf("          `    ");
gotoxy(65,28); cprintf("         `     ");
gotoxy(65,29); cprintf("        `      ");
gotoxy(65,30); cprintf("       `       ");
gotoxy(65,31); cprintf("      '        ");

textcolor(9); gotoxy(39,50); cprintf("Presione cualquier tecla para continuar...");

sound(500); delay(200); nosound();
sound(400); delay(250); nosound();
sound(550); delay(200); nosound();
sound(900); delay(800); nosound();
sound(500); delay(200); nosound();
sound(600); delay(380); nosound();
sound(200); delay(150); nosound();
sound(150); delay(600); nosound();
sound(300); delay(500); nosound();

getch(); getch();
estadisticas();
return;
}
//****************************GANADOR JUGADOR 2****************************//

void mostrar_ganador_jug2(void)
{
_setcursortype(_NOCURSOR);
clrscr();
gotoxy(3,2);
textcolor(2+BLINK);
gotoxy(27,18); cprintf("ÛÛÛÛ   ÛÛ   Û  Û  ÛÛÛÛ");
gotoxy(27,19); cprintf("Û     Û  Û  ÛÛ Û  Û  Û");
gotoxy(27,20); cprintf("Û ÛÛ  ÛÛÛÛ  Û ÛÛ  Û  Û");
gotoxy(27,21); cprintf("ÛÛÛÛ  Û  Û  Û  Û  ÛÛÛÛ");

gotoxy(34,25); cprintf("ÛÛÛÛ  ÛÛ");
gotoxy(34,26); cprintf("ÛÜÜ   ÛÛ");
gotoxy(34,27); cprintf("Ûßß   ÛÛ");
gotoxy(34,28); cprintf("ÛÛÛÛ  ÛÛÛÛ");

gotoxy(15,32); cprintf("  ÛÛÛÛ  Û  Û  ÛÛÛÛ   ÛÛ   ÛßÜ   ÛÛÛÛ  ÛÛÛÛ      ßßßßßÜ");
gotoxy(15,33); cprintf("   ÛÛ   Û  Û  Û     Û  Û  Û  Û  Û  Û  Û  Û           Û");
gotoxy(15,34); cprintf(" Û ÛÛ   Û  Û  Û ÛÛ  ÛÛÛÛ  Û  Û  Û  Û  Û ßÜ      Ûßßßß");
gotoxy(15,35); cprintf(" ÛÛÛÛ   ÛÛÛÛ  ÛÛÛÛ  Û  Û  ÛÜß   ÛÛÛÛ  Û  Û      ÛÜÜÜÜÜ");

textcolor(11);
gotoxy(4,9);  cprintf("    .....     ");
gotoxy(4,10); cprintf("  ,,,,,,,,,   ");
gotoxy(4,11); cprintf(" ...........  ");
gotoxy(4,12); cprintf(",,,,,,,,,,,,, ");
gotoxy(4,13); cprintf(",,,,,,,,,,,,, ");
gotoxy(4,14); cprintf(",,,,,,,,,,,,, ");
gotoxy(4,15); cprintf(" ,,,,,,,,,,,  ");
gotoxy(4,16); cprintf("  ,,,,,,,,,   ");
gotoxy(4,17); cprintf("   ,,,,,,,    ");
gotoxy(4,18); cprintf("    .....     ");
gotoxy(4,19); cprintf("     ...      ");
gotoxy(4,20); cprintf("      .       ");
gotoxy(4,21); cprintf("     '        ");
gotoxy(4,22); cprintf("    `         ");
gotoxy(4,23); cprintf("   `          ");
gotoxy(4,24); cprintf("  `           ");
gotoxy(4,25); cprintf(" `            ");
gotoxy(4,26); cprintf(" `            ");
gotoxy(4,27); cprintf(" `            ");
gotoxy(4,28); cprintf("  `           ");
gotoxy(4,29); cprintf("   `          ");
gotoxy(4,30); cprintf("    `         ");
gotoxy(4,31); cprintf("     '        ");

gotoxy(65,9);  cprintf("    .....    ");
gotoxy(65,10); cprintf("  ,,,,,,,,,  ");
gotoxy(65,11); cprintf(" ........... ");
gotoxy(65,12); cprintf(",,,,,,,,,,,,,");
gotoxy(65,13); cprintf(",,,,,,,,,,,,,");
gotoxy(65,14); cprintf(",,,,,,,,,,,,,");
gotoxy(65,15); cprintf(" ,,,,,,,,,,, ");
gotoxy(65,16); cprintf("  ,,,,,,,,,  ");
gotoxy(65,17); cprintf("   ,,,,,,,   ");
gotoxy(65,18); cprintf("    .....     ");
gotoxy(65,19); cprintf("     ...      ");
gotoxy(65,20); cprintf("      .       ");
gotoxy(65,21); cprintf("      '       ");
gotoxy(65,22); cprintf("       `      ");
gotoxy(65,23); cprintf("        `     ");
gotoxy(65,24); cprintf("         `    ");
gotoxy(65,25); cprintf("          `    ");
gotoxy(65,26); cprintf("          `    ");
gotoxy(65,27); cprintf("          `    ");
gotoxy(65,28); cprintf("         `     ");
gotoxy(65,29); cprintf("        `      ");
gotoxy(65,30); cprintf("       `       ");
gotoxy(65,31); cprintf("      '        ");

textcolor(9); gotoxy(39,50); cprintf("Presione cualquier tecla para continuar...");

sound(500); delay(200); nosound();
sound(400); delay(250); nosound();
sound(550); delay(200); nosound();
sound(900); delay(800); nosound();
sound(500); delay(200); nosound();
sound(600); delay(380); nosound();
sound(200); delay(150); nosound();
sound(150); delay(600); nosound();
sound(300); delay(500); nosound();

getch(); getch();
estadisticas();
return;
}

//*************************** ESTADISTICAS DEL JUEGO **********************//

void estadisticas(void)
{
_setcursortype(_NOCURSOR);
pintar_menu_estad();

// Efectividad del Jugador 1.

textcolor(15);
gotoxy(30,13); cprintf("%d",tirosjug1);
gotoxy(12,15); cprintf("%d",tenb1);

// Calificaci¢n del Jugador 1.

efectiv1=tirosjug1-tenb1;
gotoxy(17,10);
if (efectiv1>=20)
	cprintf("MARINERO FEO");
if ((efectiv1<=19) && (efectiv1>=10))
	cprintf("COMANDANTE");
if ((efectiv1<10) && (efectiv1>=5))
	cprintf("CAPITAN");
if ((efectiv1<5) && (efectiv1>=0))
	{
	textcolor(14+BLINK); cprintf("HEROE");
	}

// Tiros efectuados del Jugador 1.

gotoxy(1,19);
for(x=0;x<b;x++)
{
textcolor(15); cprintf("%c-%d, ",tiroscoljug1[x], tirosfilajug1[x]);
}

// Efectividad del Jugador 2.

textcolor(15);
gotoxy(30,33); cprintf("%d",tirosjug2);
gotoxy(12,35); cprintf("%d",tenb2);

// Calificaci¢n  del jugador 2.

efectiv2=tirosjug2-tenb2;
gotoxy(17,30);
if (efectiv2>=20)
	cprintf("MARINERO FEO");
if ((efectiv2>=10) && (efectiv2<=19))
	cprintf("COMANDANTE");
if ((efectiv2>=5) && (efectiv2<=9))
	cprintf("CAPITAN");
if ((efectiv2<5) && (efectiv2>=0))
	{
	textcolor(14+BLINK); cprintf("HEROE");
	}

// Tiros efectuados del Jugador 2.

gotoxy(1,39);
for(x=0;x<m;x++)
{
textcolor(15); cprintf("%c-%d, ",tiroscoljug2[x], tirosfilajug2[x]);
}
getch();
bpjug1=34; bpjug2=34;
b=0; m=0;
tenb1=0; tenb2=0;
tirosjug1=0; tirosjug2=0;
efectiv1=0; efectiv2=0;
contador_patrulleros=0;
contador_submarinos=0;
contador_acorazados=0;
contador_destructores=0;
inic_matrizjug1();
inic_matrizjug2();
pre_ubicar_barcos();

return;
}
//************************ GRAFICO DE INGRESOS DE BARCOS ********************//

void mostrar_fondo(void)
{
clrscr();
textcolor(15);
gotoxy(4,6);   cprintf("Seleccione coordenadas para lanzar la bomba:");
gotoxy(4,13);  cprintf("COLUMNA (A-J):");
gotoxy (4,19); cprintf("FILA (1-10):");
textcolor(15);
gotoxy(24,12); cprintf("É");
gotoxy(25,12); cprintf("ÍÍ");
gotoxy(27,12); cprintf("»");
gotoxy(24,13); cprintf("º  º");
gotoxy(24,14); cprintf("È  ¼");
gotoxy(25,14); cprintf("ÍÍ");
gotoxy(24,18); cprintf("É");
gotoxy(25,18); cprintf("ÍÍ");
gotoxy(27,18); cprintf("»");
gotoxy(24,19); cprintf("º  º");
gotoxy(24,20); cprintf("È  ¼");
gotoxy(25,20); cprintf("ÍÍ");
gotoxy(24,30); cprintf("ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ");
gotoxy(24,32); cprintf("ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ");
gotoxy(24,30); cprintf("É");
gotoxy(24,32); cprintf("È");
gotoxy(24,31); cprintf("º");
gotoxy(46,31); cprintf("º");
gotoxy(46,30); cprintf("»");
gotoxy(46,32); cprintf("¼");
gotoxy(16,31); cprintf("INFORME:");
return;
}
//*************************GRAFICOS DE ESTADISTICAS**********************//

void pintar_menu_estad(void)
{
clrscr();
textcolor(14);
gotoxy(20,3); cprintf("*********** RESUMEN DEL JUEGO ***********");
textcolor(4);
gotoxy(9,7);  cprintf("JUGADOR 1");
textcolor(15);
gotoxy(1,10); cprintf("Calificaci¢n:");
gotoxy(1,13); cprintf("Total de bombas lanzadas:");
gotoxy(1,15); cprintf("Aciertos:");
gotoxy(1,17); cprintf("Detalle de disparos efectuados:");

textcolor(2);
gotoxy(9,27); cprintf("JUGADOR 2");
textcolor(15);
gotoxy(1,30); cprintf("Calificaci¢n:");
gotoxy(1,33); cprintf("Total de bombas lanzadas:");
gotoxy(1,35); cprintf("Aciertos:");
gotoxy(1,37); cprintf("Detalle de disparos efectuados:");
textcolor(9+BLINK);
gotoxy(38,50); cprintf("Presione una tecla para volver a jugar...");
salir;
return;

}
//**************************** FIN *************************************//