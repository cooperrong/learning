#pragma once
#include<iostream>
#include<cassert>
#include<vector>
#include"Edge.hpp"

using namespace std;
template<class Weight>
class SparseGraph{
private:

    int vertexs,edges;
    bool directed;
    vector<vector<Edge<Weight>*>> list;

public:

    SparseGraph(int v,bool directed){

        this->vertexs = v;
        this->directed = directed;
        this->edges= 0;

        for(int i =0;i < vertexs;i++){

            list.push_back(vector<Edge<Weight>*>());
        }
       
    }
    int Vertexs(){

        
        return vertexs;
    }
    int Edges(){

        return edges;
    }
    void addEdges(int v,int w,Weight weight){
        assert(v >= 0 && v < vertexs);
        assert(w >= 0 && w < vertexs);
        if(v != w){
            if(hasEdge(v,w)){
                for(int i = 0; i < list[v].size();i++){

                     if(list[v][i]->other(v) == w){
                        delete list[v][i];
                        list[v][i] = new Edge<Weight>(v,w,weight);
                     }  
                    
                }

                if(!directed){
                    for(int i = 0; i < list[w].size();i++){

                     if(list[w][i]->other(w) == v){
                        delete list[w][i];
                        list[w][i] = new Edge<Weight>(w,v,weight);
                     }
                    }
                    
                }

                

               

            }
            else{

                list[v].push_back(new Edge<Weight>(v,w,weight));
                this->edges++;
            if(!directed){
                list[w].push_back(new Edge<Weight>(w,v,weight));
            }
         }

        
            
        
        }
    }
    
    bool hasEdge(int v ,int w){
        assert(v >= 0 && v < vertexs);
        assert(w >= 0 && w < vertexs);

        for(int i =0; i < list[v].size();i++){

            if(list[v][i]->other(v) == w)return true;
        }

        return false;
    }
    class adjIterator{
    private:
        int v;
        int index;
        SparseGraph &G;
    public:
        adjIterator(int v,SparseGraph &graph):G(graph){
            
           

            this->v =v;
            this->index = 0;
        }

        Edge<Weight>* begin(){
            this->index = 0;
            if(G.list[this->v].size()){
           return G.list[this->v][this->index];
            }
            return NULL;

        }

        Edge<Weight>* next(){
            index++;
            
           if(index < G.list[v].size()){

               return G.list[v][index];

           }
           
           return NULL;

        }

        bool end(){

            return this->index >= this->G.list[this->v].size();
        }
    };





};