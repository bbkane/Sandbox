#include <iostream>
#include <vector>
#include <algorithm>

struct Connection
{
    char first;
    char second;
    int cost_between;

    Connection(char first, char second, int cost)
        : first(first), second(second), cost_between(cost)
    {}

    friend std::ostream& operator<<(std::ostream &os, const Connection &c)
    {
        os << c.first << " " << c.second << " " << c.cost_between;
        return os;
    }
};

enum class CurrentList
{
    Frontier,
    Closed
};

struct DijkstraConnection
{
    Connection connection;
    CurrentList currentlist{ CurrentList::Frontier };
    int total_cost{ 0 };
    DijkstraConnection(Connection connection) :
        connection(connection)
    {}
};

int main()
{
    std::vector<Connection> connections{
        Connection('a', 'b', 1),
        Connection('a', 'c', 2),
        Connection('c', 'd', 2)
    };

    for (auto c : connections)
    {
        std::cout << c << std::endl;
    }

    std::cout << "Starting Dijkstra" << std::endl;

    std::vector<DijkstraConnection> frontier;

    char start_id = 'a';
    char end_id = 'd';

    if (start_id == end_id)
    {
        std::cout << "it worked!" << std::endl;
        return 0;
    }

    for (auto connection_it = connections.begin(); connection_it != connections.end(); )
    {
        if (connection_it->first == start_id)
        {
            DijkstraConnection d = DijkstraConnection(*connection_it);
            d.total_cost = 0 + d.connection.cost_between;
            frontier.push_back(d);
            connection_it = connections.erase(connection_it);
        }
        else
        {
            ++connection_it;
        }
    }

    for (auto connection : connections) {
        if (connection.first == start_id)
        {
            DijkstraConnection d = DijkstraConnection(connection);
            d.total_cost = 0 + d.connection.cost_between;
            frontier.push_back(d);
        }
    }

    while (true)
    {
        std::vector<DijkstraConnection>::iterator min = std::min_element(frontier.begin(), frontier.end(),
            [](DijkstraConnection a, DijkstraConnection b) { return a.total_cost < b.total_cost; });
        if (min->connection.second == end_id)
        {
            std::cout << "reached it!" << std::endl;
            std::cout << min->connection << std::endl;
            return 0;
        }

        std::cout << min->connection << std::endl;

        for (auto connection_it = connections.begin(); connection_it != connections.end(); )
        {
            if (connection_it->first == min->connection.second)
            {
                DijkstraConnection d = DijkstraConnection(*connection_it);
                d.total_cost = min->total_cost + d.connection.cost_between;
                frontier.push_back(d);
                connection_it = connections.erase(connection_it);
            }
            else
            {
                ++connection_it;
            }
        }

        frontier.erase(min);
    }

}