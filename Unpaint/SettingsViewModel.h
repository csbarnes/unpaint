﻿#pragma once
#include "SettingsViewModel.g.h"
#include "UnpaintOptions.h"

namespace winrt::Unpaint::implementation
{
  struct SettingsViewModel : SettingsViewModelT<SettingsViewModel>
  {
    SettingsViewModel();

    bool IsSafeModeEnabled();
    void IsSafeModeEnabled(bool value);

    bool IsDenoiserPinned();
    void IsDenoiserPinned(bool value);

    void Continue();

  private:
    INavigationService _navigationService;
    std::shared_ptr<UnpaintOptions> _unpaintOptions;
  };
}

namespace winrt::Unpaint::factory_implementation
{
  struct SettingsViewModel : SettingsViewModelT<SettingsViewModel, implementation::SettingsViewModel>
  {
  };
}