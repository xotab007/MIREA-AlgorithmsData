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
};
*/

class Stack {
    private:
        Node *top;
        int length = 0;
        ~Stack();
};

int pop(stak *next){
};

int main() {
    List *NewList = new List; //Выделяет память
    for (int i=0; i<5; ++i)
        Add(i, NewList);
    Show(NewList);
    return 0;
}