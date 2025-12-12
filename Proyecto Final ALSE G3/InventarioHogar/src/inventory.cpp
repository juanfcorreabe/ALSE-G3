#include "../include/inventory.h"
#include "../include/database.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>

InventoryManager::InventoryManager(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Inventario Hogar/Laboratorio");
    resize(900, 600);

    QWidget *central = new QWidget(this);
    setCentralWidget(central);
    QVBoxLayout *layout = new QVBoxLayout(central);

    // Búsqueda
    searchInput = new QLineEdit(this);
    searchInput->setPlaceholderText("Buscar por nombre...");
    layout->addWidget(searchInput);

    // Tabla
    table = new QTableWidget(this);
    table->setColumnCount(6);
    table->setHorizontalHeaderLabels({"ID", "Nombre", "Tipo", "Cantidad", "Ubicación", "Fecha"});
    layout->addWidget(table);

    // Formulario
    QHBoxLayout *form = new QHBoxLayout();
    nameInput = new QLineEdit(this); nameInput->setPlaceholderText("Nombre");
    typeInput = new QLineEdit(this); typeInput->setPlaceholderText("Tipo (ej: LED)");
    qtyInput = new QLineEdit(this); qtyInput->setPlaceholderText("Cantidad");
    locInput = new QLineEdit(this); locInput->setPlaceholderText("Ubicación");
    dateInput = new QLineEdit(this); dateInput->setPlaceholderText("Fecha (ej: 2025-04-05)");

    addButton = new QPushButton("Agregar", this);

    form->addWidget(new QLabel("Nombre:")); form->addWidget(nameInput);
    form->addWidget(new QLabel("Tipo:")); form->addWidget(typeInput);
    form->addWidget(new QLabel("Cant:")); form->addWidget(qtyInput);
    form->addWidget(new QLabel("Lugar:")); form->addWidget(locInput);
    form->addWidget(new QLabel("Fecha:")); form->addWidget(dateInput);
    form->addWidget(addButton);
    layout->addLayout(form);

    connect(addButton, &QPushButton::clicked, this, &InventoryManager::addItem);
    connect(searchInput, &QLineEdit::textChanged, this, &InventoryManager::refreshTable);

    refreshTable(); // Cargar datos al inicio
}

void InventoryManager::addItem() {
    Component c;
    c.name = nameInput->text().toStdString();
    c.type = typeInput->text().toStdString();
    c.quantity = qtyInput->text().toInt();
    c.location = locInput->text().toStdString();
    c.date = dateInput->text().toStdString();

    DatabaseManager db;
    if (db.addComponent(c)) {
        QMessageBox::information(this, "Éxito", "Artículo agregado");
        nameInput->clear(); typeInput->clear(); qtyInput->clear();
        locInput->clear(); dateInput->clear();
        refreshTable();
    } else {
        QMessageBox::warning(this, "Error", "No se pudo guardar");
    }
}

void InventoryManager::refreshTable() {
    DatabaseManager db;
    auto items = db.getAllComponents();

    table->setRowCount(0);
    for (const auto& c : items) {
        std::string name = c.name;
        if (!searchInput->text().isEmpty()) {
            if (name.find(searchInput->text().toStdString()) == std::string::npos)
                continue;
        }

        int row = table->rowCount();
        table->insertRow(row);
        table->setItem(row, 0, new QTableWidgetItem(QString::number(c.id)));
        table->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(c.name)));
        table->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(c.type)));
        table->setItem(row, 3, new QTableWidgetItem(QString::number(c.quantity)));
        table->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(c.location)));
        table->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(c.date)));

        // Alerta de stock bajo
        if (c.quantity < 5) {
            for (int i = 0; i < 6; ++i)
                table->item(row, i)->setBackground(Qt::yellow);
        }
    }
}

InventoryManager::~InventoryManager() {}
