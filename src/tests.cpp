#include <gtest/gtest.h>
#include "database.hpp"
#include "student.hpp"

struct DatabaseTest : ::testing::Test
{
    Database db;
};

TEST_F(DatabaseTest, DisplayEmptyDb)
{
    auto content = db.show();
    auto expected = "";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, DisplayNonEmptyDb)
{
    Student adam{
        "Adam",
        "Kowalski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "11223344567",
        Gender::Male};
    db.add(adam);
    // check adding same person twice

    auto content = db.show();
    auto expected = "Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 11223344567; Male";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, DisplayAfterSearchLastName)
{
    Student adam{
        "Adam",
        "Kowalski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "11223344567",
        Gender::Male};
    db.add(adam);

    auto content = db.searchLastName("Kowalski");
    auto expected = "Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 11223344567; Male";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, DisplayAfterSearchPesel)
{
    Student adam{
        "Adam",
        "Kowalski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "11223344567",
        Gender::Male};
    db.add(adam);

    auto content = db.searchPesel("11223344567");
    auto expected = "Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 11223344567; Male";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, SortDatabaseByPesel)
{
    Student adam{
        "Adam",
        "Kowalski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "11223344567",
        Gender::Male};
    db.add(adam);

    Student kaja{
        "Kaja",
        "Sypko",
        "ul. Niedobra 22, 10-999 Milicz",
        654321,
        "99004433228",
        Gender::Female};
    db.add(kaja);

    Student damian{
        "Damian",
        "Matysniak",
        "ul. Twoja 1, 68-321 Stara",
        745130,
        "76889900116",
        Gender::Male};
    db.add(damian);

    db.sortByPesel();

    auto content = db.show();
    auto expected = "Kaja Sypko; ul. Niedobra 22, 10-999 Milicz; 654321; 99004433228; MaleDamian Matysniak; ul. Twoja 1, 68-321 Stara; 745130; 76889900116; MaleAdam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 11223344567; Male";
    EXPECT_EQ(content, expected);
}