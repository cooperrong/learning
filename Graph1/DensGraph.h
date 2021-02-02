#pragma once
#include<iostream>
#include<vector>
#include<cassert>
#include"Edge.h"
using namespace std; 

template<class Weight>
class DensGraph{
private:

    int vertexs;
    int edges;
    bool directed;
    vector<vector<Edge<wight>*>> list;
public:
    DensGraph(int v,bool directed){
        this->directed = directed;
        this->vertexs = v;
        this->edges = 0;
        for(int i = 0; i< v;i++){

            list.push_back(vector<Edge<Weight>*>(this->vertexs,NULL));
        }
    }

    int Vertexs(){
        return this->vertexs;
    }
    int Edges(){

        return this->edges;
    }

    bool hasEdges(int v,int w){
         assert(v >= 0 && v< this->vertexs);
        assert(w >= 0 && w< this->vertexs);

        return list[v][w];
    }
    void addEdges(int v,int w,Weight weight){
         assert(v >= 0 && v< this->vertexs);
            assert(w >= 0 && w< this->vertexs);
         if(!this->hasEdges(v,w) && v != w){
            this->list[v][w] = new Edge<Weight>(v,w,weight);
            if(!directed){
                this->list[w][v] = new Edge<Weight>(w,v,weight);

            }
            this->edges++;
         }

    }

    class adjIterator{
    private:

        DensGraph &graph;
        int index;
        int line;
    public:
        adjIterator(int l,DensGraph &g):graph(g){

            this->line = l;
            this->index = -1;
        }
        int begin(){
                this->index = -1;
            return next();
        }

        int next(){
            for(this->index++;this->index < graph.Vertexs();this->index++ ){

                if(graph.list[line][index]){
                    return index;
                }
            }

            return -1;

        }

        int end(){

            return this->index >= graph.Vertexs();
        }




    };

    void graphshow(){

        for(int i = 0; i<this->Vertexs();i++){
            for(int j = 0; j<this->vertexs;j++){

                cout<<list[i][j]<<" ";
            }
            cout<<endl;
        }
    }




};