/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

class ClickHandler;

namespace HistoryView {

[[nodiscard]] std::shared_ptr<ClickHandler> SponsoredLink(
	const QString &link,
	bool isInternal);

} // namespace HistoryView

