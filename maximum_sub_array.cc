#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<int> intVector;

void find_maximum_subarray_cross(const intVector &vec, int low, int mid, int high, int &i, int &j, int &sum);
void find_maximum_subarray(const intVector &vec, int low, int high, int &i, int &j, int &sum);
void print(const intVector &vec, int start=0, int end=-9999);

int main(int argc, char * argv[]) {

  intVector vec;
  std::srand(std::time(0));
  
  int size = std::rand() % 10;
  int range = 100;
  for (int i=0; i<size; i++) {
    vec.push_back(std::rand()%range - range/2);
  }

  print(vec);

  int start, end, sum;
  if(vec.size()) {
	  find_maximum_subarray(vec, 0, vec.size()-1, start, end, sum);
	  print(vec, start, end+1);
  }
  return 0;
}

void print(const intVector &vec, int start, int end) {

  if(start < 0 ) {
    return;
  }

  if( end < 0 && end != -9999) {
    return;
  }

  if( end == -9999) {
      end = vec.size();
  }

  for(int i=start; i < end; i++) {
      cout << vec[i] << " ";
  }
  cout << "\n";
}

void find_maximum_subarray_cross(const intVector &vec, int low, int mid, int high, int &i, int &j, int &sum) {

  int left_sum = -9999;
  int right_sum = -9999;

  int li = mid;
  int ri = mid+1;

  int lsum = 0;

  while( li >= low) {
    lsum = lsum + vec[li];


    if( lsum > left_sum) {
        left_sum = lsum;
        i = li;
    }
    li--;
  }

  lsum = 0;

  while( ri <= high) {
    lsum = lsum + vec[ri];

    if( lsum > right_sum) {
        right_sum = lsum;
        j = ri;
    }
    ri++;
  }

  sum = left_sum + right_sum;
}

void find_maximum_subarray(const intVector &vec, int low, int high, int &i, int &j, int &sum) {
   
   if(low == high) {
      sum = vec[low];
      i = j = low;
      return;
   }

   int mid = (low+high) / 2;

   int li, lj, lsum;
   int ri, rj, rsum;
   int ci, cj, csum;

   find_maximum_subarray(vec, low, mid, li, lj, lsum);
   find_maximum_subarray(vec, mid+1, high, ri, rj, rsum);
   find_maximum_subarray_cross(vec, low, mid, high, ci, cj, csum); 


   if(lsum >= rsum && lsum >= csum) {
      sum = lsum;
      i = li;
      j = lj;
      return;
   }
   if(rsum >= lsum && rsum >= csum) {
      sum = rsum;
      i = ri;
      j = rj;
      return;
   }

   sum = csum;
   i = ci;
   j = cj;
}

