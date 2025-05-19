#include <bits/stdc++.h>
using namespace std;
// /* when we use counting sort we need to know the range of the elements
//    so we can use counting sort when the range of the elements is small
//    and we can use counting sort when the range of the elements is large
//    but the number of elements is small

void countsort(int arr[], int n){

  int minVal = INT_MAX;
  int maxVal = INT_MIN;
  for(int i = 0; i<n; i++){
    minVal = min(minVal, arr[i]);
    maxVal = max(maxVal, arr[i]);
  }
  int freq[maxVal+1] ={0};
  // 1st step

  for(int i = 0; i<n; i++){
    freq[arr[i]]++;
  }
  // 2nd step

  for(int i = minVal, j=0; i<= maxVal; i++){
    while (freq[i]>0){
      arr[j++] = i;
      freq[i]--;
    }
  }
   for (int i = 0; i<11; i++){
    cout<<arr[i]<<" ";
  }
}
int main(){
  int arr[11] =  {40,64,51 ,5 ,6, 40, 6 ,4 ,4,11,60};
  countsort(arr, 11);
 
  cout<<endl;
  return 0;
}