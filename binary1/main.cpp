#include<iostream>
#include<ctime>
#include"BST.hpp"

using namespace std;

void test(){

    srand(time(NULL));
    BST<int, int> root;
    for(int i = 0; i < 20; i++){

        int key = rand()%20;
        
        root.insert(key,rand()%100);
       
    }
         cout<<"size = "<<root.size()<<endl;
         cout<<"pred------------"<<endl;
         root.predepthprint();
         cout<<endl;
          cout<<"inorder--------"<<endl;
         root.indepthprint();
         cout<<endl;
        cout<<"postorder---------"<<endl;
         root.postdepthprint();
         cout<<endl;
        cout<<"breath--------------"<<endl;
         root.breathPrint();
         cout<<endl;
         root.deletMin();
        cout<<"breath  delete--------------"<<endl;
         root.breathPrint();
         cout<<endl;


}

int main(){
    test();

    system("pause");
    return 0;
}