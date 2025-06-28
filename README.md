# fleet-management-system

# Enterprise Fleet Manager in C++

A C++ application designed to manage vehicle fleets for multiple companies. The system includes support for company and CEO management, employee and HR operations, as well as handling both traditional and electric vehicles with associated specifications.

## 🧠 What I Learned

During this project, I deepened my understanding of core C++ concepts, including:

- Object-oriented programming with classes and inheritance
- Resource management and the Rule three/five/zero
- Use of smart pointers (`std::unique_ptr`, `std::shared_ptr`) for safe memory management
- Template programming basics to write generic and reusable code
- Proper header organization and forward declarations to handle dependencies
- Separation of interface (`.h` files) and implementation (`.cpp` files)
- Design of complex systems using modular classes representing real-world entities (companies, fleets, vehicles, employees)

This project was a practical application of these concepts, reinforcing best practices in modern C++ development.

## 📁 Project Structure

### Key Components

- **Company & CEO**
    - `Company` — Represents a company and its attributes.
    - `CEO` — Defines the CEO entity with associated responsibilities.
    - `CompanyBusinessCard` — Encapsulates business identity and contact details.

- **Employees**
    - `Employee` — Base class for employees.
    - `EmployeeIDCard` — Unique identification for employees.
    - `HRManager` — Specialized employee handling human resources tasks.

- **Fleet Management**
    - `Fleet` — Represents the collection of vehicles a company owns.
    - `FleetManager` — Handles operations related to vehicle assignment and fleet maintenance.

- **Vehicles**
    - `Vehicule` — Base vehicle class (traditional spelling kept if intentional).
    - `VehiculeSpecs` — Technical details for regular vehicles.
    - `ElectricVehicule` — Inherits from `Vehicule`, representing electric vehicles.
    - `ElectricVehiculeSpecs` — Electric-specific specs (battery, range, etc.).

- **Miscellaneous**
    - `ForwardDeclarations` — Resolves circular dependencies and improves compilation time.