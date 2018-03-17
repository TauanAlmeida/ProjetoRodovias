#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#define MAX 5
#include "diretivas.h"
#include "fila_rodovia.h"
#include "lista_cidade.h"

FILA_ENC  r; 
void cadastrar_rodovia();
void insereCidade(char nomeRodovia[], char nomeCidade[]);
void imprime_all();
LISTA_ENC rodoviasCidade(char nomeCidade[]);
bool Cruzamento(char nomeRodovia[],  char nomeRodovia2[]);

int main (){
	cria_rodovia(&r);
	char opcao;
	while(opcao!='s' && 'S'){
	menu:
	  printf(" %c----------------------------------------------------------------------------%c\n",201,187);
      printf(" | ");printf("\t\t\t     PROGRAMA RODOVIAS");printf("\t\t\t              |\n");
      printf(" %c----------------------------------------------------------------------------%c\n",200,188);
      printf("\t       %c----------%c\t\t\t\t       ",201,187);
      printf("\t\t\t               |   MENU   ");printf("|\t\t\t\t      \n");
      printf("   %c-----------%c----------%c------------%c \n",201,200,188,187);
      printf("   | <A>  Adicionar Rodovia            |                 By Tauan Almeida\n");
      printf("   |-----------------------------------|\n");
      printf("   | <B>  Consulta Cidade              |\n");      
      printf("   |-----------------------------------|\n");
      printf("   | <C>  Consulta Cruzamento          |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <D>  Ver Tudo                     |\n"); 
      printf("   |-----------------------------------|\n");
      printf("   | <E>  Sobre Nos                    |\n"); 
      printf("   |-----------------------------------|\n");
      printf("   | <S>  Sair                         |\n"); 
      printf("   %c-----------------------------------%c",200,188);
      printf("\n");
    
   	  fflush(stdin);
      opcao= getch(); 
		switch (opcao){
	
		case 'A':
	    case 'a':
	    	limpar_tela();
	    	cadastrar_rodovia();
	    	pause();
	    	limpar_tela(); 
			if (vetor[count])++count;  
		break;
		
		case 'B':
	    case 'b':
	     limpar_tela();
		char nome_cidade[20];
		printf ("Qual cidade voce deseja buscar?");
		scanf ("%s", &nome_cidade);
		imprime_lista(rodoviasCidade(nome_cidade));
	 	fflush(stdin);
		pause();
		limpar_tela();
		break;
		
		case 'C':
		case 'c':
		limpar_tela();
		char nomeRod[20], nomeRod2[20];	
		printf ("Para ver os cruzamento entre rodovias basta dizer o nome de duas rodovias cadastradas.\n");
		imprime_rodovias(r);
		printf ("\nDigite o nome da primeira rodovia: ");
		scanf ("%s", &nomeRod);
		printf ("\n");
		printf ("Digite o nome da segunda rodovia: ");
		scanf ("%s", &nomeRod2);
		Cruzamento(nomeRod,  nomeRod2);
		fflush(stdin);
		pause();
		limpar_tela();
		break;
		
		case 'D':
		case 'd':
		limpar_tela();
		imprime_all();
		pause();
	    limpar_tela();
		break;
		
		case 'E':
		case 'e':
			limpar_tela();
			printf ("\nEste programa foi feito para disciplina de estrutura dados em algoritmos\norientado pelo professor Felipe Pinheiros do Instituto Federal do Sertao\nPernambucano.\n\
			\nCriando em: 16/06/2018\nDesenvolvido por Tauan Almeida.\
			\nCodigo disponivel em: https:\\\\github.com\\TauanAlmeida\n\n");
			pause();
			limpar_tela();
		break;
		
		case 'S':
		case 's':
		limpar_tela();
		printf ("\nVoce saiu com sucesso!\n");
		exit(0);
		break;	
		default:
			limpar_tela();
	}
	}
}

LISTA_ENC rodoviasCidade(char nomeCidade[]){
	LISTA_ENC t;
	cria_lista(&t);
	int achou = 0;
	no * backup_lista = (no*) malloc (sizeof(NO));
	NODO *  backup_fila = (NODO*) malloc (sizeof(NODO));
	if (!backup_lista || !backup_fila){
		printf ("Falha ao alocar memoria!\n");
		return 0;
	}	
	if (eh_vazia1 (r)){
		printf ("Cadastre pelo menos uma rodovia antes de vim aqui!\n");
		pause();
		return 0;
	}
	for (backup_fila = r->INICIO; backup_fila;backup_fila = backup_fila->prox){
		for(backup_lista = backup_fila->cidade; backup_lista; backup_lista = backup_lista->next){
			if (strcmp(backup_lista->Nome_Cidade, nomeCidade) == 0){
				insereListaRodovias(&t, backup_fila->rodovia);
				achou = 1;
			}
		}
	}
	if (achou){
		printf ("Rodovias que passam por %s sao: \n", nomeCidade);
	}else{
		printf ("essa cidade %s nao possui nenhuma rodovia cadastrada!\n",nomeCidade);
		pause();
		return 0;
	}	
	free(backup_lista);
	free(backup_fila);
	return t;
}

