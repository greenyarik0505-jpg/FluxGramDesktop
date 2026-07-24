/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

namespace Ui {
class GenericBox;
} // namespace Ui

enum class HistoryVisibility {
	Visible,
	Hidden,
};

void EditPeerHistoryVisibilityBox(
	not_null<Ui::GenericBox*> box,
	bool isLegacy,
	Fn<void(HistoryVisibility)> savedCallback,
	HistoryVisibility historyVisibilitySavedValue);

