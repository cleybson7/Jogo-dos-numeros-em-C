#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

int main(){

    int r, r2, Nsecreto, chute, tent;
    char nome[31], curso[21], matricula[11], vazio[5];
    time_t tempo;
    time(&tempo);

    setlocale(LC_ALL,"Portuguese"); 

    struct tm * local = localtime(&tempo); 

    do {
        printf("\nEscolha uma opção: \n\n");
        printf("1 - Cadastro\n"); 
        printf("2 - Jogo\n");
        printf("3 - Sair\n\n");

        scanf("\n%d", &r);
        fflush(stdin);

        switch (r){

            case 1:

             	
                printf("\nDigite seu nome: ");
                fgets(nome, 31, stdin);
                fflush(stdin);

                printf("Digite seu curso: ");
                fgets(curso, 21, stdin);
                fflush(stdin);

                printf("Digite sua matricula: ");
                fgets(matricula, 11, stdin); 
                fflush(stdin);

                printf("\nDados cadastrados!\n\n");
                printf("Nome: %s\n", nome);
                printf("Curso: %s\n", curso);
                printf("Matricula: %s\n", matricula);
                printf("Data: %02d/%02d/%d\n", local->tm_mday,local->tm_mon+1,local->tm_year+1900);
                printf("Hora: %02d:%02d:%02d\n", local->tm_hour,local->tm_min,local->tm_sec);

                break;
			 
            case 2:

                do {
                    printf("\nBem-vindo ao: Advinhe o Número\n\n");  
                    printf("Escolha uma dificuldade:\n");
                    printf("1- Fácil (1 a 10)\n2- Médio (1 a 100)\n3- HARDCORE (1 a 1000)\n");   
                    scanf("%d", &r2);

                    switch(r2){

                        case 1:

                            printf("Digite um número de 0 a 10\n ");

                            srand(time(NULL));
                            Nsecreto = rand() % 11;

                            while(1){

                                printf("\nDigite um número: \n");
                                scanf("%d", &chute);

                                if(chute == Nsecreto){
                                    printf("Parabéns, você acertou!\n");
                                    break;
                                }
                                else if (chute > 10){
                                    printf("Digite um número entre 0 e 10\n");
                                }
                                else if (chute > Nsecreto){
                                    printf("Errou! O número secreto é menor!\n");
                                }
                                else if(chute < Nsecreto){
                                    printf("Errou! O número secreto é maior!\n");
                                }
                            }

                            break;

                        case 2:  

                            printf("\nDigite um número de 0 a 100 \n\n");

                            srand(time(NULL));
                            Nsecreto = rand() % 101;        

                            while(1){
                                printf("Dê seu chute: ");
                                scanf("%d", &chute);

                                if(chute == Nsecreto){
                                    printf("Parabéns, você acertou!\n");
                                    break;
                                }
                                else if (chute > 100){
                                    printf("Número inválido, digite um número de 0 a 100\n");
                                }
                                else if (chute > Nsecreto){
                                    printf("Número alto, tente um número menor\n");
                                }
                                else if(chute < Nsecreto){
                                    printf("Número baixo, tente um número maior\n");
                                } 
                            } 

                            break;

                        case 3:

                            printf("Você tem 10 tentativas\n");
                            printf("\nDigite um número de 0 a 1000 \n\n");

                            srand(time(NULL));
                            Nsecreto = rand() % 1001;

                            for(tent = 10; tent > 0; tent--){
                                printf("Você tem %d tentativas sobrando\n", tent);
                                printf("Dê seu chute: \n");
                                scanf("%d", &chute);

                                if(chute == Nsecreto){
                                    printf("Parabéns, você acertou!\n");
                                    break;
                                } 
                                else if (chute > 1000){
                                    printf("Número inválido, digite um número de 0 a 1000\n");
                                }
                                else if (chute > Nsecreto){
                                    printf("Número alto, tente um número menor\n");
                                }
                                else if (chute < Nsecreto){
                                    printf("Número baixo, tente um número maior\n");
                                }                                                        							

															
							}
                             if(tent < 1){
								    printf("\nSuas chances acabaram, o número era %d\n", Nsecreto);		                                							
								 }  
  						        break;
  						    
                    } //switch

                    printf("Deseja jogar novamente? (1 - Sim / 2 - Não): ");
                    scanf("%d", &r2);

                } while (r2 == 1); //do while do jogo

                break;

        }
    } while (r != 3); //do while principal

    return 0;
}
