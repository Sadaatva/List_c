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

    List(std::initializer_list<T> list_a = {}){
    for (const auto& element : list_a){
        PushBack(element);
        }
    }
 
    List(const List& M){
        for (Node* node = M.first; node != nullptr; node = node -> next){
            PushBack(node -> element);
        }
    }
    
    List& operator= (const List& M){
        if (this != &M) {
            Clear();
            for (Node* node = M.first; node != nullptr; node = node -> next) {
                PushBack(node -> element);
            }
        }
        return *this;
    }

    void PopBack(){
        if (elementsCount == 0){
            std::cerr << "Empty list" << "\n"; 
        }

        if (elementsCount == 1){
            delete last;
            last = first = nullptr;
        } else {
            Node* elem = last -> prev;
            delete last;
            last = elem;
            last -> next = nullptr;
        }

        elementsCount--;
    }

    void PopFront(){
        if (elementsCount == 0){
            std::cerr << "Empty list" << "\n";
            return;
        }

        if (elementsCount == 1){
            delete first;
            first = last = nullptr;
        } else{
            Node* elem = first -> next;
            delete first;
            first = elem;
            first -> prev = nullptr;
        }

        elementsCount--;
    }

    void Clear(){
        while (first != nullptr){
            Node* elem = first;
            first = first -> next;
            delete elem;
        }

        last = nullptr;
        elementsCount = 0;
    }

    void PushBack(const T& elem){
        Node* node = new Node(elem, last, nullptr);

        if (last != nullptr){
            last -> next = node;
        } else {
            first = node;
        }
        last = node;
        ++elementsCount;
    }

    
    const T& Front() const{
        if (first != nullptr){
            return first -> element;
        } else {
        std::cerr << "Empty list" << "\n";
        throw std::out_of_range("Empty List");
        }
    }

    bool Empty()const{
        return first == nullptr;
    }

    ~List(){
        Clear();
    }
    
    size_t Size()const{
        return elementsCount;
    }
};

int main(){
    
}
