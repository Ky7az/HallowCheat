#include "Menu.h"
using namespace std;

/* MenuEntry */
CMenuEntry::CMenuEntry(wstring name, int hotkey, CModule* mod)
{
	this->name = name;
	this->hotkey = hotkey;
	this->mod = mod;
	is_on = false;
}

CMenuEntry::~CMenuEntry()
{
}

std::wstring CMenuEntry::get_name() const { return name; }
int CMenuEntry::get_hotkey() const { return hotkey; }
bool CMenuEntry::get_is_on() const { return is_on; }

void CMenuEntry::switch_bool()
{
	is_on = !is_on;
	mod->switch_bool();
};


/* Menu */
CMenu::CMenu(Renderer *RendererPtr)
{
	font_color = Color::White();
	pos_x = 10;
	pos_y = 5;

	is_on = true;
	this->RendererPtr = RendererPtr;
}

CMenu::~CMenu()
{
	for (auto &me : MenuEntrz) {
		delete me;
	}
	MenuEntrz.clear();
}

void CMenu::add_menuentry(CMenuEntry *me)
{
	MenuEntrz.push_back(me);
}

void CMenu::draw()
{
	if (GetAsyncKeyState(VK_F1) & 1) { is_on = !is_on; }

	menu_bar = L"";
	for (const auto &me : MenuEntrz) {

		if (GetAsyncKeyState(me->get_hotkey()) & 1) { me->switch_bool(); }

		wstring repr = (boost::wformat(L"^ %s <%s> ") % me->get_name() % (me->get_is_on() ? L"ON" : L"OFF")).str();
		menu_bar.append(repr);
	}
	menu_bar.append(L"^");

	wstring fps = (boost::wformat(L" %d") % RendererPtr->frame_rate()).str();
	menu_bar.append(fps);

	if (is_on)
		RendererPtr->draw_text(menu_bar, pos_x, pos_y, font_color);
}
