#include <iostream>

using namespace std;

struct Element {
    int value;
    Element *next; //Указывает на следующий элемент
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
    int pop(Element *next){ //Возврат значения
        if (length == 0){
            return -1;
        }
        Element *old = top;
        int value = top->value; //Считывает value
        top = top->next; //Берет указатель next и делает его новым top
        delete old; //Удаляет старый top
        return Element; //Возвращает сохраненное значение
    }
};

int main() {
    Element *first = new Element;
    Element *second = new Element;
    first-> next = second;

    Stack stack = new Stack;
    stack->push(1);
    stack->push(2);
    stack->push(3);

    cout << stack.pop() << endl; //Вывод в консоль с переносом строки
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;

    delete stack;

    List *NewList = new List; //Выделяет память
    for (int i=0; i<5; ++i)
        Add(i, NewList);
    Show(NewList);

    return 0;
}