#include <iostream>

template<typename T>
class List {
private:
    struct Node {
        T element;
        Node* prev;
        Node* next;
    };

    Node* first = nullptr;
    Node* last = nullptr;
    int elementsCount = 0;

public:


};

int main(){
    
}
