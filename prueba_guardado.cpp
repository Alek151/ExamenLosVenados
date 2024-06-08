#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Alumno {
    string carne;
    string nombre;
    int edad;
    char sexo;
    int matematica;
    int ciencias;
    int computacion;
    int fisica;
    int idioma;
    int literatura;
};

vector<Alumno> alumnos;

// Función para ingresar los datos de los alumnos
void ingresarDatos() {
    alumnos.push_back({"18-00001", "Juan López", 19, 'M', 73, 65, 78, 91, 82, 73});
    alumnos.push_back({"18-00002", "Carlos Suarez", 20, 'M', 54, 61, 67, 42, 69, 70});
    alumnos.push_back({"18-00003", "Karla Sánchez", 18, 'F', 90, 88, 85, 78, 94, 79});
    alumnos.push_back({"18-00004", "Ana Perez", 19, 'F', 35, 58, 63, 67, 61, 52});
    alumnos.push_back({"18-00005", "José Juárez", 22, 'M', 62, 59, 68, 62, 65, 71});
    alumnos.push_back({"18-00006", "Daniel Pérez", 21, 'M', 67, 75, 86, 76, 72, 86});
    alumnos.push_back({"18-00007", "Deina Ovando", 19, 'F', 57, 64, 61, 69, 71, 63});
    alumnos.push_back({"18-00008", "Orlando Xu", 17, 'M', 82, 83, 78, 75, 89, 95});
    alumnos.push_back({"18-00009", "Miguel Perez", 20, 'M', 78, 82, 72, 65, 69, 81});
    alumnos.push_back({"18-00010", "Alex Carrillo", 24, 'M', 49, 62, 69, 72, 75, 79});
}


void contarSexo() {
    int hombres = 0, mujeres = 0;
    for (const auto& alumno : alumnos) {
        if (alumno.sexo == 'M') hombres++;
        else if (alumno.sexo == 'F') mujeres++;
    }
    cout << "Hombres: " << hombres << ", Mujeres: " << mujeres << endl;
}

void alumnoMasJoven() {
    int edadMinima = numeric_limits<int>::max();
    vector<string> masJovenes;
    for (const auto& alumno : alumnos) {
        if (alumno.edad < edadMinima) {
            edadMinima = alumno.edad;
            masJovenes.clear();
            masJovenes.push_back(alumno.nombre);
        } else if (alumno.edad == edadMinima) {
            masJovenes.push_back(alumno.nombre);
        }
    }
    cout << "Alumno(s) mas joven(es): ";
    for (const auto& nombre : masJovenes) {
        cout << nombre << " ";
    }
    cout << endl;
}

void clasesReprobadasCarlosSuarez() {
    int reprobadas = 0;
    for (const auto& alumno : alumnos) {
        if (alumno.nombre == "Carlos Suarez") {
            if (alumno.matematica < 61) reprobadas++;
            if (alumno.ciencias < 61) reprobadas++;
            if (alumno.computacion < 61) reprobadas++;
            if (alumno.fisica < 61) reprobadas++;
            if (alumno.idioma < 61) reprobadas++;
            if (alumno.literatura < 61) reprobadas++;
        }
    }
    cout << "Carlos Suarez ha reprobado " << reprobadas << " clases." << endl;
}

void alumnosQueAprobaronTodo() {
    cout << "Alumnos que aprobaron todos los cursos: ";
    for (const auto& alumno : alumnos) {
        if (alumno.matematica >= 61 && alumno.ciencias >= 61 && alumno.computacion >= 61 &&
            alumno.fisica >= 61 && alumno.idioma >= 61 && alumno.literatura >= 61) {
            cout << alumno.nombre << " ";
        }
    }
    cout << endl;
}

