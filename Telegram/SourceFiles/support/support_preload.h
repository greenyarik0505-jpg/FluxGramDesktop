/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

class History;

namespace Support {

// Returns histories().request, not api().request.
[[nodiscard]] int SendPreloadRequest(
	not_null<History*> history,
	Fn<void()> retry);

} // namespace Support

