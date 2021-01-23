#ifndef ETISSVP_CONFIG_H
#define ETISSVP_CONFIG_H

#include <string>
#include <unordered_map>
#include <stdexcept>

namespace etiss {
class Initializer;
class Configuration;
}  // namespace etiss

namespace etissvp {

/// Assigns command line arguments for ETISS.
void SetCmdlineArgs(int argc, char *argv[]);

/// Returns the ETISS initializer object. It is created if required.
etiss::Initializer *GetETISSInit();

/// Returns the configuration object of ETISS.
etiss::Configuration &GetETISSConfig();

/**
 * Represents a configuration consisting of key-value-pairs.
 * Final config values are determined as follows:
 * 1.) Take the default value set with applyDefaults.
 * 2.) Take the value defined by the config file that was loaded.
 * 3.) Take the value that was overwritten in code by "set".
 * Steps 2.) and 3.) can be exchanged or mixed depending on when loadFromFile
 * and set are called.
 *
 * Supported configuration types:
 * - String (std::string): A normal string. All keys are strings. ("hello
 *world")
 * - Integer (int, unsigned int, uint32_t, ...): Any integer value. (15, 0xff)
 * - Float (float, double): Any floating point value. (3.14)
 * - Boolean (bool): False if integer 0 or string "false". Otherwise true.
 **/
class Config {
 public:
  /// Loads all configs from the given file path. The file must be in INI
  /// format.
  void loadFromFile(const std::string &path);

  /// Copies every setting from the given config to the returned one, but only
  /// if the key is not contained already.
  Config applyDefaults(const Config &cfg) const;

  /// Assigns value to specific config.
  template <typename T>
  void set(const std::string &key, const T &value);

  /// Return the value for the given key.
  template <typename T = std::string>
  T get(const std::string &key) const;

  /// Returns a new Config instance that contains all configs at top-level that
  /// start with "key" in this config.
  Config getSubConfig(const std::string &key) const;

  /// Prints all config values to stdout.
  void print() const;

 private:
  std::unordered_map<std::string, std::string> keyToValue_;
  std::string dbgTrace_;
};

template <typename T>
void Config::set(const std::string &key, const T &value) {
  std::string strVal;
  if constexpr (std::is_same_v<T, bool>) {
    strVal = value ? "true" : "false";
  } else if constexpr (std::is_integral_v<T> || std::is_enum_v<T> ||
                       std::is_floating_point_v<T>) {
    strVal = std::to_string(value);
  } else {
    strVal = value;
  }
  keyToValue_[key] = strVal;
}

template <typename T>
T Config::get(const std::string &key) const {
  auto itValue = keyToValue_.find(key);
  if (itValue == keyToValue_.end()) {
    throw std::runtime_error("Config value '" + dbgTrace_ + key +
                             "' does not exist");
  }
  auto &value = itValue->second;
  if constexpr (std::is_same_v<T, bool>) {
    return value != "0" || value != "false";
  } else if constexpr (std::is_integral_v<T> || std::is_enum_v<T>) {
    int base = 10;
    if (value.size() >= 2 && value.compare(0, 2, "0x") == 0) {
      base = 16;
    }
    auto i = stoll(value, nullptr, base);
    return (T)i;
  } else if constexpr (std::is_floating_point_v<T>) {
    auto f = stod(value);
    return (T)f;
  } else {
    return value;
  }
}

}  // namespace etissvp

#endif
