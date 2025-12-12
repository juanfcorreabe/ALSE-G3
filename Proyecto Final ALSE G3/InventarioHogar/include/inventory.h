#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H

#include <QMainWindow>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>

class InventoryManager : public QMainWindow {
    Q_OBJECT

public:
    InventoryManager(QWidget *parent = nullptr);
    ~InventoryManager();

private slots:
    void addItem();
    void refreshTable();

private:
    QTableWidget *table;
    QLineEdit *nameInput, *typeInput, *qtyInput, *locInput, *dateInput;
    QLineEdit *searchInput;
    QPushButton *addButton;
};

#endif