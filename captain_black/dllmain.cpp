#define NOMINMAX
#include <windows.h>
#include <cstdint>
#include "global.hpp"
#include "native_thread.hpp"

void launcher_thread(void* arg [[maybe_unused]])
{
	global::cpt.start();
}

bool APIENTRY DllMain(void* module_handle [[maybe_unused]], std::uint32_t reason, void* reserved [[maybe_unused]])
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		native_thread<launcher_thread>().run(nullptr);
	}

    return true;
}

