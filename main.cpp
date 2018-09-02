#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int reverse_line(string & line);

int main()
{
    fstream file_from, file_to;
    string line;
    file_from.open("art.txt");
    file_to.open("reversed.txt");

    if (file_from.is_open() && file_to.is_open()) 
    {
        while (getline(file_from, line)) 
        {
            reverse_line(line);
            file_to << line;
            file_to << '\n';
        }
        file_from.close();
        file_to.close();
    }
    else
        cout << "Can't open file.\n";
}

int reverse_line(string & line) 
{
    int len = line.length();
 
    for (int i = 0; i < len / 2; ++i)
        swap(line[i], line[len-1-i]);
}