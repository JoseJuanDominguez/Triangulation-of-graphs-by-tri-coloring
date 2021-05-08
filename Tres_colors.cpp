#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <utility>
#include<algorithm>


using namespace std;

int main(){
    int cont=0;
    map<int, pair<string, vector<int>>> grafoColores;
    vector<string> colores;
    ifstream ent ("entrada.in");
    ifstream col("colores.in");
    string color;
    while(col>>color){
        colores.push_back(color);
    }
    char dato;
    int inicial;
    while(ent>>inicial)
    {
        pair<string,vector<int>> datos;
        vector<int> conexiones;
        ent>>dato;
        while (dato != '|')
        {
            conexiones.push_back(atoi(&dato));
            ent>>dato;
        }
        datos.second= conexiones;
        grafoColores[inicial] = datos;
    }
    for(auto node : grafoColores)
    {
        vector<string> coloresRestantes;
        coloresRestantes = colores;
        for( int i = 0; i< node.second.second.size(); i++)
        {
            for( int j = 0; j<coloresRestantes.size(); j++)
            {
                if( grafoColores[node.second.second[i]].first.compare(coloresRestantes[j]) == 0)
                {
                        coloresRestantes.erase(coloresRestantes.begin()+j);
                }
            }
        }
        grafoColores[node.first].first = coloresRestantes[0];
    }

    for(auto node: grafoColores)
    {
        cout<<"nodo: "<<node.first<<" tiene color "<<node.second.first<<endl;
    }



    for(auto node: grafoColores)
    {
        auto nodeAux = node; 
        int i=nodeAux.first;
        for(i=i+1;i<=grafoColores.size();i++)
        {
            if(find(grafoColores[i].second.begin(), grafoColores[i].second.end(), nodeAux.first)==grafoColores[i].second.end())
            {
                if(nodeAux.second.first!=grafoColores[i].first)
                {
                    grafoColores[i].second.push_back(nodeAux.first); 
                    nodeAux.second.second.push_back(i); 
                    cont++; 

                    cout<<"Nueva arista de "<<nodeAux.first<<" con "<<i<<endl;

                }
            }

        }

        if((grafoColores.size()-cont)==3)
                    {
                        break;
                    }
    }
}




