#include "ElectricVehiculeSpecs.h"


int ElectricVehiculeSpecs::getAutonomy() const
{
    return autonomy;
}


void ElectricVehiculeSpecs::print(std::ostream& os) const
{
    os << std::setw(15) << getBrand() << " | "
        << std::setw(8) << getModel() << " | "
        << std::setw(20) << getMileAge() << " | "
        << std::setw(20) << (isBooked() ? "Yes" : "No") << " | "
        << std::setw(20) << autonomy << " | ";
}


void ElectricVehiculeSpecs::display() const
{
    std::cout << std::left << std::setw(15) << "Brand" << " | "
        << std::setw(8) << "Model" << " | "
        << std::setw(20) << "Mileage" << " | "
        << std::setw(20) << "Booked" << " | "
        << std::setw(20) << "Autonomy" << "\n"
        << "---------------------------------------------------------" <<
        std::endl;
    std::cout << *this << std::endl;
}


std::ostream& operator<<(std::ostream& os, const ElectricVehiculeSpecs& specs)
{
    specs.print(os);
    return os;
}