void cadastrar_rodovia(){
	char NomeRodovia[20], nomeCidade[20];
	printf ("Cadastre uma rodovia: ");
	scanf ("%s", &NomeRodovia);
	insereRodovia(r, NomeRodovia);
	printf ("Rodovia Inserida!\n");	
	printf ("Agora cadastre a cidade para a rodovia %s!\n\n", NomeRodovia);
	do{
		printf ("Digite o nome da cidade ou ('s') para sair: ");
		scanf ("%s", &nomeCidade);
		if (strcmp(nomeCidade, "s") == 0 || strcmp(nomeCidade, "S") == 0)break;
			insereCidade(NomeRodovia,  nomeCidade);
			printf ("Cidade Cadatrada!\n\n");
	}while(NomeRodovia);
	
}	

void insereCidade(char nomeRodovia[], char nomeCidade[]){
	int i;
	insere_lista(nomeCidade);
	if (!r->FIM->cidade)
	r->FIM->cidade = vetor[count];//aqui faz a ligação da fila para o nó da lista de cidades
}

void imprime_all(){
	no * backup_lista = (no*) malloc (sizeof(NO));
	NODO *  backup_fila = (NODO*) malloc (sizeof(NODO));
	if (!backup_lista || !backup_fila){
		printf ("Falha ao alocar memoria!\n");
		exit(1);
	}
	for (backup_fila = r->INICIO; backup_fila;backup_fila = backup_fila->prox){
		printf ("\nRodovia: %s \n", backup_fila->rodovia);
		for(backup_lista = backup_fila->cidade; backup_lista; backup_lista = backup_lista->next){
			printf ("Cidade: %s\n", backup_lista->Nome_Cidade);
		}
	}
	free(backup_lista);
	free(backup_fila);
}

bool Cruzamento(char nomeRodovia[], char nomeRodovia2[]){
	NODO * backup_lista = (NODO*) malloc (sizeof(NODO));
	NODO * backup_lista2 = (NODO*) malloc (sizeof(NODO));
	NODO * backup_fila = (NODO*) malloc (sizeof(NODO));
	no * backup_city = (no*) malloc (sizeof(no));
	no * backup_city2 = (no*) malloc (sizeof(no));
	NODO * ProcuraRodovia = NULL;
	NODO * ProcuraRodovia2 = NULL;
	if (!backup_city || !backup_city2){
		printf ("Falha ao alocar memoria!\n");
		return false;
	}	
	if (!backup_lista || !backup_fila || !backup_lista2){
		printf ("Falha ao alocar memoria!\n");
		return false;
	}	
	if (eh_vazia1(r)){
		printf ("Cadastre pelo menos uma rodovia antes de vim aqui!\n");
		pause();
		return false;
	}
	for (backup_fila = r->INICIO; backup_fila;backup_fila = backup_fila->prox){
	//pega o indice das rodovias cuja as mesma forem econtradas.
		if (strcmp(backup_fila->rodovia, nomeRodovia) == 0){
			ProcuraRodovia = backup_fila;
		}
		if (strcmp(backup_fila->rodovia, nomeRodovia2) == 0){
			ProcuraRodovia2 = backup_fila;
		}
	}
	if (!ProcuraRodovia || !ProcuraRodovia2){
		printf ("Rodovias Nao cadastrada!\n");
		return false;
	}
	//salva os nós iniciais da lista com as cidades.
	backup_city = ProcuraRodovia->cidade;
	backup_city2 = ProcuraRodovia2->cidade;
	//procura uma cidade que pertence nas duas rodovias.
	for(backup_lista = ProcuraRodovia; backup_lista->cidade; backup_lista->cidade = backup_lista->cidade->next){
		for(backup_lista2 = ProcuraRodovia2; backup_lista2->cidade; backup_lista2->cidade = backup_lista2->cidade->next){
			if (strcmp(backup_lista->cidade->Nome_Cidade, backup_lista2->cidade->Nome_Cidade) == 0){
				printf ("\nAs Rodovias: %s e %s se cruzam na cidade %s.\n",
				backup_lista->rodovia, backup_lista2->rodovia, backup_lista->cidade->Nome_Cidade);
				return true;
			}
		}
	}
	ProcuraRodovia->cidade = backup_city;
	ProcuraRodovia2->cidade = backup_city2;
	printf ("Nenhuma cidade foi localizada!\n");
	return false;
}
