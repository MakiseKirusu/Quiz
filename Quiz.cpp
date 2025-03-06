#include <iostream>
#include <fstream>
#include <complex>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ifstream input("In.txt");
    if (!input) {
        cerr << "Error: Could not open file In.txt" << endl;
        return 1;
    }

    int n;
    input >> n;

    // Allocate an array for n complex numbers
    complex<double>* data = new complex<double>[n];

    // Read the complex numbers from the file
    for (int i = 0; i < n; ++i) {
        double real, imag;
        input >> real >> imag;
        data[i] = complex<double>(real, imag);
    }
    input.close();

    // Sort the array in descending order based on magnitude
    sort(data, data + n, [](const complex<double>& a, const complex<double>& b) {
        return abs(a) > abs(b);
    });

    // Determine the number of values to output (5 or fewer)
    int count = (n < 5) ? n : 5;
    for (int i = 0; i < count; ++i) {
        cout << "Complex number: " << data[i]
             << " with magnitude: " << abs(data[i]) << "\n";
    }

    // Free the allocated memory
    delete[] data;
    return 0;
}
