#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    string in;
    scanf("%d\n\n",&t);
    while(t--){
        vector<int> valores;
        vector<int> profun;
        vector<int> prox;
        int melhorIdx = 0;
        int melhor = 0;
        while(getline(cin,in),in != ""){
            int cur = stoi(in);
            int pai = -1, longest = 0;
            for(int i=0;i<valores.size();i++){
                if(cur > valores[i] && profun[i]>longest){
                    pai = i;
                    longest = profun[i];
                }
            }
            if(++longest > melhor){
                melhorIdx = valores.size();
                melhor = longest;
            }
            valores.push_back(cur);
            profun.push_back(longest);
            prox.push_back(pai);
        }
        stack<int> resposta;
        while(melhorIdx!=-1){
            resposta.push(valores[melhorIdx]);
            melhorIdx = prox[melhorIdx];
        }
        printf("Max hits: %d\n",melhor);
        while(!resposta.empty())
            printf("%d\n",resposta.top()), resposta.pop();
        if(t) printf("\n");
    }
}