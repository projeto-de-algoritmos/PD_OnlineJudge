#include <bits/stdc++.h>
using namespace std;

int T;  //casos de teste
int N;  // número de objetos da supersale
int G;  // numero de pessoas do grupo
int MW;  // peso que cada pessoa suporta
int P[1010];  // preços dos objetos
int W[1010];  // pesos dos objetos
int memo[1010][40];


int melhorValor(int idx, int pesoSomado) {
    if (idx == N || pesoSomado == 0)  // Se não houverem objetos na supersale
        return 0;
    
    if(memo[idx][pesoSomado] != -1)
        return memo[idx][pesoSomado];
    
    if(W[idx] > pesoSomado)
        return memo[idx][pesoSomado] = melhorValor(idx+1,pesoSomado);
    
    return memo[idx][pesoSomado] = max(
        melhorValor(idx+1,pesoSomado),
        P[idx]+melhorValor(idx+1,pesoSomado-W[idx]));
}

int main() {
    
    scanf("%d", &T); // entrada da quantidade de casos de uso
    
    while(T--){
        memset(memo, -1, sizeof(memo));
        
        scanf("%d", &N); // entrada do número de objetos da supersale
        
        for(int i=0;i<N;i++)
            scanf("%d %d", P+i, W+i); // entrada dos preços e pesos dos objetos
        int ans = 0;
        
        scanf("%d",&G); // entrada numero de pessoas do grupo
        
        while(G--) {
            scanf("%d",&MW); // entrada dos peso que cada pessoa suporta
            ans += melhorValor(0, MW); // chama a função melhorValor
        }
        printf("%d\n",ans);
    }
}