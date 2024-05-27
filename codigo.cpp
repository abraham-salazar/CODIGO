#include <iostream>

using namespace std;

// Función para fusionar dos partes ordenadas de un arreglo
void fusionarPartes(int lista[], int inicio, int mitad, int fin) {
    // Calcula las longitudes de las dos partes
    int n1 = mitad - inicio + 1; // Tamaño de la parte izquierda
    int n2 = fin - mitad;        // Tamaño de la parte derecha

    // Crea arreglos temporales para almacenar las dos partes
    int izquierda[n1], derecha[n2];

    // Copia los elementos de la lista original a los arreglos temporales
    for (int i = 0; i < n1; i++)
        izquierda[i] = lista[inicio + i]; // Copia los elementos de la parte izquierda
    for (int j = 0; j < n2; j++)
        derecha[j] = lista[mitad + 1 + j]; // Copia los elementos de la parte derecha

    // Fusiona las dos partes ordenadas en la lista original
    int i = 0, j = 0, k = inicio; // Índices para recorrer los arreglos temporales y la lista original
    while (i < n1 && j < n2) {
        if (izquierda[i] <= derecha[j]) {
            lista[k] = izquierda[i]; // Si el elemento de la izquierda es menor, lo agrega a la lista original
            i++;
        } else {
            lista[k] = derecha[j]; // Si el elemento de la derecha es menor, lo agrega a la lista original
            j++;
        }
        k++;
    }

    // Copia los elementos restantes de los arreglos temporales a la lista original
    while (i < n1) {
        lista[k] = izquierda[i];
        i++;
        k++;
    }
    while (j < n2) {
        lista[k] = derecha[j];
        j++;
        k++;
    }
}

// Función principal de ordenación por mezcla directa
void ordenarLista(int lista[], int inicio, int fin) {
    if (inicio < fin) {
        // Encuentra el punto medio de la lista
        int mitad = inicio + (fin - inicio) / 2;

        // Ordena recursivamente las dos mitades
        ordenarLista(lista, inicio, mitad);        // Ordena la parte izquierda
        ordenarLista(lista, mitad + 1, fin);       // Ordena la parte derecha

        // Fusiona las dos mitades ordenadas
        fusionarPartes(lista, inicio, mitad, fin); // Fusiona las partes izquierda y derecha
    }
}

int main() {
    // Lista de ejemplo
    int lista[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(lista) / sizeof(lista[0]); // Calcula el tamaño de la lista

    // Imprime la lista original
    cout << "Lista original:" << endl;
    for (int i = 0; i < n; i++)
        cout << lista[i] << " ";
    cout << endl;

    // Ordena la lista
    ordenarLista(lista, 0, n - 1);

    // Imprime la lista ordenada
    cout << "Lista ordenada:" << endl;
    for (int i = 0; i < n; i++)
        cout << lista[i] << " ";
    cout << endl;

    return 0;
}
