#include "Cheat.h"

/* Cheat */
CCheat::CCheat(Renderer *RendererPtr)
{
	this->RendererPtr = RendererPtr;
	menu = NULL;
}

CCheat::~CCheat()
{
	for (auto &m : Modz) {
		delete m;
	}
	Modz.clear();
}

CMenu* CCheat::get_menu() const { return menu;  }

void CCheat::pre_run_modz()
{
	for (const auto &mod : Modz) {
		if (mod->check_is_on() == true)
			mod->pre_run();
	}
}

void CCheat::post_run_modz()
{
	for (const auto &mod : Modz) {
		if (mod->check_is_on() == true)
			mod->post_run();
	}
}

void CCheat::run_modz()
{
	for (const auto &mod : Modz) {
		if (mod->check_is_on() == true)
			mod->run();
	}
}

void CCheat::draw_menu()
{
	if (menu)
		menu->draw();
}

void CCheat::debug()
{
}