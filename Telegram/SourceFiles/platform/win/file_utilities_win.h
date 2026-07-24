/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include "platform/platform_file_utilities.h"

namespace Platform {
namespace File {

inline QString UrlToLocal(const QUrl &url) {
	return ::File::internal::UrlToLocalDefault(url);
}

inline void UnsafeOpenUrl(const QString &url) {
	return ::File::internal::UnsafeOpenUrlDefault(url);
}

} // namespace File
} // namespace Platform

