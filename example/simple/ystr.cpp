#include "mz/ystring.h"
#include "mz/time.h"
 
using namespace std;
using namespace std::mz;

int main(){
   
  Tbench b;
  for(int j=0; j<100; j++) b.Run([&]{
    for(int i=0; i<1e3; i++){
      auto v1 = ystr("A=% B=% C=% D=% E=% F=%\n", 1, 2.3, "abbl", 1.23456789012345678901, -12, make_tuple(1, make_tuple(2, 3.0)));
    }
  }); 


  yprintf("% ns per string parsing:\n",b.dur_avg()*1000000);
  yprintf("A=% B=% C=% D=% E=% F=%\n",1,2.3,"abbl", 1.23456789012345678901,-12,make_tuple(1,make_tuple(2,3.0)));
  yprintf("___\n");
  getchar();
  return 0;
}

