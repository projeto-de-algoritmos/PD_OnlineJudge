#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,v;

    scanf("%d",&t); // entrada do número de casos de teste
    
    while(t--){
        vector<int> pesos;
        scanf("%d",&n);  // entrada do numero de carros
        
        for(int i=0;i<n;i++){
            scanf("%d",&v);  // entrada dos pesos dos carros
            pesos.push_back(v); // insere cada peso fornecido no final do vetor 'pesos'
        }
        
        vector<int> LIS; // Longest Increasing Subsequence
        
        deque<int> LDS; // Longest Decreasing Subsequence
        
        int res = 0;  // armazena de trás para frente, pois queremos computar e armazenar o comprimento do pd em i
        
        for(int i=n-1;i>=0;i--){
            int inferior = lower_bound(LIS.begin(),LIS.end(),pesos[i]) - LIS.begin();
            int superior = upper_bound(LDS.begin(),LDS.end(),pesos[i]) - LDS.begin();
            int pdInc, pdDec;  // increasing / decreasing
            
            if(inferior == LIS.size()) {
                LIS.push_back(pesos[i]);
                pdInc = LIS.size();
            }
            else {
                LIS[inferior] = pesos[i];
                pdInc = inferior + 1;
            }
            
            if(superior == 0){
                LDS.push_front(pesos[i]);
                pdDec = LDS.size();
            }
            else {
                LDS[superior-1] = pesos[i];
                pdDec = LDS.size()-(superior-1);
            }
            
            res = max(res, pdInc+pdDec-1);
        }
        printf("%d\n",res);
    }
}