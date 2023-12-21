#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include<stdbool.h>
#include<locale.h>
#define MAXBUF (100)
#define QDP 20 //QDP == Quantidade de Palavras
 
/*
 Jogo de Matheus Sobreira e Rodrigo Neves
 Professor: Raul Paradeda
 Universidade do Estado do Rio Grande do Norte (UERN)

Faltou corrigir um erro: evitar que o jogador digite a mesma letra, falta de tempo mesmo.

*/
int vetAux[QDP];
int k;
 
void zerarVetorAuxiliar(){
	int i;
	
	for(i=0 ; i<QDP ; i++){
		vetAux[i] = 0;
	}
}
 
int fNumRamdom(){ //Retorna um numero aleatorio que nao se repete
 
	int i, j, auxRam;
	if(k >= QDP){
        return 0;
    }
    
	do{
		auxRam = 0;
		srand(time(NULL));
		i = rand() % QDP+1;
 
		for(j=0 ; j<QDP ; j++){
			if(i == vetAux[j]){
				auxRam = 1;
 
			}
		}	
 
	} while(auxRam == 1);
 
 	vetAux[k] = i;
	k++;
 
	return i;
}
 
void fForca(int estado){ // função para imprimir a forca e suas fases correspoondentes
	if(estado==0){
		printf("\n\t\t------------");
		printf("\n\t\t|          |");
		printf("\n\t\t|");
		printf("\n\t\t|");
		printf("\n\t\t|");
		printf("\n\t\t|");
		printf("\n\t\t|");
		printf("\n\t\t-");
	} else if(estado==1){
	    printf("\n\t\t------------");
	    printf("\n\t\t|          |");
	    printf("\n\t\t|          0");
	    printf("\n\t\t|");
	    printf("\n\t\t|");
	    printf("\n\t\t|");
	    printf("\n\t\t|");
	    printf("\n\t\t-");
  	} else if(estado==2){
	    printf("\n\t\t------------");
	    printf("\n\t\t|          |");
	    printf("\n\t\t|          0");
	    printf("\n\t\t|          |");
	    printf("\n\t\t|");
	    printf("\n\t\t|");
	    printf("\n\t\t|");
	    printf("\n\t\t-");
 	} else if(estado==3){
	    printf("\n\t\t------------");
	    printf("\n\t\t|          |");
	    printf("\n\t\t|          0");
	    printf("\n\t\t|        --|");
	    printf("\n\t\t|           ");
	    printf("\n\t\t|");
	    printf("\n\t\t|");
	    printf("\n\t\t-");
  	} else if(estado==4){
	    printf("\n\t\t------------");
	    printf("\n\t\t|          |");
	    printf("\n\t\t|          0");
	    printf("\n\t\t|        --|--");
	    printf("\n\t\t|           ");
	    printf("\n\t\t|");
	    printf("\n\t\t|");
	    printf("\n\t\t-");
  	} else if(estado==5){
	    printf("\n\t\t------------");
	    printf("\n\t\t|          |");
	    printf("\n\t\t|          0");
	    printf("\n\t\t|        --|--");
	    printf("\n\t\t|         /  ");
	    printf("\n\t\t|");
	    printf("\n\t\t|");
	    printf("\n\t\t-");
  	} else if(estado==6){
	    printf("\n\t\t------------");
	    printf("\n\t\t|          |");
	    printf("\n\t\t|          0");
	    printf("\n\t\t|        --|--");
	    printf("\n\t\t|         / \\ ");
	    printf("\n\t\t|");
	    printf("\n\t\t|    Perdeu o game!");
	    printf("\n\t\t-");
  	}
}
 
void fLimpa_tela(){		//função limpa tela
  system("cls");
}
 
 
void regras(){
	char opcao;
	do{
		fLimpa_tela();
		printf("\n\t\t\t\t   Deseja ver as regras do jogo? \n\n");
		printf("\t\t\t  Digite 's' pra sim \t\t Digite 'n' pra nao \n\n");
		printf("\t\t\t               Digite aqui: ");
		scanf("%c", &opcao);
 
		if(opcao == 's'){
 
			printf("\n\n\t\tIra aparecer uma palavra escondida, e a esquerda dela uma forca. \n\n");
			printf("\t\tVoce tentarar qual a palavra digitando letra por letra, aparecendo\n\n");
			printf("\t\ta palavra aos poucos se voce acertar. Voce tem direito ate 6 erros, \n\n");
			printf("\t\tou seja, ate a forca se completar, e se isso acontecer, voce perde, \n\n");
			printf("\t\tmostrando no final a sua pontuacao durante o jogo. Dita as regras, \n\n");
			printf("\t\tBom jogo pra voce :)\n\n\n\t\t");
			printf("");
			printf("");
			printf("");
			system("pause");
 
		}
 
	} while(opcao != 's' && opcao != 'n');
 
}
 
