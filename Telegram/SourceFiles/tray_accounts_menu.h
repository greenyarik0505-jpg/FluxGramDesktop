/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include "platform/platform_tray.h"

namespace Core::TrayAccountsMenu {

void SetupChangesSubscription(
	Fn<void()> callback,
	rpl::lifetime &lifetime);
void Fill(Platform::Tray &tray);

} // namespace Core::TrayAccountsMenu

