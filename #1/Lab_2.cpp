/*
 * Задание: Дерево с балансировкой по возрастанию ((2^n)-1)
 *
 * 1. Узел дерева
 * 2. Добавление узла (Ещем, если корень пуст -- создаем новый элемент)
 * 3. Удаление узла
 * 4. Поиск
 * 5.
 *
 */

#include <iostream>

struct Node{
    int key; // Индекс значения в кружочке
    Node *left, *right;
};

class Tree{
private:
    Node *root;
    //Балансировка
    int count;

public:
    Tree();
    ~Tree();


    void add(int a){
        Node* tmp = new Node();
        tmp->right = NULL;
        tmp->left = NULL;
        tmp->key = a;

        if (NULL == root){
            root = tmp;
            return;
        }
        Node* b;
        b = root;

        bool found = false;
        while (!found)
            {
                if (b->key == a)
                {
                    delete tmp;
                    return;
                }
                if (b->key < a)
                {
                    if (b->right == NULL)
                    {
                        b->right = tmp;
                        found = true;
                        break;
                    }
                    else
                    {
                        b = b->right;
                    }
                }
                else
                {
                    if (b->key == a)
                    {
                        delete tmp;
                        return;
                    }
                    if (b->key < a)
                    {
                        if (b->left == NULL)
                        {
                            b->left = tmp;
                            found = true;
                            break;
                        }
                        else
                        {
                            b = b->left;
                        }
                    }
                }
            }
        /*
        1. Найти нового родителя или узнать, что такой элемент есть
        1.1 Если элемент меньше -- лево. Элемент больше -- право
        2. Связать родителя и тмп
        */
    };

    void remove(int key) {
        // Ищем элемент и его родителя
        Node* parent = NULL;
        Node* tmp = root;

        while (true) {
            if (key < tmp->key && tmp->left != NULL) {
                parent = tmp;
                tmp = tmp->left;
            } else if (key > tmp->key && tmp->right != NULL) {
                parent = tmp;
                tmp = tmp->right;
            } else {
                break;
            }
        }

        if (tmp->key != key) { // не нашли :C
            return;
        }

        // Потомков нету (как и этого слова)
        //          ⇑______________________⇓
        else if (tmp->left == NULL && tmp->right == NULL) {
            if (tmp->key < parent->key) {
                parent->left = NULL;
            } else if (tmp->key > parent->key) {
                parent->right = NULL;
            }
            delete tmp; // премия Дарвина
        }

        // Один потомок (слева)
        else if (tmp->left != NULL && tmp->right == NULL) {
            tmp->key = tmp->left->key;
            delete tmp->left;
            tmp->left = NULL;
        }

        // Один потомок (справа)
        else if (tmp->right != NULL && tmp->left == NULL) {
            tmp->key = tmp->right->key;
            delete tmp->right;
            tmp->right = NULL;
        }

        // 10₂ потомков (всё сложно)
        else if (tmp->left != NULL && tmp->right != NULL) {
            //int tmp_key = tmp->children[1]->min()->key;
            // Ищем минимального потомка в правом поддереве

            Node* tmp_min = tmp->right;
            while (tmp_min->left != NULL) {
                tmp_min = tmp_min->left;
            }
            int tmp_key = tmp_min->key;

            // Проводим странные махинации
            remove(tmp_key);
            tmp->key = tmp_key;
        }

        return; // Готово! Вы восхитительны!
    }

    

    // идеальная функция поиска В ней ничего не надо менять
    bool search(int x){
        Node* a = root; // a -- рамочка

        while (a != NULL){
            if (x < a->key) {
                a = a->left;
            }
            if (x > a->key) {
                a = a->right;
            }
            if (x == a->key) {
                return true;
            }
        }
        return false;
    };

    


    void print();
};
int main(){

        return 0;
};
