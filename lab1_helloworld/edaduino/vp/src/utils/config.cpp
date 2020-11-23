#include "utils/config.h"
#include <etiss/ETISS.h>
#include <etiss/IntegratedLibrary/SimpleIni/SimpleIni.h>
#include <cassert>
#include "utils/logging.h"

static bool g_argsset = false;
static int g_argc = 0;
static char **g_argv = nullptr;

void etissvp::SetCmdlineArgs(int argc, char *argv[]) {
  g_argsset = true;
  g_argc = argc;
  g_argv = argv;
}

etiss::Initializer *etissvp::GetETISSInit() {
  assert(g_argsset && "Must set cmdline args with etissvp::SetCmdlineArgs");
  static etiss::Initializer init{g_argc, g_argv};

  // TODO what is the best place for this?
  etissvp::set_log_level(etiss::verbosity());

  return &init;
}

etiss::Configuration &etissvp::GetETISSConfig() {
  (void)GetETISSInit();
  return etiss::cfg();
}

void etissvp::Config::loadFromFile(const std::string &path) {
  CSimpleIni ini(true, true, true);
  if (ini.LoadFile(path.c_str()) < 0) {
    throw std::runtime_error("could not load config file");
  }
  CSimpleIni::TNamesDepend keys;
  if (ini.GetAllKeys("etissvp", keys)) {
    for (const auto &key : keys) {
      CSimpleIni::TNamesDepend values;
      if (ini.GetAllValues("etissvp", key.pItem, values)) {
        if (values.size() != 1) {
          throw std::runtime_error(
              "multiple values not allowed for single key");
        }
        set(key.pItem, values.front().pItem);
      }
    }
  }
}

etissvp::Config etissvp::Config::applyDefaults(const Config &cfg) const {
  Config defaultCfg = *this;
  for (const auto &k2v : cfg.keyToValue_) {
    if (keyToValue_.count(k2v.first) == 0) {
      defaultCfg.set(k2v.first, k2v.second);
    }
  }
  return defaultCfg;
}

etissvp::Config etissvp::Config::getSubConfig(const std::string &key) const {
  auto keyPrefix = key + ".";
  Config subCfg;
  for (const auto &k2v : keyToValue_) {
    if (!k2v.first.compare(0, keyPrefix.size(), keyPrefix)) {
      subCfg.set(k2v.first.substr(keyPrefix.size()), k2v.second);
    }
  }
  subCfg.dbgTrace_ = dbgTrace_ + keyPrefix;
  return subCfg;
}

void etissvp::Config::print() const {
  for (const auto &k2v : keyToValue_) {
    printf("%s = %s\n", k2v.first.c_str(), k2v.second.c_str());
  }
}
