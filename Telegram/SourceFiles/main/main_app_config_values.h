/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

namespace Main {
class Session;
} // namespace Main

namespace AppConfig {

[[nodiscard]] std::optional<QString> FragmentLink(not_null<Main::Session*>);

} // namespace AppConfig

