/*
    Author: Baozan Yan
    Date: 2022.06.28
    Description: The class of list
*/
#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    Node(const T &val = T()) : data(val), next(), prev() {}
    ~Node();
    T get();
    void set(T val);

    Node *next;
    Node *prev;

private:
    T data;
};

template <typename T>
Node<T>:: ~Node()
{
}

template <typename T>
T Node<T>::get()
{
    return data;
}

template <typename T>
void Node<T>::set(T val)
{
    data = val;
}

template <typename T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void AddToFront(T data);
    void AddToEnd(T data);
    bool AddAtIndex(T data, int index);
    void AddBefore(Node<T> *node, T data);
    void AddAfter(Node<T> *node, T data);
    T RemoveFromFront();
    T RemoveFromEnd();
    void RemoveTheFirst(T data);
    void RemoveAllOf(T data);
    T RemoveBefore(Node<T> *node);
    T RemoveAfter(Node<T> *node);
    bool ElementExists(T data);
    Node<T> *Find(T data);
    int IndexOf(T data);
    T RetrieveFront();
    T RetrieveEnd();
    T Retrieve(int index);
    void PrintList();
    void Empty();
    int Length();

private:
    Node<T> *head;
    Node<T> *tail;
    int length;
};

template <class T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    tail = NULL;
    length = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    Empty();
}

template <class T>
void LinkedList<T>::AddToFront(T data)
{
    Node<T> *new_node = new Node<T>;
    new_node->set(data);
    if (!head)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    length++;
}

template <class T>
void LinkedList<T>::AddToEnd(T data)
{
    Node<T> *new_node = new Node<T>;
    new_node->set(data);
    if (!head)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
    length++;
}

template <class T>
bool LinkedList<T>::AddAtIndex(T data, int index)
{

    if (Length() < index)
    {
        return false;
    }
    Node<T> *new_node = new Node<T>;
    new_node->set(data);
    Node<T> *tmp = head;

    while (index--)
    {
        tmp = tmp->next;
    }

    new_node->prev = tmp->prev;
    tmp->prev->next = new_node;
    new_node->next = tmp;
    tmp->prev = new_node;
    length++;
    return true;
}

template <class T>
void LinkedList<T>::AddBefore(Node<T> *node, T data)
{
    Node<T> *tmp = head;

    while (tmp)
    {
        if (tmp->get() == data)
        {
            break;
        }
        tmp = tmp->next;
    }

    if (tmp)
    {
        node->prev = tmp->prev;
        tmp->prev->next = node;
        node->next = tmp;
        tmp->prev = node;
        length++;
    }
    return;
}

template <class T>
void LinkedList<T>::AddAfter(Node<T> *node, T data)
{
    Node<T> *tmp = head;

    while (tmp)
    {
        if (tmp->get() == data)
        {
            break;
        }
        tmp = tmp->next;
    }

    if (tmp)
    {
        node->prev = tmp;
        node->next = tmp->next;
        tmp->prev->next = node;
        node->next = tmp;
        tmp->prev = node;
        length++;
    }
    return;
}

template <class T>
T LinkedList<T>::RemoveFromFront()
{
    Node<T> *tmp = head;
    T data;
    head = tmp->next;
    data = tmp->get();
    delete tmp;
    length--;

    return data;
}

template <class T>
T LinkedList<T>::RemoveFromEnd()
{
    Node<T> *tmp = tail;
    T data;
    tail = tmp->prev;
    data = tmp->get();
    delete tmp;
    length--;

    return data;
}

template <class T>
void LinkedList<T>::RemoveTheFirst(T data)
{
    Node<T> *tmp = head;

    while (tmp)
    {
        if (tmp->get() == data)
        {
            if (tmp == head)
            {
                RemoveFromFront();
            }
            else if (tmp == tail)
            {
                RemoveFromEnd();
            }
            else
            {
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                delete tmp;
                length--;
            }
            break;
        }
        tmp = tmp->next;
    }

    return;
}

template <class T>
void LinkedList<T>::RemoveAllOf(T data)
{
    Node<T> *tmp = head;
    Node<T> *p;

    while (tmp)
    {
        if (tmp->get() == data)
        {
            p = tmp->next;

            if (tmp == head)
            {
                RemoveFromFront();
            }
            else if (tmp == tail)
            {
                RemoveFromEnd();
            }
            else
            {
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                delete tmp;
                length--;
            }
            tmp = p;
        }
        else
        {
            tmp = tmp->next;
        }
    }

    return;
}

template <class T>
T LinkedList<T>::RemoveBefore(Node<T> *node)
{
    Node<T> *tmp;
    T data;

    if (node != head)
    {
        tmp = node->prev;
        node->prev = tmp->prev;
        tmp->prev->next = node;
        data = tmp->get();
        delete tmp;
        length--;
    }

    return data;
}

template <class T>
T LinkedList<T>::RemoveAfter(Node<T> *node)
{
    Node<T> *tmp;
    T data;

    if (node != tail)
    {
        tmp = node->next;
        node->next = tmp->next;
        tmp->next->prev = node;
        data = tmp->get();
        delete tmp;
        length--;
    }

    return data;
}

template <class T>
bool LinkedList<T>::ElementExists(T data)
{
    Node<T> *tmp = head;

    while (tmp)
    {
        if (tmp->get() == data)
        {
            return true;
        }
        tmp = tmp->next;
    }

    return false;
}

template <class T>
Node<T> *LinkedList<T>::Find(T data)
{
    Node<T> *tmp;
    tmp = head;
    while (tmp)
    {
        if (tmp->get() == data)
        {
            return tmp;
        }
        tmp = tmp->next;
    }

    return NULL;
}

template <class T>
int LinkedList<T>::IndexOf(T data)
{
    Node<T> *tmp;
    int count = 0;
    tmp = head;
    while (tmp)
    {
        if (tmp->get() == data)
        {
            return count;
        }
        count++;
        tmp = tmp->next;
    }

    return -1;
}

template <class T>
T LinkedList<T>::RetrieveFront()
{
    if (head)
    {
        return head->get();
    }
}

template <class T>
T LinkedList<T>::Retrieve(int index)
{
    if (index < 0 || index > Length())
    {
        throw "index out of bounds";
    }
    Node<T> *tmp = head;
    while (index--)
    {
        tmp = tmp->next;
    }
    return tmp->get();
}

template <class T>
void LinkedList<T>::PrintList()
{
    Node<T> *tmp = head;
    
    for(int i = 0; i < length; i++)
    {
        cout <<"["<< tmp->get() <<"] ";
        tmp = tmp->next;
    }
    cout<<endl;
}

template <class T>
void LinkedList<T>::Empty()
{
    Node<T> *tmp = head;
    Node<T> *p;

    while (tmp)
    {
        p = tmp->next;
        delete tmp;
        tmp = p;
        length--;
    }
}

template <class T>
int LinkedList<T>::Length()
{
    return length;
}