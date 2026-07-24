/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

struct HistoryMessageSuggestion;
struct HistoryServiceSuggestDecision;

namespace HistoryView {

class Element;
class MediaGeneric;
class MediaGenericPart;

auto GenerateSuggestDecisionMedia(
	not_null<Element*> parent,
	not_null<const HistoryServiceSuggestDecision*> decision
) -> Fn<void(
	not_null<MediaGeneric*>,
	Fn<void(std::unique_ptr<MediaGenericPart>)>)>;

auto GenerateSuggestRequestMedia(
	not_null<Element*> parent,
	not_null<const HistoryMessageSuggestion*> suggest
) -> Fn<void(
	not_null<MediaGeneric*>,
	Fn<void(std::unique_ptr<MediaGenericPart>)>)>;

} // namespace HistoryView

