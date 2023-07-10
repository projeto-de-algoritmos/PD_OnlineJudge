#include <iostream>
#define TAM 9
#define INFINITO 999999999

using namespace std;


typedef struct {
    int origem;
    int destino;
    int peso;
} CAMINHO;


CAMINHO caminhos[350];


int BellmanFord(int num_caminhos, int num_Nos, int origem, int destino) {
    int i,j,trocou=1;
    int distancia[65];

    for (i = 0; i <= num_Nos; i++) {
        distancia[i] = INFINITO;
    }

    distancia[origem]=0;

    for (i = 0; i <= num_Nos && trocou; i++) { // se nenhuma iteração teve efeito, ~trocou portanto sai
        trocou = 0;
        for (j = 0; j < num_caminhos; j++) {
            if (distancia[caminhos[j].destino] > distancia[caminhos[j].origem] + caminhos[j].peso) {
                distancia[caminhos[j].destino] = distancia[caminhos[j].origem] + caminhos[j].peso;
                trocou=1;
            }
        }
    }
    return distancia[destino];
}


int main() {

    int tabuleiro[TAM][TAM];

    int cont = 1, i, j;
    for (int i=1; i<TAM; i++) {
        for (int j=1; j<TAM; j++) {
            tabuleiro[i][j] = cont++;

        }
    }

    //Realizar o Flood fill
    cont = 0;
    for(int i = 1; i < TAM; i++) {
        for(int j = 1; j < TAM; j++) {
            if( (i + 1) < TAM && (j + 2) < TAM ) {
                //1+1, 1+2 (2,3) OK
                caminhos[cont].origem = tabuleiro[i][j];
                caminhos[cont].destino = tabuleiro[i + 1][j + 2];
                caminhos[cont].peso = 1;
                cont++;
            }
            if( (i + 1) < TAM && (j - 2) >= 1 ) {
                caminhos[cont].origem = tabuleiro[i][j];
                caminhos[cont].destino = tabuleiro[i + 1][j - 2];
                caminhos[cont].peso = 1;
                cont++;
            }
            if( (i + 2) < TAM && (j + 1) < TAM ) {
                caminhos[cont].origem = tabuleiro[i][j];
                caminhos[cont].destino = tabuleiro[i + 2][j + 1];
                caminhos[cont].peso = 1;
                cont++;
            }
            if( (i + 2) < TAM && (j - 1) >= 1 ) {
                caminhos[cont].origem = tabuleiro[i][j];
                caminhos[cont].destino = tabuleiro[i + 2][j - 1];
                caminhos[cont].peso = 1;
                cont++;
            }
            if( (i - 1) > 0 && (j + 2) < TAM ) {
                caminhos[cont].origem = tabuleiro[i][j];
                caminhos[cont].destino = tabuleiro[i - 1][j + 2];
                caminhos[cont].peso = 1;
                cont++;
            }
            if( (i - 1) > 0 && (j - 2) >= 1 ) {
                caminhos[cont].origem = tabuleiro[i][j];
                caminhos[cont].destino = tabuleiro[i - 1][j - 2];
                caminhos[cont].peso = 1;
                cont++;
            }
            if( (i - 2) > 0 && (j + 1) <TAM  ) {
                caminhos[cont].origem = tabuleiro[i][j];
                caminhos[cont].destino = tabuleiro[i - 2][j + 1];
                caminhos[cont].peso = 1;
                cont++;
            }
            if( (i - 2) > 0 && (j - 1) >= 1 ) {
                caminhos[cont].origem = tabuleiro[i][j];
                caminhos[cont].destino = tabuleiro[i - 2][j - 1];
                caminhos[cont].peso = 1;
                cont++;
            }
        }
    }

    int origem;
    int destino;



    string de, para;

    while (cin >> de >> para){

        origem = (de[0]-'a')*8 + de[1]-'0';
        destino = (para[0]-'a')*8 + para[1]-'0';
    
        cout << "To get from " << de << " to " << para << " takes " << BellmanFord(cont, 64, origem, destino) << " knight moves." << endl;
        
        if (de == para){
            break;
        }

    }



    return 0;
}