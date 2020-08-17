#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
   }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }
  
  void swim(int k){
        while((k>1) && less(data_[k],data_[k/2])){
            swap(data_,k,k/2);
            k=k/2;
        }
    }
    
    void sink(int k){
        while(2*k<=data_.size()){
            int min = less(data_[2*k],data_[2*k+1])?2*k:2*k+1;
            if(less(data_[k],data_[min]))
                break;
            swap(data_,k,min);
            k=min;
        }
    }
    
    void swap(vector<int> ar,int i,int j){
        int temp = ar[i];
        ar[i] = ar[j];
        ar[j] = temp;
    }
    
    bool less(int x,int y){
        return x<y;
    }

        int leftValue(int i){
    return 2*i + 1;
  }

  int rightValue(int i){
    return 2*i + 2;
  }

  int parent(int i){
    return floor((i-1)/2);
  }

  void swimDown(int i){
    int minIndex = i;
    int l = leftValue(i);
    if(l <= data_.size()-1 && data_[l] < data_[minIndex])
      minIndex = l;
    int r = rightValue(i);
    if(r <= data_.size()-1 && data_[r] < data_[minIndex])
      minIndex = r;
    if(i != minIndex){
      swap(data_,data_[i], data_[minIndex]);
      swaps_.push_back(make_pair(i, minIndex));
      swimDown(minIndex);
    }
  }

  int minVbyI(int lI,int rI){
      if(data_[lI]<data_[rI]){
          return lI;
      }else{
          return rI;
      }
  }

  void GenerateSwaps(){
    swimDown(data_.size()-1);
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}