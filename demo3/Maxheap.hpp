#include<iostream>
#include<cmath>
using namespace std;

template<class T>
class Maxheap{

private:
    T* data;
    int capacity;
    int count;
public:
    Maxheap(int capacity){
        this->data = new T [capacity];
        this->capacity = capacity;
        this->count = 0;

    }

    ~Maxheap(){
        
        if ( this->data !=  NULL) {

         
         //   delete [] this->data;
            this->data = NULL;
            
        }


    }

    void insert(T data){
       
        if (this->count >= this->capacity){
            T* newspace = new T[this->capacity*2];
            for(int i = 0;i < this->count;i++){
                newspace[i] = this->data[i];
            }

           delete [] this->data;
            this->data = newspace;
            this->capacity = 2* this->capacity; 
            
            newspace = NULL;
           

        }
         this->data[this->count] = data;
            shiftUp(this->count);
            this->count++;

    }
void printhead(){
        int c = 0;
        int k = 1;
         
        while(c < this->count){
            cout<<"the "<<k<<" layer" <<endl;
            
            for(int j = 0;j < pow(2,k-1) && c < this->count;j++){
                
                cout<< this->data[c]<<"  ";
                c++;
               
            }
            cout<<endl;
            k++;

        }

    }

    T popelement(){

        
        if(this->count <=0 ){
            cout<<"heap is empty! return NULL"<<endl;
            return NULL;

        }
        T temp = this->data[0];
        this->data[0] = this->data[this->count-1];
        this->count--;
        shiftDown(0);

        return temp;



    }



    private:

void shiftDown(int k){

    int j = 2*k+1;
    T temp = this->data[k];
    while(j < this->count){
        

        if (this->data[j] < this->data[j+1] && j+1 < this->count)j = j+1;
        if (temp < this->data[j]){
            this->data[k] = this->data[j];
            k = j;
            j = 2*k+1;
        }
        else{
            break;
        }
    }
        this->data[k] = temp;


}
    void shiftUp(int k){

        T temp = this->data[k];
      
        while(k>0){

            if(temp> this->data[(k-1)/2]){
                this->data[k] = this->data[(k-1)/2];
                k = (k-1)/2;
            }
            else{

                break;
            }


        }
        this->data[k] = temp;


    }

    


};


void shiftDown(int k,int arr[],int len){

    int j = 2*k+1;
    int temp = arr[k];
    while(j < len){
      
        if (arr[j] < arr[j+1]&& j+1 < len)j = j+1;
        if (temp < arr[j]){
            arr[k] = arr[j];
            k = j;
            j = 2*k+1;
        }
        else{
            break;
        }
    }
        arr[k] = temp;


}

void print(int arr[],int len){

    for(int i =0 ;i<len;i++){

        cout<<arr[i]<<"  ";

    }
    cout<<endl;
}

void headsort(int arr[],int len){

    for(int i = (len-2)/2;i>=0;i--){
        shiftDown(i,arr,len);
    }
    

    for(int i =len-1;i>0;i--){

       
        
        swap(arr[i],arr[0]);
      //  cout<<"-----------1----"<<endl;
       // print(arr,len);


        shiftDown(0,arr,i);  //要注意i的值，代表了最后挪动的位置,swap函数至少要把下表为1的元素挪了才能结束；
       // cout<<"--------------"<<endl;
       // print(arr,len);


       
    }



}

 void shiftUp(int k,int arr[]){

        int temp = arr[k];
      
        while(k>0){

            if(temp> arr[(k-1)/2]){
                arr[k] = arr[(k-1)/2];
                k = (k-1)/2;
            }
            else{

                break;
            }


        }
       arr[k] = temp;


    }