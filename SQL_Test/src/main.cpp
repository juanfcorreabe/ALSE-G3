#include <iostream>
#include <mysql/mysql.h>

int main() {
    MYSQL* conn;
    conn = mysql_init(nullptr);

    if (conn == nullptr) {
        std::cerr << "Error al crear el objeto de conexión\n";
        return 1;
    }

    // Conectar a la base de datos
    if (!mysql_real_connect(conn, "localhost", "usuario", "contraseña",
                            "sistema_pedidos", 0, nullptr, 0)) {
        std::cerr << "Fallo de conexión: " << mysql_error(conn) << "\n";
        return 1;
    }

    std::cout << "Conexión exitosa a sistema_pedidos\n";

    // Realizar una consulta
    const char* consulta = "SELECT clientes.nombre, pedidos.fecha "
                           "FROM clientes JOIN pedidos ON clientes.id_cliente = pedidos.id_cliente";

    if (mysql_query(conn, consulta) == 0) {
        MYSQL_RES* res = mysql_store_result(conn);
        MYSQL_ROW row;
        while ((row = mysql_fetch_row(res))) {
            std::cout << "Cliente: " << row[0] << " | Fecha del pedido: " << row[1] << "\n";
        }
        mysql_free_result(res);
    } else {
        std::cerr << "Error en la consulta: " << mysql_error(conn) << "\n";
    }

    mysql_close(conn);
    return 0;
}
