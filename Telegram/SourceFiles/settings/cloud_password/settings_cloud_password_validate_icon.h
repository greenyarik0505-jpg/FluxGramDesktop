/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

template <typename Object>
class object_ptr;

namespace Main {
class Session;
} // namespace Main

namespace Ui {
class RpWidget;
} // namespace Ui

namespace Settings {

[[nodiscard]] object_ptr<Ui::RpWidget> CreateValidateGoodIcon(
	not_null<Main::Session*> session);

} // namespace Settings


