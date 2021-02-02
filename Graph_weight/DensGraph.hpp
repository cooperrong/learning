#pragma once
#include<iostream>
#include<cassert>
#include<vector>
#include"Edge.hpp"

using namespace std;
template<class Weight>
class DensGraph{
private:

    int vertexs,edges;
    bool directed;
    vector<vector<Edge<Weight>*>> list;

public:

    DensGraph(int v,bool directed){

        this->vertexs = v;
        this->directed = directed;
        this->edges= 0;

        for(int i =0;i < vertexs;i++){

            list.push_back(vector<Edge<Weight>*>(vertexs,NULL));
        }
    }

    int Vertexs(){
        return this->vertexs;
    }
    int Edges(){

        return this->edges;
    }
    void addEdges(int v,int w,Weight weight){
        assert(v >= 0 && v < vertexs);
        assert(w >= 0 && w < vertexs);
        if(v == w){

            return;
            
            
        }
        else if ( hasEdge(v,w)){

                delete list[v][w];

                list[v][w] = new Edge<Weight>(v,w,weight);
            if(!directed){
                delete list[w][v];

                list[w][v] = new Edge<Weight>(w,v,weight);
            }
        }
        else{

            list[v][w] = new Edge<Weight>(v,w,weight);
            if(!directed){

                list[w][v] = new Edge<Weight>(w,v,weight);
            }
        }

    }
    
    bool hasEdge(int v ,int w){
        assert(v >= 0 && v < vertexs);
        assert(w >= 0 && w < vertexs);

        return list[v][w] != NULL ;
    }
    class adjIterator{
    private:
        int v;
        int index;
        DensGraph &G;
    public:
        adjIterator(int v,DensGraph &graph):G(graph){
            
           

            this->v =v;
            this->index = 0;
        }

        Edge<Weight>* begin(){
            this->index = -1;
            return next();

        }

        Edge<Weight>* next(){
            
            for(index+=1;index < G.list[v].size();index++){

                    if(G.list[v][index]){

                        return G.list[v][index];
                    }
            }
           
           return NULL;

        }

        bool end(){

            return this->index >= this->G.list[this->v].size();
        }
    };





};