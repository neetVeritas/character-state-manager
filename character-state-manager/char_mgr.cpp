#include "char_mgr.h"

Hack::Hack(DWORD address, std::string enabled, std::string disabled)
{

  this->active = false;
  this->address = address;
  this->enabled = enabled;
  this->disabled = disabled;

}

void Hack::toggle()
{

  if (this->active)
    memapi::write(this->address, this->disabled);
  else
    memapi::write(this->address, this->enabled);

  this->active = !this->active;

}

void Mgr::init()
{

  while (FindWindow("Rumble Fighter", "Rumble Fighter") == NULL)
    Sleep(2500);


  this->char_base = 0x7C50E4;
  this->char_state = 0x576C;

  this->initialized = true;

}



void Mgr::change_char_state(int state)
{

  if (this->initialized)
    memapi::pointer::write_int(this->char_base, this->char_state, state);

}
