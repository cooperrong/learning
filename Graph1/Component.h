#include<iostream>
using namespace std;


template<class Graph>
class Component{

private:
    int ccount;
    bool* visited;
    int* id;
    Graph &G;

    void dfs(int v){
        visited[v] = true;
        id[v] = ccount;
        class Graph::adjIterator adj(v,G);

        for(int i = adj.begin(); !adj.end();i = adj.next()){

                    if(!visited[i]){

                        dfs(i);
                    }

        }


    }
    
public:
    Component(Graph &graph):G(graph){
        visited = new bool[G.Vertexs()];
        id = new int[G.Vertexs()];
        ccount = 0;
        for(int i =0; i< G.Vertexs();i++){

            visited[i] = false;
            id[i] = -1;
        }

        for(int i = 0; i< G.Vertexs();i++){

            if(!visited[i]){

                dfs(i);
                ccount++;
              
            }
        }





    }

    ~Component(){

        delete [] visited;
    }

int count(){
    return ccount;
}

bool isConnected(int v, int w){

    return id[v] == id[w];
}

};