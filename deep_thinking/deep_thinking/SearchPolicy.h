#pragma once

#include <string>
#include <vector>
#include <map>
#include <functional>
#include "EmployeeDB.h"

using namespace std;

class Search {
public:
    const int SEARCH_KEY_IDX = 5;
    const int SEARCH_OPTION_KEY_IDX = 2;
    const string SEARCH_BIRTH_DAY_STR{ "-d" };
    const string SEARCH_BIRTH_MONTH_STR{ "-m" };
    const string SEARCH_BIRTH_YEAR_STR{ "-y" };
    const string SEARCH_PHONENUMBER_MID_STR{ "-m" };
    const string SEARCH_PHONENUMBER_LAST_STR{ "-l" };
    const string SEARCH_NAME_FIRST{ "-f" };
    const string SEARCH_NAME_LAST{ "-l" };


    vector<string> search_base(const map<string, EmployeeInfo>& employeeDict, function<bool(EmployeeInfo)> isMatched) {
        vector<string> result;

        for (const auto& [key, eInfo] : employeeDict) {
            if (isMatched(eInfo)) {
                result.emplace_back(key);
            }
        }

        return result;
    }
    virtual vector<string> search(const map<string, EmployeeInfo>& employeeInfo, const vector<string>& parsedCmds) = 0;
};

class SearhById : public Search {
private:
    virtual vector<string> search(const map<string, EmployeeInfo>& employeeInfo, const vector<string>& parsedCmds)  override {
        string key = parsedCmds[SEARCH_KEY_IDX];
        auto isMatched = [&key](const EmployeeInfo& employA)  -> bool {
            return employA.getEmployeeNum() == key; };
        return search_base(employeeInfo, isMatched);
    };
};

class SearhByName : public Search {
private:
    virtual vector<string> search(const map<string, EmployeeInfo>& employeeInfo, const vector<string>& parsedCmds)  override {
        string key = parsedCmds[SEARCH_KEY_IDX];
        if (parsedCmds[SEARCH_OPTION_KEY_IDX] == SEARCH_NAME_FIRST) {
            return search_base(employeeInfo, [&key](const EmployeeInfo& employA)  -> bool {
                return employA.getFirstName() == key; });
        }
        else if (parsedCmds[SEARCH_OPTION_KEY_IDX] == SEARCH_NAME_LAST) {
            return search_base(employeeInfo, [&key](const EmployeeInfo& employA)  -> bool {
                return employA.getLastName() == key; });
        }
        else {
            auto isMatched = [&key](const EmployeeInfo& employA)  -> bool {
                return employA.getName() == key; };
            return search_base(employeeInfo, isMatched);
        }
    };
};

class SearhByPhoneNumber : public Search {
private:
    virtual vector<string> search(const map<string, EmployeeInfo>& employeeInfo, const vector<string>& parsedCmds)  override {
        string key = parsedCmds[SEARCH_KEY_IDX];
        if (parsedCmds[SEARCH_OPTION_KEY_IDX] == SEARCH_PHONENUMBER_MID_STR) {
            return search_base(employeeInfo, [&key](const EmployeeInfo& employA)  -> bool {
                return employA.getPhoneMidNum() == key; });
        }
        else if (parsedCmds[SEARCH_OPTION_KEY_IDX] == SEARCH_PHONENUMBER_LAST_STR) {
            return search_base(employeeInfo, [&key](const EmployeeInfo& employA)  -> bool {
                return employA.getPhoneLastNum() == key; });
        }
        else {
            return search_base(employeeInfo, [&key](const EmployeeInfo& employA)  -> bool {
                return employA.getPhoneNum() == key; });
        }
    };;
};

class SearhByBirth : public Search {
private:
    virtual vector<string> search(const map<string, EmployeeInfo>& employeeInfo, const vector<string>& parsedCmds)  override {
        string key = parsedCmds[SEARCH_KEY_IDX];
        if (parsedCmds[SEARCH_OPTION_KEY_IDX] == SEARCH_BIRTH_DAY_STR) {
            return search_base(employeeInfo, [&key](const EmployeeInfo& employA)  -> bool {
                return employA.getBirthDay() == key; });
        }
        else if (parsedCmds[SEARCH_OPTION_KEY_IDX] == SEARCH_BIRTH_MONTH_STR) {
            return search_base(employeeInfo, [&key](const EmployeeInfo& employA)  -> bool {
                return employA.getBirthMonth() == key; });
        }
        else if (parsedCmds[SEARCH_OPTION_KEY_IDX] == SEARCH_BIRTH_YEAR_STR) {
            return search_base(employeeInfo, [&key](const EmployeeInfo& employA)  -> bool {
                return employA.getBirthYear() == key; });
        }
        else {
            return search_base(employeeInfo, [&key](const EmployeeInfo& employA)  -> bool {
                return employA.getBirthDate() == key; });
        }
    };
};

class SearhByCerti : public Search {
private:
    virtual vector<string> search(const map<string, EmployeeInfo>& employeeInfo, const vector<string>& parsedCmds)  override {
        string key = parsedCmds[SEARCH_KEY_IDX];
        return search_base(employeeInfo, [&key](const EmployeeInfo& employA)  -> bool {
            return employA.getCerti() == key; });
    };
};

class SearhByCL : public Search {
private:
    virtual vector<string> search(const map<string, EmployeeInfo>& employeeInfo, const vector<string>& parsedCmds)  override {
        string key = parsedCmds[SEARCH_KEY_IDX];
        return search_base(employeeInfo, [&key](const EmployeeInfo& employA)  -> bool {
            return employA.getLevel() == key; });
    };
};