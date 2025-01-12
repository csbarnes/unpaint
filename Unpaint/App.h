﻿#pragma once
#include "App.xaml.g.h"

#include "SizeToStringConverter.h"
#include "IsNanToBooleanConverter.h"
#include "NanToZeroConverter.h"
#include "StringToImageSourceConverter.h"
#include "BooleanInverter.h"
#include "EqualsConverter.h"
#include "BooleanToGridLengthConverter.h"
#include "StorageFileToImageSourceConverter.h"
#include "BooleanSwitchConverter.h"
#include "IsNullConverter.h"

namespace winrt::Unpaint::implementation
{
  struct App : AppT<App>
  {
    App();
    void Activate(Windows::ApplicationModel::Activation::IActivatedEventArgs eventArgs);

    void OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs const&);
    void OnActivated(Windows::ApplicationModel::Activation::IActivatedEventArgs const& eventArgs);
    void OnSuspending(IInspectable const&, Windows::ApplicationModel::SuspendingEventArgs const&);
    void OnNavigationFailed(IInspectable const&, Windows::UI::Xaml::Navigation::NavigationFailedEventArgs const&);
  };
}
