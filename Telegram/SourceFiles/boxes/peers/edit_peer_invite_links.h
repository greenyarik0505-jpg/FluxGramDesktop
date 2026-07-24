/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include "ui/layers/generic_box.h"

class PeerData;

namespace Ui {
class SettingsButton;
} // namespace Ui

void ManageInviteLinksBox(
	not_null<Ui::GenericBox*> box,
	not_null<PeerData*> peer,
	not_null<UserData*> admin,
	int count,
	int revokedCount);

[[nodiscard]] object_ptr<Ui::SettingsButton> MakeCreateLinkButton(
	not_null<QWidget*> parent,
	rpl::producer<QString> text);

