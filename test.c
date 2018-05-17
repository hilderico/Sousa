#include <stdio.h>
#include <stdlib.h>

/*

um arquivo em que sera salvo os nomes dos
arquivos.

indexarq.txt


EscreveNoArquivo("Guarda o Nome deste arquivo\n", 1000, "indexarq.txt");


*/
void NovoArquivo(char nvarq[]);
void Zeramtx(char nome[],int maxidx);
void Escreva(char nome[],int arq, char frase[]);
void EscreveNoArquivo(char charq[], int maxidx, char nvarq[]);



int main()
{
    char nome[1000];
    char narq[1000];
    Zeramtx(nome,1000);
    Zeramtx(narq,1000);
    int opc = 0;

    while(opc != 9){

    printf("==== LISTA DE OPÇÕES ====\n");
    printf("1. Novo Arquivo\n");
    printf("2. Escrever no Arquivo\n");
    printf("3. TESTES \n");
    printf("9. Saida\n\n");
    printf(">");


    scanf("%d",&opc);



    switch(opc){
    case 1:
        Zeramtx(nome,1000);
        Zeramtx(narq,1000);
        Escreva(nome,1,"Escreva o nome do arquivo seguido de \'#\'\n>");
        NovoArquivo(nome);
        EscreveNoArquivo(nome, 1000, "indexarq.txt");
        break;
    case 2:
        Zeramtx(nome,1000);
        Zeramtx(narq,1000);
        Escreva(nome,0,"Escreva qualquer frase ou palavra seguido de \'#\'\n>");
        Escreva(narq,1,"Escreva o nome do arquivo seguido de \'#\'\n>");
        EscreveNoArquivo(nome,1000,narq);
        break;
    case 3:
        printf("OS TESTES SÃO TESTADOS AQUI\n");
        break;
    case 9:
        printf("O Programa será encerrado...\n FIM\n");
        break;
    default:
         printf ("Valor invalido!\n");
    }

    }

    return 0;
}

void NovoArquivo(char nvarq[]){

    FILE *f;
    f = fopen(nvarq,"w");
    fclose(f);

}

void Zeramtx(char nome[],int maxidx){

    for(int cont = 0; cont < maxidx; cont++){
        nome[cont] = '\0';
    }
}

void Escreva(char nome[],int arq, char frase[]){
    int cont = 0;
    char c = '\0';
    printf("%s",frase);
    while(c != '#'){
        c = getchar();
        if(c != '#'){
            nome[cont] = c;
        }
        if(arq == 0){
            if(c != '#'){
                nome[cont] = c;
            }
            if(c == '#'){
                nome[cont] = '\n';
            }
            if(c != '\n'){
                cont++;
            }
        }

        if(arq == 1){
            if(c != '#'){
                if(c == '\n'){

                }else
                {
                    nome[cont] = c;
                }
            }
            if(c == '#'){

            }
            if(c != '\n'){
                cont++;
            }
        }
    }
}

void EscreveNoArquivo(char charq[], int maxidx, char nvarq[]){
    FILE *f;
    f = fopen(nvarq,"a");
    int idx = 0;
int chva = 0;
    for(idx = 0; idx < maxidx; idx++){
        if(charq[idx] != '\0'){
            fputc(charq[idx],f);
        }

    }
    fclose(f);
}

