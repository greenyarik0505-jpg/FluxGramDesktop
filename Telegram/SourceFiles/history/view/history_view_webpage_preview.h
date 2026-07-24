/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

namespace HistoryView {

struct WebPageText {
	QString title;
	QString description;
};

WebPageText TitleAndDescriptionFromWebPage(not_null<WebPageData*> d);
bool DrawWebPageDataPreview(
	QPainter &p,
	not_null<WebPageData*> webpage,
	not_null<PeerData*> context,
	QRect to);

} // namespace HistoryView

