/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include <QtCore/QJsonObject>
#include <vector>

namespace Stripe {

[[nodiscard]] bool ContainsFields(
	const QJsonObject &object,
	std::vector<QStringView> keys);

} // namespace Stripe

