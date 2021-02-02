#pragma once
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

template<class Graph>
class ShortPath{
private:
    bool* visited;
    int* from ;
    int* order;
    int s;
    Graph &G;
    void BFS(int v){

        visited[v] = true;
        order[v] = 0;

        queue<int> q;
        q.push(v);
        while(!q.empty()){
            int m = q.front();
            q.pop();
            

        class Graph::adjIterator adj(m,G);
        for(int i = adj.begin(); !adj.end(); i = adj.next()){

                if(!visited[i]){

                    q.push(i);
                     visited[i] = true;
                    from[i] = m;
                    order[i] = order[m]+1;
                }            
        }
        }
    }

public:
    ShortPath(int source,Graph &g):G(g){
        visited = new bool[G.Vertexs()];
        from  = new  int [G.Vertexs()];
        order = new  int[G.Vertexs()];
        this->s = source;
        for(int i = 0; i < G.Vertexs(); i++){


            visited[i] = false;
            from[i]  = -1;
            order[i] = -1;
        }
        
        BFS(s);
    }


    bool hasEdges(int w){

        return  visited[w];
    }

    void road(int w, vector<int> &vec){

        if(hasEdges(w)){
            vec.clear();
            int p = w;
            
            stack<int> st;
            while(p != -1){
                st.push(p);
                p = from[p];
               

            }

            while(!st.empty()){
                vec.push_back(st.top());
                
                st.pop();
                
            }
        }
        return;

    }
    void showpath(int w){
        vector<int> vec;
        road(w,vec);
        cout<<"BFS:";
        
        for(int i = 0; i< vec.size(); i++){

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
