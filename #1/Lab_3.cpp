/*
 * Имеется доска NхN, каждая клетка которой содержит несколько монет.
 * Герой стратегической игры находится в точке с координатой (1,1) и хочет
 * попасть в точку (N, N). При этом ходить он может по горизонтали и по
 * вертикали, на одну клетку и так, чтобы его ход увеличивал значение одной
 * из его координат. Определить маршрут, по которому герой соберет
 * максимальное число монет.
 *
 */

#include <iostream>
#include <vector>

std::vector< std::vector<int> > generator(int N) {
    std::vector< std::vector<int> > result(N);

    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i].push_back(rand() % 5 + 3);
        }
    }

    return result;
}

void print_matrix(std::vector< std::vector<int> > matrix) {
    for (unsigned int i = 0; i < matrix.size(); i++) {
        for (unsigned int j = 0; j < matrix[i].size(); j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {

    print_matrix(generator(5));

    return 0;
}

int main()
{
    int num;
    cout << "Enter size: ";
    cin >> num;

    int *coin = new int[num];
    for (int i = 0; i < num; i++) {
        coin[i] = i;
        cout << "Value of " << i << " element is " << coin[i] << endl;
    }
    delete [] coin;
    return 0;
}

int random(int random_min, int random_max) {
    return random() % (random_max - random_min + 1);
}