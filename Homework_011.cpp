#include <iostream>
void exercise_1();
void exercise_2();
void exercise_3();
void exercise_4();

int main()
{
    int ex_number;
    std::cout << "Введите номер задания: ";
    std::cin >> ex_number;
    if (ex_number == 1)
        exercise_1();
    if (ex_number == 2)
        exercise_2();
    if (ex_number == 3)
    exercise_3();
    if (ex_number == 4)
    exercise_4();
}
