/*
 *  Copyright (C) 2014 Simone Barbieri, Andrea Loddo, Emanuele Mameli, Alessandro Muntoni, Livio Pompianu
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 * 
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 * 
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef EVENT_H
#define EVENT_H

#include <QVector>
#include <QLinkedList>
#include <sstream>


/**
 * @brief The Event class
 *  Classe per modellare gli Event-Point nella costruzione del diagramma di Voronoi
 *  I suoi attributi sono:
 *      - client_id : contiene l'id del client al quale è associato l'evento, se è un site event.
 *                    Se è un circle event, contiene un id identificativo per il circle event.
 *      - x: coordinata x;
 *      - y: coordinata y;
 *      - deposit: contiene true se il client associato al site event è il deposito;
 *      - event: contiene true se è un site event, false se è un circle event
 *      - circle_events:
 *      - has_circle_event: DA USARE SOLAMENTE IN T:
 *          contiene true se all'arco in T è associato un circle event in Q
 *      - associate_circle_event: DA USARE SOLAMENTE IN T:
 *          contiene il puntatore in Q al cicle event associato all'ARCO in T.
 *      - associate_circle_event_id: DA USARE SOLAMENTE IN T:
 *          contiene l'id del circle event associato all'ARCO in T.
 *          tale arco scompare quando viene visitato il circle event associato (quindi,
 *          quando in Q troviamo un circle event, dobbiamo andare a cercare l'id del circle
 *          event in T (T[i].get_associate_circle_event_id()), in modo da identificare
 *          l'arco da eliminare).
 *      - position_in_Q:
 *          SE SITE EVENT: DA USARE SOLAMENTE IN T:
 *              contiene il puntatore alla posizione dell'evento nella coda Q
 *          SE CIRCLE EVENT: DA NON USARE
 *      - generators:
 *          SE SITE EVENT: DA NON USARE
 *          SE CIRCLE EVENT:
 *              da usare in Q: contiene i site event che hanno generato il circle event
 *      - overlying: vettore utilizzato nel caso in cui vi siano punti sovrapposti.
 */
class Event
{
public:
    Event();
    Event(int client_id, double x, double y, bool deposit, bool event);
    bool operator ==(Event &other) const;
    bool operator !=(Event &other) const;
    double get_x();
    double get_y();
    bool is_deposit();
    bool is_site_event();
    int get_client_id();
    bool has_associate_circle_event();
    QLinkedList<Event>::iterator get_associate_circle_event();
    int get_associate_circle_event_id();
    void set_associate_circle_event(QLinkedList<Event>::iterator it, int circle_event_id);
    void remove_associate_circle_event();
    void set_position_in_Q(QLinkedList<Event>::iterator it);
    void add_generator(Event e1);
    QVector<Event> get_generators();
    QVector<int> get_overlying();
    bool has_overlying();
    void add_overlying(int id);
    std::string to_string();

private:
    int client_id;
    double x;
    double y;
    bool deposit; //true: è il deposito
    bool event; //true: SiteEvent, false: CircleEvent
    bool has_circle_event; //true se all'arco è associato un circle event
    QLinkedList<Event>::iterator associate_circle_event;
    int associate_circle_event_id;
    QLinkedList<Event>::iterator position_in_Q;
    QVector<Event> generators;
    QVector<int> overlying;
};

#endif // EVENT_H
