#include <iostream>
#include "MatrizBase.h"
#include "MatrizDinamica.h"
#include "MatrizEstatica.h"
#include <iomanip>

// Imprimir mensaje
void printMessage(const std::string msg);

int main()
{
    printMessage("--- Sistema gérico de Álgebra Lineal ---");
    printMessage(">> Demostración de Genericidad (Tipo FLOAT) <<");
    printMessage("// 1. Creación de Matriz Dinámica (a través del puntero base)");
    printMessage("Creando Matriz Dinámica A (3x2)...");

    MatrizBase<float> *A = new MatrizDinamica<float>(3, 2);
    printMessage("Llena la matriz A:");
    A->cargarValores();
    printMessage("Matriz A (3x2, Tipo FLOAT)");
    A->imprimir();

    printMessage("// 2. Creación de Matriz Estática (a través del puntero base)");
    printMessage("Creando Matriz Estática B (3x2)...");
    MatrizBase<float> *B = new MatrizEstatica<float, 3, 2>();
    printMessage("Llena la matriz B:");
    B->cargarValores();
    printMessage("Matriz B (3x2, Tipo FLOAT)");
    B->imprimir();

    printMessage("// 3. Operación Polimórfica (Suma)");
    printMessage("SUMANDO: Matriz C = A + B ...");
    MatrizBase<float> *C = *A + *B;

    printMessage("Matriz Resultado C (3x2, Tipo FLOAT)");
    C->imprimir();

    printMessage(">> Demostración de Genericidad (Tipo INT) <<");
    printMessage("// 1. Creación de Matriz Estática (a través del puntero base)");
    printMessage("Creando Matriz Estática D (3x2)...");

    MatrizBase<int> *D = new MatrizEstatica<int, 3, 2>();
    printMessage("Llena la matriz D:");
    D->cargarValores();
    printMessage("Matriz D (3x2, Tipo INT)");
    D->imprimir();

    printMessage("// 2. Creación de Matriz Dinámica (a través del puntero base)");
    printMessage("Creando Matriz Dinámica E (3x2)...");
    MatrizBase<int> *E = new MatrizDinamica<int>(3, 2);
    printMessage("Llena la matriz E:");
    E->cargarValores();
    printMessage("Matriz E (3x2, Tipo INT)");
    E->imprimir();

    printMessage("// 3. Operación Polimórfica (Suma)");
    printMessage("SUMANDO: Matriz F = D + E ...");
    MatrizBase<int> *F = *D + *E;
    printMessage("Matriz Resultado F (3x2, Tipo INT)");
    F->imprimir();

    printMessage(">> Demostración de Limpieza de Memoria <<");

    printMessage("Llamando al destructor de A...");
    printMessage("Liberando memoria de A (Matriz Dinámica)...");
    delete A;

    printMessage("Llamando al destructor de B...");
    printMessage("Liberando memoria de B (Matriz Estática)...");
    delete B;
    
    printMessage("Llamando al destructor de C...");
    printMessage("Liberando memoria de C (Matriz Dinámica)...");
    delete C;

    printMessage("Llamando al destructor de D...");
    printMessage("Liberando memoria de D (Matriz Estática)...");
    delete D;

    printMessage("Llamando al destructor de E...");
    printMessage("Liberando memoria de E (Matriz Dinámica)...");
    delete E;

    printMessage("Llamando al destructor de F...");
    printMessage("Liberando memoria de F (Matriz Estática)...");
    delete F;

    printMessage("Bye!");
    printMessage("Bye!");

    return 0;
}
void printMessage(const std::string msg)
{
    const std::string MENU_TOP_ROUND = "╭─────────────────────────────────────────────────────╮";
    const std::string MENU_BORDER = "│";
    const std::string MENU_BOT_ROUND = "╰─────────────────────────────────────────────────────╯";
    const int content_width = 50;
    std::cout << MENU_TOP_ROUND << std::endl;
    std::string formatted_msg = " " + msg + " ";
    std::cout << MENU_BORDER << std::left << std::setw(content_width) << formatted_msg << std::endl;
    std::cout << MENU_BOT_ROUND << std::endl;
}