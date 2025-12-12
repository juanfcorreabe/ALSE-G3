#pragma once
#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

struct Component {
    int id;
    std::string name;
    std::string type;
    int quantity;
    std::string location;
    std::string date;

    // Constructor simple
    Component() : id(0), quantity(0) {}
};

#endif