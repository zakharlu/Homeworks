#include <iostream>
#include <cstdlib>

int **create_two_dim_array(int row_cnt, int col_cnt);
void fill_two_dim_array(int **arr, int row_cnt,  int col_cnt);
void print_two_dim_array(int **arr, int row_cnt,  int col_cnt);
void delete_two_dim_array(int **arr, int row_cnt,  int col_cnt);

int exercise_3()
{
// Задание 3
    int rows;
    int cols;
    std::cout << std::endl;
    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов: ";
    std::cin >> cols;
    int **arr3 = create_two_dim_array(rows, cols);

    std::cout << "Таблица умножения: ";

    std::cout << std::endl;
    fill_two_dim_array(arr3, rows,  cols);
    print_two_dim_array(arr3, rows,  cols);
    delete_two_dim_array(arr3, rows,  cols);

    return 0;
}

double *create_array(int r_cnt)
{
    return new double[r_cnt]();
}


int **create_two_dim_array(int row_cnt, int col_cnt)
{
   int** arr_int = new int*[row_cnt];
   for(int i=0; i<row_cnt; i++)
   {
       arr_int[i] = new int[col_cnt];
   }

   return arr_int;
}

void fill_two_dim_array(int **arr, int row_cnt,  int col_cnt)
{
    int **arr_val = arr;
    for (int i =0; i < row_cnt; i++)
    {
        for(int j=0; j<col_cnt; j++)
        {
            arr_val[i][j] = (i+1)*(j+1);
        }
    }
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

void delete_two_dim_array(int **arr, int row_cnt,  int col_cnt)
{
    for(int i=0; i < row_cnt; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

}
