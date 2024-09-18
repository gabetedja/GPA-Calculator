
// Programmer Name: Gabriel Tedja
// Programmer ID: 2029312
// File: Calculations.cpp
#include "pch.h"
#include "Calculations.h"
#include <vector>


double Calculations::numberToGradePoints(double grade) {
    if (grade >= 90.0) {
        return 4.0; // A
    }
    else if (grade >= 80.0) {
        return 3.0; // B
    }
    else if (grade >= 70.0) {
        return 2.0; // C
    }
    else if (grade >= 60.0) {
        return 1.0; // D
    }
    else {
        return 0.0; // F
    }
}