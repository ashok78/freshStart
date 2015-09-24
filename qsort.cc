#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
using std::vector;
using std::rand;

int quicksort(std::vector<int> &arr, int low, int high);
int partition(std::vector<int> &arr, int low, int high);
void swap(int &a, int &b);
void printVector(std::vector<int> &arr);


int main(int argc, char *argv[]){

  std::srand(std::time(0));
  int size = std::rand() % 200000 + 1;

  size = 1000000;
  std::vector<int> arr;
  
  cout << "Size: " << size << "\n";
  for (int i=0; i<size; i++) {
    arr.push_back(std::rand());
  }

  //printVector(arr);

  quicksort(arr,0,arr.size()-1);

  //printVector(arr);

  return 0;
}

int quicksort(std::vector<int> &arr, int low, int high) {

  int p;

  if(low < high ) {
    p = partition(arr, low, high);
   	quicksort(arr, low, p-1);
    quicksort(arr, p+1, high);
  }

  return 0;
}

int partition(std::vector<int> &arr, int low, int high ) {

  int pivot = arr[high];

  int scratchIndex = low; 
  int temp;

  for(int ci=low; ci<high; ci++) {
    if (arr[ci] <= pivot ){
      swap(arr[scratchIndex], arr[ci]);
      scratchIndex++;
    }
  }

  swap(arr[scratchIndex], arr[high]);
  return scratchIndex;
}


void printVector(std::vector<int> &arr) {
    for (int i=0; i<arr.size(); i++) {
      cout << arr[i] << " ";
    }
    cout << "\n";
}


void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
