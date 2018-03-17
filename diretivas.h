//Diretivas para saber qual SO é usado pelo usuario.
#if defined(_WIN32) || defined(WIN32) //se o SO for windows define uma macro OS_WINDOWS.
   #define OS_Windows
#endif

void limpar_tela(){
#ifdef OS_Windows //se a macro for definida usa cls.
    system("cls");
#else
    system("clear"); // se nao usa clear para o linux.
#endif 
}

void pause(void) {
	printf ("Precione enter para continuar.");
	getchar();
}

