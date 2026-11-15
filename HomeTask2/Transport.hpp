#pragma once
#include "Inventory.hpp"
#include <string>

class Transport : public InventoryItem {
public:
  Transport(const std::string& id, const std::string& nm, int score);

  std::string inventoryId() const override;
  std::string name() const override;

  bool forNovice() const override;

private:
  std::string id_;
  std::string name_;
  int score_;
};

class Scooter : public Transport, public EnergyConsumer {
public:
  Scooter(const std::string& id, const std::string& nm, double energy, int score);

  std::string describe() const override;
  double dailyEnergy() const override;
  double energy() const override;
  
private:
  double energy_;
};

class Bike : public Transport {
public:
  Bike(const std::string& id, const std::string& nm, int score);
  std::string describe() const override;

};

class Ebike : public Transport, public EnergyConsumer {
public:
  Ebike(const std::string& id, const std::string& nm, double energy, int score);

  double dailyEnergy() const override;
  std::string describe() const override;
  double energy() const override;

private:
  double energy_;
};

class NewTeslaRoadster : public Transport, public EnergyConsumer {
public:
  NewTeslaRoadster(const std::string& id, const std::string& nm, double energy, int score);

  double dailyEnergy() const override;
  std::string describe() const override;
  double energy() const override;

private:
  double energy_;
};
