#include "Esp.h"
using namespace std;

/* Esp */
CEsp::CEsp(unsigned short id, wstring name, Renderer *RendererPtr) : CModule(id, name)
{
	this->RendererPtr = RendererPtr;
	dist_max = 70.0f;

	screen_width = 0;
	screen_height = 0;
}

CEsp::~CEsp()
{
}

int CEsp::get_screen_size() const { return screen_width, screen_height; }

/*void CEsp::on_setup(Renderer *RendererPtr)
{
	this->RendererPtr = RendererPtr;
}*/

/*void Esp::update()
{
	for (auto &ent : entities) {
		ent->update();
	}
}*/