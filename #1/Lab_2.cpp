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

    

    // идеальная функция поиска В ней ничего не надо менять
    bool search(int key){
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