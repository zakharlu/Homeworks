#include <iostream>
#include <string>
#include <fstream>

void reverse(int* arr_num, int size_arr);
void print(int* members, int size);

void exercise_2()
{
    std::ifstream input_file("c:\\Qt_Projects\\Homework_011\\in_2.txt");
    std::string s;
    int num_cnt;

        if(!input_file.is_open())
        {
            std::cout << "Ошибка открытия файла \"in_2.txt\"";
            return;
        }

        input_file >> s;
        num_cnt = std::stoi(s);

        int* arr = new int[num_cnt];
        for(int i=0; i<num_cnt; i++)
        {
           input_file >> s;
           arr[i] = std::stoi(s);
        }

        reverse(arr, num_cnt);
        print(arr, num_cnt);

    delete[] arr;
    input_file.close();
}


void reverse(int* arr_num, int size_arr)
{
    int var_tmp;
    for (int i = 0; i < size_arr/2; i++)
    {
       var_tmp = arr_num[size_arr-1-i];
       arr_num[size_arr-1-i] = arr_num[i];
       arr_num[i] = var_tmp;
    }

}

void print(int* members, int size)
{
    for(int i=0; i<size; i++)
    {
        std::cout << members[i] << " ";
    }
    std::cout << std::endl;
}

