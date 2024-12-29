#include <iostream>
#include <string>
#include <fstream>

int* create_arr(int size_arr);

void exercise_3()
{
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;
    int* arr_3 = create_arr(size);
    std::ofstream output_file("c:\\Qt_Projects\\Homework_011\\out_3.txt");
    std::string s;

    if(!output_file.is_open())
    {
        std::cout << "Ошибка открытия файла \"out_3.txt\"";
        return;
    }

    output_file << size << std::endl;
    for(int i=size-1; i>=0; i--)
    {
        output_file << arr_3[i] << " ";
    }

    delete[] arr_3;
    output_file.close();
}

int* create_arr(int size_arr)
{
    int* arr_new = new int[size_arr];
    for(int i=0; i < size_arr; i++)
    {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr_new[i];
    }

    return arr_new;
}
