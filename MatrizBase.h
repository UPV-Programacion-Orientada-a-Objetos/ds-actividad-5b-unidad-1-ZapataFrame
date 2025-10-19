#ifndef MATRIZBASE_H
#define MATRIZBASE_H

#include <iostream>
#include <string>

template <typename T>
class MatrizBase
{
protected:
    int _filas;
    int _columnas;

public:
    virtual ~MatrizBase() = default;

    virtual void cargarValores() = 0;
    virtual MatrizBase<T> *sumar(const MatrizBase<T> &otra) const = 0;
    virtual void imprimir() const = 0;

    virtual void set(int i, int j, T value) = 0;

    virtual T get(int i, int j) const = 0;

    int getFilas() const { return _filas; }
    int getColumnas() const { return _columnas; }

    T getInput(const std::string prompt)
    {
        T input;
        std::cout << prompt;
        while (!(std::cin >> input))
        {
            std::cout << "Ingrese un input valido!" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << prompt;
        }
        std::cin.ignore(10000, '\n');
        return input;
    }
};

#endif