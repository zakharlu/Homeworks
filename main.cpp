#include <iostream>
#include <fstream>
#include <cstdlib>
#include <utility>
#include <string>
#include <unistd.h>

char** create_generation(int row_cnt, int col_cnt);
std::pair<bool, int> fill_generation_prev(std::ifstream& in_file, char** gen_number, int row_cnt, int col_cnt);
void print_generation(char** gen_number, int row_cnt, int col_cnt);
std::pair<bool, int> fill_generation_next(char** gen_num_prev, char** gen_num_next, int row_cnt, int col_cnt);
void delete_memory(char** gen_prev, char** gen_next, int row_cnt);
char** copy(char** gen_next, char** gen_prev, int row_cnt, int col_cnt);


int main()
{
    int rows;
    int cols;
    int generation_num = 1; // счетчик количества поколений
    std::string str1;
    std::string str2;
    std::ifstream input_file("./generation_1.txt");
    if (!input_file.is_open())
    {
        std::cout << "Ошибка открытия файла generation_1.txt" << std::endl;
        system("pause");
        return 1;
    }

    input_file >> str1;
    rows = std::stoi(str1);
    input_file >> str2;
    cols = std::stoi(str2);

    char** gen_1 = create_generation(rows, cols);
    char** gen_2 = create_generation(rows, cols);
    auto resumes_prev_gen = fill_generation_prev(input_file, gen_1, rows, cols);
    print_generation(gen_1, rows, cols);
    if (resumes_prev_gen.second == 0)
    {
        std::cout << "Generation: " << generation_num << ". Alive cells: " << resumes_prev_gen.second << "." << std::endl << "All cells are dead. Game over." <<std::endl;
        delete_memory(gen_1,gen_2, rows);
        return 0;
    }
    else
    {
        std::cout << "Generation: " << generation_num << ". Alive cells: " << resumes_prev_gen.second <<"." << std::endl;
        sleep(1);
    }

    while (true)
    {     
        auto resumes_next_gen = fill_generation_next(gen_1, gen_2, rows, cols);
        ++generation_num;
        std::system("cls");
        print_generation(gen_2, rows, cols);
        if (resumes_next_gen.second == 0)
        {
            std::cout << "Generation: " << generation_num << ". Alive cells: " << resumes_next_gen.second << "." << std::endl << "All cells are dead. Game over." <<std::endl;
            delete_memory(gen_1, gen_2, rows);
            return 0;
        }

        if(resumes_next_gen.first)
        {
            gen_1 = copy(gen_2, gen_1, rows, cols);
            std::cout << "Generation: " << generation_num << ". Alive cells: " << resumes_next_gen.second <<"." << std::endl;
            sleep(1);
        }
        else
        {
            std::cout << "Generation: " << generation_num << ". Alive cells: " << resumes_next_gen.second << "." << std::endl << "The world has stagnated. Game over." <<std::endl;
            delete_memory(gen_1, gen_2, rows);
            return 0;
        }
    }
}
