#pragma once
#include <string>
#include<iostream>

class InventoryItem {
public:
  virtual std::string inventoryId() const = 0;
  virtual std::string name() const = 0;
  virtual std::string describe() const = 0;

  virtual ~InventoryItem() = default;

  virtual double energy() const { return 0; }

  virtual bool forNovice() const { return false; }
};

class EnergyConsumer {
public:
  virtual double dailyEnergy() const = 0;

  virtual ~EnergyConsumer() = default;
};



std::ostream& operator<<(std::ostream& os, const InventoryItem& item);

bool operator<(const InventoryItem& item1, const InventoryItem& item2);