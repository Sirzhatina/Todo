#pragma once

#include <string>

struct Task {
    std::string name;
    std::string description;

    bool isComplete{false};
};