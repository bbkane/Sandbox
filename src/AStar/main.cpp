#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
#include <set>
#include <memory>
#include <utility>
#include <type_traits>
#include <algorithm>

template <
    typename IdType,
    typename DataType,
    typename CostType=int
>
struct Graph
{
    static_assert(std::is_arithmetic<CostType>::value, "CostType must be numeric");
    struct Connection
    {
        IdType first;
        IdType second;

        // for Dijkstra and A*
        CostType cost_between{ 0 };

        // for A*
        CostType heuristic_to_goal{ 0 };

        CostType total_cost{ 0 };

        // for Dijkstra and A*
        bool traversed{ false };

        Connection(IdType first, IdType second, CostType cost_to_second=0)
            : first(first), second(second), cost_between(cost_to_second)
        {}

        friend std::ostream &operator<<(std::ostream &os, const Connection& c)
        {
            return os << c.first << " -> " << c.second << " cost between: " << c.cost_between << " total: " << c.total_cost;
        }
    };

    // This will 'own' all the data on the heap. the connections are 'views' onto this
    std::unordered_map<IdType, std::unique_ptr<DataType>> nodes;

    void add_node(IdType id, DataType && data)
    {
        nodes[id] = std::make_unique<DataType>(data);
    }

    void add_one_way(IdType first, IdType second, CostType cost=0)
    {
        connections.push_back(Connection(first, second, cost));
    }

    void add_two_way(IdType first, IdType second, CostType first_to_second=0, CostType second_to_first=0)
    {
        connections.push_back(Connection(first, second, first_to_second));
        connections.push_back(Connection(second, first, second_to_first));
    }

    // Checks to see if all connections name nodes in the graph
    bool has_valid_connections()
    {
        for (const auto& connection : connections)
        {
            if (!nodes.count(connection.first))
            {
                std::cerr << connection.first << " not in nodes!" << std::endl;
                return false;
            }
            if (!nodes.count(connection.second))
            {
                std::cerr << connection.second << " not in nodes!" << std::endl;
                return false;
            }
        }
        return true;
    }

    std::vector<Connection> connections;

    // Function(const IdType&, data*)
    template <typename Function>
    void traverse(IdType root_id, Function fun)
    {
        std::queue<IdType> frontier;
        std::set<IdType> closed;

        frontier.push(root_id);

        while (!frontier.empty())
        {
            IdType current_id = frontier.front();

            // if it's not in closed
            if (closed.find(current_id) == closed.end())
            {
                //TODO: check for empty values!
                DataType* current_data = nodes.at(current_id).get();
                fun(current_id, current_data);

                closed.insert(current_id);

                // add children to frontier
                for (auto connection : connections)
                {
                    if (connection.first == current_id)
                    {
                        frontier.push(connection.second);
                    }
                }
            }

            frontier.pop();
        }
    }

    void traverse_dijkstra(IdType start_id, IdType end_id)
    {
        //TODO: replace with a real queue
        std::vector<Connection> connection_queue;

       // add neighbors to the queue
        for (auto connection : connections)
        {
            if (connection.first == start_id 
                && connection.traversed == false)
            {
                connection.total_cost = 0 + connection.cost_between;
                connection_queue.push_back(connection);
            }
        }

        //get a reference to the smallest connection
        auto& cheapest_connection = connection_queue.front();
        for (auto& connection : connection_queue)
        {
            if (connection.total_cost < cheapest_connection.total_cost)
            {
                cheapest_connection = connection;
            }
        }

        cheapest_connection.traversed = true;

        for (auto connection : connections)
        {
            if (connection.first == cheapest_connection.second
                && connection.traversed == false)
            {
                connection.total_cost = cheapest_connection.total_cost + connection.cost_between;
                connection_queue.push_back(connection);
            }
        }

        // print it
        // set its traversed to true
        // loop the Dijkstra!
    }

    void print(IdType start_id)
    {
        traverse(start_id, [](IdType id, DataType* i) { std::cout << id << " " << *i << std::endl; });

    }
};

int main()
{
    Graph<char, int> graph;
    graph.add_node('a', 1);
    graph.add_node('b', 2);
    graph.add_node('c', 3);
    graph.add_node('d', 4);

    graph.add_one_way('a', 'b');
    graph.add_two_way('b', 'c');
    graph.add_two_way('a', 'd');

    graph.has_valid_connections();

    graph.print('a');

    graph.traverse_dijkstra('a', 'd');

    //for God's sake, don't delete a!
    auto a = graph.nodes.at('a').get();
    *a = 4;
    std::cout << *a << std::endl;
}
