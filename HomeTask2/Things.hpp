#pragma once
#include "Inventory.hpp"
#include <string>

class Thing : public InventoryItem {
public:
  Thing(const std::string& id, const std::string& nm);
  std::string inventoryId() const override;
  std::string name() const override;

private:
  std::string id_;
  std::string name_;

};

class Helmet : public Thing {
public:
  Helmet(const std::string& id, const std::string& nm);
  std::string describe() const override;
};

class Dock : public Thing, public EnergyConsumer {
public:
  Dock(const std::string& id, const std::string& nm, double energy);
  std::string describe() const override;
  double dailyEnergy() const override;
  double energy() const override;

private:
  double energy_;
};



