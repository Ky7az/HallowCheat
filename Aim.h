#ifndef __CHEAT_AIM_H__
#define __CHEAT_AIM_H__

/** INCLUDES **/
#define _USE_MATH_DEFINES
#include <cmath>
#include <windows.h>
#include "Module.h"
#include "../HallowDirectX/Vector.h"
#include "../HallowDirectX/Renderer.h"

/** DEFINES **/
#define RADPI 180.0f/M_PI
#define DEGPI M_PI/180.0f

/** CLASSES **/
/* Aim */
class CAimBase
{
public:
	CAimBase(Renderer *RendererPtr);
	~CAimBase();

	virtual int get_screen_size() const;

	void calc_position(const Vec3D *src, const Vec3D *dst, Vec3D &pos);

	bool check_angles(const Vec3D &ang);
	void normalize_angles(Vec3D &ang);

	float diff_angles(const Vec3D &src, const Vec3D &dst);
	void calc_angles(const Vec3D &src, const Vec3D &dst, Vec3D &ang);
	//void smooth_angles(Vec3D &src, Vec3D &dst, Vec3D &sm_ang, float sm_percent);

protected:
	Renderer *RendererPtr;
	float dist_max;

	int screen_width;
	int screen_height;

	Vec2D center_pos;
};

/* Aimbot */
class CAimbot : public virtual CAimBase, public virtual CModule
{
public:
	CAimbot(unsigned short id, std::wstring name, Renderer *RendererPtr);
	~CAimbot();

	//void pre_aim();
	//void post_aim();

	virtual void aim_at_position(float x, float y);
	virtual void aim_at_angles(Vec3D &ang);

protected:
	bool is_smooth;
	float fov;
	Vec3D aim_pos;
	float low_dist;
	Vec3D aim_ang;
	float low_fov;
};

/* Triggerbot */
class CTriggerbot : public virtual CAimBase, public virtual CModule
{
public:
	CTriggerbot(unsigned short id, std::wstring name, Renderer *RendererPtr);
	~CTriggerbot();

	virtual void action_fire() = 0;

protected:
	float fov;
};

#endif