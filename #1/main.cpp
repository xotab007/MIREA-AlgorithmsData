#include <iostream>

using namespace std;

struct Element {
    int value;
    Element *next; //Указывает на следующий элемент
};

class Stack {
    private:
        Element *top;
//        int length;
    public:
        Stack(){
            top = NULL;
        }
        void push(int a){
            if (top == NULL) {
                top = new Element;
                top->next = NULL;
//                top = new Element; //Помещает новый элемент в вершину
                top->value = a; //Записывает значение в элемент
            } else {
                Element *old =top; //Сохронет старое значение top
                top = new Element; //Перезапись top
                top->value = a;
                top->next = old; //Показывает новому элементу элемент до него
            }
//            length++; //Увеличиваем значение на единицу
        }
/*
    Stack(){
        length = 0;
    }
*/
    ~Stack() {
        while (top == NULL) {
            pop();
        }
    }

    bool empty(int Stack){
            return (value == NULL);
    }

    int pop(){ //Возврат значения
        if (top == NULL){
            return -1;
        }
        Element *old = top;
        int value = top->value; //Считывает value
        top = top->next; //Берет указатель next и делает его новым top
        delete old; //Удаляет старый top
//        length--; //Уменьшает счетчик на -1
        return value; //Возвращает сохраненное значение
    }
/*
    int size(){
        return length;
    }
*/
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
        int b;
        while ((b = ahead->pop()) != -1){
            /*int b = ahead->pop();
            if (b == -1) {
                break;
            }*/
            last->push(b); //Стек с обратным порядком переменных
        }
        ahead->push(a); //Добавление нового элемента
        while (true) {
            int b;
            b = last->pop();
            if (b == -1){
                break;
            }
            ahead->push(b);
        }
    }
    int pop() {
        return ahead->pop();
    }
/*
    int size(){
        return ahead->size();
    }
*/
};

int main() {
/*
    Element *first = new Element;
    Element *second = new Element;
    first-> next = second;
*/
    Queue *queue = new Queue;
    bool running = true; //Проверка логических условий
    int enter = 0;

    while (running) {
        cout << "1. push" << endl;
        cout << "2. pop" << endl;
        cout << "...or press Ctrl+C to Exit" << endl;

        cin >> enter; //Читаем введеное значение
        switch (enter) { //Оператор множественного выбора
            case 1: //Константное выражение №1
                cout << "Please enter a number: ";
                cin >> enter;
                queue->push(enter);
                cout << endl << "Pushed: " << enter << endl;
                break;
            case 2:
                int b;
                b = queue->pop();
                if (b != -1) {
                    cout << endl << "Popped: " << b << endl;
                } else {
                    cout << endl << "Queue is empty!" << endl;
                }
                break;
            default:
                running = false;
                break;
        }
        cout << "Press Enter to continue..." << endl;

        string tmp;
        cin.ignore(); //Чистит память ввода
        getline(cin, tmp);

    }

/*
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
*/
    delete queue;
    return 0;

}