#include<iostream>
using namespace std;
#include<memory>

class Array{
    private:
    unique_ptr<int[]> arr;
    int size;
    int capacity;

    public:
    Array(int capacity): capacity(capacity), size(0){
        arr = make_unique<int[]>(capacity);
    }
    void insert(int value){
        if(size==capacity){
            throw range_error("Array is full");
        }
        arr[size++] = value;
    }

    int get(int index){
        if(index>=size){
            throw range_error("Index out of range");
        }
        return arr[index];
    }

    int get_size(){
        return size;
    }

    int pop(){
        if(size==0){
            throw range_error("Array is empty");
        }
        return arr[--size];
    }
    void display(){
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

int main(){
    Array arr(5);
    arr.insert(1);
    arr.insert(2);
    arr.insert(3);
    arr.insert(4);
    arr.insert(5);
    arr.display();
    cout<<arr.get(2)<<endl;
    cout<<arr.pop()<<endl;
    arr.display();
    return 0;
}
