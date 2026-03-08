#include <iostream>
#include <fstream>


int main()
{
    std::ofstream file("text.txt");
    if (!file) 
    {
        std::cout << "File not opened" << std::endl; 
        return 1;
    }

    file << "Hello" << std::endl;
    file << "This is my first file" << std::endl;
    file << "C++ is cool" << std::endl; 

    file.close();
    return 0;
}