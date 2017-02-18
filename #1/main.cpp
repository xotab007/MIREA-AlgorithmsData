#include <iostream>

using namespace std;

struct Stack {
//    private:
        int value;
//        int head = -1; //Крайний элемент
        Node *next; //Указывает на следующий элемент
/*
    public:
        Stack(){
            Stack(int=5);
            ~Stack();
        }
        void pop();
        void push(int a){
            head++;
        }
*/
};

struct Node {
    int data;
    Node *previous, *next; //Указывает на соседние элементы
};

class Stack {
    private:
        Node *top;
        int length = 0;
        ~Stack();
    public:
    void push(int a){
        Stack *NewStack = new Stack;
        NewStack->value = value;
        head++;
    }
};

int pop(stak *next){
};

int main() {
    Node *first = new Node;
    Node *second = new Node;
    first-> next = second;

    List *NewList = new List; //Выделяет память
    for (int i=0; i<5; ++i)
        Add(i, NewList);
    Show(NewList);
    return 0;
}