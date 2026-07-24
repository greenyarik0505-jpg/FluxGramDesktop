/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

struct HistoryServiceNoForwardsRequest;

namespace HistoryView {

class Element;
class MediaGeneric;
class MediaGenericPart;

auto GenerateNoForwardsRequestMedia(
	not_null<Element*> parent,
	not_null<const HistoryServiceNoForwardsRequest*> request
) -> Fn<void(
	not_null<MediaGeneric*>,
	Fn<void(std::unique_ptr<MediaGenericPart>)>)>;

} // namespace HistoryView

