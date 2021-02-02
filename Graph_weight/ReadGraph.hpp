#pragma once
#include<iostream>
#include<cassert>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

template<class Graph,class Weight>
class ReadGraph{

private:
    int V,E;
    Weight w;
    Graph &G;
    string line;
public:
    ReadGraph(string name, Graph &g):G(g){
        
        ifstream file(name);
        assert(file.is_open());
        assert(getline(file,line));
        stringstream ss(line);
        ss>>V>>E;
        for(int i = 0 ; i< E;i++){

            assert(getline(file,line));
            stringstream ss(line);
            int a,b;
            ss>>a>>b>>w;

            G.addEdges(a,b,w);
        }
        file.close();
    }
    void showgraph(){

        for(int i = 0 ; i<G.Vertexs();i++){

           cout<<" vertexs "<<i<<":";
           class Graph::adjIterator adj(i,G);
            for(Edge<Weight>* w = adj.begin();!adj.end();w = adj.next()){

                cout<<*w<<" ";

            }

            cout<<endl;
        }
    }




};