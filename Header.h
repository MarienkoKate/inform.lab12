#ifndef A_H
#define A_H

class int_set {
private:
    size_t size;
    int* mas_val;
public:
    int_set(int s);

    void set_val(int val, int i);
    int serch(int val);
    void delit(int ind);
    void print();
    void sort();
    void obed(int_set& a, int_set& b);
    void razn(int_set& a, int_set& b);
    int_set& operator=(int_set& a);
    ~int_set();
};

#endif
