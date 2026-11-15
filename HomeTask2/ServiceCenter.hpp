#pragma once
#include <algorithm>
#include <cctype>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "Inventory.hpp"
#include "Errors.hpp"
#include "Registry.hpp"
#include "Things.hpp"
#include "Transport.hpp"

class Park {
public:
  void addScooter(const std::string& id, const std::string& nm, double energy, int score);
  void addBike(const std::string& id, const std::string& nm, int score);
  void addEbike(const std::string& id, const std::string& nm, double energy, int score);
  void addHelmet(const std::string& id, const std::string& nm);
  void addDock(const std::string& id, const std::string& nm, double energy);

  double energy() const;

  void novice() const;

  void list();

  void focus(const std::string& id);

  void remove (const std::string& id);

  void showFocus();

  int countNovice() const;
private:
  std::vector<std::shared_ptr<InventoryItem>> service_;
  Registry<std::string, 1000> accIds_;
  std::weak_ptr<InventoryItem> focus_;

  void inspect(const Transport& t) const {
    std::string s = t.name();
    for (char& c : s) {
      c = std::tolower(c);
    }

    if (s.find("broken") != std::string::npos) {
      throw InspectionError();
    }
  }
  void checkId(const std::string& id) const {
    if (id.empty()) {
      throw CommandError("Bad ID, try again");
    }
  }
  void checkScore(int score) const {
    if (score < 1 || score > 10) {
      throw CommandError("Bad score, try again");
    }
  }
  void checkEnergy(double energy) const {
    if (energy < 0) {
      throw CommandError("Bad energy, try again");
    }
  }

  int find(const std::string& id) const{
    auto it = std::find_if(service_.begin(), service_.end(), [&](const auto& p) { return p->inventoryId() == id; });
    if (it == service_.end()) {
      throw CommandError("Bad ID, try again");
    }
    return it - service_.begin();
  }
};
