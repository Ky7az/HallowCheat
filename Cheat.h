#ifndef __CHEAT_H__
#define __CHEAT_H__

/** INCLUDES **/
#include <vector>
#include "Menu.h"
#include "Module.h"
#include "../HallowDirectX/Renderer.h"

/** DEFINES **/

/** CLASSES **/
/* Cheat [Abstract] */
class CCheat
{
public:
	CCheat(Renderer *RendererPtr);
	~CCheat();

	virtual void pre_run_modz();
	virtual void post_run_modz();
	virtual void run_modz();

	virtual CMenu* create_menu() = 0;
	virtual CModule* create_module(unsigned short id, ModuleType type, std::wstring name) = 0;

	virtual void init() = 0;
	virtual void draw_menu();
	virtual void debug();

	virtual CMenu* get_menu() const;

protected:
	Renderer *RendererPtr;
	CMenu *menu;
	std::vector<CModule*> Modz;
};

#endif