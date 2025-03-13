#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch2.hpp"
#include "../string.cpp"

TEST_CASE("Default Constructor", "[string]")
{
    String s;
    REQUIRE(s.length() == 0);
    REQUIRE(strcmp(s.toCString(), "") == 0);
}

TEST_CASE("C-string Constructor", "[string]")
{
    SECTION("Normal string")
    {
        String s("hello");
        REQUIRE(s.length() == 5);
        REQUIRE(strcmp(s.toCString(), "hello") == 0);
    }

    SECTION("Empty string")
    {
        String s("");
        REQUIRE(s.length() == 0);
        REQUIRE(strcmp(s.toCString(), "") == 0);
    }

    SECTION("Single character")
    {
        String s("a");
        REQUIRE(s.length() == 1);
        REQUIRE(strcmp(s.toCString(), "a") == 0);
    }
}

TEST_CASE("Copy constructor functionality", "[String]")
{
    SECTION("Copy empty string")
    {
        String empty;
        String copy(empty);
        REQUIRE(copy.length() == 0);
        REQUIRE(copy.toCString()[0] == '\0');
    }

    SECTION("Copy non-empty string")
    {
        String original("test");
        String copy(original);
        REQUIRE(copy.length() == 4);
        REQUIRE(strcmp(copy.toCString(), "test") == 0);
        REQUIRE(copy.toCString() != original.toCString()); // Different memory addresses
    }
}

TEST_CASE("Assignment operator functionality", "[String]")
{
    SECTION("Assign to empty string")
    {
        String source("hello");
        String dest;
        dest = source;
        REQUIRE(strcmp(dest.toCString(), "hello") == 0);
    }

    SECTION("Assign to non-empty string")
    {
        String source("world");
        String dest("hello");
        dest = source;
        REQUIRE(strcmp(dest.toCString(), "world") == 0);
    }

    SECTION("Self assignment")
    {
        String str("test");
        str = str;
        REQUIRE(strcmp(str.toCString(), "test") == 0);
    }
}

TEST_CASE("Insert method functionality", "[String]")
{
    SECTION("Insert at beginning")
    {
        String str("hello");
        str.insert(0, 'H');
        REQUIRE(strcmp(str.toCString(), "Hhello") == 0);
    }

    SECTION("Insert in middle")
    {
        String str("hello");
        str.insert(2, '-');
        REQUIRE(strcmp(str.toCString(), "he-llo") == 0);
    }

    SECTION("Insert at end")
    {
        String str("hello");
        str.insert(5, '!');
        REQUIRE(strcmp(str.toCString(), "hello!") == 0);
    }

    SECTION("Insert at invalid position")
    {
        String str("hello");
        str.insert(10, 'x');
        REQUIRE(strcmp(str.toCString(), "hello") == 0);
    }
}

TEST_CASE("Replace method functionality", "[String]")
{
    SECTION("Replace first character")
    {
        String str("hello");
        str.replace(0, 'H');
        REQUIRE(strcmp(str.toCString(), "Hello") == 0);
    }

    SECTION("Replace middle character")
    {
        String str("hello");
        str.replace(2, 'L');
        REQUIRE(strcmp(str.toCString(), "heLlo") == 0);
    }

    SECTION("Replace last character")
    {
        String str("hello");
        str.replace(4, 'O');
        REQUIRE(strcmp(str.toCString(), "hellO") == 0);
    }

    SECTION("Replace at invalid position")
    {
        String str("hello");
        str.replace(10, 'x');
        REQUIRE(strcmp(str.toCString(), "hello") == 0);
    }
}

TEST_CASE("FindFirstOf method functionality", "[String]")
{
    SECTION("Find character at beginning")
    {
        String str("hello");
        REQUIRE(str.findFirstOf('h') == 0);
    }

    SECTION("Find character in middle")
    {
        String str("hello");
        REQUIRE(str.findFirstOf('l') == 2);
    }

    SECTION("Find character at end")
    {
        String str("hello");
        REQUIRE(str.findFirstOf('o') == 4);
    }

    SECTION("Find non-existent character")
    {
        String str("hello");
        REQUIRE(str.findFirstOf('x') == -1);
    }

    SECTION("Find in empty string")
    {
        String str;
        REQUIRE(str.findFirstOf('a') == -1);
    }
}

TEST_CASE("append() Method", "[string]")
{
    SECTION("Append to empty string")
    {
        String s;
        s.append('a');
        REQUIRE(s.length() == 1);
        REQUIRE(strcmp(s.toCString(), "a") == 0);
    }

    SECTION("Append to non-empty string")
    {
        String s("hello");
        s.append('!');
        REQUIRE(s.length() == 6);
        REQUIRE(strcmp(s.toCString(), "hello!") == 0);
    }

    SECTION("Append null character")
    {
        String s("test");
        s.append('\0');
        REQUIRE(s.length() == 5);
        REQUIRE(strcmp(s.toCString(), "test") == 0);
    }
}

TEST_CASE("concat() Method", "[string]")
{
    SECTION("Concat to empty string")
    {
        String s;
        s.concat("hello");
        REQUIRE(s.length() == 5);
        REQUIRE(strcmp(s.toCString(), "hello") == 0);
    }

    SECTION("Concat empty string")
    {
        String s("hello");
        s.concat("");
        REQUIRE(s.length() == 5);
        REQUIRE(strcmp(s.toCString(), "hello") == 0);
    }

    SECTION("Concat two non-empty strings")
    {
        String s("hello");
        s.concat(" world");
        REQUIRE(s.length() == 11);
        REQUIRE(strcmp(s.toCString(), "hello world") == 0);
    }
}

TEST_CASE("compare() Method", "[string]")
{
    SECTION("Equal strings")
    {
        String s1("hello");
        String s2("hello");
        REQUIRE(s1.compare(s2) == 0);
    }

    SECTION("Empty strings")
    {
        String s1;
        String s2;
        REQUIRE(s1.compare(s2) == 0);
    }

    SECTION("Different length strings")
    {
        String s1("hello");
        String s2("hello world");
        REQUIRE(s1.compare(s2) == -1);
        REQUIRE(s2.compare(s1) == 1);
    }

    SECTION("Different content, same length")
    {
        String s1("hello");
        String s2("world");
        REQUIRE(s1.compare(s2) == -1);
        REQUIRE(s2.compare(s1) == 1);
    }

    SECTION("Prefix strings")
    {
        String s1("hell");
        String s2("hello");
        REQUIRE(s1.compare(s2) == -1);
        REQUIRE(s2.compare(s1) == 1);
    }

    SECTION("Different characters")
    {
        String s1("abc");
        String s2("abd");
        REQUIRE(s1.compare(s2) == -1);
        REQUIRE(s2.compare(s1) == 1);
    }
}