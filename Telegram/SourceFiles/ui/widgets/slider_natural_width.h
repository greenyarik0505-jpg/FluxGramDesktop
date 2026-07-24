/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include "ui/widgets/discrete_sliders.h"

namespace Ui {

class CustomWidthSlider final : public SettingsSlider {
public:
	using Ui::SettingsSlider::SettingsSlider;
	using SettingsSlider::setNaturalWidth;

};

} // namespace Ui

