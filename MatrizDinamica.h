#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <string>

template <typename T>
class MatrizDinamica;

template <typename T>
class MatrizDinamica : public MatrizBase<T>
{
    T **_datos = nullptr;

public:
    // constructor
    MatrizDinamica<T>(int f, int c) : _datos(createMatriz(f, c))
    {
        this->_filas = f;
        this->_columnas = c;
    };

    // destructor
    ~MatrizDinamica<T>()
    {
        deleteMatriz(this->_datos, this->_filas);
    };

    // Copy constructor
    MatrizDinamica<T>(const MatrizDinamica<T> &other)
    {
        // Asignar nuevos elementos
        this->_filas = other._filas;
        this->_columnas = other._columnas;
        this->_datos = this->copyMatriz(other._datos);
    };

    // Copy operator
    MatrizDinamica<T> &operator=(const MatrizDinamica<T> &other)
    {
        if (this != &other)
        {
            if (this->_datos != nullptr)
            {
                deleteMatriz(this->_datos);
            }
            // Asignar nuevos elementos
            this->_filas = other._filas;
            this->_columnas = other._columnas;
            this->_datos = this->copyMatriz(other._datos);
        }
        return *this;
    };

    // Move constructor
    MatrizDinamica<T>(MatrizDinamica<T> &&other) noexcept
    {
        // mover elementos
        this->_filas = other._filas;
        this->_columnas = other._columnas;
        this->_datos = other._datos;

        // insertar valores por defectos
        other._filas = 0;
        other._columnas = 0;
        other._datos = nullptr;
    };

    // Move operator
    MatrizDinamica<T> &operator=(MatrizDinamica<T> &&other) noexcept
    {
        if (this != &other)
        {

            // mover elementos
            this->_filas = other._filas;
            this->_columnas = other._columnas;
            this->_datos = other._datos;

            // insertar valores por defectos
            other._filas = 0;
            other._columnas = 0;
            other._datos = nullptr;
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
            throw std::invalid_argument("Cannot addition two matriz with differents sizes");
        }

        MatrizDinamica<T> *resultado = new MatrizDinamica<T>(this->_filas, this->_columnas);

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
    }

    T get(int i, int j) const override
    {
        return this->_datos[i][j];
    };

private:
    void deleteMatriz(T **&matriz, int f, int c = 0)
    {
        for (int i = 0; i < f; i++)
        {
            delete[] matriz[i];
        }
        delete[] matriz;
        matriz = nullptr;
    };

    T **createMatriz(int f, int c)
    {
        T **newMatriz = new T *[f];
        for (int i = 0; i < f; i++)
        {
            newMatriz[i] = new T[c];
            for (int j = 0; j < c; j++)
            {
                newMatriz[i][j] = 0;
            }
        }
        return newMatriz;
    }

    T **copyMatriz(T **matriz, int f, int c = 0)
    {
        T **newMatriz = new T *[f];
        for (int i = 0; i < f; i++)
        {
            newMatriz[i] = new T[c];
            for (int j = 0; j < c; j++)
            {
                newMatriz[i][j] = matriz[i][j];
            }
        }
        return newMatriz;
    }
};