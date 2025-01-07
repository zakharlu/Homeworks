#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <utility>

char new_cell_value(char** gen_prev, int i, int j, int rows, int cols);

char** create_generation(int row_cnt, int col_cnt)
{
    char** arr_1 = new char*[row_cnt];
       for(int i=0; i<row_cnt; i++)
       {
           arr_1[i] = new char[col_cnt];
       }

       return arr_1;
}


std::pair<bool, int> fill_generation_prev(std::ifstream& in_file, char** gen_number, int row_cnt, int col_cnt)
{
    int row;
    int col;
    std::string str_1;
    std::string str_2;
    int alive_cells = 0; // счетчик живых ячеек

    char **arr = gen_number;
     for (int i =0; i < row_cnt; i++)
     {
         for(int j=0; j<col_cnt; j++)
         {
             arr[i][j] = '-';
         }
     }

     while(!in_file.eof())
     {
         in_file >> str_1;
         row = std::stoi(str_1);
         in_file >> str_2;
         col = std::stoi(str_2);
         arr[row][col] = '*';
         ++alive_cells;
     }

   return {false, alive_cells};
}

void print_generation(char** gen_number, int row_cnt, int col_cnt)
{
    char** arr = gen_number;
    for(int i=0; i<row_cnt; i++)
    {
        for(int j=0; j<col_cnt; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::pair<bool, int> fill_generation_next(char** gen_num_prev, char** gen_num_next, int row_cnt, int col_cnt)
{
    char** gen_1 = gen_num_prev;
    char** gen_2 = gen_num_next;
    int alive_cells = 0; // счетчик живых ячеек
    bool flag_changes {false}; // флаг изменения состояний ячеек

    for(int i=0;  i<row_cnt; i++)
    {
        for(int j=0;  j<col_cnt; j++)
        {
            gen_2[i][j] = new_cell_value(gen_1, i, j, row_cnt, col_cnt);
            if (gen_2[i][j] == '*')
            {
                ++alive_cells;
            }

            if(gen_2[i][j] != gen_1[i][j])
            {
                flag_changes = true;
            }
        }
    }

    return {flag_changes, alive_cells};
}

char new_cell_value(char** gen_prev, int row_num, int col_num, int rows, int cols)
{
    char** gen_1 = gen_prev;
    int alive_nearest_cells_cnt = 0; // Счетчик живых прилегающих ячеек
    for(int i = row_num-1; i <= row_num+1; i++)
    {
            for(int j = col_num-1; j <= col_num+1; j++)
            {
                if((i>=0) && (i<rows) && (j>=0) && (j<cols) && !((i==row_num) && (j==col_num)))
                {
                    if (gen_1[i][j] == '*')
                    {
                        ++alive_nearest_cells_cnt;
                    }

                }
            }
    }

    if (gen_1[row_num][col_num] == '*') // живая ячейка
    {
        if ((alive_nearest_cells_cnt == 2) || (alive_nearest_cells_cnt == 3))
        {
            return '*';
        }
        else
        {
            return '-';
        }
    }
    else // мертвая ячейка
        if (alive_nearest_cells_cnt == 3)
        {
            return '*';
        }
        else
        {
            return '-';
        }
}


char** copy(char** gen_next, char** gen_prev, int row_cnt, int col_cnt)
{
    char** gen_1 = gen_prev;
    char** gen_2 = gen_next;
    for(int i=0; i<row_cnt; i++)
    {
        for(int j=0; j<col_cnt; j++)
        {
            gen_1[i][j] = gen_2[i][j];
        }
    }

    return gen_1;
}

void delete_memory(char** gen_prev, char** gen_next, int row_cnt)
{
    for(int i=0; i<row_cnt; i++)
    {
        delete[] gen_prev[i];
        delete[] gen_next[i];
    }

    delete[] gen_prev;
    delete[] gen_next;
}
