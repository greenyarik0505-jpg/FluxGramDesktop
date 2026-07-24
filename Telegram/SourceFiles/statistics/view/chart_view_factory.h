/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

namespace Statistic {

class AbstractChartView;
enum class ChartViewType;

[[nodiscard]] std::unique_ptr<AbstractChartView> CreateChartView(
	ChartViewType type);

} // namespace Statistic

