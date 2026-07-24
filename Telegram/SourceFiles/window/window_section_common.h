/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

namespace Window {

enum class SectionActionResult {
	Handle, // Handle an action and stay in the current section.
	Fallback, // Ignore an action and fallback to the HistoryWidget.
	Ignore, // Ignore an action and stay in the current section.
};

} // namespace Window

