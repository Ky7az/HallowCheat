#include "Aim.h"

/* AimBase */
CAimBase::CAimBase(Renderer *RendererPtr)
{
	this->RendererPtr = RendererPtr;
	dist_max = 30.0f;

	screen_width = 0;
	screen_height = 0;
}

CAimBase::~CAimBase()
{
}

int CAimBase::get_screen_size() const { return screen_width, screen_height; }

void CAimBase::calc_position(const Vec3D *src, const Vec3D *dst, Vec3D &pos)
{
}

bool CAimBase::check_angles(const Vec3D &angles)
{
	return angles.x <= 89.0f && angles.x >= -89.0f
		&& angles.y <= 180.0f && angles.y >= -180.0f;
}

void CAimBase::normalize_angles(Vec3D &ang)
{
	if (ang.x > 89.0f)
		ang.x = 89.0f;
	else
		if (ang.x < -89.0f)
			ang.x = -89.0f;

	ang.y = fmodf(ang.y, 360.0f);
	if (ang.y > 180.0f)
		ang.y -= 360.0f;
	else
		if (ang.y < -180.0f)
			ang += 360.0f;

	ang.z = 0.f;
}

float CAimBase::diff_angles(const Vec3D &src, const Vec3D &dst)
{
	float pitch = src.x - dst.x;
	float yaw = src.y - dst.y;

	while (yaw > 180)
		yaw -= 360;
	while (yaw < -180)
		yaw += 360;

	return sqrtf(pow(pitch, 2) + pow(yaw, 2));
}

void CAimBase::calc_angles(const Vec3D &src, const Vec3D &dst, Vec3D &ang)
{
	Vec3D delta = src - dst;
	float hypotenuse = sqrtf(pow(delta.x, 2) + pow(delta.y, 2));

	ang.x = asinf(delta.z / hypotenuse) * RADPI;
	ang.y = atanf(delta.y / delta.x) * RADPI + 90;

	ang.z = 0.0f;

	if (delta.x >= 0.0f)
		ang.y += 180.0f;

	normalize_angles(ang);
}

/*void CAimBase::smooth_angles(Vec3D &src, Vec3D &dst, Vec3D &sm_ang, float sm_percent)
{
}*/

/* Aimbot */
CAimbot::CAimbot(unsigned short id, std::wstring name, Renderer *RendererPtr) : CAimBase(RendererPtr), CModule(id, name)
{
	is_smooth = false;
	fov = 20.0f;
	low_dist = fov;
	low_fov = fov;
}

CAimbot::~CAimbot()
{
}

void CAimbot::aim_at_position(float x, float y)
{
	float aim_speed = 5;
	float target_x = 0;
	float target_y = 0;
	float screen_center_x = screen_width * 0.5f;
	float screen_center_y = screen_height * 0.5f;

	INPUT im_m = { 0 };
	im_m.type = INPUT_MOUSE;
	im_m.mi.dwFlags = MOUSEEVENTF_MOVE;

	// X Axis
	if (x != 0)
	{
		if (x > screen_center_x)
		{
			target_x = -(screen_center_x - x);
			target_x /= aim_speed;
			if (target_x + screen_center_x > screen_center_x * 2) target_x = 0;
		}

		if (x < screen_center_x)
		{
			target_x = x - screen_center_x;
			target_x /= aim_speed;
			if (target_x + screen_center_x < 0) target_x = 0;
		}
	}

	// Y Axis
	if (y != 0)
	{
		if (y > screen_center_y)
		{
			target_y = -(screen_center_y - y);
			target_y /= aim_speed;
			if (target_y + screen_center_y > screen_center_y * 2) target_y = 0;
		}

		if (y < screen_center_y)
		{
			target_y = y - screen_center_y;
			target_y /= aim_speed;
			if (target_y + screen_center_y < 0) target_y = 0;
		}
	}

	if (is_smooth == false)
	{
		im_m.mi.dx = (DWORD)target_x;
		im_m.mi.dy = (DWORD)target_y;
		SendInput(1, &im_m, sizeof(INPUT));
		return;
	}

	target_x /= 10;
	target_y /= 10;

	if (fabs(target_x) < 1)
	{
		if (target_x > 0)
		{
			target_x = 1;
		}
		if (target_x < 0)
		{
			target_x = -1;
		}
	}
	if (fabs(target_y) < 1)
	{
		if (target_y > 0)
		{
			target_y = 1;
		}
		if (target_y < 0)
		{
			target_y = -1;
		}
	}

	im_m.mi.dx = (DWORD)target_x;
	im_m.mi.dy = (DWORD)target_y;
	SendInput(1, &im_m, sizeof(INPUT));
}

void CAimbot::aim_at_angles(Vec3D &ang)
{
}

/* Triggerbot */
CTriggerbot::CTriggerbot(unsigned short id, std::wstring name, Renderer *RendererPtr) : CAimBase(RendererPtr), CModule(id, name)
{
	fov = 5.0f;
}

CTriggerbot::~CTriggerbot()
{
}