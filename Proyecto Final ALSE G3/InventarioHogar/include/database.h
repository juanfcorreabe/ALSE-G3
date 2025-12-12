#pragma once
#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include "component.h"

class DatabaseManager {
public:
    DatabaseManager();
    ~DatabaseManager();

    bool addComponent(const Component& c);
    std::vector<Component> getAllComponents();
    bool updateQuantity(int id, int newQty);
};

#endif