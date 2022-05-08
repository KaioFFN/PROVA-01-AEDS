#include <stdio.h>
#include <stdlib.h>
#include "pilhas.h"


int main(int argc, char** argv)
{
	Pilha_vet* vagaoA, * estacao , *palavraescolhida , *buffer , *vagaoB;// CRIA PILHAS QUE SERÃO UTILIZADAS NO DECORRER DO CODIGO

	int  i , f = 0 ; // INTEIROS PARA AUXILIAR EM CONTAGENS NO  DECORRER DO CODIGO 

	// CRIANDO LISTA PARA ANALIZAR A PALAVRA
	vagaoA = pilha_vet_cria();
	estacao = pilha_vet_cria();
	palavraescolhida = pilha_vet_cria();
	buffer = pilha_vet_cria();
	
	// COPIAR AS LETRAS QUE DEVEM SER COLOCADAS EM ORDEM QUE ESTÃO NO VAGÃO A 
	printf("\tDigite a ordem de letras: ");
	scanf("%s%*c" , &buffer->vet);
	
	// ORDEM QUE A PALAVRA DEVE ESTAR NO VAGÃO B
	printf("\tDigite a palavra escolhida: ");
	scanf("%s%*c", &palavraescolhida->vet);
	
	//COLOCA AS PALAVRAS DENTRO DA PILHA
	while (buffer->vet[buffer->n] != '\0')
	{
		pilha_vet_push(buffer, buffer->vet[buffer->n]);
	}
	
	// COLOCA AS PALAVRAS DENTRO DA PILHA
	while (palavraescolhida->vet[palavraescolhida->n] != '\0')
	{
		pilha_vet_push(palavraescolhida, palavraescolhida->vet[palavraescolhida->n]);
	}
	
	// INVERTE A PILHA PRINCIPAL 
	for (size_t i = 0; i < palavraescolhida->n; i++)
	{
		pilha_vet_push(vagaoA, pilha_vet_pop(buffer));
	}
	
	//LIBERAR A MEMORIA TEMPORARIA 
	pilha_vet_libera(buffer);
	
	//AQUI CRIA O VAGAOB PARA QUE CONSIGA FAZER AS MUDANÇAS PARA ELE E COM ISSO VER SE A PALAVRA ESTA CORRETA OU NÃO 
	vagaoB = pilha_vet_cria();
	
	//AQUI FAZ A ANALIZE DO VAGAO ATE QUE A PILHA ACABE E NÃO CAIBA MAIS NADA OU ATE QUE A PALAVRA SEJA ENCONTRADA 
	printf("\t");//DAR TABEAMENTO NOS IRIR
	while (f < palavraescolhida->n)
	{
		//CASO SEJA A LETRA QUE PRECISA ESTEJA NO TOPO DA PILHA ENTRA DENTRO DO IF PARA COLOCALA NO TREM FINAL AI É RETIRADO DA ESTAÇÃO 
		if (estacao->vet[estacao->n-1] == palavraescolhida->vet[f])
		{
			pilha_vet_push(vagaoB , pilha_vet_pop(estacao));
			f++;
			printf("R");
		}
		// CASO NÃO SEJA ENTRA NO ELSE
		else
		{
			if (vagaoA->n == 0)//CASO O TREM NÃO TENHA MAIS NENHUM VAGAO PARA SER RETIRADO ELE IMPRIME A MENSAGEM DE IMPOSSIVEL 
			{
				printf("\n\tIMPOSSIBLE");
				break;
			}
			//CASO AINDA TENHA INTENS NA PILHA QUE NÃO FORAM RETIRADOS ELE VEM PARA AQUI PARA COLOCALOS NA ESTAÇÃO 
			pilha_vet_push(estacao, pilha_vet_pop(vagaoA));
			printf("I");
		}
	}

	//AQUI CASO CHEGUE COMPARE A QUANTIDADES DE VAGOES SE FOREM IGUAIS IMPRIME QUE DEU CORRETAMENTE
	if (vagaoB->n == palavraescolhida->n)
	{
		printf("\n\tDeu certo");
	}
	
	//LIBERA AS PILHAS UTILIZADAS 
	pilha_vet_libera(vagaoB);
	pilha_vet_libera(estacao);
	pilha_vet_libera(vagaoA);
	pilha_vet_libera(palavraescolhida);

	return EXIT_SUCCESS;
}