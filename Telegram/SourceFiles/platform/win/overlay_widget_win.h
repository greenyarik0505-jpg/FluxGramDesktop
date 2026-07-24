/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

namespace Platform {

inline std::unique_ptr<OverlayWidgetHelper> CreateOverlayWidgetHelper(
		not_null<Ui::RpWindow*> window,
		Fn<void(bool)> maximize) {
	return std::make_unique<DefaultOverlayWidgetHelper>(
		window,
		std::move(maximize));
}

} // namespace Platform

