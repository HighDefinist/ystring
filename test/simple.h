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
}
