#include <iostream>
using namespace std;
//Function to print array

//Function to reverse array using an auxiliary array
void reverseArray(int arr[], int n) {
   if(n==0) return;

   cout<<arr[n-1]<<" ";
   reverseArray(arr, n-1);
}
int main() {
   int n = 5;
   int arr[] = {5,4,3,2,1};
   reverseArray(arr, n);
   return 0;
}