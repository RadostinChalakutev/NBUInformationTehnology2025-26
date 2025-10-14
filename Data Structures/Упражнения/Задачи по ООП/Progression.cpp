//
// Created by rados on 14.10.2025 г..
//

#include "Progression.h"
#include <iostream>
using namespace std;

class Progression {
  public:
    Progression(long f=0);
    virtual ~Progression();

    long getFirst(){return first;}
    void setFirst(long f){first=f;}
    long getCur(){return cur;}
    void setCur(long f){cur=f;}

    void printProgression();
    protected:
      virtual long firstValue();
      virtual long nextValue();

      protected:
        long cur;
        long first;

};






Progression::Progression(long f):first (f),cur(f) {}
Progression::~Progression() {}

void Progression::printProgression(int n){
  cout<<firstValue();
  for(int i=2; i<=n; i++){
    cout<<' '<<nextValue();
    cout<<endl;
  }

}
