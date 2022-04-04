#include "pch.h"
#include "../deep_thinking/EmployeeInfo.h"

TEST(EmployeeInfoTest, getInfoTest) {
    const string info[6] = { "22040189","DEEP Park", "CL1", "010-2134-5678", "20001010", "EX" };

    EmployeeInfo test{ info[0], info[1], info[2], info[3], info[4], info[5] };
    EXPECT_EQ(test.getEmployeeNum(), info[0]);
    EXPECT_EQ(test.getName(), info[1]);
    EXPECT_EQ(test.getLevel(), info[2]);
    EXPECT_EQ(test.getPhoneNum(), info[3]);
    EXPECT_EQ(test.getBirthDate(), info[4]);
    EXPECT_EQ(test.getCerti(), info[5]);

    cout << test << endl;
}

TEST(EmployeeInfoTest, operatorEqualTest) {
    const string info[6] = { "22040189","DEEP Park", "CL3", "010-2134-5678", "20001010", "ADV" };
    EmployeeInfo test{ info[0], info[1], info[2], info[3], info[4], info[5] };

    // Copy
    EmployeeInfo testCopy{};
    testCopy = test;

    // == operator overloading
    EXPECT_EQ(test, testCopy);
}

TEST(EmployeeInfoTest, operatorNotEqualTest) {
    const string info[6] = { "18040189","DEEP Park", "CL3", "010-1221-55555", "20001010", "ADV" };
    EmployeeInfo test{ info[0], info[1], info[2], info[3], info[4], info[5] };

    // != operator overloading
    EmployeeInfo testCompare1{ "10040189", info[1], info[2], info[3], info[4], info[5] };
    cout << testCompare1;
    EXPECT_NE(testCompare1, test);

    EmployeeInfo testCompare2{ info[0], "Jin Park", info[2], info[3], info[4], info[5] };
    cout << testCompare2;
    EXPECT_NE(testCompare1, testCompare2);

    EmployeeInfo testCompare3{ info[0], info[1], "CL2", info[3], info[4], info[5] };
    cout << testCompare3;
    EXPECT_NE(testCompare2, testCompare3);

    EmployeeInfo testCompare4{ info[0], info[1], info[2], "010-7777-8888", info[4], info[5] };
    cout << testCompare4;
    EXPECT_NE(testCompare3, testCompare4);

    EmployeeInfo testCompare5{ info[0], info[1], info[2], info[3], "19981010", info[5] };
    cout << testCompare5;
    EXPECT_NE(testCompare4, testCompare5);

    EmployeeInfo testCompare6{ info[0], info[1], info[2], info[3], info[4], "PRO" };
    cout << testCompare6;
    EXPECT_NE(testCompare5, testCompare6);
}

TEST(EmployeeInfoTest, getNameFullTest) {
    EmployeeInfo test = { "18040189","San LEE", "CL3", "010-1221-55555", "19981010", "ADV" };
    EXPECT_EQ(test.getName(), "San LEE");
    EXPECT_EQ(test.getFirstName(), "San");
    EXPECT_EQ(test.getLastName(), "LEE");
}

TEST(EmployeeInfoTest, getBirthdayFullTest) {
    EmployeeInfo test = { "18040189","San LEE", "CL3", "010-1221-55555", "19891210", "ADV" };
    EXPECT_EQ(test.getBirthDate(), "19891210");
    EXPECT_EQ(test.getBirthYear(), "1989");
    EXPECT_EQ(test.getBirthMonth(), "12");
    EXPECT_EQ(test.getBirthDay(), "10");


    EmployeeInfo emptyDateTest = { "18040189","San LEE", "CL3", "010-1221-55555", "1210", "ADV" };
    EXPECT_EQ(emptyDateTest.getBirthDate(), "");
    EXPECT_EQ(emptyDateTest.getBirthYear(), "");
    EXPECT_EQ(emptyDateTest.getBirthMonth(), "");
    EXPECT_EQ(emptyDateTest.getBirthDay(), "");
}

