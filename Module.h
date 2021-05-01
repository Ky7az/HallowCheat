#ifndef __CHEAT_MODULE_H__
#define __CHEAT_MODULE_H__

/** INCLUDES **/
#include <string>
#include <atomic>

/** DEFINES **/
enum ModuleType {
	Esp,
	Aimbot,
	Triggerbot
};

/** CLASSES **/
/* Module */
class CModule
{
public:
	CModule(unsigned short id, std::wstring name = L"Null");
	virtual ~CModule() {};

	void switch_bool();

	virtual void pre_run() = 0;
	virtual void post_run() = 0;
	virtual void run() {}; //  = 0

	virtual unsigned short get_id() const;
	//virtual std::wstring get_name() const;
	virtual bool check_is_on() const;

protected:
	unsigned short id;
	std::wstring name;
	bool is_on;
};

/* Null Module */
class CNullModule : public CModule
{
public:
	void pre_main() {};
	void post_main() {};
	void run_main() {};
};

#endif