TEST_CASE("ystring special", "Main functionality") {
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