int fMenu(){  //função menu
	int fOp=0;
	printf("\n\t\t\t\t\tBEM-VINDO(A) AO JOGO DA FORCA!!\n\n");
	printf("\t\tDigite qual dificuldade deseja jogar:\n\n\n");
	printf("\t\t\t        --------------------------\n");
	printf("\t\t\t\t| Facil ------> Digite 1 |\n");
	printf("\t\t\t\t|                        |\n");
	printf("\t\t\t\t| Medio ------> Digite 2 |\n");
	printf("\t\t\t\t|                        |\n");
	printf("\t\t\t\t| Dificil ----> Digite 3 |\n");
	printf("\t\t\t        --------------------------\n\n");
 
	printf("\t\t\t   Digite aqui: ");
	scanf("%d", &fOp);
	return fOp;
}
 
int fMenuFinal(int mistakes){
 
	int op2;
 
	do{
 
		if(mistakes != 6){ //opcoes pra quem acertou
			printf("\n\n\t|-------------------------------------------------------------|\n");
			printf("\t|    Escolha uma das opcoes abaixo:                           |\n");
			printf("\t|                                                             |\n");
			printf("\t| Continuar jogo ----------------------------------> Digite 1 |\n");
			printf("\t| Parar e voltar ao menu (zera pontuacao) ---------> Digite 2 |\n");
			printf("\t| Parar e sair do jogo (zera pontuacao) -----------> Digite 3 |\n");
			printf("\t|_____________________________________________________________|\n");
			printf("\n\t  Digite aqui: ");
			scanf("%d", &op2);

			if(op2 == 1){
				return 1;
				
			} else if(op2 == 2){
				return 0;
				
			} else  if(op2 == 3){
				return op2;
				
			} else{
				printf("\n\tX NENHUMA DAS OPCOES FOI DIGITADA X");
				Sleep(1500);
				fLimpa_tela();
			}
		} else {
	 			printf("\n\n\t|-------------------------------------------------------------|\n");
				printf("\t|    Escolha uma das opcoes abaixo:                           |\n");
				printf("\t|                                                             |\n");
				printf("\t| Recomecar jogo ----------------------------------> Digite 1 |\n");
				printf("\t| Parar e voltar ao menu (zera pontuacao) ---------> Digite 2 |\n");
				printf("\t| Parar e sair do jogo (zera pontuacao) -----------> Digite 3 |\n");
				printf("\t|_____________________________________________________________|\n");
				printf("\n\t  Digite aqui: ");
				scanf("%d", &op2);
 
				if(op2 == 1){
						return 1;
				} else if(op2 == 2){
						return 0;
				} else  if(op2 == 3){
						return 2;
				} else{
						printf("\n\tX NENHUMA DAS OPCOES FOI DIGITADA X");
						Sleep(1500);
						fLimpa_tela();
				}
 
		}
 
	} while(op2!=1 || op2!=2 || op2!=3);
 
}
 
 
char * fPegarPalavraFacil(int i){ 
 
	char frase[100];
	int qtd = 0;
 
	static char retornoFrase[ MAXBUF + 1 ] = {0};
 
	FILE *file;
	file = fopen("facil.txt","r");
	if(file == NULL){
		printf("Erro!");
		exit(1);
	}
 
	//srand(time(NULL));
	//i = rand () % 7 +1;  //Aqui muda a quantidade de palavras dentro do arquivo
	while(!feof(file)){
		if(fgets(frase, 100, file)){
			qtd++;
			if(qtd == i){
				strncpy(retornoFrase,frase, MAXBUF );
			}
		}
	}
 
	fclose(file);
 
	return retornoFrase;
}
 
char * fPegarPalavraMedio(int i){ 
 
	char frase[100];
	int qtd = 0;
 
	static char retornoFrase[ MAXBUF + 1 ] = {0};
 
	FILE *file;
	file = fopen("medio.txt","r");
	if(file == NULL){
		printf("Erro!");
		exit(1);
	}
 
	//srand(time(NULL));
	//i = rand () % 7 +1; //Aqui muda a quantidade de palavras dentro do arquivo
 
	while(!feof(file)){
		if(fgets(frase, 100, file)){
			qtd++;
			if(qtd == i){
				strncpy(retornoFrase,frase, MAXBUF );
			}
		}
	}
 
	fclose(file);
 
	return retornoFrase;
}
 
