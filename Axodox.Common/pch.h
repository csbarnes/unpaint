#pragma once
#include <variant>
#include <array>
#include <queue>
#include <ranges>
#include <functional>
#include <future>
#include <shared_mutex>
#include <filesystem>
#include <type_traits>
#include <chrono>
#include <span>
#include <random>
#include <sstream>
#include <set>

#define NOMINMAX
#include <DirectXMath.h>
#include <DirectXPackedVector.h>

#include <d3d11_4.h>
#include <d3d12.h>
#include <d3d11on12.h>
#include <d2d1_3.h>
#include <dwrite_3.h>
#include <wincodec.h>
#include <winrt/base.h>

#include <winrt/windows.foundation.h>
#include <winrt/windows.web.http.h>
#include <winrt/windows.web.http.filters.h>
#include <winrt/windows.web.http.headers.h>
#include <winrt/windows.security.cryptography.h>
#include <winrt/Windows.Storage.h>
#include <winrt/Windows.Storage.Streams.h>

#ifdef UWP_UI
#include <winrt/windows.ui.core.h>
#include <winrt/windows.ui.xaml.h>
#include <winrt/windows.ui.xaml.controls.h>
#include <windows.ui.xaml.media.dxinterop.h>
#endif // UWP_UI

#ifdef ONNX
#include "onnxruntime_cxx_api.h"
#include "dml_provider_factory.h"
#endif

#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "dwrite.lib")