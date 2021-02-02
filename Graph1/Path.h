#pragma once
#include<iostream>
#include<cassert>
#include<vector>
#include<stack>


template<class Graph>
class Path{

private:
    bool* visited;
    int* from;
    Graph &G;
    int s;

    void dfs(int v){

        visited[v] = true;

        class Graph::adjIterator adj(v,G);
        for(int i = adj.begin();!adj.end();i = adj.next()){

            if(!visited[i]){
                from[i] = v;

                dfs(i);
            }
        }
    }
public:
    Path(int source,Graph &g):G(g){

        visited = new bool[G.Vertexs()];
        from = new int[G.Vertexs()];
        this->s = source;

        for(int i = 0; i < G.Vertexs(); i++){

            visited[i] = false;
            from[i]  = -1;
        }

        dfs(s);



    }
    ~Path(){

        delete [] from;
        delete [] visited;
    }

    bool hasEdge(int w){

        return visited[w];


    }

    vector<int>  road(int w, vector<int> &vec){
        assert(w >= 0 && w < G.Vertexs());
        vec.clear();
        if(hasEdge(w)){
         int p = w;
        
         stack<int> s;
            while(p != -1){
             s.push(p);
             p = from[p];
            }

        

            while(!s.empty()){
                p = s.top();
                s.pop();
                vec.push_back(p);
                
            }
        }
            return vec;

    }

    void showpath(int w,vector<int> &vec){
        road(w,vec);
        for(int i = 0; i<vec.size();i++){

            cout<<vec[i]<<" ";

            if(i == vec.size()-1){


            }
            else{

                cout<<"->"<<" ";
            }
        }
        cout<<endl;



    }





};