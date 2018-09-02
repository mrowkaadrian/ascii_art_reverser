// DISCLAIMER: All of the lines MUST have the same amount of characters - you need to fill 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void reverse_line(string & line);
void reverse_characters(string & line);
void mirror(char & x);

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
            reverse_characters(line);
            file_to << line;
            file_to << '\n';
        }
        file_from.close();
        file_to.close();
        cout << "Reverse completed.\n";
    }
    else
        cout << "Can't open file.\n";
}

void reverse_line(string & line) 
{
    int len = line.length();
 
    for (int i = 0; i < len / 2; ++i)
        swap(line[i], line[len-1-i]);
}

void reverse_characters(string & line)
{
    int len = line.length();

    for (int i = 0; i < len; ++i)
        mirror(line[i]);
}

void mirror (char & x) // THIS IS REALLY POOR CODE, IF YOU HAVE ANY IDEAS, TELL ME
{
    switch(x)
    {
    case '/':
        x = '\\';
        break;
    case '\\':
        x = '/';
        break;
    case '(':
        x = ')';
        break;
    case ')':
        x = '(';
        break;
    case '<':
        x = '>';
        break;     
    case '>':
        x = '<';
        break;
    case '[':
        x = ']';
        break;
    case ']':
        x = '[';
        break;
    case '{':
        x = '}';
        break;
    case '}':
        x = '{';
        break;
    case 'b':
        x = 'd';
        break;
    case 'd':
        x = 'b';
        break;
    default:
        break;       
    }
}