#ifndef __CHEAT_ENTITY_H__
#define __CHEAT_ENTITY_H__

/** INCLUDES **/
#include <string>
#include <vector>
#include <locale>
#include <codecvt>
#include "windows.h"
#include "../HallowDirectX/Vector.h"

/** DEFINES **/

/** CLASSES **/
/* Bone */
class CBone
{
public:
	CBone(std::string name);
	~CBone();

	virtual void init() = 0;

	virtual std::string get_name() const;
	virtual Vec3D get_position() const;

protected:
	unsigned int id;
	std::string name;
	Vec3D position;
};

/* Entity */
class CEntity
{
public:
	CEntity(); // DWORD *addr
	~CEntity();

	virtual std::wstring get_typeW() const;
	virtual int get_health() const;
	virtual bool get_is_visible() const;
	virtual Vec3D get_position() const;
	virtual Vec3D get_angles() const;
	virtual std::pair<Vec3D,Vec3D> get_bbox() const;

	virtual void set_angles(const Vec3D &angles, bool smooth = false) = 0;
	virtual void init() = 0;

protected:
	unsigned int id;
	std::string name;
	std::string type;

	int health;
	bool is_visible;

	Vec3D position;
	Vec3D angles;
	Vec3D bot_left;
	Vec3D top_right;

	std::vector<CBone*> Bonz;
};

#endif