#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
//|добавление элемента|, |удаление элемента|, |проверка вхождени€ элемента|, |объединение множеств| и вычитание одного множества из другого
// объединение  123456 34567 результат 1234567, разность 123456 - 34567 = 12 (ищу общие элементы и убираю их из первого множества)
//сначала перебираю все варианты и создаю массив повтор€ющихс€ чисел и ищу их в первом множестве 


void int_set::sort()
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = (size - 1); j > i; j--) {

            if (mas_val[j - 1] > mas_val[j]) {

                int temp = mas_val[j - 1];
                mas_val[j - 1] = mas_val[j];
                mas_val[j] = temp;
            }
        }
    }
}
void int_set::razn(int_set& b, int_set& res) {
    int_set b_copy(b.size), a_copy(size);
    b_copy = (b);
    a_copy = (*this);
    //b_copy.sort(); a_copy.sort();
    int n = 0;
    int* new_mas = new int[100];
    int* mas_povt = new int[100];
    for (int i = 0; i != a_copy.size; i++) {
        for (int j = 0; j != b_copy.size; j++) {
            if (a_copy.mas_val[i] == b_copy.mas_val[j]) {
                a_copy.delit(i);
                b_copy.delit(j);
                j--;
                i--;
            }
        }
    }
    
    if (a_copy.size == 0 || size == 0) std::cout << "NULL";
    else res = (a_copy);


}

int_set& int_set :: operator=(int_set& a) {
     if (&a == this) {
         return *this;
        
    }
     delete[] mas_val;
     size = a.size;
     mas_val = new int[size];
     for (int i = 0; i < size; i++) {
         mas_val[i] = a.mas_val[i];
        
    }
     return *this;
    
}
void int_set::obed(int_set& b, int_set& c) {
    int_set b_copy(b.size), a_copy(size);
    b_copy = (b);
    a_copy = (*this);
    int* new_mas = new int[100];
    int* povt = new int[100];
    int n = 0;

    for (int i = 0; i != a_copy.size; i++) {
        for (int j = 0; j != b_copy.size; j++) {
            if (a_copy.mas_val[i] == b_copy.mas_val[j]) {
                povt[n++] = b_copy.mas_val[j];
                a_copy.delit(i);
                b_copy.delit(j);        
                j--;
                i--;
            }
        }
    }
    delete[] c.mas_val;
    c.mas_val = new int[a_copy.size + b_copy.size + n];
    int i = 0, g = 0;
    c.mas_val[0] = a_copy.mas_val[0];
    c.size = a_copy.size + b_copy.size + n;
    for (i = 0; i != a_copy.size; i++) 
        c.mas_val[i] = a_copy.mas_val[i];

    for (i = a_copy.size, g = 0; g != b_copy.size; i++, g++) 
        c.mas_val[i] = b_copy.mas_val[g];

    for (i = a_copy.size + b_copy.size, g = 0; g != n; i++, g++) 
        c.mas_val[i] = povt[g];

}

int int_set::serch(int val) {
    for (int i = 0; i != this->size; i++) {
        if (this->mas_val[i] == val) return i;
    }
    return -1;
}

void int_set::set_val(int val, int i) {
    this->mas_val[i] = val;
}

void int_set::delit(int ind) {

    for (int i = ind; i != size; i++) {
        mas_val[i] = this->mas_val[i + 1];
    }
    size--;
 
}

int_set::int_set(int s) {
    size = s;
    mas_val = new int[size];
}

int_set::~int_set() {
    delete[] mas_val;
}

void int_set::print() {
    for (int i = 0; i != this->size; i++) {
        std::cout << mas_val[i];
        std::cout << " ";
    }
}

