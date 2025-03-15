#include <iostream>
#include "Polynomials.h" 


int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "\n	Привет!!! Эта программа позволит вам выполнять операции над многочленами.\n" << \
        " При вводе многочлена, пожалуйста, следуйте некоторым правилам:\n";
    std::cout << " 1) Введите многочлен без пробелов\n" << \
        " 2) В многочлене допускаются только 3 переменные: x, y и z\n" << \
        " 3) Одночлены записываются в любом порядке\n" << \
        " 4) Степень каждой переменной в одночлене от 0 до 9\n" << \
        " 5) После ввода многочлена нажмите Enter\n\n";
    std::cout << "Выберите действие, которое вы хотите выполнить с многочленами\n" << \
        " 1. Сложить два многочлена\n" << \
        " 2. Вычесть два многочлена\n" << \
        " 3. Умножить два многочлена\n" << \
        " 4. Умножить многочлен на число\n" << \
        " 5. Найти количество одночленов в многочлене\n" << \
        " 6. Выход\n";

    int item;
    std::cin >> item;
    while (item != 6) {
        if (item == 1 || item == 2 || item == 3) {
            std::cout << " Введите два многочлена:\n";

            std::string s1, s2;
            std::cin >> s1 >> s2;
            try {
                polynomial p1(s1), p2(s2);

                if (item == 1) {
                    p1 += p2;
                }
                else {
                    if (item == 2) p1 -= p2;
                    else p1 *= p2;
                }
                p1.print();
            }
            catch (const std::string& e) {
                std::cout << e << std::endl;
                std::cout << " Пожалуйста, попробуйте еще раз:\n";
            }
        }
        if (item == 4 || item == 5) {
            try {
                std::cout << "Введите многочлен\n";
                std::string s;
                std::cin >> s;
                polynomial p(s);

                if (item == 4) {
                    std::cout << "Введите число (double)\n";
                    double m;
                    std::cin >> m;

                    p *= m;
                    p.print();
                }
                else
                    std::cout << p.get_count() << '\n';

            }
            catch (const std::string& e) {
                std::cout << e << std::endl;
                std::cout << " Пожалуйста, попробуйте еще раз:\n";
            }
        }
        std::cout << "Введите пункт\n";
        std::cin >> item;
    }
    return 0;
}