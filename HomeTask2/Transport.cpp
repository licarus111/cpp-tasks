#include "Transport.hpp"

Transport::Transport(const std::string& id, const std::string& nm, int score) : id_(id), name_(nm), score_(score) {}

std::string Transport::inventoryId() const { return id_; }
std::string Transport::name() const { return name_; }

bool Transport::forNovice() const { return score_ >= 6; }




Scooter::Scooter(const std::string& id, const std::string& nm, double energy, int score) : Transport(id, nm, score), energy_(energy) {}

std::string Scooter::describe() const { return "Scooter"; }
double Scooter::dailyEnergy() const { return energy_; }
double Scooter::energy() const { return energy_; }




Bike::Bike(const std::string& id, const std::string& nm, int score) : Transport(id, nm, score) {}

std::string Bike::describe() const { return "Bike"; }


Ebike::Ebike(const std::string& id, const std::string& nm, double energy, int score) : Transport(id, nm, score), energy_(energy) {}

double Ebike::dailyEnergy() const { return energy_; }
std::string Ebike::describe() const { return "EBike"; }
double Ebike::energy() const {return dailyEnergy(); }




NewTeslaRoadster::NewTeslaRoadster(const std::string& id, const std::string& nm, double energy, int score) : Transport (id, nm, 1), energy_(energy) {}

double NewTeslaRoadster::dailyEnergy() const { return energy_; }
std::string NewTeslaRoadster::describe() const { return "NewTeslaRoadster"; }
double NewTeslaRoadster::energy() const {return dailyEnergy(); }



