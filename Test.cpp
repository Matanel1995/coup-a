#include "doctest.h"
#include "Player.hpp"
#include "Duke.hpp"
#include "Ambassador.hpp"
#include "Contessa.hpp"
#include "Captain.hpp"
#include "Assassin.hpp"

using namespace std;
using namespace coup;

TEST_CASE("Global test"){
    Game testGame{};
    Duke duke(testGame, "Nimrod");
    Assassin assassin(testGame,"Yakov");
    Ambassador ambassador(testGame, "Shula");
    Captain captain(testGame, "Jack Sparrow");
    Contessa contessa(testGame, "Ragnar");
    CHECK(duke.money == 0);
    CHECK(assassin.money == 0);
    CHECK(ambassador.money == 0);
    CHECK(captain.money == 0);
    CHECK(contessa.money == 0);
    // should throw if some one coup now
    CHECK_THROWS(duke.coup(assassin));
    CHECK_THROWS(assassin.coup(captain));
    CHECK_THROWS(ambassador.coup(assassin));
    CHECK_THROWS(captain.coup(assassin));
    CHECK_THROWS(contessa.coup(assassin));

    // cant coup yourself should throw
    CHECK_THROWS(duke.coup(duke));
    CHECK_THROWS(assassin.coup(captain));
    CHECK_THROWS(ambassador.coup(ambassador));
    CHECK_THROWS(captain.coup(captain));
    CHECK_THROWS(contessa.coup(contessa));
    
    // give players some money and then try to coup (only assassins should be able)
    // each player have 4 coins
    CHECK_THROWS(duke.foreign_aid());
    CHECK_THROWS(duke.foreign_aid());
    CHECK_THROWS(assassin.foreign_aid());
    CHECK_THROWS(assassin.foreign_aid());
    CHECK_THROWS(ambassador.foreign_aid());
    CHECK_THROWS(ambassador.foreign_aid());
    CHECK_THROWS(captain.foreign_aid());
    CHECK_THROWS(captain.foreign_aid());
    CHECK_THROWS(contessa.foreign_aid());
    CHECK_THROWS(contessa.foreign_aid());

    // check the coup
    CHECK_THROWS(duke.coup(ambassador));
    CHECK_THROWS(ambassador.coup(ambassador));
    CHECK_THROWS(captain.coup(ambassador));
    CHECK_THROWS(contessa.coup(ambassador));
    CHECK_NOTHROW(assassin.coup(ambassador));
}