#include <iostream>

using namespace std;

struct Element {
    int value;
    Element *next; //Указывает на следующий элемент
};

class Stack {
    private:
        Element *top;
        int length = 0;
    public:
        void push(int a){
            if (length == 0) {
                top = new Element; //Помещает новый элемент в вершину
                top->value = a; //Записывает значение в элемент
                length++; //Увеличиваем значение на единицу
            } else {
                Element *old =top; //Сохронет старое значение top
                top = new Element; //Перезапись top
                top->value = a;
                top->next = old; //Показывает новому элементу элемент до него
                length++;
            }
        }
    ~Stack() {
        while (length > 0) {
            pop();
        }
    }
    int pop(){ //Возврат значения
        if (length == 0){
            return -1;
        }
        Element *old = top;
        int value = top->value; //Считывает value
        top = top->next; //Берет указатель next и делает его новым top
        delete old; //Удаляет старый top
        return value; //Возвращает сохраненное значение
    }
    int size(){
        return length;
    }
};

class Queue {
    private:
        Stack *ahead, *last;
    public:
        Queue(){
            ahead = new Stack;
            last = new Stack;
        }
        ~Queue(){
            delete ahead;
            delete last;
        }

    void push(int a) {
        while (size()>0){
            last->push(ahead->pop()); //Стек с обратным порядком переменных
        }
        ahead->push(a); //Добавление нового элемента
        while (last->size() > 0) {
            ahead->push(last->pop());
        }
    }
    int pop() {
        return ahead->pop();
    }
    int size(){
        return ahead->size();
    }
};

int main() {
    Element *first = new Element;
    Element *second = new Element;
    first-> next = second;

    Stack *stack = new Stack;
    stack->push(1);
    stack->push(2);
    stack->push(3);

    cout << stack->pop() << endl; //Вывод в консоль с переносом строки
    cout << stack->pop() << endl;
    cout << stack->pop() << endl;

    delete stack;

    Queue *NewQueue = new Queue;
    NewQueue->push(1);
    NewQueue->push(2);
    NewQueue->push(3);

    cout << NewQueue->pop() << endl;
    cout << NewQueue->pop() << endl;
    cout << NewQueue->pop() << endl;

    delete NewQueue;

    return 0;
}