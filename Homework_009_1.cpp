#include <iostream>
#include <cstdlib>

int exercise_1()
{
// ���� ���ᨢ� � ���᮫�
    int row_cnt;
    std::cout << "������ ࠧ��� ���ᨢ�: ";
    std::cin >> row_cnt;
    int *arr1 = new int[row_cnt];
    int cell_value;
    for(int i=0; i < row_cnt; i++)
    {
        std::cout << "arr1[" << i << "] = ";
        std::cin >> cell_value;
        arr1[i] = cell_value;
    }
    std::cout << "�������� ���ᨢ: ";
    for(int i=0; i < row_cnt; i++)
    {
        std::cout << arr1[i] << " ";
    }

    delete[] arr1;
    std::cout << std::endl << std::endl;

    return 0;
}
