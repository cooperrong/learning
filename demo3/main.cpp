#include<iostream>
#include<ctime>
#include"Maxheap.hpp"
using namespace std;
void test(){

// Maxheap<int> h = Maxheap<int>(10);
 srand((unsigned int)time(NULL));
// for(int i = 0;i<10;i++){

//     h.insert(rand()%100);


// }
// //h.printhead();
// h.insert(1000);
// h.insert(100);
// //h.printhead();
// for(int i = 0;i<12;i++){

//     cout<< h.popelement()<<"  ";
// }
// cout<<endl;
int arr[10];
for(int i = 0;i<10;i++){

    arr[i] =rand()%100;
}



headsort(arr,10);
cout<<"+++++"<<endl;
for(int i = 0;i<10;i++){

    cout<<arr[i] <<"  ";

}
    cout<<endl;



}

int main(){
    test();

system("pause");
return 0;

}