//
// Created by Михаил Коваленко on 02.03.17.
//

struct Element {
    int value;
    Element *next; // Указатель на следующий элемент
};

class Stack {
    private:
        Element *top;
        int length;
    public:
    void push(int a) {
        if (length == 0){
            top = new Element;
            top -> value = a;
            length ++;
        } else {
            Element *old = top;
            top = new Element;
            top -> value = a;
            length++;
        }
    }
    int pop(int &b){
        int value = b -> value;
        
    }
    Stack(){
        length = 0;
    }
    ~Stack(){

    }

};

class Queue {
    private:

    public:
    bool empty(){

    }
    int pop(){

    }
    Queue(){

    };
    ~Queue(){

    }
};

int main {
    while (runnig){
        cont << "1. Push" << endln;
        cout << "...or press any number to exit" << endl;

        cin >> enter;
        switch (enter){
            case 1:
                cout << "Enter number: ";
                cin >> enter;
                break;
        }
    }
    return 0;
};