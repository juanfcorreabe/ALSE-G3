#include "../include/database.h"
#include <sqlite3.h>
#include <iostream>

static sqlite3* db;

DatabaseManager::DatabaseManager() {
    if (sqlite3_open("inventario.db", &db)) {
        std::cout << "Error abriendo base de datos\n";
    } else {
        const char* sql = 
            "CREATE TABLE IF NOT EXISTS components("
            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "name TEXT, type TEXT, quantity INTEGER, "
            "location TEXT, date TEXT);";
        sqlite3_exec(db, sql, nullptr, 0, nullptr);
    }
}

DatabaseManager::~DatabaseManager() {
    sqlite3_close(db);
}

bool DatabaseManager::addComponent(const Component& c) {
    std::string sql = "INSERT INTO components (name,type,quantity,location,date) VALUES ('"
        + c.name + "','" + c.type + "'," + std::to_string(c.quantity) + ",'"
        + c.location + "','" + c.date + "');";

    return sqlite3_exec(db, sql.c_str(), nullptr, 0, nullptr) == SQLITE_OK;
}

std::vector<Component> DatabaseManager::getAllComponents() {
    std::vector<Component> list;
    const char* sql = "SELECT * FROM components;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            Component c;
            c.id = sqlite3_column_int(stmt, 0);
            c.name = (const char*)sqlite3_column_text(stmt, 1);
            c.type = (const char*)sqlite3_column_text(stmt, 2);
            c.quantity = sqlite3_column_int(stmt, 3);
            c.location = (const char*)sqlite3_column_text(stmt, 4);
            c.date = (const char*)sqlite3_column_text(stmt, 5);
            list.push_back(c);
        }
    }
    sqlite3_finalize(stmt);
    return list;
}