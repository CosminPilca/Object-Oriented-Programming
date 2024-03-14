#include "Pilca_Cosmin_Problem0.h"
#include <stdexcept>

// tabel de conversie cu unitatile necesare de masura
std::map<std::string, double> Length::unit_conversion = {
        {"m", 1.0},
        {"km", 1000.0},
        {"cm", 0.01},
        {"mi", 1609.344},
};

Length::Length(double val, std::string un) : value(val), unit(un) {
    // Verificam daca unitatea este în tabel
    if (unit_conversion.find(un) == unit_conversion.end()) {
        throw std::invalid_argument("Unitatea nu este compatibila.");
    }
}

double Length::get_value() const {
    return value;
}

std::string Length::get_unit() const {
    return unit;
}

Length Length::add(const Length& other) const {
    if (unit != other.unit) {
        throw std::invalid_argument("Unitatile sunt diferite, nu pot fi diferite!");
    }
    return Length(value + other.value, unit);
}

Length Length::subtract(const Length& other) const {
    if (unit != other.unit) {
        throw std::invalid_argument("Unitatile nu pot fi diferite!.");
    }
    return Length(value - other.value, unit);
}

Length Length::scale(double factor) const {
    return Length(value * factor, unit);
}

Length Length::divide(double divisor) const {
    if (divisor == 0) {
        throw std::invalid_argument("Divizorul nu poate fi zero.");
    }
    return Length(value / divisor, unit);
}

std::string Length::text() const {
    return std::to_string(value) + " " + unit;
}

int Length::compare(const Length& other) const {
    if (unit != other.unit) {
        throw std::invalid_argument("Unitatile nu pot fi diferite!.");
    }
    if (value < other.value) return -1;
    if (value > other.value) return 1;
    return 0;
}

Length Length::convert_to(std::string new_unit) const {
    // Verifică dacă noua unitate este în tabelă
    if (unit_conversion.find(new_unit) == unit_conversion.end()) {
        throw std::invalid_argument("Unitatea nu este inclusa in tabel.");
    }
    double new_value = value * unit_conversion[unit] / unit_conversion[new_unit];
    return Length(new_value, new_unit);
}

Length::Length() {

}
