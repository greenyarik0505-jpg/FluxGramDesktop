/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

class PeerData;
class UserData;

namespace Ui {
class GenericBox;
class Show;
} // namespace Ui

void SelectFutureOwnerbox(
	not_null<Ui::GenericBox*> box,
	not_null<PeerData*> peer,
	not_null<UserData*> user);

