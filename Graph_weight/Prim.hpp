#pragma once
#include<iostream>
#include<vector>
#include<cassert>
#include"IndexMinHeap.hpp"

using namespace std;


template<class Graph,class Weight>
class Prim{
private:
    Graph &G;
    vector<Edge<Weight>> MST;
    Edge<Weight>** edgeto;
    IndexMinHeap<Edge<Weight>> heap;
    bool* marked;


    void visit(int v){

        marked[v] = true;

     

        class Graph::adjIterator adj(v,G);

        for(Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()){
            int w = e->other(v);
                
           if(!marked[w]){
            
               if(!edgeto[w]){

                   heap.insertElement(w,*e);
                   edgeto[w] = e;
               }
               else if (*e < *edgeto[w]){
                   heap.changeElement(w,*e);
                   edgeto[w] = e;

                   
               }



           }
            


        }
    }
public:
    Prim(Graph &g):G(g),heap(IndexMinHeap<Edge<Weight>>(g.Vertexs())){
        edgeto = new Edge<Weight>*[G.Vertexs()];
        marked = new bool[G.Vertexs()];

      
       
        for(int i = 0; i < G.Vertexs();i++){

            edgeto[i] = NULL;
            marked[i] = false;
        }


        visit(3);

        while(!heap.isEmpty() && MST.size() < G.Vertexs()-1){

            int index = heap.extraIndex();
            visit(index);
           
            MST.push_back(*edgeto[index]);


        }




    }

    void showMST(){

        Weight w = MST[0].Wt();
        for(int i = 1; i < MST.size(); i++){

            w = w + MST[i].Wt();
        }

            cout<<"weight = "<<w<<endl;
        for(int i = 0; i < MST.size(); i++){


            cout<<MST[i]<<endl;
        }
    }






};

