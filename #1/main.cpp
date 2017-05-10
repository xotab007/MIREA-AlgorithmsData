#include <iostream>

using namespace std;

struct Element {
    int value;
    Element *next; //Указывает на следующий элемент
};

class Stack {
private:
    Element *top;
    int length;
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
    Stack(){
        length = 0;
    }
    ~Stack() {
        while (length > 0) {
            pop();
        }
    }
    int pop(){ //Возврат значения
        /*if (length == 0){
            throw "No elements";
        }*/
        Element *old = top;
        int value = top->value; //Считывает value
        top = top->next; //Берет указатель next и делает его новым top
        delete old; //Удаляет старый top
        length--; //Уменьшает счетчик на -1
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
            /*try {*/
                if(ahead->size() == 0) {
                    //Если в стеки ничего нет
                    return 1;
                }else{
                    //Если что-то есть
                    *er = ahead->pop();
                    return 0;
                }
                return 0;
            /*} catch (const char *er) {
                cout << er << endl;
                return 1;
            }*/
    }
    int size(){
        return ahead->size();
    }
};

int main() {
    Queue *queue = new Queue;
    bool running = true; //Проверка логических условий
    int enter = 0;

    while (running) {
        cout << "1. push" << endl;
        cout << "2. pop" << endl;
        cout << "...or press any number to exit" << endl;

        cin >> enter; //Читаем введеное значение
        switch (enter) { //Оператор множественного выбора
            case 1: //Константное выражение №1
                cout << "Please enter a number: ";
                cin >> enter;
                queue->push(enter);
                cout << endl << "Pushed: " << enter << endl;
                break;
            case 2:
                int c;
                if (queue->pop(&c) == 0) {
                    cout << endl << "Popped: " << c << endl;
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
    delete queue;
    return 0;
}