typedef struct nodo{
char rodovia[10];
struct no * cidade; //recebe uma cidade
struct nodo * prox;  //recebe a proxima rodovia
}NODO;

typedef struct{
NODO *INICIO;
NODO *FIM;
}DESCRITOR;

typedef DESCRITOR * FILA_ENC;
void cria_rodovia (FILA_ENC *);
int eh_vazia1 (FILA_ENC);
void enfileira (FILA_ENC, char);
void consulta_rodovia(FILA_ENC , char *);


void cria_rodovia (FILA_ENC *pf){
*pf=(DESCRITOR *)malloc(sizeof(DESCRITOR));
	if (!*pf){
		printf ("\nERRO! Memoria insuficiente!\n");
		exit (1);
	}
	(*pf)->INICIO=(*pf)->FIM=NULL;
}


int eh_vazia1 (FILA_ENC f){
	return (f->INICIO == NULL);
}

void insereRodovia (FILA_ENC f, char string[]){
	NODO *novo;
	novo = (NODO *) malloc (sizeof(NODO));
	if (!novo){
		printf ("\nERRO! Memoria insuficiente!\n");
		exit (1);
	}

	strcpy(novo->rodovia,string);
	novo->prox = NULL;
	novo->cidade = NULL;
	if (eh_vazia1(f))
		f->INICIO=f->FIM=novo;
	else
		f->FIM->prox=novo;
		f->FIM=novo;
}

void consulta_rodovia(FILA_ENC f, char string[]){
	NODO *recup = f->INICIO;
		while (f->INICIO != NULL){
			if (strcmp(f->INICIO->rodovia, string) == 0){
				printf ("Rodovia Encontrada!\n");
				break;
			}
			f->INICIO = f->INICIO->prox;
		}
		if (f->INICIO == NULL){
			printf ("Rodovia n Encontrada!\n");
		}
	f->INICIO = recup;
}

void imprime_rodovias(FILA_ENC f){
	NODO * recup = (NODO*) malloc (sizeof(NODO));
	if (!recup){
		printf ("ERRO! falha na alocacao.\n");
		exit(0);
	}
	printf ("Rodovias Cadastradas.\n");
	for(recup = f->INICIO; recup; recup = recup->prox){
		printf ("[Rodovias: %s ]\n", recup->rodovia);
	}
	
}



