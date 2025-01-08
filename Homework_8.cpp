#include <iostream>
void counting_function()
{
    static int fun_calls_cnt = 1;
    std::cout << "������⢮ �맮��� �㭪樨 counting_function(): " << fun_calls_cnt << std::endl;
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
    // ������� 1
    std::cout << "������� 1" << std::endl;
    for (int i = 0; i < 15; i++)
        {
            counting_function();
        }

    // ������� 2
    int x = 6;
    int y = 9;
    std::cout << std::endl;
    std::cout << "������� 2" << std::endl;
    std::cout << "x = " << x << ", y = " << y << std::endl;

    std::cout << "�������� " << add::calc(x, y) << std::endl;
    std::cout << "���⠭�� " << sub::calc(x, y) << std::endl;
    std::cout << "��������� " << mult::calc(x, y) << std::endl;
    std::cout << "������� " << div_::calc(x, y) << std::endl;

    return 0;
}
