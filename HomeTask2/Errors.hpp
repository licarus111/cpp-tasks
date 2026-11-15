#pragma once
#include <exception>
#include <string>

class FleetError : public std::exception {
public:
  explicit FleetError(const std::string& msg) : msg_(msg) {}

  const char* what() const noexcept override { return msg_.c_str(); }
private:
  std::string msg_;
};

class InspectionError : public FleetError {
public:
  InspectionError() : FleetError("Inspector's BAN") {}
};

class CommandError : public FleetError {
public:
  explicit CommandError(const std::string& msg) : FleetError(msg) {}
};