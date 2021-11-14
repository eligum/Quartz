#pragma once

#include <memory>
#include "quartz/core/PlatformDetection.hpp"

#ifdef QZ_DEBUG
	#if defined(QZ_PLATFORM_WINDOWS)
		#define QZ_DEBUGBREAK() __debugbreak()
	#elif defined(QZ_PLATFORM_LINUX)
		#include <signal.h>
		#define QZ_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define QZ_ENABLE_ASSERTS
#else
	#define QZ_DEBUGBREAK()
#endif

#define QZ_EXPAND_MACRO(x) x
#define QZ_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define QZ_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace quartz {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}

#include "quartz/core/Log.hpp"
#include "quartz/core/Assert.hpp"
