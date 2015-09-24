#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<int> intVector;

void print(const intVector &vec);
void insertionSort(intVector &vec);

int main(int argc, char * argv[]) {

  intVector vec;

  std::srand(std::time(0));

  int size = std::rand() % 10;

  for (int i=0; i<size; i++) {
    vec.push_back(std::rand()%1000);
  }

  print(vec);

  insertionSort(vec);

  print(vec);

  return 0;
}


void insertionSort(intVector &vec) {
  if(vec.size() < 2) {
    return;
  }

  for(int out=1; out < vec.size(); out++) {
    int element = vec[out];
    int in = out - 1;

    while(in >= 0 && vec[in] > element) {
        vec[in+1] = vec[in];
        in--;
    }
    vec[in+1] = element;

  }
}

void print(const intVector &vec) {
  cout <<"Content: \n";
  for (int i=0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
  cout << "\n";
}

