#pragma once
#include <iostream>
#include <map>
#include "SearchEngine.h"
#include "CommandParser.h"
#include "EmployeeDB.h"

using namespace std;

class ICommand {
public:
    ICommand() : employeeDB(EmployeeDB::getDB()) {
    }
    virtual string runCmd(vector<string>& command) = 0;
    const int CMD_DISPLAY_RECORD = 1;
    const int MAX_DISPLAY_RECORD_SIZE = 5;
    string convertToString(vector<string> strList) {
        string result;
        for (const auto& str : strList) {
            result += str + "\n";
        }
        return result.substr(0, result.size() - 1);
    }
protected:
    SearchEngine searchEngine;
    EmployeeDB* employeeDB;
};

class AddCommand : public ICommand {
public:
    virtual string runCmd(vector<string>& command) override;

private:
    const int ADD_CMD_EMPLOYEENUM_INFO_IDX = 4;
    const int ADD_CMD_NAME_INFO_IDX = 5;
    const int ADD_CMD_LEVEL_INFO_IDX = 6;
    const int ADD_CMD_PHONENUM_INFO_IDX = 7;
    const int ADD_CMD_BIRTHDAY_INFO_IDX = 8;
    const int ADD_CMD_CERTI_INFO_IDX = 9;
};

class DeleteCommand : public ICommand {
public:
    virtual string runCmd(vector<string>& command) override;
};

class ModifyCommand : public ICommand {
public:
    virtual string runCmd(vector<string>& command) override;
};

class SearchCommand : public ICommand {
public:
    virtual string runCmd(vector<string>& command) override;
};