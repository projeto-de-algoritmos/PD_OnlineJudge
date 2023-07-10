#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,v;
    
    scanf("%d", &t); // entrada dos casos de teste
    
    while(t--) {
        scanf("%d", &n);  // entrada do número de moedas no saco
        
        int soma = 0;
        vector<int> moedas;
        
        for(int i=0;i<n;i++) {
            scanf("%d", &v);  // entrada dos valores das moedas
            
            moedas.push_back(v); // vai adicionando os valores das moedas no final do vetor
            soma += v;
        }
        vector<bool> knapsack(soma/2+1);  // aqui começa a função da programação dinâmica
        knapsack[0] = true;
        int maior = 0;
        
        for(auto& moeda : moedas) {
            for(int i=soma/2;i>=moeda;i--) {
                knapsack[i] = knapsack[i-moeda] ? true : knapsack[i];
                if(knapsack[i]) maior = max(i,maior);
            }
        }
        int resposta = soma-maior*2;
        printf("%d\n", resposta);
    }
}