#pragma once
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

template<class Graph,class Weight>
class BellmanFord{
private:
  Edge<Weight> ** from;
  Weight * edgeto;
  Graph &G;
public:
    BellmanFord(Graph &g):G(g){

        from = new Edge<Weight>* [G.Vertexs()];
        edgeto = new Weight[G.Vertexs()];

        for(int i = 0 ; i < G.Vertexs();i++){

            from[i] = NULL;
            edgeto[i] = Weight();
        }

        for(int pass = 1; pass < G.Vertexs(); pass++){

            for(int i = 0; i < G.Vertexs(); i++){

                class Graph::adjIterator adj(i,G);
                for(Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next() ){

                    int w = e->other(i);
                    if(!from[w]){

                        edgeto[w] = edgeto[i]+e->Wt();
                        from[w] = e;
                    }
                    else if (  edgeto[i]+e->Wt() < edgeto[w]){
                        edgeto[w] = edgeto[i]+e->Wt();
                        from[w] = e;

                    }

                }
            }
        }
    }



};