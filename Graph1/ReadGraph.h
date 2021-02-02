#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<cassert>
#include"SparseGraph.h"
#include"DensGraph.h"
using namespace std;

template<class Graph>
class ReadGraph{

private:
    int V, E;
    Graph graph;
public:
    ReadGraph(Graph &graph,const string &filename):graph(graph){
       

        ifstream file(filename);
        string line;
        

            assert(file.is_open());

            assert(getline(file,line));
        stringstream ss(line);
        ss>>V>>E;
        assert(V == graph.Vertexs());
        for(int i = 0;i<E;i++){

            assert(getline(file,line));
            stringstream ss(line);
            int a,b;
            ss>>a>>b;
            assert(a>=0 && a<V);
            assert(b>= 0 && b<V);
            graph.addEdges(a,b);
            

        }
        file.close();

    }
    



};