void alumnoConPromedioMasAlto() {
    double promedioMaximo = 0;
    vector<string> mejoresAlumnos;
    for (const auto& alumno : alumnos) {
        double promedio = (alumno.matematica + alumno.ciencias + alumno.computacion +
                           alumno.fisica + alumno.idioma + alumno.literatura) / 6.0;
        if (promedio > promedioMaximo) {
            promedioMaximo = promedio;
            mejoresAlumnos.clear();
            mejoresAlumnos.push_back(alumno.nombre);
        } else if (promedio == promedioMaximo) {
            mejoresAlumnos.push_back(alumno.nombre);
        }
    }
    cout << "Alumno(s) con el promedio más alto: ";
    for (const auto& nombre : mejoresAlumnos) {
        cout << nombre << " ";
    }
    cout << endl;
}

void alumnoConPromedioMasBajo() {
    double promedioMinimo = numeric_limits<double>::max();
    vector<string> peoresAlumnos;
    for (const auto& alumno : alumnos) {
        double promedio = (alumno.matematica + alumno.ciencias + alumno.computacion +
                           alumno.fisica + alumno.idioma + alumno.literatura) / 6.0;
        if (promedio < promedioMinimo) {
            promedioMinimo = promedio;
            peoresAlumnos.clear();
            peoresAlumnos.push_back(alumno.nombre);
        } else if (promedio == promedioMinimo) {
            peoresAlumnos.push_back(alumno.nombre);
        }
    }
    cout << "Alumno(s) con el promedio más bajo: ";
    for (const auto& nombre : peoresAlumnos) {
        cout << nombre << " ";
    }
    cout << endl;
}

void promedioCursoMatematicas() {
    double sumaMatematicas = 0;
    for (const auto& alumno : alumnos) {
        sumaMatematicas += alumno.matematica;
    }
    double promedio = sumaMatematicas / alumnos.size();
    cout << "Promedio del curso de Matemáticas: " << promedio << endl;
}

void mejorPromedioMatCompFisica() {
    double mejorPromedioHombre = 0, mejorPromedioMujer = 0;
    string mejorHombre, mejorMujer;
    for (const auto& alumno : alumnos) {
        double promedio = (alumno.matematica + alumno.computacion + alumno.fisica) / 3.0;
        if (alumno.sexo == 'M' && promedio > mejorPromedioHombre) {
            mejorPromedioHombre = promedio;
            mejorHombre = alumno.nombre;
        } else if (alumno.sexo == 'F' && promedio > mejorPromedioMujer) {
            mejorPromedioMujer = promedio;
            mejorMujer = alumno.nombre;
        }
    }
    cout << "Hombre con el mayor promedio en Matemáticas, Computación y Física: " << mejorHombre << endl;
    cout << "Mujer con el mayor promedio en Matemáticas, Computación y Física: " << mejorMujer << endl;
}

void alumnoQueReproboMasCursos() {
    int maxReprobadas = 0;
    string alumnoMaxReprobadas;
    for (const auto& alumno : alumnos) {
        int reprobadas = 0;
        if (alumno.matematica < 61) reprobadas++;
        if (alumno.ciencias < 61) reprobadas++;
        if (alumno.computacion < 61) reprobadas++;
        if (alumno.fisica < 61) reprobadas++;
        if (alumno.idioma < 61) reprobadas++;
        if (alumno.literatura < 61) reprobadas++;
        if (reprobadas > maxReprobadas) {
            maxReprobadas = reprobadas;
            alumnoMaxReprobadas = alumno.nombre;
        }
    }
    cout << "Alumno que reprobó mas cursos: " << alumnoMaxReprobadas << " (" << maxReprobadas << " cursos reprobados)" << endl;
}

int main() {
    ingresarDatos();
    cout << "Estadísticas de los cursos del Colegio 'Los Venados'" << endl;
    contarSexo();
    alumnoMasJoven();
    clasesReprobadasCarlosSuarez();
    alumnosQueAprobaronTodo();
    alumnoConPromedioMasAlto();
    alumnoConPromedioMasBajo();
    promedioCursoMatematicas();
    mejorPromedioMatCompFisica();
    alumnoQueReproboMasCursos();
    return 0;
}

