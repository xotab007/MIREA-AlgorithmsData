#include <iostream>

using namespace std;

struct Stack {
    int value;
    Node *next; //Указывает на следующий элемент
};

struct Element {
    int value;
    Element *previous, *next; //Указывает на соседние элементы
};

class Stack {
    private:
        Element *top;
        int length = 0;
    public:
    void push(int a){

    }
};

int pop(stak *next){
};

int main() {
    Element *first = new Element;
    Element *second = new Element;
    first-> next = second;

    List *NewList = new List; //Выделяет память
    for (int i=0; i<5; ++i)
        Add(i, NewList);
    Show(NewList);
    return 0;
}