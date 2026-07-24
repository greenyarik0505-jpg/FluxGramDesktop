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

void PinMessageBox(
	not_null<Ui::GenericBox*> box,
	not_null<HistoryItem*> item);

