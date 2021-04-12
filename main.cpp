#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int main()
{

    int i = 0;
    int n = 0, n1 = 0;
    std::cout << "enter the number of numbers in the set a: ";
    std::cin >> n;
    if (std::cin.fail()) {
        std::cout << "Invalid value";
        std::exit(1);
    }

    std::cout << "enter the number of numbers in the set b: ";
    std::cin >> n1;
    if (std::cin.fail()) {
        std::cout << "Invalid value";
        std::exit(1);
    }

    int c, c1;
    int_set a(n), b(n1), res(0), res2(0);
    std::cout << "enter the first set:\n";
    for (i; i != n; i++) {
        std::cin >> c;
        if (std::cin.fail()) {
            std::cout << "Invalid value";
            std::exit(1);
        }
        a.set_val(c, i);
    }
    std::cout << "enter the second set:\n ";
    for (i = 0; i != n1; i++) {
        std::cin >> c1;
        if (std::cin.fail()) {
            std::cout << "Invalid value";
            std::exit(1);
        }
        b.set_val(c1, i);
    }
    std::cout << "a + b = ";
    a.obed(b, res);
    res.print();
    std::cout << "\na - b = ";
    a.razn(b, res2);
    res2.print();

    return 1;
}