char * fPegarPalavraDificil(int i){ 
 
	char frase[100];
	int qtd = 0;
 
	static char retornoFrase[ MAXBUF + 1 ] = {0};
 
	FILE *file;
	file = fopen("dificil.txt","r");
	if(file == NULL){
		printf("Erro!");
		exit(1);
	}
 
	//srand(time(NULL));
	//i = rand () % 7 + 1; //Aqui muda a quantidade de palavras dentro do arquivo
 
	while(!feof(file)){
		if(fgets(frase, 100, file)){
			qtd++;
			if(qtd==i){
				strncpy(retornoFrase,frase, MAXBUF );
			}
		}
	}
 
	fclose(file);
 
	return retornoFrase;
}
 
char * fPegarDicaFacil(int i){ 
 
	char frase[100];
	int qtd = 0;
 
	static char retornoFrase[ MAXBUF + 1 ] = {0};
 
	FILE *file;
	file = fopen("dicaFacil.txt","r");
	if(file == NULL){
		printf("Erro!");
		exit(1);
	}
 
	//srand(time(NULL));
	//i = rand () % 7 +1;  //Aqui muda a quantidade de palavras dentro do arquivo
	while(!feof(file)){
		if(fgets(frase, 100, file)){
			qtd++;
			if(qtd == i){
				strncpy(retornoFrase,frase, MAXBUF );
			}
		}
	}
 
	fclose(file);
 
	return retornoFrase;
}
 
char * fPegarDicaMedio(int i){ 
 
	char frase[100];
	int qtd = 0;
 
	static char retornoFrase[ MAXBUF + 1 ] = {0};
 
	FILE *file;
	file = fopen("dicaMedio.txt","r");
	if(file == NULL){
		printf("Erro!");
		exit(1);
	}
 
	//srand(time(NULL));
	//i = rand () % 7 +1;  //Aqui muda a quantidade de palavras dentro do arquivo
	while(!feof(file)){
		if(fgets(frase, 100, file)){
			qtd++;
			if(qtd == i){
				strncpy(retornoFrase,frase, MAXBUF );
			}
		}
	}
 
	fclose(file);
 
	return retornoFrase;
}
 
char * fPegarDicaDificil(int i){ 
 
	char frase[100];
	int qtd = 0;
 
	static char retornoFrase[ MAXBUF + 1 ] = {0};
 
	FILE *file;
	file = fopen("dicaDificil.txt","r");
	if(file == NULL){
		printf("Erro!");
		exit(1);
	}
 
	//srand(time(NULL));
	//i = rand () % 7 +1;  //Aqui muda a quantidade de palavras dentro do arquivo
	while(!feof(file)){
		if(fgets(frase, 100, file)){
			qtd++;
			if(qtd == i){
				strncpy(retornoFrase,frase, MAXBUF );
			}
		}
	}
 
	fclose(file);
 
	return retornoFrase;
}
 
