// Day 5 :  Find Next Permutation of an array.

#include<bits/stdc++.h>
using namespace std;

// function for next permutation.
void NexPer(vector<int> & arr){
    int n = arr.size();
    int pivot = -1;
    for(int i = n-2;i>=0;i--){ // finding pivot index from backward.
        if(arr[i]<arr[i+1]){
            pivot = i;
            break;
        }
    }
    if(pivot == -1){ // if pivot not found then its is last permuatation so reverse it and get first one.
        reverse(arr.begin(),arr.end());
        return;
    }
    for(int i=n-1;i>pivot;i--){ // finding rightmost greater element than pivot and swap it.
        if(arr[i]>arr[pivot]){
            swap(arr[i],arr[pivot]);
            break;
        }
    }
    int k = pivot+1;
    reverse(arr.begin()+k,arr.end());
}

int main(){
    vector<int> V = {2,4,1,7,5,0};
    NexPer(V);
    for(int i : V){
        cout << i << " ";
    }
}