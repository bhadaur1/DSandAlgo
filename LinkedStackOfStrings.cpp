#include <iostream>
#include <stdexcept>

template <class Item>
class LinkedStack
{

private:

    struct Node {
        Item item;
        Node *next;
    };

    Node *first;
    Node *last;

public:

    LinkedStack():
        first{nullptr},
        last{nullptr}
    {    }

    bool isEmpty() {
        return ((first == nullptr) && (last == nullptr));
    }

    void addFirst(Item item)  {
        Node *temp = new Node();
        temp->item = item;
        temp->next = first;
        if (isEmpty())
            last = temp;
        first = temp;
    }

    void addLast(Item item)  {
        Node *temp = new Node();
        temp->item = item;
        temp->next = nullptr;
        last->next = temp;
        if (isEmpty())
            first = temp;
        last = temp;
    }

    Item removeFirst() {
        if (isEmpty())
            throw std::invalid_argument("Nothing to remove.");
        Item temp = first->item;
        Node *p = first;
        if (size()==1)
            last = nullptr;
        first = first->next;
        delete p;
        return temp;
    }

    Item removeLast() {
        if (isEmpty())
            throw std::invalid_argument("Nothing to remove.");
        Item temp = last->item;
        Node *p = last;
        if (size()==1) {
            first = nullptr;
            last = nullptr;
        }
        else {
            Node *curr(first);
            while (curr->next != last) {
                curr = curr->next;
            }
            last = curr;
            last->next = nullptr;
        }
        delete p;
        return temp;
    }

    int size() {
        if (isEmpty()) return 0;
        else if (first==last) return 1;
        else {
            int count(1);
            Node *curr(first);
            while (curr != last) {
                curr = curr->next;
                count++;
            }
            return count;
        }
    }
};


int main(int argc, char const *argv[])
{
    LinkedStack<std::string> lst;
    lst.addFirst("My ");
    lst.addLast("name ");
    lst.addLast("is ");
    lst.addLast("BABA ");
    std::cout << lst.isEmpty() << std::endl;
    std::cout << lst.size() << std::endl;
    std::cout << lst.removeLast() << std::endl;
    std::cout << lst.removeFirst() << std::endl;
    std::cout << lst.removeFirst() << std::endl;
    std::cout << lst.removeLast() << std::endl;

    std::cout << "Begin exception test...." << std::endl;
    std::cout << lst.removeLast() << std::endl;

    return 0;
}