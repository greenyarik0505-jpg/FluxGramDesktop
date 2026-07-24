/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

namespace Data {
struct StatisticalChart;
} // namespace Data

namespace Statistic {

[[nodiscard]] QImage ChartCurrencyIcon(
		const Data::StatisticalChart &chartData,
		std::optional<QColor> color);

} // namespace Statistic

