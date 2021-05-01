#include "Module.h"

/* Module */
CModule::CModule(unsigned short id, std::wstring name)
{
	this->id = id;
	this->name = name;
	this->is_on = false;
}

unsigned short CModule::get_id() const { return id; }
bool CModule::check_is_on() const { return is_on; }

void CModule::switch_bool()
{
	is_on = !is_on;
}