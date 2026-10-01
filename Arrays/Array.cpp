#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,2,3,4,5,6};
    int idx = 2;
    for(int i=1; i<=idx; i++){
        arr[i-1] = arr[i];
    }
    arr[idx] = 9;

    for(int num:arr){
        cout << num << " ";
    }
}