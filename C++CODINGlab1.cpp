#include <iostream>

// 15. Создать класс, определяющий одномерный массив и содержащий функцию, проверяющую упорядочен ли этот одномерный массив по убыванию. 
// Сколько строк данной матрицы упорядочены по возрастанию? 
// Создать класс-наследник, дополнив его функцией, определяющей состоит ли массив только из простых чисел. 
// Сколько столбцов данной матрицы не содержат составных чисел?

class my_array_parrent {

public:
    int matrix[100];
    int lenght = 100;
    my_array_parrent(int l, bool input_required=true)
    {
        if (input_required) {
            lenght = l;
            std::cout << "Input array: ";
            for (int i = 0; i < lenght; i++) {
                std::cin >> matrix[i];
            }
        }

        else
            lenght = l;
    }

    void append(int x) {
        matrix[lenght] = x;
        lenght += 1;
    }

    bool is_ordered_decrease() {
        int previous = matrix[0];
        for (int i = 1; i <= lenght; i++) {
            if (!(previous > matrix[i])) {
                return false;
            }
            previous = matrix[i];
        }
        return true;
    }

    bool is_ordered_increase() {
        int previous = matrix[0];
        for (int i = 1; i < lenght; i++) {
            if (!(previous <= matrix[i])) {
                return false;
            }
            previous = matrix[i];
        }
        return true;
    }

    void print()
    {
        std::cout << "\n";
        for (int i = 0; i < lenght; i++) std::cout << matrix[i] << " ";
        if (lenght == 0) std::cout << matrix[0]; 
        std::cout << "\n";
    }
};
class my_array_inheritor : public my_array_parrent {
private:
    bool is_prime(int digit) {
        for (int i = 2; i <= std::pow(digit, 0.5); i++) {
            if (digit % i == 0) {
                return false;
            }
        }
        return true;
    }
public:
    using my_array_parrent::my_array_parrent;

    bool contains_only_prime_numbers() {
        for (int i = 0; i < lenght; i++){
            if (!(is_prime(matrix[i]))) return false;
        }

        return true;
    }

};

int calculate_simple_columns(my_array_inheritor arr[], int m, int n) {
    int counter = 0;
    for (int i = 0; i < m; i++){
        my_array_inheritor tmp(0, false);
        for (int j = 0; j < n; j++) {
            tmp.append(arr[j].matrix[i]);
        }
        counter += tmp.contains_only_prime_numbers();
    }
    std::cout << "\n";
    return counter;
}   

int main()
{
    int n, m, i = 0, counter_1 = 0, counter_2 = 0;
    std::cout << "n: ";
    std::cin >> n;
    std::cout << "m: ";
    std::cin >> m;
    my_array_inheritor* inheritor_matrix = (my_array_inheritor*)malloc(sizeof(my_array_inheritor) * n);

    for (int i = 0; i < n; i++) { 
        inheritor_matrix[i] = my_array_inheritor(m);
        int p = inheritor_matrix[i].is_ordered_increase();
        counter_1 += p;
    }

    counter_2 = calculate_simple_columns(inheritor_matrix, m, n);

    std::cout << "This matrix contains " << counter_1 << " rows in Ascending Order\n";

    std::cout << "This matrix contains " << counter_2 << " columns without complex digits\n";

    for (int i = 0; i < n; i++) inheritor_matrix[i].print();

    return 0;
}
