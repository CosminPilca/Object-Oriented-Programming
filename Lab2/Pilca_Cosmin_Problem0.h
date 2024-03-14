#include <string>
#include <map>

class Length {
private:
    double value; // Valoarea lungimii
    std::string unit; // Unitatea de masura (km,cm,mi,m)
    static std::map<std::string, double> unit_conversion;

public:
    Length(double val, std::string un); // Constructor
    double get_value() const; // Aici obtinem valoarea lungimii
    std::string get_unit() const; // Aici obtinem unitatea dorita
    Length add(const Length& other) const; // Adunam cele doua lungimi
    Length subtract(const Length& other) const; // Scadem cele doua lungimi
    Length scale(double factor) const; // Inmultim lungimea cu un factor
    Length divide(double divisor) const; // Impartim lungimea la un divizor
    std::string text() const; // Reprezentarea ca sir de caractere
    int compare(const Length& other) const; // Comparam cele doua lungimi
    Length convert_to(std::string new_unit) const; // Facem conversia la o noua unitate
    Length();
};

