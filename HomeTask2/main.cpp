#include <iostream>
#include <sstream>
#include <iomanip>
#include "ServiceCenter.hpp"

void checkSize(const std::vector<std::string>& args, int n) {
  if (args.size() > n) {
    throw CommandError("Too many arguments");
  }
  if (args.size() < n) {
    throw CommandError("Not enough arguments");
  }
}

int main() {
  Park park;
  std::string line;
  while (std::getline(std::cin, line)) {
    std::istringstream in(line);
    std::vector<std::string> args;
    std::string word;
    while (in >> word) {
      args.push_back(word);
    }

    if (args.empty()) {
      continue;
    }

    try {
      if (args[0] == "add") {
        if (args.size() < 2) { throw CommandError("Not enough arguments"); }

        if (args[1] == "scooter") {
          checkSize(args, 6);
          park.addScooter(args[2], args[3], std::stod(args[4]), std::stoi(args[5]));
        } else if (args[1] == "bike") {
          checkSize(args, 5);
          park.addBike(args[2], args[3], std::stoi(args[4]));
        } else if (args[1] == "ebike") {
          checkSize(args, 6);
          park.addEbike(args[2], args[3], std::stod(args[4]), std::stoi(args[5]));
        } else if (args[1] == "helmet") {
          checkSize(args, 4);
          park.addHelmet(args[2], args[3]);
        } else if (args[1] == "dock") {
          checkSize(args, 5);
          park.addDock(args[2], args[3], std::stod(args[4]));
        } else if (args[1] == "NewTeslaRoadster") {
          checkSize(args, 6);
          park.addEbike(args[2], args[3], std::stod(args[4]), std::stoi(args[5]));
        } else {
          throw CommandError("Bad name, try again");
        }
      } else if (args[0] == "energy") {
        std::cout << std::fixed << std::setprecision(1) << park.energy() << '\n';
      } else if (args[0] == "novice") {
        park.novice();
      } else if (args[0] == "list") {
        park.list();
      } else if (args[0] == "focus") {
        checkSize(args, 2);
        park.focus(args[1]);
      } else if (args[0] == "show_focus") {
        park.showFocus();
      } else if (args[0] == "remove") {
        checkSize(args, 2);
        park.remove(args[1]);
      } else if (args[0] == "count_novice") {
        std::cout << park.countNovice() << '\n';
      } else if (args[0] == "quit") {
        break;
      } else {
        throw CommandError("Bad command, try again");
      }
    } catch (const FleetError& e) {
      std::cout << "error: " << e.what() << '\n';
    } catch (const std::exception&) {
      std::cout << "error: Bad number, try again" << '\n';
    }
  }
}