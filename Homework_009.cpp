#include <iostream>
#include <cstdlib>

double *create_array(int r_cnt);
int **create_two_dim_array(int row_cnt, int col_cnt);
void fill_two_dim_array(int **arr, int row_cnt,  int col_cnt);
void print_two_dim_array(int **arr, int row_cnt,  int col_cnt);
void delete_two_dim_array(int **arr, int row_cnt,  int col_cnt);

int main()
{
// Задание 1
    int row_cnt;
    std::cout << "Введите размер массива: ";
    std::cin >> row_cnt;
//    int * arr1 = static_cast<int *>(malloc(row_cnt * sizeof(int)));
//    int * arr1 = static_cast<int *>(calloc(row_cnt, sizeof(int)));
    int *arr1 = new int[row_cnt];
    int cell_value;
    for(int i=0; i < row_cnt; i++)
    {
        std::cout << "arr1[" << i << "] = ";
        std::cin >> cell_value;
        arr1[i] = cell_value;
    }
    std::cout << "Введенный массив: ";
    for(int i=0; i < row_cnt; i++)
    {
        std::cout << arr1[i] << " ";
    }


//    free(arr1);
    delete[] arr1;
    std::cout << std::endl;
    std::cout << std::endl;


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
//    return static_cast<double *>(calloc(r_cnt, sizeof(double)));
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
