#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<int> intVector;

void print(intVector vec);
void add(intVector &vec, int num);
void mergesort(intVector &arr, int low, int high);
void merge(intVector &arr, int low, int mid, int high);

int main(int argc, char *argv[]) {

  intVector arr;

  std:srand(std::time(0));
  int size = std::rand()%200;

  int val;
  for (int i=0; i < size ; i++) {
    val = std::rand() % 1000;
    arr.push_back(val);
  }

  print(arr);
  mergesort(arr, 0, arr.size()-1);
  print(arr);

}

void mergesort(intVector &arr, int low, int high) {

  int mid;

  if(low < high) {
    mid = (high+low)/2;
    mergesort(arr, low, mid);
    mergesort(arr, mid+1, high);
    merge(arr, low, mid, high);
  }
}

void merge(intVector &arr, int low, int mid, int high) {

  intVector::const_iterator beginP = arr.begin()+low;
  intVector::const_iterator midP = arr.begin() + mid+1;
  intVector::const_iterator midP1 = arr.begin() + mid + 1;
  intVector::const_iterator endP = arr.begin() + high + 1;
  intVector left(beginP, midP );
  intVector right(midP1, endP);

  int li=0, ri=0, fi=low;

  int leftSize  = left.size();
  int rightSize = right.size();

  while(li < leftSize && ri < rightSize) {
      if(left[li] > right[ri]) {
        arr[fi] = right[ri];
        ri++;
      }
      else{
        arr[fi] = left[li];
        li++;
      }
      fi++;
 }

 while(li < leftSize) {
  arr[fi++] = left[li++];
 }
         
 while(ri < rightSize) {
  arr[fi++] = right[ri++];
 }
}

void add(intVector &vec, int num) {
  for(int i=0; i< vec.size(); i++) {
      vec[i] += num;
  }
}

void print(intVector vec) {
  cout << "Content: " << "\n";
  for(int i=0; i< vec.size(); i++) {
      cout << vec[i] << " ";
  }
  cout << "\n";
}
