/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

namespace Data {

struct ColorProfileSet {
	std::vector<QColor> palette;
	std::vector<QColor> bg;
	std::vector<QColor> story;
};

struct ColorProfileData {
	ColorProfileSet light;
	ColorProfileSet dark;
};

} // namespace Data

