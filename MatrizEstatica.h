#include "MatrizBase.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <string>

template <typename T, int M, int N>
class MatrizEstatica;

template <typename T, int M, int N>
class MatrizEstatica : public MatrizBase<T>
{
    T _datos[M][N];

public:
    // constructor
    MatrizEstatica()
    {
        this->_filas = M;
        this->_columnas = N;
    };

    // Copy constructor
    MatrizEstatica(const MatrizEstatica &other)
    {
        // Asignar nuevos elementos
        this->_filas = other._filas;
        this->_columnas = other._columnas;

        // Copiar valores de la matriz
        for (int i = 0; i < this->_filas; i++)
        {
            for (int j = 0; j < this->_columnas; j++)
            {
                this->set(i, j, other.get(i, j));
            }
        }
    };

    // Copy operator
    MatrizEstatica &operator=(const MatrizEstatica &other)
    {
        if (this != &other)
        {
            // Asignar nuevos elementos
            this->_filas = other._filas;
            this->_columnas = other._columnas;

            // Copiar valores de la matriz
            for (int i = 0; i < this->_filas; i++)
            {
                for (int j = 0; j < this->_columnas; j++)
                {
                    this->set(i, j, other.get(i, j));
                }
            }
        }
        return *this;
    };

    void cargarValores() override
    {
        for (int i = 0; i < this->_filas; i++)
        {
            for (int j = 0; j < this->_columnas; j++)
            {
                std::string prompt = "[" + std::to_string(i) + "][" + std::to_string(j) + "]:";
                T value = this->getInput(prompt);
                this->set(i, j, value);
            }
        }
    };

    MatrizBase<T> *sumar(const MatrizBase<T> &other) const override
    {
        if (this->_filas != other.getFilas() || this->_columnas != other.getColumnas())
        {
            throw std::invalid_argument("Matrix addition requires matrices of the same dimensions.");
        }

        MatrizEstatica<T, M, N> *resultado = new MatrizEstatica<T, M, N>();

        for (int i = 0; i < this->_filas; i++)
        {
            for (int j = 0; j < this->_columnas; j++)
            {
                resultado->set(i, j, this->get(i, j) + other.get(i, j));
            }
        }
        return resultado;
    }

    void imprimir() const override
    {
        for (int i = 0; i < this->_filas; i++)
        {
            std::cout << "|";
            for (int j = 0; j < this->_columnas; j++)
            {
                std::cout << std::setw(6) << std::fixed << std::setprecision(2) << this->get(i, j) << "|";
            }
            std::cout << std::endl;
        }
    };

    void set(int i, int j, T value) override
    {
        this->_datos[i][j] = value;
    };

    T get(int i, int j) const override
    {
        return this->_datos[i][j];
    };
};