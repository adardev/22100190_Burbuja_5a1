#include <iostream>
#include <sstream>
using namespace std;

class MetodoBurbuja {
private:
    int* numeros;
    int numDatos;
    string preguntaIteracion;

    void intercambiar(int& a, int& b);
    void mostrarIteracion() const;

public:
    MetodoBurbuja();
    void ingresoDeDatos();
    void Burbuja();
    void imprimirArreglo() const;
};

void MetodoBurbuja::intercambiar(int& a, int& b) {
    int i = a;
    a = b;
    b = i;
}

void MetodoBurbuja::mostrarIteracion() const {
    for (int i = 0; i < numDatos; ++i) {
        cout << numeros[i];
        if (i != numDatos - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

MetodoBurbuja::MetodoBurbuja() {}

void MetodoBurbuja::ingresoDeDatos() {
    cout << "METODO DE ORDENACION POR BURBUJA" << endl;
    cout << "Ingresa cuantos datos quieres ordenar: ";
    cin >> numDatos;
    cin.ignore(); // limpiar el buffer del salto de línea

    numeros = new int[numDatos];

    cout << "Ingresa los datos separados por espacios: ";
    string entrada;
    getline(cin, entrada);

    istringstream stream(entrada); // convierte este string a un stream
    int numero;
    int numNumeros = 0; // para ver la cantidad de datos que se ingresaron y poder compararlos

    while (stream >> numero && numNumeros < numDatos) {
        numeros[numNumeros] = numero;
        numNumeros++;
    }

    // Si no hay los datos que el usuario dijo
    if (numNumeros < numDatos) {
        cout << "Faltan datos" << endl;
        numDatos = numNumeros;
    }

    cout << "Quieres ver cada iteracion?";
    cin >> preguntaIteracion;

    // Convertir a minúsculas
    for (char& c : preguntaIteracion) {
        c = tolower(c);
    }
}

void MetodoBurbuja::Burbuja() {
    for (int i = 0; i < numDatos - 1; ++i) {
        for (int j = 0; j < numDatos - i - 1; ++j) {
            if (numeros[j] > numeros[j + 1]) {
                intercambiar(numeros[j], numeros[j + 1]);
            }
        }
        // Mostrar iteración aquí
        if (preguntaIteracion == "si") {
            mostrarIteracion();
        }
    }
}

void MetodoBurbuja::imprimirArreglo() const {
    for (int i = 0; i < numDatos; ++i) {
        cout << numeros[i] << " ";
    }
}

int main() {
    MetodoBurbuja ordenamiento;
    ordenamiento.ingresoDeDatos();
    ordenamiento.Burbuja();

    cout << endl;
    ordenamiento.imprimirArreglo();

    return 0;
}
