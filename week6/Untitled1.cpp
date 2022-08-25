#include<iostream>
using namespace std;
class b
{
  public: int i;
  b()
  {
    i=10;
    cout<<"i "<<i<<endl;
  }
  
};
class d1:public b
{
  public:int j;
  d1():b()
  {
    j=20;
    cout<<"j "<<j<<endl;
  }
  
};

class d2:public b
{
  public:int k;
  d2():b()
  {
    k=30;
    cout<<"k "<<k<<endl;
  }
  
};


class d3:public d1, public d2
{
  public:int s;
  d3():d1(),d2()
  {
    s=0;
    cout<<"s "<<s<<endl;
  }
  
};

int main() {
d3 o;
//o.d1::i=40;
//o.j=50;
//o.k=60;
b b1;
  return 0;
}
