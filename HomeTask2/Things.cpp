#include "Things.hpp"

Thing::Thing(const std::string& id, const std::string& nm) : id_(id), name_(nm) {}
std::string Thing::inventoryId() const { return id_; }
std::string Thing::name() const { return name_; }


Helmet::Helmet(const std::string& id, const std::string& nm) : Thing(id, nm) {}
std::string Helmet::describe() const { return "Helmet"; }

Dock::Dock(const std::string& id, const std::string& nm, double energy) : Thing(id, nm), energy_(energy) {}
std::string Dock::describe() const { return "Dock"; }
double Dock::dailyEnergy() const { return energy_; }
double Dock::energy() const { return dailyEnergy(); }