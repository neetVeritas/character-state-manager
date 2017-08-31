#pragma once
#include "includes.h"
#include "scanner.h"
#include "speed.h"
#include "memory.h"

class Hack
{
private:
  bool active;
  DWORD address;
  std::string enabled, disabled;

public:
  Hack(DWORD address, std::string enabled, std::string disabled);
  void toggle();
};

class Mgr
{
private:
  bool initialized = false;
  DWORD char_base, char_state;

public:
  void init();
  void change_char_state(int state);
};
