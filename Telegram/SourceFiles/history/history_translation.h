/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include "spellcheck/spellcheck_types.h"

class History;

class HistoryTranslation final {
public:
	HistoryTranslation(
		not_null<History*> history,
		const LanguageId &offerFrom);

	void offerFrom(LanguageId id);
	[[nodiscard]] LanguageId offeredFrom() const;

	void translateTo(LanguageId id);
	[[nodiscard]] LanguageId translatedTo() const;

private:
	const not_null<History*> _history;

	LanguageId _offerFrom;
	LanguageId _translatedTo;

};
