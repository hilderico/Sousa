#include <stdio.h>
#include <stdlib.h>

/*

    void EscreveNoArquivo(char charq[], int maxidx, char nvarq[]){

        FILE *f;
        f = fopen(nvarq,"a");

        int idx = 0;

        for(idx = 0; idx < maxidx; idx++){
            fputc(charq[idx],nvarq);
        }

        fclose(f);
    }

*/
void NovoArquivo(char nvarq[]);
void Zeramtx(char nome[],int maxidx);
void Escreva(char nome[],int arq);
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
    printf("9. Saida\n\n");
    printf(">");

    scanf("%d",&opc);



    switch(opc){
    case 1:
        Escreva(nome,1);
        NovoArquivo(nome);
        break;
    case 2:
        Escreva(nome,0);
        Escreva(narq,1);
        EscreveNoArquivo(nome,1000,narq);
        break;
    case 9:
        printf("Saindo do programa...\nFIM\n");
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

void Escreva(char nome[],int arq){
    int cont = 0;
    char c = '\0';
    printf("Digite o nome do arquivo seguido de \"#\"\n>");
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
    for(idx = 0; idx < maxidx; idx++){
       if(charq[idx] != '\0'){        
           fputc(charq[idx],nvarq);
       }
    }
    fclose(f);
}

