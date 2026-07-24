/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

namespace Layout {

struct Position {
	int row = -1;
	int column = -1;
};

[[nodiscard]] Position IndexToPosition(int index);
[[nodiscard]] int PositionToIndex(int row, int column);
[[nodiscard]] int PositionToIndex(const Position &position);

} // namespace Layout

