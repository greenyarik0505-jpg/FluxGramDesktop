/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

namespace Ui {

void SetAppliedBubbleRadius(int value);
void SetBubbleRadiusOverride(int value);
void ClearBubbleRadiusOverride();

[[nodiscard]] int BubbleRadiusSmall();
[[nodiscard]] int BubbleRadiusLarge();

[[nodiscard]] int MsgFileThumbRadiusSmall();
[[nodiscard]] int MsgFileThumbRadiusLarge();

extern const char kOptionUseSmallMsgBubbleRadius[];

} // namespace Ui

