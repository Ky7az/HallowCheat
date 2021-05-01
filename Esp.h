#ifndef __CHEAT_ESP_H__
#define __CHEAT_ESP_H__

/** INCLUDES **/
#include "Module.h"
#include "Entity.h"
#include "../HallowDirectX/Renderer.h"

/** DEFINES **/

/** CLASSES **/
/* Esp */
class CEsp : public virtual CModule
{
public:
	CEsp(unsigned short id, std::wstring name, Renderer *RendererPtr);
	~CEsp();

	virtual int get_screen_size() const;

protected:
	Renderer *RendererPtr;
	float dist_max;
	//std::vector<Entity*> Entitz;

	int screen_width;
	int screen_height;
};

#endif