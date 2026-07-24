/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include "ui/layers/generic_box.h"

namespace Ui {

void ToggleTopicsBox(
    not_null<Ui::GenericBox*> box,
    bool enabled,
    bool tabs,
	Fn<void(bool enabled, bool tabs)> callback);

} // namespace Ui

