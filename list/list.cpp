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

};

int main(){
    
}
