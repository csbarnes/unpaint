#pragma once
#include "Storage/SettingManager.h"

namespace winrt::Unpaint
{
  class UnpaintOptions
  {
  public:
    UnpaintOptions();

    bool HasShownWelcomeView() const;
    void HasShownWelcomeView(bool value);

    bool IsSafeModeEnabled() const;
    void IsSafeModeEnabled(bool value);

    bool IsDenoiserPinned() const;
    void IsDenoiserPinned(bool value);

    std::string ModelId() const;
    void ModelId(const std::string& value) const;

  private:
    static const char* _hasShownWelcomeViewKey;
    static const char* _isSafeModeEnabledKey;
    static const char* _isDenoiserPinnedKey;
    static const char* _modelIdKey;

    std::shared_ptr<Axodox::Storage::SettingManager> _settingManager;
  };
}