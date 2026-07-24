/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#include "stripe/stripe_decode.h"

namespace Stripe {

[[nodiscard]] bool ContainsFields(
		const QJsonObject &object,
		std::vector<QStringView> keys) {
	for (const auto &key : keys) {
		if (object.value(key).isUndefined()) {
			return false;
		}
	}
	return true;
}

} // namespace Stripe

