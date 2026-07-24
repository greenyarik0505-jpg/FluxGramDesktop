/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

namespace Data {

struct PremiumSubscriptionOption {
	int months = 0;
	QString duration;
	QString discount;
	QString costPerMonth;
	QString costNoDiscount;
	QString costPerYear;
	QString currency;
	QString total;
	QString botUrl;
};
using PremiumSubscriptionOptions = std::vector<PremiumSubscriptionOption>;

} // namespace Data

