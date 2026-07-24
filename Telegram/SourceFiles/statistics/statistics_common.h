/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

namespace Statistic {

constexpr auto kRulerLineAlpha = 0.06;

struct Limits final {
	float64 min = 0;
	float64 max = 0;
};

enum class ChartViewType {
	Linear,
	Bar,
	StackBar,
	DoubleLinear,
	StackLinear,
};

} // namespace Statistic

