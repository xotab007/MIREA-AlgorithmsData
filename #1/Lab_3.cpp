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
#include <vector> // Для векторов std::vector
#include <math.h> // Для функции pow(число, степень)

#define MATRIX std::vector< std::vector<int> >

MATRIX generator(int N) {
    MATRIX result(N);

    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i].push_back(rand() % 5 + 3);
        }
    }

    return result;
}

void print_matrix(MATRIX matrix) {
    for (unsigned int i = 0; i < matrix.size(); i++) {
        for (unsigned int j = 0; j < matrix[i].size(); j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int brute_force(MATRIX matrix) {
    int best_result = 100500;

    for (long int state = 0; state < pow(2, (matrix.size()-1)*2); state++) {
        unsigned int x = 0; unsigned int y = 0; // текущие координаты

        int result = matrix[x][y];
        for (unsigned int i = 0; i < (matrix.size()-1)*2; i++) {
            if ((state >> i) & 1) { // вправо
                if (++x >= matrix.size()) {
                    result = 100500;
                    break;
                }
            } else { // вниз
                if (++y >= matrix.size()) {
                    result = 100500;
                    break;
                }
            }
            result += matrix[x][y];
        }

        if (result < best_result) {
            best_result = result;
        }
    }

    return best_result;
}

int dynamic(MATRIX matrix) {
    for (unsigned int i = 0; i < matrix.size(); i++) {
        for (unsigned int j = 0; j < matrix[i].size(); j++) {
            if (i > 0 && j > 0) {
                matrix[i][j] += fmin(matrix[i-1][j], matrix[i][j-1]);
            } else {
                if (i > 0) {
                    matrix[i][j] += matrix[i-1][j];
                } else if (j > 0) {
                    matrix[i][j] += matrix[i][j-1];
                }
            }
        }
    }

    return matrix[matrix.size() - 1][matrix.size() - 1];
}

int main(int argc, char **argv) {

    MATRIX matrix = generator(5);
    print_matrix(matrix);
    printf("brute force: %d\n", brute_force(matrix));
    printf("dynamic: %d\n", dynamic(matrix));

    return 0;
}