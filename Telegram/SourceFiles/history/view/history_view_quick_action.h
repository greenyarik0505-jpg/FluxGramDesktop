/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

namespace HistoryView {

enum class DoubleClickQuickAction {
	Reply, // Default.
	React,
	None,
};

[[nodiscard]] DoubleClickQuickAction CurrentQuickAction();

} // namespace HistoryView

