#pragma once
#include<stack>
#include<vector>
#include<iostream>
#include"MinHeap.hpp"

using namespace std;

template<class Graph, class Weight>
class Dijkstra {
private:
   
    Graph &G;
    int * distTo;
    Edge<Weight>** from;
    int s;
public:
    Dijkstra(int source,Graph &g):G(g){
       
        distTo = new int[G.Vertexs()];
        from  = new Edge<Weight>*[G.Vertexs()];
        this->s = source;
        for(int i = 0; i < G.Vertexs(); i++){

           
            from[i]  = NULL;
            distTo[i] = 0;
        }

    //Dijkstra
    MinHeap<Edge<Weight>> heap(G.Edges());
    from[s] = new Edge<Weight>(s,s,Weight());
    Edge<Weight> e ;
    heap.insrtelement(*from[s]);
    while(!heap.isEmpty()){
        e = heap.extractMin();
        int v = e.W();
        class Graph::adjIterator adj(v,G);
        for(Edge<Weight> *it = adj.begin(); !adj.end(); it = adj.next() ){
            int w = it->other(v);
                    
                if( !from[w] ){
                     from[w] = it;
                     distTo[w] = distTo[v] + it->Wt();
                     heap.insrtelement(*it);
               }
                 else if (distTo[v] + it->Wt() < distTo[w]){
                     from[w] = it;
                     distTo[w] = distTo[v] + it->Wt();
                     heap.insrtelement(*it);
                }
            
        }
    }

    



    }

    ~Dijkstra(){

       
        delete [] from;
    }

void showPath(int w){

    int v = w;
    stack<int> st;
    st.push(w);
    Edge<Weight>* e;
    e = from[w];

    while(w != s){

        w = e->other(w);
        e = from[w];
        st.push(w);
    }    
    vector<int> vec;
    while(!st.empty()){

        vec.push_back(st.top());
        st.pop();
    }

    cout<<"the path "<<s<<" to "<<v<<" weight : "<< distTo[v]<<endl;

    for(int i = 0; i < vec.size(); i++){

        cout<<vec[i]<<" ";
        if(i == vec.size()-1){


        }
        else {

            cout<<" -> ";
        }
    } 
    cout<<endl;
}



};