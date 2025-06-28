#include "../include/Vehicule.h"


void Vehicule::print(std::ostream& os) const
{
    os << specs;
}


const VehiculeSpecs& Vehicule::getSpecs()
{
    return specs;
}


void Vehicule::display() const
{
    specs.display();
}


std::ostream& operator<<(std::ostream& os, const Vehicule& vehicule)
{
    vehicule.print(os);
    return os;
}
