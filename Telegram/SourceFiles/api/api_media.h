/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

class HistoryItem;

namespace Api {

struct RemoteFileInfo;

MTPInputMedia PrepareUploadedPhoto(
	not_null<HistoryItem*> item,
	RemoteFileInfo info);

MTPInputMedia PrepareUploadedDocument(
	not_null<HistoryItem*> item,
	RemoteFileInfo info);

bool HasAttachedStickers(MTPInputMedia media);

} // namespace Api

