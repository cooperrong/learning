#include<iostream>
#include<vector>
#include<cassert>
using namespace std;



class SparseGraph{
private:

    int n,m;
    bool directed;
    vector<vector<int>> g;

public:

    SparseGraph(int n,bool directed){

        this->n = n;
        this->directed = directed;
        this->m = 0;

        for(int i =0;i < n;i++){

            g.push_back(vector<int>());
        }
    }

    void addEdge(int v,int w){
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        g[v].push_back(w);
        m++;
        if(!directed){

            g[w].push_back(v);
            m++;
        }
    }
    
    bool hasEdge(int v ,int w){

        for(int i =0; i < g[v].size();i++){

            if(g[v][i] == w)return true;
        }

        return false;
    }
    class adjSparseGraph{
    private:
        int n;
        int index;
        SparseGraph &G;
    public:
        adjSparseGraph(int v,SparseGraph &graph):G(graph){
            //assert(v >= 0 && v < n);
           

            this->n =v;
            this->index = 0;
        }

        int begin(){
            this->index = 0;
            if(G.g[this->n].size()){
           return G.g[this->n][this->index];
            }
            return -1;

        }

        int next(){
            this->index++;
            if(this->index < this->G.g[this->n].size()){

                return this->G.g[this->n][this->index];
            }
            else{

                return -1;
            }

        }

        bool end(){

            return this->index >= this->G.g[this->n].size();
        }



    };





};