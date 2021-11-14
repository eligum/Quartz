#pragma once

#include "quartz/core/Base.hpp"
#include "quartz/core/Log.hpp"

#ifdef QZ_ENABLE_ASSERTS
	#define QZ_ASSERT(...)
	#define QZ_CORE_ASSERT(...)
#else
	#define QZ_ASSERT(...)
	#define QZ_CORE_ASSERT(...)
#endif
