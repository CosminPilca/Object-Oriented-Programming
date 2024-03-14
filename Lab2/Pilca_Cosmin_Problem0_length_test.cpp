#include "Pilca_Cosmin_Problem0.h"
#include <iostream>
#include <string>

int main() {
    //Citim lungimile si numarul pentru inmultire/impartire
    double val1, val2, factor;
    std::string unit1, unit2;

    std::cout << "Introdu prima lungime si unitatea dorita:  ";
    std::cin >> val1 >> unit1;

    std::cout << "Introdu a doua lungime si unitatea dorita ";
    std::cin >> val2 >> unit2;

    std::cout << "Introdu un numar la care se va efectua inmultirea si impartirea: ";
    std::cin >> factor;

    try {
        // Crearea obiectelor Length
        Length len1(val1, unit1);
        Length len2(val2, unit2);
        Length result;

        // Test adunare
        result = len1.add(len2);
        std::cout << "Lungimile adunate: " << result.text() << std::endl;

        // Test scadere
        result = len1.subtract(len2);
        std::cout << "Lungimile scazute: " << result.text() << std::endl;

        // Test inmultire
        result = len1.scale(factor);
        std::cout << "Inmultirea primei lungimi cu divizorul dat: " << result.text() << std::endl;

        // Test impartire
        result = len1.divide(factor);
        std::cout << "Impartirea priemi lungimi cu divizorul dat: " << result.text() << std::endl;

        // Test comparare
        int comp_result = len1.compare(len2);
        std::cout << "Lungimile comparate: " << (comp_result == 0 ? "Lungimile sunt egale" : (comp_result > 0 ? "Prima lungime este mai mare ca a doua" : "Prima lungime este mai mica decat a doua")) << std::endl;

        // Test conversie
        std::string new_unit;
        std::cout << "Introduceti unitatea dorita pentru schimbare:   ";
        std::cin >> new_unit;
        result = len1.convert_to(new_unit);
        std::cout << "Unitatea a fost schimbata la " << new_unit << ": " << result.text() << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Eroare: " << e.what() << std::endl;
    }

    return 0;
}
