#include <iostream>

using namespace std;

struct Stack {
    private:
        int value;
//        int head = -1; //Крайний элемент
        struct stack *next; //Указывает на следующий элемент

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

int pop(stak *next){
    if (lengh == 0){

    }
};

int main() {
    List *NewList = new List; //Выделяет память
    for (int i=0; i<5; ++i)
        Add(i, NewList);
    Show(NewList);
    return 0;
}