#include "pch.h"
#include "UnpaintOptions.h"
#include "Infrastructure/DependencyContainer.h"

using namespace Axodox::Infrastructure;
using namespace Axodox::Storage;
using namespace std;

namespace winrt::Unpaint
{
  const char* UnpaintOptions::_hasShownWelcomeViewKey = "UserInterface.HasShownWelcomeView";
  const char* UnpaintOptions::_isSafeModeEnabledKey = "Inference.IsSafeModeEnabled";
  const char* UnpaintOptions::_isDenoiserPinnedKey = "Inference.IsDenoiserPinned";
  const char* UnpaintOptions::_modelIdKey = "Inference.ModelId";

  UnpaintOptions::UnpaintOptions() :
    _settingManager(dependencies.resolve<SettingManager>())
  { }

  bool UnpaintOptions::HasShownWelcomeView() const
  {
    return _settingManager->LoadSettingOr(_hasShownWelcomeViewKey, false);
  }

  void UnpaintOptions::HasShownWelcomeView(bool value)
  {
    _settingManager->StoreSetting(_hasShownWelcomeViewKey, value);
  }

  bool UnpaintOptions::IsSafeModeEnabled() const
  {
    return _settingManager->LoadSettingOr(_isSafeModeEnabledKey, true);
  }

  void UnpaintOptions::IsSafeModeEnabled(bool value)
  {
    _settingManager->StoreSetting(_isSafeModeEnabledKey, value);
  }

  bool UnpaintOptions::IsDenoiserPinned() const
  {
    return _settingManager->LoadSettingOr(_isDenoiserPinnedKey, true);
  }

  void UnpaintOptions::IsDenoiserPinned(bool value)
  {
    _settingManager->StoreSetting(_isDenoiserPinnedKey, value);
  }

  std::string UnpaintOptions::ModelId() const
  {
    return _settingManager->LoadSettingOr(_modelIdKey, string(""));
  }

  void UnpaintOptions::ModelId(const std::string& value) const
  {
    _settingManager->StoreSetting(_modelIdKey, value);
  }
}