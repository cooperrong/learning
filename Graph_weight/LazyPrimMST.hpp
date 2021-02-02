#pragma once
#include<iostream>
#include<vector>
#include<cassert>
#include"Edge.hpp"
#include"MinHeap.hpp"

using namespace std;

template<class Graph, class Weight>
class LazyPrimMST{
private:
    Graph &G;
    bool* marked;
    MinHeap<Edge<Weight>> hp;
    vector<Edge<Weight>> mst;
    Weight mstweight;
    void visit(int v){

        assert(!marked[v]);
        marked[v] = true;
        class Graph::adjIterator adj(v,G);
        for(Edge<Weight>* e = adj.begin(); !adj.end();e = adj.next()){

            if(!marked[e->other(v)]){

                hp.insrtelement(*e);
            }
        }
    }


public:
    LazyPrimMST(Graph&g):G(g),hp(MinHeap<Edge<Weight>>(G.Edges())){

        marked = new bool[G.Vertexs()];
        

        for(int i = 0; i < G.Vertexs();i++){

            marked[i] = false;

        }

        mst.clear();
        visit(0);
        while(!hp.isEmpty()){

            Edge<Weight> e = hp.extractMin();

            if(marked[e.V()] == marked[e.W()]){

                continue;
            }
            else{

                mst.push_back(e);
                cout<<"e="<<e.Wt()<<endl;
            }

            if(!marked[e.V()]){

                visit(e.V());
            }
            else{

                visit(e.W());
            }



        }

        mstweight = mst[0].Wt();
        for(int i = 1 ; i < mst.size(); i++){

            mstweight += mst[i].Wt(); 
            cout<<"weight = "<< mst[i]<<endl;
        }

    }



     ~LazyPrimMST(){

            delete [] marked;
        }
        
        vector<Edge<Weight>> mstEdge(){

            return mst;
        }

        Weight result(){
            return mstweight;
        }


};