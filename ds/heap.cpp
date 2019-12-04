#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
}

class heap {
    int max_size;
    int size;
    int* arr;

public:

    int min(int a, int b) {
    if (arr[a] > arr[b]) {
        return b;
    }
    else
    {
        return a;
    }   
}

    heap(int capacity) {
        max_size = capacity;
        size = 0;
        arr = new int[max_size];
    }

    void heapifyup(int index) {
        int parent_index = (index - 1)/2;
        while (arr[parent_index] > arr[index]) {
                swap(arr[parent_index], arr[index]);
                index = (index - 1)/2;
                parent_index = (index - 1)/2;
        }
    }
    
    void heapifydown() {
        int index = 0;
        int leftchildindex = 2*index + 1;
        int rightchildindex = 2*index + 2;
        while(2*index <=size && arr[index] > arr[min(leftchildindex, rightchildindex)]) {
            int i = min(leftchildindex, rightchildindex);
            swap(&arr[index], &arr[i]);
            index = i;
            leftchildindex = 2*index + 1;
            rightchildindex = 2*index + 2;

        }
    }

    void insertkey(int key) {
        arr[size] = key;
        size++;
        int index = size - 1;
        heapifyup(index);        
    }

    void extractmin() {
        int minkey = arr[0];
        cout << "min key is " << minkey << endl;
        arr[0] = arr[size - 1];
        size--;
        heapifydown();
    }

    void printheap() {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
    }
};

int main() {
    heap h(11);
    h.insertkey(3); 
    h.insertkey(2);
    //h.deletekey(1); 
    h.insertkey(15);
    h.insertkey(1);
    h.insertkey(4); 
    h.insertkey(45);
    h.printheap();
    cout << endl;
    h.extractmin();
    h.printheap();
    return 0;
}