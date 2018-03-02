#include "mz/ystring.h"
#include "mz/time.h"
 
using namespace std;
using namespace std::mz;

#define CATCH_CONFIG_MAIN  
#include "catch.hpp"

TEST_CASE("ystring main", "Main functionality") {
  SECTION("Conversion basics") {
    REQUIRE(ystr("Integer=%", 2) == "Integer=2");
    REQUIRE(ystr("Float=%", 3.5f) == "Float=3.5");
    REQUIRE(ystr("Double=%", 4.5) == "Double=4.5");
    REQUIRE(ystr("String=%", "abc") == "String=abc");
    REQUIRE(ystr("WString=%", L"abc") == "WString=abc");
    REQUIRE(ystr("Tuple=%",make_tuple(1, 2, "abc")) == "Tuple=[1;2;abc]");
    REQUIRE(ystr("PercentSign=%%") == "PercentSign=%");
    REQUIRE(ystr("NoParameter") == "NoParameter");
  }
  SECTION("Special stuff"){
    REQUIRE_THROWS(ystr("MissingArgument=%"));
    REQUIRE_THROWS(ystr("TooManyArguments", 3));
    REQUIRE(ystr("SpecialCase=%%%", 2) == "SpecialCase=%2");
    REQUIRE_THROWS(ystr("SpecialCase=%%%"));
    REQUIRE_THROWS(ystr("SpecialCase=%%%",2,3));
    REQUIRE(ystr("SpecialCase=%%%%") == "SpecialCase=%%");
    REQUIRE(ystr("SpecialCase=% %%",2) == "SpecialCase=2 %");
    REQUIRE(_str(23.2) == "23.2");
  }
}

//
//int main(){
//   
//  Tbench b;
//  for(int j=0; j<100; j++) b.Run([&]{
//    for(int i=0; i<1e3; i++){
//      auto v1 = ystr("A=% B=% C=% D=% E=% F=%\n", 1, 2.3, "abbl", 1.23456789012345678901, -12, make_tuple(1, make_tuple(2, 3.0)));
//    }
//  }); 
//
//
//  yprintf("% ns per string parsing:\n",b.dur_avg()*1000000);
//  yprintf("A=% B=% C=% D=% E=% F=%\n",1,2.3,"abbl", 1.23456789012345678901,-12,make_tuple(1,make_tuple(2,3.0)));
//  yprintf("___\n");
//  getchar();
//  return 0;
//}
//
