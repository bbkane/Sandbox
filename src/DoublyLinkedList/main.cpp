#include <iostream>
#include <memory>

template<typename T>
class DoublyLinkedList
{
    struct Node
    {
        Node(T data): data(data) {}
        T data;
        Node* prev{nullptr};
        Node* next{ nullptr };
    };

public:

    Node* first{ nullptr };
    Node* last{ nullptr };

    ~DoublyLinkedList()
    {
        while( !empty() )
        {
            Node* node = pop_front();
            delete node;
        }
    }

    bool empty() { return first == nullptr && last == nullptr; }

    void push_back(T data)
    {
        if(empty())
        {
            first = new Node(data);
            last = first;
        }
        else
        {
            Node* node = new Node(data);
            last->next = node;
            node->prev = last;
            last = node;
        }
    }

    template<typename First, typename... Rest>
    void push_back(First first, Rest... rest)
    {
        push_back(first);
        push_back(rest...);
    }

    Node* pop_front()
    {
        Node* front = first;
        if( first == last )
        {
            first = nullptr;
            last = nullptr;
        }
        else
        {
            first = first->next;
        }

        return front;
    }
    Node* pop_back()
    {
        Node* back = last;
        if( first == last )
        {
            first = nullptr;
            last = nullptr;
        }
        else
        {
            last = last->prev;
        }
        return back;
    }
    void print()
    {
        if( !empty() )
        {
            for(Node* node = first; node != last; node = node->next)
            {
                std::cout << node->data << ' ';// std::endl;
            }
            std::cout << last->data << std::endl;
        }
        else
        {
            std::cout << "empty" << std::endl;
        }
    }

    template<typename Fn>
    void map( Fn fn )
    {
        if( !empty() )
        {
            for(Node* node = first; node != last; node = node->next)
            {
                fn(node->data);
            }
            fn(last->data);
        }
    }
};

template<typename T>
struct Tree
{
    T data;
    DoublyLinkedList<Tree<T>> children;

    Tree(T data) : data(data) {}

    void print(Tree& tree)
    {
        std::cout << tree.data << ' ';
        children.map(&Tree<T>::print);
    }
};

int main()
{
    std::cout << "hi" << std::endl;
    DoublyLinkedList<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4,5,6);
    l.print();
    l.map( []( int& data ){ data++; } );
    l.print();

    // Tree<int> tree(11);
    // tree.children.push_back(21);
    // tree.print(tree);

}
