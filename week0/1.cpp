#include <iostream>
#include <vector>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
      int temp;
      cin >> temp;
      v.push_back(temp);
    }
    int s; // element to search
    cin >> s;
    bool flag = false;
    int counter=0;
    for(int i=0;i<n;i++){
      counter++;
      if(v[i] == s){
        flag = true;
        cout << i << " " << counter << "\n";
        break;
      }
    }
    if(!flag){
      cout << "-1" << "\n";
    }
  }
  return 0;
}
