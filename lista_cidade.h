typedef struct no{
char Nome_Cidade[20];
struct no * ant;
struct no * next;
}NO;
typedef NO * LISTA_ENC;

LISTA_ENC vetor[MAX];
static int count = 0;

void imprime_lista(LISTA_ENC );
int eh_vazia (LISTA_ENC );
int tam (LISTA_ENC );
void insere_lista(char );
void cria_lista(LISTA_ENC *);

void insere_lista(char string[]){
	NO *novo;
	int count2 = tam(vetor[count]) + 1;
	novo = (NO*) malloc (sizeof(NO));
	if (!novo){ 
		printf ("\nERRO! Memoria insuficiente!\n");
		exit (2); 
	}
	if (count2 < 1 || count2 > tam(vetor[count])+1){
		printf ("\nERRO! Posição invalida para insercao.\n");
		exit (1);
	}
	strcpy(novo->Nome_Cidade,string);
	if (!vetor[count]){
			novo->next = novo->ant = NULL;
			vetor[count] = novo;

	}else{
	LISTA_ENC aux;
	for (aux=vetor[count]; count2>2; aux=aux->next, count2--);
		novo->ant= aux;
		novo->next = aux->next;
		aux->next = novo;
	}
}

void insereListaRodovias(LISTA_ENC *pl, char string[]){
NO *novo;
int count2 = tam(*pl) + 1;
	novo = (NO*) malloc (sizeof(NO));
	if (!novo){ 
		printf ("\nERRO! Memoria insuficiente!\n");
		exit (2); 
	}
	if (count2 < 1 || count2 > tam(*pl)+1){
		printf ("\nERRO! Posição invalida para insercao.\n");
		exit (1);
	}
	strcpy(novo->Nome_Cidade,string);
	if (count2 == 1){
			novo->next = novo->ant = NULL;
			*pl = novo;

	}else{
	LISTA_ENC aux;
	for (aux=*pl; count2>2; aux=aux->next, count2--);
	novo->ant= aux;
	novo->next = aux->next;
	aux->next = novo;
	}
}
void imprime_lista(LISTA_ENC l){
	NO* aux = (NO *) malloc (sizeof(NO));

		for(aux = l;l!= NULL;l=l->next){
			printf ("%s \n",l->Nome_Cidade);
		}
		printf ("\n");
	l = aux; 
}

int tam (LISTA_ENC l){
int cont;
	for (cont=0; l!= NULL; cont++)
		l = l->next;
	return (cont);
}

int eh_vazia (LISTA_ENC l){
	if (l == NULL){
		printf ("Eh Vazia!\n");
		return (l == NULL);
	}else{
		return 0;
	}
}

void cria_lista(LISTA_ENC *pl){
	*pl=NULL;
}
