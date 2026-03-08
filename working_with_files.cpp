#include <iostream>
#include <fstream>


int main()
{
    std::ofstream file("text.txt");
    if (!file.is_open()) return 1;
    file << "Hello" << std::endl;
    file << "This is my first file" << std::endl;
    file << "C++ is cool" << std::endl; 
    file.close();
    

    std::ifstream read("text.txt");
    if (!read.is_open()) return 1;
    std::string word;
    size_t n = 0;
    while(read >> word)
    {
        std::cout << word << std::endl;
        n++;
    }
    std::cout << "Word count: " << n << std::endl;
    read.close();


    std::ifstream read_line("text.txt");
    if (!read_line.is_open()) return 1;
    n = 1;
    std::string line;
    while(std::getline(read_line, line))
    {
        std::cout << n++ << ':' << line << std::endl;
    }
    read_line.close();


    std::ofstream append("fruits.txt", std::ios::app);
    if (append.is_open()) 
    {
        append << std::endl << "Orange";
        append.close();
    }


    std::ifstream src("text.txt");
    std::ofstream place("text2.txt");
    if (src.is_open() && place.is_open())
    {
        while(std::getline(src, line))
        {
            place << line << std::endl;
        }

        src.close();
        place.close();
    }


    std::ifstream finding_longest_word("text.txt");
    std::string max_word;
    if (!finding_longest_word.is_open()) return 0;
    while(finding_longest_word >> word)
    {
        if (word.size() > max_word.size()) max_word = word;
    }
    std::cout << "the longest word in file is " << max_word << std::endl;
    finding_longest_word.close();


    return 0;
}