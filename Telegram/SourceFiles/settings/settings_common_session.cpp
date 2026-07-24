/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#include "settings/settings_common_session.h"

#include "settings/cloud_password/settings_cloud_password_email_confirm.h"
#include "settings/settings_experimental.h"
#include "settings/sections/settings_chat.h"
#include "settings/sections/settings_main.h"

// FluxGram includes
#include "ayu/ui/settings/settings_filters.h"


namespace Settings {

bool HasMenu(Type type) {
	return (type == ::Settings::CloudPasswordEmailConfirmId())
		|| (type == MainId())
		|| (type == ChatId())
		|| (type == Experimental::Id())
		|| (type == AyuFiltersId());
}

} // namespace Settings


