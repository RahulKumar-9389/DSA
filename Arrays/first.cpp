#include <iostream>
using namespace std;

int main(){

    int arr[6] = {2, 4, 6, 8, 10, 12};
    int size = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}