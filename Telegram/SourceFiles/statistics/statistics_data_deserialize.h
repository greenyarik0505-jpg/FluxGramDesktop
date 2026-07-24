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

class QByteArray;

namespace Statistic {

[[nodiscard]] Data::StatisticalChart StatisticalChartFromJSON(
	const QByteArray &json);

} // namespace Statistic