int main(){
	setlocale(LC_ALL, "Portuguese");
	int i;
	int op, op2;
	int erros;
	char palavraSecreta[50];
	char palavraPraAcertar[50];
	char letra;
	int number; //serve pra palavra aleatoria
	int seQuerParar = 0;
	int score;
	int nivel;
	regras();
 
 	do{
 		score = 0;
		nivel = 0; 
		do{
			fLimpa_tela();
			op = fMenu();
			zerarVetorAuxiliar();
			k = 0;
 
			switch(op){
 
				case 1 :
 
					do{
						if(erros == 6){
								score = 0;
								nivel = 0;
						}
 
						erros = 0;
			 			number = fNumRamdom();
 
				 			if(number == 0){
 
									printf("\nPalavras do nivel acabaram!\n");
				                    op2=2;
				                    printf("Aperte alguma coisa para continuar\n");
				                    getch();
				                    break;
 
			                 }
 
						strcpy(palavraSecreta,fPegarPalavraFacil(number)); //palavra secreta é a palavra que pega no arquivo
			    		palavraSecreta[strlen(palavraSecreta)-1] = '\0';
			    		strcpy(palavraPraAcertar, palavraSecreta); // palavra pra acertar tem tracejado
 
			    		for(i=0 ; i<strlen(palavraPraAcertar) ; i++){ //Se a a palavra tiver espaço, n troca o espaço pela "_".
 
				  				if(palavraPraAcertar[i] != ' '){
				  					palavraPraAcertar[i] = '_'; // Aqui tranforma a palavra em tracejado
								}
			  			}
 
			  			nivel++;
 
			  			while(1){ //Aqui roda o jogo
 
			  				fLimpa_tela();
			  				printf("\n\n\tNivel %d - Facil                   Score: %d\n", nivel, score);
				  			fForca(erros);
 
				  			printf("\t");
 
				  			for(i=0 ; i<strlen(palavraPraAcertar) ; i++){
 
						 			printf("%c ", palavraPraAcertar[i]); //imprime tracejado
 
							}
 
							printf("\tDica: %s\n", fPegarDicaFacil(number)); //Lembrar que talvez pode mudar
							fflush(stdin);
 
							printf("\n");
 
							printf("\t\tDigite a letra: ");
 
							letra = getchar(); //So pega o primeiro caracter
 
						//	int chute = 0;
							bool chute = false;
 
							for(i=0 ; i<strlen(palavraPraAcertar) ; i++){ //Verifica se acertou a letra
 
								if(letra == palavraSecreta[i]){
 
				 					palavraPraAcertar[i] = letra;
				 					printf("\n\n\t\tAcertou a letra,  +5");
				 					Sleep(740);
									chute = true;
									score += 5;
 
								}
 
							}
 
							if(chute == false){ //errou a letra
								erros++;
 
							}
 
							if(strcmp(palavraPraAcertar, palavraSecreta) == 0){ //se acertou a palavra inteira
 
								fLimpa_tela();
			 					fForca(erros);
			 					printf("   ");
								for(i=0 ; i<strlen(palavraPraAcertar) ; i++){
 
									printf("%c ", palavraPraAcertar[i]);
 
								}
	 							score += 10;
								printf("\n\n\tVOCE ACERTOU A PALAVRA , +10 pontos!!!!!\n");
								printf("\tSua pontuacao ate agora foi: %d", score);
 
								break;
 
							}
 
							if(erros == 6){ //se errou 6 vezes
 
								fLimpa_tela();
								fForca(erros);
 
								printf("\n\n\tA palavra para acertar era '%s'.\n", palavraSecreta);
								printf("\tA sua pontuacao final ficou: %d", score);
								fflush(stdin);
								break;
 
							}
						}
 
						seQuerParar = fMenuFinal(erros);
 
		 			} while(erros != 6 || seQuerParar == 1 );
 
				break;
 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	 
 
				case 2 :
						do{
						if(erros == 6){
								score = 0;
								nivel = 0;
						}
 
						erros = 0;
			 			number = fNumRamdom();
 
			 			if(number == 0){
 
								printf("\nPalavras do nivel acabaram!\n");
			                    op2=2;
			                    printf("Aperte alguma coisa para continuar\n");
			                    getch();
			                    break;
 
		                 }
 
						strcpy(palavraSecreta,fPegarPalavraMedio(number)); //lembrar que talvez isso mude
			    		palavraSecreta[strlen(palavraSecreta)-1] = '\0';
			    		strcpy(palavraPraAcertar, palavraSecreta);
 
			    		for(i=0 ; i<strlen(palavraPraAcertar) ; i++){ //Se a a palavra tiver espaço, n troca o espaço pela "_".
 
				  				if(palavraPraAcertar[i] != ' '){
				  						palavraPraAcertar[i] = '_';
								}
			  			}
 
			  			nivel++;
			  			while(1){
 
			  				fLimpa_tela();
			  				printf("\n\n\tNivel %d - Medio                   Score: %d\n", nivel, score); //aqui muda
				  			fForca(erros);
 
				  			printf("\t");
 
				  			for(i=0 ; i<strlen(palavraPraAcertar) ; i++){
 
						 			printf("%c ", palavraPraAcertar[i]);
 
							}
 
							printf("\tDica: %s\n", fPegarDicaMedio(number)); //Lembrar que talvez pode mudar
							fflush(stdin);
 
							printf("\n");
 
							printf("\t\tDigite a letra: ");
 
							letra = getchar();
 
							int chute = 0;
 
							for(i=0 ; i<strlen(palavraPraAcertar) ; i++){
 
								if(letra == palavraSecreta[i]){
 
				 					palavraPraAcertar[i] = letra;
				 					printf("\n\n\t\tAcertou a letra,  +5");
				 					Sleep(710);
									chute = 1;
									score += 5;
 
								}
 
							}
 
							if(chute == 0){
								erros++;
 
							}
 
							if(strcmp(palavraPraAcertar, palavraSecreta) == 0){
 
								fLimpa_tela();
			 					fForca(erros);
			 					printf("   ");
								for(i=0 ; i<strlen(palavraPraAcertar) ; i++){
 
 
									printf("%c ", palavraPraAcertar[i]);
 
								}
	 							score += 10;
								printf("\n\n\tVOCE ACERTOU A PALAVRA , +10 pontos!!!!!\n");
								printf("\tSua pontuacao ate agora foi: %d", score);
 
								break;
 
							}
 
							if(erros == 6){
 
								fLimpa_tela();
								fForca(erros);
 
								printf("\n\n\tA palavra para acertar era '%s'.\n", palavraSecreta);
								printf("\tA sua pontuacao final ficou: %d", score);
								fflush(stdin);
								break;
 
							}
 
						}
 
						seQuerParar = fMenuFinal(erros);
 
		 			} while(erros != 6 || seQuerParar == 1 );
 
				break;
 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////				
 
				case 3 :
						do{
						if(erros == 6){
								score = 0;
								nivel = 0;
						}
 
						erros = 0;
			 			number = fNumRamdom();
 
			 			if(number == 0){
 
								printf("\nPalavras do nivel acabaram!\n");
			                    op2=2;
			                    printf("Aperte alguma coisa para continuar\n");
			                    getch();
			                    break;
 
		                 }
 
						strcpy(palavraSecreta,fPegarPalavraDificil(number)); //lembrar que talvez isso mude
			    		palavraSecreta[strlen(palavraSecreta)-1] = '\0';
			    		strcpy(palavraPraAcertar, palavraSecreta);
 
			    		for(i=0 ; i<strlen(palavraPraAcertar) ; i++){ //Se a a palavra tiver espaço, n troca o espaço pela "_".
 
				  				if(palavraPraAcertar[i] != ' '){
				  						palavraPraAcertar[i] = '_';
								}
			  			}
 
			  			nivel++;
			  			while(1){
 
			  				fLimpa_tela();
			  				printf("\n\n\tNivel %d - Dificil                   Score: %d\n", nivel, score); //aqui muda
				  			fForca(erros);
 
				  			printf("\t");
 
				  			for(i=0 ; i<strlen(palavraPraAcertar) ; i++){
 
						 			printf("%c ", palavraPraAcertar[i]);
 
							}
 
							printf("\tDica: %s\n", fPegarDicaDificil(number)); //Lembrar que talvez pode mudar
							fflush(stdin);
 
							printf("\n");
 
							printf("\t\tDigite a letra: ");
 
							letra = getchar();
 
							int chute = 0;
 
							for(i=0 ; i<strlen(palavraPraAcertar) ; i++){
 
								if(letra == palavraSecreta[i]){
 
				 					palavraPraAcertar[i] = letra;
				 					printf("\n\n\t\tAcertou a letra,  +5");
				 					Sleep(710);
									chute = 1;
									score += 5;
 
								}
 
							}
 
							if(chute == 0){
								erros++;
 
							}
 
							if(strcmp(palavraPraAcertar, palavraSecreta) == 0){
 
								fLimpa_tela();
			 					fForca(erros);
			 					printf("   ");
								for(i=0 ; i<strlen(palavraPraAcertar) ; i++){
 
									printf(" %c ", palavraPraAcertar[i]);
 
								}
	 							score += 10;
								printf("\n\n\tVOCE ACERTOU A PALAVRA , +10 pontos!!!!!\n");
								printf("\tSua pontuacao ate agora foi: %d", score);
 
								break;
 
							}
 
							if(erros == 6){
 
								fLimpa_tela();
								fForca(erros);
 
								printf("\n\n\tA palavra para acertar era '%s'.\n", palavraSecreta);
								printf("\tA sua pontuacao final ficou: %d", score);
								fflush(stdin);
								break;
 
							}
						}
 
						seQuerParar = fMenuFinal(erros);
 
		 			} while(erros != 6 || seQuerParar == 1 );
 
				break;
 
				default :
					printf("\n\t\t\tX OPCAO INVALIDA X");
					Sleep(1500);
			}
 
		} while(op != 1 && op != 2 && op != 3);
 
	} while(seQuerParar == 0);
 
 
	return 0;
}
