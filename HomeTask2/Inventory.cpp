//
// Created by Егор on 14.11.2026.
//

#include "Inventory.hpp"


std::ostream& operator<<(std::ostream& os, const InventoryItem& item) {
  os << item.inventoryId() << ' ' << item.name();
  return os;
}

bool operator<(const InventoryItem& item1, const InventoryItem& item2) {
  return item1.inventoryId() < item2.inventoryId();
}