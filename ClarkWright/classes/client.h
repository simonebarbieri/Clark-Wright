#ifndef CLIENT_H
#define CLIENT_H

#include <math.h>
#include <QString>
#include <sstream>
#include <QPoint>
#include <QPair>
#include <QList>

typedef int client_id; //tipo utilizzato per indicare l'id di un cliente;
typedef int route_id; //tipo utilizzato per indicare l'id di una route;
typedef int index_client; //tipo utilizzato per indicare l'indice di posizione di un cliente in una route;

/**
 * @brief The Client class
 *  Modella il cliente, ossia un nodo nel grafo, appartenente ad una route.
 *  Ossia, non modella solamente attributi propri del cliente, ma mantiene anche informazioni relative
 *  alla route a cui appartiene il cliente stesso.
 *  è composta dagli attributi:
 *      - id                : identifica univocamente un nodo del grafo. Il nodo 0 è trattato dai metodi
 *                            come il nodo deposito;
 *      - x                 : coordinata x del nodo sul piano;
 *      - y                 : coordinata y del nodo sul piano;
 *      - demand            : quantità di merce richiesta da parte del cliente;
 *      - rid               : identifica la route a cui appartiene al cliente;
 *      - position_in_route : posizione del cliente nella route a cui appartiene;
 *      - alone             : indica se è l'unico nodo presente nella route, oltre il deposito (0).
 */
class Client
{
public:
    Client();
    Client(client_id id, int x, int y, int demand);
    void set_id(client_id id);
    client_id get_id();
    void set_coordinates(int x, int y);
    int get_x();
    int get_y();
    int get_demand();
    route_id get_route();
    void set_demand(int demand);
    double get_distance(Client c);
    void set_route(route_id rid);
    index_client get_position_in_route();
    void set_position_in_route(index_client position);
    bool is_alone();
    void set_alone(bool a);
    std::string to_string();
    QPair<QPoint, QString> to_point_label_pair();
    QPoint to_QPoint();

private:
    client_id id;
    int x;
    int y;
    int demand;
    route_id rid;
    index_client position_in_route;
    bool alone;
};

#endif // CLIENT_H
