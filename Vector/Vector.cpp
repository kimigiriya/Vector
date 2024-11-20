#include "Vector.h"
#include <iostream>
#include <locale.h>
#include <cstring>
#include <string>
#include <stdexcept>
#include <sstream>

using namespace std;


int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    std::cout << "Введите кол-во эл-тов для вектора: ";
    std::cin >> n;

    try {
        Vector<int> vector1_int(n);
        Vector<int> vector2_int(n);
        Vector<int> vector3_int(1);

        for (int i = 0; i < n; i++) {
            vector1_int.getData()[i] = i + 1;
            vector2_int.getData()[i] = (i + 1) * 10;
        }

        std::cout << "\n\tДля int\n";
        std::cout << "vector1 = " << vector1_int << "\n";
        std::cout << "vector2 = " << vector2_int << "\n";
        std::cout << "vector1 + vector2 = " << vector1_int + vector2_int << "\n";
        std::cout << "vector2 - vector1 = " << vector2_int - vector1_int << "\n";
        std::cout << "vector1 * vector2 = " << vector1_int * vector2_int << "\n";
        std::cout << "Введите vector3: ";
        std::cin >> vector3_int.getData()[0];
        std::cout << "vector3 = " << vector3_int << "\n";
        std::cout << "\n";

        //------------------------------------------------------------------------

        Vector<double> vector1_double(n);
        Vector<double> vector2_double(n);
        Vector<double> vector3_double(1);

        for (int i = 0; i < n; i++) {
            vector1_double.getData()[i] = (0.1 * i) + i + 1;
            vector2_double.getData()[i] = ((0.1 * i) + i + 1) * 10;
        }

        std::cout << "\n\tДля double\n";
        std::cout << "vector1 = " << vector1_double << "\n";
        std::cout << "vector2 = " << vector2_double << "\n";
        std::cout << "vector1 + vector2 = " << vector1_double + vector2_double << "\n";
        std::cout << "vector2 - vector1 = " << vector2_double - vector1_double << "\n";
        std::cout << "vector1 * vector2 = " << vector1_double * vector2_double << "\n";
        std::cout << "Введите vector3: ";
        std::cin >> vector3_double.getData()[0];
        std::cout << "vector3 = " << vector3_double << "\n";
        std::cout << "\n";

        //------------------------------------------------------------------------

        Vector<char> vector1_char(n);
        Vector<char> vector2_char(n);
        Vector<char> vector3_char(1);

        for (int i = 0; i < n; i++) {
            vector1_char.getData()[i] = 'A' + i; // 'A' = 65
            vector2_char.getData()[i] = ' ' + (i * 2); //' ' = 32
        }

        std::cout << "\n\tДля char\n";
        std::cout << "vector1 = " << vector1_char << "\n";
        std::cout << "vector2 = " << vector2_char << "\n";
        std::cout << "vector1 + vector2 = " << vector1_char + vector2_char << "\n";
        std::cout << "vector2 - vector1 = " << vector2_char - vector1_char << "\n";
        std::cout << "vector1 * vector2 = " << vector1_char * vector2_char << "\n";
        std::cout << "Введите vector3: ";
        std::cin >> vector3_char.getData()[0];
        std::cout << "vector3 = " << vector3_char << "\n";
        std::cout << "\n";

        //------------------------------------------------------------------------

        Vector<std::string> vector1_string(1);
        Vector<std::string> vector2_string(1);
        Vector<std::string> vector3_string(3);

        for (int i = 0; i < 1; i++) {
            vector1_string.getData()[i] = "Hello-hello";
            vector2_string.getData()[i] = "World";
        }

        std::cout << "\n\tДля string\n";
        std::cout << "vector1 = " << vector1_string << "\n";
        std::cout << "vector2 = " << vector2_string << "\n";
        std::cout << "vector1 + vector2 = " << vector1_string + vector2_string << "\n";
        std::cout << "Введите vector3: ";
        for (int i = 0; i < n; i++) {
            std::cin >> vector3_string.getData()[i];
        }
        std::cout << "vector3 = " << vector3_string << "\n";
        std::cout << "\n";

        // Случаи для исключений
        //std::cout << "vector1(3)int + vector3(1)int = " << vector1_int + vector3_int << "\n";
        //std::cout << "vector2 - vector1 = " << vector2_string - vector1_string << "\n";
        //std::cout << "vector1 * vector2 = " << vector1_string * vector2_string << "\n";
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}