#include "VehiculeSpecs.h"


const std::string& VehiculeSpecs::getBrand() const
{
    return brand;
}


const std::string& VehiculeSpecs::getModel() const
{
    return model;
}


unsigned int VehiculeSpecs::getMileAge() const
{
    return mileAge;
}


bool VehiculeSpecs::isBooked() const
{
    return booked;
}


void VehiculeSpecs::display() const
{
    std::cout << std::left << std::setw(15) << "Brand" << " | "
    << std::setw(8) << "Model" << " | "
    << std::setw(20) << "Mileage" << " | "
    << std::setw(20) << "Booked" << " | "
    << std::setw(20) << "Autonomy" << "\n"
    << "---------------------------------------------------------" << std::endl;
    std::cout << *this << std::endl; 
}


void VehiculeSpecs::print(std::ostream& os) const
{
    os << std::setw(15) << brand << " | "
    << std::setw(8) << model << " | "
    << std::setw(20) << mileAge << " | "
    << std::setw(20) << (booked ? "Yes" : "No") << " | "
    << std::setw(20) << "Unavailable" << " | ";
}


std::ostream& operator<<(std::ostream& os, const VehiculeSpecs& specs)
{
    specs.print(os); 
    return os;
}