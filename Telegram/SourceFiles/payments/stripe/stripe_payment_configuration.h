/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include "stripe/stripe_address.h"

#include <QtCore/QString>

namespace Stripe {

struct PaymentConfiguration {
	QString publishableKey;
	// PaymentMethodType additionalPaymentMethods; // Apply Pay

	// TODO incomplete, not used.
	//BillingAddressFields requiredBillingAddressFields
	//	= BillingAddressFields::None;

	QString companyName;
	// QString appleMerchantIdentifier; // Apple Pay
	// bool smsAutofillDisabled = true; // Mobile only
};

} // namespace Stripe

