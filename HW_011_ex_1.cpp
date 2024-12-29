#include <iostream>
#include <string>
#include <fstream>

void exercise_1()
{
    std::ifstream input_file("c:\\Qt_Projects\\Homework_011\\in.txt");
    std::ofstream output_file("c:\\Qt_Projects\\Homework_011\\out.txt");
    std::string s;

    if(!input_file.is_open())
    {
        std::cout << "Ошибка открытия файла in.txt";
        return;
    }

    if(!output_file.is_open())
    {
        std::cout << "Ошибка открытия файла out.txt";
        return;
    }


    while(!input_file.eof())
    {
        input_file >> s;
        output_file << s << std::endl;
    }

    input_file.close();
    output_file.close();
}
