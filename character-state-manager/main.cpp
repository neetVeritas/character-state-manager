#include "char_mgr.h"
#include "speed.h"

void Main(void)
{

  Mgr *mgr = new Mgr();
  mgr->init();	 // # initialize

  while (true)
  {
    if (GetAsyncKeyState(VK_F1) & 1) {
      MessageBoxA(NULL, "State Reset", "", 0);
      mgr->change_char_state(0);
    }
    if (GetAsyncKeyState(VK_F2) & 1) {
      MessageBoxA(NULL, "Basic Tier Commands Available", "", 0);
      mgr->change_char_state(1);
    }
    if (GetAsyncKeyState(VK_F3) & 1) {
      MessageBoxA(NULL, "GM Room State Triggered", "", 0);
      mgr->change_char_state(258);
    }
    Sleep(25);
  }

}
