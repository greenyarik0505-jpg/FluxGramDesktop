/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

namespace Window {
class Controller;
} // namespace Window

namespace Ui {

void ShowPhoneBannedError(
	not_null<Window::Controller*> controller,
	const QString &phone);

} // namespace Ui

