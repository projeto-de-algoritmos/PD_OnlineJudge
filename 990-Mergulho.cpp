#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> tesouros;
vector<vector<bool>> escolhido; 
vector<vector<int>> profundidade; 

int knapsack(int idx,int t){
    if(t<0) return INT_MIN;
    if(idx == tesouros.size() || t == 0) return 0;
    if(profundidade[idx][t] != -1) return profundidade[idx][t];
    int sem = knapsack(idx+1,t);
    profundidade[idx][t] = sem;
    if(tesouros[idx].first <= t){
        int com = knapsack(idx+1,t-tesouros[idx].first) + tesouros[idx].second;
        if(com > sem) {

            escolhido[idx][t] = true;
            profundidade[idx][t] = com;
        }
    }
    return profundidade[idx][t];
}

int main()
{
    int t,w,n,d,v,tc=1;
    while(scanf("%d %d",&t,&w) != EOF){
        if(tc++>1) printf("\n");
        scanf("%d",&n);
        tesouros.clear();
        escolhido = vector<vector<bool>>(n+1,vector<bool>(t+1));
        profundidade = vector<vector<int>>(n+1,vector<int>(t+1,-1));

        for(int i=0;i<n;i++){
            scanf("%d %d",&d,&v);
            tesouros.push_back({d*3*w,v});
        }
        int maxValue = knapsack(0,t);
        printf("%d\n",maxValue);
        vector<int> escolhidoIndex;

        for(int i=0;i<n;i++){
            if(escolhido[i][t]){
                escolhidoIndex.push_back(i);
                t -= tesouros[i].first;
            }
        }
        printf("%d\n",escolhidoIndex.size());
        for(auto& idx : escolhidoIndex)
            printf("%d %d\n",tesouros[idx].first/(3*w),tesouros[idx].second);
    }
    return 0;
}