#include <iostream>
using namespace std;
int main() {
  int n, liczba = 1, chuj;
  cout<<"Podaj n: ";
  cin>>n;
  while(liczba <= n) {
    for(chuj = 2; chuj <= liczba; chuj++) {
      if(liczba%chuj == 0) {
        if (liczba == chuj) cout<<liczba<<endl;
        else break;
      }
    }  
    liczba++;
  }
  return 0;
}
