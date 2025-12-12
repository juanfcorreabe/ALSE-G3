#include <QApplication>
#include "include/inventory.h"
#include "include/database.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    InventoryManager window;
    window.show();
    return app.exec();
}