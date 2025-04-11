#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch2.hpp"
#include "../homework.cpp"

TEST_CASE("Animal Constructor", "[animal]")
{
    SECTION("Valid parameters")
    {
        Animal animal("Buddy", 5, 10.5);
        REQUIRE(animal.getName() == "Buddy");
        REQUIRE(animal.getAge() == 5);
        REQUIRE(animal.getWeight() == 10.5);
        REQUIRE_FALSE(animal.getHungerStatus());
    }

    SECTION("Invalid parameters")
    {
        REQUIRE_THROWS_AS(Animal("", 5, 10.5), invalid_argument);
        REQUIRE_THROWS_AS(Animal("Buddy", -1, 10.5), invalid_argument);
        REQUIRE_THROWS_AS(Animal("Buddy", 5, -1.0), invalid_argument);
    }
}

TEST_CASE("Animal setName", "[animal]")
{
    Animal animal("Buddy", 5, 10.5);

    SECTION("Valid name")
    {
        animal.setName("Max");
        REQUIRE(animal.getName() == "Max");
    }

    SECTION("Empty name")
    {
        REQUIRE_THROWS_AS(animal.setName(""), invalid_argument);
    }
}

TEST_CASE("Animal setAge", "[animal]")
{
    Animal animal("Buddy", 5, 10.5);

    SECTION("Valid age")
    {
        animal.setAge(7);
        REQUIRE(animal.getAge() == 7);
    }

    SECTION("Zero age")
    {
        animal.setAge(0);
        REQUIRE(animal.getAge() == 0);
    }

    SECTION("Negative age")
    {
        REQUIRE_THROWS_AS(animal.setAge(-1), invalid_argument);
    }
}

TEST_CASE("Animal setWeight", "[animal]")
{
    Animal animal("Buddy", 5, 10.5);

    SECTION("Valid weight")
    {
        animal.setWeight(15.5);
        REQUIRE(animal.getWeight() == 15.5);
    }

    SECTION("Zero weight")
    {
        animal.setWeight(0);
        REQUIRE(animal.getWeight() == 0);
    }

    SECTION("Negative weight")
    {
        REQUIRE_THROWS_AS(animal.setWeight(-1.0), invalid_argument);
    }
}

TEST_CASE("Animal feed and sleep", "[animal]")
{
    Animal animal("Buddy", 5, 10.5);

    SECTION("Feed")
    {
        animal.sleep(); // Make hungry first
        REQUIRE(animal.getHungerStatus());
        animal.feed();
        REQUIRE_FALSE(animal.getHungerStatus());
    }

    SECTION("Sleep")
    {
        animal.feed(); // Make not hungry first
        REQUIRE_FALSE(animal.getHungerStatus());
        animal.sleep();
        REQUIRE(animal.getHungerStatus());
    }
}

TEST_CASE("Dog Constructor", "[dog]")
{
    SECTION("Valid parameters")
    {
        Dog dog("Rex", 3, 20.5, "Labrador");
        REQUIRE(dog.getName() == "Rex");
        REQUIRE(dog.getAge() == 3);
        REQUIRE(dog.getWeight() == 20.5);
        REQUIRE(dog.getBreed() == "Labrador");
    }

    SECTION("Invalid parameters")
    {
        REQUIRE_THROWS_AS(Dog("Rex", 3, 20.5, ""), invalid_argument);
    }
}

TEST_CASE("Dog setBreed", "[dog]")
{
    Dog dog("Rex", 3, 20.5, "Labrador");

    SECTION("Valid breed")
    {
        dog.setBreed("German Shepherd");
        REQUIRE(dog.getBreed() == "German Shepherd");
    }

    SECTION("Empty breed")
    {
        REQUIRE_THROWS_AS(dog.setBreed(""), invalid_argument);
    }
}

TEST_CASE("Dog behavior methods", "[dog]")
{
    Dog dog("Rex", 3, 20.5, "Labrador");

    SECTION("bark method")
    {
        // Redirect cout to test output
        stringstream output;
        auto old_buf = cout.rdbuf(output.rdbuf());

        dog.bark();
        REQUIRE(output.str() == "Woof!\n");

        cout.rdbuf(old_buf);
    }

    SECTION("wagTail method")
    {
        stringstream output;
        auto old_buf = cout.rdbuf(output.rdbuf());

        dog.wagTail();
        REQUIRE(output.str() == "Dog is wagging its tail!\n");

        cout.rdbuf(old_buf);
    }
}

TEST_CASE("Cat Constructor", "[cat]")
{
    SECTION("Valid parameters")
    {
        Cat cat("Whiskers", 2, 4.5, true);
        REQUIRE(cat.getName() == "Whiskers");
        REQUIRE(cat.getAge() == 2);
        REQUIRE(cat.getWeight() == 4.5);
        REQUIRE(cat.getIsIndoor());
        REQUIRE(cat.getLivesLeft() == 9);
    }
}

TEST_CASE("Cat behavior methods", "[cat]")
{
    Cat cat("Whiskers", 2, 4.5, true);

    SECTION("meow method")
    {
        stringstream output;
        auto old_buf = cout.rdbuf(output.rdbuf());

        cat.meow();
        REQUIRE(output.str() == "Meow!\n");

        cout.rdbuf(old_buf);
    }

    SECTION("purr method")
    {
        stringstream output;
        auto old_buf = cout.rdbuf(output.rdbuf());

        cat.purr();
        REQUIRE(output.str() == "Cat is purring...\n");

        cout.rdbuf(old_buf);
    }
}

TEST_CASE("Cat setIsIndoor", "[cat]")
{
    Cat cat("Whiskers", 2, 4.5, true);

    SECTION("Change to outdoor")
    {
        cat.setIsIndoor(false);
        REQUIRE_FALSE(cat.getIsIndoor());
    }

    SECTION("Change to indoor")
    {
        cat.setIsIndoor(true);
        REQUIRE(cat.getIsIndoor());
    }
}