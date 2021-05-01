#include "Entity.h"
using namespace std;

/* Bone */
CBone::CBone(string name)
{
	this->name = name;
	position = NULL;
}

CBone::~CBone()
{
}

string CBone::get_name() const { return name; }
Vec3D CBone::get_position() const { return position; }


/* Entity */
CEntity::CEntity()
{
	id = 0;
	name = "";
	type = "";

	health = 0;
	is_visible = false;

	position = NULL;
	angles = NULL;
	bot_left = NULL;
	top_right = NULL;
}

CEntity::~CEntity()
{
}

wstring CEntity::get_typeW() const { return wstring_convert<codecvt_utf8<wchar_t>>().from_bytes(type); }
int CEntity::get_health() const { return health; }
bool CEntity::get_is_visible() const { return is_visible; }
Vec3D CEntity::get_position() const { return position; }
Vec3D CEntity::get_angles() const { return angles; }
pair<Vec3D, Vec3D> CEntity::get_bbox() const { return make_pair(bot_left, top_right); }