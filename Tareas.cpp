#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Tarea {
    int indice;
    int beneficio;
    int plazo;
};

// Función de comparación para ordenar en orden descendente por beneficio
bool compararPorBeneficio(const Tarea& t1, const Tarea& t2) {
    return t1.beneficio > t2.beneficio;
}

void seleccionarTareas(vector<Tarea>& tareas) {
    sort(tareas.begin(), tareas.end(), compararPorBeneficio);

    vector<bool> tiempoOcupado(tareas.size(), false);

    int beneficioTotal = 0;

    for (const Tarea& tarea : tareas) {
        for (int i = min(tarea.plazo - 1, static_cast<int>(tareas.size()) - 1); i >= 0; i--) {
            if (!tiempoOcupado[i]) {
                tiempoOcupado[i] = true;
                beneficioTotal += tarea.beneficio;
                break;
            }
        }
    }

    // Imprimir el beneficio total y las tareas seleccionadas
    cout << "Beneficio total: " << beneficioTotal << endl;
    cout << "Tareas seleccionadas: ";
    for (const Tarea& tarea : tareas) {
        if (tiempoOcupado[tarea.plazo - 1]) {
            cout << tarea.indice << " ";
        }
    }
    cout << endl;
}

int main() {
    vector<Tarea> tareas = {
        {1, 50, 2},
        {2, 10, 1},
        {3, 15, 2},
        {4, 30, 1}
    };

    seleccionarTareas(tareas);

    return 0;
}
