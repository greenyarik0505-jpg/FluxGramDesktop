/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

namespace Ui {
class RpWidget;
} // namespace Ui

namespace Ui::NewBadge {

[[nodiscard]] not_null<Ui::RpWidget*> CreateNewBadge(
	not_null<Ui::RpWidget*> parent,
	rpl::producer<QString> text);

void AddToRight(not_null<Ui::RpWidget*> parent);
void AddAfterLabel(
	not_null<Ui::RpWidget*> parent,
	not_null<Ui::RpWidget*> label);

} // namespace Ui::NewBadge

