#include <iostream>
#include <cstdlib>

double *create_array(int r_cnt);

int exercise_2()
{
// Задание 2
    int row_cnt2;
    std::cout << "Введите размер массива: ";
    std::cin >> row_cnt2;
    double *arr_new = create_array(row_cnt2);

    std::cout << "Массив: ";
    for(int i=0; i < row_cnt2; i++)
    {
        std::cout << arr_new[i] << " ";
    }
    delete[] arr_new;
    std::cout << std::endl;

    return 0;
}
