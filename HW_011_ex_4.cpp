#include <iostream>
#include <string>
#include <fstream>

int** create_arr_2(int row_cnt, int col_cnt);
void print_two_dim_array(int **arr, int row_cnt,  int col_cnt);
void delete_two_dim_array(int **arr, int row_cnt);


void exercise_4()
{
    std::ifstream input_file("c:\\Qt_Projects\\Homework_011\\in_4.txt");
    std::string str_1;
    std::string str_2;
    std::string str_3;
    int rows;
    int cols;

    if(!input_file.is_open())
    {
        std::cout << "Ошибка открытия файла \"in_4.txt\"";
        return;
    }

    input_file >> str_1;
    rows = std::stoi(str_1);
    input_file >> str_2;
    cols = std::stoi(str_2);

    int** arr_4 = create_arr_2(rows, cols);
    while (!input_file.eof())
    {
        for (int i =0; i < rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                input_file >> str_3;
                arr_4[i][cols-j-1] = std::stoi(str_3);
            }

        }
    }

    print_two_dim_array(arr_4, rows,  cols);
    delete_two_dim_array(arr_4, rows);


    input_file.close();
}

int** create_arr_2(int row_cnt, int col_cnt)
{
    int** arr_int = new int*[row_cnt];
       for(int i=0; i<row_cnt; i++)
       {
           arr_int[i] = new int[col_cnt];
       }

       return arr_int;
}


void print_two_dim_array(int **arr, int row_cnt,  int col_cnt)
{
    for (int i=0; i<row_cnt; i++)
    {
        for(int j=0; j<col_cnt; j++)
        {
           std::cout << arr[i][j] <<"\t";
        }
        std::cout << std::endl;
    }
}

void delete_two_dim_array(int **arr, int row_cnt)
{
    for(int i=0; i < row_cnt; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

}
