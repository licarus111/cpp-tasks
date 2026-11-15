#include "ServiceCenter.hpp"


void Park::addScooter(const std::string& id, const std::string& nm, double energy, int score) {
  checkId(id);
  checkScore(score);
  checkEnergy(energy);
  auto item = std::make_unique<Scooter>(id, nm, energy, score);
  inspect(*item);
  accIds_.add(id);
  service_.push_back(std::move(item));
}
void Park::addBike(const std::string& id, const std::string& nm, int score) {
  checkId(id);
  checkScore(score);
  auto item = std::make_unique<Bike>(id, nm, score);
  inspect(*item);
  accIds_.add(id);
  service_.push_back(std::move(item));
}
void Park::addEbike(const std::string& id, const std::string& nm, double energy, int score) {
  checkId(id);
  checkScore(score);
  checkEnergy(energy);
  auto item = std::make_unique<Ebike>(id, nm, energy, score);
  inspect(*item);
  accIds_.add(id);
  service_.push_back(std::move(item));
}
void Park::addHelmet(const std::string& id, const std::string& nm) {
  checkId(id);
  auto item = std::make_unique<Helmet>(id, nm);
  service_.push_back(std::move(item));
}
void Park::addDock(const std::string& id, const std::string& nm, double energy) {
  checkId(id);
  checkEnergy(energy);
  auto item = std::make_unique<Dock>(id, nm, energy);
  service_.push_back(std::move(item));
}

double Park::energy() const {
  double ans = 0;
  for (const auto& item : service_) {
    ans += (*item).energy();
  }
  return ans;
}

void Park::novice() const {
  for (const auto& item : service_) {
    if ((*item).forNovice()) {
      std::cout << *item << '\n';
    }
  }
}

void Park::list() {
  std::sort(service_.begin(), service_.end(), [](const auto& a, const auto& b) { return *a < *b; });
  for (const auto& item : service_) {
    std::cout << *item << '\n';
  }
}

void Park::focus(const std::string& id) {
  focus_ = service_[find(id)];
}

void Park::remove (const std::string& id) {
  service_.erase(service_.begin() + find(id));
}

void Park::showFocus() {
  if (auto p = focus_.lock()) {
    std::cout << *p << '\n';
  } else {
    std::cout << "removed" << '\n';
  }
}

int Park::countNovice() const {
  int ans = 0;
  for (const auto& item : service_) {
    if (item->forNovice()) {
      ++ans;
    }
  }
  return ans;
}