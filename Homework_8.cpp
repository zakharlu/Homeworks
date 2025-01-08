#include <iostream>
void counting_function()
{
    static int fun_calls_cnt = 1;
    std::cout << "Количество вызовов функции counting_function(): " << fun_calls_cnt << std::endl;
    ++fun_calls_cnt;
}

namespace add
{
    int calc(int x, int y)
    {
        return x + y;
    }
}

namespace sub
{
    int calc(int x, int y)
    {
        return x - y;
    }
}

namespace mult
{
    int calc(int x, int y)
    {
        return x * y;
    }
}

namespace div_
{
    int calc(int x, int y)
    {
        return x / y;
    }
}

int main()
{
    // Задание 1
    std::cout << "Задание 1" << std::endl;
    for (int i = 0; i < 15; i++)
        {
            counting_function();
        }

    // Задание 2
    int x = 6;
    int y = 9;
    std::cout << std::endl;
    std::cout << "Задание 2" << std::endl;
    std::cout << "x = " << x << ", y = " << y << std::endl;

    std::cout << "Сложение " << add::calc(x, y) << std::endl;
    std::cout << "Вычитание " << sub::calc(x, y) << std::endl;
    std::cout << "Умножение " << mult::calc(x, y) << std::endl;
    std::cout << "Деление " << div_::calc(x, y) << std::endl;

    return 0;
}
