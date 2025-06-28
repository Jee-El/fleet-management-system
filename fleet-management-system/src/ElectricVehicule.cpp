#include "ElectricVehicule.h"


void ElectricVehicule::print(std::ostream& os) const
{
    os << specs;
}


const ElectricVehiculeSpecs& ElectricVehicule::getSpecs()
{
    return specs;
}


void ElectricVehicule::display() const
{
    specs.display();
}


std::ostream& operator<<(std::ostream& os, const ElectricVehicule& eVehicule)
{
    eVehicule.print(os);
    return os;
}
