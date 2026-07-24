/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include "data/data_abstract_sparse_ids.h"

class PeerData;

namespace Main {
class Session;
} // namespace Main

namespace Data {

using StoriesIdsSlice = AbstractSparseIds<std::vector<StoryId>>;

[[nodiscard]] rpl::producer<StoriesIdsSlice> AlbumStoriesIds(
	not_null<PeerData*> peer,
	int albumId,
	StoryId aroundId,
	int limit);

} // namespace Data

