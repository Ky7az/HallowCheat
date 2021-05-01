#ifndef __CHEAT_MENU_H__
#define __CHEAT_MENU_H__

/** INCLUDES **/
#include <string>
#include <vector>
#include <boost/format.hpp>
#include "Module.h"
#include "../HallowDirectX/Renderer.h"

/** DEFINES **/

/** CLASSES **/
/* MenuEntry */
class CMenuEntry
{
public:
	CMenuEntry(std::wstring name, int hotkey, CModule* mod);
	~CMenuEntry();

	std::wstring get_name() const;
	int get_hotkey() const;
	bool get_is_on() const;

	void switch_bool();

protected:
	std::wstring name;
	int hotkey;
	bool is_on;
	CModule *mod;
};

/* Menu */
class CMenu
{
public:
	CMenu(Renderer *RendererPtr);
	~CMenu();

	void add_menuentry(CMenuEntry *me);
	void draw();

protected:
	Color font_color;
	int pos_x;
	int pos_y;

	std::wstring menu_bar;
	bool is_on;

	Renderer *RendererPtr;
	std::vector<CMenuEntry*> MenuEntrz;
};

#endif